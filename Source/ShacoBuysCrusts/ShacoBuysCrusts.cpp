#include "stdafx.h"
#include "windows.h"
#include "cstdlib"
#include "resource.h"
#include "time.h"

#define KEYVALUE 59842 //KEY: KEY=sexy&!know!t


void Welcome()
{
	system("cls");
	char s[1500];
	LoadStringA(NULL, (int)MAKEINTRESOURCE(IDS_STRING1), s, sizeof(s)); 
	printf("%s\n\n\n",s);
	/*LoadStringA(NULL, (int)MAKEINTRESOURCE(IDS_STRING2), TrueKey, sizeof(TrueKey)); */
}

void PlayMusic(int kind)
{
	printf("Play Music now! Listening...\n");
	if (kind == 1)//BEE
	{
		    int row,col;
    int voice[16][4]={{700,600,600,0},{650,550,550,0},{500,550,600,650},{700,700,700,0},
                    {700,600,600,0},{650,550,550,0},{500,650,700,700},{600,0,0,0},
                    {550,550,550,550},{550,600,650,0},{600,600,600,600},{600,650,700,0},
                    {700,600,600,0},{650,550,550,0},{500,600,700,700},{500,0,0,0}} ; 
    int tempo[16][4]={{1,1,2,0},{1,1,2,0},{1,1,1,1},{1,1,2,0},
                    {1,1,2,0},{1,1,2,0},{1,1,1,1},{4,0,0,0},
                    {1,1,1,1},{1,1,2,0},{1,1,1,1},{1,1,2,0},
                    {1,1,2,0},{1,1,2,0},{1,1,1,1},{4,0,0,0}}; 
    for(row=0; row<16; row++) for(col=0; col<4; col++) Beep(voice[row][col],tempo[row][col]*250);       
	}
	else if (kind == 2)//2Tiger
	{
		int freq[]={523,587,659,523,523,587,659,523,
		659,698,784,784,659,698,784,784,
		784,880,784,698,659,523,
		784,880,784,698,659,523,
		523,392,523,523,392,523};
		int duration[]={500,500,500,500,500,500,500,500,
		500,500,500,500,500,500,500,500,
		250,250,250,250,500,500,
		250,250,250,250,500,500,
		500,500,1000,500,500,1000};
		for(int i=0;i<34;i++)	Beep(freq[i], duration[i]);

	}
	else
	{
		printf("hmm... I don't know what need to be palyed!\n");
		return;
	}
	printf("The music sound good,right?\n");

}

unsigned int Money = 10;
char *inputKey = new char[100];
bool BuyOver = false;

void GetKeyValue(char* key)
{
	int sum = 0,extr = 0;
	for(int i =0;key[i];i++) 
	{
		sum += key[i]* i + extr;
		extr += (sum%10) + (sum/10);
	}
	//KEY=sexy&!know!t
	if (sum == KEYVALUE)
	{
		int val = *(int*)(key+0) ^ 0x3d59454b;
			val +=*(int*)(key+4) ^ 0x79786573;
			val +=*(int*)(key+8) ^ 0x6E6B2126;
			val +=*(key+0x0C) ^ 'o';
			val +=*(key+0x0E) ^ '!';
		if (val)
		{
			printf("This key invoke system error....1@I!$@RH\n");
			return;
		}
		Money += sum;
		printf(",and get %d $\nNow you have %d $!!! WoW!!!\n", sum, Money);
		BuyOver = true;
	}
	else if (sum < 10000)
	{
		Money += sum;
		printf(",you get change %d $ :D\nNow you have %d $\n", sum, Money);
		BuyOver = true;
	}
	else printf("\nhmm...something wrong! get money fail. OTZ\n");
}


int main(int argc, char ** argv)
{
	for(char ch = 0; ch != '6' ;)
	{
		Welcome();
		printf("SHACO BUYS CRUSTs!\n");
		printf("SHACO goes to a shop and wants to buy crusts.\n");
		printf("SHACO Story Link: www.youtube.com/watch?v=PVc8sMb6piU\n\n");
		printf("+*************** Welcome To Teemo's Shop ***************\n");
		printf("+Now you have money: %d $\n" ,  Money);
		printf("+Choose your action:\n");
		if (!BuyOver) printf("+\t[1] Input the key to get money.(Just one chance)\t\n");
		printf("+\t[2] Play music \" Bee \"\t\t\t... $1\n");
		printf("+\t[3] Play music \" Two Tiger \"\t\t... $3\n");
		printf("+\t[4] Make a wish \t\t\t... $10\n");
		printf("+\t[5] Buy a crust \t\t\t... $%d\n", KEYVALUE);
		printf("+\t[6] Exit.\n");
		printf("+*******************************************************\n");
		printf("What do you want to do? ");
		scanf(" %c", &ch); 
		
		if ((ch == '1') && (!BuyOver)) 
		{
			printf("KEY: ");
			scanf("%s" , inputKey);
			printf("You input the key \" %s \"", inputKey);
			if (strlen(inputKey) > 16) 
				printf("Your key is too long!\n");
			else 
				GetKeyValue(inputKey);
		}
		else if (ch == '2' || ch == '3') 
		{
			int NeedCost = (ch == '2'? 1:3);
			if (Money < NeedCost) printf("Money not enough.. :(\n");
			else
			{
				Money -= NeedCost;
				PlayMusic(ch == '2' ? 1:2);
			}
		}
		else if (ch == '4')
		{
			if (Money < 10)	printf("Money not enough!\n");
			else
			{
				Money -= 10;
				printf("Your wish will not come true =P\n");
				printf("But you send a 10$ coin to wishing well,\n");
				printf("Now you have money: %d $\n", Money);
			}	
		}
		else if (ch == '5')
		{
			if (Money == KEYVALUE) 
			{
				printf("Good! You got it.\nGame Over!\n");			
				system("PAUSE");
				return 0;
			}
			else printf("Money not enough or something wrong!\n");
		}
		system("PAUSE");
	}
	return 0;
}

