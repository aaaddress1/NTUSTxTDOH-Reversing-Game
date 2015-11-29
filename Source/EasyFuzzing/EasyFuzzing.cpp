#include "stdafx.h"
#include "windows.h"
#include "cstdlib"
//#include "resource.h"

char KeyArray[] = {0x66,0x21,0x72,0x73,0x74,0x5f,0x62,0x6c,0x30,0x30,0x64};
char inputkey[256];
char *RealKeyPtr = KeyArray;
char *InptKeyPtr = inputkey;

void myMain()
{
	char Buffer[10] ;
	printf("Input your key: ");
	scanf("%10s", Buffer);
	bool Pass = false;
	
	if (Buffer[0] >> 1 << 1 == Buffer[0] - 1)
		if (Buffer[1] == Buffer[0] + 3)
			if (Buffer[2] == Buffer[1] + 14)
				if (!Buffer[3]) Pass = true;
	
	printf(Pass ? "Pass!\n" : "Fail!\n");
	system("PAUSE");
}

