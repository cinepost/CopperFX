
// Generated from /Users/max/dev/shout/src/shout_lib/OBJ.g4 by ANTLR 4.7.1

#pragma once


#include "antlr4-runtime.h"
#include "OBJListener.h"


namespace shout {

/**
 * This class provides an empty implementation of OBJListener,
 * which can be extended to create a listener which only needs to handle a subset
 * of the available methods.
 */
class  OBJBaseListener : public OBJListener {
public:

  virtual void enterStart(OBJParser::StartContext * /*ctx*/) override { }
  virtual void exitStart(OBJParser::StartContext * /*ctx*/) override { }

  virtual void enterLine(OBJParser::LineContext * /*ctx*/) override { }
  virtual void exitLine(OBJParser::LineContext * /*ctx*/) override { }

  virtual void enterFace(OBJParser::FaceContext * /*ctx*/) override { }
  virtual void exitFace(OBJParser::FaceContext * /*ctx*/) override { }

  virtual void enterVertex(OBJParser::VertexContext * /*ctx*/) override { }
  virtual void exitVertex(OBJParser::VertexContext * /*ctx*/) override { }

  virtual void enterMtllib(OBJParser::MtllibContext * /*ctx*/) override { }
  virtual void exitMtllib(OBJParser::MtllibContext * /*ctx*/) override { }

  virtual void enterObject(OBJParser::ObjectContext * /*ctx*/) override { }
  virtual void exitObject(OBJParser::ObjectContext * /*ctx*/) override { }

  virtual void enterUse_material(OBJParser::Use_materialContext * /*ctx*/) override { }
  virtual void exitUse_material(OBJParser::Use_materialContext * /*ctx*/) override { }

  virtual void enterGroup(OBJParser::GroupContext * /*ctx*/) override { }
  virtual void exitGroup(OBJParser::GroupContext * /*ctx*/) override { }


  virtual void enterEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void exitEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void visitTerminal(antlr4::tree::TerminalNode * /*node*/) override { }
  virtual void visitErrorNode(antlr4::tree::ErrorNode * /*node*/) override { }

};

}  // namespace shout
