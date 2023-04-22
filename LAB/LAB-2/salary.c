#include <stdio.h>
// Function to calculate the
// salary of the person
struct employee
{
    char name[50], gender[10], designation[10], depertment[10];
    float basic, hra, da, gross;
};

int main()
{
    printf("Arnab pal 213099\n");
    int n, i;
    printf("enter employee number\n");
    scanf("%d", &n);
    struct employee e[n];
    for ( i = 0; i < n; i++)
    {
        printf("enter a name, gender, designation, depertment\n");
        scanf("%s %s %s %s", &e[i].name, &e[i].gender, &e[i].designation, &e[i].depertment);
        printf("enter your basic salary\n");
        scanf("%f", &e->basic);
        e[i].hra = e[i].basic * 0.25;
        e[i].da = e[i].basic * 0.75;
        e[i].gross = e[i].hra + e[i].da + e[i].basic;
    }
    printf("enter the index of employee\n");
    scanf("%d", &i);
    printf("name  gender  designation  depertment  hra  da  gross\n");
    printf("%s\t%s\t  %s\t  %s\t  %.2f  %.2f  %.2f\n ", e[i].name, e[i].gender, e[i].designation, e[i].depertment, e[i].hra, e[i].da, e[i].gross);
    
}
