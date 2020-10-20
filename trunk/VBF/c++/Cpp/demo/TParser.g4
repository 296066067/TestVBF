parser grammar TParser;

options {
	tokenVocab = TLexer;
	language=Cpp;
}

/*
 * Parser Rules
 */

/**
 * The root rule for vbf file.
 */
database
	:	versionSection headerSection
	;

/**
 * The version specification
 */
versionSection
	:	'vbf_version' '=' Reals ';'
	;

/**
 * The header specification
 */
headerSection
	:	'header' '{'
		(description)?
		swPartNumber
		swPartType
		(dataFormatIdentifier)?
		ecuAddress
		frameFormat
		(erase)?
		(omit)?
		(call)?
		fileChecksum
		'}'
	;

/**
 * The description specification
 */
description
	:	'description' '=' 
		'{'
		String (',' String)*
		'}'
		';'
	;

/**
 * The swPartNumber specification
 */
swPartNumber
	:	'sw_part_number' '=' 
		(String | ('{' String ',' String '}'))
		';'
	;

/**
 * The swPartType specification
 */
swPartType
	:	'sw_part_type' '=' 
		('CARCFG' | 'CUSTOM' | 'DATA' |
		'EXE' | 'GBL' | 'SBL' | 'SIGCFG' | 'TEST')
		';'
	;

/**
 * The dataFormatIdentifier specification
 */
dataFormatIdentifier
	:	'data_format_identifier' '=' 
		(Hexadecimal | Binary | Decimal)
		';'
	;

/**
 * The ecuAddress specification
 */
ecuAddress
	:	'ecu_address' '=' 
		(
		(Hexadecimal) |
		('{'(Hexadecimal) ',' (Hexadecimal) ',' (Hexadecimal) '}')
		)
		';'
	;

/**
 * The frameFormat specification
 */
frameFormat
	:	'frame_format' '=' 
		('CAN_STANDARD' | 'CAN_EXTENDED')
		';'
	;

/**
 * The erase specification
 */
erase
	:	'erase' '=' 
		'{'
		('{' (Hexadecimal) ',' (Hexadecimal) '}') 
		(',' '{' (Hexadecimal) ',' (Hexadecimal) '}')*
		'}'
		';'
	;

/**
 * The omit specification
 */
omit
	:	'omit' '=' 
		'{'
		('{' (Hexadecimal) ',' (Hexadecimal) '}') 
		(',' '{' (Hexadecimal) ',' (Hexadecimal) '}')*
		'}'
		';'
	;

/**
 * The call specification
 */
call
	:	'call' '=' 
		(Hexadecimal)
		';'
	;

/**
 * The fileChecksum specification
 */
fileChecksum
	:	'file_checksum' '=' 
		(Hexadecimal)
		';'
	;