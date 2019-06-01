#include <boost/log/core.hpp>
#include <boost/log/trivial.hpp>
#include <boost/log/expressions.hpp>

#include <string>
#include <iostream>
#include <sstream>

#include <locale>
#include <codecvt>

#include "antlr4-runtime.h"
#include "shout/generated/IFDLexer.h"
#include "shout/generated/IFDParser.h"
#include "shout/generated/IFDBaseListener.h"
#include "shout/generated/IFDBaseVisitor.h"

#include "BinaryAntlrInputStream.h"
#include "SCN_IFDTranslator.h"

using namespace shout;
using namespace antlr4;


class IFDFileVisitor : public IFDBaseVisitor {
public:
  virtual antlrcpp::Any visitFile(IFDParser::FileContext *ctx) override {
    std::cout << "visitFile" << std::endl;
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitSetenv(IFDParser::SetenvContext *ctx) override {
    std::cout << "visitSetenv" << std::endl;
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitVersion(IFDParser::VersionContext *ctx) override {
    std::cout << "visitVersion" << std::endl;
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitDetail(IFDParser::DetailContext *ctx) override {
    std::cout << "visitDetail_1" << std::endl;
    return true;
  }

  virtual antlrcpp::Any visitDetail_instance(IFDParser::Detail_instanceContext *ctx) override {
    std::cout << "visitDetail_2" << std::endl;
    return true;
  }

};

SCN_IFDTranslator::SCN_IFDTranslator() {
  BOOST_LOG_TRIVIAL(debug) << "IFD file translator constructed!";
}


SCN_IFDTranslator::~SCN_IFDTranslator() {
  BOOST_LOG_TRIVIAL(debug) << "IFD file translator destructed!";
}


const char *SCN_IFDTranslator::formatName() const{
    return "Mantra IFD";
}


int SCN_IFDTranslator::checkExtension(const char *name) {
    if (strcmp(name, ".ifd"))return 0;
    return 1;
}


void SCN_IFDTranslator::getFileExtensions(std::vector<std::string> &extensions) const{
    extensions.insert(extensions.end(), _ifd_extensions.begin(), _ifd_extensions.end());
}


int SCN_IFDTranslator::checkMagicNumber(unsigned magic) {
    return 0;
}


SCN_Scene::IOStatus SCN_IFDTranslator::fileLoad(SCN_Scene &scn, std::istream &in, bool ate_magic) {
  BinaryANTLRInputStream input(in);
  //antlr4::ANTLRInputStream input(in);
  std::cout << "1\n";

  IFDLexer lexer(&input);
  std::cout << "2\n";

  antlr4::CommonTokenStream tokens(&lexer);
  std::cout << "3\n";

  IFDParser parser(&tokens);
  std::cout << "4\n";

  std::cout << "SCN_IFDTranslator::fileLoad.. parser.file()" << std::endl;
  //antlr4::tree::ParseTree* tree  = parser.file();
  IFDParser::FileContext* tree = parser.file();

  //IFDFileListener listener;
  //std::cout << "SCN_IFDTranslator::fileLoad.. DEFAULT.walk()" << std::endl;
  //antlr4::tree::ParseTreeWalker::DEFAULT.walk(&listener, tree);

  IFDFileVisitor visitor;
  std::cout << "SCN_IFDTranslator::fileLoad.. visitor.visitFile(tree)" << std::endl;
  visitor.visitFile(tree);

  return true;
}


// factory methods

std::vector<std::string> *SCN_IFDTranslatorFactory::myExtensions() {
    return &_ifd_extensions;
}



SCN_IOTranslator *SCN_IFDTranslatorFactory::myConstructor() {
    return new SCN_IFDTranslator();
}