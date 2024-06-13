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


//Μετατροπή σε δυαδικό με χρήση του τύπου μετατροπής σε δεκαδικό σύστημα
//Με βάση το 2 (twos)
void binaryTodecimal(int x){
	int digit, temp=0,twos=1,dec=0;
	while (x>0){
		digit=x%10; 	  //παίρνω τελευταίο ψηφίο
		x=x/10;     	  //μειώνω τον αριθμό κατα 1 ψηφίο
		temp=digit*twos;  //φτιάχνω τον τρέχον όρο του αρθροίσματος 
						  //(digit) * 2 εις την 0,1,2,3η κ.ο.κ 
		dec+=temp;        //προσθέτω όρους
		twos*=2;		  //φτιάχνω την δύναμη του 2 (πχ 2**3 * 2 = 2**4) για τον επόμενο όρο
	}
	printf("Δεκαδικό: %d",dec);
}



int main(void){
	system("chcp 1253>nul");
	
	int num,valid;
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
