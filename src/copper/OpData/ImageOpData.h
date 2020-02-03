#ifndef Image_OP_DATA_H
#define Image_OP_DATA_H

#include <vector>
#include <string>
#include <map>

#include "copper/OpData/OpDataBase.h"
#include "copper/OpData/OpDataTable.h"

namespace copper {

class ImageOpData: public OpDataBase {
	public:
		ImageOpData(){};

	public:
		const std::string& name() const override;

		void saveToFile(const std::string& filename, const unsigned int version) const override;
    	void loadFromFile(const std::string& filename, const unsigned int version) override;
		
    	// opdata type info
    	static TypeInfo opDataTypeInfo();

    	// factory methods
    	static OpDataBase *myConstructor();
    	static void registerDataType(OpDataTable *op_data_table);

	private:
		static std::string _ui_name;
};

}

#endif // Image_OP_DATA_H