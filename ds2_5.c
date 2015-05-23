#include<stdio.h>
#include<stdlib.h>


typedef struct node {
	int v;
	struct node *ptr;
}nod;

nod *s;
nod* srt(int val)
{

	nod *y;
	y=s;
	nod *temp=(nod *)malloc(sizeof(nod));
	temp->v=val;
	if((s->v)>val)
	{
		temp->ptr=s;
		return temp;
	}
	if(s->ptr == NULL)
	{
		s->ptr = temp;
		temp->ptr=NULL;
		return y;
	}
	while(s->ptr!=NULL)
	{
		if((s->ptr->v) < val)
			s=s->ptr;
		else 
			break;

	}
	temp->ptr=s->ptr;
	s->ptr=temp;
	return y;
}


/*nod * del(nod* s,int val)
{
	nod *y;
	y=s;
	if(s->v==val)
	{
		s=s->ptr;
		return s;
	}


	while(s->ptr->ptr!=NULL&&(s->ptr->v != val))
	{
		s=s->ptr ;
	}
	if (s->ptr->ptr==NULL && s->ptr->v == val)
	{

		s->ptr=NULL;
		return y;
	}

	if(s->ptr->v==val)
		s->ptr=s->ptr->ptr;

	return y;
}


*/
int k;
nod *t;
void del()
{
	int i=k-1;
if(k>1)	while(--i && i)
	{
		if(t!=NULL)
		{
			if(t->ptr!=NULL)
			{
				t=t->ptr;
			}
			else
			{
				t=s;
			}
		}

	}
	if(t->ptr!=NULL)
	{
		if(t->ptr->ptr!=NULL)
		{
			nod *k=t->ptr;
			t->ptr=t->ptr->ptr;
			free(k);
			t=t->ptr;
		}
		else
		{
			nod *k=t->ptr;
			t->ptr=NULL;
			free(k);
			t=s;

			
		}
	}
	else
	{
		nod *k=s;
		s=s->ptr;
		t=s;
		free(k);
	}



}




	


print(nod *s)
{
	while(s!=NULL)
	{
		printf("%d  ",s->v);
		s=s->ptr;
	}
	printf("\n");

}

int main()
{
	int n,j;
	s=(nod *)malloc(sizeof(nod));
	int r=0;

	while(~(scanf("%d",&r)))
	{	j=r;
	scanf("%d",&n);
	s->v=n;
	s->ptr=NULL;
	
	while(--r)
	{
		
		
		scanf("%d",&n);
		s=srt(n);
//		print(s);
//		printf("\n");
		
	}
	
	scanf("%d",&k);
	if(k==1)
	{
		while(s->ptr!=NULL)
			s=s->ptr;
		printf("%d\n",s->v);
	}

	else{
		t=s;
		while(--j)
	{
		del();
	}

	printf("%d\n",t->v);

	}

	
/*	while(~scanf("%d",&n))
	{
		if(s==NULL|| (s->ptr==NULL&&s->v==n))
		{
			printf("NULL\n");
			s=NULL;
		}

		else if (s->ptr==NULL && s->v != n)
			print(s);

		else 
		{
			s=del (s,n);
			print(s);
//			printf("\n");
		}
	}


*/
	}
	return 0;
}


