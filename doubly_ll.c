//doubly linked list
#include<stdio.h>
#include<malloc.h>

struct node{
    int data;
    struct node *next;
    struct node * prev;
}*start=NULL;

struct node* makenode(int a){
    struct node *newnode;
    newnode=(struct node *)malloc (sizeof(*newnode));
    newnode->data=a;
    return newnode;
};
void addnode_end(){
int x;
struct node * newnode,*temp;
temp=start;
printf("\nEnter the data to be inserted: ");
scanf("%d",&x);
newnode = makenode(x);
if(start==NULL){
 newnode->next=NULL;
 newnode->prev=NULL;
 start=newnode;
}
else if(start->next==NULL){
    start->next=newnode;
    newnode->prev=start;
    newnode->next=NULL;
}
else{
 while(temp->next!=NULL)
    temp=temp->next;
 temp->next=newnode;
 newnode->prev=temp;
 newnode->next=NULL;
}
printf("\nData inserted at the end.\n");
}

void addnode_beg()
{
    int x;
    struct node* newnode,*temp;
    temp=start;
    printf("\nEnter data to be inserted:");
    scanf("%d",&x);
    newnode=makenode(x);
    if(start==NULL){
        newnode->prev=NULL;
        newnode->next=NULL;
        start=newnode;
    }
    else {
            start->prev=newnode;
            newnode->next=start;
            newnode->prev=NULL;
            start=newnode;
    }

}

void display(){
struct node * temp;
int i=1;
temp=start;
if(temp==NULL)
    printf("\nLinked list is empty.");
else{
    do{
       {
        printf("\n%d  %d",i,temp->data);
        temp=temp->next;
        i++;
       }
    }while(temp->next!=NULL);

}

}

int main(){
  int a,n;
  while(1){
  printf("\nEnter choice.\n1>add element.\n2>delete element.\n3>search element.\n4>display list.\n5>reverse list.\nany no to exit.\n");
  scanf("%d",&n);
  switch (n){
         case 1:printf("\nEnter choice.\n1>At the end.\n2.at the beginning.\n3>at a specific position.\n");
                scanf("%d",&n);
                switch(n){
                case 1:
                   addnode_end();
                   break;
                case 2:
                    addnode_beg();
                    break;
                }
                break;
          case 4: display();      //check working of display function.
                  break;
     }

  }

}
