#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "Node.h"

template <class T>
class LinkedList {
    public:
        LinkedList(); // Constructor
        ~LinkedList(); // destructor
        void addFirst(T data);
        void addLast(T data);
        bool add(T data, int pos);
        void deleteFirst();
        void deleteLast();
        void del(int pos);
        bool isEmpty() const;
        int deleteAll();
        T set(T data, int pos);
        T get(int pos) const;
        bool change(int pos1, int pos2);
        int getSize() const;
        void print() const;
    private:
        Node<T> *head;
        int size;
};

template <class T>
LinkedList<T>::LinkedList() { // Constructor
    head = nullptr;
    size = 0;
}

template <class T>
LinkedList<T>::~LinkedList() { // destructor
    deleteAll();
}

template <class T>
void LinkedList<T>::addFirst(T data) { // Complejidad: O(1)
    head = new Node<T>(data, head);
    size++;
}

template <class T>
void LinkedList<T>::addLast(T data) { // Complejidad: O(n)
    if (isEmpty()) {
        addFirst(data);
    }
    else {
        Node<T> *current = head;
        for (int i = 0; i < size - 1; i++) {
            current = current->getNext();
        }
        current->setNext(new Node<T>(data));
        size++;
    }
}

template <class T>
bool LinkedList<T>::add(T data, int pos) { // Complejidad: O(n)
    if ((pos < 0 ) || (pos > size)) {
        return false;
    }
    else if (pos == 0) {
        addFirst(data);
    }
    else if (pos == size) {
        addLast(data);
    }
    else {
       Node<T> *current = head;
       for (int i = 0; i < pos - 1; i++) {
           current = current->getNext();
       }
       current->setNext(new Node<T>(data, current->getNext()));
       size++;
    }
    return true;
}

template <class T>
void LinkedList<T>::deleteFirst() { // Complejidad: O(1)
    if (!isEmpty()) {
        Node<T> *erase = head;
        head = erase->getNext();
        delete erase;
        size--;
    }
}

template <class T>
void LinkedList<T>::deleteLast() { // Complejidad: O(n)
    if (!isEmpty()) {
        if (size == 1) {
            deleteFirst();
        }
        else {
            Node<T> *current = head;
            while (current->getNext()->getNext() != nullptr) {
                current = current->getNext();
            }
            Node<T> *erase = current->getNext();
            current->setNext(nullptr);
            delete erase;
            size--;
        }
    }
}

template <class T>
void LinkedList<T>::del(int pos) { // Complejidad: O(n)
    if (pos == 0) {
        deleteFirst();
    }
    else {
        Node<T> *current = head;
        for (int i = 0; i < pos - 1; i++) {
            current = current->getNext();
        }
        Node<T> *erase = current->getNext();
        current->setNext(erase->getNext());
        delete erase;
        size--;
    }
    

}

template <class T>
bool LinkedList<T>::isEmpty() const { // Complejidad: O(1)
    return size == 0;
}

template <class T>
int LinkedList<T>::deleteAll() { // Complejidad: O(n)
    int deleted = size;
    while (!isEmpty()) {
        deleteFirst();
    }
    return deleted;
}

template <class T>
T LinkedList<T>::set(T data, int pos) { // Complejidad: O(n)
    Node<T> *current = head;
    for (int i = 0; i < pos; i++) {
        current = current->getNext();
    }
    T old = current->getData();
    current->setData(data);
    return old;
}

template <class T>
T LinkedList<T>::get(int pos) const { // Complejidad: O(n)
    Node<T> *current = head;
    for (int i = 0; i < pos; i++) {
        current = current->getNext();
    }
    return current->getData();

}

template <class T>
bool LinkedList<T>::change(int pos1, int pos2) { // Complejidad: O(n)
    if ((pos1 < 0) || (pos1 >= size) || (pos2 < 0) || (pos2 >= size)) {
        return false;
    }
    Node<T> *current1 = head;
    for (int i = 0; i < pos1; i++) {
        current1 = current1->getNext();
    }
    Node<T> *current2 = head;
    for (int i = 0; i < pos2; i++) {
        current2 = current2->getNext();
    }
    T temp = current1->getData();
    current1->setData(current2->getData());
    current2->setData(temp);
    return true;

}

template <class T>
int LinkedList<T>::getSize() const { // Complejidad: O(1)
    return size;
}

template <class T>
void LinkedList<T>::print() const { // Complejidad: O(n)
    if (!isEmpty()) {
        cout << head->getData();
        Node<T> *current = head->getNext();
        while (current != nullptr) {
            cout << " " << current->getData();
            current = current->getNext();
        }
        cout << endl;
    }
}

#endif // LINKEDLIST_H
