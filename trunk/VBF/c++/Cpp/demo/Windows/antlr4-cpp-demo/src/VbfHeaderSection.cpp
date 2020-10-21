/**
* Copyright (c) 2020, Sumarte Technology, All right reserved
*
* @file: VbfHeaderSection.cpp
* The file is used to handle the vbf file header section.
*
* @date 07/10/2020
* @author chencheng@smarte.com
*/
#include "VbfHeaderSection.h"

using namespace std;

/**
* The constructor is used to initialize the value of member.
*/
VbfHeaderSection::VbfHeaderSection() :
				descriptionValidity(NonExistent),
				swPartNumberValidity(NonExistent),
				swPartTypeValidity(NonExistent),
				dataFormatIdentifierValidity(NonExistent),
				ecuAddressValidity(NonExistent),
				frameFormatValidity(NonExistent),
				eraseValidity(NonExistent),
				omitValidity(NonExistent),
				callValidity(NonExistent),
				fileChecksumValidity(NonExistent),
				headerSectionValidity(NonExistent),
				swPartType(InvalidSwPartType),
				dataFormatIdentifier(0),
				frameFormat(InvalidFrameFormat),
				call(0),
				fileChecksum(0)
{
}

VbfHeaderSection::~VbfHeaderSection()
{
}

/**
* The function is used to get the validity of description.
*
* @param: None.
* @retval: the validity of description.
*/
ValidityOfContent_E VbfHeaderSection::getDescriptionValidity()
{
   if (descriptionValidity == NonExistent ||
        descriptionValidity == ParseError)
        return descriptionValidity;

    if (descriptionValidity == Existent)
    {
        //The description contain a maximum of 16 rows, with each row containing a maximum of 80 characters.
        for (int i = 0; i < description.size(); i++)
        {
            if (description[i].length() > 80 || i > 15)
                return ExistentButInvalid;
        }
    }
    return ExistentAndValid;
}

/**
* The function is used to get the validity of swPartNumber.
*
* @param: None.
* @retval: the validity of swPartNumber.
*/
ValidityOfContent_E VbfHeaderSection::getSwPartNumberValidity()
{
    string str;

    if (swPartNumberValidity == NonExistent ||
        swPartNumberValidity == ParseError)
        return swPartNumberValidity;

    for (int i = 0; i < swPartNumber.size(); i++)
    {
        str = swPartNumber[i];
        //The sw part number shall be contained in quotes and shall consist of a maximum of 24 characters(bytes).
        //No white space characters or comments are allowed within these quotes.
        if (string::npos != str.find(" ") || str.length() > 24 ||
            string::npos != str.find("/*") || string::npos != str.find("*/") || i > 1)
            return ExistentButInvalid;
    }
    return ExistentAndValid;
}

/**
* The function is used to get the validity of swPartType.
*
* @param: None.
* @retval: the validity of swPartType.
*/
ValidityOfContent_E VbfHeaderSection::getSwPartTypeValidity()
{
	if (swPartTypeValidity == NonExistent ||
        swPartTypeValidity == ParseError ||
        swPartTypeValidity == ExistentButInvalid)
        return swPartTypeValidity;

    if (swPartTypeValidity == Existent)
    {
        if (swPartType == InvalidSwPartType)
            return ExistentButInvalid;
    }
    return ExistentAndValid;
}

/**
* The function is used to get the validity of dataFormatIdentifier.
*
* @param: None.
* @retval: the validity of dataFormatIdentifier.
*/
ValidityOfContent_E VbfHeaderSection::getDataFormatIdentifierValidity()
{
    if (dataFormatIdentifierValidity == NonExistent ||
        dataFormatIdentifierValidity == ParseError ||
        dataFormatIdentifierValidity == ExistentButInvalid)
        return dataFormatIdentifierValidity;

    if (dataFormatIdentifierValidity == Existent)
    {
        //Valid values for the data format identifier are one byte long with a range of 0x00 to 0xFF.
        if (dataFormatIdentifier > 0xFF)
            return ExistentButInvalid;
    }
    return ExistentAndValid;
}

/**
* The function is used to get the validity of ecuAddress.
*
* @param: None.
* @retval: the validity of ecuAddress.
*/
ValidityOfContent_E VbfHeaderSection::getEcuAddressValidity()
{
    if (ecuAddressValidity == NonExistent ||
        ecuAddressValidity == ParseError ||
        ecuAddressValidity == ExistentButInvalid)
        return ecuAddressValidity;

    if (ecuAddressValidity == Existent)
    {
        if (frameFormat == CAN_EXTENDED)
        {
            if (ecuAddress.size() == 1)
            {
                if (ecuAddress[0] > 0xFF)
                    return ExistentButInvalid;
            }
            if (ecuAddress.size() == 3)
            {
                if (ecuAddress[0] > 0xFF ||
                    ecuAddress[1] > 0x07 ||
                    ecuAddress[2] > 0xFF)
                    return ExistentButInvalid;
            }
        }
        else if (frameFormat == CAN_STANDARD)
        {
            if (ecuAddress.size() == 1)
            {
                if (ecuAddress[0] > 0x7FF)
                    return ExistentButInvalid;
            }
            if (ecuAddress.size() == 3)
            {
                if (ecuAddress[0] > 0x7FF ||
                    ecuAddress[1] > 0xFF ||
                    ecuAddress[2] > 0xFF)
                    return ExistentButInvalid;
            }
        }
        else
            return ExistentButInvalid;
    }
    return ExistentAndValid;
}

/**
* The function is used to get the validity of frameFormat.
*
* @param: None.
* @retval: the validity of frameFormat.
*/
ValidityOfContent_E VbfHeaderSection::getFrameFormatValidity()
{
    if (frameFormatValidity == NonExistent ||
        frameFormatValidity == ParseError ||
        frameFormatValidity == ExistentButInvalid)
        return frameFormatValidity;

    if (frameFormatValidity == Existent)
    {
        if (frameFormat == InvalidFrameFormat)
            return ExistentButInvalid;
    }
    return ExistentAndValid;
}

/**
* The function is used to get the validity of erase.
*
* @param: None.
* @retval: the validity of erase.
*/
ValidityOfContent_E VbfHeaderSection::getEraseValidity()
{
    if (eraseValidity == NonExistent ||
        eraseValidity == ParseError ||
        eraseValidity == ExistentButInvalid)
        return eraseValidity;

    if (eraseValidity == Existent)
    {
        uint64_t data = 0;
        for (int i = 0; i < erase.size(); i++)
        {
            // Address overflow.
            data = (uint64_t)erase[i].startAddress + (uint64_t)erase[i].length;
            if (data > 0xFFFFFFFF)
                return ExistentButInvalid;
        }
    }
    return ExistentAndValid;
}

/**
* The function is used to get the validity of omit.
*
* @param: None.
* @retval: the validity of omit.
*/
ValidityOfContent_E VbfHeaderSection::getOmitValidity()
{
    if (omitValidity == NonExistent ||
        omitValidity == ParseError ||
        omitValidity == ExistentButInvalid)
        return omitValidity;

    if (omitValidity == Existent)
    {
        if (omitValidity == ExistentAndValid)
        {
            for (int i = 0; i < omit.size(); i++)
            {
                bool isFound = false;
                for (int j = 0; j < erase.size(); j++)
                {
                    if (erase[j].startAddress == omit[i].startAddress &&
                        erase[j].length == omit[i].length)
                    {
                        isFound = true;
                        break;
                    }
                }
                if (!isFound)
                    return ExistentButInvalid;
            }
        }
    }
    return ExistentAndValid;
}

/**
* The function is used to get the validity of call.
*
* @param: None.
* @retval: the validity of call.
*/
ValidityOfContent_E VbfHeaderSection::getCallValidity()
{
    if (callValidity == ParseError ||
        callValidity == ExistentButInvalid)
        return callValidity;

    //The call entry is mandatory in VBF files with sw part type identifier values equal to SBL or GBL and optional
    //in VBF files with sw part type equal to TEST.
    //For all other identifier values of sw part type, the call entry is not allowed.
    if (swPartType == SBL || swPartType == GBL)
    {
        if (callValidity == NonExistent)
            return ExistentButInvalid;
    }
    else if (swPartType == TEST)
    {
                
    }
    else
    {
        if (callValidity == Existent)
            return ExistentButInvalid;
    }

    if (callValidity == NonExistent)
        return callValidity;
    return ExistentAndValid;
}

/**
* The function is used to get the validity of fileChecksum.
*
* @param: None.
* @retval: the validity of fileChecksum.
*/
ValidityOfContent_E VbfHeaderSection::getFileChecksumValidity()
{
    if (fileChecksumValidity == NonExistent ||
        fileChecksumValidity == ParseError ||
        fileChecksumValidity == ExistentButInvalid)
        return fileChecksumValidity;

    if (fileChecksumValidity == Existent)
    {

    }
    return ExistentAndValid;
}

/**
* The function is used to get the validity of headerSection.
*
* @param: None.
* @retval: the validity of headerSection.
*/
ValidityOfContent_E VbfHeaderSection::getHeaderSectionValidity()
{
    if (headerSectionValidity == NonExistent ||
        headerSectionValidity == ParseError)
        return headerSectionValidity;

    if (headerSectionValidity == Existent)
    {
        descriptionValidity = getDescriptionValidity();
        swPartNumberValidity = getSwPartNumberValidity();
        swPartTypeValidity = getSwPartTypeValidity();
        dataFormatIdentifierValidity = getDataFormatIdentifierValidity();
        frameFormatValidity = getFrameFormatValidity();
        ecuAddressValidity = getEcuAddressValidity();
        eraseValidity = getEraseValidity();
        omitValidity = getOmitValidity();
        callValidity = getCallValidity();
        fileChecksumValidity = getFileChecksumValidity();

        // The following contents are mandatory requirements, must be existent and valid.
        if (swPartNumberValidity != ExistentAndValid ||
            swPartTypeValidity != ExistentAndValid ||
            ecuAddressValidity != ExistentAndValid ||
            frameFormatValidity != ExistentAndValid ||
            fileChecksumValidity != ExistentAndValid)
            return ExistentButInvalid;

        // The following contents are optional, but existent and invalid.
        if (descriptionValidity == ExistentButInvalid ||
            dataFormatIdentifierValidity == ExistentButInvalid ||
            eraseValidity == ExistentButInvalid ||
            omitValidity == ExistentButInvalid ||
            callValidity == ExistentButInvalid)
            return ExistentButInvalid;

        // The following contents should not be parsed error, or the vbf file is invalid.
        if (descriptionValidity == ParseError || swPartNumberValidity == ParseError ||
            swPartTypeValidity == ParseError || dataFormatIdentifierValidity == ParseError ||
            ecuAddressValidity == ParseError || frameFormatValidity == ParseError ||
            eraseValidity == ParseError || omitValidity == ParseError ||
            callValidity == ParseError || fileChecksumValidity == ParseError)
            return ParseError;
    }

    return ExistentAndValid;
}

/** End copyright (c) 2020, Sumarte Technology, All right reserved */
