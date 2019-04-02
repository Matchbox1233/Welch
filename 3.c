#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
typedef struct node{
	char c;
	struct node* left;
	struct node* right;
} Node;

Node* fa;
Node gyoker;

#define null NULL

Node* create_empty()
{
	Node* tmp = &gyoker;
	tmp->c= '/';
	tmp->left = null;
	tmp->right = null;
	return tmp;
}

Node* create_node(char val)
{
	Node* tmp = (Node*)malloc(sizeof(Node));
	tmp->c=val;
	tmp->left = null;
	tmp->right = null;
	return tmp;
}

void insert_tree(char val)
{
	if(val=='0')
	{
		if(fa->left == null)
		{
			fa->left = create_node(val);
			fa = &gyoker;
			//printf("Inserted into left.");
		}
		else
		{
			fa = fa->left;
		}
	}
	else
	{
		if(fa->right == null)
		{
			fa->right = create_node(val);
			fa = &gyoker;
			//printf("Inserted into left.");
		}
		else
		{
			fa = fa->right;
		}
	}
}

void inorder(Node* elem,int depth)
{

	if(elem==null)
	{
		return;
	}
	inorder(elem->left,depth+1);
	if(depth) 
	{
		char *spaces;
		spaces =(char*) malloc(sizeof(char)*depth*2+1);
		for(int i=0;i<depth;i+=2)
		{
			spaces[i]='-';
			spaces[i+1]='-';
		}
		spaces[depth]='\0';

		printf("%s%c\n",spaces,elem->c);
	}
	else
	{
		printf("%c\n",elem->c);
	}
	inorder(elem->right,depth+1);
}

void preorder(Node* elem,int depth)
{
	if(elem==null)
	{
		return;
	}
	if(depth) 
	{
		char *spaces;
		spaces =(char*) malloc(sizeof(char)*depth*2+1);
		for(int i=0;i<depth;i+=2)
		{
			spaces[i]='-';
			spaces[i+1]='-';
		}
		spaces[depth*2]='\0';

		printf("%s%c\n",spaces,elem->c);
	}
	else
	{
		printf("%c\n",elem->c);
	}
	preorder(elem->left,depth+1);	
	preorder(elem->right,depth+1);
}
void postorder(Node* elem,int depth)
{
	if(elem==null)
	{
		return;
	}
	postorder(elem->left,depth+1);	
	postorder(elem->right,depth+1);
	if(depth) 
	{
		char *spaces;
		spaces =(char*) malloc(sizeof(char)*depth*2+1);
		for(int i=0;i<depth;i+=2)
		{
			spaces[i]='-';
			spaces[i+1]='-';
		}
		spaces[depth*2]='\0';

		printf("%s%c\n",spaces,elem->c);
		free(spaces);
	}
	else
	{
		printf("%c\n",elem->c);
	}
}

void destroy_tree(Node* elem)
{
	if(elem==null)
	{
		return;
	}
	destroy_tree(elem->left);
	destroy_tree(elem->right);
	if(elem->c == gyoker.c)
	{

	}
	else
	{
		free(elem);
	}
}

void usage()
{
	printf("Használat: ./binfa KAPCSOLÓ\n");
	printf("Az KAPCSOLÓ lehet:\n");
	printf("--preorder\tA bináris fa preorder bejárása\n");
	printf("--inorder\tA bináris fa inorder bejárása\n");
	printf("--postorder\tA bináris fa postorder bejárása\n");
}

int main(int argc, char** argv)
{
	srand(time(null));
	fa = create_empty();
	//gyoker = *fa;
	for(int i=0;i<10000;i++)
	{
		int x=rand()%2;
		if(x)
		{
			insert_tree('1');
		}
		else
		{
			insert_tree('0');
		}
	}
	if(argc == 2)
	{
		if(strcmp(argv[1],"--preorder")==0)
		{
			preorder(&gyoker,0);
		}
		else if(strcmp(argv[1],"--inorder")==0)
		{
			inorder(&gyoker,0);
		}
		else if(strcmp(argv[1],"--postorder")==0)
		{
			postorder(&gyoker,0);
		}
		else
		{
			usage();
		}
	}
	else
	{
		usage();
	}
	destroy_tree(&gyoker);
	return 0;
}
