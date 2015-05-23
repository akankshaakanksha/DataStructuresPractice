#include<stdio.h>
#include<stdlib.h>

typedef struct term
{
	int exp;
	int coef;
	struct term* next;
}TERM;

void print(TERM *pol);
void delete(TERM **pol,int exp)
{
	TERM *temp;
	temp=*pol;
	if(temp->exp==exp)
	{
		*pol=temp->next;
		free(temp);
		return;
	}
	while(temp->next!=NULL)
	{
		if(temp->next->exp==exp)
		{
			TERM *dum;
			dum=temp->next;
			temp->next=temp->next->next;
			free(dum);
		}
		return;

	}
}
void srtinsrt(TERM** pol,int exp,int coef)
{
	if(*pol==NULL || (*pol)->exp<=exp)
	{
		TERM *temp;
		temp=(TERM*)malloc(sizeof(TERM));
		temp->exp=exp;
		temp->coef=coef;
		temp->next=*pol;
		*pol=temp;
	}

	else
	{
		TERM *temp;
		temp=*pol;
		while(temp->next!=NULL && temp->next->exp>exp)
		{

			temp=temp->next;
		}
		TERM *new;
		new=(TERM*)malloc(sizeof(TERM));
		new->exp=exp;
		new->coef=coef;
		new->next=temp->next;
		temp->next=new;
	}
	return;			
}



void insrt(TERM **pol,int exp,int coef)
{
	if(*pol==NULL || (*pol)->exp<exp)
	{
		TERM *temp;
		temp=(TERM*)malloc(sizeof(TERM));
		temp->exp=exp;
		temp->coef=coef;
		temp->next=*pol;
		*pol=temp;
		return;
	}
	
	if((*pol)->exp==exp)
	{
		(*pol)->coef=((*pol)->coef)+coef;
		return;

	}

	else
	{
		TERM *temp;
		temp=*pol;
		while(temp->next!=NULL)
		{
			if(temp->next->exp>exp)
			{
				temp=temp->next;
			}
			else if(temp->next->exp==exp)
			{
				temp->next->coef=temp->next->coef+coef;
				return;

			}
			else
				break;

			
		}
		TERM *new;
		new=malloc(sizeof(TERM));
		new->exp=exp;
		new->coef=coef;
		new->next=temp->next;
		temp->next=new;
		return;

	}

}




int search(TERM *pol,int exp)
{
	int rcoef;
	while(pol!=NULL)
	{
		if(pol->exp==exp)
		{
			rcoef=pol->coef;
			return rcoef;
		}
		pol=pol->next;

	}
	if(pol==NULL)
		return 0;

}

void add(TERM *pol1,TERM *pol2,TERM **resA)
{
	TERM *tem1,*tem2;
	tem1=pol1;
	tem2=pol2;
	int ncoef,nexp;
	TERM *nterm;
	while(tem1!=NULL)
	{
		int coef2=search(tem2,tem1->exp);
		if(coef2)
		{
			ncoef=tem1->coef+coef2;
			delete(&tem2,tem1->exp);
		}
		else
		{
			ncoef=tem1->coef;
		}
		nexp=tem1->exp;
		if(ncoef)
		{
		
			srtinsrt(resA,nexp,ncoef);
		}

		tem1=tem1->next;
	}
	while(tem2!=NULL)
	{
		srtinsrt(resA,tem2->exp,tem2->coef);
		tem2=tem2->next;
	}



}
void sub(TERM *pol1,TERM *pol2,TERM **resS)
{
	TERM *tem1,*tem2;
	tem1=pol1;
	tem2=pol2;
	int ncoef,nexp;
	TERM *nterm;
	while(tem1!=NULL)
	{
		int coef2=search(tem2,tem1->exp);
		if(coef2)
		{
			ncoef=(tem1->coef)-(coef2);
			delete(&tem2,tem1->exp);	

		}
		else
		{
			ncoef=tem1->coef;
		}
		nexp=tem1->exp;
		if(ncoef)
		{
		      srtinsrt(resS,nexp,ncoef);
		}

		tem1=tem1->next;
	}
	while(tem2!=NULL)
	{
		srtinsrt(resS,tem2->exp,-1*tem2->coef);
		tem2=tem2->next;
	}



}


void mult(TERM *pol1,TERM *pol2,TERM **resM)
{
	TERM *tem1,*tem2;
	tem1=pol1;
	tem2=pol2;
	int ncoef,nexp;
//	printf("\nInitial value : ");
//	print(tem2);
	while(tem1!=NULL)
	{       tem2 = pol2;
		while(tem2!=NULL)
		{	
			
			ncoef=(tem1->coef)*(tem2->coef);
			nexp=(tem1->exp)+(tem2->exp);
			insrt(resM,nexp,ncoef);
//			printf("\nTem1 is : ");
//			print(tem1);
//			printf("\nTem2 is : ");
//			print(tem2);
//			printf("\nAnswer is : ");
//			print(*resM);
			tem2=tem2->next;
		}
		tem1=tem1->next;
	}
	


}





void print(TERM *pol)
{
	TERM *temp;
	temp=pol;
	while(temp->next!=NULL)
	{
		printf("%d %d\n",temp->exp,temp->coef);
		temp=temp->next;
	}
	printf("%d %d\n",temp->exp,temp->coef);
	return;

}

void prntlen(TERM *pol)
{
	TERM *temp;
	temp=pol;
	int i=1;
	while(temp->next!=NULL)
	{
		temp=temp->next;
		i++;
	}
	printf("%d\n",i);
}
int main()
{

	int t,op,i,j,N,M;
	scanf("%d",&t);

	while(t>0)
	{

		TERM *pol1,*pol1A,*pol1B,*pol2A,*pol2B;
		TERM *pol2;
		TERM *resA;
		TERM *resS;
		TERM *resM;
		pol1=NULL;
		pol2=NULL;
		pol1A=NULL;
		pol1B=NULL;
		pol2A=NULL;
		pol2B=NULL;
		resA=NULL;
		resS=NULL;
		resM=NULL;
		scanf("%d%d",&M,&N);
		while(M--)
		{
			int exp,coef;
			scanf("%d%d",&exp,&coef);
			srtinsrt(&pol1,exp,coef);
			srtinsrt(&pol1A,exp,coef);
			srtinsrt(&pol1B,exp,coef);


		}
	
		while(N--)
		{
			int exp,coef;
			scanf("%d%d",&exp,&coef);
			srtinsrt(&pol2,exp,coef);
			srtinsrt(&pol2A,exp,coef);
			srtinsrt(&pol2B,exp,coef);
		}

		
//		print(pol1);
/*		print(pol2);

		printf("%d\n%d\n%d\n",search(pol1,2),search(pol2,3),search(pol1,4));

		delete(&pol1,3);
		delete(&pol2,4);

		print(pol1);
		print(pol2);



		TERM *found;
*		found=search(&pol1,3);
*		if(found!=NULL)
*		{
*			print(found);
*
*		}
*		else
*			printf("NO");
*		
*/

		
		
		//prntlen(pol1);
		/*Addition*/
		add(pol1,pol2,&resA);
		prntlen(resA);
		print(resA);
		/*Subtraction*/
		sub(pol1A,pol2A,&resS);
		prntlen(resS);
		print(resS);
		/*Multiplication*/
		mult(pol1B,pol2B,&resM);
		prntlen(resM);
		print(resM);

		t--;
	}
	return 0;

}
