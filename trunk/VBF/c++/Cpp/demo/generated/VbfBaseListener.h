
// Generated from Vbf.g4 by ANTLR 4.8

#pragma once


#include "antlr4-runtime.h"
#include "VbfListener.h"


namespace antlrcpptest {

/**
 * This class provides an empty implementation of VbfListener,
 * which can be extended to create a listener which only needs to handle a subset
 * of the available methods.
 */
class  VbfBaseListener : public VbfListener {
public:

  virtual void enterDatabase(VbfParser::DatabaseContext * /*ctx*/) override { }
  virtual void exitDatabase(VbfParser::DatabaseContext * /*ctx*/) override { }

  virtual void enterVersionSection(VbfParser::VersionSectionContext * /*ctx*/) override { }
  virtual void exitVersionSection(VbfParser::VersionSectionContext * /*ctx*/) override { }

  virtual void enterHeaderSection(VbfParser::HeaderSectionContext * /*ctx*/) override { }
  virtual void exitHeaderSection(VbfParser::HeaderSectionContext * /*ctx*/) override { }

  virtual void enterDescription(VbfParser::DescriptionContext * /*ctx*/) override { }
  virtual void exitDescription(VbfParser::DescriptionContext * /*ctx*/) override { }

  virtual void enterSwPartNumber(VbfParser::SwPartNumberContext * /*ctx*/) override { }
  virtual void exitSwPartNumber(VbfParser::SwPartNumberContext * /*ctx*/) override { }

  virtual void enterSwPartType(VbfParser::SwPartTypeContext * /*ctx*/) override { }
  virtual void exitSwPartType(VbfParser::SwPartTypeContext * /*ctx*/) override { }

  virtual void enterDataFormatIdentifier(VbfParser::DataFormatIdentifierContext * /*ctx*/) override { }
  virtual void exitDataFormatIdentifier(VbfParser::DataFormatIdentifierContext * /*ctx*/) override { }

  virtual void enterEcuAddress(VbfParser::EcuAddressContext * /*ctx*/) override { }
  virtual void exitEcuAddress(VbfParser::EcuAddressContext * /*ctx*/) override { }

  virtual void enterFrameFormat(VbfParser::FrameFormatContext * /*ctx*/) override { }
  virtual void exitFrameFormat(VbfParser::FrameFormatContext * /*ctx*/) override { }

  virtual void enterErase(VbfParser::EraseContext * /*ctx*/) override { }
  virtual void exitErase(VbfParser::EraseContext * /*ctx*/) override { }

  virtual void enterOmit(VbfParser::OmitContext * /*ctx*/) override { }
  virtual void exitOmit(VbfParser::OmitContext * /*ctx*/) override { }

  virtual void enterCall(VbfParser::CallContext * /*ctx*/) override { }
  virtual void exitCall(VbfParser::CallContext * /*ctx*/) override { }

  virtual void enterFileChecksum(VbfParser::FileChecksumContext * /*ctx*/) override { }
  virtual void exitFileChecksum(VbfParser::FileChecksumContext * /*ctx*/) override { }


  virtual void enterEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void exitEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void visitTerminal(antlr4::tree::TerminalNode * /*node*/) override { }
  virtual void visitErrorNode(antlr4::tree::ErrorNode * /*node*/) override { }

};

}  // namespace antlrcpptest
