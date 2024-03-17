#include <iostream>
//#include "headerFile/Node.h"
using namespace std;
class Node{
    public:
        int data;
        Node* next;
        Node* prev;
        Node(int data){
            this->data = data;
            this->next = nullptr;
            this->prev = nullptr;
        }
};

class doublyLinklist{
    private:
        Node* head;
        Node* tail;
    public:
        doublyLinklist(){
            head = nullptr;
            tail = head; 
        }

        void insertInHead(int data){
            Node* newNode = new Node(data);
            if(head == nullptr){
                head = newNode;
                return;
            }
            Node* current = head;
            newNode->next = current;
            current->prev = newNode;
            head = newNode;
            tail = current;
        }
        void insertInTail(int data){
            Node* newNode = new Node(data);
            if(head == nullptr || tail == head){
                head = newNode;
                return;
            }
            Node* current = tail;
            current->next = newNode;
            newNode->prev = current;
            tail = newNode;
        }
        void insertInMid(int data, int position){
            int k = 1;
            Node* newNode = new Node(data);
            if(head == nullptr){
                head = newNode;
                return;
            }
            Node* current = head;
            while(current->next != nullptr){
                if(position == k){
                    Node* temp = current->next;
                    current->next = newNode;
                    newNode->prev = current;
                    newNode->next = temp;
                    temp->prev = newNode;
                    return;
                }
                k++;
            }
            if(position != k){
                std::cout << "nullptr" << std::endl;
            }

        }
        void travarse(){
            Node* current = head;
            while (current != nullptr) {
                std::cout << current->data << " -> ";
                current = current->next;
            }
            std::cout << "nullptr" << std::endl;
        }
};

int main(){
    doublyLinklist list;
    list.insertInHead(1);
    list.travarse();
    return 0;
}
