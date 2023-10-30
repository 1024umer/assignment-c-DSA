//Binary search tree making, searching and insertion // Online C compiler to run C program online
#include <stdio.h>
#include <stdlib.h>
struct node{
    int data;
    struct node * left;
    struct node * right;
};
struct node * createnode(int data){
    struct node* n= (struct node* )malloc(sizeof (struct node));
    n->data=data;
    n->left=NULL;
    n->right=NULL;
    return n;
}
struct node * search(struct node * root, int key){
    if(root==NULL){
        return NULL;
    }
    if( root->data==key){
        return root;
    }
    else if(key<root->data){
        return search(root->left,key);
    }
    else{
        return search(root->right,key);
    }
}
////OR////
  struct node * searchIter (struct node * root,int key){ 
    while(root!=NULL){
        if(root->data==key){
            return root;
        }
        else if(root->data>key){
            root=root->left;
        }
        else{
            root=root->right;
        }
    }
    return NULL;
}
void Insert(struct node * root, int key){
    struct node * prev;
    while(root!=NULL){
        prev=root;
        if (root->data==key){
            return;
        }
        if(root->data>key){
            root=root->left;
        }
         else{
            root=root->right;
        }
    }
    if(key<prev->data){
        prev->left=createnode(key);
    }
    if(key>prev->data){
        prev->right=createnode(key);
    }
}

void preorder(struct node * root){
    if(root!=NULL){
        printf("%d ",root->data);
        preorder(root->left);
        preorder(root->right);
    }
}
void postorder(struct node * root){
    if(root!=NULL){
        postorder(root->left);
        postorder(root->right);
        printf("%d ",root->data);
    }
}
void inorder(struct node * root){
    if(root!=NULL){
        inorder(root->left);
        printf("%d ",root->data);
        inorder(root->right);
        
    }
}

int main() {
    struct node * p=createnode(5);
    struct node * p1=createnode(3);
    struct node * p2=createnode(6);
    struct node * p3=createnode(1);
    struct node * p4=createnode(4);
    
    p->left=p1;
    p->right=p2;
    p1->left=p3;
    p1->right=p4;
    
    // preorder(p);
    // postorder(p);
    // inorder(p);
    Insert(p,7);
    Insert(p,2);
    struct node * n=searchIter(p,2);
    if(n!=NULL){
        printf("Number is found:%d\n",n->data);
    }
    else{
        printf("Number is not found\n");
    }
    
   
    preorder(p);


    return 0;
}