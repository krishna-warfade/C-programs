#include<stdio.h>
#include<stdlib.h>

struct stack{
    int size;
    int top;
    int *s;
};

void create(struct stack *st){
    printf("Enter Size :");
    scanf("%d",&st->size);
    st->top=-1;
    st->s=(int*)malloc(st->size*sizeof(int));
}

void Display(struct stack st){
    for(int i = st.top;i>=0;i--){
        printf("%d ",st.s[i]);
    }
    printf("\n");
}

void push(struct stack *st,int x){
    if(st->top==st->size-1){
        printf("Stack Overflow");
    }else{
        // st->top++;
        st->s[st->(++top)] = x;
    }
}

int pop(struct stack *st){
    int x = -1;
    if(st->top==-1){
        printf("Stack underflow");
    }else{
        x = st->s[st->top--];
        // st->top--;
    }
    return x;
}

int peek(struct stack st,int index){
    int x = -1;
    if(st.top-index+1<0){
        printf("Invalid Index \n");
    }else{
        x = st.s[st.top-index+1];
    }
    return x;
}

int isEmpty(struct stack st){
    return st.top==-1;
}

int isFull(struct stack st){
    return st.top==st.size-1;
}

int stackTop(struct stack st){
    int x = -1;
    if(!isEmpty){
        x = st.s[st.top];
    }
    return x;
}

int main(){
    struct stack st;
    create(&st);

    push(&st,25);
    push(&st,30);
    push(&st,35);
    push(&st,40);
    printf("%d \n",pop(&st));
    printf("%d \n",peek(st,3));

    Display(st);
    return 0;
}