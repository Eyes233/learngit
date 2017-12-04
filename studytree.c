#include<stdio.h>
#include<stdlib.h>
struct BiTree
{
	char date;
	BiTree * lc;
	BiTree * rc;
};


BiTree * CreatBiTree()
{
	char ch;
	BiTree *tmp=NULL;
	ch=getchar();
	if (ch==' ') 
	{
		;
	}
	else
	{
		tmp = (BiTree *)malloc(sizeof(BiTree)); 
		tmp->date = ch;
		tmp->lc=CreatBiTree();
		tmp->rc=CreatBiTree();
	}
	return tmp;
}


void preordertraversal(BiTree *T)
{
	if (T)
	{
		printf("%c  ", T->date);
		preordertraversal(T->lc);
		preordertraversal(T->rc);
	}
	
}

void inordertraversal(BiTree *T)
{
	if (T)
	{
		inordertraversal(T->lc);
		printf("%c  ", T->date);
		inordertraversal(T->rc);
	}
}
void postorderTraversal(BiTree *T)
{
	if (T)
	{
		
		postorderTraversal(T->lc);
		postorderTraversal(T->rc);
		printf("%c  ", T->date);
	}

}

int TreeHigh(BiTree *T)
{
	int x=0, y=0;

		if (T == NULL) return 0;
		x = TreeHigh(T->lc);
		y = TreeHigh(T->rc);
		if (x > y) return (x +1);
			return (y+1);
	
}

void SumNumLeaf(BiTree *T,int &s)
{
	
	if (T)
	{
		SumNumLeaf(T->lc, s);
		SumNumLeaf(T->rc, s);
		if (T->lc == NULL&&T->rc == NULL)
		{
			s++;
		}
	}
}



int main()
{
	BiTree *T=NULL;
	T=CreatBiTree();
/*	preordertraversal(T);
	printf("\n");
	inordertraversal(T);
	printf("\n");
	postorderTraversal(T);
	printf("\n");*/
	int x = 0;
	//SumNumLeaf(T, x);
	x=TreeHigh(T);
	printf("%d",x );
	
}
