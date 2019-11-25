#include <stdio.h>
#include <stdbool.h>
#include <time.h>
#define MAX_STACK_SIZE 10

struct sStack
{
    int aiData[MAX_STACK_SIZE];
    int iStackSize;
    int iStackHead;
};

void push(struct sStack *stack, const int kiDataValue)
{
    if(stack->iStackSize >= MAX_STACK_SIZE)
    {
        printf("Stack overflow!");
    }
    else
    {
        stack->aiData[stack->iStackSize]=kiDataValue;
        stack->iStackSize++;
    }
}

int pop(struct sStack *stack)
{
    if(stack->iStackSize<=0)
    {
        printf("Stack is empty");
    }
    else
    {
        stack->iStackSize--;
        return stack->aiData[stack->iStackSize];
    }
}

int shift(struct sStack *stack)
{
    if(stack->iStackHead>=stack->iStackSize)
    {
        printf("Queue is empty!");
    }
    else
    {
        stack->iStackHead++;
        return stack->aiData[stack->iStackHead-1];
    }
}
int peek(const struct sStack *stack)
{
    if(stack->iStackSize<=0)
    {
        printf("Stack is empty");
    }
    else
    {
        return stack->aiData[stack->iStackSize-1];
    }
}

void printStack(const struct sStack *stack)
{
    int i;
    int iBegin=stack->iStackHead;
    int iLength=stack->iStackSize-1;
    printf("\nList of %d tasks >> ", iLength+1-iBegin);
    for(i=iBegin;i<iLength;i++)
    {
        printf("%d", stack->aiData[i]);
        printf(" | ");
    }
    if(i==iLength)
    {
        printf("%d", stack->aiData[i]);
    }
    printf("\n");
}

int main()
{
    int iAction=0;
    int iNumberOfTasks=0;
    bool bMainLoopIsTrue=true;
    struct sStack stack;
    stack.iStackSize=0;
    stack.iStackHead=0;

    printf("Welcome to task manager. Maximum number of tasks is 10!");
    do
    {
        printf("\nPress \'1\' to enter number of tasks.");
        printf("\nPress \'2\' to form task list automatically.");
        printf("\nPress \'3\' to enter data.");
        printf("\nPress \'4\' to view list of tasks.");
        printf("\nPress \'5\' to start STACK-order execution.");
        printf("\nPress \'6\' to start QUEUE-order execution.");
        printf("\nPress \'7\' to PEEK task.");
        printf("\nPress \'0\' to exit program.\nAction is: ");
        scanf("%d", &iAction);

        switch(iAction)
        {
            case 0:
                {
                    printf("\nAction 0 selected.\nExit!");
                    bMainLoopIsTrue=false;
                    break;
                }

            case 1:
                {
                    bool bIsOutOfRange=true;
                    printf("\nAction 1 selected.");
                    do
                    {
                        printf("\nEnter number of tasks between 1 and 10: ");
                        scanf("%d", &iNumberOfTasks);
                        if (iNumberOfTasks<1 || iNumberOfTasks>10 )
                            {
                                bIsOutOfRange=true;
                            }
                        else
                        {
                            bIsOutOfRange=false;
                        }
                    }while(bIsOutOfRange);
                    break;
                }
            case 2:
                {
                    int iData;
                    srand(time(NULL));
                    printf("\nAction 2 selected.");
                    if (iNumberOfTasks<1 || iNumberOfTasks>10 )
                    {
                        printf("\nNumber of tasks is not specified!\n");
                        break;
                    }
                    int i;
                    for(i=1;i<=iNumberOfTasks;i++)
                    {
                        iData=rand()%100;
                        push(&stack, iData);
                    }
                    printf("\nList of tasks is formed automatically.\n");
                    break;
                }
            case 3:
                {
                    printf("\nAction 3 selected.");
                    int i;
                    int res;
                    int iData;
                    if (iNumberOfTasks<=0)
                    {
                        printf("\nEnter number of task first!\n");
                        break;
                    }
                    if(stack.iStackSize==iNumberOfTasks)
                    {
                        printf("\nTask list is full!\n");
                        break;
                    }
                    for(i=0; i<iNumberOfTasks; i++)
                    {
                        do
                        {
                            printf("\nEnter digital data: ");
                            fflush(stdin);
                            res=scanf("%d",&iData);
                            if(res==1) printf("Good!\n");
                            else printf("%s","Invalid input. Try again.\n");
                        }while(res!=1);
                        push(&stack, iData);
                    }
                    printf("\n");
                    break;
                }
            case 4:
                {
                    printf("\nAction 4 selected.");
                    printStack(&stack);
                    break;
                }
            case 5:
                {

                    printf("\nAction 5 is selected.");
                    if(iNumberOfTasks<=0)
                    {
                        printf("\nTask list is empty!\n");
                        break;
                    }
                    int i;
                    for(i=0; i<=stack.iStackSize; i++)
                    {
                        printStack(&stack);
                        printf("\nTask %d is executed", pop(&stack));
                    }
                    iNumberOfTasks=stack.iStackSize;
                    printf("\nThere is %d tasks in the list!\n", iNumberOfTasks);

                    break;
                }
            case 6:
                {
                    printf("\nAction 6 is selected.");
                    if(iNumberOfTasks<=0)
                    {
                        printf("\nTask list is empty!");
                        break;
                    }

                    int i;
                    for(i=stack.iStackSize-1; i>=0; i--)
                    {
                        printStack(&stack);
                        printf("\nTask %d is executed", shift(&stack));
                        //iNumberOfTasks--;
                    }
                    iNumberOfTasks=i+1;
                    printf("\nThere is %d tasks in the list!\n", iNumberOfTasks);

                    break;
                }
            case 7:
            {
                printf("\nAction 7 selected.");
                printf("Task %d is peeked.", peek(&stack) );
                printStack(&stack);
            }
            default:
                break;
        }
    }while(bMainLoopIsTrue);
    printf("\nBye!");
    getchar();

    return 0;
}
