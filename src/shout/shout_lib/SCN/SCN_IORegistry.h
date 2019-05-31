#ifndef __SCN_Registry_h__
#define __SCN_Registry_h__

#include <string>
#include <vector>
#include <map>

#include "SCN_IOTranslator.h"

typedef std::vector<std::string> *(*IO_Extensions)();
typedef SCN_IOTranslator *(*IO_Constructor)();

class SCN_IORegistry {
	public:
		static SCN_IORegistry& getInstance() {
			static SCN_IORegistry instance; // Guaranteed to be destroyed.
																			// Instantiated on first use.
			return instance;
		}

	private:
		SCN_IORegistry() {} // Constructor? (the {} brackets) are needed here.

 		// C++ 11
    // =======
    // We can use the better technique of deleting the methods
    // we don't want.
	public:
    SCN_IORegistry(SCN_IORegistry const&) = delete;
    void operator=(SCN_IORegistry const&) = delete;

    // Note: Scott Meyers mentions in his Effective Modern
    //       C++ book, that deleted functions should generally
    //       be public as it results in better error messages
    //       due to the compilers behavior to check accessibility
    //       before deleted status

	public:
		void	          	addIOTranslator(IO_Extensions extensions, IO_Constructor constructor);
		SCN_IOTranslator 	*getTranslatorByExt(std::string ext);

	private:
		std::map<std::string, IO_Constructor> translatorsByExtension;
};


#endif // __SCN_Registry_h__