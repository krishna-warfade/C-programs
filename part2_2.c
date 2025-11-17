/*
 - Circular Linked List
*/

#include<stdio.h>

typedef struct bhai{
	char c;
	struct bhai *a;
}bhai;

void printList (bhai *head) {
	if (head == NULL) {
		printf("list is empty\n");
		return;
	}
	bhai *temp = head;

	do {
		printf("%c ", temp->c);
		temp = temp->a;
	} while (temp != head);

	return;
}

int main(){
	bhai *p, *q, *r;
	bhai l, m, n;
	
	p = &l;
	p->c = 'w';
	p->a = &m;
	q = p->a;
	
	q->c = 'x';
	q->a = &n;
	r = q->a;
	
	r->c = 'y';
	r->a = p;
	
	printList(p);

	q = r = NULL;
	return 0;
}
