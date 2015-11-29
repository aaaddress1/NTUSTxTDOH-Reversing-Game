#include "stdafx.h"
#include "windows.h"
#include "cstdlib"
#include "resource.h"

void Welcome()
{
	system("cls");
	char s[1000];
	LoadStringA(NULL, (int)MAKEINTRESOURCE(IDS_STRING1), s, sizeof(s)); 
	printf("%s\n\n\n",s);

	LoadStringA(NULL, (int)MAKEINTRESOURCE(IDS_STRING2), s, sizeof(s)); 
	printf("%s\n\n\n",s);
}

char KeyArray[] = {0x66,0x21,0x72,0x73,0x74,0x5f,0x62,0x6c,0x30,0x30,0x64};
char inputkey[256];
char *RealKeyPtr = KeyArray;
char *InptKeyPtr = inputkey;

void myMain()
{
	for(char choise = 0 ;(choise != 'Y')&&(choise != 'N');scanf("%c", &choise))
	{
		Welcome();
		printf("Do you want to get the key? Y/N\n");	
	}

	if (choise == 'N') 
	{	
		printf("All right, I don't want give you key, bye.\n");
		system("PAUSE");
		return ;
	}	

	printf("You mean YES? But I don't want to give you key :P\n");
	printf("But I can check you key! Input your key: \n");
	scanf("%s" , InptKeyPtr);
	
	while (*RealKeyPtr)
	{
		if (*RealKeyPtr++ ^ *InptKeyPtr++)
		{
			printf("You have incorrect key,bye.\n");
			system("PAUSE");
			return ;
		}
	}
	printf("Your have correct key!\n");
	system("PAUSE");
}

