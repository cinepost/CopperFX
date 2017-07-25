#include "../include/String_Utils.h"


std::string makeBase1String(std::string s) {
	// find integer in the end of the string to increase if there is some
	std::string::size_type found = s.find_last_not_of( "0123456789" );
	if ( found != (s.length() - 1) ) {
		// there is digits in the end
		std::string name_string = s.substr( 0, found + 1);
    	int i = std::stoi( s.substr(found + 1) );
    	return name_string.append(std::to_string( i + 1 ));
	}

	// no integer found in the end of the strind, just add 1 and return
	return s + "1";
}