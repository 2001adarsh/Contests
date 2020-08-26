#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define endl    "\n"

struct CLLNode
{
    int data;
    struct CLLNode* next;
};

//inserting at End means, just adding a node at end.
void insertEnd(struct CLLNode **head, int data) {
    struct CLLNode *current = (*head);
    struct CLLNode *newNode = (CLLNode*)malloc(sizeof(struct CLLNode));
    newNode->data = data;
    newNode->next = newNode;

    if (!newNode) { //Check available memory in PC
        cout << "Memory Error!";
        return;
    }

    if (!(*head)) {
        (*head) = newNode;
    } else {
        while (current->next != (*head)) {
            current = current->next;
        }
        //current points to last element now
        newNode->next = (*head);
        current->next = newNode;
    }
}

//similar to insertEnd(), just here you have change the head.
void insertStart(struct CLLNode **head, int data) {
    struct CLLNode *current = (*head);
    struct CLLNode *newNode = (CLLNode*)malloc(sizeof(struct CLLNode));
    newNode->data = data;
    newNode->next = newNode;

    if (!newNode) { //memory error
        cout << "Node cannot be created!";
        return;
    }

    if (!(*head)) {
        (*head) = newNode;
    } else {
        while (current->next != (*head)) {
            current = current->next;
        }
        newNode->next = (*head);
        current->next = newNode;
        (*head) = newNode;
    }
}

//deletes the last element.
void deleteLast(struct CLLNode **head) {
    struct CLLNode *current = (*head);
    if (!(*head)) {
        cout << "List is empty" << endl;
        return;
    }
    // if only 1 node available.
    if (current == current->next) {
        (*head) = NULL;
        return;
    }

    struct CLLNode *prev = NULL;
    while (current->next != (*head)) {
        prev = current;
        current = current->next;
    }
    prev->next = current->next;
    current->next = NULL;
    delete current;
}


void deleteStart(struct CLLNode **head) {
    struct CLLNode *current = (*head);

    //if only 1 node
    if (current == current->next) {
        (*head) = NULL;
        return;
    }

    while (current->next != (*head)) {
        current = current->next;
    }
    struct CLLNode *temp = current->next; //which is head
    current->next = (*head)->next;
    (*head) = (*head)->next;
    delete temp;
}

void printCLL(struct CLLNode *head) {
    struct CLLNode *current = head;
    if (!head) {
        cout << "CLLNode is Empty" << endl;
        return;
    }
    do {
        cout << current->data << " ";
        current = current->next;
    } while (current != head);
}

int32_t main()
{   ios_base::sync_with_stdio(false);
    cin.tie(NULL);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    struct CLLNode *head = NULL;
    insertEnd(&head, 10);
    insertEnd(&head, 20);
    insertEnd(&head, 30);
    insertStart(&head, 40);
    insertStart(&head, 50);
    deleteLast(&head);
    deleteStart(&head);
    printCLL(head);

    return 0;
}