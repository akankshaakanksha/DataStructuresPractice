#include<stdio.h>
#include<stdlib.h>
typedef struct Node 
{ 
	char data;
	struct Node *next;
}NODE;
NODE *top;



void pop()
{
	NODE* temp;
	NODE* mv=top;
	if(mv==top)
	{
		top=top->next;
		free(mv);
	}
	else 
	printf("Empty stack\n");
	return ;
}
void push(char val)
{
	NODE *temp;
	temp=(NODE*)malloc(sizeof(struct Node));
	temp->data=val;
	if(top==NULL)
	{
		top=temp;
		top->next=NULL;
	}
	else
	{
		temp->next=top;
		top=temp;
	}
	return;
}

void print()
{
	NODE *var=top;
	if(var!=NULL)
	{
		while(var!=NULL)

		{
			printf("%c ",var->data);
			var=var->next;
		}
		printf("\n");

	}
	else
	{
		printf("Empty Stack\n");
	}
	return;
}




int prec(char op)
{
	switch(op)
	{
		case '%':return 2;
		case '/':return 2;
		case '*':return 2;
		case '+':return 1;
		case '-':return 1;
		case '^':return 3;
		default:return 0;
	}
}
int main()
{
	char s[100],r[100];
	scanf("%s",s);
	int i=0,j=0;
	while(s[i]!='\0')
	{
		if(prec(s[i])==0)
		{
			r[j++]=s[i];
		}
		else if(prec(s[i])==3)
		{
			
			
			push(s[i]);
			
			
		}
		else
		{
			if( top==NULL || prec(s[i])>prec(top->data) )
			{
				push(s[i]);
			}
			else
			{
				r[j++]=top->data;
				pop(top);
				push(s[i]);
			}
		}	

		i++;
	}
	for(i=0;i<j;i++)
	{
		printf("%c ",r[i]);
	}
	
	print() ;



	return 0;
}
