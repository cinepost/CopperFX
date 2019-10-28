#ifndef OP_TABLE_H
#define OP_TABLE_H

#include <vector>
#include <algorithm>
#include <unordered_map>

#include <boost/uuid/uuid.hpp>

#include <boost/log/core.hpp>
#include <boost/log/trivial.hpp>

#include <boost/multi_index_container.hpp>
#include <boost/multi_index/ordered_index.hpp>
#include <boost/multi_index/member.hpp>
#include <boost/multi_index/composite_key.hpp>
#include <boost/multi_index/ordered_index.hpp>
#include <boost/multi_index/hashed_index.hpp>

#include "copper/Plugin/TypeInfo.h"
#include "copper/Plugin/AbstractFactory.h"
#include "copper/Operator/OpBase.h"

using namespace boost::multi_index;

namespace copper {

class Engine;
class OpNodeTemplate;

struct OpNodeTemplateEntry {
	TypeInfo type_info;
	OpNodeTemplate* op_node_template;
};

struct entry_uuid_extractor {
  typedef boost::uuids::uuid result_type;
  const result_type& operator()(const OpNodeTemplateEntry& e)const{return e.type_info.type_uuid;}
  result_type&       operator()(OpNodeTemplateEntry* e)const{return e->type_info.type_uuid;}
};

struct entry_type_name_extractor {
  typedef std::string result_type;
  const result_type& operator()(const OpNodeTemplateEntry& e)const{return e.type_info.type_name;}
  result_type&       operator()(OpNodeTemplateEntry* e)const{return e->type_info.type_name;}
};

struct entry_version_extractor {
  typedef unsigned int result_type;
  const result_type& operator()(const OpNodeTemplateEntry& e)const{return e.type_info.version;}
  result_type&       operator()(OpNodeTemplateEntry* e)const{return e->type_info.version;}
};

typedef multi_index_container<
  OpNodeTemplateEntry,
  indexed_by<
    ordered_unique<
    	tag<struct uuid_version>,
    	composite_key<
    		OpNodeTemplateEntry,
    		entry_uuid_extractor,
    		entry_version_extractor
    	>,
    	composite_key_compare<
        std::less<boost::uuids::uuid>, //
        std::greater<unsigned int>     // versions reversed (greater comes first)
      >
    >,
    ordered_unique<
    	tag<struct type_name_version>,
    	composite_key<
    		OpNodeTemplateEntry,
    		entry_type_name_extractor,
    		entry_version_extractor
    	>,
    	composite_key_compare<
        std::less<std::string>, //
        std::greater<unsigned int>     // versions reversed (greater comes first)
      >
    >
  >
> OpNodeTemplatesTable;

class OpTable {
	public:
		void registerOpNodeTemplate(
			OpNodeTemplate *op_template
		);

	protected:
		OpNodeTemplate *getOpNodeTemplate(std::string type_name);
		OpNodeTemplate *getOpNodeTemplate(std::string type_name, unsigned int version);
		OpNodeTemplate *getOpNodeTemplate(boost::uuids::uuid type_uuid);
		OpNodeTemplate *getOpNodeTemplate(boost::uuids::uuid type_uuid, unsigned int version);

		friend class Engine;

	public:
		const std::vector<TypeInfo> registeredOperators() const;

	private:
		OpNodeTemplatesTable _op_node_templates_table;
};

}

#endif // OP_TABLE_H