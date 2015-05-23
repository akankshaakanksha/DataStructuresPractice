#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
	int d;
	struct node *next;
}NODE;

int comp(const void* a,const void* b)
{
	int *A= (int*)a;
	int *B= (int*)b;

	return *A-*B;
}

NODE* insert(NODE* head,int val)
{
	if(head=NULL)
	{
		NODE* temp;
		temp=malloc(sizeof(NODE));
		temp->d=val;
		head=temp;
		temp->next=head;
		printf("head:%d",head->d);
		return head;
	}
	else
	{
		NODE* temp;
		temp=head;
		while(temp->next!=head)
			temp=temp->next;
		NODE* new;
		new=malloc(sizeof(NODE));
		new->d=val;
		new->next=head;
		temp->next=new;
		printf("later:%d",temp->next->d);
		return head;

	}
}


void print(NODE *head)
{
	NODE* temp;
	temp=head;
	while(temp->next!=head)
	{
		printf("%d ",temp->d);
		temp=temp->next;
	}
	printf("\n");
}
int main()
{
	int a[100];
	int i,n,j,k;
	NODE *head; 
	head=NULL;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}

	qsort(a,n,sizeof(int),comp);

	printf("Sorted\n");
	for(i=0;i<n;i++)
	{
		head=insert(head,a[i]);
		printf("i");
	}

	print(head);



}
