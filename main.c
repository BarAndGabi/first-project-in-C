#include <stdio.h>
#include "exe.h"

void menuAndChoise( char* cP)
{
	printf("Choose one of the folloeing options : \n");
	printf("S/s- Biggest Matrix Sum\n");
	printf("C/c- Color Game\n");
	printf("B/b- Black and White Game\n");
	printf("E/e- Exit\nYour answer:  ");
	scanf("%c",cP);
	

	
}

int  main()
{
	char choise;
	menuAndChoise(&choise);
		
	switch(choise)
	{
		case 'S' :
			q1();
		break;
		case 'C':
			q2();		
		break;
		case 'B':
			q3();
		break;
		case 's' :
			q1();
		break;
		case 'c':
			q2();		
		break;
		case 'b':
			q3();
		break;
		case 'E':
			printf("\nOkay  , bye \n");
		break;
		default:
			printf("\nTry again, wrong input\n");
		break;

	}
}


