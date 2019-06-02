#include <iostream>
#include <string>
#include <locale>
#include <codecvt>
#include <chrono>

#include <boost/log/core.hpp>
#include <boost/log/trivial.hpp>
#include <boost/log/expressions.hpp>

#include "antlr4/runtime/Cpp/runtime/src/Exceptions.h"

#include "BinaryAntlrInputStream.h"


using namespace std::chrono;

BinaryANTLRInputStream::BinaryANTLRInputStream(std::istream &stream) {
	p = 0;
	_name.empty();
	load(stream);
}


void BinaryANTLRInputStream::load(std::istream &stream) {
	BOOST_LOG_TRIVIAL(debug) << "BinaryANTLRInputStream loading stream.";
	#ifdef DEBUG
	high_resolution_clock::time_point t_start = high_resolution_clock::now();
	#endif

	if (!stream.good() || stream.eof()) // No fail, bad or EOF.
    return;

  _data.clear();
  
  // read the UTF8 file, skipping the BOM
	stream.imbue(std::locale(stream.getloc(), new std::codecvt_utf8<wchar_t, 0x10ffff, std::consume_header>));

	std::string buff((std::istream_iterator< unsigned char >(stream)), std::istream_iterator< unsigned char >() );
	_data = buff;

	#ifdef DEBUG
	high_resolution_clock::time_point t_end = high_resolution_clock::now();
	auto duration = duration_cast<seconds>( t_end - t_start ).count();
	BOOST_LOG_TRIVIAL(debug) << "Stream loaded in: " << duration << " seconds.";
	#endif

	BOOST_LOG_TRIVIAL(debug) << "BinaryANTLRInputStream stream loaded.";
}

size_t BinaryANTLRInputStream::index() {
	return p;
}

size_t BinaryANTLRInputStream::size() {
	return _data.size();
}

// Mark/release do nothing. We have entire buffer.
ssize_t BinaryANTLRInputStream::mark() {
  return -1;
}

void BinaryANTLRInputStream::release(ssize_t /* marker */) {
}

void BinaryANTLRInputStream::consume() {
  if (p >= _data.size()) {
    assert(LA(1) == IntStream::EOF);
    throw antlr4::IllegalStateException("cannot consume EOF");
  }

  if (p < _data.size()) {
    p++;
  }
}

size_t BinaryANTLRInputStream::LA(ssize_t i) {
  if (i == 0) {
    return 0; // undefined
  }

  ssize_t position = static_cast<ssize_t>(p);
  if (i < 0) {
    i++; // e.g., translate LA(-1) to use offset i=0; then _data[p+0-1]
    if ((position + i - 1) < 0) {
      return IntStream::EOF; // invalid; no char before first char
    }
  }

  if ((position + i - 1) >= static_cast<ssize_t>(_data.size())) {
    return IntStream::EOF;
  }

  return _data[static_cast<size_t>((position + i - 1))];
}

void BinaryANTLRInputStream::seek(size_t index) {
  if (index <= p) {
    p = index; // just jump; don't update stream state (line, ...)
    return;
  }
  // seek forward, consume until p hits index or n (whichever comes first)
  index = std::min(index, _data.size());
  while (p < index) {
    consume();
  }
}

std::string BinaryANTLRInputStream::getSourceName() const {
  if (_name.empty()) {
    return IntStream::UNKNOWN_SOURCE_NAME;
  }
  return _name;
}

std::string BinaryANTLRInputStream::getText(const antlr4::misc::Interval &interval) {
  if (interval.a < 0 || interval.b < 0) {
    return "";
  }

  size_t start = static_cast<size_t>(interval.a);
  size_t stop = static_cast<size_t>(interval.b);


  if (stop >= _data.size()) {
    stop = _data.size() - 1;
  }

  size_t count = stop - start + 1;
  if (start >= _data.size()) {
    return "";
  }

  return _data.substr(start, count);
}

std::string BinaryANTLRInputStream::toString() const {
  return _data;
}


