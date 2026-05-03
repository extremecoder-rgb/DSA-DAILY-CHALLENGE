// Intersection of Two Linked Lists

#include <iostream>
#include<map>
using namespace std;

struct Node{
    int data;
    Node* next;
    Node(int val){
        data = val;
        next = nullptr;
    }
};

Node* intersection(Node* headL1, Node* headL2){
    Node* temp = headL1;
    map<Node*, int> visited;
    while(temp != nullptr){
        visited[temp] = 1;
        temp = temp->next;
    }
    temp = headL2;
    while(temp != nullptr){
        if(visited.find(temp) != visited.end()) return temp;
        temp = temp->next;
    }
    return nullptr;
}

Node* intersectPoint(Node* t1, Node* t2, int d){
    while(d){
        d--;
        t2=t2->next;
    }
    while(t1!=t2){
        t1=t1->next;
        t2=t2->next;
    }
    return t1;
}

Node* intersectionAlgo2(Node* headL1, Node* headL2){
    Node* t1 = headL1;
    Node* t2 = headL2;
    int c1=0,c2=0;
    while(t1 != nullptr){
        c1++;
        t1=t1->next;
    }
    while(t2!=nullptr){
        c2++;
        t2=t2->next;
    }
    if(c1<c2){
        return intersectPoint(headL1,headL2,c2-c1);
    }
    else return intersectPoint(headL2,headL1,c1-c2);
}

Node* intersectionAlgo3(Node* headL1, Node* headL2){
    Node* t1 = headL1;
    Node* t2 = headL2;
    if(headL1 == nullptr || headL2 == nullptr) return nullptr;
    while(t1!=t2){
        t1=t1->next;
        t2=t2->next;
        if(t1 == nullptr) t1=headL2;
        if(t2 == nullptr) t2=headL1;
        if(t1 == t2) return t1;
    }
    return t1;
}

int main() {
    // Common part (intersection)
    Node* common1 = new Node(8);
    Node* common2 = new Node(10);
    common1->next = common2;

    // First linked list: 1 -> 2 -> 8 -> 10
    Node* headL1 = new Node(1);
    headL1->next = new Node(2);
    headL1->next->next = common1;

    // Second linked list: 3 -> 8 -> 10
    Node* headL2 = new Node(3);
    headL2->next = common1;

    Node* result = intersectionAlgo3(headL1, headL2);

    if (result != nullptr)
        cout << "Intersecting point: " << result->data << endl;
    else
        cout << "No intersection" << endl;

    return 0;
}

