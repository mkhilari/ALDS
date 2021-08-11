# include <stdio.h>
# include <stdlib.h>

typedef struct ListNode 
{
    int val;
    struct ListNode* next;
} ListNode;

ListNode* createList(int A[], int nA) {

    // Create head 
    ListNode* head = (ListNode*) malloc(sizeof(ListNode));

    ListNode* prev = head;
    ListNode* curr = head;

    // Create list 
    for (int i = 0; i < nA; i++) {
        curr->val = A[i];
        curr = curr->next;

        // Last node null 
        if (i < nA - 1) {
            curr = (ListNode*) malloc(sizeof(ListNode));
        }

        prev->next = curr;
        prev = curr;
    }

    return head;
}

void printList(struct ListNode* head) {
    ListNode* curr = head;

    while (curr != NULL) {
        printf("%d", curr->val);

        curr = curr->next;
    }
}

int main(int argc, char* argv[]) {
    int A[] = {1, 2, 3, 4, 5};
    int nA = sizeof(A) / sizeof(A[0]);

    ListNode* listA = createList(A, nA);

    printList(listA);

    return 0;
}