#ifndef MT_METACREATOR_H
#define MT_METACREATOR_H

#include "copper/MT/MT_MetaData.h"

namespace copper {

template <typename Metatype>
class MetaCreator {
	public:
	  MetaCreator( std::string name, unsigned size )
	  {
	    Init( name, size );
	  }

	  static void Init( std::string name, unsigned size )
	  {
	    Get( )->Init( name, size );
	  }
	  // Ensure a single instance can exist for this class type
	  static MetaData *Get( void )
	  {
	    static MetaData instance;
	    return &instance;
	  }
};

}

#endif // MT_METACREATOR_H