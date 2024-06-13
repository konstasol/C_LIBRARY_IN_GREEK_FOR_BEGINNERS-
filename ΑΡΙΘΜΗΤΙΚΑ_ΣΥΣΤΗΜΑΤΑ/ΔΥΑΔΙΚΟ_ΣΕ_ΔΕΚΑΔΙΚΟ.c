#include <stdio.h>


// Ελεγχος αν είναι δυαδικό
int isBinary(int num) {
    while (num > 0) {
        int digit = num % 10;
        if (digit != 0 && digit != 1) {
            return 0; // όχι δυαδικό
        }
        num /= 10;
    }
    return 1; // ειναι δυαδικό
}


void binaryTodecimal(int x){
	int digit, temp=0,twos=1,dec=0;
	while (x>0){
		digit=x%10;
		x=x/10;
		temp=digit*twos;
		dec+=temp;
		twos*=2;
	}
	printf("Δεκαδικό: %d",dec);
}


int main(void){
	system("chcp 1253>nul");
	
	int i, num, pin[8],valid;
	puts(" Μετατροπή Δυαδικού σε δεκαδικό αριθμό");
	puts("---------------------------------------");
	do{
		printf("Δώσε δυαδικό αριθμό: ");
		scanf("%d",&num);
		valid=isBinary(num);
		if(valid==0) puts("Χμ..δεν είναι δυαδικό..");
	}while (valid==0);
	
	
	
	//Κλήση συναρτήσεων
	binaryTodecimal(num);
}
