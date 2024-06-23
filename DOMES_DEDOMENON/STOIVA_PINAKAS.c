#include <stdio.h>
#include <stdlib.h>
#define SIZE 10
#define EMPTY -1

void push(int S[],int *top, int size, int data){
	(*top)++;
	if(*top==SIZE){
		puts("STACK OVERFLOW");
		exit(1);
	}
	
	S[*top]=data;
}


int pop(int S[],int *top){
	int data;
	if ( (*top)==EMPTY) {
		printf("Αδεια στοίβα!") ;
		exit(1);
	}
	data=S[(*top)];
	(*top)--;
	return data;	
}



int main(void){
	system("chcp 1253>nul");
	int i;
	int A[SIZE]={0};
	int top=EMPTY;
	
	push(A,&top,SIZE,3);
	push(A,&top,SIZE,6);
	push(A,&top,SIZE,8);
	push(A,&top,SIZE,83);
	
	puts("\nΣΤΟΙΒΑ: ");
	for (i=0; i<=top;++i){
		printf(" %d ",A[i]);
	}
	printf("\nΑφαιρέθηκε το : %d",pop(A,&top));
	printf("\nΑφαιρέθηκε το : %d",pop(A,&top));
	puts("\n\nΣΤΟΙΒΑ: ");
	for (i=0; i<=top;++i){
		printf(" %d ",A[i]);
	}
}
