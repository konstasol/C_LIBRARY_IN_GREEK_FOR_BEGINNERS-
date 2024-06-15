#include <stdio.h>

// Έλεγχος αν είναι οκταδικό
int isOctal(int num) {
    while (num > 0) {
        int digit = num % 10;
        if (digit >= 8) {
            return 0; // όχι οκταδικό
        }
        num /= 10;
    }
    return 1; // είναι οκταδικό
}

void octaltohex(int x) {
    int bin[300], count = 0; // Πίνακας για δυαδικό
    int hex[100], count2 = 0; // Πίνακας για δεκαεξαδικό
    int temp, i, j, sum, base;

    // Μετατροπή οκταδικού σε δυαδικό
    while (x > 0) {
        temp = x % 10; // Παίρνουμε το τελευταίο ψηφίο κάθε φορά
        int binPart[3] = {0, 0, 0}; // Το μετατρέπουμε σε τριάδα δυαδικού

        // Βήματα μετατροπής δεκαδικού σε δυαδικό
        for (i = 0; temp > 0; ++i) {
            binPart[i] = temp % 2;
            temp /= 2;
        }

        // Προσαρτούμε τα 3 bit στον πίνακα με ολόκληρο τον αριθμό
        for (i = 0; i < 3; ++i) {
            bin[count++] = binPart[i];
        }

        x /= 10; // Μειώνουμε τον αριθμό κατά ένα ψηφίο
    }

    // Μετατροπή δυαδικού σε δεκαεξαδικό
    for (i = 0; i < count; i+=4) {
        sum = 0;
        base = 1;
        for (j = i; j < i + 4; ++j) {
            sum += bin[j] * base;
            base *= 2;
        }
        hex[count2++] = sum;
    }

       if (count2 > 99) {
        printf("Πολύ μεγάλος αριθμός! Μήπως το παράκανες;");
    } else {
        puts("Δεκαεξαδικός:");

        // Για να μην τυπώνουμε το 0 στην αρχή
        int leading = 1;
        for (i = count2 - 1; i >= 0; --i) {
            if (leading && hex[i] == 0) {
                continue; // Αν υπάρχει μηδέν στην αρχή δεν το τυπώνουμε
            }
            leading = 0; // Όταν βρεθεί το πρώτο ψηφίο

            if (hex[i] >= 10) {
                printf("%c", 'A' + (hex[i] - 10));
            } else {
                printf("%d", hex[i]);
            }
        }

        // Αν δεν βρεθεί πρωτο ψηφίο
        if (leading) {
            printf("0");
        }

        printf("\n");
    }
}

int main(void) {
	system("chcp 1253>nul");
    int num, valid;

    puts("Μετατροπή Οκταδικού σε 16δικό αριθμό");
    puts("---------------------------------------");

    do {
        printf("Δώσε θετικό ακέραιο οκταδικό αριθμό: ");
        scanf("%d", &num);
        valid = isOctal(num);
        if (!valid) {
            puts("Δώσε έγκυρο οκταδικό αριθμό μόνο!");
        }
    } while (!valid);

    // Κλήση συναρτήσεων
    octaltohex(num);

    return 0;
}
