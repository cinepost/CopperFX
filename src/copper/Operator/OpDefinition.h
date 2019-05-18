#ifndef OP_DEFINITION_H
#define OP_DEFINITION_H

#include <string>
#include <vector>
#include <map>

#include "flags/flags.hpp"

#include "copper/Plugin/PluginApi.h"
#include "copper/Operator/OpDataSocket.h"
#include "copper/Operator/OpBase.h"


namespace copper {

class OpNode;

typedef OpBase *(*opConstructor)();

class OpDefinition {
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
		OpDefinition(
			unsigned int version, 							/// operator version
			std::string type_name, 							/// internal operator name
			std::string ui_name, 								/// name used in ui
			opConstructor op_contructor,   			/// operator factory method for operator instance construction
			std::vector<OpDataSocket> inputs,		/// operator data inputs
			std::vector<OpDataSocket> outputs, 	/// operator data outputs 
			OpDefinition::Flags flags
		);

		std::string typeName() const;
		opConstructor constructor() const;
		const std::vector<OpDataSocket> *inputs() const;
		const std::vector<OpDataSocket> *outputs() const;

	public:
		OpNode *createOpNode(OpNode *parent_op_network, const std::string &name = "");

	private:
		unsigned int _version;
		std::string _type_name;
		std::string _ui_name;
		opConstructor _opConstructor;
		std::vector<OpDataSocket> _inputs;
		std::vector<OpDataSocket> _outputs;
		OpDefinition::Flags _flags;

};

}

ALLOW_FLAGS_FOR_ENUM(copper::OpDefinition::Flags)

#endif // OP_DEFINITION_H
