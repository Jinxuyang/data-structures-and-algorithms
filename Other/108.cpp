#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

#define OK  1
#define ERROR  0
#define TRUE   1
#define FALSE 0

typedef char ElemType;
typedef struct Node 
{
	ElemType data;
	struct Node *next;

}Node, *LinkList;

void init_linklist(LinkList *l)
{
	*l=(LinkList)malloc(sizeof(Node));
	(*l)->next=NULL;
}
void CreateFromTail(LinkList L)
{
	Node *r,*s;
	char c;
	int flag =1;
	r=L;
	while(flag)
	{
		c=getchar();
		if(c!='$')
		{
			s=(Node*)malloc(sizeof(Node));
			s->data=c;
			r->next=s;
			r=s;
		}
		else
		{
			flag=0;
		r->next=NULL;
		}

	}
}

int main(int argc, char const *argv[])
{
	LinkList l;
	init_linklist(*l);
	CreateFromTail(l);
	return 0;
}

