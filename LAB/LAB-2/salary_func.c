#include <stdio.h>
// Function to calculate the
// salary of the person
struct employee
{
    char name[50], gender[10], designation[10], depertment[10];
    float basic, hra, da, gross;
};
void store_details(struct employee *e)
{
        printf("enter a name, gender, designation, depertment\n");
        scanf("%s %s %s %s", &e->name, &e->gender, &e->designation, &e->depertment);
        printf("enter your basic salary\n");
        scanf("%f", &e->basic);
        e->hra = e->basic * 0.25;
        e->da = e->basic * 0.75;
        e->gross = e->hra + e->da + e->basic;
    
}
void print_details(struct employee *e){
    printf("name  gender  designation  depertment  hra  da  gross\n");
    printf("%s\t%s\t  %s\t  %s\t  %.2f  %.2f  %.2f\n ", e->name, e->gender, e->designation, e->depertment, e->hra, e->da, e->gross);
};

int main()
{
    int n, i;
    printf("enter employee number\n");
    scanf("%d", &n);
    struct employee e[n];
    for ( i = 0; i < n; i++)
    {
        store_details(&e[i]);
    }
    printf("enter the index of employee\n");
    scanf("%d", &i);
    print_details(&e[i]);
}

