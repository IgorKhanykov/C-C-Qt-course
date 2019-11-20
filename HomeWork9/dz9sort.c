#include<stdio.h>
#include<string.h>
#include<time.h>
#include<stdbool.h>
#define MAX_SIZE 100000
#define MAX_RAND MAX_SIZE/10
//See Simplest, Bubble, Coctail, Even-odd, Comby sorts at  https://habr.com/ru/post/204600/
//See Quick sort at https://habr.com/ru/sandbox/29775/


//1
void SortSimplest( int aiMas[], int iMasLength) //Simplest sort
{
    int i=0, k;
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
    }
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

    }while(!bIsExitCondition);
}
//5
void SortComby(int aiArr[],int iArrLength)
{
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
        iShift--;
        if(iShift==0)
            break;
    }
}

void CopyArray(int *aiMas1, int *aiMas, int iMasLength)
{
    int i;
    for(i=0;i<iMasLength;i++)
        aiMas1[i]=aiMas[i];
}

void OutputArray(int *aiMas, int iMasLength)
{
    int i;
    for(i=0;i<iMasLength;i++)
        printf("%d ", aiMas[i]);
    printf("\n");
}

void SortQuick(int aiArr[],int first, int last)
{
    if(first<last)
    {
        int left=first;
        int right=last;
        int middle=aiArr[(left+right)/2];
        do
        {
            while(aiArr[left]<middle) left++;
            while(aiArr[right]>middle) right--;
            if(left<=right)
            {
                int iTmp=aiArr[left];
                aiArr[left]=aiArr[right];
                aiArr[right]=iTmp;
                left++;
                right--;
            }
        }while(left<=right);
        SortQuick(aiArr, first, right);
        SortQuick(aiArr, left, last);
    }
}

void SortMinSearch(int aiArr[],int iMasLength)
{
    int i,j,k;
    int iMinPos, iMinVal, iCurPos, iCurVal;

    for(i=0;i<iMasLength-1; i++)
    {
        for(j=i+1;j<iMasLength;j++)
        {
            if (aiArr[i]>aiArr[j])
            {
                int iTmp=aiArr[i];
                aiArr[i]=aiArr[j];
                aiArr[j]=iTmp;
            }
        }
    }
}

int main()
{
    srand(time(NULL));
    int aiMas[MAX_SIZE];//[]={3,7,6,8,9,0,4,5,1,2};//
    int iMasLength=MAX_SIZE;//10;//
    int aiMas1[iMasLength];
    int i=0;
    clock_t t;

    //generation of random array of integers
    for(i=0; i<MAX_SIZE; i++)
        aiMas[i]=rand()%MAX_RAND;


    //printf("Initial unsorted array\n");
    //OutputArray(aiMas, iMasLength);
/* // //don't activate. Method is extremely slow.
   // CopyArray(&aiMas1, &aiMas, iMasLength);
   // SortSimplest(aiMas1, iMasLength);
*/

    t=clock();
    CopyArray(&aiMas1, &aiMas, iMasLength);
    t=clock()-t;
    double time_taken = ((double)t)/CLOCKS_PER_SEC;
    printf("\nCopying of %d elements lasts: %0.9f sec\n", MAX_SIZE, time_taken );
/**/
    printf("\nBubble sort...");
    t=clock();
    SortBubble(aiMas1, iMasLength);
    t=clock()-t;
    time_taken = ((double)t)/CLOCKS_PER_SEC;
    printf("\nBubble sort lasted: %f sec\n", time_taken );

    CopyArray(&aiMas1, &aiMas, iMasLength);
    printf("\nCoctail sort...");
    t=clock();
    SortCoctail(aiMas1, iMasLength);
    t=clock()-t;
    time_taken = ((double)t)/CLOCKS_PER_SEC;
    printf("\nCoctail sort lasted: %f sec\n", time_taken );

    CopyArray(&aiMas1, &aiMas, iMasLength);
    printf("\nEven-Odd sort...");
    t=clock();
    SortEvenOdd(aiMas1,iMasLength);
    t=clock()-t;
    time_taken = ((double)t)/CLOCKS_PER_SEC;
    printf("\nEven-Odd sort lasted: %f sec\n", time_taken );

    CopyArray(&aiMas1, &aiMas, iMasLength);
    printf("\nComby sort...");
    t=clock();
    SortComby(aiMas1,iMasLength);
    t=clock()-t;
    time_taken = ((double)t)/CLOCKS_PER_SEC;
    printf("\nComby sort lasted: %f sec\n", time_taken );

    CopyArray(&aiMas1, &aiMas, iMasLength);
    printf("\nMinSearch sort..." );
    t=clock();
    SortMinSearch(aiMas1, iMasLength);
    t=clock()-t;
     time_taken = ((double)t)/CLOCKS_PER_SEC;
    printf("\nMinSearch sort lasted: %f sec\n", time_taken );

    CopyArray(&aiMas1, &aiMas, iMasLength);
    printf("\nQuick sort..." );
    t=clock();
    SortQuick(aiMas1, 0, iMasLength-1);
    t=clock()-t;
     time_taken = ((double)t)/CLOCKS_PER_SEC;
    printf("\nQuick sort lasted: %f sec\n", time_taken );

    return 0;
}
