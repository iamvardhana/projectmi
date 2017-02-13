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

void addnode_beg(){
    int x;
    struct node* newnode;
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

int count_nodes()
{
struct node * temp;
int count;
temp=start;
if(start==NULL)
 count=0;
else{
count=1;
while(temp->next!=NULL)
{
temp=temp->next;
count++;
}
}
return count;
}
void addnode_pos(int pos){
int x,i;
struct node *t1,*t2,*newnode;
printf("\nEnter data to be inserted:");
scanf("%d",&x);
newnode=makenode(x);
i=count_nodes();
if((pos>0)&&(pos<i)){
t1=start;
t2=start;
i=1;
while(i<pos){
t1=t2;
t2=t2->next;
i++;
}
t1->next=newnode;
newnode->prev=t1;
t2->prev=newnode;
newnode->next=t2;
}
else{
printf("\nInvalid position");}
}


void display(){
struct node * temp;
int i=1;
temp=start;
if(temp==NULL)
    printf("\nLinked list is empty.");
else if(start->next==NULL){
   printf("\nstart-> %d ->NULL",start->data);
}
else{
printf("\nstart->");
while(temp->next!=NULL){
 printf(" %d ->",temp->data);
 temp=temp->next;
}
printf(" %d -> null\n",temp->data);
}
}

int main(){
  int a,n,pos;
  while(1){
  printf("\nEnter choice.\n1>add element   2>delete element.  3>search element.\n4>display list.   5>reverse list.\nany no to exit.\n");
  scanf("%d",&n);
  switch (n){
         case 1:printf("\nEnter choice.\n1>At the end.  2>at the beginning.  3>at a specific position.\n>");
                scanf("%d",&n);
                switch(n){
                case 1:
                   addnode_end();
                   break;
                case 2:
                    addnode_beg();
                    break;
                case 3:
                    printf("\nEnter position>");
                    scanf("%d",&pos);//function over-writing earlier element
                    addnode_pos(pos);
                    break;
                }
                break;
          case 4: display();      //check working of display function.
                  break;
     }

  }

}
