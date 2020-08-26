#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define endl    "\n"
#define inf 1000000000000000000ll

struct ListNode
{
    int data;
    struct ListNode *next;
};

// double pointers as we have to change the head in main also.
void insertInLinkedList(struct ListNode **head, int data, int pos) {
    struct ListNode* current = (*head);
    struct ListNode* newNode = (ListNode*)malloc(sizeof(struct ListNode));
    newNode->data = data;
    newNode->next = NULL;

    //check for memory
    if (!newNode) {
        cout << "Memory Error!" << endl;
        return;
    }
    int k = 1; // counter

    if (pos == 1) { //Insertion at begining.
        newNode -> next = (*head);
        (*head) = newNode;
    } else {
        while (current->next != NULL && pos != k + 1) {
            k++;
            current = current -> next;
        }
        newNode->next = current->next;
        current->next = newNode;
    }
}

void deleteNode(struct ListNode **head, int pos) {
    struct ListNode* current = (*head);
    if (pos == 1) { //deletion at begining.
        (*head) = (*head)-> next;
        delete current;
    } else {
        int k = 1;
        struct ListNode* prev;
        while (current != NULL && k != pos) {
            prev = current;
            current = current-> next;
            k++;
        }
        prev -> next = current->next;
        delete current;
    }
}

void deleteList(struct ListNode **head) { //delete whole linkedlist.
    struct ListNode *current = (*head);
    struct ListNode *prev;
    while (current != NULL) {
        prev = current;
        current = current->next;
        delete prev;
    }
    //make head as NULL
    (*head) = NULL;
}

void printList(struct ListNode* head) {
    if (!head) {
        cout << "List is empty" << endl;
        return;
    }
    struct ListNode* current = (head);
    while (current != NULL) {
        cout << current->data << " ";
        current = current->next;
    } cout << endl;
}

int32_t main()
{   ios_base::sync_with_stdio(false);
    cin.tie(NULL);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    struct ListNode* head = NULL;
    insertInLinkedList(&head, 30, 1); //insert at begining.
    insertInLinkedList(&head, 50, 2);
    insertInLinkedList(&head, 40, 1);
    insertInLinkedList(&head, 60, 4);
    insertInLinkedList(&head, 70, 6); // it will be inserted at index 5.

    deleteNode(&head, 4);
    deleteNode(&head, 1);

    printList(head);

    deleteList(&head);
    printList(head);

    return 0;
}