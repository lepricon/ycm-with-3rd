/*
 * Secret Labs' Regular Expression Engine
 *
 * regular expression matching engine
 *
 * Copyright (c) 1997-2001 by Secret Labs AB.  All rights reserved.
 *
 * NOTE: This file is generated by regex.py.  If you need
 * to change anything in here, edit regex.py and run it.
 *
 * 2010-01-16 mrab Re-written
 */

/* Supports Unicode version 10.0.0. */

#define RE_MAGIC 20100116

#include "_regex_unicode.h"

/* Operators. */
#define RE_OP_FAILURE 0
#define RE_OP_SUCCESS 1
#define RE_OP_ANY 2
#define RE_OP_ANY_ALL 3
#define RE_OP_ANY_ALL_REV 4
#define RE_OP_ANY_REV 5
#define RE_OP_ANY_U 6
#define RE_OP_ANY_U_REV 7
#define RE_OP_ATOMIC 8
#define RE_OP_BOUNDARY 9
#define RE_OP_BRANCH 10
#define RE_OP_CALL_REF 11
#define RE_OP_CHARACTER 12
#define RE_OP_CHARACTER_IGN 13
#define RE_OP_CHARACTER_IGN_REV 14
#define RE_OP_CHARACTER_REV 15
#define RE_OP_CONDITIONAL 16
#define RE_OP_DEFAULT_BOUNDARY 17
#define RE_OP_DEFAULT_END_OF_WORD 18
#define RE_OP_DEFAULT_START_OF_WORD 19
#define RE_OP_END 20
#define RE_OP_END_OF_LINE 21
#define RE_OP_END_OF_LINE_U 22
#define RE_OP_END_OF_STRING 23
#define RE_OP_END_OF_STRING_LINE 24
#define RE_OP_END_OF_STRING_LINE_U 25
#define RE_OP_END_OF_WORD 26
#define RE_OP_FUZZY 27
#define RE_OP_GRAPHEME_BOUNDARY 28
#define RE_OP_GREEDY_REPEAT 29
#define RE_OP_GROUP 30
#define RE_OP_GROUP_CALL 31
#define RE_OP_GROUP_EXISTS 32
#define RE_OP_KEEP 33
#define RE_OP_LAZY_REPEAT 34
#define RE_OP_LOOKAROUND 35
#define RE_OP_NEXT 36
#define RE_OP_PROPERTY 37
#define RE_OP_PROPERTY_IGN 38
#define RE_OP_PROPERTY_IGN_REV 39
#define RE_OP_PROPERTY_REV 40
#define RE_OP_PRUNE 41
#define RE_OP_RANGE 42
#define RE_OP_RANGE_IGN 43
#define RE_OP_RANGE_IGN_REV 44
#define RE_OP_RANGE_REV 45
#define RE_OP_REF_GROUP 46
#define RE_OP_REF_GROUP_FLD 47
#define RE_OP_REF_GROUP_FLD_REV 48
#define RE_OP_REF_GROUP_IGN 49
#define RE_OP_REF_GROUP_IGN_REV 50
#define RE_OP_REF_GROUP_REV 51
#define RE_OP_SEARCH_ANCHOR 52
#define RE_OP_SET_DIFF 53
#define RE_OP_SET_DIFF_IGN 54
#define RE_OP_SET_DIFF_IGN_REV 55
#define RE_OP_SET_DIFF_REV 56
#define RE_OP_SET_INTER 57
#define RE_OP_SET_INTER_IGN 58
#define RE_OP_SET_INTER_IGN_REV 59
#define RE_OP_SET_INTER_REV 60
#define RE_OP_SET_SYM_DIFF 61
#define RE_OP_SET_SYM_DIFF_IGN 62
#define RE_OP_SET_SYM_DIFF_IGN_REV 63
#define RE_OP_SET_SYM_DIFF_REV 64
#define RE_OP_SET_UNION 65
#define RE_OP_SET_UNION_IGN 66
#define RE_OP_SET_UNION_IGN_REV 67
#define RE_OP_SET_UNION_REV 68
#define RE_OP_SKIP 69
#define RE_OP_START_OF_LINE 70
#define RE_OP_START_OF_LINE_U 71
#define RE_OP_START_OF_STRING 72
#define RE_OP_START_OF_WORD 73
#define RE_OP_STRING 74
#define RE_OP_STRING_FLD 75
#define RE_OP_STRING_FLD_REV 76
#define RE_OP_STRING_IGN 77
#define RE_OP_STRING_IGN_REV 78
#define RE_OP_STRING_REV 79
#define RE_OP_STRING_SET 80
#define RE_OP_STRING_SET_FLD 81
#define RE_OP_STRING_SET_FLD_REV 82
#define RE_OP_STRING_SET_IGN 83
#define RE_OP_STRING_SET_IGN_REV 84
#define RE_OP_STRING_SET_REV 85
#define RE_OP_BODY_END 86
#define RE_OP_BODY_START 87
#define RE_OP_END_ATOMIC 88
#define RE_OP_END_CONDITIONAL 89
#define RE_OP_END_FUZZY 90
#define RE_OP_END_GREEDY_REPEAT 91
#define RE_OP_END_GROUP 92
#define RE_OP_END_LAZY_REPEAT 93
#define RE_OP_END_LOOKAROUND 94
#define RE_OP_GREEDY_REPEAT_ONE 95
#define RE_OP_GROUP_RETURN 96
#define RE_OP_LAZY_REPEAT_ONE 97
#define RE_OP_MATCH_BODY 98
#define RE_OP_MATCH_TAIL 99
#define RE_OP_START_GROUP 100

char* re_op_text[] = {
    "RE_OP_FAILURE",
    "RE_OP_SUCCESS",
    "RE_OP_ANY",
    "RE_OP_ANY_ALL",
    "RE_OP_ANY_ALL_REV",
    "RE_OP_ANY_REV",
    "RE_OP_ANY_U",
    "RE_OP_ANY_U_REV",
    "RE_OP_ATOMIC",
    "RE_OP_BOUNDARY",
    "RE_OP_BRANCH",
    "RE_OP_CALL_REF",
    "RE_OP_CHARACTER",
    "RE_OP_CHARACTER_IGN",
    "RE_OP_CHARACTER_IGN_REV",
    "RE_OP_CHARACTER_REV",
    "RE_OP_CONDITIONAL",
    "RE_OP_DEFAULT_BOUNDARY",
    "RE_OP_DEFAULT_END_OF_WORD",
    "RE_OP_DEFAULT_START_OF_WORD",
    "RE_OP_END",
    "RE_OP_END_OF_LINE",
    "RE_OP_END_OF_LINE_U",
    "RE_OP_END_OF_STRING",
    "RE_OP_END_OF_STRING_LINE",
    "RE_OP_END_OF_STRING_LINE_U",
    "RE_OP_END_OF_WORD",
    "RE_OP_FUZZY",
    "RE_OP_GRAPHEME_BOUNDARY",
    "RE_OP_GREEDY_REPEAT",
    "RE_OP_GROUP",
    "RE_OP_GROUP_CALL",
    "RE_OP_GROUP_EXISTS",
    "RE_OP_KEEP",
    "RE_OP_LAZY_REPEAT",
    "RE_OP_LOOKAROUND",
    "RE_OP_NEXT",
    "RE_OP_PROPERTY",
    "RE_OP_PROPERTY_IGN",
    "RE_OP_PROPERTY_IGN_REV",
    "RE_OP_PROPERTY_REV",
    "RE_OP_PRUNE",
    "RE_OP_RANGE",
    "RE_OP_RANGE_IGN",
    "RE_OP_RANGE_IGN_REV",
    "RE_OP_RANGE_REV",
    "RE_OP_REF_GROUP",
    "RE_OP_REF_GROUP_FLD",
    "RE_OP_REF_GROUP_FLD_REV",
    "RE_OP_REF_GROUP_IGN",
    "RE_OP_REF_GROUP_IGN_REV",
    "RE_OP_REF_GROUP_REV",
    "RE_OP_SEARCH_ANCHOR",
    "RE_OP_SET_DIFF",
    "RE_OP_SET_DIFF_IGN",
    "RE_OP_SET_DIFF_IGN_REV",
    "RE_OP_SET_DIFF_REV",
    "RE_OP_SET_INTER",
    "RE_OP_SET_INTER_IGN",
    "RE_OP_SET_INTER_IGN_REV",
    "RE_OP_SET_INTER_REV",
    "RE_OP_SET_SYM_DIFF",
    "RE_OP_SET_SYM_DIFF_IGN",
    "RE_OP_SET_SYM_DIFF_IGN_REV",
    "RE_OP_SET_SYM_DIFF_REV",
    "RE_OP_SET_UNION",
    "RE_OP_SET_UNION_IGN",
    "RE_OP_SET_UNION_IGN_REV",
    "RE_OP_SET_UNION_REV",
    "RE_OP_SKIP",
    "RE_OP_START_OF_LINE",
    "RE_OP_START_OF_LINE_U",
    "RE_OP_START_OF_STRING",
    "RE_OP_START_OF_WORD",
    "RE_OP_STRING",
    "RE_OP_STRING_FLD",
    "RE_OP_STRING_FLD_REV",
    "RE_OP_STRING_IGN",
    "RE_OP_STRING_IGN_REV",
    "RE_OP_STRING_REV",
    "RE_OP_STRING_SET",
    "RE_OP_STRING_SET_FLD",
    "RE_OP_STRING_SET_FLD_REV",
    "RE_OP_STRING_SET_IGN",
    "RE_OP_STRING_SET_IGN_REV",
    "RE_OP_STRING_SET_REV",
    "RE_OP_BODY_END",
    "RE_OP_BODY_START",
    "RE_OP_END_ATOMIC",
    "RE_OP_END_CONDITIONAL",
    "RE_OP_END_FUZZY",
    "RE_OP_END_GREEDY_REPEAT",
    "RE_OP_END_GROUP",
    "RE_OP_END_LAZY_REPEAT",
    "RE_OP_END_LOOKAROUND",
    "RE_OP_GREEDY_REPEAT_ONE",
    "RE_OP_GROUP_RETURN",
    "RE_OP_LAZY_REPEAT_ONE",
    "RE_OP_MATCH_BODY",
    "RE_OP_MATCH_TAIL",
    "RE_OP_START_GROUP",
};

#define RE_FLAG_ASCII 0x80
#define RE_FLAG_BESTMATCH 0x1000
#define RE_FLAG_DEBUG 0x200
#define RE_FLAG_DOTALL 0x10
#define RE_FLAG_ENHANCEMATCH 0x8000
#define RE_FLAG_FULLCASE 0x4000
#define RE_FLAG_IGNORECASE 0x2
#define RE_FLAG_LOCALE 0x4
#define RE_FLAG_MULTILINE 0x8
#define RE_FLAG_POSIX 0x10000
#define RE_FLAG_REVERSE 0x400
#define RE_FLAG_TEMPLATE 0x1
#define RE_FLAG_UNICODE 0x20
#define RE_FLAG_VERBOSE 0x40
#define RE_FLAG_VERSION0 0x2000
#define RE_FLAG_VERSION1 0x100
#define RE_FLAG_WORD 0x800