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

void octaltobinary(int x) {
    int pin[300], count = 0; // Πίνακας για δυαδικό
    int temp, i;

    // Αντιστρέφουμε τη σειρά των ψηφίων για να τα χειριστούμε σωστά
    while (x > 0) {
        temp = x % 10; // Παίρνουμε το τελευταίο ψηφίο κάθε φορά
        int bin[3] = {0, 0, 0}; // Το μετατρέπουμε σε τριάδα δυαδικού

        // Βήματα μετατροπής δεκαδικού σε δυαδικό
        for (i = 0; temp>0; ++i) {
            bin[i] = temp % 2;
            temp /= 2;
        }

        // Προσαρτούμε τα 3 bit στον πίνακα με ολόκληρο τον αριθμό
        for (i = 0; i < 3; ++i) {
            pin[count++] = bin[i];
        }

        x /= 10; // Μειώνουμε τον αριθμό κατά ένα ψηφίο
    }

    if (count > 299) {
        printf("Πολύ μεγάλος αριθμός! Μήπως το παράκανες;");
    } else {
        puts("ΔΥΑΔΙΚΟΣ:");
        // Τυπώνουμε με αντίστροφη σειρά
        for (i = count - 1; i >= 0; --i) {
            printf("%d", pin[i]);
        }
        printf("\n");
    }
}

int main(void) {
	system("chcp 1253>nul");
    int num, valid;

    puts("Μετατροπή Οκταδικού σε Δυαδικό αριθμό");
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
    octaltobinary(num);

    return 0;
}
