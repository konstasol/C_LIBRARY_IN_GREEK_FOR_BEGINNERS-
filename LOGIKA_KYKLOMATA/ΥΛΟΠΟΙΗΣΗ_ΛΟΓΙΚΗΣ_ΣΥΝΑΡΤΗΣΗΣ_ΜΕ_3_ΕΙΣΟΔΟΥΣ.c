
#include <stdio.h>
#include <stdlib.h>


int main(void){
	system("chcp 1253>nul");
	
    int a,b,c,output;
    
    do{
    	printf("%s","Δώσε το Α (0 ή 1): ");
    	scanf("%d",&a);
    	
	}while(a!=0 && a!=1);
	
	do{
    	printf("%s","Δώσε το Β (0 ή 1): ");
    	scanf("%d",&b);
    	
	}while(b!=0 && b!=1);
	
	do{
    	printf("%s","Δώσε το Γ (0 ή 1): ");
    	scanf("%d",&c);
    	
	}while(c!=0 && c!=1);
	
	// OR==> || , AND==>&&, XOR==>^, NOT==>!
	// NOR==> ! (A||B), NAND==> !(A&&B), XNOR ==>!(A ^ B)
	
	output=( a || b || c ) && ( !a || !b || !c);    //Εδώ τοποθετούμε τη λογική συνάρτηση  || 
	
	printf("Έξοδος κυκλώματος: %d ",output);
	
	return 0;
	
	

	
}
