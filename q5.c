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

void insert(NODE** head,int val)
{
	if(*head==NULL)
	{
		NODE* temp;
		temp=(NODE*)malloc(sizeof(NODE));
		temp->d=val;
		temp->next=NULL;
		*head=temp;
		//printf("%d ",(*head)->d);
	}


	else
	{
		NODE* temp;
		temp=*head;
		/*Traverse till the end-temp points to the last filled node*/
		while(temp->next!=NULL)
		{
			temp=temp->next;
		}

		NODE* new;
		new=malloc(sizeof(NODE));
		new->d=val;
		new->next=NULL;
		temp->next=new;
		//		printf("nexted");

	}
}


void circular(NODE **head)
{
	NODE *temp;
	temp=*head;
	while(temp->next!=NULL)
	{
		temp=temp->next;

	}
	temp->next=*head;
}
void print(NODE *head,int n)
{

	NODE* temp;
	temp=head;
	while(temp->next!=head)
	{
		printf("%d ",temp->d);
		temp=temp->next;
	}
	printf("%d ",temp->d);
	printf("\n");
}
int main()
{
	int a[1000];
	int i,n,j,k,t;
	scanf("%d",&t);
	while(t>0)
	{
		NODE *head; 
		head=NULL;
		scanf("%d",&n);
		for(i=0;i<n;i++)
		{
			scanf("%d",&a[i]);
		}

		qsort(a,n,sizeof(int),comp);

		for(j=0;j<n;j++)
		{
			insert(&head,a[j]);
		}

		circular(&head);
		scanf("%d",&k);
		/*the iteration &deletion process*/

		NODE* temp;
		temp=head;
		while(temp->next!=temp)
		{
			for(i=1;i<k-1;i++)
			{
				temp=temp->next;
			}
			NODE* dum;
			dum=temp->next;
			temp->next=temp->next->next;
			//		printf("%d",dum->d);
			free(dum);
			temp=temp->next;

		}
		printf("%d\n",temp->d);
		t--;
	}

	return 0;



}
