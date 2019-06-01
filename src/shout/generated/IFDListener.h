
// Generated from /Users/max/dev/CopperFX/src/shout/shout_lib/IFD.g4 by ANTLR 4.7.1

#pragma once


#include "antlr4-runtime.h"
#include "IFDParser.h"


namespace shout {

/**
 * This interface defines an abstract listener for a parse tree produced by IFDParser.
 */
class  IFDListener : public antlr4::tree::ParseTreeListener {
public:

  virtual void enterFile(IFDParser::FileContext *ctx) = 0;
  virtual void exitFile(IFDParser::FileContext *ctx) = 0;

  virtual void enterLine(IFDParser::LineContext *ctx) = 0;
  virtual void exitLine(IFDParser::LineContext *ctx) = 0;

  virtual void enterSetenv(IFDParser::SetenvContext *ctx) = 0;
  virtual void exitSetenv(IFDParser::SetenvContext *ctx) = 0;

  virtual void enterVersion(IFDParser::VersionContext *ctx) = 0;
  virtual void exitVersion(IFDParser::VersionContext *ctx) = 0;

  virtual void enterDeclare(IFDParser::DeclareContext *ctx) = 0;
  virtual void exitDeclare(IFDParser::DeclareContext *ctx) = 0;

  virtual void enterStart(IFDParser::StartContext *ctx) = 0;
  virtual void exitStart(IFDParser::StartContext *ctx) = 0;

  virtual void enterEnd(IFDParser::EndContext *ctx) = 0;
  virtual void exitEnd(IFDParser::EndContext *ctx) = 0;

  virtual void enterDetail(IFDParser::DetailContext *ctx) = 0;
  virtual void exitDetail(IFDParser::DetailContext *ctx) = 0;

  virtual void enterDetail_instance(IFDParser::Detail_instanceContext *ctx) = 0;
  virtual void exitDetail_instance(IFDParser::Detail_instanceContext *ctx) = 0;

  virtual void enterProperty(IFDParser::PropertyContext *ctx) = 0;
  virtual void exitProperty(IFDParser::PropertyContext *ctx) = 0;

  virtual void enterImage(IFDParser::ImageContext *ctx) = 0;
  virtual void exitImage(IFDParser::ImageContext *ctx) = 0;

  virtual void enterGeomerty(IFDParser::GeomertyContext *ctx) = 0;
  virtual void exitGeomerty(IFDParser::GeomertyContext *ctx) = 0;

  virtual void enterTime(IFDParser::TimeContext *ctx) = 0;
  virtual void exitTime(IFDParser::TimeContext *ctx) = 0;

  virtual void enterRaytrace(IFDParser::RaytraceContext *ctx) = 0;
  virtual void exitRaytrace(IFDParser::RaytraceContext *ctx) = 0;

  virtual void enterQuit(IFDParser::QuitContext *ctx) = 0;
  virtual void exitQuit(IFDParser::QuitContext *ctx) = 0;


};

}  // namespace shout
