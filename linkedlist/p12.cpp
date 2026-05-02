// Sort a LinkedList of 0's, 1's and 2's 
#include <bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* next;
    Node(int val){
        data = val;
        next = nullptr;
    }
};

Node* sortAlgoOnePass(Node* head){
    Node* zeroHead = new Node(-1);
    Node* oneHead = new Node(-1);
    Node* twoHead = new Node(-1);
    Node* zero = zeroHead;
    Node* one = oneHead;
    Node* two = twoHead;
    Node* temp = head;
    while(temp != nullptr){
        if(temp->data == 0){
            zero->next = temp;
            zero = temp;
        }
        else if(temp->data == 1){
            one->next = temp;
            one = temp;
        }
        else{
            two->next = temp;
            two = temp;
        }
        temp = temp->next;
    }
    zero->next = (oneHead->next) ? (oneHead->next) : (twoHead->next);
    one->next = twoHead->next;
    two->next = nullptr;
    Node* newNode = zeroHead->next;
    delete(zeroHead);
    delete(oneHead);
    delete(twoHead);
    return newNode; 
}

Node* sort(Node* head){
    int count0 = 0;
    int count1 = 0;
    int count2 = 0;
    Node* temp = head;
    while(temp != nullptr){
        if(temp->data == 0) count0++;
        else if(temp->data == 1) count1++;
        else count2++;
        temp = temp->next;
    }
    temp = head;
    while(temp != nullptr){
        if(count0){
            temp->data = 0;
            count0--;
        }
        else if(count1){
            temp->data = 1;
            count1--;
        }
        else{
            temp->data = 2;
            count2--;
        }
        temp = temp->next;
    }
    return head;
}

int main(){
    Node* head = new Node(1);
    head->next = new Node(2);   
    head->next->next = new Node(0);
    head->next->next->next = new Node(1);

    head = sortAlgoOnePass(head);

    Node* temp = head;
    while(temp != nullptr){
        cout << temp->data << " ";
        temp = temp->next;
    }
    return 0;
}
