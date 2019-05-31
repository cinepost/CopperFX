#ifndef SCN_BASE_LEXER_H
#define SCN_BASE_LEXER_H

#include <vector>

typedef const char* ConstString;

class SCN_BaseLexer {
	public:
		typedef std::vector<int> IntArray;
		typedef std::vector<float> FloatArray;
		typedef std::vector<ConstString> StringArray;

		enum TokenType {
			Tk_Int,
			Tk_Float,
			Tk_String,
			Tk_Array,
			Tk_CommandEnd
		};

		// When error encounterd we can use this to skip everything until next command
		// By doing this we can recover from errors and still doing something
		virtual void skipUntilCommand() = 0;

		virtual void pushInput(std::istream& inStream, const std::string& streamName) = 0;

		/* If the stream is the last on the input stack, the lexer reverts to
     * null input for which parseNextCommand() has no effect.
     */
    virtual void popInput() = 0;


    virtual const char* nextRequest() = 0;


		/// Read an integer from the input
		int getInt();
		
		/// Read a float from the input
		float getFloat()0;

		/// Read a string from the input
		const char* getString();

		/// Read an integer from the input
		// in [int1, int2 ... intx ] or int1 int2 ... intx
		IntArray getIntArray();

		/// Read a float from the input
		// in [float1, float2 ... floatx ] or float1 float2 ... floatx
		FloatArray getFloatArray(int length = -1);

		/// Read a string from the input
		// in [string1, string2 ... stringx ] or string1 string2 ... stringx
		StringArray getStringArray();


		TokenType peekNextType();
}

#endif // BASE_LEXER_H