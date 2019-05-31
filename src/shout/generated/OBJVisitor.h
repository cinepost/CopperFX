
// Generated from /Users/max/dev/shout/src/shout_lib/OBJ.g4 by ANTLR 4.7.1

#pragma once


#include "antlr4-runtime.h"
#include "OBJParser.h"


namespace shout {

/**
 * This class defines an abstract visitor for a parse tree
 * produced by OBJParser.
 */
class  OBJVisitor : public antlr4::tree::AbstractParseTreeVisitor {
public:

  /**
   * Visit parse trees produced by OBJParser.
   */
    virtual antlrcpp::Any visitStart(OBJParser::StartContext *context) = 0;

    virtual antlrcpp::Any visitLine(OBJParser::LineContext *context) = 0;

    virtual antlrcpp::Any visitFace(OBJParser::FaceContext *context) = 0;

    virtual antlrcpp::Any visitVertex(OBJParser::VertexContext *context) = 0;

    virtual antlrcpp::Any visitMtllib(OBJParser::MtllibContext *context) = 0;

    virtual antlrcpp::Any visitObject(OBJParser::ObjectContext *context) = 0;

    virtual antlrcpp::Any visitUse_material(OBJParser::Use_materialContext *context) = 0;

    virtual antlrcpp::Any visitGroup(OBJParser::GroupContext *context) = 0;


};

}  // namespace shout
