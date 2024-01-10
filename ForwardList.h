//
// Created by Samanta on 9/01/2024.
//

#ifndef CS2023_LINKED_LIST_FORWARDLIST_H
#define CS2023_LINKED_LIST_FORWARDLIST_H

#include <stdexcept>

template <typename T>
class ForwardList {
private:
    template <typename U>
    struct Node {
        U data;
        Node<U>* next;
        explicit Node(U valor): data(valor), next(nullptr) {}
    };

    Node<T>* head;
public:
    ForwardList(){
        head = nullptr;
    }
    ~ForwardList() {
        clear();
    }

    T front(){
        if (empty()) {
            throw std::runtime_error("La lista esta vacia.");
        }
        // Retorna el elemento al comienzo
        return head->data;
    }
    T back(){
        if (empty()) {
            throw std::runtime_error("La lista esta vacia.");
        }
        // Retorna el elemento al final
        Node<T>* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        return temp->data;
    }
    void push_front(T valor){
        // Agrega un elemento al comienzo
        auto* temp = new Node<T>(valor);
        temp->next = head;
        head = temp;
    }
    void push_back(T valor) {
        // Agrega un elemento al final
        if (head == nullptr) {
            push_front(valor);
            return;
        }
        Node<T>* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = new Node<T>(valor);
    }
    T pop_front(){
        if (empty()) {
            throw std::runtime_error("Lista vacia.");
        }
        // Remueve el elemento al comienzo
        Node<T>* temp = head;
        head = head->next;
        T return_value = temp->data;
        delete temp;
        return return_value;
    }
    T pop_back(){
        if (head == nullptr) {
            throw std::runtime_error("Lista vacia.");
        }
        // Remueve el elemento al final
        Node<T>* temp = head;
        if (temp->next == nullptr) {
            T return_value = temp->data;
            delete temp;
            return return_value;
        }
        while (temp->next->next != nullptr) {
            temp = temp->next;
        }
        T return_value = temp->next->data;
        delete temp->next;
        temp->next = nullptr;
        return return_value;
    }
    T operator[](int n){
        if (n < 0 || n >= size()) {
            throw std::runtime_error("Indice fuera de rango.");
        }
        // Retorna el elemento en la posición indicada
        Node<T>* temp = head;
        for (int i = 0; i < n; i++) {
            temp = temp->next;
        }
        return temp->data;
    }
    bool empty(){
        // Retorna si la lista está vacía o no
        return head == nullptr;
    }
    int size(){
        // Retorna el tamaño de la lista
        Node<T>* temp = head;
        int size = 0;
        while (temp != nullptr) {
            temp = temp->next;
            size++;
        }
        return size;
    }
    void clear() {
        // Elimina todos los elementos de la lista
        while (head != nullptr) {
            Node<T>* temp = head;
            head = head->next;
            delete temp;
        }
    }
    void sort(){
        if (head == nullptr) {
            return;
        }
        // Implemente un algoritmo de ordenacion con listas enlazadas)
        Node<T>* biss = head; // before is sorted
        Node<T>* temp; // recorre de biss al final
        Node<T>* minVal; // min value in iteration

        while (biss->next != nullptr) {
            temp = biss;
            minVal = temp;

            while (temp != nullptr) {
                if (temp->data < minVal->data) {
                    minVal = temp;
                }
                temp = temp->next;
            }
            T value = biss->data;
            biss->data = minVal->data;
            minVal->data = value;

            biss = biss->next;
        }

    }
    void reverse(){
        if (empty()) {
            return;
        }
        // Revierte la lista
        Node<T>* temp = nullptr;
        Node<T>* node;
        while (head != nullptr) {
            node = head;
            head = head->next;
            node->next = temp;
            temp = node;
        }
        head = temp;
    }
    friend std::ostream& operator<<(std::ostream& os, ForwardList<T>& a) {
        Node<T>* temp = a.head;
        while (temp != nullptr) {
            os << temp->data << " ";
            temp = temp->next;
        }
        return os;
    }
};



#endif //CS2023_LINKED_LIST_FORWARDLIST_H
