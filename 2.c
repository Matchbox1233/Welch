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
        free (spaces);
    }
    else
    {
        printf("%c\n",elem->c);
    }
    inorder(elem->right,depth+1);
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

int main(int argc, char** argv)
{
    srand(time(null));
    fa = create_empty();
    for(int i=0;i<100;i++)
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

    inorder(&gyoker,0);

    destroy_tree(&gyoker);
    return 0;
}