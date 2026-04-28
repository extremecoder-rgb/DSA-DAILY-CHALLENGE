// Remove nth node from end of list

#include<iostream>
using namespace std;

struct Node {
    int val;
    Node *next;
    Node(int x) : val(x), next(NULL) {}
};

Node* removeNthFromEnd(Node* head, int n){
    Node* temp = head;
    int count = 0;
    while(temp != nullptr){
        count ++;
        temp = temp->next;
    }
    if(count == n){
        Node* newHead = head->next;
        delete(head);
        return newHead;
    }
    int res = count - n;
    temp = head;
    while(temp != nullptr){
        res--;
        if(res == 0) break;
        temp = temp->next;
    }
    Node* deleteNode = temp->next;
    temp->next = temp->next->next;
    delete(deleteNode);
    return head;
}

Node* removeV2(Node* head, int n){
    Node* fast = head;
    for(int i = 0; i < n; i++) {
        if (fast == nullptr) return head; 
        fast = fast->next;
    }
    if (fast == nullptr) {
        Node* newHead = head->next;
        delete head;
        return newHead;
    }
    Node* slow = head;
    while(fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next;
    }
    Node* deleteNode = slow->next;
    slow->next = slow->next->next;
    delete deleteNode;
    return head;
}

int main(){
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);

    // Node* result = removeNthFromEnd(head, 5);
    Node* result = removeV2(head,5);
    Node* temp = result;
    while(temp != nullptr){
        cout << temp->val << " ";
        temp = temp->next;
    }

}
