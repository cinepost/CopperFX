#ifndef SCN_BASE_TOKEN_H
#define SCN_BASE_TOKEN_H

#include <string>
#include <iostream>
#include <vector>

typedef const char* ConstString;

class SCN_BaseToken {
	public:

		// Common token types
		enum Type {
			ARRAY_BEGIN,
			ARRAY_END,
			STRING,
			INTEGER,
			FLOAT,
			COMMAND,
			ERROR,
			ENDOFFILE
		};

		SCN_BaseToken(Type type = ERROR);
		SCN_BaseToken(int intVal);
		SCN_BaseToken(float floatVal);
		SCN_BaseToken(Type type, const std::string& strVal);

		// Assign to the given type
		SCN_BaseToken& operator=(Type type);
		SCN_BaseToken& operator=(int i);
		SCN_BaseToken& operator=(float f);

		// Set the token to the error type, with the given error message
		void error(const char* message);

		bool operatr==(const SCN_BaseToken& tok) const;

		// Format token for stream output 
		friend std::ostream& operator<<(std::ostream& out, const SCN_BaseToken& tok);

		// Get token type
		Type type() const;

		// Get int value of a token
		int getIntVal() const;

		// Get float value of a token
		float getFloatVal() const;

	private:
		friend class SCN_BaseTokenizer;

}

#endif // BASE_LEXER_H