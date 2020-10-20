lexer grammar TLexer;

options { language=Cpp; }

/*
 * Lexer Rules
 */

/** 
 * "Any string of alphabetic ([a-zA-Z\200-\377]) characters, underscores
 *  ('_') or digits ([0-9]), not beginning with a digit"
 */
//ID
//	:	Digit'.'Digit
//	;

/** 
 * "any double-quoted string ("...") possibly containing escaped quotes"
 */
String
	:	'"' (~'"')* '"' 
	;

Digit
	:	[0-9]
	;

Letter
	:	[a-zA-Z\u0080-\u00FF_]
	;

Hexadecimal
	:	('0x' | '0X')(Digit | Letter)+
	;

Binary
	:	('0b' | '0B')([01])+
	;

Decimal
	:	(Digit)+
	;

Reals
	:	Digit+ '.' Digit+
	;

Whitespace
	:	[ \t\n\r]+ -> skip 
	;

/**
 * The C++ style comment.
 */
CPlusStyleComment
	:	'//'.*?'\n' -> skip
	;

/**
 * The C style comment.
 */
CStyleComment
	:	'/*'.*?'*/' -> skip
	;
	
	
Vbf_version : 'vbf_version';

Is : '=';

Semicolon : ';';

Header : 'header';

LeftBrace : '{';

RightBrace : '}';

Description : 'description';

SwPartNumber : 'sw_part_number';

SwPartType : 'sw_part_type';

Carcfg : 'CARCFG';

Custom : 'CUSTOM';

Data : 'DATA';

Exe : 'EXE';

Gbl : 'GBL';

Sbl : 'SBL';

Sigcfg : 'SIGCFG';

Test : 'TEST';

DataFormatIdentifier : 'data_format_identifier';

EcuAddress : 'ecu_address';

FrameFormat : 'frame_format';

CanStandard : 'CAN_STANDARD';

CanExtended : 'CAN_EXTENDED';

Erase : 'erase';

Omit : 'omit';

Call : 'call';

FileChecksum : 'file_checksum';

Comma : ',';
