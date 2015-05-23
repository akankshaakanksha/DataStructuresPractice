#include<stdio.h>
#include<stdlib.h>
typedef struct TreeNode 
{
	int data;
	struct TreeNode *lchild,*rchild;
	int height;

}TNode;
int heightcounter=1;

TNode *Insert(TNode *root,int data )
{
	if (root==NULL)
		
	{
		TNode* temp;	
		temp=(TNode*)malloc(sizeof(TNode));
		temp->lchild=NULL;
		temp->rchild=NULL;
		temp->data=data;
		temp->height=heightcounter;
		root=temp;
		return root;
	}

	else if(root->data > data)
	{
		heightcounter++;
		root->lchild=Insert((root->lchild),data);
		return root;
			
	}
	else
	{
		heightcounter++;
		root->rchild=Insert((root->rchild),data);
		return root;
	}
}
int a[1000000];
int counter=0;
void printGivenLevel(TNode* root, int level)
{
	if(root == NULL)
		return;
	if(level == 1)
		a[counter++]=root->data;
		
	else if (level > 1)
	{
		printGivenLevel(root->lchild, level-1);
		printGivenLevel(root->rchild, level-1);
	}
}


void printtree(TNode *root)
{
	if(root==NULL)
	{
		return;
	}
	printf("VAl:%d\nHt: %d\n ",root->data,root->height);
	printtree(root->lchild);
	printtree(root->rchild);

}
void printLOTest(TNode* root,int height)
{
		
	printGivenLevel(root,height);
	a[counter]=-1;
	counter=0;
	int i;	
	/*for(i=0;a[i]!=-1;i++)
	{
		printf("%d ",a[i]);
	}
	printf("\n");*/
}

TNode* find(int val,TNode *root)
{
	if (root==NULL)
	{
		return NULL;
	}
	if (root->data==val)
	{
		return root;
	}
	else if(root->data > val)
	{
		return (find(val,root->lchild));

	}
	else if(root->data < val)
	{
		return(find(val,root->rchild));
	}

}

int checkIRnode(int rnode)
{
	int i=0;
	while(a[i]!=rnode && a[i]!=-1)
	{
		i++;
	}
	return a[++i];
	
}

int counterfork=0;
int klist[1000000];
void makeklist(TNode *root)
{
	
	if(root==NULL)
	{
		return;
	}
	makeklist(root->lchild);
	klist[counterfork++]=root->data;
	makeklist(root->rchild);

}


int main ()
{
	int Test;
	scanf("%d",&Test);
	while(Test)
	{
		
		TNode *root;
		root=NULL;
		int NTreeElement,i, TreeElement;
		scanf("%d",&NTreeElement);
		/*Inserting in a BST*/
		for(i=0;i<NTreeElement;i++)
		{
			scanf("%d",&TreeElement);
			root=Insert(root,TreeElement);
			heightcounter=1;
		}

		int mynode,k;
		scanf("%d%d",&mynode,&k);

		/*Find and return the node of right immediate right node*/

		int HeightReq;
		TNode *NodeReq;
		NodeReq=find(mynode,root);
		if(NodeReq) 
			HeightReq=NodeReq->height;
		else
			HeightReq=-1;
		// printf("The height of %d is :%d\n",mynode,HeightReq);

		//printf("The height I am printing at is: %d\n\n",HeightReq);
		printLOTest(root,HeightReq);
		/* (i=0;a[i]!=-1;i++)
		{
			printf("%d ",a[i]);
		}
		printf("\n");
		*/
		
		
		
		
		int IRnode;
		TNode* TheSubTree;
		IRnode=checkIRnode(mynode);
		if(IRnode==-1 || HeightReq==-1)

		{
			printf("$ $\n");
			
		}
		else
		{
			printf("%d ",IRnode);
			
			TheSubTree=find(IRnode,root);
			makeklist(TheSubTree);
			klist[counterfork]=-1;
			counterfork=0;
			int found;
			//printf("The K-LIST \n");

			for(i=0;klist[i]!=-1 && i<k-1 ;i++)
			{
				continue;
				
			}
			int j;
			//for (j=0;j<15;j++)
			//	printf("%d ",klist[j]);
			//printf("\n");
			found=klist[i];

			if(found!=-1)
			{	
			  printf("%d\n",found );
			}
			else
			{
				printf("$\n");
			}

		}


	
	//printtree(root);



			
		
	
	 


		


		Test--;
	}
	return 0;

}
