
#include <stdio.h>
#include <stdlib.h>

void complement(int a[], int N) {
    int i;
    int c[N];
    int d[N];
    
    // Αρχικοποίηση με 0
    for (i = 0; i < N; ++i) {
        c[i] = 0;
        d[i] = 0;
    }
    //Ο πίνακας c είναι το 1 που θα προσθέσουμε
    c[N - 1] = 1; 

    // Συμπλήρωμα ως προς 1 αντιστροφή ψηφίων
    for (i = 0; i < N; ++i) {
        if (a[i] == 0) {
            a[i] = 1;
        } else {
            a[i] = 0;
        }
    }

    int carry = 0;

    // Συμπλήρωμα ως προς 2 (προσθέτουμε 1)
    for (i = N - 1; i >= 0; --i) {
        int sum = a[i] + c[i] + carry;
        d[i] = sum % 2; // αποτέλεσμα πρόσθεση(δυαδικο ψηφίο)
        carry = sum / 2; // κρατούμενο για επόμενο ψηφίο
    }

    if (carry == 1) {
        printf("Μη επαρκή bit για αναπαράσταση\n"); // αν γίνει υπερχείλιση λογω κρατούμενων
    } else {
        printf("Συμπλήρωμα ως προς 2: ");
        for (i = 0; i < N; ++i) {
            printf("%d ", d[i]);
        }
        printf("\n");
    }
}

int main(void) {
    system("chcp 1253>nul"); 
    int a[8] = {0,0,0,0 ,0, 1, 1, 1};

    int i;

    printf("Before: \n");
    for (i = 0; i < 8; ++i) {
        printf("%d ", a[i]);
    }
    printf("\n");

    complement(a, 8);

    return 0;
}

