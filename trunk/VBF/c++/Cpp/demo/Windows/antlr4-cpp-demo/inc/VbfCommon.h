/**
* Copyright (c) 2020, Sumarte Technology, All right reserved
*
* @file: VbfCommon.h
* The file is used to describe the common definition of vbf file.
*
* @date 07/10/2020
* @author chencheng@smarte.com
*/

#ifndef _VBFCOMMON_H_
#define _VBFCOMMON_H_

#include <stdint.h>
#include <string>
#include <deque>
#include <iostream>
/**
 * The available value of sw part type.
*/
typedef enum _SwPartType_E
{
	InvalidSwPartType,
	CARCFG,
	CUSTOM,
	DATA,
	EXE,
	GBL,
	SBL,
	SIGCFG,
	TEST

} SwPartType_E;

/**
 * The available value of frame format.
*/
typedef enum _FrameFormat_E
{
	InvalidFrameFormat,
	CAN_STANDARD,
	CAN_EXTENDED

} FrameFormat_E;

/**
 * The available value of content validity.
*/
typedef enum _ValidityOfContent_E
{
	NonExistent,
	Existent,
	ParseError,
	ExistentAndValid,
	ExistentButInvalid

} ValidityOfContent_E;

/**
 * The defination of block.
*/
typedef struct _Block_T
{
	uint32_t startAddress;
	uint32_t length;
} Block_T;

#endif // !_VBFCOMMON_H_

/** End copyright (c) 2020, Sumarte Technology, All right reserved */
