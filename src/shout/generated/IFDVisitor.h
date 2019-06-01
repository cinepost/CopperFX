
// Generated from /Users/max/dev/CopperFX/src/shout/shout_lib/IFD.g4 by ANTLR 4.7.1

#pragma once


#include "antlr4-runtime.h"
#include "IFDParser.h"


namespace shout {

/**
 * This class defines an abstract visitor for a parse tree
 * produced by IFDParser.
 */
class  IFDVisitor : public antlr4::tree::AbstractParseTreeVisitor {
public:

  /**
   * Visit parse trees produced by IFDParser.
   */
    virtual antlrcpp::Any visitFile(IFDParser::FileContext *context) = 0;

    virtual antlrcpp::Any visitLine(IFDParser::LineContext *context) = 0;

    virtual antlrcpp::Any visitSetenv(IFDParser::SetenvContext *context) = 0;

    virtual antlrcpp::Any visitVersion(IFDParser::VersionContext *context) = 0;

    virtual antlrcpp::Any visitDeclare(IFDParser::DeclareContext *context) = 0;

    virtual antlrcpp::Any visitStart(IFDParser::StartContext *context) = 0;

    virtual antlrcpp::Any visitEnd(IFDParser::EndContext *context) = 0;

    virtual antlrcpp::Any visitDetail(IFDParser::DetailContext *context) = 0;

    virtual antlrcpp::Any visitDetail_instance(IFDParser::Detail_instanceContext *context) = 0;

    virtual antlrcpp::Any visitProperty(IFDParser::PropertyContext *context) = 0;

    virtual antlrcpp::Any visitImage(IFDParser::ImageContext *context) = 0;

    virtual antlrcpp::Any visitGeomerty(IFDParser::GeomertyContext *context) = 0;

    virtual antlrcpp::Any visitTime(IFDParser::TimeContext *context) = 0;

    virtual antlrcpp::Any visitRaytrace(IFDParser::RaytraceContext *context) = 0;

    virtual antlrcpp::Any visitQuit(IFDParser::QuitContext *context) = 0;


};

}  // namespace shout
