#include<stdio.h>

int main()
{
    int i=0;
cicle:
    printf("%d\n",i);
    i++;
    if(i<101)
        goto cicle;

    return 0;
}