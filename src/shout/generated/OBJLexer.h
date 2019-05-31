
// Generated from /Users/max/dev/shout/src/shout_lib/OBJ.g4 by ANTLR 4.7.1

#pragma once


#include "antlr4-runtime.h"


namespace shout {


class  OBJLexer : public antlr4::Lexer {
public:
  enum {
    T__0 = 1, T__1 = 2, T__2 = 3, T__3 = 4, T__4 = 5, GEOMETRIC_VERTEX = 6, 
    TEXTURE_VERTEX = 7, VERTEX_NORMAL = 8, PARAMETER_SPACE_VERTEX = 9, DEGREE = 10, 
    BASIS_MATRIX = 11, STEP_SIZE = 12, CURVE_SURF_TYPE = 13, POINT = 14, 
    LINE = 15, FACE = 16, CURVE = 17, CURVE2D = 18, SURF = 19, PARAM = 20, 
    OUTER_TRIMMING_HOLE = 21, INNER_TRIMMING_HOLE = 22, SPECIAL_CURVE = 23, 
    SPECIAL_POINT = 24, END = 25, CONNECT = 26, GROUP_NAME = 27, SMOOTHING_GROUP = 28, 
    MERGING_GROUP = 29, OBJECT_NAME = 30, BEVEL_INTERPOLATION = 31, COLOR_INTERPOLATION = 32, 
    DISSOLVE_INTERPOLATION = 33, LEVEL_OF_DETAIL = 34, MATERIAL_NAME = 35, 
    MATERIAL_LIBRARY = 36, SHADOW_CASTING = 37, RAY_TRACING = 38, CURVE_APPROX = 39, 
    SURF_APPROX = 40, INTEGER = 41, DECIMAL = 42, COMMENT = 43, NAME = 44, 
    WS = 45
  };

  OBJLexer(antlr4::CharStream *input);
  ~OBJLexer();

  virtual std::string getGrammarFileName() const override;
  virtual const std::vector<std::string>& getRuleNames() const override;

  virtual const std::vector<std::string>& getChannelNames() const override;
  virtual const std::vector<std::string>& getModeNames() const override;
  virtual const std::vector<std::string>& getTokenNames() const override; // deprecated, use vocabulary instead
  virtual antlr4::dfa::Vocabulary& getVocabulary() const override;

  virtual const std::vector<uint16_t> getSerializedATN() const override;
  virtual const antlr4::atn::ATN& getATN() const override;

private:
  static std::vector<antlr4::dfa::DFA> _decisionToDFA;
  static antlr4::atn::PredictionContextCache _sharedContextCache;
  static std::vector<std::string> _ruleNames;
  static std::vector<std::string> _tokenNames;
  static std::vector<std::string> _channelNames;
  static std::vector<std::string> _modeNames;

  static std::vector<std::string> _literalNames;
  static std::vector<std::string> _symbolicNames;
  static antlr4::dfa::Vocabulary _vocabulary;
  static antlr4::atn::ATN _atn;
  static std::vector<uint16_t> _serializedATN;


  // Individual action functions triggered by action() above.

  // Individual semantic predicate functions triggered by sempred() above.

  struct Initializer {
    Initializer();
  };
  static Initializer _init;
};

}  // namespace shout
