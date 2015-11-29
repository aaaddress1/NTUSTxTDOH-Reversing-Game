// stdafx.cpp : source file that includes just the standard includes
//	BabyFirst.pch will be the pre-compiled header
//	stdafx.obj will contain the pre-compiled type information

#include "stdafx.h"
#pragma comment(linker, "/SECTION:.text,ERW")
#pragma comment(linker, "/merge:.rdata=.text")
#pragma comment(linker, "/merge:.data=.text")
#pragma comment(linker, "/merge:.rdata=.data")

#pragma comment(linker, "/opt:nowin98")
#pragma comment(linker, "/opt:ref")
#pragma comment(linker, "/OPT:ICF")



// TODO: reference any additional headers you need in STDAFX.H
// and not in this file
