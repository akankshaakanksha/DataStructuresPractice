#include<stdio.h>
#include<stdlib.h>
#include<math.h>
typedef struct node
{
	int d;
	struct node* next;
}NODE;

void push(NODE **top,int val)
{
	NODE *temp;
	temp=malloc(sizeof(NODE));
	temp->d=val;
	temp->next=(*top);
	*top=temp;
	return;

}

char pop(NODE **top)
{
	int popitem;
	popitem=(*top)->d;
	NODE *temp;
	temp=*top;
	*top=(*top)->next;
	free(temp);
	return popitem;

}

int calc(int op1,char opr,int op2)
{
	int r;
	if(opr=='+')
	{
		r=op1+op2;
	}
	if(opr=='-')
	{
		r=op1-op2;
	}
	if(opr=='*')
	{
		r=op1*op2;
	}
	if(opr=='/')
	{
		r=op1/op2;
	}
	if(opr=='^')
	{
		r=(int)pow(op1,op2);
		
	}
	return r;
}
int isop(char a)
{
	switch(a)
	{
		case'/':return 1;
		case'+':return 2;
		case'-':return 2;
		case'*':return 3;
		case'^':return 3;
		default:return 0;

	}

}



int main()
{
	int t,i;
	char s[1000];
	scanf("%d",&t);
	NODE *top;
	top=NULL;
	while(t>0)
	{
		int flag=0;
		scanf("%s",s);
		i=0;
		int oprand=0,oprator=0;
		while(s[i]!='\0')
		{
			if(s[i]<='9' && s[i]>='0')
			{
				oprand++;
			}
			else if(isop(s[i]))
			{
				oprator++;
			}
			else
			{
			//	printf("invalid\n");
				flag=1;
				break;
			}
			i++;

		}
		if(isop(s[i-1]) || oprator!=oprand-1 || flag==1)
		{
			printf("invalid\n");
			t--;
			continue;
		}

		int end=i-1;
	
		int operand1,operand2,ans;
		for(i=end;i>=0;i--)
		{
			
			if(s[i]<='9' && s[i]>='0')
			{
				push(&top,(int)s[i]-48);
			}
			else if (isop(s[i]))
			{
				operand1=pop(&top);
				operand2=pop(&top);
				if(isop(s[i])==1 && operand2==0)
				{
					flag=1;
					break;
				}
				ans=calc(operand1,s[i],operand2);
				push(&top,ans);
			}
			
		}
		if(flag==1)
		{
			printf("invalid\n");
			t--;
			continue;
		}
		printf("%d\n",top->d);		
		
		t--;
	}
	return 0;

}
