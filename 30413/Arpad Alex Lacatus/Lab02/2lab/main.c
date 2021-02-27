#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct node
{
    int key;
    struct node *next;

}NodeT;
typedef struct
{
    int count;
    NodeT *first;
    NodeT *last;

}ListT;

int isEmpty(ListT *listPtr)
{
    if(listPtr->count==0)
    {
        return 1;
    }
    return 0;
}
ListT *createEmptySLL()
{
    ListT *listPtr=(ListT*)malloc(sizeof(ListT));
    if(listPtr)
    {
        listPtr->count=0;
        listPtr->first=listPtr->last=NULL;
    }
    return listPtr;
}

NodeT *createSLLNode(int key)
{
    NodeT *p=(NodeT*)malloc(sizeof(NodeT));
    if(p)
    {
        p->key=key;
        p->next=NULL;
    }
    return p;
}

int insertAtRear(ListT *listPtr,NodeT *p)
{
    if(listPtr)
    {
        if(isEmpty(listPtr))
        {
            listPtr->first=p;
        }
        else
        {
            listPtr->last->next=p;
        }
        listPtr->last=p;
        listPtr->last->next=NULL;
        listPtr->count++;
        return 1;
    }
    return 0;
}

NodeT *find(ListT *listPtr, int givenKey)
{
    NodeT *p;
    p=listPtr->first;
    while(p!=NULL)
    {
        if(p->key==givenKey)
        {
            return p;
        }
        else
        {
            p=p->next;
        }
    }
    return NULL;
}

NodeT *deleteLast(ListT *listPtr)
{
    NodeT *q,*q1;
    q1=NULL;
    q=listPtr->first;

    if(q!=NULL)
    {
        while(q != listPtr->last)
        {
            q1=q;
            q=q->next;
        }
        if(q == listPtr->first)
        {
            listPtr->first=listPtr->last=NULL;
        }
        else
        {
            q1->next=NULL;
            listPtr->last=q1;
        }
        listPtr->count--;
    }
    return q;

}
NodeT *deleteByKey(ListT *listPtr, int givenKey)
{
    NodeT *q,*q1;
    q1=NULL;
    q=listPtr->first;
    while(q!=NULL)
    {
        if(q->key==givenKey) break;
        q1=q;
        q=q->next;
    }
    if(q!=NULL)
    {
        if(q==listPtr->first)
        {
            listPtr->first=listPtr->first->next;
            if(listPtr->first==NULL)
            {
                listPtr->first=NULL;
            }

        }
        else
        {
            q1->next=q->next;
            if(q==listPtr->last) q=listPtr->last;
        }
        return q;
    }
    return NULL;

}



int main( )
{
    FILE *f=fopen("data.txt","r");
    ListT *road,*garage;
    road=createEmptySLL();
    garage=createEmptySLL();


    char comanda[7];
    while(fscanf(f,"%s",comanda)==1)
    {
        int i;
        int val=0;

        for(i=0;i<strlen(comanda);i++)
        {
            if(comanda[i]<='9' && comanda[i]>='0')
            {
                val=val*10+(comanda[i]-'0');
            }
        }
        char cuv=comanda[2];
       // printf("ads");

        switch(comanda[0])
        {
            case 'R':
                insertAtRear(road,createSLLNode(val));
                break;
            case 'E':
                if(find(road,val)!=NULL)
                {

                if(val==road->first->key)
                {


                insertAtRear(garage,deleteByKey(road,val));
                }
                else
                {
                    printf("error:%d not on road exit \n");
                }

                }
                else
                {
                    printf("error: %d not at road exit \n",val);
                }
                break;
            case 'X':
                if(find(garage,val)!=NULL)
                {
                    if(val==garage->last->key)
                    {
                        insertAtRear(road,deleteLast(garage));


                    }
                    else
                    {
                        printf("error: %d not at garage exit \n",val);
                    }
                }
                else
                {
                    printf("error: %d not in garage \n",val);
                }
                break;
            case 'S':
                if(cuv=='G')
                {
                    int k=0;
                    NodeT *q=garage->first;
                    printf("G:");
                    while(q!=NULL)
                    {
                        printf("%d ",q->key);
                        q=q->next;
                        k++;
                    }
                    if(k==0)
                    {
                        printf("none");
                    }
                    printf("\n");
                }
                if(cuv=='R')
                {
                    int k=0;
                    NodeT *q=road->first;
                    printf("R:");
                    while(q!=NULL)
                    {
                        printf("%d ",q->key);
                        q=q->next;
                        k++;
                    }
                    if(k==0)
                    {
                        printf("none");
                    }
                    printf("\n");
                }
                break;
            default:
                ;






        }
    }
    return 0;
}
