#include <iostream>
#include "headerFile/Node.h"

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
            if(position < k){
                std::cout << "nullptr" << std::endl;
            }

        }
};
