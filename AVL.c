#include<stdio.h>
#include<stdlib.h>
#define FALSE 0
#define TRUE 1
typedef struct node
{
	int d;
	struct node *l,*r;
	int balance;
}NODE;



NODE* RotateRight(NODE* parent)
{
	NODE* aptr;
	aptr=parent->l;
	parent->l=aptr->r;
	aptr->r=parent;
	return aptr;
}


NODE *insert_RightBalance (NODE* p);
NODE* RotateLeft(NODE *parent)
{
	NODE *aptr;
	aptr=parent->r;
	parent->r=aptr->l;
	aptr->l=parent;
	
	return aptr;

}

NODE *insert_LeftBalance(NODE* p)
{
	NODE *a,*b;
	a=p->l;
	if(a->balance==1)
	{
		p->balance=0;
		a->balance=0;
		p=RotateRight(p);
	}
	else 
	{
		b=a->r;
		switch(b->balance)
		{
			case -1:
				p->balance= 0;
				a->balance=1;
				break;
			case 1:
				p->balance= -1;
				a->balance = 0;
				break;
			case 0:
				p->balance= 0;
				a->balance= 0;
				break;
		}
		b->balance=0;
		p->l=RotateLeft(a);
		p= RotateRight(p);


	}
	return p;
	
}
NODE *insert_left_check(NODE*  pptr,int *ptaller)
{
	switch(pptr->balance)
	{
		case 0:
			pptr->balance=1;
			break;

		case -1: 
			pptr->balance=0;
			
			*ptaller=FALSE;
			break;
		case 1: 
			pptr=insert_LeftBalance(pptr);
			*ptaller=FALSE;
	}
	return pptr;
	
}

NODE *insert_right_check(NODE *p,int *ptaller)
{
	switch (p->balance)
	{
		case 0:
			p->balance = -1;
			break;
		case 1:
			p->balance = 0;
			*ptaller=FALSE;
			break;
		case -1:
			p = insert_RightBalance(p);
			*ptaller= FALSE ;
	}
	return p;

}

NODE *insert_RightBalance(NODE *p)
{
	struct node *a,*b;
	a= p->r;
	if(a->balance==-1)
	{
		p->balance=0;
		a->balance=0;
		p=RotateLeft(p);
	}
	else 
	{
		b=a->l;
		switch(b->balance)
		{
			case -1:
				p->balance = 1;
				a->balance = 0;
				break;
			case 1:
				p->balance= 0 ;
				a->balance=-1;
				break;
			case 0:
				p->balance= 0;
				a->balance=0;
		}
		b->balance=0;
		p->r=RotateRight(a);
		p=RotateLeft(p);
	}
	return p;
	
}



NODE* insert(NODE *root,int data)
{
	static int taller;
	if(root == NULL)
	{
		root=malloc(sizeof(NODE));
		root->d=data;
		root->l=NULL;
		root->r=NULL;
		root->balance= 0;
		taller= TRUE;

	}
	else if(data < root->d)
	{
		root->l=insert(root->l,data);
		if(taller==TRUE)
		{
			root= insert_left_check(root,&taller);

		}
	}

	else if(data > root->d)
	{
		root->r=insert(root->r,data);
		if(taller==TRUE)
			root= insert_right_check(root,&taller);

	}
	else
	{
		taller=FALSE;
	}
	return root;
	
}

NODE *del_LeftBalance(NODE *p, int *pshorter)
{
	struct node *a,*b;
	a= p->l;
	if(a->balance==0)
	{
		p->balance=1;
		a->balance=-1;
		*pshorter=FALSE;
		p=RotateRight(p);
	}
	else if(a->balance==1)
	{
		p->balance=0;
		a->balance=0;
		p=RotateRight(p);
	}
	
	else 

	{
		b=a->r;
		switch(b->balance)
		{
			case -1:
				p->balance = 0;
				a->balance = 1;
				break;
			case 1:
				p->balance= -1;
				a->balance=0;
				break;
			case 0:
				p->balance= 0;
				a->balance=0;
		}
		b->balance=0;
		p->l=RotateLeft(a);
		p=RotateRight(p);
	}
	return p;
	
}

NODE *del_RightBalance(NODE *p, int *pshorter)
{
	struct node *a,*b;
	a= p->r;
	if(a->balance==0)
	{
		p->balance=-1;
		a->balance=1;
		*pshorter=FALSE;
		p=RotateLeft(p);
	}
	else if(a->balance==-1)
	{
		p->balance=0;
		a->balance=0;
		p=RotateLeft(p);
	}
	
	else 

	{
		b=a->l;
		switch(b->balance)
		{
			case -1:
				p->balance = 1;
				a->balance = 0;
				break;
			case 1:
				p->balance= 0;
				a->balance=-1;
				break;
			case 0:
				p->balance= 0;
				a->balance=0;
		}
		b->balance=0;
		p->r=RotateRight(a);
		p=RotateLeft(p);
	}
	return p;
	
}





NODE *del_right_check(NODE* p, int *pshorter)
{
	switch (p->balance)
	{
		case 0:
			p->balance = 1;
			*pshorter= FALSE;
			break;
		case -1:
			p->balance = 0;
			
			break;
		case 1:
			p = del_LeftBalance(p,pshorter);
			
	}
	return p;
}



NODE *del_left_check(NODE* p, int *pshorter)
{
	switch (p->balance)
	{
		case 0:
			p->balance = -1;
			*pshorter= FALSE; 
			break;
		case 1:
			p->balance = 0;
			
			break;
		case -1:
			p = del_RightBalance(p,pshorter);
			
	}
	return p;
}


NODE *del(NODE *p,int dkey)
{
	NODE *tmp,*succ;
	static int shorter;
	if (p==NULL)
	{
		shorter=FALSE;
		return p;
	}

	if(dkey<p->d)
	{
		p->l=del(p->l,dkey);
		if(shorter==TRUE)
			p=del_left_check(p,&shorter);
	}
	else if(dkey> p->d)
	{
		p->r=del(p->r,dkey);
		if(shorter==TRUE)
			p=del_right_check(p,&shorter);
	}
	else
	{
		if(p->l!=NULL && p->r!=NULL)
		{
			succ=p->r;
			while(succ->l)
				succ=succ->l;
			p->d=succ->d;
			p->r=del(p->r,succ->d);
			if(shorter==TRUE)
				p=del_right_check(p,&shorter);
		}
		else
		{
			tmp=p;
			if(p->l!=NULL)
				p=p->l;
			else if(p->r !=NULL)
				p=p->r;
			else
				p=NULL;
			free(tmp);
			shorter =TRUE;
		}
	}
	return p;


	

}



int a[1000000];
int i=0;
void printtree(NODE *root)
{
	if (root==NULL)
	{
		return;
	}
	a[i++]=root->d;
	printtree(root->l);
	printtree(root->r);
}
int main()
{
	int test;
	scanf("%d",&test);
	while(test>0)
	{
		int lines;
		NODE *root;
		root = NULL;
		scanf("%d",&lines);
		while(lines>0)
		{


		//	printf("%d",lines);
			char query;
			int operand;
			scanf("%*c%c", &query);
			if(query=='d')
			{
				scanf("%d",&operand);
				root=del(root,operand);
			}
			else if(query=='i')
			{
				scanf("%d",&operand);
				root=insert(root,operand);
			}
			else if(query=='p')
			{
				printtree(root);
				int j;
				if(root!=NULL)
				{for(j=0;j<i-1;j++)
				{
					printf("%d ",a[j]);

				}
				printf("%d",a[j]);}
				i=0;
				printf("\n");
			}
			else
			{
				printf("wrong");
			}
			lines--;

		}
		free(root);
		test--;
	
	}
}
