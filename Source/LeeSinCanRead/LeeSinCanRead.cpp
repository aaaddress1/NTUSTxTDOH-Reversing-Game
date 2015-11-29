#include "stdafx.h"
#include "windows.h"
#include "cstdlib"
#include "resource.h"
char TrueKey[25];
void Welcome()
{
	system("cls");
	char s[1000];
	LoadStringA(NULL, (int)MAKEINTRESOURCE(IDS_STRING1), s, sizeof(s)); 
	printf("%s\n\n\n",s);
	LoadStringA(NULL, (int)MAKEINTRESOURCE(IDS_STRING2), TrueKey, sizeof(TrueKey)); 
}

void PrintKey(bool b)
{
	if (!b) return;	
	printf("hmm... Key is ...{%s}?\n", TrueKey);
	printf("OOPS! I blundered out the secret!!\n");
	exit(0);
}


int main(int argc, char ** argv)
{
	char InputData[10];
	Welcome();
	if (!--argc)
	{
		printf("LEE SIN CAN READ WORDS!\n");
		printf("you can say something or give a text file to LEE SIN,\nand he will repeat it again.\n");
		printf("PS: LEE SIN accidentally blundered out the key.\n");
		printf("\nME: ");
		scanf("%s", InputData);
	}
	else
	{
		FILE* fp = fopen(argv[1],"r"); 
		if (!fp) 
		{
			printf("LEE SIN: I cannot read this text file. soory! :(\n");
			system("PAUSE");
			return 0;
		}
		fscanf(fp,"%s",&InputData);
	}
	printf("LEE SIN: Ok,I can read it! There are %d words.\n",strlen(InputData));
	printf("LEE SIN: You said \" %s \" ?\n",InputData);
	PrintKey(false);
	system("PAUSE");
	return 0;
}

