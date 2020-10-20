
// Generated from Vbf.g4 by ANTLR 4.8

#pragma once


#include "antlr4-runtime.h"
#include "VbfParser.h"


namespace antlrcpptest {

/**
 * This interface defines an abstract listener for a parse tree produced by VbfParser.
 */
class  VbfListener : public antlr4::tree::ParseTreeListener {
public:

  virtual void enterDatabase(VbfParser::DatabaseContext *ctx) = 0;
  virtual void exitDatabase(VbfParser::DatabaseContext *ctx) = 0;

  virtual void enterVersionSection(VbfParser::VersionSectionContext *ctx) = 0;
  virtual void exitVersionSection(VbfParser::VersionSectionContext *ctx) = 0;

  virtual void enterHeaderSection(VbfParser::HeaderSectionContext *ctx) = 0;
  virtual void exitHeaderSection(VbfParser::HeaderSectionContext *ctx) = 0;

  virtual void enterDescription(VbfParser::DescriptionContext *ctx) = 0;
  virtual void exitDescription(VbfParser::DescriptionContext *ctx) = 0;

  virtual void enterSwPartNumber(VbfParser::SwPartNumberContext *ctx) = 0;
  virtual void exitSwPartNumber(VbfParser::SwPartNumberContext *ctx) = 0;

  virtual void enterSwPartType(VbfParser::SwPartTypeContext *ctx) = 0;
  virtual void exitSwPartType(VbfParser::SwPartTypeContext *ctx) = 0;

  virtual void enterDataFormatIdentifier(VbfParser::DataFormatIdentifierContext *ctx) = 0;
  virtual void exitDataFormatIdentifier(VbfParser::DataFormatIdentifierContext *ctx) = 0;

  virtual void enterEcuAddress(VbfParser::EcuAddressContext *ctx) = 0;
  virtual void exitEcuAddress(VbfParser::EcuAddressContext *ctx) = 0;

  virtual void enterFrameFormat(VbfParser::FrameFormatContext *ctx) = 0;
  virtual void exitFrameFormat(VbfParser::FrameFormatContext *ctx) = 0;

  virtual void enterErase(VbfParser::EraseContext *ctx) = 0;
  virtual void exitErase(VbfParser::EraseContext *ctx) = 0;

  virtual void enterOmit(VbfParser::OmitContext *ctx) = 0;
  virtual void exitOmit(VbfParser::OmitContext *ctx) = 0;

  virtual void enterCall(VbfParser::CallContext *ctx) = 0;
  virtual void exitCall(VbfParser::CallContext *ctx) = 0;

  virtual void enterFileChecksum(VbfParser::FileChecksumContext *ctx) = 0;
  virtual void exitFileChecksum(VbfParser::FileChecksumContext *ctx) = 0;


};

}  // namespace antlrcpptest
