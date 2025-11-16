#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    struct Node *lchild;
    int data;
    struct Node *rchild;
} Node;

Node *root = NULL;

Node *RSearch(Node *t, int key)
{
    if (t == NULL)
    {
        return NULL;
    }
    if (t->data == key)
    {
        return t;
    }
    else if (t->data < key)
    {
        return RSearch(t->rchild, key);
    }
    else
    {
        return RSearch(t->lchild, key);
    }
}

Node *Insert(Node *t, int x)
{
    Node *r, *p, *q;
    q = t;
    r = NULL;
    if (t == NULL)
    {
        p = (Node *)malloc(sizeof(Node));
        p->data = x;
        p->lchild = p->rchild = NULL;
        t = p;
        return t;
    }
    while (t)
    {
        r = t;
        if (t->data == x)
        {
            return NULL;
        }
        else if (t->data < x)
        {
            t = t->rchild;
        }
        else
        {
            t = t->lchild;
        }
    }
    p = (Node *)malloc(sizeof(Node));
    p->data = x;
    p->lchild = p->rchild = NULL;
    if (p->data < r->data)
    {
        r->lchild = p;
    }
    else
    {
        r->rchild = p;
    }
    return q;
}

int height (Node* root) {
    int a = 0;
    int b = 0;

    if (root == 0)
        return 0;
    a = height(root->lchild);
    b = height(root->rchild);

    return (a > b) ? (1 + a) : (1 + b);
}

Node *inorder_predec (Node *p) { // for largest value in left subtree by going as right as possible
    while (p && p->rchild)
        p = p->rchild;
    return p;
}

Node *inorder_succ (Node *p) { // receives right subtree of a node and goes as left as possible
    while (p && p->lchild)
        p = p->lchild;
    return p;
}

Node *delete (int key, Node *t) {
    if (!t)
        return NULL;
    
    if (key < t->data)
        t->lchild = delete(key, t->lchild);
    else if (key > t->data)
        t->rchild = delete(key, t->rchild);
    else { // key node found
        if (!t->lchild && !t->rchild) {
            free(t);
            return NULL;
        }
        else if (height(t->lchild) > height(t->rchild)) {
            Node *predecessor = inorder_predec(t->lchild);

            t->data = predecessor->data;
            t->lchild = delete(predecessor->data, t->lchild);
        }
        else {
            Node *successor = inorder_succ(t->rchild);

            t->data = successor->data;
            t->rchild = delete(successor->data, t->rchild);
        }
    }
    return t;
}

void Inorder(Node *p)
{
    if (p)
    {
        Inorder(p->lchild);
        printf("%d ", p->data);
        Inorder(p->rchild);
    }
}

int main()
{
    root = Insert(root, 2);
    Insert(root, 3);
    Insert(root, 5);
    Insert(root, 7);
    Inorder(root);

    Node *t = RSearch(root, 5);
    printf("%d", t->data);

    printf("\n");
    root = delete(3, root);
    Inorder(root);
    return 0;
}