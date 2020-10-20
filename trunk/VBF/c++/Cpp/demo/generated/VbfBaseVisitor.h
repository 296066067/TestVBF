
// Generated from Vbf.g4 by ANTLR 4.8

#pragma once


#include "antlr4-runtime.h"
#include "VbfVisitor.h"


namespace antlrcpptest {

/**
 * This class provides an empty implementation of VbfVisitor, which can be
 * extended to create a visitor which only needs to handle a subset of the available methods.
 */
class  VbfBaseVisitor : public VbfVisitor {
public:

  virtual antlrcpp::Any visitDatabase(VbfParser::DatabaseContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitVersionSection(VbfParser::VersionSectionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitHeaderSection(VbfParser::HeaderSectionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitDescription(VbfParser::DescriptionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitSwPartNumber(VbfParser::SwPartNumberContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitSwPartType(VbfParser::SwPartTypeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitDataFormatIdentifier(VbfParser::DataFormatIdentifierContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitEcuAddress(VbfParser::EcuAddressContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitFrameFormat(VbfParser::FrameFormatContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitErase(VbfParser::EraseContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitOmit(VbfParser::OmitContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitCall(VbfParser::CallContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitFileChecksum(VbfParser::FileChecksumContext *ctx) override {
    return visitChildren(ctx);
  }


};

}  // namespace antlrcpptest
