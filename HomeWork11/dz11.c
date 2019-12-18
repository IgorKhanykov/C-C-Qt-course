#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>   // for srand(), rand()
#include <string.h> // for strlen()
#define MAX_MEMORY_CAPACITY 10485760


typedef struct sStruct
{
    int iOrder;     //4bytes
    char *str;      //4bytes
    int iStrLen;    //4bytes
    bool bExist;    //1byte
    struct sStruct *next;   //4bytes
    struct sStruct *prev;   //4bytes
} tsStruct;

void pushStruct(tsStruct **head, const char * paChars)
{
    tsStruct *tmp=(tsStruct *)malloc(sizeof(tsStruct));
    if(tmp==NULL)
    {
        printf("Stack overflow!");
    }
    else
    {
        tmp->iOrder=(*head)->iOrder+1;
        tmp->str=paChars;
        tmp->iStrLen=strlen(paChars)+sizeof(tsStruct);
        tmp->bExist=true;

        tmp->prev=(*head);
        tmp->next=NULL;
        (*head)->next=tmp;
        (*head)=tmp;
    }
}

void printStructList(tsStruct *tail)
{
    printf("\nStructList > ");
    while(tail->next)
    { //skip first zero-node and message freed nodes
        if(tail->str && tail->bExist ) printf("\nBlock #%d, Volume %d Bytes",tail->iOrder, tail->iStrLen);//string+'\0'
        if(tail->str && !(tail->bExist) ) printf("\nBlock #%d is marked to free. SORT OUT to get access %d Bytes.", tail->iOrder, tail->iStrLen);
        tail=tail->next;
    }
    if( !(tail->next) && (tail->str) && (tail->bExist))
    {//print last node that was not freed
        printf("\nBlock #%d, Volume %d Bytes",tail->iOrder, tail->iStrLen);//string+'\0'
    }
    if( !(tail->next) && (tail->str) && !(tail->bExist) )
    {//print message if last node was freed
        printf("\nBlock #%d is marked to free. SORT OUT to get access to %d Bytes.", tail->iOrder, tail->iStrLen);
    }

}

char * generateRandomString(const int kiLength)
{
    char *pString= "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789[];:'|,.-#'?~!@#$%^&*()_+-/\"\\ ";
    unsigned int iStringLen=strlen(pString);
    char *pcRandomString=NULL;

    srand(time(NULL));
    pcRandomString=malloc(sizeof(char)*(kiLength+1));

    if(pcRandomString)
    {
        int key=0;
        int i;
        for(i=0; i<kiLength; i++)
        {
            key=rand()%iStringLen;
            pcRandomString[i]=pString[key];
        }
        pcRandomString[kiLength]='\0';
        return pcRandomString;
    }
    else
    {
        printf("\ngenerateRandomString(): Out of memory!");
        exit(1);
    }
}

int freeStructList(tsStruct **head)
{
    int i=0, iFreedMemory=0;
    while( (*head)->prev )
    {
        tsStruct *out=*head;
        *head=(*head)->prev;
        (*head)->next=NULL;
        iFreedMemory=iFreedMemory+(out->iStrLen);
        free(out);
        i++;
    }
    printf("\nfreeStructList(): %d blocks of total volume of %d Bytes freed.\nStruct is empty! ", i, iFreedMemory);
    return iFreedMemory;
}

int sortoutStructList(tsStruct *tail, tsStruct **head)
{ // !UNDONE!!
    int iMemoryFreed=0;
    while( tail->next )
    {
        tsStruct *tmp=tail;
        while(tmp->next)
        {
            tmp=tmp->next;
            if( tmp != *head)
            {
                if(tmp->bExist) tail=tail->next;
                else
                {
                    tsStruct *out=tmp;
                    tail->next=tmp->next;
                    tmp->next->prev=tail;
                    iMemoryFreed=iMemoryFreed+(out->iStrLen);
                    printf("\nsortoutStructList(): Block #%d freed.",out->iOrder);
                    free(out);
                }
            }
            else
            {
                if(tmp->bExist) tail=tail->next;
                else
                {
                    tsStruct *out=*head;
                    (*head)=(*head)->prev;
                    (*head)->next=NULL;
                    iMemoryFreed=iMemoryFreed+(out->iStrLen);
                    printf("\nsortoutStructList(): Block #%d freed.",out->iOrder);
                    free(out);
                }
            }
        }
    }
    printf("\nsortoutStructList(): Freed %d Bytes in total.",iMemoryFreed);
    return iMemoryFreed;
}


void markBlockAsFree(tsStruct *tail, const int kiBlockToFree)
{
    bool bMarked=false;
    while( tail->next )
    {
        if( tail->iOrder == kiBlockToFree)
        {
            tail->bExist=false;
            bMarked=true;
            printf("\nmarkBlockAsFree(): The %d Bytes of volume of Block #%d is marked to free.\nSelect SORT OUT to free selected memory.", tail->iStrLen, tail->iOrder );
            break;
        }
        tail=tail->next;
    }
    if( !(tail->next) && (tail->str) )
    {//check if last node is free
        if( tail->iOrder == kiBlockToFree)
        {
            tail->bExist=false;
            bMarked=true;
            printf("\nmarkBlockAsFree(): The %d Bytes of volume of Block #%d is marked to free.\nSelect SORT OUT to free selected memory.", tail->iStrLen, tail->iOrder );
        }
    }
    if(!bMarked) printf("\nmarkBlockAsFree(): None of Blocks is marked as free." );
}

void reorderStructList(tsStruct *tail)
{
    while(tail->next)
    {
        tail->next->iOrder=(tail->iOrder)+1;
        tail=tail->next;
    }
}

int main()
{
    int iMemoryVolumeLeft=MAX_MEMORY_CAPACITY; //10485760Bytes=10MBytes
    int iMemoryVolume;
    char* pcString;
    int iAction;
    bool bMainLoop=true;
    tsStruct *head=(tsStruct *)malloc(sizeof(tsStruct));
    tsStruct *tail=head;
    head->iOrder=NULL;
    head->str=NULL;
    head->iStrLen=NULL;
    head->bExist=NULL;
    head->next=NULL;
    head->prev=NULL;

    printf("\nWelcome to Simple Memory Manager!");
    printf("\nMaximum memory available 10485760 Bytes.");
    printf("\nMinimum reserve is 10240 Bytes.\n");

    while(bMainLoop)
    {
        printf("\nPress 0 to EXIT.");
        printf("\nPress 1 to RESERVE some memory volume.");
        printf("\nPress 2 to FREE selected block of memory.");
        printf("\nPress 3 to SORT OUT the memory.");
        printf("\nPress 4 to CLEAR the memory.");
        printf("\nPress 5 to SAVE data to file.");

        printf("\nAction is: ");

        int res=0;
        do
        {
            fflush(stdin);
            res=scanf("%d", &iAction);
            if(!res) printf("\nTry again: ");
        }while(!res);


        switch (iAction)
        {
            case 0: //EXIT
            {
                printf("\nAction 0 selected.\nBey!");
                freeStructList(&head);
                bMainLoop=false;
                break;
            }
            case 1: //RESERVE
            {
                printf("\nAction 1 selected.");
                int res;
                if(iMemoryVolumeLeft<=10240)
                    printf("\nRESERVE operation abandoned. Available memory amount is less than 10240 Bytes!\nTry FREE, SORT OUT or CLEAR operation.\n");
                else
                {
                    printf("\nEnter memory volume greater than 10240 Bytes to reserve: ");
                    do
                    {
                        fflush(stdin);
                        res=scanf("%d", &iMemoryVolume);
                        if (!res) printf("Invalid input! Try again: ");
                        if (iMemoryVolume<10240)
                        {
                            printf("Invalid input! Try again: ");
                            res=0;
                        }
                        if(iMemoryVolumeLeft<iMemoryVolume)
                        {
                            printf("Out of Memory! Try again: ");
                            res=0;
                        }
                    }while(!res);

                    iMemoryVolumeLeft=iMemoryVolumeLeft-iMemoryVolume;
                    pcString=generateRandomString(iMemoryVolume-sizeof(tsStruct));
                    pushStruct(&head, pcString);
                    printStructList(tail);
                    printf("\nFree memory available %d Bytes.\n", iMemoryVolumeLeft);
                }
                break;
            }
            case 2: //FREE
            {
                int iBlockToFree;
                int res;
                printf("\nAction 2 selected.");
                printf("\nSelect Block to free: ");
                do
                {
                    fflush(stdin);
                    res=scanf("%d", &iBlockToFree);
                    if(!res) printf("Invalid input! Try again: ");
                    if( (head->iOrder)<iBlockToFree || iBlockToFree<1)
                    {
                        printf("Order out of range! Try again: ");
                        res=0;
                    }
                }while(!res);

                markBlockAsFree(tail, iBlockToFree);

                printStructList(tail);
                printf("\nFree memory available %d Bytes.\n", iMemoryVolumeLeft);
                break;
            }
            case 3: //SORT OUT
            {
                int iMemoryFreed=0;
                printf("\nAction 3 selected.");
                // !UNDONE!!
                iMemoryFreed=sortoutStructList(tail, &head);
                iMemoryVolumeLeft=iMemoryVolumeLeft+iMemoryFreed;
                reorderStructList(tail);
                printStructList(tail);
                printf("\nFree memory available %d Bytes.\n", iMemoryVolumeLeft);
                break;
            }
            case 4: //CLEAR
            {
                int iMemoryFreed;
                printf("\nAction 4 selected.");
                iMemoryFreed=freeStructList(&head);
                iMemoryVolumeLeft=iMemoryVolumeLeft+iMemoryFreed;
                printf("\nFree memory available %d Bytes.\n", iMemoryVolumeLeft);
                break;
            }
            case 5:
            {
                FILE *fp;
                printf("\nAction 5 selected.");
                fp=fopen("outputdata.txt", "w");
                if (!fp) printf("\ncase 5: Error opening file!");
                else
                {
                    while( tail->next )
                    {   //skip first zero-node
                        if (tail->str)
                        {
                            char cOrder[8];
                            sprintf(cOrder, "%d", tail->iOrder);
                            fputs("\n\nBlock #",fp); fputs(cOrder,fp); fputs(": ",fp); fputs(tail->str,fp);
                        }
                        tail=tail->next;
                    }
                    if( !(tail->next) && (tail->str))
                    {
                        char cOrder[8];
                        sprintf(cOrder, "%d", tail->iOrder);
                        fputs("\n\nBlock #",fp); fputs(cOrder,fp); fputs(": ",fp); fputs(tail->str,fp);
                    }
                }
                fclose(fp);
                printf("\nData saved to file \'outputdata.txt\' successfully.");

                break;
            }
        }
    }//while(bMainLoop)
    return 0;
}
