/**
* Copyright (c) 2020, Sumarte Technology, All right reserved
*
* @file: VbfDatabase.h
* The file is used to define the vbf file database.
*
* @date 07/10/2020
* @author chencheng@smarte.com
*/

#ifndef _VBFDATABASE_H_
#define _VBFDATABASE_H_

#include "VbfHeaderSection.h"

class VbfDatabase
{
public:
	VbfDatabase();
	~VbfDatabase();

public:
	std::string versionSection;
	ValidityOfContent_E versionSectionValidity;
	VbfHeaderSection headerSection;
	ValidityOfContent_E headerSectionValidity;
	bool vbfDatabaseIsValid;

public:
	ValidityOfContent_E getVersionSectionValidity();
	bool checkVbfDatabaseIsValid();
	static VbfDatabase Load(std::string path);
};

#endif // !1


/** End copyright (c) 2020, Sumarte Technology, All right reserved */
