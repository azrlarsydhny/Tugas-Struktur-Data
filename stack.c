#include <stdio.h>
#include <stdlib.h>

#define MAX 100
typedef struct {
    int data[MAX];
    int top;
} Stack;
void initialize(Stack *s) {
    s->top = -1;
}
int isEmpty(Stack *s) {
    return s->top == -1;
}
int isFull(Stack *s) {
    return s->top == MAX - 1;
}
void push(Stack *s, int value) {
    if (isFull(s)) {
        printf("Stack penuh! Tidak bisa menambahkan %d.\n", value);
    } else {
        s->data[++(s->top)] = value;
        printf("Elemen %d berhasil ditambahkan ke stack.\n", value);
    }
}
int pop(Stack *s) {
    if (isEmpty(s)) {
        printf("Stack kosong! Tidak ada elemen untuk dihapus.\n");
        return -1;
    } else {
        return s->data[(s->top)--];
    }
}
int stackTop(Stack *s) {
    if (isEmpty(s)) {
        printf("Stack kosong! Tidak ada elemen di atas.\n");
        return -1;
    } else {
        return s->data[s->top];
    }
}
int stackCount(Stack *s) {
    return s->top + 1;
}
void destroyStack(Stack *s) {
    s->top = -1;
    printf("Stack telah dihancurkan.\n");
}
int main() {
    Stack stack;
    initialize(&stack);
    char choice;
    int value;

    do {
        printf("\nOperasi Stack:\n");
        printf("1. Push Stack(Menambah elemen ke stack)\n");
        printf("2. Pop Stack (Menghapus elemen teratas dari stack)\n");
        printf("3. Stack Top (Menampilkan elemen teratas stack tanpa menghapus)\n");
        printf("4. Empty Stack (Mengecek apakah stack kosong)\n");
        printf("5. Full Stack (Mengecek apakah stack penuh)\n");
        printf("6. Stack Count (Menghitung jumlah elemen dalam stack)\n");
        printf("7. Destroy Stack (Menghancurkan atau mengosongkan stack)\n");
        printf("x. Keluar\n");
        printf("Pilih operasi: ");
        scanf(" %c", &choice);

        switch (choice) {
            case '1':
                printf("Masukkan nilai untuk ditambahkan: ");
                scanf("%d", &value);
                push(&stack, value);
                break;
            case '2':
                value = pop(&stack);
                if (value != -1) {
                    printf("Elemen %d telah dihapus dari stack.\n", value);
                }
                break;
            case '3':
                value = stackTop(&stack);
                if (value != -1) {
                    printf("Elemen teratas di stack: %d\n", value);
                }
                break;
            case '4':
                if (isEmpty(&stack)) {
                    printf("Stack kosong.\n");
                } else {
                    printf("Stack tidak kosong.\n");
                }
                break;
            case '5':
                if (isFull(&stack)) {
                    printf("Stack penuh.\n");
                } else {
                    printf("Stack tidak penuh.\n");
                }
                break;
            case '6':
                printf("Jumlah elemen di stack: %d\n", stackCount(&stack));
                break;
            case '7':
                destroyStack(&stack);
                break;
            case 'x':
                printf("Keluar dari program.\n");
                break;
            default:
                printf("Pilihan tidak valid.\n");
        }
    } while (choice != 'x');

    return 0;
}
