
// Generated from /Users/max/dev/shout/src/shout_lib/OBJ.g4 by ANTLR 4.7.1

#pragma once


#include "antlr4-runtime.h"


namespace shout {


class  OBJParser : public antlr4::Parser {
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

  enum {
    RuleStart = 0, RuleLine = 1, RuleFace = 2, RuleVertex = 3, RuleMtllib = 4, 
    RuleObject = 5, RuleUse_material = 6, RuleGroup = 7
  };

  OBJParser(antlr4::TokenStream *input);
  ~OBJParser();

  virtual std::string getGrammarFileName() const override;
  virtual const antlr4::atn::ATN& getATN() const override { return _atn; };
  virtual const std::vector<std::string>& getTokenNames() const override { return _tokenNames; }; // deprecated: use vocabulary instead.
  virtual const std::vector<std::string>& getRuleNames() const override;
  virtual antlr4::dfa::Vocabulary& getVocabulary() const override;


  class StartContext;
  class LineContext;
  class FaceContext;
  class VertexContext;
  class MtllibContext;
  class ObjectContext;
  class Use_materialContext;
  class GroupContext; 

  class  StartContext : public antlr4::ParserRuleContext {
  public:
    StartContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<LineContext *> line();
    LineContext* line(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  StartContext* start();

  class  LineContext : public antlr4::ParserRuleContext {
  public:
    LineContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    VertexContext *vertex();
    FaceContext *face();
    MtllibContext *mtllib();
    ObjectContext *object();
    Use_materialContext *use_material();
    GroupContext *group();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  LineContext* line();

  class  FaceContext : public antlr4::ParserRuleContext {
  public:
    FaceContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *FACE();
    std::vector<antlr4::tree::TerminalNode *> INTEGER();
    antlr4::tree::TerminalNode* INTEGER(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  FaceContext* face();

  class  VertexContext : public antlr4::ParserRuleContext {
  public:
    VertexContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<antlr4::tree::TerminalNode *> DECIMAL();
    antlr4::tree::TerminalNode* DECIMAL(size_t i);
    antlr4::tree::TerminalNode *GEOMETRIC_VERTEX();
    antlr4::tree::TerminalNode *TEXTURE_VERTEX();
    antlr4::tree::TerminalNode *VERTEX_NORMAL();
    antlr4::tree::TerminalNode *PARAMETER_SPACE_VERTEX();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  VertexContext* vertex();

  class  MtllibContext : public antlr4::ParserRuleContext {
  public:
    antlr4::Token *a = nullptr;;
    MtllibContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *MATERIAL_LIBRARY();
    antlr4::tree::TerminalNode *NAME();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  MtllibContext* mtllib();

  class  ObjectContext : public antlr4::ParserRuleContext {
  public:
    ObjectContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *OBJECT_NAME();
    antlr4::tree::TerminalNode *NAME();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ObjectContext* object();

  class  Use_materialContext : public antlr4::ParserRuleContext {
  public:
    Use_materialContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *MATERIAL_NAME();
    antlr4::tree::TerminalNode *NAME();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Use_materialContext* use_material();

  class  GroupContext : public antlr4::ParserRuleContext {
  public:
    GroupContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *SMOOTHING_GROUP();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  GroupContext* group();


private:
  static std::vector<antlr4::dfa::DFA> _decisionToDFA;
  static antlr4::atn::PredictionContextCache _sharedContextCache;
  static std::vector<std::string> _ruleNames;
  static std::vector<std::string> _tokenNames;

  static std::vector<std::string> _literalNames;
  static std::vector<std::string> _symbolicNames;
  static antlr4::dfa::Vocabulary _vocabulary;
  static antlr4::atn::ATN _atn;
  static std::vector<uint16_t> _serializedATN;


  struct Initializer {
    Initializer();
  };
  static Initializer _init;
};

}  // namespace shout
