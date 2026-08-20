#include<stdio.h>
#include<stdlib.h>

struct node
{
        int data;
        struct node *next;
};

typedef struct node NODE;
typedef struct node* PNODE;
typedef struct node** PPNODE;

void Display(PNODE first)
{
        while(first != NULL)
        {
                printf(" | %d | -> ", first->data);
                first = first->next;
        }
        
        printf(" NULL\n");
}

int Count(PNODE first)
{
        int iCount = 0;

        while(first != NULL)
        {
                iCount++;
                first = first->next;
        }
        
        return iCount;
        
}

void InsertFirst(PPNODE first, int iNo)
{
        PNODE newn = NULL;

        newn = (PNODE)malloc(sizeof(NODE));

        newn->data = iNo;
        newn->next = NULL;

        if(*first == NULL)
        {
                *first = newn;
        }
        else
        {
                newn->next = *first;
                *first = newn;
        }
}

void InsertLast(PPNODE first, int iNo)
{
        PNODE newn = NULL;
        PNODE temp = NULL;

        newn = (PNODE)malloc(sizeof(NODE));

        newn->data = iNo;
        newn->next = NULL;

        if(*first == NULL)
        {
                *first = newn;
        }
        else
        {
                temp = *first;

                while(temp->next != NULL)
                {
                        temp = temp->next;
                }

                temp->next = newn;                
        }
}

void InsertAtPos(PPNODE first, int iNo, int iPos)
{
        PNODE temp = NULL;
        PNODE newn = NULL;

        int i = 0;
        int iCount = 0;

        iCount = Count(*first);

        if((iPos < 1) || (iPos > iCount + 1))
        {
                printf("Invalid Position\n");
                return;
        }

        if(iPos == 1)
        {
                InsertFirst(first, iNo);
        }
        else if(iPos == iCount + 1)
        {
                InsertLast(first, iNo);
        }
        else
        {
                newn = (PNODE)malloc(sizeof(NODE));

                newn->data = iNo;
                newn->next = NULL;

                temp = *first;

                for(i = 1; i < iPos - 1; i++)
                {
                        temp = temp->next;
                }

                newn->next = temp->next;
                temp->next = newn;
        }
}

void DeleteFirst(PPNODE first)
{
        PNODE temp = NULL;

        if(*first == NULL)
        {
                return;
        }
        else if((*first)->next == NULL)
        {
                free(*first);
                *first = NULL;
        }
        else
        {
                temp = *first;

                *first = (*first)->next;
                free(temp);
        }
}

void DeleteLast(PPNODE first)
{
        PNODE temp = NULL;

        if(*first == NULL)
        {
                return;
        }
        else if((*first)->next == NULL)
        {
                free(*first);
                *first = NULL;
        }
        else
        {
                temp = *first;

                while(temp->next->next != NULL)
                {
                        temp = temp->next;
                }

                free(temp->next);
                temp->next = NULL;                
        }
}

void DeleteAtPos(PPNODE first, int iPos)
{
        PNODE temp = NULL;
        PNODE target = NULL;

        int i = 0;
        int iCount = 0;

        iCount = Count(*first);

        if((iPos < 1) || (iPos > iCount))
        {
                printf("Invalid Position\n");
                return;
        }

        if(iPos == 1)
        {
                DeleteFirst(first);
        }
        else if(iPos == iCount)
        {
                DeleteLast(first);
        }
        else
        {
                temp = *first;

                for(i = 1; i < iPos - 1; i++)
                {
                        temp = temp->next;
                }

                target = temp->next;
                temp->next = target->next;
                free(target);
        }
}

int main()
{
        PNODE head = NULL;
        int iRet = 0;
        
        printf("\n");

        InsertFirst(&head, 51);
        InsertFirst(&head, 21);
        InsertFirst(&head, 11);

        Display(head);
        iRet = Count(head);
        printf("Number of Nodes are : %d \n", iRet);

        printf("\n");

        InsertLast(&head, 101);
        InsertLast(&head, 111);
        InsertLast(&head, 121);

        Display(head);
        iRet = Count(head);
        printf("Number of Nodes are : %d \n", iRet);

        printf("\n");

        InsertAtPos(&head, 105, 4);

        Display(head);
        iRet = Count(head);
        printf("Number of Nodes are : %d \n", iRet);

        printf("\n");

        DeleteFirst(&head);

        Display(head);
        iRet = Count(head);
        printf("Number of Nodes are : %d \n", iRet);

        printf("\n");

        DeleteLast(&head);

        Display(head);
        iRet = Count(head);
        printf("Number of Nodes are : %d \n", iRet);

        printf("\n");

        DeleteAtPos(&head, 4);

        Display(head);
        iRet = Count(head);
        printf("Number of Nodes are : %d \n", iRet);

        printf("\n");

        return 0;
}