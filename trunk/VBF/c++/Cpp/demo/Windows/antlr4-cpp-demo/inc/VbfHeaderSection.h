/**
* Copyright (c) 2020, Sumarte Technology, All right reserved
*
* @file: VbfHeaderSection.h
* The file is used to describe the definition of vbf file header section.
*
* @date 07/10/2020
* @author chencheng@smarte.com
*/

#ifndef _VBFHEADERSECTION_H_
#define _VBFHEADERSECTION_H_

#include "VbfCommon.h"

/**
* The class is used to describe the header section of the vbf file.
*/
class VbfHeaderSection
{
public:
	VbfHeaderSection();
	~VbfHeaderSection();

public:
	std::deque<std::string> description;
	ValidityOfContent_E descriptionValidity;

	std::deque<std::string> swPartNumber;
	ValidityOfContent_E swPartNumberValidity;

	SwPartType_E swPartType;
	ValidityOfContent_E swPartTypeValidity;

	uint16_t dataFormatIdentifier;
	ValidityOfContent_E dataFormatIdentifierValidity;

	std::deque<uint16_t> ecuAddress;
	ValidityOfContent_E ecuAddressValidity;

	FrameFormat_E frameFormat;
	ValidityOfContent_E frameFormatValidity;

	std::deque<Block_T> erase;
	ValidityOfContent_E eraseValidity;

	std::deque<Block_T> omit;
	ValidityOfContent_E omitValidity;

	uint32_t call;
	ValidityOfContent_E callValidity;

	uint32_t fileChecksum;
	ValidityOfContent_E fileChecksumValidity;

	ValidityOfContent_E headerSectionValidity;

public:
	ValidityOfContent_E getDescriptionValidity();
	ValidityOfContent_E getSwPartNumberValidity();
	ValidityOfContent_E getSwPartTypeValidity();
	ValidityOfContent_E getDataFormatIdentifierValidity();
	ValidityOfContent_E getEcuAddressValidity();
	ValidityOfContent_E getFrameFormatValidity();
	ValidityOfContent_E getEraseValidity();
	ValidityOfContent_E getOmitValidity();
	ValidityOfContent_E getCallValidity();
	ValidityOfContent_E getFileChecksumValidity();
	ValidityOfContent_E getHeaderSectionValidity();
};

#endif // !_VBFHEADERSECTION_H_

/** End copyright (c) 2020, Sumarte Technology, All right reserved */
