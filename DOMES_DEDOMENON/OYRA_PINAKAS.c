#include <stdio.h>
#include <stdlib.h>

#define MAX_QUEUE_SIZE 100

// Πίνακας για τα δεδομένα της ουράς
int queue[MAX_QUEUE_SIZE];
int front = -1; // Δείκτης για το πρώτο στοιχείο στην ουρά
int rear = -1;  // Δείκτης για το τελευταίο στοιχείο στην ουρά

// Έλεγχος αν η ουρά είναι γεμάτη
int is_full() {
    return rear == MAX_QUEUE_SIZE - 1;
}

// Έλεγχος αν η ουρά είναι άδεια
int is_empty() {
    return front == -1;
}

// Εισαγωγή στοιχείου στην ουρά (enqueue)
void enqueue(int value) {
    if (is_full()) {
        printf("Η ουρά είναι γεμάτη, δεν μπορεί να γίνει εισαγωγή.\n");
    } else {
        if (front == -1) {
            front = 0; // Αρχικοποίηση του front αν είναι άδεια η ουρά
        }
        rear++; // Αύξηση του rear
        queue[rear] = value; // Εισαγωγή του στοιχείου στην ουρά
        printf("Εισήχθη %d στην ουρά.\n", value);
    }
}

// Αφαίρεση στοιχείου από την ουρά (dequeue)
int dequeue() {
    int item;
    if (is_empty()) {
        printf("Η ουρά είναι άδεια, δεν μπορεί να γίνει αφαίρεση.\n");
        return -1;
    } else {
        item = queue[front]; // Αποθήκευση του πρώτου στοιχείου της ουράς
        if (front == rear) {
            front = -1; // Επαναφορά του front αν αφαιρεθεί το τελευταίο στοιχείο
            rear = -1;
        } else {
            front++; // Αύξηση του front για να δείξει στο επόμενο στοιχείο
        }
        return item; // Επιστροφή του αφαιρεθέντος στοιχείου
    }
}

// Εκτύπωση της ουράς
void print_queue() {
	int i;
    if (is_empty()) {
        printf("Η ουρά είναι άδεια.\n");
    } else {
        printf("Περιεχόμενα της ουράς: ");
        for (i = front; i <= rear; i++) {
            printf("%d ", queue[i]);
        }
        printf("\n");
    }
}

int main() {
	system("chcp 1253>nul");
    enqueue(10); // Εισαγωγή στοιχείων στην ουρά
    enqueue(20);
    enqueue(30);

    print_queue(); // Εκτύπωση της ουράς

    printf("Αφαιρέθηκε %d από την ουρά.\n", dequeue()); // Αφαίρεση στοιχείων από την ουρά

    print_queue(); // Εκτύπωση της ουράς

    return 0;
}
