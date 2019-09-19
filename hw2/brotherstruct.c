#include <stdio.h>
#include <stdlib.h>


struct linkedlist {
    int data;
    struct linkedlist* next;
};

struct linkedlist* newNode(int value) {
    struct linkedlist *node;
    node = (struct linkedlist*)malloc(sizeof(struct linkedlist));
    node->data = value;
    node->next = NULL;
    return node;
}

void printLinkedList(struct linkedlist* head) {
    struct linkedlist *iter = head;
    while (1) {
        printf("%d", iter->data);
        if ((iter = iter->next)) {
            printf(", ");
        } else {
            printf("\n");
            return;
        }
    }
}

int main(int argc, char *argv[]) {
    struct linkedlist *head;
    head = newNode(0);

    struct linkedlist *node = head;
    int i;
    for (i = 1; i < 5; ++i) {
        node->next = newNode(i);
        node = node->next;
    }

    printLinkedList(head);

    // do something here

    head->next->next->next = head->next->next->next->next;
//    printf("%d\n", head->next->data);

    // I want to see 0, 1, 2, 4
    printLinkedList(head);
    return 0;
}
