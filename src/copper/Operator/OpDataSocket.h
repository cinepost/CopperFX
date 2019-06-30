#ifndef OP_DATA_SOCKET_H
#define OP_DATA_SOCKET_H

#include <string>
#include <vector>
#include <type_traits>

#include <boost/uuid/uuid.hpp>
#include <boost/uuid/uuid_io.hpp>
#include <boost/uuid/string_generator.hpp>

#include <flags/flags.hpp>

#include "copper/Plugin/PluginApi.h"
#include "copper/OpData/OpDataBase.h"
#include "copper/Util/IndexableObject.h"

namespace copper {

class OpNode;

class OpDataSocket: public IndexableObject {
	friend class OpDataSocketTemplate;

	public:
		virtual ~OpDataSocket();
		unsigned int idx() const;
		bool isInput() const;
		bool isOutput() const;
		bool isMultiInput() const;
		bool setInput(const OpDataSocket *socket);
		const std::vector<OpDataSocketGUID>& inputGUIDs() const;
		static bool canConnect(const OpDataSocket* socket_1, const OpDataSocket* socket_2);

	public:
		boost::uuids::uuid dataTypeUUID() const;

	protected:
		// direct OpDataSocket construction prohibited. Only OpDataSocketTemplate factory methon can make it
		OpDataSocket();

	private:
		unsigned int _id;
		boost::uuids::uuid _data_type_uuid;
		unsigned int _data_type_version;
		OpNode *_op_node = nullptr;
		OpNodeGUID _op_node_guid;
		bool _is_input;
		bool _is_multi_input;

		std::vector<OpDataSocketGUID> _input_guids;
};

}

#endif // OP_DATA_SOCKET_H