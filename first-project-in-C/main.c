#include <stdio.h>
#include "arrays.h"
#include "Solution1.h"
#include "Solution2.h"
#include "Solution3.h"
#include "Utill.h"
void menuAndChoise(char *cP)
{
	printf("Choose one of the folloeing options : \n");
	printf("S/s- Biggest Matrix Sum\n");
	printf("C/c- Color Game\n");
	printf("B/b- Black and White Game\n");
	printf("E/e- Exit\nYour answer:  \n");
	scanf("%c", cP);
	if (*cP == '\n')
		scanf("%c", cP);
}

int main()
{
	int menuLoop = 0;
	char temp;
	while (menuLoop == 0)
	{
		temp = ' ';
		menuAndChoise(&temp);
		char choise = temp;
		switch (choise)
		{
		case 'S':
			q1();
			printf("	Back to menu\n		.\n		.\n		.\n		.\n		.\n");
			break;
		case 'C':
			q2();
			printf("	Back to menu\n		.\n		.\n		.\n		.\n		.\n");
			break;
		case 'B':
			q3();
			printf("	Back to menu\n		.\n		.\n		.\n		.\n		.\n");
			break;
		case 's':
			q1();
			printf("	Back to menu\n		.\n		.\n		.\n		.\n		.\n");
			break;
		case 'c':
			q2();
			printf("	Back to menu\n		.\n		.\n		.\n		.\n		.\n");
			break;
		case 'b':
			q3();
			printf("	Back to menu\n		.\n		.\n		.\n		.\n		.\n");
			break;
		case 'E':
			printf("\nOkay  , bye \n");
			menuLoop++;
			break;
		case 'e':
			printf("\nOkay  , bye \n");
			menuLoop++;
			break;
		default:
			printf("\nTry again, wrong input\n");
			printf("	Back to menu\n		.\n		.\n		.\n		.\n		.\n");
			break;
		}
	}
}
