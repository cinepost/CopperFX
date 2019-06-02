
// Generated from /Users/max/dev/CopperFX/src/shout/shout_lib/IFD.g4 by ANTLR 4.7.1

#pragma once


#include "antlr4-runtime.h"
#include "IFDVisitor.h"


namespace shout {

/**
 * This class provides an empty implementation of IFDVisitor, which can be
 * extended to create a visitor which only needs to handle a subset of the available methods.
 */
class  IFDBaseVisitor : public IFDVisitor {
public:

  virtual antlrcpp::Any visitFile(IFDParser::FileContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitLine(IFDParser::LineContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitBgeo(IFDParser::BgeoContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitSetenv(IFDParser::SetenvContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitVersion(IFDParser::VersionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitDeclare(IFDParser::DeclareContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitStart(IFDParser::StartContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitEnd(IFDParser::EndContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitDetail(IFDParser::DetailContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitProperty(IFDParser::PropertyContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitImage(IFDParser::ImageContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitGeomerty(IFDParser::GeomertyContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitTime(IFDParser::TimeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitRaytrace(IFDParser::RaytraceContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitQuit(IFDParser::QuitContext *ctx) override {
    return visitChildren(ctx);
  }


};

}  // namespace shout
