/**
* Copyright (c) 2020, Sumarte Technology, All right reserved
*
* @file: VbfDatabase.cpp
* The file is used to handle the vbf file database.
*
* @date 07/10/2020
* @author chencheng@smarte.com
*/

#include "VbfDatabase.h"
#include "antlr4-runtime.h"

#include "VbfLexer.h"
#include "VbfParser.h"
#include "VbfMyVisitor.h"

using namespace antlr4;
using namespace antlrcpptest;
using namespace std;

/**
* The constructor is used to initialize the value of member.
*/
VbfDatabase::VbfDatabase() :
	versionSection(""),
	versionSectionValidity(NonExistent),
	headerSectionValidity(NonExistent),
	vbfDatabaseIsValid(false)
{
}

VbfDatabase::~VbfDatabase()
{
}

/**
* The function is used to get the validity of versionSection.
*
* @param: None.
* @retval: the validity of versionSection.
*/
ValidityOfContent_E VbfDatabase::getVersionSectionValidity()
{
    if (versionSectionValidity == NonExistent ||
        versionSectionValidity == ParseError)
        return versionSectionValidity;

    if (versionSectionValidity == Existent)
    {
        if (versionSection != "3.0")
            return ExistentButInvalid;
    }
    return ExistentAndValid;
}

/**
* The function is used to check the valid of vbf file database.
*
* @param: None.
* @retval: the valid of vbf file database.
*/
bool VbfDatabase::checkVbfDatabaseIsValid()
{
    // Version and header must be existent and valid.
    if (ExistentAndValid == (versionSectionValidity = getVersionSectionValidity()) &&
        ExistentAndValid == (headerSectionValidity = headerSection.getHeaderSectionValidity()))
        return true;

    return false;
}

VbfDatabase VbfDatabase::Load(std::string path)
{
	// Create antlr input stream. 
	ANTLRInputStream stream = ANTLRFileStream(path);

	// Create the lexer. 
	VbfLexer lexer(&stream);

	//// Start syntax analysing. 
	CommonTokenStream tokens(&lexer);

	// Create the parser to start sematic analysing. 
	VbfParser parser(&tokens);
	//parser.RemoveErrorListeners();
	//parser.AddErrorListener(new VbfErrorListener());

	//// Get the parse tree.
	antlr4::tree::ParseTree *tree = parser.database();

	// For test purpose, print out the parse tree.
	//cout << tree->toStringTree(&parser) << endl;
	
	VbfMyVisitor loader;
	loader.visit(tree);

	VbfDatabase d = loader.VbfDatabase;
	d.vbfDatabaseIsValid = d.checkVbfDatabaseIsValid();
	return d;
}

/** End copyright (c) 2020, Sumarte Technology, All right reserved */