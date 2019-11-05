#include<stdio.h>
#include<locale.h>
#define MAX_SIZE 10000
int main(){

    // WORK with FILES
    setlocale(LC_ALL,"");
    int iaArrayOfSymbols[255]={0};      //array of symbols
    char str[MAX_SIZE];             //string of chars
    char cSymbol;                   // symbol
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
    }

    //output Array of symbols
    for (i=0; i<255; i++)
    {
        printf("\n%c: %d",(char)i, iaArrayOfSymbols[i]);
    }


    getchar();
    return 0;
}
