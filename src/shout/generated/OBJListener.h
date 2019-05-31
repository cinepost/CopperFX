
// Generated from /Users/max/dev/shout/src/shout_lib/OBJ.g4 by ANTLR 4.7.1

#pragma once


#include "antlr4-runtime.h"
#include "OBJParser.h"


namespace shout {

/**
 * This interface defines an abstract listener for a parse tree produced by OBJParser.
 */
class  OBJListener : public antlr4::tree::ParseTreeListener {
public:

  virtual void enterStart(OBJParser::StartContext *ctx) = 0;
  virtual void exitStart(OBJParser::StartContext *ctx) = 0;

  virtual void enterLine(OBJParser::LineContext *ctx) = 0;
  virtual void exitLine(OBJParser::LineContext *ctx) = 0;

  virtual void enterFace(OBJParser::FaceContext *ctx) = 0;
  virtual void exitFace(OBJParser::FaceContext *ctx) = 0;

  virtual void enterVertex(OBJParser::VertexContext *ctx) = 0;
  virtual void exitVertex(OBJParser::VertexContext *ctx) = 0;

  virtual void enterMtllib(OBJParser::MtllibContext *ctx) = 0;
  virtual void exitMtllib(OBJParser::MtllibContext *ctx) = 0;

  virtual void enterObject(OBJParser::ObjectContext *ctx) = 0;
  virtual void exitObject(OBJParser::ObjectContext *ctx) = 0;

  virtual void enterUse_material(OBJParser::Use_materialContext *ctx) = 0;
  virtual void exitUse_material(OBJParser::Use_materialContext *ctx) = 0;

  virtual void enterGroup(OBJParser::GroupContext *ctx) = 0;
  virtual void exitGroup(OBJParser::GroupContext *ctx) = 0;


};

}  // namespace shout
