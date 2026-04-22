#include<cstdio>
#include<cstdlib>
#include<cstdlib>

#define LH +1  
#define EH 0   
#define RH -1   
typedef struct NODE
{
	char data; 
	int bf; 
	struct NODE *lchild; 
	struct NODE *rchild;  
}BSnode, *BSTree;

void R_Rotate(BSTree *ptr)
{
	BSTree lc = (*ptr)->lchild;
	(*ptr)->lchild = lc->rchild; 
	lc->rchild = *ptr;
	*ptr = lc; 
}
void L_Rotate(BSTree *ptr)
{
	BSTree rc = (*ptr)->rchild;   
	(*ptr)->rchild = rc->lchild; 
	rc->lchild = *ptr;
	*ptr = rc;                  
}
void LeftBalance(BSTree *root)
{
	BSTree lc;
	BSTree rd;
	lc = (*root)->lchild; 
	switch (lc->bf)
	{
		case LH:
		{
			(*root)->bf = lc->bf = EH;
			R_Rotate(root);
			break;
		}
		case RH:
		{
			rd = lc->rchild;
			switch (rd->bf)
			{
				
				case LH:
				{
					(*root)->bf = RH;
					lc->bf = EH;
					break;
				}
				case EH:
				{
					(*root)->bf = lc->bf = EH;
					break;
				}
				case RH:
				{
					(*root)->bf = EH;
					lc->bf = LH;
					break;
				}
			}
			rd->bf = EH;
		
			L_Rotate(&(*root)->lchild);
		
			R_Rotate(root);
		}
	}
}
void RightBalance(BSTree *root)
{
	BSTree lc;
	BSTree rd;
	lc = (*root)->rchild;

	switch (lc->bf)
	{
		case RH:
		{
			(*root)->bf = lc->bf = EH;
			L_Rotate(root);
			break;
		}
		case LH:
		{
			rd = lc->lchild;
			switch (rd->bf)
			{
				case LH:
				{
					(*root)->bf = EH;
					lc->bf = RH;
					break;
				}
				case EH:
				{
					(*root)->bf = lc->bf = EH;
					break;
				}
				case RH:
				{
					(*root)->bf = LH;
					lc->bf = EH;
					break;
				}
			}
			rd->bf = EH;
			R_Rotate(&(*root)->rchild);
			L_Rotate(root);
		}
	}
}

int InsertAVL(BSTree *root, char e, bool *taller)
{
	if ((*root) == NULL)
	{
		(*root) = (BSTree)malloc(sizeof(BSnode));
		(*root)->bf = EH;
		(*root)->data = e;
		(*root)->lchild = NULL;
		(*root)->rchild = NULL;
		*taller = true;
	}
	else if (e == (*root)->data)
	{
		*taller = false;
		return 0;
	}
	else if (e < (*root)->data)
	{
		if (!InsertAVL(&(*root)->lchild, e, taller))
		{
			return 0;
		}
		
		if (*taller)
		{
			switch ((*root)->bf)
			{
				case LH:
				{
				
				
					LeftBalance(root);
					*taller = false;
					break;
				}
				case EH:
				{
					(*root)->bf = LH;
					*taller = true;
					break;
				}
			
				case RH:
				{
					(*root)->bf = EH;
					*taller = false;
					break;
				}
			}
		}
	}
	else
	{
		
		if (!InsertAVL(&(*root)->rchild, e, taller))
		{
			return 0;
		}
		
		if (*taller)
		{
			switch ((*root)->bf)
			{
				case LH:
				{
				
					(*root)->bf = EH;
					*taller = false;
					break;
				}
				case EH:
				{
					
					(*root)->bf = RH;
					*taller = true;
					break;
				}
				case RH:
				{
					
					RightBalance(root);
					*taller = false;
					break;
				}
			}
		}
	}
	return 1;
}
void printBIT(BSTree root, int x)
{
	if (root != NULL)
	{
		printBIT(root->rchild, x + 1);
		for (int i = 0; i < x; i++)
			printf("    ");
		printf("%c\n", root->data);
		printBIT(root->lchild, x + 1);
	}
}
void preorder(BSTree root)
{
	if (root != NULL)
	{
		printf("%c", root->data);
		preorder(root->lchild);
		preorder(root->rchild);
	}
}
void inorder(BSTree root)
{
	if (root != NULL)
	{
		inorder(root->lchild);
		printf("%c", root->data);
		inorder(root->rchild);
	}
}
void postorder(BSTree root)
{
	if (root != NULL)
	{
		postorder(root->lchild);
		postorder(root->rchild);
		printf("%c", root->data);
	}
}
int main()
{
	char e;
	bool taller;
	BSTree root = NULL;

	while (e = getchar())
	{
		if (e == '\n')
			break;
		InsertAVL(&root, e, &taller);
	}
	printf("Preorder: ");
	preorder(root);
	printf("\n");
	printf("Inorder: ");
	inorder(root);
	printf("\n");
	printf("Postorder: ");
	postorder(root);
	printf("\n");
	
	printf("Tree:\n");
	printBIT(root, 0);
	return 0;
}
