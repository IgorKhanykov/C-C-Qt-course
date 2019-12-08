#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<time.h>

typedef struct sStack
{
    int iData;
    struct sStack *next;
    struct sStack *prev;
} tsStack;

void pushStack(tsStack **head, const int iValue)
{
    tsStack *tmp=(tsStack*)malloc(sizeof(tsStack));
    if(tmp==NULL)
    {
        printf("Stack overflow!");
    }
    else
    {
        tmp->iData=iValue;
        tmp->next=*head;
        (*head)->prev=tmp;
        //if( (*head)->prev || (*head)->next )
        //            printf("[%d,%d,%d] | ",(*head)->prev->iData, (*head)->iData, (*head)->next->iData);
        //printf("[%d ] | ", (*head)->iData);
        *head=tmp;

    }
}
int popStack(tsStack **head)
{
    tsStack *out;
    int iValue;
    if(*head==NULL)
    {
        printf("\npopStack(): Stack is empty!");
    }
    else
    {
        out=*head;
        *head=(*head)->next;
        iValue=out->iData;
        free(out);
        return iValue;
    }
}

void printStack(tsStack *head)
{
    if(!head)
    {
        printf("\nprintStack(): Stack is empty!");
    }
    else
    {
        printf("\nStack > ");
        while(head->next)
        {
            printf("%d | ", head->iData);
            head = head->next;
        }
    }
}

int peekStack(tsStack *head)
{
    return head->iData;
}

void clearStack(tsStack **head)
{
    tsStack *out;
    if(*head==NULL)
    {
        printf("\nclearStack(): Stack is empty!");
    }
    else
    {
        while( (*head)->next)
        {
            out=*head;
            *head=(*head)->next;
            free(out);
        }
    }
}

int shiftStack(tsStack **tail)
{
    tsStack *out;
    int iValue;
    if(*tail==NULL)
    {
        printf("\nshiftStack(): Stack is empty!");
    }
    else
    {
        out=*tail;
        *tail=(*tail)->prev;
        iValue=out->iData;
        free(out);
        return iValue;
    }
}
void printStackShift(tsStack *tail)
{
    printf("\nQueue > ");
    while(tail->next)
    {
        printf("%d | ",tail->iData);
        tail=tail->next;
    }
    printf("\n");
}

int main()
{
    int iAction;
    bool isMainLoopContinue=true;
    int iNumberOfTasks=0;
    int iValue;
    tsStack *head=(tsStack*)malloc(sizeof(tsStack));
    tsStack *tail=(tsStack*)malloc(sizeof(tsStack));
    head->next=NULL;
    head->prev=tail;
    tail->next=head;
    tail->prev=NULL;

    printf("\nWelcome to Simple Task Manager!\n");
    while(isMainLoopContinue)
    {
        printf("\nSelect action.");
        //printf("\nPress 1 to specify number of tasks to enter at once.");
        printf("\nPress 2 to push set of tasks automatically.");
        printf("\nPress 3 to push one task manually.");
        printf("\nPress 4 to print all task list.");
        printf("\nPress 5 to pop one task from task list.");
        printf("\nPress 6 to peek task from task list.");
        printf("\nPress 7 to clear task list.");
/*        printf("\nPress 8 to shift one task from task list.");
        printf("\nPress 9 to ShiftPrint task list.");
*/
        printf("\nPress 0 to exit.\n");
        printf("\nSelected action is: ");
        scanf("%d",&iAction);
        switch(iAction)
        {
            case 0:
            {
                printf("\nAction 0 selected.");
                printf("\nKonstantin, don't forget to get Superman costume! Bye!");
                isMainLoopContinue=false;
                break;
            }

            case 2:
            {
                int i;
                int iValue;
                int iData;
                printf("\nAction 2 selected.");
                printf("\nSpecify number of tasks between 1 and 10 for automatic data insertion: ");
                scanf("%d",&iData);
                if (iData>10 || iData<1)
                {
                    printf("Value out of range! Default number of tasks in set is equal 1.\n");
                    iNumberOfTasks=1;
                }
                else
                {
                    printf("Number of tasks in set is specified!\n");
                    iNumberOfTasks=iData;
                }

                printf("Set of tasks is inserted into task-list.\n");
                srand(time(NULL));
                for(i=1;i<=iNumberOfTasks;i++)
                {
                    iValue=rand()%100;
                    pushStack(&head, iValue);
                }
                break;
            }
            case 3:
            {
                int iValue, iRes=0;
                printf("\nAction 3 selected.");
                do
                {
                    printf("\nEnter digital value: ");
                    fflush(stdin);
                    iRes=scanf("%d", &iValue);
                    if(iRes==1) printf("Good!\n");
                    else printf("%s","Invalid input. Try again.\n");
                }while(iRes!=1);
                pushStack(&head, iValue);
                printf("\n");
                break;
            }
            case 4:
            {
                printf("\nAction 4 selected.");
                printStack(head);
                printf("\n");
                break;
            }
            case 5:
            {
                printf("\nAction 5 selected.");
                if (head->next) printf("\nPopped task is %d",popStack(&head));
                else printf("\ncase 5: Stack is empty!");
                printStack(head);
                break;
            }
            case 6:
            {
                printf("\nAction 6 selected.");
                if(head->next) printf("Peeked task is %d\n", peekStack(head));
                else printf("\ncase 6: Stack is empty!\n");
                break;
            }
            case 7:
            {
                printf("\nAction 7 selected.");
                clearStack(&head);
                printf("\nTask-list is cleared\n.");
                break;

            }
/*
            case 8:
            {
                printf("\nAction 8 selected.");
                if(tail->)
                {
                    printf("tail->iData: %d\n",tail->iData);
                    printf("tail->prev->iData: %d\n",tail->prev->iData);
                    shiftStack(&tail);
                    printf("tail->iData: %d\n",tail->iData);
                }
                else printf("\ncase 8: Task-List is empty!\n");

                //printStack(head);
                break;
            }
            case 9:
            {
                printf("\nAction 9 selected.");
                if (tail)
                    printStackShift(tail);
                else printf("\ncase 9: Task-List is empty!\n");
            }
*/
        }

    }

}
