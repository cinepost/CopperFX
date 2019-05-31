#include <iostream>
#include <string>
#include <locale>
#include <codecvt>

#include "BinaryAntlrInputStream.h"


BinaryANTLRInputStream::BinaryANTLRInputStream(std::istream &stream) {
	p = 0;
	load(stream);
}

void BinaryANTLRInputStream::load(const std::string &input) {
	//wchar_t w;
  for(const char& c : input) {
  	if (c > 0) {
  		// valid ascii character
  		_data += c;
  	}
  }
  p = 0;
}


void BinaryANTLRInputStream::load(std::istream &stream) {
if (!stream.good() || stream.eof()) // No fail, bad or EOF.
    return;

  _data.clear();
  
  // read the UTF8 file, skipping the BOM
	stream.imbue(std::locale(stream.getloc(),
		new std::codecvt_utf8<wchar_t, 0x10ffff, std::consume_header>));

	std::string content( (std::istreambuf_iterator<char>(stream) ), (std::istreambuf_iterator<char>()   ) );
	load(content);
}
