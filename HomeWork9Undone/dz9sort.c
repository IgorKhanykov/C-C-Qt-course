#include<stdio.h>
#include<time.h>
#include<stdbool.h>
#define MAX_SIZE 100
#define MAX_RAND MAX_SIZE/10
//See Simplest, Bubble, Coctail, Even-odd, Comby sorts at  https://habr.com/ru/post/204600/
//See Quick sort at https://habr.com/ru/sandbox/29775/


//1
void SortSimplest( int aiMas[], int iMasLength) //Simplest sort
{
    int i=0, k;
    time_t start, end;

    time(&start);
    while(i<iMasLength-1)
    {
        if(aiMas[i]>aiMas[i+1])   //Проблема первого элемента!!
        {
            int iTmp=aiMas[i];
            aiMas[i]=aiMas[i+1];
            aiMas[i+1]=iTmp;
            i=0;
        }
        i++;
        for(k=0;k<iMasLength; k++)
            printf("%d ", aiMas[k]);
        printf("\n");
    }
    time(&end);
    printf("\nSimplest sort lasted: %0.lf sec\n", difftime(end, start));
;
}
//2
void SortBubble(int aiMas[], int iMasLength)
{
    int i,j,k;
    int iLength=iMasLength;
    for(i=0;i<iLength-1;i++)
    {
        for(j=0;j<iLength-1;j++)
        {
            if(aiMas[j]>aiMas[j+1])
            {
                int iTmp=aiMas[j+1];
                aiMas[j+1]=aiMas[j];
                aiMas[j]=iTmp;
            }
        }
        for(k=0;k<iMasLength;k++)
            printf("%d ", aiMas[k]);
        printf("\n");

    }
}
//3
void SortCoctail(int aiMas[], int iMasLength)
{
    int i,j,k;
    int iLeft=0;
    int iRight=iMasLength;
    while(iLeft<=iRight)
    {
        for(i=iLeft; i<iRight-1; i++)
        {
            if(aiMas[i]>aiMas[i+1])
            {
                int iTmp=aiMas[i+1];
                aiMas[i+1]=aiMas[i];
                aiMas[i]=iTmp;
            }
        }
        iRight--;
        for(k=0;k<iMasLength;k++)
            printf("%d ", aiMas[k]);
        printf("\n");

        for(j=iRight; j>iLeft; j--)
        {
            if(aiMas[j-1]>aiMas[j])
            {
                int iTmp=aiMas[j-1];
                aiMas[j-1]=aiMas[j];
                aiMas[j]=iTmp;
            }
        }
        iLeft++;
        for(k=0;k<iMasLength;k++)
            printf("%d ", aiMas[k]);
        printf("\n");
    }
}
//4
void SortEvenOdd(int aiMas[], int iMasLength)
{
    int i,j,k;
    bool bIsSwappedEven=false;
    bool bIsSwappedOdd=false;
    bool bIsExitCondition=false;

    do
    {
        bIsSwappedEven=false;
        bIsSwappedOdd=false;
        for(i=0; i<iMasLength; i=i+2)
        {
            if(aiMas[i]>aiMas[i+1])
            {
                int iTmp=aiMas[i+1];
                aiMas[i+1]=aiMas[i];
                aiMas[i]=iTmp;
                bIsSwappedOdd=true;
            }
        }
        for(k=0;k<iMasLength;k++)
            printf("%d ", aiMas[k]);
        printf("\n");
        for(j=1; j<iMasLength-1; j=j+2)
        {
            if(aiMas[j]>aiMas[j+1])
            {
                int iTmp=aiMas[j+1];
                aiMas[j+1]=aiMas[j];
                aiMas[j]=iTmp;
                bIsSwappedEven=true;
            }
        }
        if(bIsSwappedEven==false && bIsSwappedOdd==false)
            bIsExitCondition=true;

        for(k=0;k<iMasLength;k++)
            printf("%d ", aiMas[k]);
        printf("\n");

    }while(!bIsExitCondition);


/*
        for(k=0;k<iMasLength;k++)
            printf("%d ", aiMas[k]);
        printf("\n");
*/
}
//5
void SortComby(int aiArr[],int iArrLength)
{
    //int *paiMas=aiMas;
    int i,j,k;
    int iShift=iArrLength-1;

    for (j=0;j<iArrLength;j++)
    {
        for(i=0; i+iShift<iArrLength; i++)
        {
            if(aiArr[i]>aiArr[i+iShift])
            {
                int iTmp=aiArr[i];
                aiArr[i]=aiArr[i+iShift];
                aiArr[i+iShift]=iTmp;
            }
        }

        for(k=0;k<iArrLength;k++)
            printf("%d ", aiArr[k]);
        printf("   %d\n", iShift);

        iShift--;
        if(iShift==0)
            break;
    }
}

void AlterArray(int aiMas[], int iMasLength)
{
    int k;
    int *pMas=aiMas;
    pMas[0]=9;
    printf("\nInside Alter Array\n");
    for(k=0;k<iMasLength;k++)
        printf("%d ", pMas[k]);
    printf("\n");

}

square(int a, int b)
{
    a=a*a;
    b=b*b;
     printf("Inside square: a=%d, b=%d\n", a,b);

}

int main()
{
    srand(time(NULL));
    char ch;
    int aiMas[]={3,7,6,8,9,0,4,5,1,2};//[MAX_SIZE];
    int iMasLength=10;
    int i=0, j=0;
    FILE *pFile;


    //generation of random array of integers
    //for(i=0; i<MAX_SIZE; i++)
    //    aiMas[i]=rand()%MAX_RAND;


    //ouput unsorted array
    printf("Initial unsorted array\n");
    for(i=0;i<10;i++) //MAX_SIZE-1
        printf("%d ", aiMas[i]);
    printf("\n");

/*
    printf("\nInside Simple sort function\n");
    SortSimplest(aiMas, iMasLength);
    printf("\nSimply sorted array \n");
    for(i=0;i<iMasLength-1;i++)
        printf("%d ", aiMas[i]);
    printf("\n");
*/

/*
    printf("\nInside Bubble sort function\n");
    SortBubble(aiMas, iMasLength);
    printf("\nBubbly sorted array \n");
    for(i=0;i<iMasLength;i++) //MAX_SIZE-1
        printf("%d ", aiMas[i]);
    printf("\n");
*/
/*
    printf("\nInside Cocltail sort function\n");
    SortCoctail(aiMas, iMasLength);
    printf("\nCoctaily sorted array \n");
    for(i=0;i<iMasLength;i++) //MAX_SIZE-1
        printf("%d ", aiMas[i]);
    printf("\n");
*/

    printf("\nInside Even-odd sort function\n");
    SortEvenOdd(aiMas,iMasLength);
    printf("\nEvenOddly sorted array \n");
    for(i=0;i<iMasLength;i++) //MAX_SIZE-1
        printf("%d ", aiMas[i]);
    printf("\n");

//    aiMas[]={3,7,6,8,9,0,4,5,1,2};

    printf("\nInside Comb-sort function\n");
    SortComby(aiMas,iMasLength);
    printf("\nComby sorted array \n");
    for(i=0;i<iMasLength;i++) //MAX_SIZE-1
        printf("%d ", aiMas[i]);
    printf("\n");


    return 0;
}
