#include <string>
#include <vector>

#include <boost/log/core.hpp>
#include <boost/log/trivial.hpp>
#include <boost/log/expressions.hpp>

#include "SCN_IORegistry.h"

void SCN_IORegistry::addIOTranslator(IO_Extensions extensions, IO_Constructor constructor) {
	std::string registered_extensions = "";
	for (auto ext : *extensions()) {
		translatorsByExtension.insert ( std::pair<std::string, IO_Constructor>(ext, constructor) );
		registered_extensions += " " + ext;
	}
	BOOST_LOG_TRIVIAL(debug) << "SCN_IOTranslator registered for extensions:" << registered_extensions;
}

SCN_IOTranslator *SCN_IORegistry::getTranslatorByExt(std::string ext) {
	return translatorsByExtension[ext]();
}