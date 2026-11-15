#pragma once
#include "priNode.h"
#include <iostream>             ////zeyad

//This class impelements the priority queue as a sorted list (Linked List)
//The item with highest priority is at the front of the queue
template <typename T>
class priQueue
{
protected:  //in case you need to inherit for the project
    priNode<T>* head;
    int count;              ////zeyad
public:
    priQueue() : head(nullptr), count(0) {}

    ~priQueue() {
        T tmp;
        int p;
        while (dequeue(tmp, p));
    }

    //insert the new node in its correct position according to its priority
    void enqueue(const T& data, int priority) {
        priNode<T>* newNode = new priNode<T>(data, priority);

        if (head == nullptr || priority > head->getPri()) {

            newNode->setNext(head);
            head = newNode;
            count++;                ////zeyad
            return;
        }

        priNode<T>* current = head;
        while (current->getNext() && priority <= current->getNext()->getPri()) {
            current = current->getNext();
        }
        newNode->setNext(current->getNext());
        current->setNext(newNode);
        count++;                ///zeyad
    }

    bool dequeue(T& topEntry, int& pri) {
        if (isEmpty())
            return false;

        topEntry = head->getItem(pri);
        priNode<T>* temp = head;
        head = head->getNext();
        delete temp;

        count--;                        ////zeyad
        return true;
    }

    bool peek(T& topEntry, int& pri) {
        if (isEmpty())
            return false;

        topEntry = head->getItem(pri);
        return true;
    }

    bool isEmpty() const {
        return head == nullptr;
    }

    int GetCount() const                ////zeyad
    {
        return count;
    }

    void print() const
    {
        priNode<T>* current = head;
        int pri;
        while (current != nullptr)
        {
            std::cout << current->getItem(pri);
            if (current->getNext() != nullptr)
                std::cout << ", ";
            current = current->getNext();               /////zeyad
        }
    }


};
