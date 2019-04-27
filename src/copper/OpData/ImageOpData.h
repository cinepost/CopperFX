#ifndef Image_OP_DATA_H
#define Image_OP_DATA_H

#include <vector>
#include <string>
#include <map>

#include "copper/OpData/OpDataBase.h"

namespace copper {

class ImageOpData: public OpDataBase {
	public:
		ImageOpData(){};

		const std::string name() const override;
		const std::string typeName() const override;
		const unsigned int version() const override;

		void saveToFile(std::string filename, const unsigned int version) override;
    void loadFromFile(std::string filename, const unsigned int version) override;
		
    // factory methods
    static std::string myTypeName();
    static OpDataBase *myConstructor();

	private:
};

// factory methods
OpDataBase *imageOpDataConstructor();
std::string	imageOpDataTypeName();

}

#endif // Image_OP_DATA_H