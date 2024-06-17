#include  <stdio.h>
#include <stdlib.h>


#define MAX 100 //


int main(void){
	system("chcp 1253>nul");
	
	
	int i,j,temp,min,pos; 
	int k=0;
	int p[MAX];
	
	//Επιλογή αριθμών από χρήστη
	puts("\n++++++++++++++++++++++  SELECTION SORT +++++++++++++++++++++++++++++++\n");
	printf("\nΔώσε αριθμους για ταξινόμηση, όταν βαρεθείς πάτα =\n");
	while(1){
		
		
		printf("Αριθμός %3d:  ",k+1);
		
		scanf("%d",&p[k]);
		
		char c=getchar(); //Διαβάζει επόμενο χαρακτήρα 
		if(c =='='){
			puts("Επιτέλους τελείωσες...\n\n");
			break;
			
		}
		if (k==100){
			puts("Σοβαρά τώρα χρειάζεσαι πάνω απο 100 νούμερα? ");
			break;
		}
		
		++k;
		
	}
	
	
	//Τυπώνουμε οτι μας έδωσε ο χρήστης 
	
	puts("Ο αρχικός πίνακας που έδωσες:");
	
	puts("--------------------------------------");
	for(i=0;i<k;++i){
		
		printf("[%d]  ",p[i]);
	}
	
	
	//SELECTION SORT CLASSIC
	
	for (i=0;i<k-1;++i){
		min=p[i];
		pos=i;
		for(j=i+1;j<k;++j){
			if (p[j]<min){
				min=p[j];
				pos=j;		
			}				
		}
		//SWAP
		temp=p[i];
		p[i]=p[pos];
		p[pos]=temp;		
	}
	
	
	//Τυπώνουμε τον ταξινομημένο
	
	puts("\n\nΟ πίνακας ΤΑΞΙΝΟΜΗΜΕΝΟΣ: ");
	
	puts("--------------------------------------");
	for(i=0;i<k;++i){
		
		printf("[%d]  ",p[i]);
	}
	
	puts("\n\n");
	
	return 0;
	
}
