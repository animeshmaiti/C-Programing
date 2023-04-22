#include<stdio.h>
#include<math.h> //for sqrt function
int a,b,c,d,e;
// float *sum,*avg;
void funcSum(float *sum)
{
   *sum = a+b+c+d+e;
}
void funcAvg(float *sum,float *avg){
    *sum = a+b+c+d+e;
    // funcSum();
    *avg = *sum/5.0;
}
void funcDev(float *sum,float *avg,float *std_dev){
    *sum = a+b+c+d+e;
    *avg = *sum/5.0;
    *std_dev = sqrt (((a-*avg)*(a-*avg))+((b-*avg)*(b-*avg))+((c-*avg)*(c-*avg))+((d-*avg)*(d-*avg))+((e-*avg)*(e-*avg))/5.0);
}
void main()
{
    float sum, avg, std_dev;

    printf("Enter 5 numbers: ");
    scanf("%d%d%d%d%d", &a,&b,&c,&d,&e);
    funcSum(&sum);
    funcAvg(&sum,&avg);
    funcDev(&sum,&avg,&std_dev);
    printf("The Sum: %f\n", sum);
    printf("The Average: %f\n", avg);
    printf("The Standard Deviation: %f", std_dev);

}
