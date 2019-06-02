
// Generated from /Users/max/dev/CopperFX/src/shout/shout_lib/IFD.g4 by ANTLR 4.7.1

#pragma once


#include "antlr4-runtime.h"


namespace shout {


class  IFDLexer : public antlr4::Lexer {
public:
  enum {
    T__0 = 1, T__1 = 2, T__2 = 3, T__3 = 4, T__4 = 5, T__5 = 6, T__6 = 7, 
    T__7 = 8, T__8 = 9, T__9 = 10, T__10 = 11, T__11 = 12, T__12 = 13, T__13 = 14, 
    T__14 = 15, T__15 = 16, T__16 = 17, COMMENT = 18, OBJNAME = 19, TYPE = 20, 
    OBJECT = 21, VEX_VERSION = 22, VAR_NAME = 23, VALUE = 24, INTEGER = 25, 
    NUMBER = 26, STRING = 27, NO_QUOTED = 28, QUOTED = 29, CHARS = 30, BGEO_START = 31, 
    WS = 32, BSON_VALUE = 33, BSON_KEY = 34, BSON_MAP = 35, BSON_ARRAY = 36, 
    JID_NULL = 37, JID_MAP_BEGIN = 38, JID_MAP_END = 39, JID_ARRAY_BEGIN = 40, 
    JID_ARRAY_END = 41, JID_BOOL = 42, JID_INT8 = 43, JID_INT16 = 44, JID_INT32 = 45, 
    JID_INT64 = 46, JID_REAL16 = 47, JID_REAL32 = 48, JID_REAL64 = 49, JID_UINT8 = 50, 
    JID_UINT16 = 51, JID_STRING = 52, JID_FALSE = 53, JID_TRUE = 54, JID_TOKENDEF = 55, 
    JID_TOKENREF = 56, JID_TOKENUNDEF = 57, JID_UNIFORM_ARRAY = 58, JID_KEY_SEPARATOR = 59, 
    JID_VALUE_SEPARATOR = 60, JID_MAGIC = 61
  };

  IFDLexer(antlr4::CharStream *input);
  ~IFDLexer();

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
