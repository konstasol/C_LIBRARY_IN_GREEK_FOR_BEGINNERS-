#include <stdio.h>


//Μετατροπή σε 16δικό με συνεχείς διαιρέσεις με το 16 
void decimaltoBinary(int x){
	int i, ypoloipo, pin[100],count=0;
	
	while (x>0){
	    ypoloipo=x%16;  
	    pin[count++]=ypoloipo;
		x=x/16;     	  
				  
	}
	if (count>99) {
		printf("Πολύ μεγάλος αριθμός! Μήπως το παράκανες;");
		
	}else {
		
		for(i=count-1;i>=0;--i){ 
			if (pin[i]==10) printf("A"); 
			else if( pin[i]==11) printf("B");
			else if( pin[i]==12) printf("C");
			else if( pin[i]==13) printf("D");
			else if( pin[i]==14) printf("E");
			else if( pin[i]==15) printf("F");
			else printf("%d",pin[i]);
		}
	}

		
}


int main(void){
	system("chcp 1253>nul");
	
	int i, num, pin[8],valid;
	puts(" Μετατροπή Δεκαδικού σε δυαδικό αριθμό");
	puts("---------------------------------------");
	do{
		printf("Δώσε θετικό ακέραιο αριθμό: ");
		scanf("%d",&num);
		
	
	}while (num<=0);
	
	
	
	//Κλήση συναρτήσεων
	decimaltoBinary(num);
	return 0;
}
