
// Generated from Vbf.g4 by ANTLR 4.8

#pragma once


#include "antlr4-runtime.h"
#include "VbfParser.h"


namespace antlrcpptest {

/**
 * This class defines an abstract visitor for a parse tree
 * produced by VbfParser.
 */
class  VbfVisitor : public antlr4::tree::AbstractParseTreeVisitor {
public:

  /**
   * Visit parse trees produced by VbfParser.
   */
    virtual antlrcpp::Any visitDatabase(VbfParser::DatabaseContext *context) = 0;

    virtual antlrcpp::Any visitVersionSection(VbfParser::VersionSectionContext *context) = 0;

    virtual antlrcpp::Any visitHeaderSection(VbfParser::HeaderSectionContext *context) = 0;

    virtual antlrcpp::Any visitDescription(VbfParser::DescriptionContext *context) = 0;

    virtual antlrcpp::Any visitSwPartNumber(VbfParser::SwPartNumberContext *context) = 0;

    virtual antlrcpp::Any visitSwPartType(VbfParser::SwPartTypeContext *context) = 0;

    virtual antlrcpp::Any visitDataFormatIdentifier(VbfParser::DataFormatIdentifierContext *context) = 0;

    virtual antlrcpp::Any visitEcuAddress(VbfParser::EcuAddressContext *context) = 0;

    virtual antlrcpp::Any visitFrameFormat(VbfParser::FrameFormatContext *context) = 0;

    virtual antlrcpp::Any visitErase(VbfParser::EraseContext *context) = 0;

    virtual antlrcpp::Any visitOmit(VbfParser::OmitContext *context) = 0;

    virtual antlrcpp::Any visitCall(VbfParser::CallContext *context) = 0;

    virtual antlrcpp::Any visitFileChecksum(VbfParser::FileChecksumContext *context) = 0;


};

}  // namespace antlrcpptest
