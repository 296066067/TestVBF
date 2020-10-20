/* Copyright (c) 2012-2017 The ANTLR Project. All rights reserved.
 * Use of this file is governed by the BSD 3-clause license that
 * can be found in the LICENSE.txt file in the project root.
 */

//
//  main.cpp
//  antlr4-cpp-demo
//
//  Created by Mike Lischke on 13.03.16.
//

#include "VbfDatabase.h"
using namespace std;

void print_database()
{
	string path = "E:\\Sumarte\\Code\\vba3_VBF\\trunk\\VBF\\c++\\Cpp\\demo\\Windows\\antlr4-cpp-demo\\test.vbf";
	VbfDatabase database = VbfDatabase::Load(path);

	cout << "\r\n vbf file valid : " << database.vbfDatabaseIsValid << " version_section valid : " << database.versionSectionValidity << " header_section valid : " << database.headerSectionValidity << endl;

	cout << "\r\n version valid : " << database.versionSectionValidity << endl;
	cout << " version value : " << database.versionSection << endl;

	cout << "\r\n description valid : " << database.headerSection.descriptionValidity << endl;
	for (int i = 0; i < database.headerSection.description.size(); i++)
	{
		cout << " description value : " << database.headerSection.description[i] << endl;
	}

	cout << "\r\n sw_part_number valid : " << database.headerSection.swPartNumberValidity << endl;
	for (int i = 0; i < database.headerSection.swPartNumber.size(); i++)
	{
		cout << " sw_part_number value : " << database.headerSection.swPartNumber[i] << endl;
	}

	cout << "\r\n sw_part_type valid : " << database.headerSection.swPartTypeValidity << endl;
	cout << " sw_part_type value : " << database.headerSection.swPartType << endl;

	cout << "\r\n data_format_identifier valid : " << database.headerSection.dataFormatIdentifierValidity << endl;
	cout << " data_format_identifier value : 0x" << hex << database.headerSection.dataFormatIdentifier << endl;

	cout << "\r\n ecu_address valid : " << database.headerSection.ecuAddressValidity << endl;
	for (int i = 0; i < database.headerSection.ecuAddress.size(); i++)
	{
		cout << " ecu_address value : 0x" << hex << database.headerSection.ecuAddress[i] << endl;
	}

	cout << "\r\n frame_format valid : " << database.headerSection.frameFormatValidity << endl;
	cout << " frame_format value : " << database.headerSection.frameFormat << endl;

	cout << "\r\n erase valid : " << database.headerSection.eraseValidity << endl;
	for (int i = 0; i < database.headerSection.erase.size(); i++)
	{
		cout << " erase value : 0x" << hex << database.headerSection.erase[i].startAddress << " 0x" << hex << database.headerSection.erase[i].length << endl;
	}

	cout << "\r\n omit valid : " << database.headerSection.omitValidity << endl;
	for (int i = 0; i < database.headerSection.omit.size(); i++)
	{
		cout << " omit value : 0x" << hex << database.headerSection.omit[i].startAddress << " 0x" << hex << database.headerSection.omit[i].length << endl;
	}

	cout << "\r\n call valid : " << database.headerSection.callValidity << endl;
	cout << " call value : 0x" << hex << database.headerSection.call << endl;

	cout << "\r\n file_checksum valid : " << database.headerSection.fileChecksumValidity << endl;
	cout << " file_checksum value : 0x" << hex << database.headerSection.fileChecksum << endl;
}

int main(int argc, const char * argv[]) {

	int i = 0;
	print_database();
	while (true)
	{
		i = 0;
	}
	return 0;
}
