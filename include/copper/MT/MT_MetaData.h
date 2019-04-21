#ifndef MT_METADATA_H
#define MT_METADATA_H

#include <string>


namespace copper {

//
// MetaData
// Purpose: Object for holding various info about any C++ type for the MetaData reflection system.
//
class MetaData {
	public:
		MetaData(std::string string, unsigned val) : _name( string), _size( val ) {}
		~MetaData()

		const std::string& name (void) const { return _name; }
		unsigned size(void) const { return _size; }

	private:
		std::string _name;
		unsigned size;
}

}

#endif // MT_METADATA_H