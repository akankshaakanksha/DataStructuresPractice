#include<stdio.h>
#include<stdlib.h>
typedef struct node{
	int data;
	struct node *left;
	struct node *ryt;
	struct node *parent;
}node;

void insert(int data,node *tree)
{
	if(tree)
	{
		if(tree->data < data)
		{
			if(tree->ryt==NULL)
			{

				tree->ryt=(node*)malloc(sizeof(node));
				tree->ryt->data=data;
				tree->ryt->ryt=NULL;
				tree->ryt->left=NULL;
				tree->ryt->parent=tree;
			}
			else
			insert(data,tree->ryt);
		}
		if(tree->data>data)
		{
			if(tree->left==NULL)
			{
				tree->left=(node*)malloc(sizeof(node));
				tree->left->data=data;
				tree->left->ryt=NULL;
				tree->left->left=NULL;
					tree->left->parent=tree;		}
			else
			insert(data,tree->left);
		}
	}

}
void printpre(node* tree)
{if(tree){
	printf(" %d ",tree->data);

	if(tree->left)
	{
		printpre(tree->left);
	}	

	if(tree->ryt)
		printpre(tree->ryt); 

		 }
}


void post(node *tree)
{if(tree){
	
	if(tree->left)
	{
		post(tree->left);
	}	

	if(tree->ryt)
		post(tree->ryt); 

		 }
printf(" %d ",tree->data);

}



void print(node * tree)
{
	if(tree->left)
	{
		print(tree->left);
	//	printf("%d",tree->data);
	}
	printf(" %d ",tree->data);
		
	if(tree->ryt)	
		print(tree->ryt);
	
//	printf(" %d ",tree->data);
}

node* find(node* tree ,int data)
{
	if(tree)
	{
		if(tree->data >data)
			return find(tree->left,data);
		else if(tree->data < data)
			return find(tree->ryt,data);
		else return tree;
	}
	return NULL;
}


void del(node *tree,int data)
{
	if(tree)
	{
		if(tree->data>data)
			del(tree->left,data);
		else if(tree->data<data)
			del(tree->ryt,data);
		else if(tree->data==data)
		{
			node *ek=tree;
			if(tree->left==NULL)
			{
				node *k=tree;
				if(tree->data > tree->parent->data)
					tree->parent->ryt=tree->ryt;

				else
					tree->parent->left=tree->ryt;
				free(k);
			}
			else if(tree->ryt==NULL)
			{
				node *k=tree;

				if(tree->data > tree->parent->data)
					tree->parent->ryt=tree->left;

				else
					tree->parent->left=tree->left;
				
				free(k);
			}
			else
			{
				if(tree->ryt->left==NULL)
				{	node *k=tree;

					if(tree->data > tree->parent->data)
	
					tree->parent->ryt->ryt->left=tree->ryt;

					else
						tree->parent->left->ryt->left=tree->ryt;

								

					free(k);
				}
				else
				{
					tree=tree->ryt;
					while(tree->left->left)
						tree=tree->left;
					ek->data=tree->left->data;
					node *k=tree->left;
					tree->left=NULL;
						free(k);
				
				}
			}
			printf("yes\n");
		}

	}

	else printf("no\n");
}


int  main()
{
	int i,n,data;
	scanf("%d",&n);
	scanf("%d",&data);
	node* tree=(node*)malloc(sizeof(node));
	tree->data=data;
	tree->left=NULL;
	tree->ryt=NULL;
	tree->parent=NULL;
	while(--n)
	{
		scanf("%d",&data);
		insert(data,tree);
	}
printf("inorder\n          ");

	print(tree);

	printf("\npre\n        ");
	printpre(tree);

	printf("\npost\n          ");
	post(tree);



	printf("\nfind : ");
	scanf("%d",&n);
	while(n--)
	{
		scanf("%d",&i);
		node *s= find(tree,i);
		if(s)
			printf("yes\n");
		else printf("no\n");
	}
	printf("\ndel : ");
	scanf("%d",&n);
	while(n--)
	{
		scanf("%d",&i);
		del(tree,i);
	}

	print(tree);
	return 0;
}

