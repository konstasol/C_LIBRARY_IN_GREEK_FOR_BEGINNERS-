#include <stdio.h>
#include <string.h>
#include <math.h>

// Åëåã÷ïò 16áäéêïý
int validhex(char hex[]) {
    int i;
    for (i = 0; hex[i] != '\0'; ++i) {
        if (!((hex[i] >= '0' && hex[i] <= '9') || (hex[i] >= 'A' && hex[i] <= 'F') ||
		(hex[i] >= 'a' && hex[i] <= 'f'))) {
            return 0; // Ìç Ýãêõñï
        }
    }
    return 1; // Åãêõñï
}

//ìåôáôñïðÞ óå äåêáäéêü 
int hexToDecimal(char hex[]) {
    int len = strlen(hex);
    int base = 1; // ÂÜóç 16, ãéá ðñþôï üñï 16^0=1
    int decimal = 0;
	int i;
	
    // Convert hex to decimal
    for (i = len - 1; i >= 0; i--) {
        if (hex[i] >= '0' && hex[i] <= '9') {
            decimal += (hex[i] - '0') * base;  // ÌåôáôñÝðïõìå ôï '0'-'9' óå 0-9
        } else if (hex[i] >= 'A' && hex[i] <= 'F') {
            decimal += (hex[i] - 'A' + 10) * base;  // ÌåôáôñÝðïõìå ôï 'A'-'F' óå 10-15
        } else if (hex[i] >= 'a' && hex[i] <= 'f') {
            decimal += (hex[i] - 'a' + 10) * base;  // ÌåôáôñÝðïõìå ôï 'a'-'f' óå 10-15
        	} 
        base = base * 16;  // áõîçóç ôçò äýíáìçò ôïõ 16
    }
    return decimal;
}


int main(void) {
    system("chcp 1253>nul");
	int valid, decimal;
    char hex[17];
    do{
    	printf("Äþóôå äåêáåîáäéêü áñéèìü: ");
    	scanf("%s", hex);
    	valid=validhex(hex);
    	if (valid==0) puts("Ìç Ýãõêõñï 16áäéêü!");
	}while(valid==0);
    

    decimal = hexToDecimal(hex);
    if (decimal != -1) {
        printf("Decimal: %d\n", decimal);
    }

    return 0;
}
