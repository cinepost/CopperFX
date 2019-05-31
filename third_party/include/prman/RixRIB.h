#ifndef RixRIB_h
#define RixRIB_h
/* $Revision: #3 $ $Date: 2014/12/10 $
# ------------------------------------------------------------------------------
#
# Copyright (c) 2010 Pixar Animation Studios. All rights reserved.
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

#include "RixInterfaces.h"
#include "ri.hpp"

/** 
   The RixRIB interface provides a factory class to manufacture RIB 
   generation contexts. A typical use of this factory is:

   \code
   Ri *rib = ribRixInterface->CreateRIBGenerator();
   rib->Begin("hello.rib");
     rib->ArchiveRecord(RI_COMMENT, "Hello World, from %s", argv[0]);
   rib->End();
   ribif->DestroyRIBGenerator(rib);
   \endcode

   NOTE: RIB generation contexts can be produced relative to
   others to share the binary encoding contexts and symbol
   table state.
*/
class RixRIB : public RixInterface 
{
public:
    /// Return a pointer to RIB generator, or NULL of there is an error.
    /// If parent is non-NULL the RIB generator created will share
    /// the binary encoding and symbol table of the parent generator.
    virtual Ri *CreateRIBGenerator(Ri *parent=0L) = 0;

    /// Destructs a RIB generator created by CreateRIBGenerator()
    virtual void DestroyRIBGenerator(Ri *) = 0;

protected:
    /// Constructor is for internal use only.
    RixRIB() : RixInterface(1) { }
};

#endif