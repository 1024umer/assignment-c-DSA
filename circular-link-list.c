#include <stdio.h>
#include <stdlib.h>
struct node{
    int data;
    struct node* next;
};
void LinkedListTraversal(struct node* head){
    struct node* ptr = head;
    do{
        printf("Element=%d\n",ptr->data);
        ptr=ptr->next;
    }while(ptr!=head);
}
struct node* InsertAtFirst(struct node* head,int data){
    struct node* ptr=(struct node*)malloc(sizeof(struct node));
    ptr->data=data;
    struct node* p=head->next;
    while(p->next!=head){
        p=p->next;
    }
    p->next=ptr;
    ptr->next=head;
    head=ptr;
    return head;
}

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
   fourth->next=head;
   
   printf("LINKED LIST:\n");
   LinkedListTraversal(head);
   head=InsertAtFirst(head,80);
   LinkedListTraversal(head);

    return 0;
}