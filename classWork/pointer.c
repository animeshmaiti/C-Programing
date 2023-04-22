#include <stdio.h>
int main()
{
    void *pnum;
	// int num;
    char ch = 'a';
	// pnum = &num;
    pnum= &ch;
	
	// printf("\n The number that was entered is : %d", num+1);
	// printf("\n The number that was entered is : %d", &num);
	// printf("\n The number that was entered is : %d", &num+2);
	printf("\n The number that was entered is : %d", pnum);
	printf("\n The number that was entered is : %d", pnum+1);
	// printf("\n The number that was entered is : %d", *pnum+2);
	return 0;
}