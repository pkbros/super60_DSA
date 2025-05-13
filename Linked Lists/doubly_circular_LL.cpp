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

    public:
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
        else{
            Node* tail = head->prev;
            newNode->next = head;
            newNode->prev = tail;
            tail->next = newNode;
            head->prev = newNode;
            head = newNode;
        }

    }

    void insertAtTail(int value){
        Node* newNode = new Node(value);
        if(head == nullptr){
            head = newNode;
            head->next = head;
            head->prev = head;
        }
        else{
            Node* tail = head->prev;
            tail->next = newNode;
            newNode->prev = tail;
            newNode->next = head;
            head->prev = newNode;
        }
    }

    void deleteHead(){
        if(head == nullptr){
            cout << "List is empty." << endl;
            return;
        }
        if(head->next == head){
            delete head;
            head = nullptr;
            return;
        }
        Node* tail = head->prev;
        Node* temp = head;
        head = head->next;
        tail->next = head;
        head->prev = tail;
        delete temp;
    }

    void deleteTail(){
        if(head == nullptr){
            cout << "List is empty." << endl;
            return;
        }
        if(head->next == head){
            delete head;
            head = nullptr;
            return;
        }
        Node* tail = head->prev;
        Node* newTail = tail->prev;
        newTail->next = head;
        head->prev = newTail;
        delete tail;
    }

    void display(){
        if(head == nullptr){
            cout<<"List is empty"<<endl;
            return;
        }
        Node* temp = head;
        do{
            cout<<temp->data<<" ";
            temp = temp->next;
        }while(temp != head);
        cout<<endl;
    }
};


int main(){
    DoublyCircularLinkedList list;
    list.insertAtHead(10);
    list.insertAtHead(20);
    list.insertAtTail(5);
    list.display();
    
    list.deleteHead();
    list.display();

    list.deleteTail();
    list.display();

    list.deleteHead();
    list.display();


    return 0;
}