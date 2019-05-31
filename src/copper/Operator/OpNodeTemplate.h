#ifndef OP_DEFINITION_H
#define OP_DEFINITION_H

#include <string>
#include <vector>
#include <map>

#include "flags/flags.hpp"

#include "copper/Plugin/PluginApi.h"
#include "copper/Operator/OpBase.h"
#include "copper/Operator/OpDataSocketTemplate.h"

namespace copper {

class OpNode;
class OpDataBase;
class OpDataSocketBase;

typedef OpBase *(*opConstructor)();
typedef std::vector<OpDataSocketTemplate> OpDataSocketTemplateList;

class OpNodeTemplate {
	friend class OpNode;

	/// Flags passed to the operator definition contructor:
	public:
		enum class Flags{
			OP_FLAG_NETWORK                = 0x01,
			OP_FLAG_GENERATOR              = 0x02, /// Generates new data
			OP_FLAG_UNORDERED              = 0x04, /// Unordered, variable inputs
			OP_FLAG_SCRIPTDEF              = 0x08, /// Defined by a dialog script
			//OP_FLAG_MANAGER                = 0x10, /// This is a management node.
			//OP_FLAG_PRIMARYSUBNET          = 0x20, /// The primary "subnet" operator
			//OP_FLAG_OUTPUT                 = 0x40, /// Output type. Only one per net
			//OP_FLAG_EDITABLE_INPUT_DATA    = 0x80  /// Enable editable input data
		};

	public:
		OpNodeTemplate(
			unsigned int version, 							/// operator version
			std::string type_name, 							/// internal operator name
			std::string ui_name, 								/// name used in ui
			opConstructor op_contructor,   			/// operator factory method for operator instance construction
			OpDataSocketTemplateList input_socket_templates,		/// operator data inputs
			OpDataSocketTemplateList output_socket_templates, 	/// operator data outputs 
			OpNodeTemplate::Flags flags
		);

		const std::string& typeName() const;
		opConstructor constructor() const;
		const OpDataSocketTemplateList *inputs() const;
		const OpDataSocketTemplateList *outputs() const;

	public:
		OpNode *createOpNode(OpNode *parent_op_node, const std::string &name = "");

	private:
		unsigned int _version;
		std::string _type_name;
		std::string _ui_name;
		opConstructor _opConstructor;
		OpDataSocketTemplateList _input_socket_templates;
		OpDataSocketTemplateList _output_socket_templates;
		OpNodeTemplate::Flags _flags;
};

}

ALLOW_FLAGS_FOR_ENUM(copper::OpNodeTemplate::Flags)

#endif // OP_DEFINITION_H
