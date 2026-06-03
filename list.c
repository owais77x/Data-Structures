#include<stdio.h>
#include<stdlib.h>
//------------------------------------**** LINKED LIST IMPLEMENTATION IN C LANGUAGE ****------------------------------
//Node Structure.
struct Node{
    int data;
    struct Node* next;
};

//Node creater function.
struct Node* CreateNode(int data){
    struct Node* newNode=(struct Node*)malloc(sizeof(struct Node));
    if(!newNode){
        printf("Memory allocation failed!");
        return NULL;
    }
    newNode->data=data;
    newNode->next=NULL;
    return newNode;
}

//Insert Node at Head.
void InsertAtHead(struct Node** head,int data){
    struct Node* newNode=CreateNode(data);
    newNode->next=*head;
    *head=newNode;
}

//Insert Node at the End.
void InsertAtEnd(struct Node** head,int data){
    struct Node* newNode=CreateNode(data);
    if(*head==NULL){
        *head=newNode;
        return;
    }
    struct Node* temp=*head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=newNode;
}

//Delete Node by value.
void DeleteNode(struct Node** head,int key){
    struct Node *temp=*head,*prev=NULL;
    if(temp!=NULL && temp->data==key){
        *head=temp->next;
        free(temp);
        return;
    }
    while(temp!=NULL && temp->data!=key){
        prev=temp;
        temp=temp->next;
    }
    if(temp==NULL){
        return;
    }
    prev->next=temp->next;
    free(temp);
}

//Traverse and Print list function.
void PrintList(struct Node* node){
    while(node!=NULL){
        printf("%d -> ",node->data);
        node=node->next;
    }
    printf("NULL\n");
}


int main(){
    struct Node* head=NULL;
    int num;
    printf("These values are goint to be inserte at head. Enter numbers 1-5.\n");
    for(int i=0;i<5;i++){
        printf("Enter number %d : ",i+1);
        scanf("%d",&num);
        InsertAtHead(&head,num);
    }
    printf("\nThese values are going to be insert at end. Enter numbers 6-10.\n");
    for(int j=0;j<5;j++){
        printf("Enter number %d : ",j+1);
        scanf("%d",&num);
        InsertAtEnd(&head,num);
    }
    printf("\nList as you entered\n");
    PrintList(head);
    printf("\nList after Deletion of 5-Head Value and 10-End value.\n");
    DeleteNode(&head,5);
    DeleteNode(&head,10);
    PrintList(head);
    return 0;
}
