#include <stdio.h>
#include <stdlib.h>

// Δομή για τον κόμβο της ουράς
struct QueueNode {
    int data;               // Τα δεδομένα του κόμβου
    struct QueueNode *next; // Δείκτης στον επόμενο κόμβο
};

typedef struct QueueNode Queue;
typedef struct QueueNode* QueuePtr;

// Συνάρτηση για την εισαγωγή στοιχείου στην ουρά
void enqueue(QueuePtr *front, QueuePtr *rear, int num) {
    // Δημιουργία νέου κόμβου
    QueuePtr newnode = (QueuePtr)malloc(sizeof(Queue));
    if (!newnode) {
        // Έλεγχος αν η δέσμευση μνήμης απέτυχε
        puts("Δεν υπάρχει αρκετή μνήμη!");
        exit(1);
    }
    
    // Αρχικοποίηση των δεδομένων του νέου κόμβου
    newnode->data = num;
    newnode->next = NULL;
    
    // Εισαγωγή του νέου κόμβου στην ουρά
    if (*rear == NULL) {
        // Αν η ουρά είναι άδεια, ο νέος κόμβος γίνεται και το front
        *front = newnode;
    } else {
        // Αλλιώς, συνδέεται στον τελευταίο κόμβο με το rear
        (*rear)->next = newnode;
    }
    
    // Ο νέος κόμβος γίνεται και το rear της ουράς
    *rear = newnode;
}

// Συνάρτηση για την αφαίρεση στοιχείου από την ουρά
int dequeue(QueuePtr *front, QueuePtr *rear) {
    // Έλεγχος αν η ουρά είναι άδεια
    if (*front == NULL) {
        printf("Η ουρά είναι άδεια!");
        exit(1);
    }
    
    // Κρατάμε τον πρώτο κόμβο για αφαίρεση
    QueuePtr temp = *front;
    int x = temp->data; // Αποθηκεύουμε τα δεδομένα για επιστροφή
    
    // Μετακίνηση του front στον επόμενο κόμβο
    *front = (*front)->next;
    
    // Αν η ουρά έγινε άδεια, το rear γίνεται NULL
    if (*front == NULL) {
        *rear = NULL;
    }
    
    // Απελευθέρωση της μνήμης του κόμβου που αφαιρέθηκε
    free(temp);
    
    // Επιστροφή των δεδομένων του αφαιρεθέντος κόμβου
    return x;
}

// Συνάρτηση για την εκτύπωση της ουράς
void printQueue(QueuePtr front) {
    QueuePtr temp = front;
    printf("Περιεχόμενα της ουράς: ");
    while (temp) {
        printf("%d --> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Συνάρτηση main για τον έλεγχο της υλοποίησης
int main(void) {
	system("chcp 1253>nul");
    QueuePtr front = NULL; // Δείκτης στην αρχή της ουράς
    QueuePtr rear = NULL;  // Δείκτης στο τέλος της ουράς
    
    // Εισαγωγή στοιχείων στην ουρά
    enqueue(&front, &rear, 5);
    enqueue(&front, &rear, 8);
    enqueue(&front, &rear, 9);
    
    // Εκτύπωση της ουράς
    printQueue(front);
    printf("\n");
    
    // Αφαίρεση στοιχείου από την ουρά και εκ νέου εκτύπωση
    printf("Αφαιρέθηκε από την ουρά: %d\n", dequeue(&front, &rear));
    printQueue(front);
    
    return 0;
}
