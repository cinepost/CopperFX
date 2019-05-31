#ifndef SCN_BASE_PARSER_H
#define SCN_BASE_PARSER_H

#include <string>
#include <map>
#include <vector>

namespace Shout { class Renderer;  }

class SCN_BaseParser {


	private:
		// Request handler function type
    typedef void (SCN_BaseParser::*RequestHandlerType)(Shout::Renderer& renderer);
    // Request -> handler mapping type
		typedef std::map<std::string, RequestHandlerType> handlerMap;
}

#endif // BASE_PARSER_H