#include <stdio.h>
#include <stdlib.h>
struct node {
    int data;
    struct node *left, *right;
};
typedef struct node tree;
tree *root = NULL;
tree *t1, *t2;
int flag;
/* To find the smallest element in the right sub tree */
int smallest(tree *t)
{
    t2 = t;
    if (t->left != NULL)
    {
        t2 = t;
        return(smallest(t->left));
    }
    else    
        return (t->data);
}
 
/* To find the largest element in the left sub tree */
int largest(tree *t)
{
    if (t->right != NULL)
    {
        t2 = t;
        return(largest(t->right));
    }
    else    
        return(t->data);
}
 
/* To delete a node */
void delete1(tree *t)
{
    int k;
 
    /* To delete leaf node */
    if ((t->left == NULL) && (t->right == NULL))
    {
        if (t1->left == t)
        {
            t1->left = NULL;
        }
        else
        {
            t1->right = NULL;
        }
        t = NULL;
        free(t);
        return;
    }
 
    /* To delete node having one left hand child */
    else if ((t->right == NULL))
    {
        if (t1 == t)
        {
            root = t->left;
            t1 = root;
        }
        else if (t1->left == t)
        {
            t1->left = t->left;
 
        }
        else
        {
            t1->right = t->left;
        }
        t = NULL;
        free(t);
        return;
    }
 
    /* To delete node having right hand child */
    else if (t->left == NULL)
    {
        if (t1 == t)
        {
            root = t->right;
            t1 = root;
        }
        else if (t1->right == t)
            t1->right = t->right;
        else
            t1->left = t->right;
        t == NULL;
        free(t);
        return;
    }
 
    /* To delete node having two child */
    else if ((t->left != NULL) && (t->right != NULL))  
    {
        t2 = root;
        if (t->right != NULL)
        {
            k = smallest(t->right);
            flag = 1;
        }
        else
        {
            k =largest(t->left);
            flag = 2;
        }
        search1(root, k);
        t->data = k;
    }
 
}
 

void search1(tree *t, int data)
{
    if ((data>t->data))
    {
        t1 = t;
        search1(t->right, data);
    }
    else if ((data < t->data))
    {
        t1 = t;
        search1(t->left, data);
    }
    else if ((data==t->data))
    {
        delete1(t);
    }
}

void delete(int data)
{
 
    if (root == NULL)
    {
        printf("No elements in a tree to delete");
        return;
    }
    t1 = root;
    t2 = root;
    search1(root, data);
}

void insert(int e) {
    tree *t,*x;
    if(root == NULL) {                          //case 1 root is null
        root  = (tree *)malloc(sizeof(tree));   // allocate memory to root
        root->data = e;                         //copy the value
        root->left = NULL;                      //make the left as null
        root->right = NULL;                     // make the right as null
    }
    else {
        t = root;                               // pointing t to root
        while(t != NULL) {
            x = t;                              // x is holding the current t
            if(t->data == e) {                  // checking for duplicate values
                printf("Duplicate Key");
                return;
            }
            else if(t->data > e) {              // element is lesser so moving to the left
                t = t->left;
            }
            else {
                t = t->right;                   // element is greater so moving to the right
            }
        }
        if(x->data > e) {                           // element inserted to the left of x
            x->left = (tree *)malloc(sizeof(tree));
            x->left->data = e;
            x->left->left = NULL;
            x->left->right = NULL;
        }
        else {                                      //element is inserted to the right of x
            x->right = (tree *)malloc(sizeof(tree));
            x->right->data = e;
            x->right->left = NULL;
            x->right->right = NULL;
        }
    }
}
void inorder(tree *r) {
    if(r != NULL) {
        inorder(r->left);           //left
        printf("\t%d",r->data);     //print root
        inorder(r->right);          //right
    }
}
void preorder(tree *r) {
    if(r != NULL) {
        printf("\t%d",r->data);     //print root
        preorder(r->left);          //left
        preorder(r->right);         //right
    }
}
void postorder(tree *r) {
    if(r != NULL) {
        postorder(r->left);         //left
        postorder(r->right);        //right
        printf("\t%d",r->data);     //print root
    }
}

int main()
{
    insert(100);
    insert(50);
    insert(120);
    insert(110);
    insert(10);
    insert(20);
    printf("\nINORDER\n");
    inorder(root);
    printf("\nPREORDER\n");
    preorder(root);
    printf("\nPOSTORDER\n");
    postorder(root);
    delete(20);
    printf("\nINORDER\n");
    inorder(root);
    delete(100);
    printf("\nINORDER\n");
    inorder(root);
    delete(120);
    printf("\nINORDER\n");
    inorder(root);
    return 0;
}