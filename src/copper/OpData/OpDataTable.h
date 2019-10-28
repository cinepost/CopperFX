#ifndef OP_DATA_TABLE_H
#define OP_DATA_TABLE_H

#include <vector>
#include <unordered_map>

#include <boost/log/core.hpp>
#include <boost/log/trivial.hpp>

#include <boost/uuid/uuid.hpp>

#include <boost/multi_index_container.hpp>
#include <boost/multi_index/ordered_index.hpp>
#include <boost/multi_index/member.hpp>
#include <boost/multi_index/composite_key.hpp>
#include <boost/multi_index/ordered_index.hpp>
#include <boost/multi_index/hashed_index.hpp>

#include "copper/Plugin/TypeInfo.h"
#include "copper/Plugin/AbstractFactory.h"
#include "copper/OpData/OpDataBase.h"

using namespace boost::multi_index;

namespace copper {

typedef OpDataBase *(*OpDataConstructor)();

struct OpDataTypeEntry {
	TypeInfo type_info;
	OpDataConstructor op_data_constructor;
};

struct data_entry_uuid_extractor {
  typedef boost::uuids::uuid result_type;
  const result_type& operator()(const OpDataTypeEntry& e)const{return e.type_info.type_uuid;}
  result_type&       operator()(OpDataTypeEntry* e)const{return e->type_info.type_uuid;}
};

struct data_entry_version_extractor {
  typedef unsigned int result_type;
  const result_type& operator()(const OpDataTypeEntry& e)const{return e.type_info.version;}
  result_type&       operator()(OpDataTypeEntry* e)const{return e->type_info.version;}
};

typedef multi_index_container<
  OpDataTypeEntry,
  indexed_by<
    ordered_unique<
    	composite_key<
    		OpDataTypeEntry,
    		data_entry_uuid_extractor,
    		data_entry_version_extractor
    	>,
    	composite_key_compare<
        std::less<boost::uuids::uuid>, //
        std::greater<unsigned int>     // versions reversed (greater comes first)
      >
    >
  >
> OpDataTypesTable;

class Engine;

class OpDataTable {
	public:
		void registerOpDataType(
			TypeInfo op_data_type_info,
			OpDataConstructor op_data_constructor
		);
	
	protected:
		OpDataBase *buildOpData(boost::uuids::uuid type_uuid, unsigned int version);
		const std::vector<OpDataTypeEntry> registeredDataTypes() const;

		friend class Engine;

	private:
		OpDataTypesTable _op_data_types_table;
};

}

#endif // OP_DATA_TABLE_H