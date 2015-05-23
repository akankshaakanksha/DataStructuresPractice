#include<stdio.h>
int main()
{
	int t,n,a,b;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d%d",&n,&a,&b);
		while(a!=b)
		{
			if(a>b)
			{
				a=a/2;
				continue;
			}
			else
			{
				b=b/2;
				continue;
			}
			
		}
		printf("%d\n",b);
	}
}
