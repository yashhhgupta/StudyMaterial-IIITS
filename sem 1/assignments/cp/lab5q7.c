//Print day of week name using switch case.
#include <stdio.h>
int main()
{
	int n;
	printf("enter a number between 1 to 7\n");
	scanf("%d",&n);
	switch(n)
	{
	case 1:
		printf("sunday");
		break;
	case 2:
		printf("monday");
		break;
	case 3:
		printf("tuesday");
		break;
	case 4:
		printf("wednesday");
		break;
	case 5:
		printf("thursday");
		break;
	case 6:
		printf("friday");
		break;
	case 7:
		printf("saturday");
		break;
	default:
		printf("enter a valid number");
		break;
	}
	return 0;	
}
