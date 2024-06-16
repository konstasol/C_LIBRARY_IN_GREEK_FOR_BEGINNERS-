#include <stdio.h>
#include <stdlib.h>


int main(void){
	system("chcp 1253>nul");
	
    int a,b,c,output;
    
    do{
    	printf("%s","Äþóå ôï Á (0 Þ 1): ");
    	scanf("%d",&a);
    	
	}while(a!=0 && a!=1);
	
	do{
    	printf("%s","Äþóå ôï Â (0 Þ 1): ");
    	scanf("%d",&b);
    	
	}while(b!=0 && b!=1);
	
	do{
    	printf("%s","Äþóå ôï Ã (0 Þ 1): ");
    	scanf("%d",&c);
    	
	}while(c!=0 && c!=1);
	
	// OR==> || , AND==>&&, XOR==>^, NOT==>!
	// NOR==> ! (A||B), NAND==> !(A&&B), XNOR ==>!(A ^ B)
	
	output=( a || b || c ) && ( !a || !b || !c);    //Åäþ ôïðïèåôïýìå ôç ëïãéêÞ óõíÜñôçóç  || 
	
	printf("¸îïäïò êõêëþìáôïò: %d ",output);
	
	return 0;
	
	

	
}
