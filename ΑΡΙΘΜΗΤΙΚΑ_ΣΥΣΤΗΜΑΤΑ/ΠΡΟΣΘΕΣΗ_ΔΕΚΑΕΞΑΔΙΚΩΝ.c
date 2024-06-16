#include <stdio.h>
#include <string.h>
#include <ctype.h>



int validhex(char hex[]) {
    int i;
    for (i = 0; hex[i] != '\0'; ++i) {
        if (!((hex[i] >= '0' && hex[i] <= '9') || (hex[i] >= 'A' && hex[i] <= 'F') ||
		(hex[i] >= 'a' && hex[i] <= 'f'))) {
            return 0; // Μη έγκυρο
        }
    }
    return 1; // Εγκυρο
}

void sum_hex( char a[], char b[]) {
    int len_a = strlen(a);
    int len_b = strlen(b);
    int max_len = (len_a > len_b) ? len_a : len_b;
    int result[max_len + 1];
    

    int i, sum, carry = 0;
    int idx_a = len_a - 1;
    int idx_b = len_b - 1;

    for (i = max_len - 1; i >= 0; --i) {
        int digit_a = 0, digit_b = 0;

        if (idx_a >= 0) {
            if (a[idx_a] >= '0' && a[idx_a] <= '9') {
                digit_a = a[idx_a] - '0';
            } else if (a[idx_a] >= 'A' && a[idx_a] <= 'F') {
                digit_a = a[idx_a] - 'A' + 10;
            } else if (a[idx_a] >= 'a' && a[idx_a] <= 'f') {
                digit_a = a[idx_a] - 'a' + 10;
            }
            idx_a--;
        }

        if (idx_b >= 0) {
            if (b[idx_b] >= '0' && b[idx_b] <= '9') {
                digit_b = b[idx_b] - '0';
            } else if (b[idx_b] >= 'A' && b[idx_b] <= 'F') {
                digit_b = b[idx_b] - 'A' + 10;
            } else if (b[idx_b] >= 'a' && b[idx_b] <= 'f') {
                digit_b = b[idx_b] - 'a' + 10;
            }
            idx_b--;
        }

        sum = digit_a + digit_b + carry;
        result[i + 1] = sum % 16;
        carry = sum / 16;
    }

    result[0] = carry;

    puts("\nΑποτέλεσμα: ");
    if (result[0] != 0) {
        if (result[0] < 10) {
            printf("%d", result[0]);
        } else {
            printf("%c", result[0] - 10 + 'A');
        }
    }

    for (i = 1; i <= max_len; ++i) {
        if (result[i] < 10) {
            printf("%d", result[i]);
        } else {
            printf("%c", result[i] - 10 + 'A');
        }
    }
    printf("\n");
}

int main(void) {
    system("chcp 1253>nul");
    char num1[20];
    char num2[20];

    puts("Προσθήκη δεκαεξαδικών αριθμών");
    puts("-----------------------------");
	do{
		printf("Δώσε τον πρώτο δεκαεξαδικό αριθμό: ");
    	scanf("%19s", num1);
		
	}while(validhex(num1)==0);
	
    do{
	    printf("Δώσε τον δεύτερο δεκαεξαδικό αριθμό: ");
	    scanf("%19s", num2);
	}while(validhex(num2)==0);
    
	
	sum_hex(num1, num2);

    return 0;
}
