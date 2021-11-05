#include "exe.h"

int  main()
{
	char choise;
	menuAndChoise(&choise);
	switch(choise)
	{
		case 'S','s':
		break;
		case 'C','c':
		break;
		case 'B','B':
		break;
		case 'E','e':
		break;

	}

	
}

void menuAndChoise( char* cP)
{
	printf("Choose one of the folloeing options : \nS/s- Biggest Matrix Sum\nC/c- Color Game\nB/b- Black and White Game\nE/e- Exit");
	scanf("%c",cP);
	if(
}
