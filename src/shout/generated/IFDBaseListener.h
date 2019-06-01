
// Generated from /Users/max/dev/CopperFX/src/shout/shout_lib/IFD.g4 by ANTLR 4.7.1

#pragma once


#include "antlr4-runtime.h"
#include "IFDListener.h"


namespace shout {

/**
 * This class provides an empty implementation of IFDListener,
 * which can be extended to create a listener which only needs to handle a subset
 * of the available methods.
 */
class  IFDBaseListener : public IFDListener {
public:

  virtual void enterFile(IFDParser::FileContext * /*ctx*/) override { }
  virtual void exitFile(IFDParser::FileContext * /*ctx*/) override { }

  virtual void enterLine(IFDParser::LineContext * /*ctx*/) override { }
  virtual void exitLine(IFDParser::LineContext * /*ctx*/) override { }

  virtual void enterSetenv(IFDParser::SetenvContext * /*ctx*/) override { }
  virtual void exitSetenv(IFDParser::SetenvContext * /*ctx*/) override { }

  virtual void enterVersion(IFDParser::VersionContext * /*ctx*/) override { }
  virtual void exitVersion(IFDParser::VersionContext * /*ctx*/) override { }

  virtual void enterDeclare(IFDParser::DeclareContext * /*ctx*/) override { }
  virtual void exitDeclare(IFDParser::DeclareContext * /*ctx*/) override { }

  virtual void enterStart(IFDParser::StartContext * /*ctx*/) override { }
  virtual void exitStart(IFDParser::StartContext * /*ctx*/) override { }

  virtual void enterEnd(IFDParser::EndContext * /*ctx*/) override { }
  virtual void exitEnd(IFDParser::EndContext * /*ctx*/) override { }

  virtual void enterDetail(IFDParser::DetailContext * /*ctx*/) override { }
  virtual void exitDetail(IFDParser::DetailContext * /*ctx*/) override { }

  virtual void enterDetail_instance(IFDParser::Detail_instanceContext * /*ctx*/) override { }
  virtual void exitDetail_instance(IFDParser::Detail_instanceContext * /*ctx*/) override { }

  virtual void enterProperty(IFDParser::PropertyContext * /*ctx*/) override { }
  virtual void exitProperty(IFDParser::PropertyContext * /*ctx*/) override { }

  virtual void enterImage(IFDParser::ImageContext * /*ctx*/) override { }
  virtual void exitImage(IFDParser::ImageContext * /*ctx*/) override { }

  virtual void enterGeomerty(IFDParser::GeomertyContext * /*ctx*/) override { }
  virtual void exitGeomerty(IFDParser::GeomertyContext * /*ctx*/) override { }

  virtual void enterTime(IFDParser::TimeContext * /*ctx*/) override { }
  virtual void exitTime(IFDParser::TimeContext * /*ctx*/) override { }

  virtual void enterRaytrace(IFDParser::RaytraceContext * /*ctx*/) override { }
  virtual void exitRaytrace(IFDParser::RaytraceContext * /*ctx*/) override { }

  virtual void enterQuit(IFDParser::QuitContext * /*ctx*/) override { }
  virtual void exitQuit(IFDParser::QuitContext * /*ctx*/) override { }


  virtual void enterEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void exitEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void visitTerminal(antlr4::tree::TerminalNode * /*node*/) override { }
  virtual void visitErrorNode(antlr4::tree::ErrorNode * /*node*/) override { }

};

}  // namespace shout
