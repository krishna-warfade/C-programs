#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

Node *Head;

void create(int A[], int n)
{
    Node *last, *t;
    Head = (Node *)malloc(sizeof(Node));
    Head->data = A[0];
    Head->next = Head;
    last = Head;
    for (int i = 1; i < n; i++)
    {
        t = (Node *)malloc(sizeof(Node));
        t->data = A[i];
        t->next = last->next;
        last->next = t;
        last = t;
    }
}

void Display(Node *h)
{
    Node*p=h;
    do
    {
        printf("%d ", p->data);
        p = p->next;
    } while (p != h);
    printf("\n");
}

void RDisplay(Node *h)
{
    static int flag = 0;
    if (h != Head || flag == 0)
    {
        flag = 1;
        printf("%d ", h->data);
        RDisplay(h->next);
    }
    flag = 0;
}

int Length(Node *h)
{
    int len = 0;
    do
    {
        len++;
        h = h->next;
    } while (h != Head);
    return len;
}

void insert(Node *h, int pos, int x)
{
    Node *t, *p;
    if (pos < 0 || pos > Length(h))
    {
        return;
    }
    if (pos == 0)
    {
        t = (Node *)malloc(sizeof(Node));
        t->data = x;
        if (Head == NULL)
        {
            Head = t;
            t->next = t;
        }
        else
        {
            p = Head;
            while (p->next != Head)
            {
                p = p->next;
            }
            p->next = t;
            t->next = Head;
            Head = t;
        }
    }
    else
    {
        p = Head;
        for (int i = 0; i < pos - 1; i++)
        {
            p = p->next;
        }
        t = (Node *)malloc(sizeof(Node));
        t->data = x;
        t->next = p->next;
        p->next = t;
    }
}

int Delete(Node *h, int pos)
{
    int x = -1;
    if (pos == 1)
    {
        while (h->next != Head)
        {
            h = h->next;
        }
        if (h == Head)
        {
            free(Head);
            Head = NULL;
        }
        else
        {
            h->next = Head->next;
            x = Head->data;
            free(Head);
            Head = h->next;
        }
    }
    else
    {
        Node *q;
        for (int i = 0; i < pos - 2; i++)
        {
            h = h->next;
            if (h == Head) // out of bound
                return -1;
        }
        q = h->next; // node to be deleted
        if (q == Head)
            return -1;
        h->next = q->next;
        x = q->data;
        free(q);
    }
    return x;
}

int main()
{
    int A[] = {20, 30, 40, 50, 60};
    create(A, 5);
    insert(Head, 3, 70);
    printf("%d\n",Delete(Head,1));
    Display(Head);
    return 0;
}