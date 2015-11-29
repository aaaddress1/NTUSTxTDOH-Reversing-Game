#include "stdafx.h"
#include "windows.h"
#include "cstdlib"
#include "resource.h"

void Welcome()
{
	system("cls");
	char s[1500];
	LoadStringA(NULL, (int)MAKEINTRESOURCE(IDS_STRING1), s, sizeof(s)); 
	printf("%s\n",s);
}

int MyMain()
{
	Welcome();
	unsigned long checksum[2] = {-1,-1};
	char KEY[8];
	printf("REVO WOLF!\n");
    printf("Give me your key and overflooooooooooow it,\nI'll Check it.\n");
	printf("Looking for keys? find those on STACK OVERFLOW\nTell me your Key: ");
	scanf("%s", KEY);
	if (*(unsigned int*)(KEY+0) == 0x7265766f)
	{
		if (*(unsigned int*)(KEY+4) == 0x776f6c66)
		{
			_asm
			{
				xor ecx,ecx
				mov eax,[checksum+00]
				xor eax,0x3D504952
				add ecx,eax

				mov eax,[checksum+04]
				xor eax,0x776f6f6f
				add ecx,eax
				
				test ecx,ecx
				jnz levelCurrSub
			}
			printf("WoW! Your key is correct!\n");
		}
		else printf("Your key must be like an animal....like wolf?\n");
	}
	else printf("Your key is not revo's?\n");

levelCurrSub:
	system("PAUSE");
	return 0;
}

