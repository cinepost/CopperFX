#ifndef ANTLR_BINARY_STREAM_H
#define ANTLR_BINARY_STREAM_H

#include <string>

#include "antlr4-runtime.h"
#include "antlr4/runtime/Cpp/runtime/src/ANTLRInputStream.h"
#include "antlr4/runtime/Cpp/runtime/src/CharStream.h"
#include "antlr4/runtime/Cpp/runtime/src/IntStream.h"


class BinaryANTLRInputStream: public antlr4::CharStream {
	public:
		BinaryANTLRInputStream(std::istream &stream);

	public:
		void consume() override;
		size_t LA(ssize_t i) override;
		ssize_t mark() override;
		void release(ssize_t marker) override;
		size_t index() override;
		void seek(size_t index) override;
		size_t size() override;
		std::string getSourceName() const override;
		std::string getText(const antlr4::misc::Interval &interval) override;
		std::string toString() const override;

	private:
		void load(std::istream &stream);

	private:
		size_t p;
		std::string _data;
		std::string _name;
};

#endif // ANTLR_BINARY_STERAM_H
