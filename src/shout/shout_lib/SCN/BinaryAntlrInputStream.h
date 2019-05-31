#ifndef ANTLR_BINARY_STREAM_H
#define ANTLR_BINARY_STREAM_H

#include "antlr4-runtime.h"
#include "antlr4/runtime/Cpp/runtime/src/ANTLRInputStream.h"

class BinaryANTLRInputStream: public antlr4::ANTLRInputStream {
	public:
		BinaryANTLRInputStream(std::istream &stream);

	public:
		void load(const std::string &input) override;
		void load(std::istream &stream) override;
};

#endif // ANTLR_BINARY_STERAM_H
