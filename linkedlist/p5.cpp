// Given the head of a linked list, return the node where the cycle begins. 
// If there is no cycle, return null.
#include<iostream>
#include<map>

using namespace std;

struct Node {
    int val;
    Node *next;
    Node(int x) : val(x), next(NULL) {}
};

Node* startingNodeOfCycle(Node* head){
    Node* slow = head;
    Node* fast = head;
    while(fast != nullptr && fast->next != nullptr){
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast){
            slow = head;
            while(slow!=fast){
                slow = slow->next;
                fast = fast->next;
            }
            return slow;
        }
    }
    return nullptr;

}

Node* startNodeHashing(Node* head){
    map<Node*,int> visited;
    Node* temp = head;
    while(temp != nullptr){
        if(visited.find(temp) != visited.end()){
            return temp;
        }
        visited[temp] = 1;
        temp = temp->next;
    }
}

int main(){
    Node* head = new Node(1);
    Node* second = new Node(2);
    Node* third = new Node(3);
    Node* fourth = new Node(4);
    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = second;

    Node* entryNode = startingNodeOfCycle(head);
    // Node* entryNode = startNodeHashing(head);

    if(entryNode != nullptr) {
        cout << "starting node is " << entryNode->val << endl;
    }
    else {
        cout << "No cycle detected";
    }
}