/**
* Copyright (c) 2020, Sumarte Technology, All right reserved
*
* @file: VbfDatabase.cpp
* The file is used to handle the vbf file database.
*
* @date 07/10/2020
* @author chencheng@smarte.com
*/

#include "VbfMyVisitor.h"
using namespace std;

VbfMyVisitor::VbfMyVisitor()
{
}

VbfMyVisitor::~VbfMyVisitor()
{
}

antlrcpp::Any VbfMyVisitor::visitDatabase(antlrcpptest::VbfParser::DatabaseContext * context)
{
	//Exception is not null means some errors happen and vbf file is invalid.
	if (context->exception != NULL)
	{
		//cout << 12 << endl;
		VbfDatabase.vbfDatabaseIsValid = false;
		return antlrcpptest::VbfBaseVisitor::visitDatabase(context);
	}

	return antlrcpptest::VbfBaseVisitor::visitDatabase(context);
}

antlrcpp::Any VbfMyVisitor::visitVersionSection(antlrcpptest::VbfParser::VersionSectionContext * context)
{
	//Exception is not null means some errors happen and vbf file is invalid.
	if (context->exception != NULL)
	{
		//Console.WriteLine(context->exception);
		VbfDatabase.versionSectionValidity = ParseError;
		return antlrcpptest::VbfBaseVisitor::visitVersionSection(context);
	}

	VbfDatabase.versionSectionValidity = Existent;
	VbfDatabase.versionSection = context->Reals()->getText();
	return antlrcpptest::VbfBaseVisitor::visitVersionSection(context);
}

antlrcpp::Any VbfMyVisitor::visitHeaderSection(antlrcpptest::VbfParser::HeaderSectionContext * context)
{
	//Exception is not null means some errors happen and vbf file is invalid.
	if (context->exception != NULL)
	{
		//Console.WriteLine(context.exception);
		VbfDatabase.headerSection.headerSectionValidity = ParseError;
		return antlrcpptest::VbfBaseVisitor::visitHeaderSection(context);
	}

	VbfDatabase.headerSection.headerSectionValidity = Existent;
	return antlrcpptest::VbfBaseVisitor::visitHeaderSection(context);
}

antlrcpp::Any VbfMyVisitor::visitDescription(antlrcpptest::VbfParser::DescriptionContext * context)
{
	string str;
	std::vector<antlr4::tree::TerminalNode *> node = context->String();
	size_t pos = 0;

	//Exception is not null means some errors happen and vbf file is invalid.
	if (context->exception != NULL)
	{
		//Console.WriteLine(context.exception);
		VbfDatabase.headerSection.descriptionValidity = ParseError;
		return antlrcpptest::VbfBaseVisitor::visitDescription(context);
	}

	// Walk through all value and gather into the description.
	for (int i = 0; i < node.size(); i++)
	{
		//Remove the double-quoted in the string.
		str = node[i]->getText();
		while (string::npos != (pos = str.find("\"")))
		{
			str.erase(pos, 1);
		}
		VbfDatabase.headerSection.description.push_back(str);
	}
	
	VbfDatabase.headerSection.descriptionValidity = Existent;
	return antlrcpptest::VbfBaseVisitor::visitDescription(context);
}

antlrcpp::Any VbfMyVisitor::visitSwPartNumber(antlrcpptest::VbfParser::SwPartNumberContext * context)
{
	string str;
	std::vector<antlr4::tree::TerminalNode *> node = context->String();
	size_t pos = 0;

	//Exception is not null means some errors happen and vbf file is invalid.
	if (context->exception != NULL)
	{
		//Console.WriteLine(context.exception);
		VbfDatabase.headerSection.swPartNumberValidity = ParseError;
		return antlrcpptest::VbfBaseVisitor::visitSwPartNumber(context);
	}

	// Walk through all value and gather into the sw part number.
	for (int i = 0; i < node.size(); i++)
	{
		//Remove the double-quoted in the string.
		str = node[i]->getText();
		while (string::npos != (pos = str.find("\"")))
		{
			str.erase(pos, 1);
		}
		VbfDatabase.headerSection.swPartNumber.push_back(str);
	}

	VbfDatabase.headerSection.swPartNumberValidity = Existent;
	return antlrcpptest::VbfBaseVisitor::visitSwPartNumber(context);
}

antlrcpp::Any VbfMyVisitor::visitSwPartType(antlrcpptest::VbfParser::SwPartTypeContext * context)
{
	//Exception is not null means some errors happen and vbf file is invalid.
	if (context->exception != NULL)
	{
		//Console.WriteLine(context.exception);
		VbfDatabase.headerSection.swPartTypeValidity = ParseError;
		return antlrcpptest::VbfBaseVisitor::visitSwPartType(context);
	}

	//Get the frame format string from the tree and compare the string.
	string str = context->children[2]->getText();
	if (str == "CARCFG")
		VbfDatabase.headerSection.swPartType = CARCFG;
	else if (str == "CUSTOM")
		VbfDatabase.headerSection.swPartType = CUSTOM;
	else if (str == "DATA")
		VbfDatabase.headerSection.swPartType = DATA;
	else if (str == "EXE")
		VbfDatabase.headerSection.swPartType = EXE;
	else if (str == "GBL")
		VbfDatabase.headerSection.swPartType = GBL;
	else if (str == "SBL")
		VbfDatabase.headerSection.swPartType = Test;
	else if (str == "SIGCFG")
		VbfDatabase.headerSection.swPartType = SIGCFG;
	else if (str == "TEST")
		VbfDatabase.headerSection.swPartType = TEST;
	else
	{
		VbfDatabase.headerSection.swPartType = InvalidSwPartType;
		VbfDatabase.headerSection.swPartTypeValidity = ExistentButInvalid;
	}

	VbfDatabase.headerSection.swPartTypeValidity = Existent;
	return antlrcpptest::VbfBaseVisitor::visitSwPartType(context);
}

antlrcpp::Any VbfMyVisitor::visitDataFormatIdentifier(antlrcpptest::VbfParser::DataFormatIdentifierContext * context)
{
	uint16_t data = 0;
	antlr4::tree::TerminalNode* node;
	//Exception is not null means some errors happen and vbf file is invalid.
	if (context->exception != NULL)
	{
		//Console.WriteLine(context.exception);
		VbfDatabase.headerSection.dataFormatIdentifierValidity = ParseError;
		return antlrcpptest::VbfBaseVisitor::visitDataFormatIdentifier(context);
	}

	try
	{
		string str;
		size_t pos;
		if (NULL != (node = context->Hexadecimal()))
		{
			str = node->getText();
			data = stoi(str, 0, 16);
		}
			
		else if (NULL != (node = context->Binary()))
		{
			str = node->getText();
			if (string::npos != (pos = str.find("0b")))
				data = stoi(str.erase(pos, 2), 0, 2);
			else if (string::npos != (pos = str.find("0B")))
				data = stoi(str.erase(pos, 2), 0, 2);
		}
		else if (NULL != (node = context->Decimal()))
		{
			str = node->getText();
			data = stoi(str, 0, 10);
		}
	}
	catch (...)
	{
		// Convert string to uint16 failed means vbf file is invalid.
		//Console.WriteLine(e.Message);
		VbfDatabase.headerSection.dataFormatIdentifier = ExistentButInvalid;
		return antlrcpptest::VbfBaseVisitor::visitDataFormatIdentifier(context);
	}

	VbfDatabase.headerSection.dataFormatIdentifierValidity = Existent;
	VbfDatabase.headerSection.dataFormatIdentifier = data;
	return antlrcpptest::VbfBaseVisitor::visitDataFormatIdentifier(context);
}

antlrcpp::Any VbfMyVisitor::visitEcuAddress(antlrcpptest::VbfParser::EcuAddressContext * context)
{
	uint16_t data = 0;
	std::vector<antlr4::tree::TerminalNode *> node = context->Hexadecimal();
	
	//Exception is not null means some errors happen and vbf file is invalid.
	if (context->exception != NULL)
	{
		//Console.WriteLine(context.exception);
		VbfDatabase.headerSection.ecuAddressValidity = ParseError;
		return antlrcpptest::VbfBaseVisitor::visitEcuAddress(context);
	}

	for (int i = 0; i < node.size(); i++)
	{
		try
		{
			data = stoi(node[i]->getText(), 0, 16);
		}
		catch (...)
		{
			// Convert string to uint16 failed means vbf file is invalid.
			//Console.WriteLine(e.Message);
			VbfDatabase.headerSection.ecuAddressValidity = ExistentButInvalid;
			return antlrcpptest::VbfBaseVisitor::visitEcuAddress(context);
		}
		VbfDatabase.headerSection.ecuAddress.push_back(data);
	}

	VbfDatabase.headerSection.ecuAddressValidity = Existent;
	return antlrcpptest::VbfBaseVisitor::visitEcuAddress(context);
}

antlrcpp::Any VbfMyVisitor::visitFrameFormat(antlrcpptest::VbfParser::FrameFormatContext * context)
{
	//Exception is not null means some errors happen and vbf file is invalid.
	if (context->exception != NULL)
	{
		//Console.WriteLine(context.exception);
		VbfDatabase.headerSection.frameFormatValidity = ParseError;
		return antlrcpptest::VbfBaseVisitor::visitFrameFormat(context);
	}

	//Get the frame format string from the tree and compare the string.
	string str = context->children[2]->getText();
	if (str == ("CAN_STANDARD"))
		VbfDatabase.headerSection.frameFormat = CAN_STANDARD;
	else if (str == ("CAN_EXTENDED"))
		VbfDatabase.headerSection.frameFormat = CAN_EXTENDED;
	else
	{
		VbfDatabase.headerSection.frameFormat = InvalidFrameFormat;
		VbfDatabase.headerSection.frameFormatValidity = ExistentButInvalid;
	}

	VbfDatabase.headerSection.frameFormatValidity = Existent;
	return antlrcpptest::VbfBaseVisitor::visitFrameFormat(context);
}

antlrcpp::Any VbfMyVisitor::visitErase(antlrcpptest::VbfParser::EraseContext * context)
{
	uint32_t data = 0;
	int count = 0;
	Block_T block;
	std::vector<antlr4::tree::TerminalNode *> node = context->Hexadecimal();

	//Exception is not null means some errors happen and vbf file is invalid.
	if (context->exception != NULL)
	{
		//Console.WriteLine(context.exception);
		VbfDatabase.headerSection.eraseValidity = ParseError;
		return antlrcpptest::VbfBaseVisitor::visitErase(context);
	}

	//If sw part type = SBL or GBL, the VBF file shall not contain the erase identifier.
	if (VbfDatabase.headerSection.swPartType == Test || 
		VbfDatabase.headerSection.swPartType == GBL ||
		VbfDatabase.headerSection.swPartType == InvalidSwPartType)
	{
		//Console.WriteLine("erase is invalid. ");
		VbfDatabase.vbfDatabaseIsValid = false;
		return antlrcpptest::VbfBaseVisitor::visitErase(context);
	}

	// Walk through all value and gather into the erase address.
	for (int i = 0; i < node.size(); i++)
	{
		try
		{
			data = stoi(node[i]->getText(), 0, 16);
			if (count % 2 == 0)
				block.startAddress = data;
			else
				block.length = data;
			count++;
		}
		catch (...)
		{
			// Convert string to uint32 failed means vbf file is invalid.
			//Console.WriteLine(e.Message);
			VbfDatabase.headerSection.eraseValidity = ExistentButInvalid;
			return antlrcpptest::VbfBaseVisitor::visitErase(context);
		}

		if (count % 2 == 0)
			VbfDatabase.headerSection.erase.push_back(block);
	}

	VbfDatabase.headerSection.eraseValidity = Existent;
	return antlrcpptest::VbfBaseVisitor::visitErase(context);
}

antlrcpp::Any VbfMyVisitor::visitOmit(antlrcpptest::VbfParser::OmitContext * context)
{
	uint32_t data = 0;
	int count = 0;
	Block_T block;
	std::vector<antlr4::tree::TerminalNode *> node = context->Hexadecimal();

	//Exception is not null means some errors happen and vbf file is invalid.
	if (context->exception != NULL)
	{
		//Console.WriteLine(context.exception);
		VbfDatabase.headerSection.omitValidity = ParseError;
		return antlrcpptest::VbfBaseVisitor::visitOmit(context);
	}

	// Walk through all value and gather into the omit address.
	for (int i = 0; i < node.size(); i++)
	{
		try
		{
			data = stoi(node[i]->getText(), 0, 16);
			if (count % 2 == 0)
				block.startAddress = data;
			else
				block.length = data;
			count++;
		}
		catch (...)
		{
			// Convert string to uint32 failed means vbf file is invalid.
			//Console.WriteLine(e.Message);
			VbfDatabase.headerSection.omitValidity = ExistentButInvalid;
			return antlrcpptest::VbfBaseVisitor::visitOmit(context);
		}

		if (count % 2 == 0)
			VbfDatabase.headerSection.omit.push_back(block);
	}

	VbfDatabase.headerSection.omitValidity = Existent;
	return antlrcpptest::VbfBaseVisitor::visitOmit(context);
}

antlrcpp::Any VbfMyVisitor::visitCall(antlrcpptest::VbfParser::CallContext * context)
{
	uint32_t data = 0;
	//Exception is not null means some errors happen and vbf file is invalid.
	if (context->exception != NULL)
	{
		//Console.WriteLine(context.exception);
		VbfDatabase.headerSection.callValidity = ParseError;
		return antlrcpptest::VbfBaseVisitor::visitCall(context);
	}

	try
	{
		data = stoi(context->Hexadecimal()->getText(), 0, 16);
	}
	catch (...)
	{
		// Convert string to uint32 failed means vbf file is invalid.
		//Console.WriteLine(e.Message);
		VbfDatabase.headerSection.callValidity = ExistentButInvalid;
		return antlrcpptest::VbfBaseVisitor::visitCall(context);
	}

	VbfDatabase.headerSection.callValidity = Existent;
	VbfDatabase.headerSection.call = data;
	return antlrcpptest::VbfBaseVisitor::visitCall(context);
}

antlrcpp::Any VbfMyVisitor::visitFileChecksum(antlrcpptest::VbfParser::FileChecksumContext * context)
{
	uint32_t data = 0;

	//Exception is not null means some errors happen and vbf file is invalid.
	if (context->exception != NULL)
	{
		//Console.WriteLine(context.exception);
		VbfDatabase.headerSection.fileChecksumValidity = ParseError;
		return antlrcpptest::VbfBaseVisitor::visitFileChecksum(context);
	}

	try
	{
		data = stoi(context->Hexadecimal()->getText(), 0, 16);
	}
	catch (...)
	{
		// Convert string to uint32 failed means vbf file is invalid.
		//Console.WriteLine(e.Message);
		VbfDatabase.headerSection.fileChecksumValidity = ExistentButInvalid;
		return antlrcpptest::VbfBaseVisitor::visitFileChecksum(context);
	}

	VbfDatabase.headerSection.fileChecksumValidity = Existent;
	VbfDatabase.headerSection.fileChecksum = data;
	return antlrcpptest::VbfBaseVisitor::visitFileChecksum(context);
}


/** End copyright (c) 2020, Sumarte Technology, All right reserved */

