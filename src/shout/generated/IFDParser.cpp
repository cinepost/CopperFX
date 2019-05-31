
// Generated from /Users/max/dev/CopperFX/src/shout/shout_lib/IFD.g4 by ANTLR 4.7.1


#include "IFDListener.h"
#include "IFDVisitor.h"

#include "IFDParser.h"


using namespace antlrcpp;
using namespace shout;
using namespace antlr4;

IFDParser::IFDParser(TokenStream *input) : Parser(input) {
  _interpreter = new atn::ParserATNSimulator(this, _atn, _decisionToDFA, _sharedContextCache);
}

IFDParser::~IFDParser() {
  delete _interpreter;
}

std::string IFDParser::getGrammarFileName() const {
  return "IFD.g4";
}

const std::vector<std::string>& IFDParser::getRuleNames() const {
  return _ruleNames;
}

dfa::Vocabulary& IFDParser::getVocabulary() const {
  return _vocabulary;
}


//----------------- FileContext ------------------------------------------------------------------

IFDParser::FileContext::FileContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<IFDParser::LineContext *> IFDParser::FileContext::line() {
  return getRuleContexts<IFDParser::LineContext>();
}

IFDParser::LineContext* IFDParser::FileContext::line(size_t i) {
  return getRuleContext<IFDParser::LineContext>(i);
}


size_t IFDParser::FileContext::getRuleIndex() const {
  return IFDParser::RuleFile;
}

void IFDParser::FileContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<IFDListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFile(this);
}

void IFDParser::FileContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<IFDListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFile(this);
}


antlrcpp::Any IFDParser::FileContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<IFDVisitor*>(visitor))
    return parserVisitor->visitFile(this);
  else
    return visitor->visitChildren(this);
}

IFDParser::FileContext* IFDParser::file() {
  FileContext *_localctx = _tracker.createInstance<FileContext>(_ctx, getState());
  enterRule(_localctx, 0, IFDParser::RuleFile);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(33);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << IFDParser::T__0)
      | (1ULL << IFDParser::T__2)
      | (1ULL << IFDParser::T__3)
      | (1ULL << IFDParser::T__4)
      | (1ULL << IFDParser::T__5)
      | (1ULL << IFDParser::T__6)
      | (1ULL << IFDParser::T__10)
      | (1ULL << IFDParser::T__11)
      | (1ULL << IFDParser::T__12)
      | (1ULL << IFDParser::T__13)
      | (1ULL << IFDParser::T__14)
      | (1ULL << IFDParser::T__15)
      | (1ULL << IFDParser::COMMENT))) != 0)) {
      setState(30);
      line();
      setState(35);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- LineContext ------------------------------------------------------------------

IFDParser::LineContext::LineContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

IFDParser::VersionContext* IFDParser::LineContext::version() {
  return getRuleContext<IFDParser::VersionContext>(0);
}

IFDParser::DeclareContext* IFDParser::LineContext::declare() {
  return getRuleContext<IFDParser::DeclareContext>(0);
}

IFDParser::SetenvContext* IFDParser::LineContext::setenv() {
  return getRuleContext<IFDParser::SetenvContext>(0);
}

IFDParser::StartContext* IFDParser::LineContext::start() {
  return getRuleContext<IFDParser::StartContext>(0);
}

IFDParser::EndContext* IFDParser::LineContext::end() {
  return getRuleContext<IFDParser::EndContext>(0);
}

IFDParser::PropertyContext* IFDParser::LineContext::property() {
  return getRuleContext<IFDParser::PropertyContext>(0);
}

IFDParser::Detail_1Context* IFDParser::LineContext::detail_1() {
  return getRuleContext<IFDParser::Detail_1Context>(0);
}

IFDParser::Detail_2Context* IFDParser::LineContext::detail_2() {
  return getRuleContext<IFDParser::Detail_2Context>(0);
}

IFDParser::ImageContext* IFDParser::LineContext::image() {
  return getRuleContext<IFDParser::ImageContext>(0);
}

IFDParser::GeomertyContext* IFDParser::LineContext::geomerty() {
  return getRuleContext<IFDParser::GeomertyContext>(0);
}

IFDParser::TimeContext* IFDParser::LineContext::time() {
  return getRuleContext<IFDParser::TimeContext>(0);
}

IFDParser::RaytraceContext* IFDParser::LineContext::raytrace() {
  return getRuleContext<IFDParser::RaytraceContext>(0);
}

IFDParser::QuitContext* IFDParser::LineContext::quit() {
  return getRuleContext<IFDParser::QuitContext>(0);
}

tree::TerminalNode* IFDParser::LineContext::COMMENT() {
  return getToken(IFDParser::COMMENT, 0);
}


size_t IFDParser::LineContext::getRuleIndex() const {
  return IFDParser::RuleLine;
}

void IFDParser::LineContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<IFDListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterLine(this);
}

void IFDParser::LineContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<IFDListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitLine(this);
}


antlrcpp::Any IFDParser::LineContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<IFDVisitor*>(visitor))
    return parserVisitor->visitLine(this);
  else
    return visitor->visitChildren(this);
}

IFDParser::LineContext* IFDParser::line() {
  LineContext *_localctx = _tracker.createInstance<LineContext>(_ctx, getState());
  enterRule(_localctx, 2, IFDParser::RuleLine);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(50);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 1, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(36);
      version();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(37);
      declare();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(38);
      setenv();
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(39);
      start();
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(40);
      end();
      break;
    }

    case 6: {
      enterOuterAlt(_localctx, 6);
      setState(41);
      property();
      break;
    }

    case 7: {
      enterOuterAlt(_localctx, 7);
      setState(42);
      detail_1();
      break;
    }

    case 8: {
      enterOuterAlt(_localctx, 8);
      setState(43);
      detail_2();
      break;
    }

    case 9: {
      enterOuterAlt(_localctx, 9);
      setState(44);
      image();
      break;
    }

    case 10: {
      enterOuterAlt(_localctx, 10);
      setState(45);
      geomerty();
      break;
    }

    case 11: {
      enterOuterAlt(_localctx, 11);
      setState(46);
      time();
      break;
    }

    case 12: {
      enterOuterAlt(_localctx, 12);
      setState(47);
      raytrace();
      break;
    }

    case 13: {
      enterOuterAlt(_localctx, 13);
      setState(48);
      quit();
      break;
    }

    case 14: {
      enterOuterAlt(_localctx, 14);
      setState(49);
      match(IFDParser::COMMENT);
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- SetenvContext ------------------------------------------------------------------

IFDParser::SetenvContext::SetenvContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* IFDParser::SetenvContext::VAR_NAME() {
  return getToken(IFDParser::VAR_NAME, 0);
}

tree::TerminalNode* IFDParser::SetenvContext::VALUE() {
  return getToken(IFDParser::VALUE, 0);
}


size_t IFDParser::SetenvContext::getRuleIndex() const {
  return IFDParser::RuleSetenv;
}

void IFDParser::SetenvContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<IFDListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSetenv(this);
}

void IFDParser::SetenvContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<IFDListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSetenv(this);
}


antlrcpp::Any IFDParser::SetenvContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<IFDVisitor*>(visitor))
    return parserVisitor->visitSetenv(this);
  else
    return visitor->visitChildren(this);
}

IFDParser::SetenvContext* IFDParser::setenv() {
  SetenvContext *_localctx = _tracker.createInstance<SetenvContext>(_ctx, getState());
  enterRule(_localctx, 4, IFDParser::RuleSetenv);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(52);
    match(IFDParser::T__0);
    setState(53);
    match(IFDParser::VAR_NAME);
    setState(54);
    match(IFDParser::T__1);
    setState(55);
    match(IFDParser::VALUE);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- VersionContext ------------------------------------------------------------------

IFDParser::VersionContext::VersionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* IFDParser::VersionContext::VEX_VERSION() {
  return getToken(IFDParser::VEX_VERSION, 0);
}


size_t IFDParser::VersionContext::getRuleIndex() const {
  return IFDParser::RuleVersion;
}

void IFDParser::VersionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<IFDListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterVersion(this);
}

void IFDParser::VersionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<IFDListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitVersion(this);
}


antlrcpp::Any IFDParser::VersionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<IFDVisitor*>(visitor))
    return parserVisitor->visitVersion(this);
  else
    return visitor->visitChildren(this);
}

IFDParser::VersionContext* IFDParser::version() {
  VersionContext *_localctx = _tracker.createInstance<VersionContext>(_ctx, getState());
  enterRule(_localctx, 6, IFDParser::RuleVersion);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(57);
    match(IFDParser::T__2);
    setState(58);
    match(IFDParser::VEX_VERSION);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- DeclareContext ------------------------------------------------------------------

IFDParser::DeclareContext::DeclareContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* IFDParser::DeclareContext::OBJECT() {
  return getToken(IFDParser::OBJECT, 0);
}

tree::TerminalNode* IFDParser::DeclareContext::TYPE() {
  return getToken(IFDParser::TYPE, 0);
}

tree::TerminalNode* IFDParser::DeclareContext::VAR_NAME() {
  return getToken(IFDParser::VAR_NAME, 0);
}

tree::TerminalNode* IFDParser::DeclareContext::VALUE() {
  return getToken(IFDParser::VALUE, 0);
}


size_t IFDParser::DeclareContext::getRuleIndex() const {
  return IFDParser::RuleDeclare;
}

void IFDParser::DeclareContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<IFDListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterDeclare(this);
}

void IFDParser::DeclareContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<IFDListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitDeclare(this);
}


antlrcpp::Any IFDParser::DeclareContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<IFDVisitor*>(visitor))
    return parserVisitor->visitDeclare(this);
  else
    return visitor->visitChildren(this);
}

IFDParser::DeclareContext* IFDParser::declare() {
  DeclareContext *_localctx = _tracker.createInstance<DeclareContext>(_ctx, getState());
  enterRule(_localctx, 8, IFDParser::RuleDeclare);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(60);
    match(IFDParser::T__3);
    setState(61);
    match(IFDParser::OBJECT);
    setState(62);
    match(IFDParser::TYPE);
    setState(63);
    match(IFDParser::VAR_NAME);
    setState(64);
    match(IFDParser::VALUE);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- StartContext ------------------------------------------------------------------

IFDParser::StartContext::StartContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* IFDParser::StartContext::OBJECT() {
  return getToken(IFDParser::OBJECT, 0);
}


size_t IFDParser::StartContext::getRuleIndex() const {
  return IFDParser::RuleStart;
}

void IFDParser::StartContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<IFDListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterStart(this);
}

void IFDParser::StartContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<IFDListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitStart(this);
}


antlrcpp::Any IFDParser::StartContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<IFDVisitor*>(visitor))
    return parserVisitor->visitStart(this);
  else
    return visitor->visitChildren(this);
}

IFDParser::StartContext* IFDParser::start() {
  StartContext *_localctx = _tracker.createInstance<StartContext>(_ctx, getState());
  enterRule(_localctx, 10, IFDParser::RuleStart);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(66);
    match(IFDParser::T__4);
    setState(67);
    match(IFDParser::OBJECT);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- EndContext ------------------------------------------------------------------

IFDParser::EndContext::EndContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t IFDParser::EndContext::getRuleIndex() const {
  return IFDParser::RuleEnd;
}

void IFDParser::EndContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<IFDListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterEnd(this);
}

void IFDParser::EndContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<IFDListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitEnd(this);
}


antlrcpp::Any IFDParser::EndContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<IFDVisitor*>(visitor))
    return parserVisitor->visitEnd(this);
  else
    return visitor->visitChildren(this);
}

IFDParser::EndContext* IFDParser::end() {
  EndContext *_localctx = _tracker.createInstance<EndContext>(_ctx, getState());
  enterRule(_localctx, 12, IFDParser::RuleEnd);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(69);
    match(IFDParser::T__5);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Detail_1Context ------------------------------------------------------------------

IFDParser::Detail_1Context::Detail_1Context(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* IFDParser::Detail_1Context::OBJPATH() {
  return getToken(IFDParser::OBJPATH, 0);
}

tree::TerminalNode* IFDParser::Detail_1Context::STREAM() {
  return getToken(IFDParser::STREAM, 0);
}

tree::TerminalNode* IFDParser::Detail_1Context::FILENAME() {
  return getToken(IFDParser::FILENAME, 0);
}


size_t IFDParser::Detail_1Context::getRuleIndex() const {
  return IFDParser::RuleDetail_1;
}

void IFDParser::Detail_1Context::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<IFDListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterDetail_1(this);
}

void IFDParser::Detail_1Context::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<IFDListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitDetail_1(this);
}


antlrcpp::Any IFDParser::Detail_1Context::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<IFDVisitor*>(visitor))
    return parserVisitor->visitDetail_1(this);
  else
    return visitor->visitChildren(this);
}

IFDParser::Detail_1Context* IFDParser::detail_1() {
  Detail_1Context *_localctx = _tracker.createInstance<Detail_1Context>(_ctx, getState());
  enterRule(_localctx, 14, IFDParser::RuleDetail_1);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(71);
    match(IFDParser::T__6);
    setState(73);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == IFDParser::T__7) {
      setState(72);
      match(IFDParser::T__7);
    }
    setState(75);
    match(IFDParser::OBJPATH);
    setState(76);
    _la = _input->LA(1);
    if (!(_la == IFDParser::FILENAME

    || _la == IFDParser::STREAM)) {
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

//----------------- Detail_2Context ------------------------------------------------------------------

IFDParser::Detail_2Context::Detail_2Context(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<tree::TerminalNode *> IFDParser::Detail_2Context::OBJPATH() {
  return getTokens(IFDParser::OBJPATH);
}

tree::TerminalNode* IFDParser::Detail_2Context::OBJPATH(size_t i) {
  return getToken(IFDParser::OBJPATH, i);
}

std::vector<tree::TerminalNode *> IFDParser::Detail_2Context::VALUE() {
  return getTokens(IFDParser::VALUE);
}

tree::TerminalNode* IFDParser::Detail_2Context::VALUE(size_t i) {
  return getToken(IFDParser::VALUE, i);
}


size_t IFDParser::Detail_2Context::getRuleIndex() const {
  return IFDParser::RuleDetail_2;
}

void IFDParser::Detail_2Context::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<IFDListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterDetail_2(this);
}

void IFDParser::Detail_2Context::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<IFDListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitDetail_2(this);
}


antlrcpp::Any IFDParser::Detail_2Context::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<IFDVisitor*>(visitor))
    return parserVisitor->visitDetail_2(this);
  else
    return visitor->visitChildren(this);
}

IFDParser::Detail_2Context* IFDParser::detail_2() {
  Detail_2Context *_localctx = _tracker.createInstance<Detail_2Context>(_ctx, getState());
  enterRule(_localctx, 16, IFDParser::RuleDetail_2);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(78);
    match(IFDParser::T__6);
    setState(84);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case IFDParser::T__8: {
        setState(79);
        match(IFDParser::T__8);
        setState(80);
        match(IFDParser::VALUE);
        break;
      }

      case IFDParser::T__9: {
        setState(81);
        match(IFDParser::T__9);
        setState(82);
        match(IFDParser::VALUE);
        setState(83);
        match(IFDParser::VALUE);
        break;
      }

      case IFDParser::OBJPATH: {
        break;
      }

    default:
      break;
    }
    setState(86);
    match(IFDParser::OBJPATH);
    setState(87);
    match(IFDParser::OBJPATH);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- PropertyContext ------------------------------------------------------------------

IFDParser::PropertyContext::PropertyContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* IFDParser::PropertyContext::OBJECT() {
  return getToken(IFDParser::OBJECT, 0);
}

tree::TerminalNode* IFDParser::PropertyContext::VAR_NAME() {
  return getToken(IFDParser::VAR_NAME, 0);
}

tree::TerminalNode* IFDParser::PropertyContext::STREAM() {
  return getToken(IFDParser::STREAM, 0);
}

tree::TerminalNode* IFDParser::PropertyContext::VALUE() {
  return getToken(IFDParser::VALUE, 0);
}


size_t IFDParser::PropertyContext::getRuleIndex() const {
  return IFDParser::RuleProperty;
}

void IFDParser::PropertyContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<IFDListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterProperty(this);
}

void IFDParser::PropertyContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<IFDListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitProperty(this);
}


antlrcpp::Any IFDParser::PropertyContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<IFDVisitor*>(visitor))
    return parserVisitor->visitProperty(this);
  else
    return visitor->visitChildren(this);
}

IFDParser::PropertyContext* IFDParser::property() {
  PropertyContext *_localctx = _tracker.createInstance<PropertyContext>(_ctx, getState());
  enterRule(_localctx, 18, IFDParser::RuleProperty);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(89);
    match(IFDParser::T__10);
    setState(90);
    match(IFDParser::OBJECT);
    setState(91);
    match(IFDParser::VAR_NAME);
    setState(92);
    _la = _input->LA(1);
    if (!(_la == IFDParser::STREAM

    || _la == IFDParser::VALUE)) {
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

//----------------- ImageContext ------------------------------------------------------------------

IFDParser::ImageContext::ImageContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<tree::TerminalNode *> IFDParser::ImageContext::VALUE() {
  return getTokens(IFDParser::VALUE);
}

tree::TerminalNode* IFDParser::ImageContext::VALUE(size_t i) {
  return getToken(IFDParser::VALUE, i);
}


size_t IFDParser::ImageContext::getRuleIndex() const {
  return IFDParser::RuleImage;
}

void IFDParser::ImageContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<IFDListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterImage(this);
}

void IFDParser::ImageContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<IFDListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitImage(this);
}


antlrcpp::Any IFDParser::ImageContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<IFDVisitor*>(visitor))
    return parserVisitor->visitImage(this);
  else
    return visitor->visitChildren(this);
}

IFDParser::ImageContext* IFDParser::image() {
  ImageContext *_localctx = _tracker.createInstance<ImageContext>(_ctx, getState());
  enterRule(_localctx, 20, IFDParser::RuleImage);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(94);
    match(IFDParser::T__11);
    setState(95);
    match(IFDParser::VALUE);
    setState(97);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == IFDParser::VALUE) {
      setState(96);
      match(IFDParser::VALUE);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- GeomertyContext ------------------------------------------------------------------

IFDParser::GeomertyContext::GeomertyContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* IFDParser::GeomertyContext::VALUE() {
  return getToken(IFDParser::VALUE, 0);
}


size_t IFDParser::GeomertyContext::getRuleIndex() const {
  return IFDParser::RuleGeomerty;
}

void IFDParser::GeomertyContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<IFDListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterGeomerty(this);
}

void IFDParser::GeomertyContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<IFDListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitGeomerty(this);
}


antlrcpp::Any IFDParser::GeomertyContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<IFDVisitor*>(visitor))
    return parserVisitor->visitGeomerty(this);
  else
    return visitor->visitChildren(this);
}

IFDParser::GeomertyContext* IFDParser::geomerty() {
  GeomertyContext *_localctx = _tracker.createInstance<GeomertyContext>(_ctx, getState());
  enterRule(_localctx, 22, IFDParser::RuleGeomerty);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(99);
    match(IFDParser::T__12);
    setState(100);
    match(IFDParser::VALUE);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- TimeContext ------------------------------------------------------------------

IFDParser::TimeContext::TimeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* IFDParser::TimeContext::VALUE() {
  return getToken(IFDParser::VALUE, 0);
}


size_t IFDParser::TimeContext::getRuleIndex() const {
  return IFDParser::RuleTime;
}

void IFDParser::TimeContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<IFDListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterTime(this);
}

void IFDParser::TimeContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<IFDListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitTime(this);
}


antlrcpp::Any IFDParser::TimeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<IFDVisitor*>(visitor))
    return parserVisitor->visitTime(this);
  else
    return visitor->visitChildren(this);
}

IFDParser::TimeContext* IFDParser::time() {
  TimeContext *_localctx = _tracker.createInstance<TimeContext>(_ctx, getState());
  enterRule(_localctx, 24, IFDParser::RuleTime);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(102);
    match(IFDParser::T__13);
    setState(103);
    match(IFDParser::VALUE);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- RaytraceContext ------------------------------------------------------------------

IFDParser::RaytraceContext::RaytraceContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t IFDParser::RaytraceContext::getRuleIndex() const {
  return IFDParser::RuleRaytrace;
}

void IFDParser::RaytraceContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<IFDListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterRaytrace(this);
}

void IFDParser::RaytraceContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<IFDListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitRaytrace(this);
}


antlrcpp::Any IFDParser::RaytraceContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<IFDVisitor*>(visitor))
    return parserVisitor->visitRaytrace(this);
  else
    return visitor->visitChildren(this);
}

IFDParser::RaytraceContext* IFDParser::raytrace() {
  RaytraceContext *_localctx = _tracker.createInstance<RaytraceContext>(_ctx, getState());
  enterRule(_localctx, 26, IFDParser::RuleRaytrace);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(105);
    match(IFDParser::T__14);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- QuitContext ------------------------------------------------------------------

IFDParser::QuitContext::QuitContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t IFDParser::QuitContext::getRuleIndex() const {
  return IFDParser::RuleQuit;
}

void IFDParser::QuitContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<IFDListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterQuit(this);
}

void IFDParser::QuitContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<IFDListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitQuit(this);
}


antlrcpp::Any IFDParser::QuitContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<IFDVisitor*>(visitor))
    return parserVisitor->visitQuit(this);
  else
    return visitor->visitChildren(this);
}

IFDParser::QuitContext* IFDParser::quit() {
  QuitContext *_localctx = _tracker.createInstance<QuitContext>(_ctx, getState());
  enterRule(_localctx, 28, IFDParser::RuleQuit);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(107);
    match(IFDParser::T__15);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

// Static vars and initialization.
std::vector<dfa::DFA> IFDParser::_decisionToDFA;
atn::PredictionContextCache IFDParser::_sharedContextCache;

// We own the ATN which in turn owns the ATN states.
atn::ATN IFDParser::_atn;
std::vector<uint16_t> IFDParser::_serializedATN;

std::vector<std::string> IFDParser::_ruleNames = {
  "file", "line", "setenv", "version", "declare", "start", "end", "detail_1", 
  "detail_2", "property", "image", "geomerty", "time", "raytrace", "quit"
};

std::vector<std::string> IFDParser::_literalNames = {
  "", "'setenv'", "'='", "'ray_version'", "'ray_declare'", "'ray_start'", 
  "'ray_end'", "'ray_detail'", "'-T'", "'-v'", "'-V'", "'ray_property'", 
  "'ray_image'", "'ray_geometry'", "'ray_time'", "'ray_raytrace'", "'ray_quit'"
};

std::vector<std::string> IFDParser::_symbolicNames = {
  "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "PATH", 
  "OBJPATH", "FILENAME", "COMMENT", "STREAM", "TYPE", "OBJECT", "VEX_VERSION", 
  "VAR_NAME", "VALUE", "INTEGER", "NUMBER", "STRING", "NO_QUOTED", "QUOTED", 
  "CHARS", "BYTE", "BGEO", "WS"
};

dfa::Vocabulary IFDParser::_vocabulary(_literalNames, _symbolicNames);

std::vector<std::string> IFDParser::_tokenNames;

IFDParser::Initializer::Initializer() {
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
    0x3, 0x25, 0x70, 0x4, 0x2, 0x9, 0x2, 0x4, 0x3, 0x9, 0x3, 0x4, 0x4, 0x9, 
    0x4, 0x4, 0x5, 0x9, 0x5, 0x4, 0x6, 0x9, 0x6, 0x4, 0x7, 0x9, 0x7, 0x4, 
    0x8, 0x9, 0x8, 0x4, 0x9, 0x9, 0x9, 0x4, 0xa, 0x9, 0xa, 0x4, 0xb, 0x9, 
    0xb, 0x4, 0xc, 0x9, 0xc, 0x4, 0xd, 0x9, 0xd, 0x4, 0xe, 0x9, 0xe, 0x4, 
    0xf, 0x9, 0xf, 0x4, 0x10, 0x9, 0x10, 0x3, 0x2, 0x7, 0x2, 0x22, 0xa, 
    0x2, 0xc, 0x2, 0xe, 0x2, 0x25, 0xb, 0x2, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 
    0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 
    0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x5, 0x3, 0x35, 0xa, 0x3, 0x3, 
    0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x5, 0x3, 0x5, 0x3, 
    0x5, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 
    0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x8, 0x3, 0x8, 0x3, 0x9, 0x3, 0x9, 0x5, 
    0x9, 0x4c, 0xa, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0xa, 0x3, 0xa, 
    0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x5, 0xa, 0x57, 0xa, 0xa, 0x3, 
    0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 
    0xb, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x5, 0xc, 0x64, 0xa, 0xc, 0x3, 0xd, 
    0x3, 0xd, 0x3, 0xd, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xf, 0x3, 0xf, 
    0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 0x2, 0x2, 0x11, 0x2, 0x4, 0x6, 0x8, 
    0xa, 0xc, 0xe, 0x10, 0x12, 0x14, 0x16, 0x18, 0x1a, 0x1c, 0x1e, 0x2, 
    0x4, 0x4, 0x2, 0x15, 0x15, 0x17, 0x17, 0x4, 0x2, 0x17, 0x17, 0x1c, 0x1c, 
    0x2, 0x72, 0x2, 0x23, 0x3, 0x2, 0x2, 0x2, 0x4, 0x34, 0x3, 0x2, 0x2, 
    0x2, 0x6, 0x36, 0x3, 0x2, 0x2, 0x2, 0x8, 0x3b, 0x3, 0x2, 0x2, 0x2, 0xa, 
    0x3e, 0x3, 0x2, 0x2, 0x2, 0xc, 0x44, 0x3, 0x2, 0x2, 0x2, 0xe, 0x47, 
    0x3, 0x2, 0x2, 0x2, 0x10, 0x49, 0x3, 0x2, 0x2, 0x2, 0x12, 0x50, 0x3, 
    0x2, 0x2, 0x2, 0x14, 0x5b, 0x3, 0x2, 0x2, 0x2, 0x16, 0x60, 0x3, 0x2, 
    0x2, 0x2, 0x18, 0x65, 0x3, 0x2, 0x2, 0x2, 0x1a, 0x68, 0x3, 0x2, 0x2, 
    0x2, 0x1c, 0x6b, 0x3, 0x2, 0x2, 0x2, 0x1e, 0x6d, 0x3, 0x2, 0x2, 0x2, 
    0x20, 0x22, 0x5, 0x4, 0x3, 0x2, 0x21, 0x20, 0x3, 0x2, 0x2, 0x2, 0x22, 
    0x25, 0x3, 0x2, 0x2, 0x2, 0x23, 0x21, 0x3, 0x2, 0x2, 0x2, 0x23, 0x24, 
    0x3, 0x2, 0x2, 0x2, 0x24, 0x3, 0x3, 0x2, 0x2, 0x2, 0x25, 0x23, 0x3, 
    0x2, 0x2, 0x2, 0x26, 0x35, 0x5, 0x8, 0x5, 0x2, 0x27, 0x35, 0x5, 0xa, 
    0x6, 0x2, 0x28, 0x35, 0x5, 0x6, 0x4, 0x2, 0x29, 0x35, 0x5, 0xc, 0x7, 
    0x2, 0x2a, 0x35, 0x5, 0xe, 0x8, 0x2, 0x2b, 0x35, 0x5, 0x14, 0xb, 0x2, 
    0x2c, 0x35, 0x5, 0x10, 0x9, 0x2, 0x2d, 0x35, 0x5, 0x12, 0xa, 0x2, 0x2e, 
    0x35, 0x5, 0x16, 0xc, 0x2, 0x2f, 0x35, 0x5, 0x18, 0xd, 0x2, 0x30, 0x35, 
    0x5, 0x1a, 0xe, 0x2, 0x31, 0x35, 0x5, 0x1c, 0xf, 0x2, 0x32, 0x35, 0x5, 
    0x1e, 0x10, 0x2, 0x33, 0x35, 0x7, 0x16, 0x2, 0x2, 0x34, 0x26, 0x3, 0x2, 
    0x2, 0x2, 0x34, 0x27, 0x3, 0x2, 0x2, 0x2, 0x34, 0x28, 0x3, 0x2, 0x2, 
    0x2, 0x34, 0x29, 0x3, 0x2, 0x2, 0x2, 0x34, 0x2a, 0x3, 0x2, 0x2, 0x2, 
    0x34, 0x2b, 0x3, 0x2, 0x2, 0x2, 0x34, 0x2c, 0x3, 0x2, 0x2, 0x2, 0x34, 
    0x2d, 0x3, 0x2, 0x2, 0x2, 0x34, 0x2e, 0x3, 0x2, 0x2, 0x2, 0x34, 0x2f, 
    0x3, 0x2, 0x2, 0x2, 0x34, 0x30, 0x3, 0x2, 0x2, 0x2, 0x34, 0x31, 0x3, 
    0x2, 0x2, 0x2, 0x34, 0x32, 0x3, 0x2, 0x2, 0x2, 0x34, 0x33, 0x3, 0x2, 
    0x2, 0x2, 0x35, 0x5, 0x3, 0x2, 0x2, 0x2, 0x36, 0x37, 0x7, 0x3, 0x2, 
    0x2, 0x37, 0x38, 0x7, 0x1b, 0x2, 0x2, 0x38, 0x39, 0x7, 0x4, 0x2, 0x2, 
    0x39, 0x3a, 0x7, 0x1c, 0x2, 0x2, 0x3a, 0x7, 0x3, 0x2, 0x2, 0x2, 0x3b, 
    0x3c, 0x7, 0x5, 0x2, 0x2, 0x3c, 0x3d, 0x7, 0x1a, 0x2, 0x2, 0x3d, 0x9, 
    0x3, 0x2, 0x2, 0x2, 0x3e, 0x3f, 0x7, 0x6, 0x2, 0x2, 0x3f, 0x40, 0x7, 
    0x19, 0x2, 0x2, 0x40, 0x41, 0x7, 0x18, 0x2, 0x2, 0x41, 0x42, 0x7, 0x1b, 
    0x2, 0x2, 0x42, 0x43, 0x7, 0x1c, 0x2, 0x2, 0x43, 0xb, 0x3, 0x2, 0x2, 
    0x2, 0x44, 0x45, 0x7, 0x7, 0x2, 0x2, 0x45, 0x46, 0x7, 0x19, 0x2, 0x2, 
    0x46, 0xd, 0x3, 0x2, 0x2, 0x2, 0x47, 0x48, 0x7, 0x8, 0x2, 0x2, 0x48, 
    0xf, 0x3, 0x2, 0x2, 0x2, 0x49, 0x4b, 0x7, 0x9, 0x2, 0x2, 0x4a, 0x4c, 
    0x7, 0xa, 0x2, 0x2, 0x4b, 0x4a, 0x3, 0x2, 0x2, 0x2, 0x4b, 0x4c, 0x3, 
    0x2, 0x2, 0x2, 0x4c, 0x4d, 0x3, 0x2, 0x2, 0x2, 0x4d, 0x4e, 0x7, 0x14, 
    0x2, 0x2, 0x4e, 0x4f, 0x9, 0x2, 0x2, 0x2, 0x4f, 0x11, 0x3, 0x2, 0x2, 
    0x2, 0x50, 0x56, 0x7, 0x9, 0x2, 0x2, 0x51, 0x52, 0x7, 0xb, 0x2, 0x2, 
    0x52, 0x57, 0x7, 0x1c, 0x2, 0x2, 0x53, 0x54, 0x7, 0xc, 0x2, 0x2, 0x54, 
    0x55, 0x7, 0x1c, 0x2, 0x2, 0x55, 0x57, 0x7, 0x1c, 0x2, 0x2, 0x56, 0x51, 
    0x3, 0x2, 0x2, 0x2, 0x56, 0x53, 0x3, 0x2, 0x2, 0x2, 0x56, 0x57, 0x3, 
    0x2, 0x2, 0x2, 0x57, 0x58, 0x3, 0x2, 0x2, 0x2, 0x58, 0x59, 0x7, 0x14, 
    0x2, 0x2, 0x59, 0x5a, 0x7, 0x14, 0x2, 0x2, 0x5a, 0x13, 0x3, 0x2, 0x2, 
    0x2, 0x5b, 0x5c, 0x7, 0xd, 0x2, 0x2, 0x5c, 0x5d, 0x7, 0x19, 0x2, 0x2, 
    0x5d, 0x5e, 0x7, 0x1b, 0x2, 0x2, 0x5e, 0x5f, 0x9, 0x3, 0x2, 0x2, 0x5f, 
    0x15, 0x3, 0x2, 0x2, 0x2, 0x60, 0x61, 0x7, 0xe, 0x2, 0x2, 0x61, 0x63, 
    0x7, 0x1c, 0x2, 0x2, 0x62, 0x64, 0x7, 0x1c, 0x2, 0x2, 0x63, 0x62, 0x3, 
    0x2, 0x2, 0x2, 0x63, 0x64, 0x3, 0x2, 0x2, 0x2, 0x64, 0x17, 0x3, 0x2, 
    0x2, 0x2, 0x65, 0x66, 0x7, 0xf, 0x2, 0x2, 0x66, 0x67, 0x7, 0x1c, 0x2, 
    0x2, 0x67, 0x19, 0x3, 0x2, 0x2, 0x2, 0x68, 0x69, 0x7, 0x10, 0x2, 0x2, 
    0x69, 0x6a, 0x7, 0x1c, 0x2, 0x2, 0x6a, 0x1b, 0x3, 0x2, 0x2, 0x2, 0x6b, 
    0x6c, 0x7, 0x11, 0x2, 0x2, 0x6c, 0x1d, 0x3, 0x2, 0x2, 0x2, 0x6d, 0x6e, 
    0x7, 0x12, 0x2, 0x2, 0x6e, 0x1f, 0x3, 0x2, 0x2, 0x2, 0x7, 0x23, 0x34, 
    0x4b, 0x56, 0x63, 
  };

  atn::ATNDeserializer deserializer;
  _atn = deserializer.deserialize(_serializedATN);

  size_t count = _atn.getNumberOfDecisions();
  _decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    _decisionToDFA.emplace_back(_atn.getDecisionState(i), i);
  }
}

IFDParser::Initializer IFDParser::_init;
