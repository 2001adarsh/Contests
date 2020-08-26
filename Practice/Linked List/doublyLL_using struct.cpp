#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define endl    "\n"

struct DLLNode
{
    int data;
    struct DLLNode *next;
    struct DLLNode *prev;
};

void Insert(struct DLLNode **head, int data, int pos) {
    struct DLLNode *current = (*head);
    struct DLLNode *newNode = (DLLNode*) malloc(sizeof(struct DLLNode));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;

    if (!newNode) { //memory overflow
        cout << "Memory Error!";
        return;
    }

    if (pos == 1) { //Insertion at begining.
        newNode->next = (*head);
        if (*head)
            (*head)->prev = newNode;
        (*head) = newNode;
        return;
    } else {
        int k = 1; //counter.
        while (current->next != NULL && (k < pos)) {
            current = current->next;
            k++;
        }
        if (k + 1 != pos ) {
            cout << "Desired position doesn't exists." << k << endl;
            return;
        }
        //current is at position where I have to add the element.
        newNode->prev = current;
        newNode->next = current->next;
        if (current->next)  //if not null
            current->next->prev = newNode;
        current->next = newNode;
    }
}

void deleteNode(struct DLLNode **head, int pos) {
    struct DLLNode* current = (*head);
    if (!(*head)) { //if empty
        cout << "The Doubly Linked List is empty!" << endl;
        return;
    }

    if (pos == 1) { //deletion at begining.
        current = (*head);
        (*head) = (*head)->next;
        (*head)->prev = NULL;
        delete current;
    } else {
        int k = 1;
        while (k < pos && current->next != NULL) {
            current = current->next;
            k++;
        }
        struct DLLNode* temp = current;
        current = temp->prev;
        if (temp->next != NULL) {
            current->next = temp->next;
            temp->next->prev = current;
        } else {
            current->next = NULL;
        }
        delete temp;
    }
}

//forward direction.
void printDLLf(struct DLLNode* head) {
    struct DLLNode* current = head;
    while (current != NULL) {
        cout << current->data << " ";
        current = current->next;
    }
}

int32_t main()
{   ios_base::sync_with_stdio(false);
    cin.tie(NULL);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    struct DLLNode* head = NULL;
    Insert(&head, 10, 1);
    Insert(&head, 30, 2);
    Insert(&head, 40, 1);
    Insert(&head, 50, 4);

    deleteNode(&head, 3);

    deleteNode(&head, 1);
    printDLLf(head);
    return 0;
}