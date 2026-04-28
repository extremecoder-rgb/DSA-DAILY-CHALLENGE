// Given the head of a linked list, return the list after sorting it in ascending order.

#include<iostream>
using namespace std;

struct Node {
    int data;
    Node *next;
    Node(int x) : data(x), next(NULL) {}
};

Node* BubbleSortLL(Node* head){
    bool swapped = true;
    int copy;
    if(head == nullptr || head->next == nullptr) return head;
    while(swapped){
        swapped = false;
        Node* temp = head;
        while(temp->next != nullptr){
            if(temp->data > temp->next->data){
                copy = temp->data;
                temp->data = temp->next->data;
                temp->next->data = copy;
                swapped = true;
            }
            temp = temp->next;
        }
    }
    return head;
}
Node* findMiddle(Node* head){
    Node* slow = head;
    Node* fast = head->next;
    while(fast != nullptr && fast->next != nullptr){
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

Node* merge(Node* leftHead, Node* rightHead){
    Node* dummy = new Node(-1);
    Node* temp = dummy;
    Node* t1 = leftHead;
    Node* t2 = rightHead;
    while(t1 != nullptr && t2 != nullptr){
        if(t1->data < t2->data){
            temp->next = t1;
            temp = t1;
            t1 = t1->next;
        }
        else{
            temp->next = t2;
            temp = t2;
            t2 = t2->next;
        }
    }
    if(t1) temp->next = t1;
    else temp->next = t2;
    return dummy->next;
}

Node* MergeSort(Node* head){
    if(head == nullptr || head->next == nullptr) return head;
    Node* middleNode = findMiddle(head);
    Node* leftHead = head;
    Node* rightHead = middleNode->next;
    middleNode->next = nullptr;

    leftHead = MergeSort(leftHead);
    rightHead = MergeSort(rightHead);
    return merge(leftHead, rightHead);
}

int main(){
    Node* head = new Node(5);
    head->next = new Node(4);
    head->next->next = new Node(6);
    head->next->next->next = new Node(2);
    head->next->next->next->next = new Node(1);
    // head = BubbleSortLL(head);
    head = MergeSort(head);
    Node* temp = head;
    while(temp != nullptr){
        cout << temp->data << " ";
        temp = temp->next;
    }
}

