



#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Έλεγχος αν είναι έγκυρος δεκαεξαδικός χαρακτήρας
int validhex(char hex[]) {
    int i;
    for (i = 0; hex[i] != '\0'; ++i) {
        if (!((hex[i] >= '0' && hex[i] <= '9') || (hex[i] >= 'A' && hex[i] <= 'F') ||
              (hex[i] >= 'a' && hex[i] <= 'f'))) {
            return 0; // Μη έγκυρο
        }
    }
    return 1; // Έγκυρο
}

// Συνάρτηση για τη μετατροπή δεκαεξαδικού αριθμού σε δυαδικό
void hextobinary(char hex[]) {
    int pin[500], count = 0; // Πίνακας για δυαδικό
    int temp, i, j;

    // Μετατροπή κάθε δεκαεξαδικού ψηφίου σε 4-bit δυαδικό
    for (i = 0; i < strlen(hex); ++i) {
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

    if (count > 499) {
        printf("Πολύ μεγάλος αριθμός! Μήπως το παράκανες;");
    } else {
        puts("ΔΥΑΔΙΚΟΣ:");
        // Τυπώνουμε με τη σωστή σειρά, χωρίς τα προπορευόμενα μηδενικά
        int leading0 = 1;
        for (i = 0; i < count; ++i) {
            if (leading0 && pin[i] == 0) {
                continue;
            }
            leading0 = 0; // Αφού εντοπίσουμε το πρώτο μη μηδενικό ψηφίο, αλλάζουμε το flag

            printf("%d", pin[i]);
        }

        // Αν όλα τα ψηφία είναι μηδέν, τότε τυπώνουμε ένα μοναδικό μηδέν
        if (leading0) {
            printf("0");
        }
        
        printf("\n");
    }
}

int main(void) {
    system("chcp 1253>nul");
    int valid;
    char num[20];

    puts("Μετατροπή 16δικού σε Δυαδικό αριθμό");
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
    hextobinary(num);

    return 0;
}
