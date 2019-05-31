#ifndef __SCN_IOTranslator_h__
#define __SCN_IOTranslator_h__

#include <string>
#include <vector>
#include <iostream>
#include <fstream>

#include "SCN_Scene.h"


class SCN_IOTranslator {
  public:
    SCN_IOTranslator();
    virtual ~SCN_IOTranslator();

    virtual const char         *formatName() const = 0;
    virtual int                 checkExtension(const char *name) = 0;

    virtual void                getFileExtensions(std::vector<std::string> &extensions) const = 0;

    // Method to check if the given magic number matches the magic number. Return true on a match.
    virtual int                 checkMagicNumber(unsigned magic) = 0;

    virtual SCN_Scene::IOStatus fileLoad(SCN_Scene &scn, std::istream &in, bool ate_magic) = 0;
};



#endif // __SCN_IOTranslator_h__