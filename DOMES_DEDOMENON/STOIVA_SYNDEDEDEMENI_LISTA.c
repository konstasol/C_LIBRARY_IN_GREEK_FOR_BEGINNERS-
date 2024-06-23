#include <stdio.h>
#include <stdlib.h>



struct ListNode {
int data; 
struct ListNode *next;
};

typedef struct ListNode STACK;
typedef struct ListNode* STACK_PTR;

void ST_PUSH(STACK_PTR * head,int num){ //εισαγωγη στην αρχή
	STACK_PTR newnode;

	newnode=(STACK_PTR )malloc(sizeof(STACK));
	if(!newnode) {
		puts("Αδυναμία δέσμευσης μνήμης!");
		exit(1);
	}
	
	newnode->data=num;
	
	newnode->next=*head;
	*head=newnode;
	
	}
	
	
int ST_POP(STACK_PTR* head){ //διαγραφή από την αρχή
	
	if(*head==NULL){
		printf("Αδεια λίστα!");
		exit (1);
	}
	
	STACK_PTR temp;
	int x;	
	
	 temp=*head;
	 x=temp->data;
	 (*head)=(*head)->next;
	 free(temp);
	 return x;
	}
	

	
void ST_PRINT(STACK_PTR head){
	
	STACK_PTR temp;
	temp=head;
	while(temp){
		printf("%d -->",temp->data);
		temp=temp->next;
	}
	printf("NULL\n");
}	





int main(void){
	system("chcp 1253>nul");
	STACK_PTR head=NULL;
	
	
	
	ST_PUSH(&head,5);
	ST_PUSH(&head,8);
	ST_PUSH(&head,9);
	
	ST_PRINT(head);
	puts("");
	
	printf("Εγινε pop του στοιχείου: %d", ST_POP(&head));
	puts("");
	ST_PRINT(head);
	
	return 0;
}
