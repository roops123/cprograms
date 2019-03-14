#include<stdio.h>
#include<stdlib.h>

typedef struct node{
int key;
struct node* next;
}list;

list* createnode(int );
void insertfront(int key);
void traverse(list * temp);
void insertend(int key);
void deletefront();
void deleteend();
void insertmid(int,int);
list* searchkey(int);

struct node* head=NULL;
///////////////////////////////////////////////
int main(){
int value,key,midkey;
list* Node;
while(1){
printf("\nenter your choice\n 1.insert node at front \n 2.print node \n 3.exit \n 4.insert node at end\n 5.delete node at front\n 6.delete node at end\n 7.insert at mid\n 8.search the key");
scanf("%d",&value);
switch(value){
case 1:
	
	printf("enter key\n");
	scanf("%d",&key);

	insertfront(key);
	printf("node entered successfully\n");
break;
case 2:
	traverse(head);
break;
case 3:
	exit(1);
break;
case 4:
	printf("enter key\n");
	scanf("%d",&key);

	insertend(key);
	printf("node entered successfully\n");
break;
case 5:
	deletefront();
break;
case 6:
	deleteend();
break;
case 8: if(head==NULL)
	break;
	else{
	printf("enter key\n");
	scanf("%d",&key);
	Node=searchkey(key);
	if(Node!=NULL && Node->key==key)
	printf("the key %d is found",Node->key);
	else
	printf("not found");
	}
	//printf("node entered successfully\n");
break;
case 7: if(head==NULL)
	break;
	else{
	printf("enter key\n");
	scanf("%d",&key);
	printf("enter the key after u want to insert\n");
	scanf("%d",&midkey);
	insertmid(key,midkey);
	}
	//printf("node entered successfully\n");
break;
default:
	printf("wrong choice\n");
}
	}
return 0;

}
///////////////////////////////////////////////
list* createnode(int key){
list * temp;
	temp=(list*)malloc(sizeof(list));
	temp->key=key;
	temp->next=NULL;
	return temp;
}
//////////////////////////////////////////////////////////
void insertfront(int key){
list* Node=createnode(key);
if(Node!=NULL){
	if(head==NULL){
	head=Node;
	printf("first node");
	}
		else{
		Node->next=head;
		head=Node;
		}
	}
}
/////////////////////////////////////////////////////////
void traverse(list * temp){
if(temp!=NULL){
	do{
	printf("%d\t",temp->key);
	temp=temp->next;
	}while(temp->next!=NULL);
printf("%d",temp->key);
}
}
///////////////////////////////////////////////////////////
void insertend(int key){
list* temp=head;
list* Node=createnode(key);
while(temp->next!=NULL)
temp=temp->next;

temp->next=Node;
}
///////////////////////////////////////////////////////////
void deletefront(){

list* temp=head;
if(temp!=NULL){
	head=head->next;
	free(temp);
	printf("deleted successfully");
	}
}
////////////////////////////////////////////////////////////
void deleteend(){
list* temp=head;
list* endnode=NULL;
if(temp!=NULL){
while(temp->next!=NULL){
	endnode=temp;
	temp=temp->next;
	}
endnode->next=NULL;
free(temp);
printf("endnode deleted successfully");	
}
}
//////////////////////////////////////////////////////////////
void insertmid(int key,int midkey){
list* temp=NULL;
list* midnode=NULL;
list* Node=createnode(key);
midnode=searchkey(midkey);
if(midnode!=NULL && midnode->key==midkey){
	temp=midnode->next;
	midnode->next=Node;
	Node->next=temp;
printf("entered successfully/n");
}

}
////////////////////////////////////////////////////////////
list* searchkey(int key){
list* temp=head;
if(temp!=NULL){
while(temp->key!=key && temp->next!=NULL){
//printf("%d has been scanned",temp->key);
temp=temp->next;
}
//printf("%d is found",temp->key);
}
return(temp);
}
////////////////////////////////////////////////////////////

























