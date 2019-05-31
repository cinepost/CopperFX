#ifndef OP_DATA_SOCKET_H
#define OP_DATA_SOCKET_H

#include <string>
#include <vector>
#include <type_traits>

#include <flags/flags.hpp>

#include "copper/Plugin/PluginApi.h"
#include "copper/OpData/OpDataBase.h"

namespace copper {

class OpNode;

class OpDataSocket {
	friend class OpDataSocketTemplate;

	public:
		virtual ~OpDataSocket();
		unsigned int idx() const;
		bool isInput() const;
		bool isOutput() const;
		bool isMultiInput() const;
		bool connect(const OpDataSocket *socket);
		std::vector<const OpDataSocket*> connections() const;
		static bool canConnect(const OpDataSocket* socket_1, const OpDataSocket* socket_2);

	public:
		unsigned int dataTypeUUID() const;

	protected:
		// direct OpDataSocket construction prohibited. Only OpDataSocketTemplate factory methon can make it
		OpDataSocket();

	private:
		unsigned int _id;
		unsigned int _data_type_uuid;
		OpNode *_op_node = nullptr;
		bool _is_input;
		bool _is_multi_input;

		std::vector<const OpDataSocket*> 	_connections;
};

}

#endif // OP_DATA_SOCKET_H