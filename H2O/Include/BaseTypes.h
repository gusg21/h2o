//
// Created by Angus Goucher on 10/13/2024.
//

#pragma once

#ifdef _MSC_VER
typedef unsigned char U8;
typedef char I8;
typedef unsigned U16;
typedef int I16;
typedef unsigned long int U32;
typedef long int I32;
typedef unsigned long long U64;
typedef long long I64;

typedef U64 INTPTR;
typedef I8 CHAR;
// TODO: Determine how multi-byte strings should be represented
// typedef I8 WIDECHAR;
#else
#error Make sure to define appropriate integral sizes for new platforms!
#endif
