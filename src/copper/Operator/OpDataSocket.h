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

class OpDataSocketBase {
	public:
		virtual ~OpDataSocketBase();
		unsigned int idx() const;
		bool isInput() const;
		bool isOutput() const;
		bool isMultiInput() const;
		bool connect(const OpDataSocketBase *socket);
		std::vector<const OpDataSocketBase*> connections() const;
		static bool canConnect(const OpDataSocketBase* socket_1, const OpDataSocketBase* socket_2);

	public:
		virtual const std::string& dataTypeName() const = 0;

	protected:
		// direct OpDataSocket construction prohibited. Only OpDataSocketTemplate factory methon can make it
		OpDataSocketBase();

	private:
		unsigned int _id;
		OpNode *_op_node = nullptr;
		bool _is_input;
		bool _is_multi_input;

		std::vector<const OpDataSocketBase*> 	_connections;
};

template <class T>
class OpDataSocket: public OpDataSocketBase {
	static_assert(std::is_base_of<OpDataBase, T>::value, "T must inherit from OpDataBase");
	
	public:
		const std::string& dataTypeName() const;
		OpDataSocket(): OpDataSocketBase(){};
};

template<class T>
const std::string& OpDataSocket<T>::dataTypeName() const {
	return T::typeName();
}

}

#endif // OP_DATA_SOCKET_H