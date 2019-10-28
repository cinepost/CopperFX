#include "OpDataTable.h"


namespace copper {

void OpDataTable::registerOpDataType(TypeInfo op_data_type_info, OpDataConstructor op_data_constructor) {
	BOOST_LOG_TRIVIAL(debug) << "Registering opdata type: \"" << op_data_type_info.type_name 
		<< "\" uuid: " << op_data_type_info.type_uuid 
		<< " with version: " << op_data_type_info.version;

	TypeInfo op_data_info {
		op_data_type_info.type_name,
		op_data_type_info.ui_name,
		op_data_type_info.version,
		op_data_type_info.type_uuid,
	};

	OpDataTypeEntry entry {
		op_data_info,
		op_data_constructor,
	};

	if(!_op_data_types_table.insert(entry).second){
  	std::cout<<"OpDataType already registered!"<<std::endl;
	}
}

}