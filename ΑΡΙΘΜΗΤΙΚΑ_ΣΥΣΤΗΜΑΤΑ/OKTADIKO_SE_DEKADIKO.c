#include <stdio.h>


// Ελεγχος αν είναι οκταδικό
int isOctal(int num) {
    while (num > 0) {
        int digit = num % 10;
        if (digit == 8 || digit == 9) {
            return 0; // όχι οκταδικό
        }
        num /= 10;
    }
    return 1; // ειναι οκταδικό
}

//Μετατροπή σε δεκαδικό με χρήση του τύπου μετατροπής σε δεκαδικό σύστημα
//Με βάση το 8 (okto)
void octalTodecimal(int x){
	int digit, temp=0,okto=1,dec=0;
	while (x>0){
		digit=x%10; 	  //παίρνω τελευταίο ψηφίο
		x=x/10;     	  //μειώνω τον αριθμό κατα 1 ψηφίο
		temp=digit*okto;  //φτιάχνω τον τρέχον όρο του αρθροίσματος 
						  //(digit) * 8 εις την 0,1,2,3η κ.ο.κ 
		dec+=temp;        //προσθέτω όρους
		okto*=8;		  //φτιάχνω την δύναμη του 8 (πχ 8**3 * 8 = 8**4) για τον επόμενο όρο
	}
	printf("Δεκαδικός: %d",dec);
}


int main(void){
	system("chcp 1253>nul");

	int num,valid;
	puts(" Μετατροπή Οκταδικού σε δεκαδικό αριθμό");
	puts("---------------------------------------");
	do{
		printf("Δώσε οκταδικό αριθμό: ");
		scanf("%d",&num);
		valid=isOctal(num);
		if(valid==0) puts("Χμ..δεν είναι οκταδικό..");
	}while (valid==0);
	
	
	
	//Κλήση συναρτήσεων
	octalTodecimal(num);
}
