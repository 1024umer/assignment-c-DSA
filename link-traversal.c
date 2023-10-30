#include <stdio.h>
#include <stdlib.h>
struct node{
    int data;
    struct node* next;
};
struct node* LinkedListTraversal(struct node* head){
    struct node* ptr=head;
    while(ptr!=NULL){
        printf("Element: %d\n",ptr->data);
        ptr=ptr->next;
    }
};
struct node* DeleteFirstElement(struct node* head){
    struct node * ptr=head;
    head=head->next;
    free(ptr);
    return head;
};
struct node* DeleteAtIndex(struct node* head,int index){
    struct node* p=head;
    struct node* q=head->next;
    for(int i=0;i<index-1;i++){
        p=p->next;
        q=q->next;
    }
    p->next=q->next;
    free(q);
    return head;
};
struct node* DeleteAtEnd(struct node* head){
    struct node* p=head;
    struct node* q=head->next;
    
    while(q->next!=NULL){
        
        p=p->next;
        q=q->next;
    }
    p->next=NULL;
    free(q);
    return head;
};
struct node* DeleteAtTheValue(struct node* head,int value){
    struct node* p=head;
    struct node* q=head->next;
    
    while(q->data!=value && q->next!=NULL){
        
        p=p->next;
        q=q->next;
    }
    if(q->data==value){
    p->next=q->next;
    free(q);
    }
    else{
        printf("THE GIVEN VALUE NOT FOUND\n");
    }
    return head;
};

int main() {
   struct node* head=(struct node*)malloc(sizeof(struct node));
   struct node* second=(struct node*)malloc(sizeof(struct node));
   struct node* third=(struct node*)malloc(sizeof(struct node));
   struct node* fourth=(struct node*)malloc(sizeof(struct node));
   head->data=3;
   head->next=second;
  
  second->data=5;
  second->next=third;
   
   third->data=7;
   third->next=fourth;
   
   fourth->data=9;
   fourth->next=NULL;
   
   printf("LINKED LIST:\n");
   LinkedListTraversal(head);
   
//   head=DeleteFirstElement(head);
// printf("LIST AFTER DELETING THE FIRST ELEMENT\n");
//  LinkedListTraversal(head);

// head=DeleteAtIndex(head,2);
// printf("LIST AFTER DELETING THE ELEMENT AT GIVEN INDEX\n");
//  LinkedListTraversal(head);

// head=DeleteAtEnd(head);
// printf("LIST AFTER DELETING THE LAST ELEMENT\n");
//  LinkedListTraversal(head);

head=DeleteAtTheValue(head,100);
printf("LIST AFTER DELETING THE GIVEN VALUE\n");
  LinkedListTraversal(head);
   

    return 0;
}