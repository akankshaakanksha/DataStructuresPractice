#include<stdio.h>
#include<stdlib.h>
#define VISITED 1
#define NOTVISI 0

typedef struct node{
	int dat;
}node;

void foo(node q)
{
	q.dat=2;

}

void foo2(node q,node r)
{
	q.dat=5;
	r.dat=q.dat;

}


int visited[100000],b[100000],c,f;
int large(int** a,int n)
{
	int i,j,max,len;
	for(i=0;i<n;++i)
	{
		visited[i] = NOTVISI;
		b[i] = 0;
	}
	c = -1;
	f = 0;
	bfs(0,n,a);
	for(i=0;i<n;++i)
		if(visited[i] != NOTVISI)
			len++;
	max = len;
	for(i=1;i<n;++i)
	{
		if(visited[i] == NOTVISI)
		{
			c = -1;
			f = 0;
			for(j=0;j<n;++j)
			{
				visited[j] =NOTVISI;
				b[j] = 0;
			}
			len = 0;
			node r;
			foo(r);
			bfs(i,n,a);
			for(j=0;j<n;++j)
				if(visited[j] != NOTVISI)
					len++;
			if(len > max)
				max = len;
		}
		node q;
		foo(q);
	}
	return max;
}
void bfs(int v,int n,int** a)
{
	int i;
	for(i=0;i<n;++i)
		if(a[v][i] != 0 && visited[i] == NOTVISI)
			b[++c] = i;
	if(f <= c)
	{
		visited[b[f]] = VISITED;
		bfs(b[f++],n,a);
	}
	node q,r;

	foo2(q,r);
	return;
}
int main()
{
	int t,i;
	scanf("%d",&t);
	for(i=1;i<=t;++i)
	{
		int n,j,k,len;
		scanf("%d",&n);
		int** a = (int**)malloc(n*sizeof(int*));
		for(j=0;j<n;++j)
		{
			a[j] = (int*)malloc(n*sizeof(int));
			for(k=0;k<n;++k)
				scanf("%d",&a[j][k]);
		}
		len = large(a,n);
		printf("%d\n",len);
	}
	return 0;
}
