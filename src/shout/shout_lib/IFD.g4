/*
 * Mantra ASCII .IFD file format grammer.
 */

grammar IFD;

file: line*;

line: version | declare | setenv | start | end | property | detail | image | geomerty | time | raytrace | quit | COMMENT;

setenv
   : 'setenv' VAR_NAME '=' VALUE
   ;

version
   : 'ray_version' VEX_VERSION
   ;

declare
   : 'ray_declare' OBJECT TYPE VAR_NAME VALUE
   ;

start
   : 'ray_start' OBJECT
   ;

end
   : 'ray_end'
   ;

detail
   : 'ray_detail' '-T'? OBJPATH (STREAM | FILENAME)
   ;

detail_instance
   : 'ray_detail' (('-v' VALUE) | ('-V' VALUE VALUE))? OBJPATH OBJPATH
   ;

property
   : 'ray_property' OBJECT VAR_NAME (STREAM | VALUE)
   ;

image
   : 'ray_image' VALUE VALUE?
   ;

geomerty
   : 'ray_geometry' VALUE
   ;

time
   : 'ray_time' VALUE
   ;

raytrace
   : 'ray_raytrace'
   ;

quit
   : 'ray_quit'
   ;

PATH
   /*: [a-zA-Z0-9/] [a-zA-Z0-9/]* */
   : STRING
   ;

OBJPATH
   /*: '/' [a-zA-Z] [a-zA-Z0-9/]* */
   : STRING
   ;

FILENAME
   : PATH
   ;

COMMENT
   : '#' ~( '\r' | '\n' )*
   ;

STREAM
   /*: 'stdin' .*? 'ray_end'*/
   : 'stdin' .*? 'ray_end'
   ;

TYPE
   : 'float' | 'bool' | 'int' | 'vector2' | 'vector3' | 'vector4' | 'matrix3' | 'matrix4' | 'string'
   ;

OBJECT
   : 'global' | 'material' | 'geo' | 'geomerty' | 'segment' | 'camera' | 'light' | 'fog' | 'object' | 'instance' | 'plane' | 'image' | 'renderer'
   ;

VEX_VERSION
   : 'VEX' INT ('.' INT)*
   ;

VAR_NAME
   : VALID_ID_START VALID_ID_CHAR*
   ;

VALUE
   : INTEGER | NUMBER | STRING
   ;

INTEGER
   : INT
   ;

NUMBER
   : '-'? INT '.' [0-9] + EXP? | '-'? INT EXP | '-'? INT
   ;

STRING
   : QUOTED | NO_QUOTED
   ;

NO_QUOTED
   : ~(' ' | '\'' | '"' | '\t' | '\r' | '\n')+
   ;

QUOTED
   : '"' (NO_QUOTED | ' ')* '"'
   ;

CHARS
   : LETTER+
   ;

fragment VALID_ID_START
   : LETTER | '_'
   ;

fragment VALID_ID_CHAR
   : VALID_ID_START | ('0' .. '9') | '-' | '+' | ':' | '.'
   ;

fragment LETTER
   : [a-zA-Z]
   ;

fragment INT
   : '0' | [1-9] [0-9]*
   ;

fragment EXP
   : [Ee] [+\-]? INT
   ;

BYTE 
   : '\u0000'..'\u00FF' 
   ;

BGEO
   : '\u0000' 'NSJb' BYTE*
   ;

WS: [ \n\t\r]+
   -> skip;