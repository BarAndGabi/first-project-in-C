#include <stdio.h>
#include "exe.h"

void menuAndChoise( char* cP)
{
	printf("Choose one of the folloeing options : \n");
	printf("S/s- Biggest Matrix Sum\n");
	printf("C/c- Color Game\n");
	printf("B/b- Black and White Game\n");
	printf("E/e- Exit");
	scanf("%c",cP);
	

	
}

int  main()
{
	char choise;
	menuAndChoise(&choise);
	switch(choise)
	{
		case 'S' :
		break;
		case 'C':
		break;
		case 'B':
		break;
		case 'E':
		break;
		default:
		break;

	}
}


