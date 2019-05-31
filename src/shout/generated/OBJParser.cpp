
// Generated from /Users/max/dev/shout/src/shout_lib/OBJ.g4 by ANTLR 4.7.1


#include "OBJListener.h"
#include "OBJVisitor.h"

#include "OBJParser.h"


using namespace antlrcpp;
using namespace shout;
using namespace antlr4;

OBJParser::OBJParser(TokenStream *input) : Parser(input) {
  _interpreter = new atn::ParserATNSimulator(this, _atn, _decisionToDFA, _sharedContextCache);
}

OBJParser::~OBJParser() {
  delete _interpreter;
}

std::string OBJParser::getGrammarFileName() const {
  return "OBJ.g4";
}

const std::vector<std::string>& OBJParser::getRuleNames() const {
  return _ruleNames;
}

dfa::Vocabulary& OBJParser::getVocabulary() const {
  return _vocabulary;
}


//----------------- StartContext ------------------------------------------------------------------

OBJParser::StartContext::StartContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<OBJParser::LineContext *> OBJParser::StartContext::line() {
  return getRuleContexts<OBJParser::LineContext>();
}

OBJParser::LineContext* OBJParser::StartContext::line(size_t i) {
  return getRuleContext<OBJParser::LineContext>(i);
}


size_t OBJParser::StartContext::getRuleIndex() const {
  return OBJParser::RuleStart;
}

void OBJParser::StartContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<OBJListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterStart(this);
}

void OBJParser::StartContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<OBJListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitStart(this);
}


antlrcpp::Any OBJParser::StartContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<OBJVisitor*>(visitor))
    return parserVisitor->visitStart(this);
  else
    return visitor->visitChildren(this);
}

OBJParser::StartContext* OBJParser::start() {
  StartContext *_localctx = _tracker.createInstance<StartContext>(_ctx, getState());
  enterRule(_localctx, 0, OBJParser::RuleStart);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(17); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(16);
      line();
      setState(19); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << OBJParser::GEOMETRIC_VERTEX)
      | (1ULL << OBJParser::TEXTURE_VERTEX)
      | (1ULL << OBJParser::VERTEX_NORMAL)
      | (1ULL << OBJParser::PARAMETER_SPACE_VERTEX)
      | (1ULL << OBJParser::FACE)
      | (1ULL << OBJParser::SMOOTHING_GROUP)
      | (1ULL << OBJParser::OBJECT_NAME)
      | (1ULL << OBJParser::MATERIAL_NAME)
      | (1ULL << OBJParser::MATERIAL_LIBRARY))) != 0));
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- LineContext ------------------------------------------------------------------

OBJParser::LineContext::LineContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

OBJParser::VertexContext* OBJParser::LineContext::vertex() {
  return getRuleContext<OBJParser::VertexContext>(0);
}

OBJParser::FaceContext* OBJParser::LineContext::face() {
  return getRuleContext<OBJParser::FaceContext>(0);
}

OBJParser::MtllibContext* OBJParser::LineContext::mtllib() {
  return getRuleContext<OBJParser::MtllibContext>(0);
}

OBJParser::ObjectContext* OBJParser::LineContext::object() {
  return getRuleContext<OBJParser::ObjectContext>(0);
}

OBJParser::Use_materialContext* OBJParser::LineContext::use_material() {
  return getRuleContext<OBJParser::Use_materialContext>(0);
}

OBJParser::GroupContext* OBJParser::LineContext::group() {
  return getRuleContext<OBJParser::GroupContext>(0);
}


size_t OBJParser::LineContext::getRuleIndex() const {
  return OBJParser::RuleLine;
}

void OBJParser::LineContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<OBJListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterLine(this);
}

void OBJParser::LineContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<OBJListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitLine(this);
}


antlrcpp::Any OBJParser::LineContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<OBJVisitor*>(visitor))
    return parserVisitor->visitLine(this);
  else
    return visitor->visitChildren(this);
}

OBJParser::LineContext* OBJParser::line() {
  LineContext *_localctx = _tracker.createInstance<LineContext>(_ctx, getState());
  enterRule(_localctx, 2, OBJParser::RuleLine);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(27);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case OBJParser::GEOMETRIC_VERTEX:
      case OBJParser::TEXTURE_VERTEX:
      case OBJParser::VERTEX_NORMAL:
      case OBJParser::PARAMETER_SPACE_VERTEX: {
        setState(21);
        vertex();
        break;
      }

      case OBJParser::FACE: {
        setState(22);
        face();
        break;
      }

      case OBJParser::MATERIAL_LIBRARY: {
        setState(23);
        mtllib();
        break;
      }

      case OBJParser::OBJECT_NAME: {
        setState(24);
        object();
        break;
      }

      case OBJParser::MATERIAL_NAME: {
        setState(25);
        use_material();
        break;
      }

      case OBJParser::SMOOTHING_GROUP: {
        setState(26);
        group();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    setState(30);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == OBJParser::T__0) {
      setState(29);
      match(OBJParser::T__0);
    }
    setState(32);
    match(OBJParser::T__1);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FaceContext ------------------------------------------------------------------

OBJParser::FaceContext::FaceContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* OBJParser::FaceContext::FACE() {
  return getToken(OBJParser::FACE, 0);
}

std::vector<tree::TerminalNode *> OBJParser::FaceContext::INTEGER() {
  return getTokens(OBJParser::INTEGER);
}

tree::TerminalNode* OBJParser::FaceContext::INTEGER(size_t i) {
  return getToken(OBJParser::INTEGER, i);
}


size_t OBJParser::FaceContext::getRuleIndex() const {
  return OBJParser::RuleFace;
}

void OBJParser::FaceContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<OBJListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFace(this);
}

void OBJParser::FaceContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<OBJListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFace(this);
}


antlrcpp::Any OBJParser::FaceContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<OBJVisitor*>(visitor))
    return parserVisitor->visitFace(this);
  else
    return visitor->visitChildren(this);
}

OBJParser::FaceContext* OBJParser::face() {
  FaceContext *_localctx = _tracker.createInstance<FaceContext>(_ctx, getState());
  enterRule(_localctx, 4, OBJParser::RuleFace);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(34);
    match(OBJParser::FACE);
    setState(36); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(35);
      match(OBJParser::INTEGER);
      setState(38); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while (_la == OBJParser::INTEGER);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- VertexContext ------------------------------------------------------------------

OBJParser::VertexContext::VertexContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<tree::TerminalNode *> OBJParser::VertexContext::DECIMAL() {
  return getTokens(OBJParser::DECIMAL);
}

tree::TerminalNode* OBJParser::VertexContext::DECIMAL(size_t i) {
  return getToken(OBJParser::DECIMAL, i);
}

tree::TerminalNode* OBJParser::VertexContext::GEOMETRIC_VERTEX() {
  return getToken(OBJParser::GEOMETRIC_VERTEX, 0);
}

tree::TerminalNode* OBJParser::VertexContext::TEXTURE_VERTEX() {
  return getToken(OBJParser::TEXTURE_VERTEX, 0);
}

tree::TerminalNode* OBJParser::VertexContext::VERTEX_NORMAL() {
  return getToken(OBJParser::VERTEX_NORMAL, 0);
}

tree::TerminalNode* OBJParser::VertexContext::PARAMETER_SPACE_VERTEX() {
  return getToken(OBJParser::PARAMETER_SPACE_VERTEX, 0);
}


size_t OBJParser::VertexContext::getRuleIndex() const {
  return OBJParser::RuleVertex;
}

void OBJParser::VertexContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<OBJListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterVertex(this);
}

void OBJParser::VertexContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<OBJListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitVertex(this);
}


antlrcpp::Any OBJParser::VertexContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<OBJVisitor*>(visitor))
    return parserVisitor->visitVertex(this);
  else
    return visitor->visitChildren(this);
}

OBJParser::VertexContext* OBJParser::vertex() {
  VertexContext *_localctx = _tracker.createInstance<VertexContext>(_ctx, getState());
  enterRule(_localctx, 6, OBJParser::RuleVertex);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(47);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case OBJParser::GEOMETRIC_VERTEX:
      case OBJParser::TEXTURE_VERTEX:
      case OBJParser::VERTEX_NORMAL: {
        enterOuterAlt(_localctx, 1);
        setState(40);
        _la = _input->LA(1);
        if (!((((_la & ~ 0x3fULL) == 0) &&
          ((1ULL << _la) & ((1ULL << OBJParser::GEOMETRIC_VERTEX)
          | (1ULL << OBJParser::TEXTURE_VERTEX)
          | (1ULL << OBJParser::VERTEX_NORMAL))) != 0))) {
        _errHandler->recoverInline(this);
        }
        else {
          _errHandler->reportMatch(this);
          consume();
        }
        setState(41);
        match(OBJParser::DECIMAL);
        setState(42);
        match(OBJParser::DECIMAL);
        setState(43);
        match(OBJParser::DECIMAL);
        break;
      }

      case OBJParser::PARAMETER_SPACE_VERTEX: {
        enterOuterAlt(_localctx, 2);
        setState(44);
        match(OBJParser::PARAMETER_SPACE_VERTEX);
        setState(45);
        match(OBJParser::DECIMAL);
        setState(46);
        match(OBJParser::DECIMAL);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- MtllibContext ------------------------------------------------------------------

OBJParser::MtllibContext::MtllibContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* OBJParser::MtllibContext::MATERIAL_LIBRARY() {
  return getToken(OBJParser::MATERIAL_LIBRARY, 0);
}

tree::TerminalNode* OBJParser::MtllibContext::NAME() {
  return getToken(OBJParser::NAME, 0);
}


size_t OBJParser::MtllibContext::getRuleIndex() const {
  return OBJParser::RuleMtllib;
}

void OBJParser::MtllibContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<OBJListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterMtllib(this);
}

void OBJParser::MtllibContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<OBJListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitMtllib(this);
}


antlrcpp::Any OBJParser::MtllibContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<OBJVisitor*>(visitor))
    return parserVisitor->visitMtllib(this);
  else
    return visitor->visitChildren(this);
}

OBJParser::MtllibContext* OBJParser::mtllib() {
  MtllibContext *_localctx = _tracker.createInstance<MtllibContext>(_ctx, getState());
  enterRule(_localctx, 8, OBJParser::RuleMtllib);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(49);
    match(OBJParser::MATERIAL_LIBRARY);
    setState(50);
    dynamic_cast<MtllibContext *>(_localctx)->a = match(OBJParser::NAME);
    setState(51);
    match(OBJParser::T__2);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ObjectContext ------------------------------------------------------------------

OBJParser::ObjectContext::ObjectContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* OBJParser::ObjectContext::OBJECT_NAME() {
  return getToken(OBJParser::OBJECT_NAME, 0);
}

tree::TerminalNode* OBJParser::ObjectContext::NAME() {
  return getToken(OBJParser::NAME, 0);
}


size_t OBJParser::ObjectContext::getRuleIndex() const {
  return OBJParser::RuleObject;
}

void OBJParser::ObjectContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<OBJListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterObject(this);
}

void OBJParser::ObjectContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<OBJListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitObject(this);
}


antlrcpp::Any OBJParser::ObjectContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<OBJVisitor*>(visitor))
    return parserVisitor->visitObject(this);
  else
    return visitor->visitChildren(this);
}

OBJParser::ObjectContext* OBJParser::object() {
  ObjectContext *_localctx = _tracker.createInstance<ObjectContext>(_ctx, getState());
  enterRule(_localctx, 10, OBJParser::RuleObject);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(53);
    match(OBJParser::OBJECT_NAME);
    setState(54);
    match(OBJParser::NAME);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Use_materialContext ------------------------------------------------------------------

OBJParser::Use_materialContext::Use_materialContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* OBJParser::Use_materialContext::MATERIAL_NAME() {
  return getToken(OBJParser::MATERIAL_NAME, 0);
}

tree::TerminalNode* OBJParser::Use_materialContext::NAME() {
  return getToken(OBJParser::NAME, 0);
}


size_t OBJParser::Use_materialContext::getRuleIndex() const {
  return OBJParser::RuleUse_material;
}

void OBJParser::Use_materialContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<OBJListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterUse_material(this);
}

void OBJParser::Use_materialContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<OBJListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitUse_material(this);
}


antlrcpp::Any OBJParser::Use_materialContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<OBJVisitor*>(visitor))
    return parserVisitor->visitUse_material(this);
  else
    return visitor->visitChildren(this);
}

OBJParser::Use_materialContext* OBJParser::use_material() {
  Use_materialContext *_localctx = _tracker.createInstance<Use_materialContext>(_ctx, getState());
  enterRule(_localctx, 12, OBJParser::RuleUse_material);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(56);
    match(OBJParser::MATERIAL_NAME);
    setState(57);
    match(OBJParser::NAME);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- GroupContext ------------------------------------------------------------------

OBJParser::GroupContext::GroupContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* OBJParser::GroupContext::SMOOTHING_GROUP() {
  return getToken(OBJParser::SMOOTHING_GROUP, 0);
}


size_t OBJParser::GroupContext::getRuleIndex() const {
  return OBJParser::RuleGroup;
}

void OBJParser::GroupContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<OBJListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterGroup(this);
}

void OBJParser::GroupContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<OBJListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitGroup(this);
}


antlrcpp::Any OBJParser::GroupContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<OBJVisitor*>(visitor))
    return parserVisitor->visitGroup(this);
  else
    return visitor->visitChildren(this);
}

OBJParser::GroupContext* OBJParser::group() {
  GroupContext *_localctx = _tracker.createInstance<GroupContext>(_ctx, getState());
  enterRule(_localctx, 14, OBJParser::RuleGroup);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(59);
    match(OBJParser::SMOOTHING_GROUP);
    setState(60);
    _la = _input->LA(1);
    if (!(_la == OBJParser::T__3

    || _la == OBJParser::T__4)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

// Static vars and initialization.
std::vector<dfa::DFA> OBJParser::_decisionToDFA;
atn::PredictionContextCache OBJParser::_sharedContextCache;

// We own the ATN which in turn owns the ATN states.
atn::ATN OBJParser::_atn;
std::vector<uint16_t> OBJParser::_serializedATN;

std::vector<std::string> OBJParser::_ruleNames = {
  "start", "line", "face", "vertex", "mtllib", "object", "use_material", 
  "group"
};

std::vector<std::string> OBJParser::_literalNames = {
  "", "'\r'", "'\n'", "'.mtl'", "'on'", "'off'", "'v'", "'vt'", "'vn'", 
  "'vp'", "'deg'", "'bmat'", "'step'", "'cstype'", "'p'", "'l'", "'f'", 
  "'curv'", "'curv2'", "'surf'", "'parm'", "'trim'", "'hole'", "'scrv'", 
  "'sp'", "'end'", "'con'", "'g'", "'s'", "'mg'", "'o'", "'bevel'", "'c_interp'", 
  "'d_interp'", "'lod'", "'usemtl'", "'mtllib'", "'shadow_obj'", "'trace_obj'", 
  "'ctech'", "'stech'"
};

std::vector<std::string> OBJParser::_symbolicNames = {
  "", "", "", "", "", "", "GEOMETRIC_VERTEX", "TEXTURE_VERTEX", "VERTEX_NORMAL", 
  "PARAMETER_SPACE_VERTEX", "DEGREE", "BASIS_MATRIX", "STEP_SIZE", "CURVE_SURF_TYPE", 
  "POINT", "LINE", "FACE", "CURVE", "CURVE2D", "SURF", "PARAM", "OUTER_TRIMMING_HOLE", 
  "INNER_TRIMMING_HOLE", "SPECIAL_CURVE", "SPECIAL_POINT", "END", "CONNECT", 
  "GROUP_NAME", "SMOOTHING_GROUP", "MERGING_GROUP", "OBJECT_NAME", "BEVEL_INTERPOLATION", 
  "COLOR_INTERPOLATION", "DISSOLVE_INTERPOLATION", "LEVEL_OF_DETAIL", "MATERIAL_NAME", 
  "MATERIAL_LIBRARY", "SHADOW_CASTING", "RAY_TRACING", "CURVE_APPROX", "SURF_APPROX", 
  "INTEGER", "DECIMAL", "COMMENT", "NAME", "WS"
};

dfa::Vocabulary OBJParser::_vocabulary(_literalNames, _symbolicNames);

std::vector<std::string> OBJParser::_tokenNames;

OBJParser::Initializer::Initializer() {
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
    0x3, 0x2f, 0x41, 0x4, 0x2, 0x9, 0x2, 0x4, 0x3, 0x9, 0x3, 0x4, 0x4, 0x9, 
    0x4, 0x4, 0x5, 0x9, 0x5, 0x4, 0x6, 0x9, 0x6, 0x4, 0x7, 0x9, 0x7, 0x4, 
    0x8, 0x9, 0x8, 0x4, 0x9, 0x9, 0x9, 0x3, 0x2, 0x6, 0x2, 0x14, 0xa, 0x2, 
    0xd, 0x2, 0xe, 0x2, 0x15, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 
    0x3, 0x3, 0x3, 0x5, 0x3, 0x1e, 0xa, 0x3, 0x3, 0x3, 0x5, 0x3, 0x21, 0xa, 
    0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x4, 0x3, 0x4, 0x6, 0x4, 0x27, 0xa, 0x4, 
    0xd, 0x4, 0xe, 0x4, 0x28, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 
    0x5, 0x3, 0x5, 0x3, 0x5, 0x5, 0x5, 0x32, 0xa, 0x5, 0x3, 0x6, 0x3, 0x6, 
    0x3, 0x6, 0x3, 0x6, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x8, 0x3, 0x8, 
    0x3, 0x8, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x2, 0x2, 0xa, 0x2, 
    0x4, 0x6, 0x8, 0xa, 0xc, 0xe, 0x10, 0x2, 0x4, 0x3, 0x2, 0x8, 0xa, 0x3, 
    0x2, 0x6, 0x7, 0x2, 0x41, 0x2, 0x13, 0x3, 0x2, 0x2, 0x2, 0x4, 0x1d, 
    0x3, 0x2, 0x2, 0x2, 0x6, 0x24, 0x3, 0x2, 0x2, 0x2, 0x8, 0x31, 0x3, 0x2, 
    0x2, 0x2, 0xa, 0x33, 0x3, 0x2, 0x2, 0x2, 0xc, 0x37, 0x3, 0x2, 0x2, 0x2, 
    0xe, 0x3a, 0x3, 0x2, 0x2, 0x2, 0x10, 0x3d, 0x3, 0x2, 0x2, 0x2, 0x12, 
    0x14, 0x5, 0x4, 0x3, 0x2, 0x13, 0x12, 0x3, 0x2, 0x2, 0x2, 0x14, 0x15, 
    0x3, 0x2, 0x2, 0x2, 0x15, 0x13, 0x3, 0x2, 0x2, 0x2, 0x15, 0x16, 0x3, 
    0x2, 0x2, 0x2, 0x16, 0x3, 0x3, 0x2, 0x2, 0x2, 0x17, 0x1e, 0x5, 0x8, 
    0x5, 0x2, 0x18, 0x1e, 0x5, 0x6, 0x4, 0x2, 0x19, 0x1e, 0x5, 0xa, 0x6, 
    0x2, 0x1a, 0x1e, 0x5, 0xc, 0x7, 0x2, 0x1b, 0x1e, 0x5, 0xe, 0x8, 0x2, 
    0x1c, 0x1e, 0x5, 0x10, 0x9, 0x2, 0x1d, 0x17, 0x3, 0x2, 0x2, 0x2, 0x1d, 
    0x18, 0x3, 0x2, 0x2, 0x2, 0x1d, 0x19, 0x3, 0x2, 0x2, 0x2, 0x1d, 0x1a, 
    0x3, 0x2, 0x2, 0x2, 0x1d, 0x1b, 0x3, 0x2, 0x2, 0x2, 0x1d, 0x1c, 0x3, 
    0x2, 0x2, 0x2, 0x1e, 0x20, 0x3, 0x2, 0x2, 0x2, 0x1f, 0x21, 0x7, 0x3, 
    0x2, 0x2, 0x20, 0x1f, 0x3, 0x2, 0x2, 0x2, 0x20, 0x21, 0x3, 0x2, 0x2, 
    0x2, 0x21, 0x22, 0x3, 0x2, 0x2, 0x2, 0x22, 0x23, 0x7, 0x4, 0x2, 0x2, 
    0x23, 0x5, 0x3, 0x2, 0x2, 0x2, 0x24, 0x26, 0x7, 0x12, 0x2, 0x2, 0x25, 
    0x27, 0x7, 0x2b, 0x2, 0x2, 0x26, 0x25, 0x3, 0x2, 0x2, 0x2, 0x27, 0x28, 
    0x3, 0x2, 0x2, 0x2, 0x28, 0x26, 0x3, 0x2, 0x2, 0x2, 0x28, 0x29, 0x3, 
    0x2, 0x2, 0x2, 0x29, 0x7, 0x3, 0x2, 0x2, 0x2, 0x2a, 0x2b, 0x9, 0x2, 
    0x2, 0x2, 0x2b, 0x2c, 0x7, 0x2c, 0x2, 0x2, 0x2c, 0x2d, 0x7, 0x2c, 0x2, 
    0x2, 0x2d, 0x32, 0x7, 0x2c, 0x2, 0x2, 0x2e, 0x2f, 0x7, 0xb, 0x2, 0x2, 
    0x2f, 0x30, 0x7, 0x2c, 0x2, 0x2, 0x30, 0x32, 0x7, 0x2c, 0x2, 0x2, 0x31, 
    0x2a, 0x3, 0x2, 0x2, 0x2, 0x31, 0x2e, 0x3, 0x2, 0x2, 0x2, 0x32, 0x9, 
    0x3, 0x2, 0x2, 0x2, 0x33, 0x34, 0x7, 0x26, 0x2, 0x2, 0x34, 0x35, 0x7, 
    0x2e, 0x2, 0x2, 0x35, 0x36, 0x7, 0x5, 0x2, 0x2, 0x36, 0xb, 0x3, 0x2, 
    0x2, 0x2, 0x37, 0x38, 0x7, 0x20, 0x2, 0x2, 0x38, 0x39, 0x7, 0x2e, 0x2, 
    0x2, 0x39, 0xd, 0x3, 0x2, 0x2, 0x2, 0x3a, 0x3b, 0x7, 0x25, 0x2, 0x2, 
    0x3b, 0x3c, 0x7, 0x2e, 0x2, 0x2, 0x3c, 0xf, 0x3, 0x2, 0x2, 0x2, 0x3d, 
    0x3e, 0x7, 0x1e, 0x2, 0x2, 0x3e, 0x3f, 0x9, 0x3, 0x2, 0x2, 0x3f, 0x11, 
    0x3, 0x2, 0x2, 0x2, 0x7, 0x15, 0x1d, 0x20, 0x28, 0x31, 
  };

  atn::ATNDeserializer deserializer;
  _atn = deserializer.deserialize(_serializedATN);

  size_t count = _atn.getNumberOfDecisions();
  _decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    _decisionToDFA.emplace_back(_atn.getDecisionState(i), i);
  }
}

OBJParser::Initializer OBJParser::_init;
