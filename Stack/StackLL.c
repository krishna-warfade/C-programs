#include <stdio.h>
#include <stdlib.h>

struct Node
{
    char data;
    struct Node *next;
} *top = NULL;

void push(int x)
{
    struct Node *t;
    t = (struct Node *)malloc(sizeof(struct Node));
    if (t == NULL)
    {
        printf("Stack is Full\n");
        return;
    }
    else
    {
        t->data = x;
        t->next = top;
        top = t;
        return;
    }
}

char pop()
{
    char x = -1;
    if (top == NULL)
    {
        printf("Stack is empty\n");
    }
    else
    {
        struct Node *p;
        p = top;
        top = top->next;
        x = p->data;
        free(p);
    }
    return x;
}

int peek(int index)
{
    int x = -1;
    if (top == NULL)
    {
        printf("Stack is empty");
    }
    else
    {
        struct Node *p;
        p = top;
        for (int i = 0; p != NULL && i < index - 1; i++)
        {
            p = p->next;
        }
        if (p != NULL)
        {
            x = p->data;
        }
    }
    return x;
}

void Display()
{
    struct Node *p;
    p = top;
    while (p != NULL)
    {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

int isEmpty(){
    return top==NULL?1:0;
}

int isBalance(char *exp){
    for(int i = 0;exp[i]!='\0';i++){
        if(exp[i]=='('){
            push(exp[i]);
        }else if(exp[i]==')'){
            if(top==NULL) 
                return 0;
            pop();
        }
        
    }
    if(top==NULL){
        return 1;
    }
    return 0;
}
int main()
{
    // char *exp = "(((a+b)*(c-d)))";
    // printf("%d ",isBalance(exp));
    push(3);
    push(4);
    Display();
    return 0;
}
