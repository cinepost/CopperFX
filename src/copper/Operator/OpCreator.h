#ifndef OP_CREATOR_H
#define OP_CREATOR_H

#include <string>
#include <vector>
#include <map>

#include "copper/Plugin/PluginApi.h"
#include "copper/Operator/OpDataSocket.h"
#include "copper/Operator/OpBase.h"


namespace copper {

typedef OpBase *(*opConstructor)();

class OpCreator {

	/// Flags passed to the operator definition contructor:
	public:
		enum Flags{
			OP_FLAG_NETWORK                = 0x01,
			OP_FLAG_GENERATOR              = 0x02, /// Generates new data
			OP_FLAG_UNORDERED              = 0x04, /// Unordered, variable inputs
			OP_FLAG_SCRIPTDEF              = 0x08, /// Defined by a dialog script
			OP_FLAG_MANAGER                = 0x10, /// This is a management node.
			OP_FLAG_PRIMARYSUBNET          = 0x20, /// The primary "subnet" operator
			OP_FLAG_OUTPUT                 = 0x40, /// Output type. Only one per net
			OP_FLAG_EDITABLE_INPUT_DATA    = 0x80  /// Enable editable input data
		};

	public:
		OpCreator(
			unsigned int version, 							/// operator version
			std::string type_name, 							/// internal operator name
			std::string ui_name, 								/// name used in ui
			opConstructor op_contructor,   			/// operator factory method for operator instance construction
			std::vector<OpDataSocket> inputs,		/// operator data inputs
			std::vector<OpDataSocket> outputs, 	/// operator data outputs 
			Flags flags
		);

		std::string typeName();
		opConstructor constructor();

	private:
		unsigned int _version;
		opConstructor _opConstructor;
		std::string _type_name;
		std::string _ui_name;
		std::vector<OpDataSocket> _inputs;
		std::vector<OpDataSocket> _outputs;
		Flags _flags;

};

}

#endif // OP_CREATOR_H