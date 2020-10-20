/**
* Copyright (c) 2020, Sumarte Technology, All right reserved
*
* @file: VbfMyVisitor.h
* The file is used to describe the visitor of vbf file.
*
* @date 07/10/2020
* @author chencheng@smarte.com
*/

#ifndef _VBFMYVISITOR_H_
#define _VBFMYVISITOR_H_

#include "VbfBaseVisitor.h"
#include "VbfDatabase.h"

class VbfMyVisitor : public antlrcpptest::VbfBaseVisitor
{
public:
	VbfMyVisitor();
	~VbfMyVisitor();

public:
	VbfDatabase VbfDatabase;

public:
	virtual antlrcpp::Any visitDatabase(antlrcpptest::VbfParser::DatabaseContext *ctx);

	virtual antlrcpp::Any visitVersionSection(antlrcpptest::VbfParser::VersionSectionContext *ctx);

	virtual antlrcpp::Any visitHeaderSection(antlrcpptest::VbfParser::HeaderSectionContext *ctx);

	virtual antlrcpp::Any visitDescription(antlrcpptest::VbfParser::DescriptionContext *context);

	virtual antlrcpp::Any visitSwPartNumber(antlrcpptest::VbfParser::SwPartNumberContext *context);

	virtual antlrcpp::Any visitSwPartType(antlrcpptest::VbfParser::SwPartTypeContext *context);

	virtual antlrcpp::Any visitDataFormatIdentifier(antlrcpptest::VbfParser::DataFormatIdentifierContext *context);

	virtual antlrcpp::Any visitEcuAddress(antlrcpptest::VbfParser::EcuAddressContext *context);

	virtual antlrcpp::Any visitFrameFormat(antlrcpptest::VbfParser::FrameFormatContext *context);

	virtual antlrcpp::Any visitErase(antlrcpptest::VbfParser::EraseContext *context);

	virtual antlrcpp::Any visitOmit(antlrcpptest::VbfParser::OmitContext *context);

	virtual antlrcpp::Any visitCall(antlrcpptest::VbfParser::CallContext *context);

	virtual antlrcpp::Any visitFileChecksum(antlrcpptest::VbfParser::FileChecksumContext *context);
};
#endif // !_VBFMYVISITOR_H_

/** End copyright (c) 2020, Sumarte Technology, All right reserved */
