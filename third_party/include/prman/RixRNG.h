#ifndef RixRNG_h
#define RixRNG_h
/* $Revision: #2 $ $Date: 2014/12/10 $ */
/*
# ------------------------------------------------------------------------------
#
# Copyright (c) 2014 Pixar Animation Studios. All rights reserved.
#
# The information in this file (the "Software") is provided for the
# exclusive use of the software licensees of Pixar.  Licensees have
# the right to incorporate the Software into other products for use
# by other authorized software licensees of Pixar, without fee.
# Except as expressly permitted herein, the Software may not be
# disclosed to third parties, copied or duplicated in any form, in
# whole or in part, without the prior written permission of
# Pixar Animation Studios.
#
# The copyright notices in the Software and this entire statement,
# including the above license grant, this restriction and the
# following disclaimer, must be included in all copies of the
# Software, in whole or in part, and all permitted derivative works of
# the Software, unless such copies or derivative works are solely
# in the form of machine-executable object code generated by a
# source language processor.
#
# PIXAR DISCLAIMS ALL WARRANTIES WITH REGARD TO THIS SOFTWARE, INCLUDING
# ALL IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS, IN NO EVENT
# SHALL PIXAR BE LIABLE FOR ANY SPECIAL, INDIRECT OR CONSEQUENTIAL DAMAGES
# OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS,
# WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION,
# ARISING OUT OF OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS
# SOFTWARE.
#
# Pixar
# 1200 Park Ave
# Emeryville CA 94608
#
# ------------------------------------------------------------------------------
*/

#include <stddef.h>     // for size_t
#include <float.h>      // for FLT_EPSILON in RixRNGInline.h
#include <cassert>     // for size_t

#include "ri.h"

/// All-inlined interface for generating random numbers for use by Monte Carlo
/// integration and multiple-importance sampling.  Samples are distributed
/// within an N-dimension domain characterized by the combination of
/// patternid, sampleid and "stratified" according to the strata size
/// implied by the numsamples array.  Resulting random numbers reside
/// within the [0,1)^N region.
///
// RixRNG is an interface that couples an array of per-point RNG
// contexts (RixRNG::SampleCtx) with a single shared context (ShareCtx). 
// All operations on individual RixRNG::SampleCtx require access to
// SharedCtx.


#include "RixRNGInline.h"

class RixRNG
{
public:

    /// SampleCtx identifies an index into an abribtrary scheme of random
    /// numbers.  It may be used to pick a random number or to derive a 
    /// new 'domain' which represents a new point of consumption for random
    /// numbers - eg picking a direction and picking a position might be
    /// two distinct domains which both want independent streams of
    /// decorrelated random numbers
    struct SampleCtx
    {
        unsigned patternid;
        unsigned sampleid;
        unsigned numsamples : 31;
        unsigned ispath : 1;

        /// Return a new Ctx based on this one, but with a scrambled pattern
        /// based on domain, an integer characterizing a sampling domain
        //  (e.g. a number based on brdf 'lobe').
        SampleCtx NewDomain(unsigned domain)
        {
            SampleCtx newd = *this;
            newd.patternid = RixRNGUtils::shufflePattern(patternid + domain);
            return newd;
        }

        /// Return a new Ctx based on this one, but with a scrambled pattern
        /// based on domain and inherited pattern id. Domain is usually a small
        /// integer characterizing a sampling domain (e.g. a number based on
        /// brdf 'lobe').  
        /// This form should be preferred where the new domain's
        /// expected number of samples differs from that of the parent and
        /// repeated visits may nor may not have the same sample count or 
        /// may consume differing numbers of samples
        SampleCtx NewDomain(unsigned newdomain, unsigned newsampleid, 
                            unsigned newnsamples)
        {
            SampleCtx newd;
            if (newnsamples == 1) 
            {
                // distribution to path or path to path
                newd.patternid = 
                    RixRNGUtils::shufflePattern(patternid + newdomain);
                newd.sampleid = sampleid;
                newd.numsamples = numsamples;
                newd.ispath = true;
            } 
            else 
            {
                // path to distribution or distribution to distribution
                newd.patternid = 
                    RixRNGUtils::shufflePattern(patternid+newdomain, sampleid);
                newd.sampleid = newsampleid;
                newd.numsamples = newnsamples;
                newd.ispath = false;
            }
            return newd;
        }

        /// Return a new Ctx based on this one, but with a scrambled pattern
        /// based on domain and inherited pattern id. Domain is usually a small
        /// integer characterizing a sampling domain (e.g. a number based on
        /// brdf 'lobe').  
        /// This form should be preferred where every visit will consume the
        /// same number of samples, and it is expected that all sibling visits
        /// will also always result in the drawing of a new domain - thus
        /// exploring the full space.  Uses trajectory splitting.
        SampleCtx NewDomain(unsigned newdomain, unsigned newnsamples)
        {
            SampleCtx newd = *this;
            newd.patternid = RixRNGUtils::shufflePattern(patternid + newdomain);
            newd.sampleid *= newnsamples;
            newd.numsamples *= newnsamples;
            return newd;
        }
    }; // end of struct SampleCtx


    // Overiddable implementation
    class Generator
    {
    public:
        Generator() { }
        virtual ~Generator() { }

        virtual RtFloat  Sample1D(unsigned i, const SampleCtx &rctx) = 0;
        virtual RtFloat2 Sample2D(unsigned i, const SampleCtx &rctx) = 0;
        virtual RtFloat3 Sample3D(unsigned i, const SampleCtx &rctx) = 0;
        
        virtual void MultiSample1D(unsigned n, const SampleCtx *rctx, 
                                    RtFloat *xis) = 0;
        virtual void MultiSample2D(unsigned n, const SampleCtx *rctx, 
                                    RtFloat2 *xis) = 0;
        virtual void MultiSample3D(unsigned n, const SampleCtx *rctx, 
                                    RtFloat3 *xis) = 0;
    };
    
    // Default implementation
    #include "RixRNGProgressive.h"

public:
    RixRNG(Generator *i, unsigned npts = 0) : 
        numPts(npts), 
        sampleCtxArray(0), 
        impl(i) {}

    // Construct a new RixRNG, with specified SampleCtx memory block.
    RixRNG(Generator *imp, SampleCtx *sca, unsigned npts) : 
        numPts(npts),
        sampleCtxArray(sca),
        impl(imp) {}


    // Construct a RixRNG based on another, but with a new SampleCtx memory 
    // block.
    // WARNING: if your parent RNG is of a different size, do not use this 
    //          routine.
    RixRNG(RixRNG const *rhs, SampleCtx *sca) : 
        numPts(rhs->numPts),
        sampleCtxArray(sca),
        impl(rhs->impl) {}

    // Construct a RixRNG based on another, but with a new SampleCtx memory 
    // block.
    RixRNG(RixRNG const *rhs, SampleCtx *sca, unsigned npts) : 
        numPts(npts),
        sampleCtxArray(sca),
        impl(rhs->impl) {}

    // Construct a RixRNG based on another, but with a new SampleCtx memory 
    // block. Derivation of the new domain uses trajectory splitting 
    // (the second form of NewDomain)
    // WARNING: if your parent RNG is of a different size, do not use 
    //          this routine.
    RixRNG(RixRNG const *rhs, SampleCtx *sca, unsigned domain, unsigned nsamps) : 
        numPts(rhs->numPts),
        sampleCtxArray(sca),
        impl(rhs->impl)
    {
        for(unsigned i=0;i<numPts;++i)
        {
            sampleCtxArray[i] = 
                rhs->sampleCtxArray[i].NewDomain(domain, nsamps);
        }
    }

    // Construct a RixRNG based on another, but with a new SampleCtx memory 
    // block. Derivation of the new domain uses ordinary method (the first 
    // form of NewDomain)
    // WARNING: if your parent RNG is of a different size, do not use 
    //          this routine.
    RixRNG(RixRNG const *rhs, SampleCtx *sca, 
            unsigned domain, unsigned sampleid, unsigned nsamps) : 
        numPts(rhs->numPts),
        sampleCtxArray(sca),
        impl(rhs->impl)
    {
        for(unsigned i=0;i<numPts;++i)
            sampleCtxArray[i] = 
                rhs->sampleCtxArray[i].NewDomain(domain, sampleid, nsamps);
    }

    // Construct a single-element RNG based on another, need new SampleCtx
    // memory and an offset into rhs's sample array.
    RixRNG GetSlice(SampleCtx *sca, unsigned index)
    {
        RixRNG result(this->impl);
        result.numPts = 1;
        result.sampleCtxArray = sca;
        result.sampleCtxArray[0] = this->sampleCtxArray[index];
        return result;
    }

    virtual ~RixRNG() {}

    unsigned numPts;
    SampleCtx *sampleCtxArray;
    Generator *impl;

    SampleCtx &GetSampleCtx(unsigned i) 
    {
        return sampleCtxArray[i];
    }

    // The 'Generate' family of interfaces assumes caller will generate
    // a sequence of samples based on a SampleCtx obtained from the 
    // renderer.

    // Generate a sample and increment sample id
    RtFloat GenerateSample1D(unsigned i)
    {
        RtFloat f = impl->Sample1D(i,sampleCtxArray[i]);
        sampleCtxArray[i].sampleid++;
        return f;
    }

    RtFloat2 GenerateSample2D(unsigned i)
    {
        RtFloat2 f2 = impl->Sample2D(i,sampleCtxArray[i]);
        sampleCtxArray[i].sampleid++;
        return f2;
    }

    RtFloat3 GenerateSample3D(unsigned i)
    {
        RtFloat3 f3 = impl->Sample3D(i,sampleCtxArray[i]);
        sampleCtxArray[i].sampleid++;
        return f3;
    }

    // Generate numPts samples
    void GenerateSamples1D(unsigned n, RtFloat *xis)
    {
        assert(n == numPts);
        impl->MultiSample1D(numPts,sampleCtxArray,xis);
        for (unsigned i = 0; i < numPts; ++i)
            sampleCtxArray[i].sampleid++;
    }

    void GenerateSamples2D(unsigned n, RtFloat2 *xis)
    {
        assert(n == numPts);
        impl->MultiSample2D(numPts,sampleCtxArray,xis);
        for (unsigned i = 0; i < numPts; ++i)
            sampleCtxArray[i].sampleid++;
    }

    void GenerateSamples3D(unsigned n, RtFloat3 *xis)
    {
        assert(n == numPts);
        impl->MultiSample3D(numPts,sampleCtxArray,xis);
        for (unsigned i = 0; i < numPts; ++i)
            sampleCtxArray[i].sampleid++;
    }

    // You must pass the index from which this SampleCtx was derived
    RtFloat GenerateSample1D(unsigned i, SampleCtx &c)
    {
        RtFloat f = impl->Sample1D(i,c);
        c.sampleid++;
        return f;
    }

    RtFloat2 GenerateSample2D(unsigned i, SampleCtx &c)
    {
        RtFloat2 f2 = impl->Sample2D(i,c);
        c.sampleid++;
        return f2;
    }

    RtFloat3 GenerateSample3D(unsigned i, SampleCtx &c)
    {
        RtFloat3 f3 = impl->Sample3D(i,c);
        c.sampleid++;
        return f3;
    }

    // draw a sample from the sequence
    RtFloat DrawSample1D(unsigned i)
    {
        return impl->Sample1D(i,sampleCtxArray[i]);
    }

    RtFloat2 DrawSample2D(unsigned i)
    {
        return impl->Sample2D(i,sampleCtxArray[i]);
    }

    RtFloat3 DrawSample3D(unsigned i)
    {
        return impl->Sample3D(i,sampleCtxArray[i]);
    }

    // Generate numPts samples
    void DrawSamples1D(unsigned n, RtFloat *xis)
    {
        assert(n == numPts);
        impl->MultiSample1D(numPts,sampleCtxArray,xis);
    }

    void DrawSamples2D(unsigned n, RtFloat2 *xis)
    {
        assert(n == numPts);
        impl->MultiSample2D(numPts,sampleCtxArray,xis);
    }

    void DrawSamples3D(unsigned n, RtFloat3 *xis)
    {
        assert(n == numPts);
        impl->MultiSample3D(numPts,sampleCtxArray,xis);
    }

    // You must pass the index from which this SampleCtx was
    // derived
    RtFloat DrawSample1D(unsigned i, const SampleCtx &c)
    {
        return impl->Sample1D(i,c);
    }

    RtFloat2 DrawSample2D(unsigned i, const SampleCtx &c)
    {
        return impl->Sample2D(i,c);
    }

    RtFloat3 DrawSample3D(unsigned i, const SampleCtx &c)
    {
        return impl->Sample3D(i,c);
    }

    // Setting up new random domains
    SampleCtx NewDomain(unsigned i, unsigned domain)
    {
        return sampleCtxArray[i].NewDomain(domain);
    }

    SampleCtx NewDomain(unsigned i,
                        unsigned newdomain, unsigned newsampleid, 
                        unsigned newnsamples)
    {
        return sampleCtxArray[i].NewDomain(newdomain, 
                                           newsampleid, newnsamples);
    }

    SampleCtx NewDomain(unsigned i,
                        unsigned newdomain, unsigned newnsamples)
    {
        return sampleCtxArray[i].NewDomain(newdomain, newnsamples);
    }

};

#endif
