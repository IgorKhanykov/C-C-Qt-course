#include<stdio.h>
#define MAX_SIZE 100000

int main()
{
    FILE * pFile;
    char ch;
    int i2;

    pFile=open("text.txt","rt");
    if(pFile==NULL)
    {
        printf("Error opening file!");
        fclose(pFile);
    }
    else
    {
        while(!feof(pFile) && i2<MAX_SIZE)
        { 
            ch=fgetc(pFile);
            printf("%c",ch);
            i2++;
        }
        flose(pFile);
        printf("\nTotal bytes in chars: %d\n", i2);
    }

    return 0;
}