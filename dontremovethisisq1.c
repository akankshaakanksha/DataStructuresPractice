#include<stdio.h>

#include<stdlib.h>
#include<math.h>
typedef struct node
{
	int d;
	int sum;
	struct node* next;
}NODE;
int flag=0;

void push(NODE **top,int val)
{
	NODE *temp;
	temp=malloc(sizeof(NODE));
	temp->d=val;
	if(*top == NULL)
		temp->sum=0;
	else if( val <= (*top)->d)
	{
		
		flag=1;
		return;
	}
	if (*top!=NULL)
	{	
	temp->next=(*top);
	temp->sum=0;
	*top=temp;
	return;
	}
	
	temp->next=(NULL);
	*top=temp;
	return;

}

void pop(NODE **top)
{
	
	if(*top==NULL)
	{
		flag=1;
		return;
	}
	int x=(*top)->d;
	NODE *temp;
	temp=*top;
	*top=(*top)->next;
	if((temp->sum)>=(-x) && (temp->sum)!= 0)
	{
		flag = 1;
		return;
	}
	if(*top !=NULL)
	{
		(*top)->sum=(*top)->sum + x;
		free(temp);
		return;
	}



}





int main()
{
	int test;
	
	scanf("%d",&test);
	while(test>0)
	{
		 flag = 0;
		NODE *top;
		top=NULL;
		int numem;
		scanf("%d",&numem);
		int i;
		int start,end;	
		for(i=0;i<numem;i++)
		{
			int moss;
			scanf("%d",&moss);
			if(i==0)
				start=moss;
			if(i==numem-1)
				end=moss;
			if(moss<0)
				push(&top,moss);
			else if(top!=NULL)
			{
				if(top->d == -1*moss)
					pop(&top);
				else
					flag=1;
			}
			else 
				flag=1;

		}

		if(-1* start!=end)
			flag=1;
		if(top !=NULL)
			flag=1;
		if(flag ==1)
			printf(":-( Try again.\n");
		else
			printf(":-) Matrioshka!\n");
		flag = 0;
		test--;
	}	
	return 0;
}
	
		
