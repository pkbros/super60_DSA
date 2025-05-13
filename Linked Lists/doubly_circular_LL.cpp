#include <iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node* prev;

    Node(int value){
        data = value;
        next = nullptr;
        prev = nullptr;
    }
};

class DoublyCircularLinkedList{
    private:
    Node*head;

    DoublyCircularLinkedList(){
        head = nullptr;
    }

    void insertAtHead(int value){
        Node* newNode = new Node(value);
        if(head == nullptr){
            head = newNode;
            head->next = head;
            head->prev = head;
            
        }

    }
}


int main(){

    return 0;
}