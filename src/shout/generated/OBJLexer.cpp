
// Generated from /Users/max/dev/shout/src/shout_lib/OBJ.g4 by ANTLR 4.7.1


#include "OBJLexer.h"


using namespace antlr4;

using namespace shout;

OBJLexer::OBJLexer(CharStream *input) : Lexer(input) {
  _interpreter = new atn::LexerATNSimulator(this, _atn, _decisionToDFA, _sharedContextCache);
}

OBJLexer::~OBJLexer() {
  delete _interpreter;
}

std::string OBJLexer::getGrammarFileName() const {
  return "OBJ.g4";
}

const std::vector<std::string>& OBJLexer::getRuleNames() const {
  return _ruleNames;
}

const std::vector<std::string>& OBJLexer::getChannelNames() const {
  return _channelNames;
}

const std::vector<std::string>& OBJLexer::getModeNames() const {
  return _modeNames;
}

const std::vector<std::string>& OBJLexer::getTokenNames() const {
  return _tokenNames;
}

dfa::Vocabulary& OBJLexer::getVocabulary() const {
  return _vocabulary;
}

const std::vector<uint16_t> OBJLexer::getSerializedATN() const {
  return _serializedATN;
}

const atn::ATN& OBJLexer::getATN() const {
  return _atn;
}




// Static vars and initialization.
std::vector<dfa::DFA> OBJLexer::_decisionToDFA;
atn::PredictionContextCache OBJLexer::_sharedContextCache;

// We own the ATN which in turn owns the ATN states.
atn::ATN OBJLexer::_atn;
std::vector<uint16_t> OBJLexer::_serializedATN;

std::vector<std::string> OBJLexer::_ruleNames = {
  u8"T__0", u8"T__1", u8"T__2", u8"T__3", u8"T__4", u8"GEOMETRIC_VERTEX", 
  u8"TEXTURE_VERTEX", u8"VERTEX_NORMAL", u8"PARAMETER_SPACE_VERTEX", u8"DEGREE", 
  u8"BASIS_MATRIX", u8"STEP_SIZE", u8"CURVE_SURF_TYPE", u8"POINT", u8"LINE", 
  u8"FACE", u8"CURVE", u8"CURVE2D", u8"SURF", u8"PARAM", u8"OUTER_TRIMMING_HOLE", 
  u8"INNER_TRIMMING_HOLE", u8"SPECIAL_CURVE", u8"SPECIAL_POINT", u8"END", 
  u8"CONNECT", u8"GROUP_NAME", u8"SMOOTHING_GROUP", u8"MERGING_GROUP", u8"OBJECT_NAME", 
  u8"BEVEL_INTERPOLATION", u8"COLOR_INTERPOLATION", u8"DISSOLVE_INTERPOLATION", 
  u8"LEVEL_OF_DETAIL", u8"MATERIAL_NAME", u8"MATERIAL_LIBRARY", u8"SHADOW_CASTING", 
  u8"RAY_TRACING", u8"CURVE_APPROX", u8"SURF_APPROX", u8"DIGIT", u8"INTEGER", 
  u8"DECIMAL", u8"COMMENT", u8"NAME", u8"WS"
};

std::vector<std::string> OBJLexer::_channelNames = {
  "DEFAULT_TOKEN_CHANNEL", "HIDDEN"
};

std::vector<std::string> OBJLexer::_modeNames = {
  u8"DEFAULT_MODE"
};

std::vector<std::string> OBJLexer::_literalNames = {
  "", u8"'\r'", u8"'\n'", u8"'.mtl'", u8"'on'", u8"'off'", u8"'v'", u8"'vt'", 
  u8"'vn'", u8"'vp'", u8"'deg'", u8"'bmat'", u8"'step'", u8"'cstype'", u8"'p'", 
  u8"'l'", u8"'f'", u8"'curv'", u8"'curv2'", u8"'surf'", u8"'parm'", u8"'trim'", 
  u8"'hole'", u8"'scrv'", u8"'sp'", u8"'end'", u8"'con'", u8"'g'", u8"'s'", 
  u8"'mg'", u8"'o'", u8"'bevel'", u8"'c_interp'", u8"'d_interp'", u8"'lod'", 
  u8"'usemtl'", u8"'mtllib'", u8"'shadow_obj'", u8"'trace_obj'", u8"'ctech'", 
  u8"'stech'"
};

std::vector<std::string> OBJLexer::_symbolicNames = {
  "", "", "", "", "", "", u8"GEOMETRIC_VERTEX", u8"TEXTURE_VERTEX", u8"VERTEX_NORMAL", 
  u8"PARAMETER_SPACE_VERTEX", u8"DEGREE", u8"BASIS_MATRIX", u8"STEP_SIZE", 
  u8"CURVE_SURF_TYPE", u8"POINT", u8"LINE", u8"FACE", u8"CURVE", u8"CURVE2D", 
  u8"SURF", u8"PARAM", u8"OUTER_TRIMMING_HOLE", u8"INNER_TRIMMING_HOLE", 
  u8"SPECIAL_CURVE", u8"SPECIAL_POINT", u8"END", u8"CONNECT", u8"GROUP_NAME", 
  u8"SMOOTHING_GROUP", u8"MERGING_GROUP", u8"OBJECT_NAME", u8"BEVEL_INTERPOLATION", 
  u8"COLOR_INTERPOLATION", u8"DISSOLVE_INTERPOLATION", u8"LEVEL_OF_DETAIL", 
  u8"MATERIAL_NAME", u8"MATERIAL_LIBRARY", u8"SHADOW_CASTING", u8"RAY_TRACING", 
  u8"CURVE_APPROX", u8"SURF_APPROX", u8"INTEGER", u8"DECIMAL", u8"COMMENT", 
  u8"NAME", u8"WS"
};

dfa::Vocabulary OBJLexer::_vocabulary(_literalNames, _symbolicNames);

std::vector<std::string> OBJLexer::_tokenNames;

OBJLexer::Initializer::Initializer() {
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
    0x2, 0x2f, 0x146, 0x8, 0x1, 0x4, 0x2, 0x9, 0x2, 0x4, 0x3, 0x9, 0x3, 
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
    0x9, 0x28, 0x4, 0x29, 0x9, 0x29, 0x4, 0x2a, 0x9, 0x2a, 0x4, 0x2b, 0x9, 
    0x2b, 0x4, 0x2c, 0x9, 0x2c, 0x4, 0x2d, 0x9, 0x2d, 0x4, 0x2e, 0x9, 0x2e, 
    0x4, 0x2f, 0x9, 0x2f, 0x3, 0x2, 0x3, 0x2, 0x3, 0x3, 0x3, 0x3, 0x3, 0x4, 
    0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 
    0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x7, 0x3, 0x7, 0x3, 0x8, 
    0x3, 0x8, 0x3, 0x8, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0xa, 0x3, 0xa, 
    0x3, 0xa, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xc, 0x3, 0xc, 
    0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 
    0x3, 0xd, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 
    0x3, 0xe, 0x3, 0xf, 0x3, 0xf, 0x3, 0x10, 0x3, 0x10, 0x3, 0x11, 0x3, 
    0x11, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 0x13, 
    0x3, 0x13, 0x3, 0x13, 0x3, 0x13, 0x3, 0x13, 0x3, 0x13, 0x3, 0x14, 0x3, 
    0x14, 0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 0x3, 0x15, 0x3, 0x15, 0x3, 0x15, 
    0x3, 0x15, 0x3, 0x15, 0x3, 0x16, 0x3, 0x16, 0x3, 0x16, 0x3, 0x16, 0x3, 
    0x16, 0x3, 0x17, 0x3, 0x17, 0x3, 0x17, 0x3, 0x17, 0x3, 0x17, 0x3, 0x18, 
    0x3, 0x18, 0x3, 0x18, 0x3, 0x18, 0x3, 0x18, 0x3, 0x19, 0x3, 0x19, 0x3, 
    0x19, 0x3, 0x1a, 0x3, 0x1a, 0x3, 0x1a, 0x3, 0x1a, 0x3, 0x1b, 0x3, 0x1b, 
    0x3, 0x1b, 0x3, 0x1b, 0x3, 0x1c, 0x3, 0x1c, 0x3, 0x1d, 0x3, 0x1d, 0x3, 
    0x1e, 0x3, 0x1e, 0x3, 0x1e, 0x3, 0x1f, 0x3, 0x1f, 0x3, 0x20, 0x3, 0x20, 
    0x3, 0x20, 0x3, 0x20, 0x3, 0x20, 0x3, 0x20, 0x3, 0x21, 0x3, 0x21, 0x3, 
    0x21, 0x3, 0x21, 0x3, 0x21, 0x3, 0x21, 0x3, 0x21, 0x3, 0x21, 0x3, 0x21, 
    0x3, 0x22, 0x3, 0x22, 0x3, 0x22, 0x3, 0x22, 0x3, 0x22, 0x3, 0x22, 0x3, 
    0x22, 0x3, 0x22, 0x3, 0x22, 0x3, 0x23, 0x3, 0x23, 0x3, 0x23, 0x3, 0x23, 
    0x3, 0x24, 0x3, 0x24, 0x3, 0x24, 0x3, 0x24, 0x3, 0x24, 0x3, 0x24, 0x3, 
    0x24, 0x3, 0x25, 0x3, 0x25, 0x3, 0x25, 0x3, 0x25, 0x3, 0x25, 0x3, 0x25, 
    0x3, 0x25, 0x3, 0x26, 0x3, 0x26, 0x3, 0x26, 0x3, 0x26, 0x3, 0x26, 0x3, 
    0x26, 0x3, 0x26, 0x3, 0x26, 0x3, 0x26, 0x3, 0x26, 0x3, 0x26, 0x3, 0x27, 
    0x3, 0x27, 0x3, 0x27, 0x3, 0x27, 0x3, 0x27, 0x3, 0x27, 0x3, 0x27, 0x3, 
    0x27, 0x3, 0x27, 0x3, 0x27, 0x3, 0x28, 0x3, 0x28, 0x3, 0x28, 0x3, 0x28, 
    0x3, 0x28, 0x3, 0x28, 0x3, 0x29, 0x3, 0x29, 0x3, 0x29, 0x3, 0x29, 0x3, 
    0x29, 0x3, 0x29, 0x3, 0x2a, 0x3, 0x2a, 0x3, 0x2b, 0x5, 0x2b, 0x11c, 
    0xa, 0x2b, 0x3, 0x2b, 0x6, 0x2b, 0x11f, 0xa, 0x2b, 0xd, 0x2b, 0xe, 0x2b, 
    0x120, 0x3, 0x2c, 0x3, 0x2c, 0x3, 0x2c, 0x7, 0x2c, 0x126, 0xa, 0x2c, 
    0xc, 0x2c, 0xe, 0x2c, 0x129, 0xb, 0x2c, 0x5, 0x2c, 0x12b, 0xa, 0x2c, 
    0x3, 0x2d, 0x3, 0x2d, 0x7, 0x2d, 0x12f, 0xa, 0x2d, 0xc, 0x2d, 0xe, 0x2d, 
    0x132, 0xb, 0x2d, 0x3, 0x2d, 0x5, 0x2d, 0x135, 0xa, 0x2d, 0x3, 0x2d, 
    0x3, 0x2d, 0x3, 0x2d, 0x3, 0x2d, 0x3, 0x2e, 0x6, 0x2e, 0x13c, 0xa, 0x2e, 
    0xd, 0x2e, 0xe, 0x2e, 0x13d, 0x3, 0x2f, 0x6, 0x2f, 0x141, 0xa, 0x2f, 
    0xd, 0x2f, 0xe, 0x2f, 0x142, 0x3, 0x2f, 0x3, 0x2f, 0x2, 0x2, 0x30, 0x3, 
    0x3, 0x5, 0x4, 0x7, 0x5, 0x9, 0x6, 0xb, 0x7, 0xd, 0x8, 0xf, 0x9, 0x11, 
    0xa, 0x13, 0xb, 0x15, 0xc, 0x17, 0xd, 0x19, 0xe, 0x1b, 0xf, 0x1d, 0x10, 
    0x1f, 0x11, 0x21, 0x12, 0x23, 0x13, 0x25, 0x14, 0x27, 0x15, 0x29, 0x16, 
    0x2b, 0x17, 0x2d, 0x18, 0x2f, 0x19, 0x31, 0x1a, 0x33, 0x1b, 0x35, 0x1c, 
    0x37, 0x1d, 0x39, 0x1e, 0x3b, 0x1f, 0x3d, 0x20, 0x3f, 0x21, 0x41, 0x22, 
    0x43, 0x23, 0x45, 0x24, 0x47, 0x25, 0x49, 0x26, 0x4b, 0x27, 0x4d, 0x28, 
    0x4f, 0x29, 0x51, 0x2a, 0x53, 0x2, 0x55, 0x2b, 0x57, 0x2c, 0x59, 0x2d, 
    0x5b, 0x2e, 0x5d, 0x2f, 0x3, 0x2, 0x5, 0x4, 0x2, 0xc, 0xc, 0xf, 0xf, 
    0x9, 0x2, 0x2a, 0x2b, 0x2f, 0x2f, 0x32, 0x3b, 0x43, 0x5c, 0x61, 0x61, 
    0x63, 0x7c, 0x80, 0x80, 0x4, 0x2, 0xb, 0xb, 0x22, 0x22, 0x2, 0x14c, 
    0x2, 0x3, 0x3, 0x2, 0x2, 0x2, 0x2, 0x5, 0x3, 0x2, 0x2, 0x2, 0x2, 0x7, 
    0x3, 0x2, 0x2, 0x2, 0x2, 0x9, 0x3, 0x2, 0x2, 0x2, 0x2, 0xb, 0x3, 0x2, 
    0x2, 0x2, 0x2, 0xd, 0x3, 0x2, 0x2, 0x2, 0x2, 0xf, 0x3, 0x2, 0x2, 0x2, 
    0x2, 0x11, 0x3, 0x2, 0x2, 0x2, 0x2, 0x13, 0x3, 0x2, 0x2, 0x2, 0x2, 0x15, 
    0x3, 0x2, 0x2, 0x2, 0x2, 0x17, 0x3, 0x2, 0x2, 0x2, 0x2, 0x19, 0x3, 0x2, 
    0x2, 0x2, 0x2, 0x1b, 0x3, 0x2, 0x2, 0x2, 0x2, 0x1d, 0x3, 0x2, 0x2, 0x2, 
    0x2, 0x1f, 0x3, 0x2, 0x2, 0x2, 0x2, 0x21, 0x3, 0x2, 0x2, 0x2, 0x2, 0x23, 
    0x3, 0x2, 0x2, 0x2, 0x2, 0x25, 0x3, 0x2, 0x2, 0x2, 0x2, 0x27, 0x3, 0x2, 
    0x2, 0x2, 0x2, 0x29, 0x3, 0x2, 0x2, 0x2, 0x2, 0x2b, 0x3, 0x2, 0x2, 0x2, 
    0x2, 0x2d, 0x3, 0x2, 0x2, 0x2, 0x2, 0x2f, 0x3, 0x2, 0x2, 0x2, 0x2, 0x31, 
    0x3, 0x2, 0x2, 0x2, 0x2, 0x33, 0x3, 0x2, 0x2, 0x2, 0x2, 0x35, 0x3, 0x2, 
    0x2, 0x2, 0x2, 0x37, 0x3, 0x2, 0x2, 0x2, 0x2, 0x39, 0x3, 0x2, 0x2, 0x2, 
    0x2, 0x3b, 0x3, 0x2, 0x2, 0x2, 0x2, 0x3d, 0x3, 0x2, 0x2, 0x2, 0x2, 0x3f, 
    0x3, 0x2, 0x2, 0x2, 0x2, 0x41, 0x3, 0x2, 0x2, 0x2, 0x2, 0x43, 0x3, 0x2, 
    0x2, 0x2, 0x2, 0x45, 0x3, 0x2, 0x2, 0x2, 0x2, 0x47, 0x3, 0x2, 0x2, 0x2, 
    0x2, 0x49, 0x3, 0x2, 0x2, 0x2, 0x2, 0x4b, 0x3, 0x2, 0x2, 0x2, 0x2, 0x4d, 
    0x3, 0x2, 0x2, 0x2, 0x2, 0x4f, 0x3, 0x2, 0x2, 0x2, 0x2, 0x51, 0x3, 0x2, 
    0x2, 0x2, 0x2, 0x55, 0x3, 0x2, 0x2, 0x2, 0x2, 0x57, 0x3, 0x2, 0x2, 0x2, 
    0x2, 0x59, 0x3, 0x2, 0x2, 0x2, 0x2, 0x5b, 0x3, 0x2, 0x2, 0x2, 0x2, 0x5d, 
    0x3, 0x2, 0x2, 0x2, 0x3, 0x5f, 0x3, 0x2, 0x2, 0x2, 0x5, 0x61, 0x3, 0x2, 
    0x2, 0x2, 0x7, 0x63, 0x3, 0x2, 0x2, 0x2, 0x9, 0x68, 0x3, 0x2, 0x2, 0x2, 
    0xb, 0x6b, 0x3, 0x2, 0x2, 0x2, 0xd, 0x6f, 0x3, 0x2, 0x2, 0x2, 0xf, 0x71, 
    0x3, 0x2, 0x2, 0x2, 0x11, 0x74, 0x3, 0x2, 0x2, 0x2, 0x13, 0x77, 0x3, 
    0x2, 0x2, 0x2, 0x15, 0x7a, 0x3, 0x2, 0x2, 0x2, 0x17, 0x7e, 0x3, 0x2, 
    0x2, 0x2, 0x19, 0x83, 0x3, 0x2, 0x2, 0x2, 0x1b, 0x88, 0x3, 0x2, 0x2, 
    0x2, 0x1d, 0x8f, 0x3, 0x2, 0x2, 0x2, 0x1f, 0x91, 0x3, 0x2, 0x2, 0x2, 
    0x21, 0x93, 0x3, 0x2, 0x2, 0x2, 0x23, 0x95, 0x3, 0x2, 0x2, 0x2, 0x25, 
    0x9a, 0x3, 0x2, 0x2, 0x2, 0x27, 0xa0, 0x3, 0x2, 0x2, 0x2, 0x29, 0xa5, 
    0x3, 0x2, 0x2, 0x2, 0x2b, 0xaa, 0x3, 0x2, 0x2, 0x2, 0x2d, 0xaf, 0x3, 
    0x2, 0x2, 0x2, 0x2f, 0xb4, 0x3, 0x2, 0x2, 0x2, 0x31, 0xb9, 0x3, 0x2, 
    0x2, 0x2, 0x33, 0xbc, 0x3, 0x2, 0x2, 0x2, 0x35, 0xc0, 0x3, 0x2, 0x2, 
    0x2, 0x37, 0xc4, 0x3, 0x2, 0x2, 0x2, 0x39, 0xc6, 0x3, 0x2, 0x2, 0x2, 
    0x3b, 0xc8, 0x3, 0x2, 0x2, 0x2, 0x3d, 0xcb, 0x3, 0x2, 0x2, 0x2, 0x3f, 
    0xcd, 0x3, 0x2, 0x2, 0x2, 0x41, 0xd3, 0x3, 0x2, 0x2, 0x2, 0x43, 0xdc, 
    0x3, 0x2, 0x2, 0x2, 0x45, 0xe5, 0x3, 0x2, 0x2, 0x2, 0x47, 0xe9, 0x3, 
    0x2, 0x2, 0x2, 0x49, 0xf0, 0x3, 0x2, 0x2, 0x2, 0x4b, 0xf7, 0x3, 0x2, 
    0x2, 0x2, 0x4d, 0x102, 0x3, 0x2, 0x2, 0x2, 0x4f, 0x10c, 0x3, 0x2, 0x2, 
    0x2, 0x51, 0x112, 0x3, 0x2, 0x2, 0x2, 0x53, 0x118, 0x3, 0x2, 0x2, 0x2, 
    0x55, 0x11b, 0x3, 0x2, 0x2, 0x2, 0x57, 0x122, 0x3, 0x2, 0x2, 0x2, 0x59, 
    0x12c, 0x3, 0x2, 0x2, 0x2, 0x5b, 0x13b, 0x3, 0x2, 0x2, 0x2, 0x5d, 0x140, 
    0x3, 0x2, 0x2, 0x2, 0x5f, 0x60, 0x7, 0xf, 0x2, 0x2, 0x60, 0x4, 0x3, 
    0x2, 0x2, 0x2, 0x61, 0x62, 0x7, 0xc, 0x2, 0x2, 0x62, 0x6, 0x3, 0x2, 
    0x2, 0x2, 0x63, 0x64, 0x7, 0x30, 0x2, 0x2, 0x64, 0x65, 0x7, 0x6f, 0x2, 
    0x2, 0x65, 0x66, 0x7, 0x76, 0x2, 0x2, 0x66, 0x67, 0x7, 0x6e, 0x2, 0x2, 
    0x67, 0x8, 0x3, 0x2, 0x2, 0x2, 0x68, 0x69, 0x7, 0x71, 0x2, 0x2, 0x69, 
    0x6a, 0x7, 0x70, 0x2, 0x2, 0x6a, 0xa, 0x3, 0x2, 0x2, 0x2, 0x6b, 0x6c, 
    0x7, 0x71, 0x2, 0x2, 0x6c, 0x6d, 0x7, 0x68, 0x2, 0x2, 0x6d, 0x6e, 0x7, 
    0x68, 0x2, 0x2, 0x6e, 0xc, 0x3, 0x2, 0x2, 0x2, 0x6f, 0x70, 0x7, 0x78, 
    0x2, 0x2, 0x70, 0xe, 0x3, 0x2, 0x2, 0x2, 0x71, 0x72, 0x7, 0x78, 0x2, 
    0x2, 0x72, 0x73, 0x7, 0x76, 0x2, 0x2, 0x73, 0x10, 0x3, 0x2, 0x2, 0x2, 
    0x74, 0x75, 0x7, 0x78, 0x2, 0x2, 0x75, 0x76, 0x7, 0x70, 0x2, 0x2, 0x76, 
    0x12, 0x3, 0x2, 0x2, 0x2, 0x77, 0x78, 0x7, 0x78, 0x2, 0x2, 0x78, 0x79, 
    0x7, 0x72, 0x2, 0x2, 0x79, 0x14, 0x3, 0x2, 0x2, 0x2, 0x7a, 0x7b, 0x7, 
    0x66, 0x2, 0x2, 0x7b, 0x7c, 0x7, 0x67, 0x2, 0x2, 0x7c, 0x7d, 0x7, 0x69, 
    0x2, 0x2, 0x7d, 0x16, 0x3, 0x2, 0x2, 0x2, 0x7e, 0x7f, 0x7, 0x64, 0x2, 
    0x2, 0x7f, 0x80, 0x7, 0x6f, 0x2, 0x2, 0x80, 0x81, 0x7, 0x63, 0x2, 0x2, 
    0x81, 0x82, 0x7, 0x76, 0x2, 0x2, 0x82, 0x18, 0x3, 0x2, 0x2, 0x2, 0x83, 
    0x84, 0x7, 0x75, 0x2, 0x2, 0x84, 0x85, 0x7, 0x76, 0x2, 0x2, 0x85, 0x86, 
    0x7, 0x67, 0x2, 0x2, 0x86, 0x87, 0x7, 0x72, 0x2, 0x2, 0x87, 0x1a, 0x3, 
    0x2, 0x2, 0x2, 0x88, 0x89, 0x7, 0x65, 0x2, 0x2, 0x89, 0x8a, 0x7, 0x75, 
    0x2, 0x2, 0x8a, 0x8b, 0x7, 0x76, 0x2, 0x2, 0x8b, 0x8c, 0x7, 0x7b, 0x2, 
    0x2, 0x8c, 0x8d, 0x7, 0x72, 0x2, 0x2, 0x8d, 0x8e, 0x7, 0x67, 0x2, 0x2, 
    0x8e, 0x1c, 0x3, 0x2, 0x2, 0x2, 0x8f, 0x90, 0x7, 0x72, 0x2, 0x2, 0x90, 
    0x1e, 0x3, 0x2, 0x2, 0x2, 0x91, 0x92, 0x7, 0x6e, 0x2, 0x2, 0x92, 0x20, 
    0x3, 0x2, 0x2, 0x2, 0x93, 0x94, 0x7, 0x68, 0x2, 0x2, 0x94, 0x22, 0x3, 
    0x2, 0x2, 0x2, 0x95, 0x96, 0x7, 0x65, 0x2, 0x2, 0x96, 0x97, 0x7, 0x77, 
    0x2, 0x2, 0x97, 0x98, 0x7, 0x74, 0x2, 0x2, 0x98, 0x99, 0x7, 0x78, 0x2, 
    0x2, 0x99, 0x24, 0x3, 0x2, 0x2, 0x2, 0x9a, 0x9b, 0x7, 0x65, 0x2, 0x2, 
    0x9b, 0x9c, 0x7, 0x77, 0x2, 0x2, 0x9c, 0x9d, 0x7, 0x74, 0x2, 0x2, 0x9d, 
    0x9e, 0x7, 0x78, 0x2, 0x2, 0x9e, 0x9f, 0x7, 0x34, 0x2, 0x2, 0x9f, 0x26, 
    0x3, 0x2, 0x2, 0x2, 0xa0, 0xa1, 0x7, 0x75, 0x2, 0x2, 0xa1, 0xa2, 0x7, 
    0x77, 0x2, 0x2, 0xa2, 0xa3, 0x7, 0x74, 0x2, 0x2, 0xa3, 0xa4, 0x7, 0x68, 
    0x2, 0x2, 0xa4, 0x28, 0x3, 0x2, 0x2, 0x2, 0xa5, 0xa6, 0x7, 0x72, 0x2, 
    0x2, 0xa6, 0xa7, 0x7, 0x63, 0x2, 0x2, 0xa7, 0xa8, 0x7, 0x74, 0x2, 0x2, 
    0xa8, 0xa9, 0x7, 0x6f, 0x2, 0x2, 0xa9, 0x2a, 0x3, 0x2, 0x2, 0x2, 0xaa, 
    0xab, 0x7, 0x76, 0x2, 0x2, 0xab, 0xac, 0x7, 0x74, 0x2, 0x2, 0xac, 0xad, 
    0x7, 0x6b, 0x2, 0x2, 0xad, 0xae, 0x7, 0x6f, 0x2, 0x2, 0xae, 0x2c, 0x3, 
    0x2, 0x2, 0x2, 0xaf, 0xb0, 0x7, 0x6a, 0x2, 0x2, 0xb0, 0xb1, 0x7, 0x71, 
    0x2, 0x2, 0xb1, 0xb2, 0x7, 0x6e, 0x2, 0x2, 0xb2, 0xb3, 0x7, 0x67, 0x2, 
    0x2, 0xb3, 0x2e, 0x3, 0x2, 0x2, 0x2, 0xb4, 0xb5, 0x7, 0x75, 0x2, 0x2, 
    0xb5, 0xb6, 0x7, 0x65, 0x2, 0x2, 0xb6, 0xb7, 0x7, 0x74, 0x2, 0x2, 0xb7, 
    0xb8, 0x7, 0x78, 0x2, 0x2, 0xb8, 0x30, 0x3, 0x2, 0x2, 0x2, 0xb9, 0xba, 
    0x7, 0x75, 0x2, 0x2, 0xba, 0xbb, 0x7, 0x72, 0x2, 0x2, 0xbb, 0x32, 0x3, 
    0x2, 0x2, 0x2, 0xbc, 0xbd, 0x7, 0x67, 0x2, 0x2, 0xbd, 0xbe, 0x7, 0x70, 
    0x2, 0x2, 0xbe, 0xbf, 0x7, 0x66, 0x2, 0x2, 0xbf, 0x34, 0x3, 0x2, 0x2, 
    0x2, 0xc0, 0xc1, 0x7, 0x65, 0x2, 0x2, 0xc1, 0xc2, 0x7, 0x71, 0x2, 0x2, 
    0xc2, 0xc3, 0x7, 0x70, 0x2, 0x2, 0xc3, 0x36, 0x3, 0x2, 0x2, 0x2, 0xc4, 
    0xc5, 0x7, 0x69, 0x2, 0x2, 0xc5, 0x38, 0x3, 0x2, 0x2, 0x2, 0xc6, 0xc7, 
    0x7, 0x75, 0x2, 0x2, 0xc7, 0x3a, 0x3, 0x2, 0x2, 0x2, 0xc8, 0xc9, 0x7, 
    0x6f, 0x2, 0x2, 0xc9, 0xca, 0x7, 0x69, 0x2, 0x2, 0xca, 0x3c, 0x3, 0x2, 
    0x2, 0x2, 0xcb, 0xcc, 0x7, 0x71, 0x2, 0x2, 0xcc, 0x3e, 0x3, 0x2, 0x2, 
    0x2, 0xcd, 0xce, 0x7, 0x64, 0x2, 0x2, 0xce, 0xcf, 0x7, 0x67, 0x2, 0x2, 
    0xcf, 0xd0, 0x7, 0x78, 0x2, 0x2, 0xd0, 0xd1, 0x7, 0x67, 0x2, 0x2, 0xd1, 
    0xd2, 0x7, 0x6e, 0x2, 0x2, 0xd2, 0x40, 0x3, 0x2, 0x2, 0x2, 0xd3, 0xd4, 
    0x7, 0x65, 0x2, 0x2, 0xd4, 0xd5, 0x7, 0x61, 0x2, 0x2, 0xd5, 0xd6, 0x7, 
    0x6b, 0x2, 0x2, 0xd6, 0xd7, 0x7, 0x70, 0x2, 0x2, 0xd7, 0xd8, 0x7, 0x76, 
    0x2, 0x2, 0xd8, 0xd9, 0x7, 0x67, 0x2, 0x2, 0xd9, 0xda, 0x7, 0x74, 0x2, 
    0x2, 0xda, 0xdb, 0x7, 0x72, 0x2, 0x2, 0xdb, 0x42, 0x3, 0x2, 0x2, 0x2, 
    0xdc, 0xdd, 0x7, 0x66, 0x2, 0x2, 0xdd, 0xde, 0x7, 0x61, 0x2, 0x2, 0xde, 
    0xdf, 0x7, 0x6b, 0x2, 0x2, 0xdf, 0xe0, 0x7, 0x70, 0x2, 0x2, 0xe0, 0xe1, 
    0x7, 0x76, 0x2, 0x2, 0xe1, 0xe2, 0x7, 0x67, 0x2, 0x2, 0xe2, 0xe3, 0x7, 
    0x74, 0x2, 0x2, 0xe3, 0xe4, 0x7, 0x72, 0x2, 0x2, 0xe4, 0x44, 0x3, 0x2, 
    0x2, 0x2, 0xe5, 0xe6, 0x7, 0x6e, 0x2, 0x2, 0xe6, 0xe7, 0x7, 0x71, 0x2, 
    0x2, 0xe7, 0xe8, 0x7, 0x66, 0x2, 0x2, 0xe8, 0x46, 0x3, 0x2, 0x2, 0x2, 
    0xe9, 0xea, 0x7, 0x77, 0x2, 0x2, 0xea, 0xeb, 0x7, 0x75, 0x2, 0x2, 0xeb, 
    0xec, 0x7, 0x67, 0x2, 0x2, 0xec, 0xed, 0x7, 0x6f, 0x2, 0x2, 0xed, 0xee, 
    0x7, 0x76, 0x2, 0x2, 0xee, 0xef, 0x7, 0x6e, 0x2, 0x2, 0xef, 0x48, 0x3, 
    0x2, 0x2, 0x2, 0xf0, 0xf1, 0x7, 0x6f, 0x2, 0x2, 0xf1, 0xf2, 0x7, 0x76, 
    0x2, 0x2, 0xf2, 0xf3, 0x7, 0x6e, 0x2, 0x2, 0xf3, 0xf4, 0x7, 0x6e, 0x2, 
    0x2, 0xf4, 0xf5, 0x7, 0x6b, 0x2, 0x2, 0xf5, 0xf6, 0x7, 0x64, 0x2, 0x2, 
    0xf6, 0x4a, 0x3, 0x2, 0x2, 0x2, 0xf7, 0xf8, 0x7, 0x75, 0x2, 0x2, 0xf8, 
    0xf9, 0x7, 0x6a, 0x2, 0x2, 0xf9, 0xfa, 0x7, 0x63, 0x2, 0x2, 0xfa, 0xfb, 
    0x7, 0x66, 0x2, 0x2, 0xfb, 0xfc, 0x7, 0x71, 0x2, 0x2, 0xfc, 0xfd, 0x7, 
    0x79, 0x2, 0x2, 0xfd, 0xfe, 0x7, 0x61, 0x2, 0x2, 0xfe, 0xff, 0x7, 0x71, 
    0x2, 0x2, 0xff, 0x100, 0x7, 0x64, 0x2, 0x2, 0x100, 0x101, 0x7, 0x6c, 
    0x2, 0x2, 0x101, 0x4c, 0x3, 0x2, 0x2, 0x2, 0x102, 0x103, 0x7, 0x76, 
    0x2, 0x2, 0x103, 0x104, 0x7, 0x74, 0x2, 0x2, 0x104, 0x105, 0x7, 0x63, 
    0x2, 0x2, 0x105, 0x106, 0x7, 0x65, 0x2, 0x2, 0x106, 0x107, 0x7, 0x67, 
    0x2, 0x2, 0x107, 0x108, 0x7, 0x61, 0x2, 0x2, 0x108, 0x109, 0x7, 0x71, 
    0x2, 0x2, 0x109, 0x10a, 0x7, 0x64, 0x2, 0x2, 0x10a, 0x10b, 0x7, 0x6c, 
    0x2, 0x2, 0x10b, 0x4e, 0x3, 0x2, 0x2, 0x2, 0x10c, 0x10d, 0x7, 0x65, 
    0x2, 0x2, 0x10d, 0x10e, 0x7, 0x76, 0x2, 0x2, 0x10e, 0x10f, 0x7, 0x67, 
    0x2, 0x2, 0x10f, 0x110, 0x7, 0x65, 0x2, 0x2, 0x110, 0x111, 0x7, 0x6a, 
    0x2, 0x2, 0x111, 0x50, 0x3, 0x2, 0x2, 0x2, 0x112, 0x113, 0x7, 0x75, 
    0x2, 0x2, 0x113, 0x114, 0x7, 0x76, 0x2, 0x2, 0x114, 0x115, 0x7, 0x67, 
    0x2, 0x2, 0x115, 0x116, 0x7, 0x65, 0x2, 0x2, 0x116, 0x117, 0x7, 0x6a, 
    0x2, 0x2, 0x117, 0x52, 0x3, 0x2, 0x2, 0x2, 0x118, 0x119, 0x4, 0x32, 
    0x3b, 0x2, 0x119, 0x54, 0x3, 0x2, 0x2, 0x2, 0x11a, 0x11c, 0x7, 0x2f, 
    0x2, 0x2, 0x11b, 0x11a, 0x3, 0x2, 0x2, 0x2, 0x11b, 0x11c, 0x3, 0x2, 
    0x2, 0x2, 0x11c, 0x11e, 0x3, 0x2, 0x2, 0x2, 0x11d, 0x11f, 0x5, 0x53, 
    0x2a, 0x2, 0x11e, 0x11d, 0x3, 0x2, 0x2, 0x2, 0x11f, 0x120, 0x3, 0x2, 
    0x2, 0x2, 0x120, 0x11e, 0x3, 0x2, 0x2, 0x2, 0x120, 0x121, 0x3, 0x2, 
    0x2, 0x2, 0x121, 0x56, 0x3, 0x2, 0x2, 0x2, 0x122, 0x12a, 0x5, 0x55, 
    0x2b, 0x2, 0x123, 0x127, 0x7, 0x30, 0x2, 0x2, 0x124, 0x126, 0x5, 0x53, 
    0x2a, 0x2, 0x125, 0x124, 0x3, 0x2, 0x2, 0x2, 0x126, 0x129, 0x3, 0x2, 
    0x2, 0x2, 0x127, 0x125, 0x3, 0x2, 0x2, 0x2, 0x127, 0x128, 0x3, 0x2, 
    0x2, 0x2, 0x128, 0x12b, 0x3, 0x2, 0x2, 0x2, 0x129, 0x127, 0x3, 0x2, 
    0x2, 0x2, 0x12a, 0x123, 0x3, 0x2, 0x2, 0x2, 0x12a, 0x12b, 0x3, 0x2, 
    0x2, 0x2, 0x12b, 0x58, 0x3, 0x2, 0x2, 0x2, 0x12c, 0x130, 0x7, 0x25, 
    0x2, 0x2, 0x12d, 0x12f, 0xa, 0x2, 0x2, 0x2, 0x12e, 0x12d, 0x3, 0x2, 
    0x2, 0x2, 0x12f, 0x132, 0x3, 0x2, 0x2, 0x2, 0x130, 0x12e, 0x3, 0x2, 
    0x2, 0x2, 0x130, 0x131, 0x3, 0x2, 0x2, 0x2, 0x131, 0x134, 0x3, 0x2, 
    0x2, 0x2, 0x132, 0x130, 0x3, 0x2, 0x2, 0x2, 0x133, 0x135, 0x7, 0xf, 
    0x2, 0x2, 0x134, 0x133, 0x3, 0x2, 0x2, 0x2, 0x134, 0x135, 0x3, 0x2, 
    0x2, 0x2, 0x135, 0x136, 0x3, 0x2, 0x2, 0x2, 0x136, 0x137, 0x7, 0xc, 
    0x2, 0x2, 0x137, 0x138, 0x3, 0x2, 0x2, 0x2, 0x138, 0x139, 0x8, 0x2d, 
    0x2, 0x2, 0x139, 0x5a, 0x3, 0x2, 0x2, 0x2, 0x13a, 0x13c, 0x9, 0x3, 0x2, 
    0x2, 0x13b, 0x13a, 0x3, 0x2, 0x2, 0x2, 0x13c, 0x13d, 0x3, 0x2, 0x2, 
    0x2, 0x13d, 0x13b, 0x3, 0x2, 0x2, 0x2, 0x13d, 0x13e, 0x3, 0x2, 0x2, 
    0x2, 0x13e, 0x5c, 0x3, 0x2, 0x2, 0x2, 0x13f, 0x141, 0x9, 0x4, 0x2, 0x2, 
    0x140, 0x13f, 0x3, 0x2, 0x2, 0x2, 0x141, 0x142, 0x3, 0x2, 0x2, 0x2, 
    0x142, 0x140, 0x3, 0x2, 0x2, 0x2, 0x142, 0x143, 0x3, 0x2, 0x2, 0x2, 
    0x143, 0x144, 0x3, 0x2, 0x2, 0x2, 0x144, 0x145, 0x8, 0x2f, 0x2, 0x2, 
    0x145, 0x5e, 0x3, 0x2, 0x2, 0x2, 0xb, 0x2, 0x11b, 0x120, 0x127, 0x12a, 
    0x130, 0x134, 0x13d, 0x142, 0x3, 0x8, 0x2, 0x2, 
  };

  atn::ATNDeserializer deserializer;
  _atn = deserializer.deserialize(_serializedATN);

  size_t count = _atn.getNumberOfDecisions();
  _decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    _decisionToDFA.emplace_back(_atn.getDecisionState(i), i);
  }
}

OBJLexer::Initializer OBJLexer::_init;
