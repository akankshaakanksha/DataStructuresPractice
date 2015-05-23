#include<stdio.h>
#include<stdlib.h>
struct node
{
	int x;
	int sum;
	struct node* next;
};
typedef struct node node;
int flag;
node* top;
void push(int x)
{
	if(top == NULL)
	{
		top = (node*)malloc(sizeof(node));
		top->x = x;
		top->sum = 0;
		top->next = NULL;
		return;
	}
	else if(x <= top->x)
	{
		flag = 1;
		return;
	}
	else
	{
		node* temp = (node*)malloc(sizeof(node));
		temp->x = x;
		temp->sum = 0;
		temp->next = top;
		top = temp;
		return;
	}
}
void pop(int x)
{
	if(top == NULL)
	{
		flag = 1;
		return;
	}
	node* temp = top;
	top = top->next;
	if(temp->sum >= -temp->x && temp->sum != 0)
	{
		flag = 1;
		return;
	}
	if(top != NULL)
	{
		top->sum += x;
		free(temp);
		return;
	}
	free(temp);
	return;
}
int main()
{
	int t,i,j,n,x;
	scanf("%d",&t);
	for(i=1;i<=t;++i)
	{
		int start, end;
		top = NULL;
		flag = 0;
		scanf("%d",&n);
		for(j=1;j<=n;++j)
		{
			scanf("%d",&x);
			if( j == 1 )
				start = x;
			if( j == n )
				end = x;
			if(x < 0)
				push(x);
			else if(top != NULL)
			{
				if(top->x == -x)
					pop(x);
				else
					flag = 1;
			}
			else
				flag = 1;
		}
		if( -1*start != end )
			flag = 1;
		if(top != NULL)
			flag = 1;
		if(flag == 1)
			printf(":-( Try again.\n");
		else
			printf(":-) Matrioshka!\n");
	}
	return 0;
}
