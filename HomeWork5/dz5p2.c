#include<stdio.h>
#define MAX_SIZE 10000
int main(){

    // WORK with FILES
    int iaArrayOfSymbols[255]={0};      //array of symbols
    char str[MAX_SIZE];             //string of chars
    char cSymbol;                   // symbol
    int iStrSize=0;                 //length of a string in fact.
    FILE *pFile;                    // file pointer
    int i=0;

    // read file
    pFile=fopen("t2.txt","rt");
    if (pFile==NULL)
    {
        printf("Error opening file!");
        fclose(pFile);
    }
    if (pFile)
    {

            while ((cSymbol = getc(pFile)) != EOF)
            {
                printf("%c",cSymbol);
                iaArrayOfSymbols[ (int)cSymbol ]++;
                i++;
                if(i==MAX_SIZE)
                {
                    break;
                }
            }
        fclose(pFile);
        getchar();
    }

    //output Array of symbols
    for (i=0; i<255; i++)
    {
        printf("%c: %d\n",(char)i, iaArrayOfSymbols[i]);
    }


    getchar();getchar();
    return 0;
}
