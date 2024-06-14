#include <stdio.h>


//Μετατροπή σε δυαδικό με συνεχείς διαιρέσεις με το 2 
void decimaltoBinary(int x){
	int i, ypoloipo, pin[100],count=0;
	
	while (x>0){
	    ypoloipo=x%2;  
	    pin[count++]=ypoloipo;
		x=x/2;     	  
				  
	}
	if (count>99) {
		printf("Πολύ μεγάλος αριθμός! Μήπως το παράκανες;");
		
	}else {
		
		for(i=count-1;i>=0;--i){ 
		
			printf("%d",pin[i]);
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
