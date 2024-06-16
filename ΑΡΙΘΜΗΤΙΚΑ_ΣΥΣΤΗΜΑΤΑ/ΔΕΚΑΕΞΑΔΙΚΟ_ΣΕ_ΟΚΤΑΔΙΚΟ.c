#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Έλεγχος αν είναι έγκυρος δεκαεξαδικός χαρακτήρας
int validhex(const char hex[]) {
    int i;
    for (i = 0; hex[i] != '\0'; ++i) {
        if (!((hex[i] >= '0' && hex[i] <= '9') || (hex[i] >= 'A' && hex[i] <= 'F') ||
              (hex[i] >= 'a' && hex[i] <= 'f'))) {
            return 0; // Μη έγκυρο
        }
    }
    return 1; // Έγκυρο
}

// Συνάρτηση για τη μετατροπή δεκαεξαδικού αριθμού σε οκταδικό
void hextooctal(const char hex[]) {
    int pin[500], count = 0; // Πίνακας για δυαδικό
    int temp, i, j;
    int oct[200], count2 = 0;

    // Μετατροπή κάθε δεκαεξαδικού ψηφίου σε 4-bit δυαδικό
    for (i = 0; hex[i] != '\0'; ++i) {
        char c = tolower(hex[i]);

        // Μετατροπή χαρακτήρα σε δεκαδικό αριθμό
        if (isdigit(c)) {
            temp = c - '0';
        } else {
            temp = 10 + (c - 'a');
        }

        // Μετατροπή δεκαδικού αριθμού σε δυαδικό (4 bits)
        int bin[4] = {0, 0, 0, 0};
        for (j = 3; temp > 0; --j) {
            bin[j] = temp % 2;
            temp /= 2;
        }

        // Προσθήκη των 4-bit δυαδικών ψηφίων στον πίνακα
        for (j = 0; j < 4; ++j) {
            pin[count++] = bin[j];
        }
    }

    // Προσθήκη προπορευόμενων μηδενικών αν χρειάζεται για την τριάδα
    int padding = (3 - (count % 3)) % 3; //πόσα ψηφία λείπουν για να εχουμε τριάδες ψηφίων
    for (i = count - 1; i >= 0; --i) {
        pin[i + padding] = pin[i];
    }
    //προσθετουμε 0νικα μπροστα να συμπληρωθούν τριάδες
    for (i = 0; i < padding; ++i) {
        pin[i] = 0;
    }
    count += padding;

    // Μετατροπή των δυαδικών ψηφίων σε οκταδικά
    for (i = 0; i < count; i += 3) {
        int sum = pin[i] * 4 + pin[i + 1] * 2 + pin[i + 2];
        oct[count2++] = sum;
    }

    // Τυπώνουμε τον οκταδικό αριθμό χωρίς προπορευόμενα μηδενικά
    printf("ΟΚΤΑΔΙΚΟΣ:\n");
    int leading_zero = 1;
    for (i = 0; i < count2; ++i) {
        if (oct[i] != 0 || !leading_zero) {
            printf("%d", oct[i]);
            leading_zero = 0;
        }
    }
    if (leading_zero) {
        printf("0");
    }
    printf("\n");
}

int main(void) {
    system("chcp 1253>nul");
    char num[20];
    int valid;

    puts("Μετατροπή 16δικού σε Οκταδικό αριθμό");
    puts("---------------------------------------");

    do {
        printf("Δώσε θετικό ακέραιο 16δικό αριθμό: ");
        scanf("%19s", num);
        valid = validhex(num);
        if (!valid) {
            puts("Δώσε έγκυρο 16δικο αριθμό μόνο!");
        }
    } while (!valid);

    // Κλήση της συνάρτησης για τη μετατροπή
    hextooctal(num);

    return 0;
}
