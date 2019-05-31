#ifndef __SCN_IFDTranslator_h__
#define __SCN_IFDTranslator_h__

#include <string>
#include <vector>
#include <iostream>
#include <fstream>

#include <boost/spirit.hpp>

#include "SCN_IOTranslator.h"

static std::vector<std::string> _ifd_extensions = {".ifd",".ifd.gz",".ifd.zip"};


class SCN_IFDTranslator : public SCN_IOTranslator {
  public:
    SCN_IFDTranslator();
    ~SCN_IFDTranslator();

    const char         *formatName() const;
    int                 checkExtension(const char *name);

    void                getFileExtensions(std::vector<std::string> &extensions) const;

    // Method to check if the given magic number matches the magic number. Return true on a match.
    int                 checkMagicNumber(unsigned magic);

    SCN_Scene::IOStatus fileLoad(SCN_Scene &scn, std::istream &in, bool ate_magic) override;
};


class SCN_IFDTranslatorFactory {
    public:
        // factory methods
        static SCN_IOTranslator         *myConstructor();
        static std::vector<std::string> *myExtensions();
};

#endif // __SCN_IFDTranslator_h__