
// Generated from /Users/max/dev/CopperFX/src/shout/shout_lib/IFD.g4 by ANTLR 4.7.1


#include "IFDLexer.h"


using namespace antlr4;

using namespace shout;

IFDLexer::IFDLexer(CharStream *input) : Lexer(input) {
  _interpreter = new atn::LexerATNSimulator(this, _atn, _decisionToDFA, _sharedContextCache);
}

IFDLexer::~IFDLexer() {
  delete _interpreter;
}

std::string IFDLexer::getGrammarFileName() const {
  return "IFD.g4";
}

const std::vector<std::string>& IFDLexer::getRuleNames() const {
  return _ruleNames;
}

const std::vector<std::string>& IFDLexer::getChannelNames() const {
  return _channelNames;
}

const std::vector<std::string>& IFDLexer::getModeNames() const {
  return _modeNames;
}

const std::vector<std::string>& IFDLexer::getTokenNames() const {
  return _tokenNames;
}

dfa::Vocabulary& IFDLexer::getVocabulary() const {
  return _vocabulary;
}

const std::vector<uint16_t> IFDLexer::getSerializedATN() const {
  return _serializedATN;
}

const atn::ATN& IFDLexer::getATN() const {
  return _atn;
}




// Static vars and initialization.
std::vector<dfa::DFA> IFDLexer::_decisionToDFA;
atn::PredictionContextCache IFDLexer::_sharedContextCache;

// We own the ATN which in turn owns the ATN states.
atn::ATN IFDLexer::_atn;
std::vector<uint16_t> IFDLexer::_serializedATN;

std::vector<std::string> IFDLexer::_ruleNames = {
  u8"T__0", u8"T__1", u8"T__2", u8"T__3", u8"T__4", u8"T__5", u8"T__6", 
  u8"T__7", u8"T__8", u8"T__9", u8"T__10", u8"T__11", u8"T__12", u8"T__13", 
  u8"T__14", u8"T__15", u8"PATH", u8"OBJPATH", u8"FILENAME", u8"COMMENT", 
  u8"STREAM", u8"TYPE", u8"OBJECT", u8"VEX_VERSION", u8"VAR_NAME", u8"VALUE", 
  u8"INTEGER", u8"NUMBER", u8"STRING", u8"NO_QUOTED", u8"QUOTED", u8"CHARS", 
  u8"VALID_ID_START", u8"VALID_ID_CHAR", u8"LETTER", u8"INT", u8"EXP", u8"BYTE", 
  u8"BGEO", u8"WS"
};

std::vector<std::string> IFDLexer::_channelNames = {
  "DEFAULT_TOKEN_CHANNEL", "HIDDEN"
};

std::vector<std::string> IFDLexer::_modeNames = {
  u8"DEFAULT_MODE"
};

std::vector<std::string> IFDLexer::_literalNames = {
  "", u8"'setenv'", u8"'='", u8"'ray_version'", u8"'ray_declare'", u8"'ray_start'", 
  u8"'ray_end'", u8"'ray_detail'", u8"'-T'", u8"'-v'", u8"'-V'", u8"'ray_property'", 
  u8"'ray_image'", u8"'ray_geometry'", u8"'ray_time'", u8"'ray_raytrace'", 
  u8"'ray_quit'"
};

std::vector<std::string> IFDLexer::_symbolicNames = {
  "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", u8"PATH", 
  u8"OBJPATH", u8"FILENAME", u8"COMMENT", u8"STREAM", u8"TYPE", u8"OBJECT", 
  u8"VEX_VERSION", u8"VAR_NAME", u8"VALUE", u8"INTEGER", u8"NUMBER", u8"STRING", 
  u8"NO_QUOTED", u8"QUOTED", u8"CHARS", u8"BYTE", u8"BGEO", u8"WS"
};

dfa::Vocabulary IFDLexer::_vocabulary(_literalNames, _symbolicNames);

std::vector<std::string> IFDLexer::_tokenNames;

IFDLexer::Initializer::Initializer() {
  // This code could be in a static initializer lambda, but VS doesn't allow access to private class members from there.
	for (size_t i = 0; i < _symbolicNames.size(); ++i) {
		std::string name = _vocabulary.getLiteralName(i);
		if (name.empty()) {
			name = _vocabulary.getSymbolicName(i);
		}

		if (name.empty()) {
			_tokenNames.push_back("<INVALID>");
		} else {
      _tokenNames.push_back(name);
    }
	}

  _serializedATN = {
    0x3, 0x608b, 0xa72a, 0x8133, 0xb9ed, 0x417c, 0x3be7, 0x7786, 0x5964, 
    0x2, 0x25, 0x1ff, 0x8, 0x1, 0x4, 0x2, 0x9, 0x2, 0x4, 0x3, 0x9, 0x3, 
    0x4, 0x4, 0x9, 0x4, 0x4, 0x5, 0x9, 0x5, 0x4, 0x6, 0x9, 0x6, 0x4, 0x7, 
    0x9, 0x7, 0x4, 0x8, 0x9, 0x8, 0x4, 0x9, 0x9, 0x9, 0x4, 0xa, 0x9, 0xa, 
    0x4, 0xb, 0x9, 0xb, 0x4, 0xc, 0x9, 0xc, 0x4, 0xd, 0x9, 0xd, 0x4, 0xe, 
    0x9, 0xe, 0x4, 0xf, 0x9, 0xf, 0x4, 0x10, 0x9, 0x10, 0x4, 0x11, 0x9, 
    0x11, 0x4, 0x12, 0x9, 0x12, 0x4, 0x13, 0x9, 0x13, 0x4, 0x14, 0x9, 0x14, 
    0x4, 0x15, 0x9, 0x15, 0x4, 0x16, 0x9, 0x16, 0x4, 0x17, 0x9, 0x17, 0x4, 
    0x18, 0x9, 0x18, 0x4, 0x19, 0x9, 0x19, 0x4, 0x1a, 0x9, 0x1a, 0x4, 0x1b, 
    0x9, 0x1b, 0x4, 0x1c, 0x9, 0x1c, 0x4, 0x1d, 0x9, 0x1d, 0x4, 0x1e, 0x9, 
    0x1e, 0x4, 0x1f, 0x9, 0x1f, 0x4, 0x20, 0x9, 0x20, 0x4, 0x21, 0x9, 0x21, 
    0x4, 0x22, 0x9, 0x22, 0x4, 0x23, 0x9, 0x23, 0x4, 0x24, 0x9, 0x24, 0x4, 
    0x25, 0x9, 0x25, 0x4, 0x26, 0x9, 0x26, 0x4, 0x27, 0x9, 0x27, 0x4, 0x28, 
    0x9, 0x28, 0x4, 0x29, 0x9, 0x29, 0x3, 0x2, 0x3, 0x2, 0x3, 0x2, 0x3, 
    0x2, 0x3, 0x2, 0x3, 0x2, 0x3, 0x2, 0x3, 0x3, 0x3, 0x3, 0x3, 0x4, 0x3, 
    0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 
    0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 
    0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 
    0x5, 0x3, 0x5, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 
    0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x7, 0x3, 0x7, 0x3, 
    0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x8, 0x3, 
    0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 
    0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0xa, 0x3, 
    0xa, 0x3, 0xa, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xc, 0x3, 0xc, 0x3, 
    0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 
    0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 
    0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 
    0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 
    0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xf, 0x3, 
    0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 
    0xf, 0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 
    0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 0x3, 
    0x10, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 
    0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 0x12, 0x3, 0x12, 0x3, 0x13, 0x3, 
    0x13, 0x3, 0x14, 0x3, 0x14, 0x3, 0x15, 0x3, 0x15, 0x7, 0x15, 0xe6, 0xa, 
    0x15, 0xc, 0x15, 0xe, 0x15, 0xe9, 0xb, 0x15, 0x3, 0x16, 0x3, 0x16, 0x3, 
    0x16, 0x3, 0x16, 0x3, 0x16, 0x3, 0x16, 0x3, 0x16, 0x7, 0x16, 0xf2, 0xa, 
    0x16, 0xc, 0x16, 0xe, 0x16, 0xf5, 0xb, 0x16, 0x3, 0x16, 0x3, 0x16, 0x3, 
    0x16, 0x3, 0x16, 0x3, 0x16, 0x3, 0x16, 0x3, 0x16, 0x3, 0x16, 0x3, 0x17, 
    0x3, 0x17, 0x3, 0x17, 0x3, 0x17, 0x3, 0x17, 0x3, 0x17, 0x3, 0x17, 0x3, 
    0x17, 0x3, 0x17, 0x3, 0x17, 0x3, 0x17, 0x3, 0x17, 0x3, 0x17, 0x3, 0x17, 
    0x3, 0x17, 0x3, 0x17, 0x3, 0x17, 0x3, 0x17, 0x3, 0x17, 0x3, 0x17, 0x3, 
    0x17, 0x3, 0x17, 0x3, 0x17, 0x3, 0x17, 0x3, 0x17, 0x3, 0x17, 0x3, 0x17, 
    0x3, 0x17, 0x3, 0x17, 0x3, 0x17, 0x3, 0x17, 0x3, 0x17, 0x3, 0x17, 0x3, 
    0x17, 0x3, 0x17, 0x3, 0x17, 0x3, 0x17, 0x3, 0x17, 0x3, 0x17, 0x3, 0x17, 
    0x3, 0x17, 0x3, 0x17, 0x3, 0x17, 0x3, 0x17, 0x3, 0x17, 0x3, 0x17, 0x3, 
    0x17, 0x3, 0x17, 0x3, 0x17, 0x3, 0x17, 0x3, 0x17, 0x3, 0x17, 0x3, 0x17, 
    0x5, 0x17, 0x134, 0xa, 0x17, 0x3, 0x18, 0x3, 0x18, 0x3, 0x18, 0x3, 0x18, 
    0x3, 0x18, 0x3, 0x18, 0x3, 0x18, 0x3, 0x18, 0x3, 0x18, 0x3, 0x18, 0x3, 
    0x18, 0x3, 0x18, 0x3, 0x18, 0x3, 0x18, 0x3, 0x18, 0x3, 0x18, 0x3, 0x18, 
    0x3, 0x18, 0x3, 0x18, 0x3, 0x18, 0x3, 0x18, 0x3, 0x18, 0x3, 0x18, 0x3, 
    0x18, 0x3, 0x18, 0x3, 0x18, 0x3, 0x18, 0x3, 0x18, 0x3, 0x18, 0x3, 0x18, 
    0x3, 0x18, 0x3, 0x18, 0x3, 0x18, 0x3, 0x18, 0x3, 0x18, 0x3, 0x18, 0x3, 
    0x18, 0x3, 0x18, 0x3, 0x18, 0x3, 0x18, 0x3, 0x18, 0x3, 0x18, 0x3, 0x18, 
    0x3, 0x18, 0x3, 0x18, 0x3, 0x18, 0x3, 0x18, 0x3, 0x18, 0x3, 0x18, 0x3, 
    0x18, 0x3, 0x18, 0x3, 0x18, 0x3, 0x18, 0x3, 0x18, 0x3, 0x18, 0x3, 0x18, 
    0x3, 0x18, 0x3, 0x18, 0x3, 0x18, 0x3, 0x18, 0x3, 0x18, 0x3, 0x18, 0x3, 
    0x18, 0x3, 0x18, 0x3, 0x18, 0x3, 0x18, 0x3, 0x18, 0x3, 0x18, 0x3, 0x18, 
    0x3, 0x18, 0x3, 0x18, 0x3, 0x18, 0x3, 0x18, 0x3, 0x18, 0x3, 0x18, 0x3, 
    0x18, 0x3, 0x18, 0x3, 0x18, 0x5, 0x18, 0x184, 0xa, 0x18, 0x3, 0x19, 
    0x3, 0x19, 0x3, 0x19, 0x3, 0x19, 0x3, 0x19, 0x3, 0x19, 0x3, 0x19, 0x7, 
    0x19, 0x18d, 0xa, 0x19, 0xc, 0x19, 0xe, 0x19, 0x190, 0xb, 0x19, 0x3, 
    0x1a, 0x3, 0x1a, 0x7, 0x1a, 0x194, 0xa, 0x1a, 0xc, 0x1a, 0xe, 0x1a, 
    0x197, 0xb, 0x1a, 0x3, 0x1b, 0x3, 0x1b, 0x3, 0x1b, 0x5, 0x1b, 0x19c, 
    0xa, 0x1b, 0x3, 0x1c, 0x3, 0x1c, 0x3, 0x1d, 0x5, 0x1d, 0x1a1, 0xa, 0x1d, 
    0x3, 0x1d, 0x3, 0x1d, 0x3, 0x1d, 0x6, 0x1d, 0x1a6, 0xa, 0x1d, 0xd, 0x1d, 
    0xe, 0x1d, 0x1a7, 0x3, 0x1d, 0x5, 0x1d, 0x1ab, 0xa, 0x1d, 0x3, 0x1d, 
    0x5, 0x1d, 0x1ae, 0xa, 0x1d, 0x3, 0x1d, 0x3, 0x1d, 0x3, 0x1d, 0x3, 0x1d, 
    0x5, 0x1d, 0x1b4, 0xa, 0x1d, 0x3, 0x1d, 0x5, 0x1d, 0x1b7, 0xa, 0x1d, 
    0x3, 0x1e, 0x3, 0x1e, 0x5, 0x1e, 0x1bb, 0xa, 0x1e, 0x3, 0x1f, 0x6, 0x1f, 
    0x1be, 0xa, 0x1f, 0xd, 0x1f, 0xe, 0x1f, 0x1bf, 0x3, 0x20, 0x3, 0x20, 
    0x3, 0x20, 0x7, 0x20, 0x1c5, 0xa, 0x20, 0xc, 0x20, 0xe, 0x20, 0x1c8, 
    0xb, 0x20, 0x3, 0x20, 0x3, 0x20, 0x3, 0x21, 0x6, 0x21, 0x1cd, 0xa, 0x21, 
    0xd, 0x21, 0xe, 0x21, 0x1ce, 0x3, 0x22, 0x3, 0x22, 0x5, 0x22, 0x1d3, 
    0xa, 0x22, 0x3, 0x23, 0x3, 0x23, 0x5, 0x23, 0x1d7, 0xa, 0x23, 0x3, 0x24, 
    0x3, 0x24, 0x3, 0x25, 0x3, 0x25, 0x3, 0x25, 0x7, 0x25, 0x1de, 0xa, 0x25, 
    0xc, 0x25, 0xe, 0x25, 0x1e1, 0xb, 0x25, 0x5, 0x25, 0x1e3, 0xa, 0x25, 
    0x3, 0x26, 0x3, 0x26, 0x5, 0x26, 0x1e7, 0xa, 0x26, 0x3, 0x26, 0x3, 0x26, 
    0x3, 0x27, 0x3, 0x27, 0x3, 0x28, 0x3, 0x28, 0x3, 0x28, 0x3, 0x28, 0x3, 
    0x28, 0x3, 0x28, 0x3, 0x28, 0x7, 0x28, 0x1f4, 0xa, 0x28, 0xc, 0x28, 
    0xe, 0x28, 0x1f7, 0xb, 0x28, 0x3, 0x29, 0x6, 0x29, 0x1fa, 0xa, 0x29, 
    0xd, 0x29, 0xe, 0x29, 0x1fb, 0x3, 0x29, 0x3, 0x29, 0x3, 0xf3, 0x2, 0x2a, 
    0x3, 0x3, 0x5, 0x4, 0x7, 0x5, 0x9, 0x6, 0xb, 0x7, 0xd, 0x8, 0xf, 0x9, 
    0x11, 0xa, 0x13, 0xb, 0x15, 0xc, 0x17, 0xd, 0x19, 0xe, 0x1b, 0xf, 0x1d, 
    0x10, 0x1f, 0x11, 0x21, 0x12, 0x23, 0x13, 0x25, 0x14, 0x27, 0x15, 0x29, 
    0x16, 0x2b, 0x17, 0x2d, 0x18, 0x2f, 0x19, 0x31, 0x1a, 0x33, 0x1b, 0x35, 
    0x1c, 0x37, 0x1d, 0x39, 0x1e, 0x3b, 0x1f, 0x3d, 0x20, 0x3f, 0x21, 0x41, 
    0x22, 0x43, 0x2, 0x45, 0x2, 0x47, 0x2, 0x49, 0x2, 0x4b, 0x2, 0x4d, 0x23, 
    0x4f, 0x24, 0x51, 0x25, 0x3, 0x2, 0xb, 0x4, 0x2, 0xc, 0xc, 0xf, 0xf, 
    0x3, 0x2, 0x32, 0x3b, 0x7, 0x2, 0xb, 0xc, 0xf, 0xf, 0x22, 0x22, 0x24, 
    0x24, 0x29, 0x29, 0x5, 0x2, 0x2d, 0x2d, 0x2f, 0x30, 0x32, 0x3c, 0x4, 
    0x2, 0x43, 0x5c, 0x63, 0x7c, 0x3, 0x2, 0x33, 0x3b, 0x4, 0x2, 0x47, 0x47, 
    0x67, 0x67, 0x4, 0x2, 0x2d, 0x2d, 0x2f, 0x2f, 0x5, 0x2, 0xb, 0xc, 0xf, 
    0xf, 0x22, 0x22, 0x2, 0x226, 0x2, 0x3, 0x3, 0x2, 0x2, 0x2, 0x2, 0x5, 
    0x3, 0x2, 0x2, 0x2, 0x2, 0x7, 0x3, 0x2, 0x2, 0x2, 0x2, 0x9, 0x3, 0x2, 
    0x2, 0x2, 0x2, 0xb, 0x3, 0x2, 0x2, 0x2, 0x2, 0xd, 0x3, 0x2, 0x2, 0x2, 
    0x2, 0xf, 0x3, 0x2, 0x2, 0x2, 0x2, 0x11, 0x3, 0x2, 0x2, 0x2, 0x2, 0x13, 
    0x3, 0x2, 0x2, 0x2, 0x2, 0x15, 0x3, 0x2, 0x2, 0x2, 0x2, 0x17, 0x3, 0x2, 
    0x2, 0x2, 0x2, 0x19, 0x3, 0x2, 0x2, 0x2, 0x2, 0x1b, 0x3, 0x2, 0x2, 0x2, 
    0x2, 0x1d, 0x3, 0x2, 0x2, 0x2, 0x2, 0x1f, 0x3, 0x2, 0x2, 0x2, 0x2, 0x21, 
    0x3, 0x2, 0x2, 0x2, 0x2, 0x23, 0x3, 0x2, 0x2, 0x2, 0x2, 0x25, 0x3, 0x2, 
    0x2, 0x2, 0x2, 0x27, 0x3, 0x2, 0x2, 0x2, 0x2, 0x29, 0x3, 0x2, 0x2, 0x2, 
    0x2, 0x2b, 0x3, 0x2, 0x2, 0x2, 0x2, 0x2d, 0x3, 0x2, 0x2, 0x2, 0x2, 0x2f, 
    0x3, 0x2, 0x2, 0x2, 0x2, 0x31, 0x3, 0x2, 0x2, 0x2, 0x2, 0x33, 0x3, 0x2, 
    0x2, 0x2, 0x2, 0x35, 0x3, 0x2, 0x2, 0x2, 0x2, 0x37, 0x3, 0x2, 0x2, 0x2, 
    0x2, 0x39, 0x3, 0x2, 0x2, 0x2, 0x2, 0x3b, 0x3, 0x2, 0x2, 0x2, 0x2, 0x3d, 
    0x3, 0x2, 0x2, 0x2, 0x2, 0x3f, 0x3, 0x2, 0x2, 0x2, 0x2, 0x41, 0x3, 0x2, 
    0x2, 0x2, 0x2, 0x4d, 0x3, 0x2, 0x2, 0x2, 0x2, 0x4f, 0x3, 0x2, 0x2, 0x2, 
    0x2, 0x51, 0x3, 0x2, 0x2, 0x2, 0x3, 0x53, 0x3, 0x2, 0x2, 0x2, 0x5, 0x5a, 
    0x3, 0x2, 0x2, 0x2, 0x7, 0x5c, 0x3, 0x2, 0x2, 0x2, 0x9, 0x68, 0x3, 0x2, 
    0x2, 0x2, 0xb, 0x74, 0x3, 0x2, 0x2, 0x2, 0xd, 0x7e, 0x3, 0x2, 0x2, 0x2, 
    0xf, 0x86, 0x3, 0x2, 0x2, 0x2, 0x11, 0x91, 0x3, 0x2, 0x2, 0x2, 0x13, 
    0x94, 0x3, 0x2, 0x2, 0x2, 0x15, 0x97, 0x3, 0x2, 0x2, 0x2, 0x17, 0x9a, 
    0x3, 0x2, 0x2, 0x2, 0x19, 0xa7, 0x3, 0x2, 0x2, 0x2, 0x1b, 0xb1, 0x3, 
    0x2, 0x2, 0x2, 0x1d, 0xbe, 0x3, 0x2, 0x2, 0x2, 0x1f, 0xc7, 0x3, 0x2, 
    0x2, 0x2, 0x21, 0xd4, 0x3, 0x2, 0x2, 0x2, 0x23, 0xdd, 0x3, 0x2, 0x2, 
    0x2, 0x25, 0xdf, 0x3, 0x2, 0x2, 0x2, 0x27, 0xe1, 0x3, 0x2, 0x2, 0x2, 
    0x29, 0xe3, 0x3, 0x2, 0x2, 0x2, 0x2b, 0xea, 0x3, 0x2, 0x2, 0x2, 0x2d, 
    0x133, 0x3, 0x2, 0x2, 0x2, 0x2f, 0x183, 0x3, 0x2, 0x2, 0x2, 0x31, 0x185, 
    0x3, 0x2, 0x2, 0x2, 0x33, 0x191, 0x3, 0x2, 0x2, 0x2, 0x35, 0x19b, 0x3, 
    0x2, 0x2, 0x2, 0x37, 0x19d, 0x3, 0x2, 0x2, 0x2, 0x39, 0x1b6, 0x3, 0x2, 
    0x2, 0x2, 0x3b, 0x1ba, 0x3, 0x2, 0x2, 0x2, 0x3d, 0x1bd, 0x3, 0x2, 0x2, 
    0x2, 0x3f, 0x1c1, 0x3, 0x2, 0x2, 0x2, 0x41, 0x1cc, 0x3, 0x2, 0x2, 0x2, 
    0x43, 0x1d2, 0x3, 0x2, 0x2, 0x2, 0x45, 0x1d6, 0x3, 0x2, 0x2, 0x2, 0x47, 
    0x1d8, 0x3, 0x2, 0x2, 0x2, 0x49, 0x1e2, 0x3, 0x2, 0x2, 0x2, 0x4b, 0x1e4, 
    0x3, 0x2, 0x2, 0x2, 0x4d, 0x1ea, 0x3, 0x2, 0x2, 0x2, 0x4f, 0x1ec, 0x3, 
    0x2, 0x2, 0x2, 0x51, 0x1f9, 0x3, 0x2, 0x2, 0x2, 0x53, 0x54, 0x7, 0x75, 
    0x2, 0x2, 0x54, 0x55, 0x7, 0x67, 0x2, 0x2, 0x55, 0x56, 0x7, 0x76, 0x2, 
    0x2, 0x56, 0x57, 0x7, 0x67, 0x2, 0x2, 0x57, 0x58, 0x7, 0x70, 0x2, 0x2, 
    0x58, 0x59, 0x7, 0x78, 0x2, 0x2, 0x59, 0x4, 0x3, 0x2, 0x2, 0x2, 0x5a, 
    0x5b, 0x7, 0x3f, 0x2, 0x2, 0x5b, 0x6, 0x3, 0x2, 0x2, 0x2, 0x5c, 0x5d, 
    0x7, 0x74, 0x2, 0x2, 0x5d, 0x5e, 0x7, 0x63, 0x2, 0x2, 0x5e, 0x5f, 0x7, 
    0x7b, 0x2, 0x2, 0x5f, 0x60, 0x7, 0x61, 0x2, 0x2, 0x60, 0x61, 0x7, 0x78, 
    0x2, 0x2, 0x61, 0x62, 0x7, 0x67, 0x2, 0x2, 0x62, 0x63, 0x7, 0x74, 0x2, 
    0x2, 0x63, 0x64, 0x7, 0x75, 0x2, 0x2, 0x64, 0x65, 0x7, 0x6b, 0x2, 0x2, 
    0x65, 0x66, 0x7, 0x71, 0x2, 0x2, 0x66, 0x67, 0x7, 0x70, 0x2, 0x2, 0x67, 
    0x8, 0x3, 0x2, 0x2, 0x2, 0x68, 0x69, 0x7, 0x74, 0x2, 0x2, 0x69, 0x6a, 
    0x7, 0x63, 0x2, 0x2, 0x6a, 0x6b, 0x7, 0x7b, 0x2, 0x2, 0x6b, 0x6c, 0x7, 
    0x61, 0x2, 0x2, 0x6c, 0x6d, 0x7, 0x66, 0x2, 0x2, 0x6d, 0x6e, 0x7, 0x67, 
    0x2, 0x2, 0x6e, 0x6f, 0x7, 0x65, 0x2, 0x2, 0x6f, 0x70, 0x7, 0x6e, 0x2, 
    0x2, 0x70, 0x71, 0x7, 0x63, 0x2, 0x2, 0x71, 0x72, 0x7, 0x74, 0x2, 0x2, 
    0x72, 0x73, 0x7, 0x67, 0x2, 0x2, 0x73, 0xa, 0x3, 0x2, 0x2, 0x2, 0x74, 
    0x75, 0x7, 0x74, 0x2, 0x2, 0x75, 0x76, 0x7, 0x63, 0x2, 0x2, 0x76, 0x77, 
    0x7, 0x7b, 0x2, 0x2, 0x77, 0x78, 0x7, 0x61, 0x2, 0x2, 0x78, 0x79, 0x7, 
    0x75, 0x2, 0x2, 0x79, 0x7a, 0x7, 0x76, 0x2, 0x2, 0x7a, 0x7b, 0x7, 0x63, 
    0x2, 0x2, 0x7b, 0x7c, 0x7, 0x74, 0x2, 0x2, 0x7c, 0x7d, 0x7, 0x76, 0x2, 
    0x2, 0x7d, 0xc, 0x3, 0x2, 0x2, 0x2, 0x7e, 0x7f, 0x7, 0x74, 0x2, 0x2, 
    0x7f, 0x80, 0x7, 0x63, 0x2, 0x2, 0x80, 0x81, 0x7, 0x7b, 0x2, 0x2, 0x81, 
    0x82, 0x7, 0x61, 0x2, 0x2, 0x82, 0x83, 0x7, 0x67, 0x2, 0x2, 0x83, 0x84, 
    0x7, 0x70, 0x2, 0x2, 0x84, 0x85, 0x7, 0x66, 0x2, 0x2, 0x85, 0xe, 0x3, 
    0x2, 0x2, 0x2, 0x86, 0x87, 0x7, 0x74, 0x2, 0x2, 0x87, 0x88, 0x7, 0x63, 
    0x2, 0x2, 0x88, 0x89, 0x7, 0x7b, 0x2, 0x2, 0x89, 0x8a, 0x7, 0x61, 0x2, 
    0x2, 0x8a, 0x8b, 0x7, 0x66, 0x2, 0x2, 0x8b, 0x8c, 0x7, 0x67, 0x2, 0x2, 
    0x8c, 0x8d, 0x7, 0x76, 0x2, 0x2, 0x8d, 0x8e, 0x7, 0x63, 0x2, 0x2, 0x8e, 
    0x8f, 0x7, 0x6b, 0x2, 0x2, 0x8f, 0x90, 0x7, 0x6e, 0x2, 0x2, 0x90, 0x10, 
    0x3, 0x2, 0x2, 0x2, 0x91, 0x92, 0x7, 0x2f, 0x2, 0x2, 0x92, 0x93, 0x7, 
    0x56, 0x2, 0x2, 0x93, 0x12, 0x3, 0x2, 0x2, 0x2, 0x94, 0x95, 0x7, 0x2f, 
    0x2, 0x2, 0x95, 0x96, 0x7, 0x78, 0x2, 0x2, 0x96, 0x14, 0x3, 0x2, 0x2, 
    0x2, 0x97, 0x98, 0x7, 0x2f, 0x2, 0x2, 0x98, 0x99, 0x7, 0x58, 0x2, 0x2, 
    0x99, 0x16, 0x3, 0x2, 0x2, 0x2, 0x9a, 0x9b, 0x7, 0x74, 0x2, 0x2, 0x9b, 
    0x9c, 0x7, 0x63, 0x2, 0x2, 0x9c, 0x9d, 0x7, 0x7b, 0x2, 0x2, 0x9d, 0x9e, 
    0x7, 0x61, 0x2, 0x2, 0x9e, 0x9f, 0x7, 0x72, 0x2, 0x2, 0x9f, 0xa0, 0x7, 
    0x74, 0x2, 0x2, 0xa0, 0xa1, 0x7, 0x71, 0x2, 0x2, 0xa1, 0xa2, 0x7, 0x72, 
    0x2, 0x2, 0xa2, 0xa3, 0x7, 0x67, 0x2, 0x2, 0xa3, 0xa4, 0x7, 0x74, 0x2, 
    0x2, 0xa4, 0xa5, 0x7, 0x76, 0x2, 0x2, 0xa5, 0xa6, 0x7, 0x7b, 0x2, 0x2, 
    0xa6, 0x18, 0x3, 0x2, 0x2, 0x2, 0xa7, 0xa8, 0x7, 0x74, 0x2, 0x2, 0xa8, 
    0xa9, 0x7, 0x63, 0x2, 0x2, 0xa9, 0xaa, 0x7, 0x7b, 0x2, 0x2, 0xaa, 0xab, 
    0x7, 0x61, 0x2, 0x2, 0xab, 0xac, 0x7, 0x6b, 0x2, 0x2, 0xac, 0xad, 0x7, 
    0x6f, 0x2, 0x2, 0xad, 0xae, 0x7, 0x63, 0x2, 0x2, 0xae, 0xaf, 0x7, 0x69, 
    0x2, 0x2, 0xaf, 0xb0, 0x7, 0x67, 0x2, 0x2, 0xb0, 0x1a, 0x3, 0x2, 0x2, 
    0x2, 0xb1, 0xb2, 0x7, 0x74, 0x2, 0x2, 0xb2, 0xb3, 0x7, 0x63, 0x2, 0x2, 
    0xb3, 0xb4, 0x7, 0x7b, 0x2, 0x2, 0xb4, 0xb5, 0x7, 0x61, 0x2, 0x2, 0xb5, 
    0xb6, 0x7, 0x69, 0x2, 0x2, 0xb6, 0xb7, 0x7, 0x67, 0x2, 0x2, 0xb7, 0xb8, 
    0x7, 0x71, 0x2, 0x2, 0xb8, 0xb9, 0x7, 0x6f, 0x2, 0x2, 0xb9, 0xba, 0x7, 
    0x67, 0x2, 0x2, 0xba, 0xbb, 0x7, 0x76, 0x2, 0x2, 0xbb, 0xbc, 0x7, 0x74, 
    0x2, 0x2, 0xbc, 0xbd, 0x7, 0x7b, 0x2, 0x2, 0xbd, 0x1c, 0x3, 0x2, 0x2, 
    0x2, 0xbe, 0xbf, 0x7, 0x74, 0x2, 0x2, 0xbf, 0xc0, 0x7, 0x63, 0x2, 0x2, 
    0xc0, 0xc1, 0x7, 0x7b, 0x2, 0x2, 0xc1, 0xc2, 0x7, 0x61, 0x2, 0x2, 0xc2, 
    0xc3, 0x7, 0x76, 0x2, 0x2, 0xc3, 0xc4, 0x7, 0x6b, 0x2, 0x2, 0xc4, 0xc5, 
    0x7, 0x6f, 0x2, 0x2, 0xc5, 0xc6, 0x7, 0x67, 0x2, 0x2, 0xc6, 0x1e, 0x3, 
    0x2, 0x2, 0x2, 0xc7, 0xc8, 0x7, 0x74, 0x2, 0x2, 0xc8, 0xc9, 0x7, 0x63, 
    0x2, 0x2, 0xc9, 0xca, 0x7, 0x7b, 0x2, 0x2, 0xca, 0xcb, 0x7, 0x61, 0x2, 
    0x2, 0xcb, 0xcc, 0x7, 0x74, 0x2, 0x2, 0xcc, 0xcd, 0x7, 0x63, 0x2, 0x2, 
    0xcd, 0xce, 0x7, 0x7b, 0x2, 0x2, 0xce, 0xcf, 0x7, 0x76, 0x2, 0x2, 0xcf, 
    0xd0, 0x7, 0x74, 0x2, 0x2, 0xd0, 0xd1, 0x7, 0x63, 0x2, 0x2, 0xd1, 0xd2, 
    0x7, 0x65, 0x2, 0x2, 0xd2, 0xd3, 0x7, 0x67, 0x2, 0x2, 0xd3, 0x20, 0x3, 
    0x2, 0x2, 0x2, 0xd4, 0xd5, 0x7, 0x74, 0x2, 0x2, 0xd5, 0xd6, 0x7, 0x63, 
    0x2, 0x2, 0xd6, 0xd7, 0x7, 0x7b, 0x2, 0x2, 0xd7, 0xd8, 0x7, 0x61, 0x2, 
    0x2, 0xd8, 0xd9, 0x7, 0x73, 0x2, 0x2, 0xd9, 0xda, 0x7, 0x77, 0x2, 0x2, 
    0xda, 0xdb, 0x7, 0x6b, 0x2, 0x2, 0xdb, 0xdc, 0x7, 0x76, 0x2, 0x2, 0xdc, 
    0x22, 0x3, 0x2, 0x2, 0x2, 0xdd, 0xde, 0x5, 0x3b, 0x1e, 0x2, 0xde, 0x24, 
    0x3, 0x2, 0x2, 0x2, 0xdf, 0xe0, 0x5, 0x3b, 0x1e, 0x2, 0xe0, 0x26, 0x3, 
    0x2, 0x2, 0x2, 0xe1, 0xe2, 0x5, 0x23, 0x12, 0x2, 0xe2, 0x28, 0x3, 0x2, 
    0x2, 0x2, 0xe3, 0xe7, 0x7, 0x25, 0x2, 0x2, 0xe4, 0xe6, 0xa, 0x2, 0x2, 
    0x2, 0xe5, 0xe4, 0x3, 0x2, 0x2, 0x2, 0xe6, 0xe9, 0x3, 0x2, 0x2, 0x2, 
    0xe7, 0xe5, 0x3, 0x2, 0x2, 0x2, 0xe7, 0xe8, 0x3, 0x2, 0x2, 0x2, 0xe8, 
    0x2a, 0x3, 0x2, 0x2, 0x2, 0xe9, 0xe7, 0x3, 0x2, 0x2, 0x2, 0xea, 0xeb, 
    0x7, 0x75, 0x2, 0x2, 0xeb, 0xec, 0x7, 0x76, 0x2, 0x2, 0xec, 0xed, 0x7, 
    0x66, 0x2, 0x2, 0xed, 0xee, 0x7, 0x6b, 0x2, 0x2, 0xee, 0xef, 0x7, 0x70, 
    0x2, 0x2, 0xef, 0xf3, 0x3, 0x2, 0x2, 0x2, 0xf0, 0xf2, 0xb, 0x2, 0x2, 
    0x2, 0xf1, 0xf0, 0x3, 0x2, 0x2, 0x2, 0xf2, 0xf5, 0x3, 0x2, 0x2, 0x2, 
    0xf3, 0xf4, 0x3, 0x2, 0x2, 0x2, 0xf3, 0xf1, 0x3, 0x2, 0x2, 0x2, 0xf4, 
    0xf6, 0x3, 0x2, 0x2, 0x2, 0xf5, 0xf3, 0x3, 0x2, 0x2, 0x2, 0xf6, 0xf7, 
    0x7, 0x74, 0x2, 0x2, 0xf7, 0xf8, 0x7, 0x63, 0x2, 0x2, 0xf8, 0xf9, 0x7, 
    0x7b, 0x2, 0x2, 0xf9, 0xfa, 0x7, 0x61, 0x2, 0x2, 0xfa, 0xfb, 0x7, 0x67, 
    0x2, 0x2, 0xfb, 0xfc, 0x7, 0x70, 0x2, 0x2, 0xfc, 0xfd, 0x7, 0x66, 0x2, 
    0x2, 0xfd, 0x2c, 0x3, 0x2, 0x2, 0x2, 0xfe, 0xff, 0x7, 0x68, 0x2, 0x2, 
    0xff, 0x100, 0x7, 0x6e, 0x2, 0x2, 0x100, 0x101, 0x7, 0x71, 0x2, 0x2, 
    0x101, 0x102, 0x7, 0x63, 0x2, 0x2, 0x102, 0x134, 0x7, 0x76, 0x2, 0x2, 
    0x103, 0x104, 0x7, 0x64, 0x2, 0x2, 0x104, 0x105, 0x7, 0x71, 0x2, 0x2, 
    0x105, 0x106, 0x7, 0x71, 0x2, 0x2, 0x106, 0x134, 0x7, 0x6e, 0x2, 0x2, 
    0x107, 0x108, 0x7, 0x6b, 0x2, 0x2, 0x108, 0x109, 0x7, 0x70, 0x2, 0x2, 
    0x109, 0x134, 0x7, 0x76, 0x2, 0x2, 0x10a, 0x10b, 0x7, 0x78, 0x2, 0x2, 
    0x10b, 0x10c, 0x7, 0x67, 0x2, 0x2, 0x10c, 0x10d, 0x7, 0x65, 0x2, 0x2, 
    0x10d, 0x10e, 0x7, 0x76, 0x2, 0x2, 0x10e, 0x10f, 0x7, 0x71, 0x2, 0x2, 
    0x10f, 0x110, 0x7, 0x74, 0x2, 0x2, 0x110, 0x134, 0x7, 0x34, 0x2, 0x2, 
    0x111, 0x112, 0x7, 0x78, 0x2, 0x2, 0x112, 0x113, 0x7, 0x67, 0x2, 0x2, 
    0x113, 0x114, 0x7, 0x65, 0x2, 0x2, 0x114, 0x115, 0x7, 0x76, 0x2, 0x2, 
    0x115, 0x116, 0x7, 0x71, 0x2, 0x2, 0x116, 0x117, 0x7, 0x74, 0x2, 0x2, 
    0x117, 0x134, 0x7, 0x35, 0x2, 0x2, 0x118, 0x119, 0x7, 0x78, 0x2, 0x2, 
    0x119, 0x11a, 0x7, 0x67, 0x2, 0x2, 0x11a, 0x11b, 0x7, 0x65, 0x2, 0x2, 
    0x11b, 0x11c, 0x7, 0x76, 0x2, 0x2, 0x11c, 0x11d, 0x7, 0x71, 0x2, 0x2, 
    0x11d, 0x11e, 0x7, 0x74, 0x2, 0x2, 0x11e, 0x134, 0x7, 0x36, 0x2, 0x2, 
    0x11f, 0x120, 0x7, 0x6f, 0x2, 0x2, 0x120, 0x121, 0x7, 0x63, 0x2, 0x2, 
    0x121, 0x122, 0x7, 0x76, 0x2, 0x2, 0x122, 0x123, 0x7, 0x74, 0x2, 0x2, 
    0x123, 0x124, 0x7, 0x6b, 0x2, 0x2, 0x124, 0x125, 0x7, 0x7a, 0x2, 0x2, 
    0x125, 0x134, 0x7, 0x35, 0x2, 0x2, 0x126, 0x127, 0x7, 0x6f, 0x2, 0x2, 
    0x127, 0x128, 0x7, 0x63, 0x2, 0x2, 0x128, 0x129, 0x7, 0x76, 0x2, 0x2, 
    0x129, 0x12a, 0x7, 0x74, 0x2, 0x2, 0x12a, 0x12b, 0x7, 0x6b, 0x2, 0x2, 
    0x12b, 0x12c, 0x7, 0x7a, 0x2, 0x2, 0x12c, 0x134, 0x7, 0x36, 0x2, 0x2, 
    0x12d, 0x12e, 0x7, 0x75, 0x2, 0x2, 0x12e, 0x12f, 0x7, 0x76, 0x2, 0x2, 
    0x12f, 0x130, 0x7, 0x74, 0x2, 0x2, 0x130, 0x131, 0x7, 0x6b, 0x2, 0x2, 
    0x131, 0x132, 0x7, 0x70, 0x2, 0x2, 0x132, 0x134, 0x7, 0x69, 0x2, 0x2, 
    0x133, 0xfe, 0x3, 0x2, 0x2, 0x2, 0x133, 0x103, 0x3, 0x2, 0x2, 0x2, 0x133, 
    0x107, 0x3, 0x2, 0x2, 0x2, 0x133, 0x10a, 0x3, 0x2, 0x2, 0x2, 0x133, 
    0x111, 0x3, 0x2, 0x2, 0x2, 0x133, 0x118, 0x3, 0x2, 0x2, 0x2, 0x133, 
    0x11f, 0x3, 0x2, 0x2, 0x2, 0x133, 0x126, 0x3, 0x2, 0x2, 0x2, 0x133, 
    0x12d, 0x3, 0x2, 0x2, 0x2, 0x134, 0x2e, 0x3, 0x2, 0x2, 0x2, 0x135, 0x136, 
    0x7, 0x69, 0x2, 0x2, 0x136, 0x137, 0x7, 0x6e, 0x2, 0x2, 0x137, 0x138, 
    0x7, 0x71, 0x2, 0x2, 0x138, 0x139, 0x7, 0x64, 0x2, 0x2, 0x139, 0x13a, 
    0x7, 0x63, 0x2, 0x2, 0x13a, 0x184, 0x7, 0x6e, 0x2, 0x2, 0x13b, 0x13c, 
    0x7, 0x6f, 0x2, 0x2, 0x13c, 0x13d, 0x7, 0x63, 0x2, 0x2, 0x13d, 0x13e, 
    0x7, 0x76, 0x2, 0x2, 0x13e, 0x13f, 0x7, 0x67, 0x2, 0x2, 0x13f, 0x140, 
    0x7, 0x74, 0x2, 0x2, 0x140, 0x141, 0x7, 0x6b, 0x2, 0x2, 0x141, 0x142, 
    0x7, 0x63, 0x2, 0x2, 0x142, 0x184, 0x7, 0x6e, 0x2, 0x2, 0x143, 0x144, 
    0x7, 0x69, 0x2, 0x2, 0x144, 0x145, 0x7, 0x67, 0x2, 0x2, 0x145, 0x184, 
    0x7, 0x71, 0x2, 0x2, 0x146, 0x147, 0x7, 0x69, 0x2, 0x2, 0x147, 0x148, 
    0x7, 0x67, 0x2, 0x2, 0x148, 0x149, 0x7, 0x71, 0x2, 0x2, 0x149, 0x14a, 
    0x7, 0x6f, 0x2, 0x2, 0x14a, 0x14b, 0x7, 0x67, 0x2, 0x2, 0x14b, 0x14c, 
    0x7, 0x74, 0x2, 0x2, 0x14c, 0x14d, 0x7, 0x76, 0x2, 0x2, 0x14d, 0x184, 
    0x7, 0x7b, 0x2, 0x2, 0x14e, 0x14f, 0x7, 0x75, 0x2, 0x2, 0x14f, 0x150, 
    0x7, 0x67, 0x2, 0x2, 0x150, 0x151, 0x7, 0x69, 0x2, 0x2, 0x151, 0x152, 
    0x7, 0x6f, 0x2, 0x2, 0x152, 0x153, 0x7, 0x67, 0x2, 0x2, 0x153, 0x154, 
    0x7, 0x70, 0x2, 0x2, 0x154, 0x184, 0x7, 0x76, 0x2, 0x2, 0x155, 0x156, 
    0x7, 0x65, 0x2, 0x2, 0x156, 0x157, 0x7, 0x63, 0x2, 0x2, 0x157, 0x158, 
    0x7, 0x6f, 0x2, 0x2, 0x158, 0x159, 0x7, 0x67, 0x2, 0x2, 0x159, 0x15a, 
    0x7, 0x74, 0x2, 0x2, 0x15a, 0x184, 0x7, 0x63, 0x2, 0x2, 0x15b, 0x15c, 
    0x7, 0x6e, 0x2, 0x2, 0x15c, 0x15d, 0x7, 0x6b, 0x2, 0x2, 0x15d, 0x15e, 
    0x7, 0x69, 0x2, 0x2, 0x15e, 0x15f, 0x7, 0x6a, 0x2, 0x2, 0x15f, 0x184, 
    0x7, 0x76, 0x2, 0x2, 0x160, 0x161, 0x7, 0x68, 0x2, 0x2, 0x161, 0x162, 
    0x7, 0x71, 0x2, 0x2, 0x162, 0x184, 0x7, 0x69, 0x2, 0x2, 0x163, 0x164, 
    0x7, 0x71, 0x2, 0x2, 0x164, 0x165, 0x7, 0x64, 0x2, 0x2, 0x165, 0x166, 
    0x7, 0x6c, 0x2, 0x2, 0x166, 0x167, 0x7, 0x67, 0x2, 0x2, 0x167, 0x168, 
    0x7, 0x65, 0x2, 0x2, 0x168, 0x184, 0x7, 0x76, 0x2, 0x2, 0x169, 0x16a, 
    0x7, 0x6b, 0x2, 0x2, 0x16a, 0x16b, 0x7, 0x70, 0x2, 0x2, 0x16b, 0x16c, 
    0x7, 0x75, 0x2, 0x2, 0x16c, 0x16d, 0x7, 0x76, 0x2, 0x2, 0x16d, 0x16e, 
    0x7, 0x63, 0x2, 0x2, 0x16e, 0x16f, 0x7, 0x70, 0x2, 0x2, 0x16f, 0x170, 
    0x7, 0x65, 0x2, 0x2, 0x170, 0x184, 0x7, 0x67, 0x2, 0x2, 0x171, 0x172, 
    0x7, 0x72, 0x2, 0x2, 0x172, 0x173, 0x7, 0x6e, 0x2, 0x2, 0x173, 0x174, 
    0x7, 0x63, 0x2, 0x2, 0x174, 0x175, 0x7, 0x70, 0x2, 0x2, 0x175, 0x184, 
    0x7, 0x67, 0x2, 0x2, 0x176, 0x177, 0x7, 0x6b, 0x2, 0x2, 0x177, 0x178, 
    0x7, 0x6f, 0x2, 0x2, 0x178, 0x179, 0x7, 0x63, 0x2, 0x2, 0x179, 0x17a, 
    0x7, 0x69, 0x2, 0x2, 0x17a, 0x184, 0x7, 0x67, 0x2, 0x2, 0x17b, 0x17c, 
    0x7, 0x74, 0x2, 0x2, 0x17c, 0x17d, 0x7, 0x67, 0x2, 0x2, 0x17d, 0x17e, 
    0x7, 0x70, 0x2, 0x2, 0x17e, 0x17f, 0x7, 0x66, 0x2, 0x2, 0x17f, 0x180, 
    0x7, 0x67, 0x2, 0x2, 0x180, 0x181, 0x7, 0x74, 0x2, 0x2, 0x181, 0x182, 
    0x7, 0x67, 0x2, 0x2, 0x182, 0x184, 0x7, 0x74, 0x2, 0x2, 0x183, 0x135, 
    0x3, 0x2, 0x2, 0x2, 0x183, 0x13b, 0x3, 0x2, 0x2, 0x2, 0x183, 0x143, 
    0x3, 0x2, 0x2, 0x2, 0x183, 0x146, 0x3, 0x2, 0x2, 0x2, 0x183, 0x14e, 
    0x3, 0x2, 0x2, 0x2, 0x183, 0x155, 0x3, 0x2, 0x2, 0x2, 0x183, 0x15b, 
    0x3, 0x2, 0x2, 0x2, 0x183, 0x160, 0x3, 0x2, 0x2, 0x2, 0x183, 0x163, 
    0x3, 0x2, 0x2, 0x2, 0x183, 0x169, 0x3, 0x2, 0x2, 0x2, 0x183, 0x171, 
    0x3, 0x2, 0x2, 0x2, 0x183, 0x176, 0x3, 0x2, 0x2, 0x2, 0x183, 0x17b, 
    0x3, 0x2, 0x2, 0x2, 0x184, 0x30, 0x3, 0x2, 0x2, 0x2, 0x185, 0x186, 0x7, 
    0x58, 0x2, 0x2, 0x186, 0x187, 0x7, 0x47, 0x2, 0x2, 0x187, 0x188, 0x7, 
    0x5a, 0x2, 0x2, 0x188, 0x189, 0x3, 0x2, 0x2, 0x2, 0x189, 0x18e, 0x5, 
    0x49, 0x25, 0x2, 0x18a, 0x18b, 0x7, 0x30, 0x2, 0x2, 0x18b, 0x18d, 0x5, 
    0x49, 0x25, 0x2, 0x18c, 0x18a, 0x3, 0x2, 0x2, 0x2, 0x18d, 0x190, 0x3, 
    0x2, 0x2, 0x2, 0x18e, 0x18c, 0x3, 0x2, 0x2, 0x2, 0x18e, 0x18f, 0x3, 
    0x2, 0x2, 0x2, 0x18f, 0x32, 0x3, 0x2, 0x2, 0x2, 0x190, 0x18e, 0x3, 0x2, 
    0x2, 0x2, 0x191, 0x195, 0x5, 0x43, 0x22, 0x2, 0x192, 0x194, 0x5, 0x45, 
    0x23, 0x2, 0x193, 0x192, 0x3, 0x2, 0x2, 0x2, 0x194, 0x197, 0x3, 0x2, 
    0x2, 0x2, 0x195, 0x193, 0x3, 0x2, 0x2, 0x2, 0x195, 0x196, 0x3, 0x2, 
    0x2, 0x2, 0x196, 0x34, 0x3, 0x2, 0x2, 0x2, 0x197, 0x195, 0x3, 0x2, 0x2, 
    0x2, 0x198, 0x19c, 0x5, 0x37, 0x1c, 0x2, 0x199, 0x19c, 0x5, 0x39, 0x1d, 
    0x2, 0x19a, 0x19c, 0x5, 0x3b, 0x1e, 0x2, 0x19b, 0x198, 0x3, 0x2, 0x2, 
    0x2, 0x19b, 0x199, 0x3, 0x2, 0x2, 0x2, 0x19b, 0x19a, 0x3, 0x2, 0x2, 
    0x2, 0x19c, 0x36, 0x3, 0x2, 0x2, 0x2, 0x19d, 0x19e, 0x5, 0x49, 0x25, 
    0x2, 0x19e, 0x38, 0x3, 0x2, 0x2, 0x2, 0x19f, 0x1a1, 0x7, 0x2f, 0x2, 
    0x2, 0x1a0, 0x19f, 0x3, 0x2, 0x2, 0x2, 0x1a0, 0x1a1, 0x3, 0x2, 0x2, 
    0x2, 0x1a1, 0x1a2, 0x3, 0x2, 0x2, 0x2, 0x1a2, 0x1a3, 0x5, 0x49, 0x25, 
    0x2, 0x1a3, 0x1a5, 0x7, 0x30, 0x2, 0x2, 0x1a4, 0x1a6, 0x9, 0x3, 0x2, 
    0x2, 0x1a5, 0x1a4, 0x3, 0x2, 0x2, 0x2, 0x1a6, 0x1a7, 0x3, 0x2, 0x2, 
    0x2, 0x1a7, 0x1a5, 0x3, 0x2, 0x2, 0x2, 0x1a7, 0x1a8, 0x3, 0x2, 0x2, 
    0x2, 0x1a8, 0x1aa, 0x3, 0x2, 0x2, 0x2, 0x1a9, 0x1ab, 0x5, 0x4b, 0x26, 
    0x2, 0x1aa, 0x1a9, 0x3, 0x2, 0x2, 0x2, 0x1aa, 0x1ab, 0x3, 0x2, 0x2, 
    0x2, 0x1ab, 0x1b7, 0x3, 0x2, 0x2, 0x2, 0x1ac, 0x1ae, 0x7, 0x2f, 0x2, 
    0x2, 0x1ad, 0x1ac, 0x3, 0x2, 0x2, 0x2, 0x1ad, 0x1ae, 0x3, 0x2, 0x2, 
    0x2, 0x1ae, 0x1af, 0x3, 0x2, 0x2, 0x2, 0x1af, 0x1b0, 0x5, 0x49, 0x25, 
    0x2, 0x1b0, 0x1b1, 0x5, 0x4b, 0x26, 0x2, 0x1b1, 0x1b7, 0x3, 0x2, 0x2, 
    0x2, 0x1b2, 0x1b4, 0x7, 0x2f, 0x2, 0x2, 0x1b3, 0x1b2, 0x3, 0x2, 0x2, 
    0x2, 0x1b3, 0x1b4, 0x3, 0x2, 0x2, 0x2, 0x1b4, 0x1b5, 0x3, 0x2, 0x2, 
    0x2, 0x1b5, 0x1b7, 0x5, 0x49, 0x25, 0x2, 0x1b6, 0x1a0, 0x3, 0x2, 0x2, 
    0x2, 0x1b6, 0x1ad, 0x3, 0x2, 0x2, 0x2, 0x1b6, 0x1b3, 0x3, 0x2, 0x2, 
    0x2, 0x1b7, 0x3a, 0x3, 0x2, 0x2, 0x2, 0x1b8, 0x1bb, 0x5, 0x3f, 0x20, 
    0x2, 0x1b9, 0x1bb, 0x5, 0x3d, 0x1f, 0x2, 0x1ba, 0x1b8, 0x3, 0x2, 0x2, 
    0x2, 0x1ba, 0x1b9, 0x3, 0x2, 0x2, 0x2, 0x1bb, 0x3c, 0x3, 0x2, 0x2, 0x2, 
    0x1bc, 0x1be, 0xa, 0x4, 0x2, 0x2, 0x1bd, 0x1bc, 0x3, 0x2, 0x2, 0x2, 
    0x1be, 0x1bf, 0x3, 0x2, 0x2, 0x2, 0x1bf, 0x1bd, 0x3, 0x2, 0x2, 0x2, 
    0x1bf, 0x1c0, 0x3, 0x2, 0x2, 0x2, 0x1c0, 0x3e, 0x3, 0x2, 0x2, 0x2, 0x1c1, 
    0x1c6, 0x7, 0x24, 0x2, 0x2, 0x1c2, 0x1c5, 0x5, 0x3d, 0x1f, 0x2, 0x1c3, 
    0x1c5, 0x7, 0x22, 0x2, 0x2, 0x1c4, 0x1c2, 0x3, 0x2, 0x2, 0x2, 0x1c4, 
    0x1c3, 0x3, 0x2, 0x2, 0x2, 0x1c5, 0x1c8, 0x3, 0x2, 0x2, 0x2, 0x1c6, 
    0x1c4, 0x3, 0x2, 0x2, 0x2, 0x1c6, 0x1c7, 0x3, 0x2, 0x2, 0x2, 0x1c7, 
    0x1c9, 0x3, 0x2, 0x2, 0x2, 0x1c8, 0x1c6, 0x3, 0x2, 0x2, 0x2, 0x1c9, 
    0x1ca, 0x7, 0x24, 0x2, 0x2, 0x1ca, 0x40, 0x3, 0x2, 0x2, 0x2, 0x1cb, 
    0x1cd, 0x5, 0x47, 0x24, 0x2, 0x1cc, 0x1cb, 0x3, 0x2, 0x2, 0x2, 0x1cd, 
    0x1ce, 0x3, 0x2, 0x2, 0x2, 0x1ce, 0x1cc, 0x3, 0x2, 0x2, 0x2, 0x1ce, 
    0x1cf, 0x3, 0x2, 0x2, 0x2, 0x1cf, 0x42, 0x3, 0x2, 0x2, 0x2, 0x1d0, 0x1d3, 
    0x5, 0x47, 0x24, 0x2, 0x1d1, 0x1d3, 0x7, 0x61, 0x2, 0x2, 0x1d2, 0x1d0, 
    0x3, 0x2, 0x2, 0x2, 0x1d2, 0x1d1, 0x3, 0x2, 0x2, 0x2, 0x1d3, 0x44, 0x3, 
    0x2, 0x2, 0x2, 0x1d4, 0x1d7, 0x5, 0x43, 0x22, 0x2, 0x1d5, 0x1d7, 0x9, 
    0x5, 0x2, 0x2, 0x1d6, 0x1d4, 0x3, 0x2, 0x2, 0x2, 0x1d6, 0x1d5, 0x3, 
    0x2, 0x2, 0x2, 0x1d7, 0x46, 0x3, 0x2, 0x2, 0x2, 0x1d8, 0x1d9, 0x9, 0x6, 
    0x2, 0x2, 0x1d9, 0x48, 0x3, 0x2, 0x2, 0x2, 0x1da, 0x1e3, 0x7, 0x32, 
    0x2, 0x2, 0x1db, 0x1df, 0x9, 0x7, 0x2, 0x2, 0x1dc, 0x1de, 0x9, 0x3, 
    0x2, 0x2, 0x1dd, 0x1dc, 0x3, 0x2, 0x2, 0x2, 0x1de, 0x1e1, 0x3, 0x2, 
    0x2, 0x2, 0x1df, 0x1dd, 0x3, 0x2, 0x2, 0x2, 0x1df, 0x1e0, 0x3, 0x2, 
    0x2, 0x2, 0x1e0, 0x1e3, 0x3, 0x2, 0x2, 0x2, 0x1e1, 0x1df, 0x3, 0x2, 
    0x2, 0x2, 0x1e2, 0x1da, 0x3, 0x2, 0x2, 0x2, 0x1e2, 0x1db, 0x3, 0x2, 
    0x2, 0x2, 0x1e3, 0x4a, 0x3, 0x2, 0x2, 0x2, 0x1e4, 0x1e6, 0x9, 0x8, 0x2, 
    0x2, 0x1e5, 0x1e7, 0x9, 0x9, 0x2, 0x2, 0x1e6, 0x1e5, 0x3, 0x2, 0x2, 
    0x2, 0x1e6, 0x1e7, 0x3, 0x2, 0x2, 0x2, 0x1e7, 0x1e8, 0x3, 0x2, 0x2, 
    0x2, 0x1e8, 0x1e9, 0x5, 0x49, 0x25, 0x2, 0x1e9, 0x4c, 0x3, 0x2, 0x2, 
    0x2, 0x1ea, 0x1eb, 0x4, 0x2, 0x101, 0x2, 0x1eb, 0x4e, 0x3, 0x2, 0x2, 
    0x2, 0x1ec, 0x1ed, 0x7, 0x2, 0x2, 0x2, 0x1ed, 0x1ee, 0x7, 0x50, 0x2, 
    0x2, 0x1ee, 0x1ef, 0x7, 0x55, 0x2, 0x2, 0x1ef, 0x1f0, 0x7, 0x4c, 0x2, 
    0x2, 0x1f0, 0x1f1, 0x7, 0x64, 0x2, 0x2, 0x1f1, 0x1f5, 0x3, 0x2, 0x2, 
    0x2, 0x1f2, 0x1f4, 0x5, 0x4d, 0x27, 0x2, 0x1f3, 0x1f2, 0x3, 0x2, 0x2, 
    0x2, 0x1f4, 0x1f7, 0x3, 0x2, 0x2, 0x2, 0x1f5, 0x1f3, 0x3, 0x2, 0x2, 
    0x2, 0x1f5, 0x1f6, 0x3, 0x2, 0x2, 0x2, 0x1f6, 0x50, 0x3, 0x2, 0x2, 0x2, 
    0x1f7, 0x1f5, 0x3, 0x2, 0x2, 0x2, 0x1f8, 0x1fa, 0x9, 0xa, 0x2, 0x2, 
    0x1f9, 0x1f8, 0x3, 0x2, 0x2, 0x2, 0x1fa, 0x1fb, 0x3, 0x2, 0x2, 0x2, 
    0x1fb, 0x1f9, 0x3, 0x2, 0x2, 0x2, 0x1fb, 0x1fc, 0x3, 0x2, 0x2, 0x2, 
    0x1fc, 0x1fd, 0x3, 0x2, 0x2, 0x2, 0x1fd, 0x1fe, 0x8, 0x29, 0x2, 0x2, 
    0x1fe, 0x52, 0x3, 0x2, 0x2, 0x2, 0x1c, 0x2, 0xe7, 0xf3, 0x133, 0x183, 
    0x18e, 0x195, 0x19b, 0x1a0, 0x1a7, 0x1aa, 0x1ad, 0x1b3, 0x1b6, 0x1ba, 
    0x1bf, 0x1c4, 0x1c6, 0x1ce, 0x1d2, 0x1d6, 0x1df, 0x1e2, 0x1e6, 0x1f5, 
    0x1fb, 0x3, 0x8, 0x2, 0x2, 
  };

  atn::ATNDeserializer deserializer;
  _atn = deserializer.deserialize(_serializedATN);

  size_t count = _atn.getNumberOfDecisions();
  _decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    _decisionToDFA.emplace_back(_atn.getDecisionState(i), i);
  }
}

IFDLexer::Initializer IFDLexer::_init;
