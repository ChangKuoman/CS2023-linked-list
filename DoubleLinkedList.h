//
// Created by Samanta on 9/01/2024.
//

#ifndef CS2023_LINKED_LIST_DOUBLELINKEDLIST_H
#define CS2023_LINKED_LIST_DOUBLELINKEDLIST_H

#include <stdexcept>

template <typename T>
class DoubleLinkedList {
private:
    template <typename U>
    struct Node {
        U data;
        Node<U>* prev;
        Node<U>* next;
        explicit Node(U valor): data(valor), next(nullptr), prev(nullptr) {}
    };
    Node<T>* start;
    Node<T>* end;
public:
    DoubleLinkedList(): start(nullptr), end(nullptr) {}
    ~DoubleLinkedList() {
        clear();
    }

    T front() {
        if (empty()) {
            throw std::runtime_error("Lista vacia.");
        }
        // Retorna el elemento al comienzo
        return start->data;
    }
    T back() {
        if (empty()) {
            throw std::runtime_error("Lista vacia.");
        }
        // Retorna el elemento al final
        return end->data;
    }
    void push_front(T valor) {
        // Agrega un elemento al comienzo
        auto* node = new Node<T>(valor);
        if (empty()) {
            start = end = node;
        }
        else {
            start->prev = node;
            node->next = start;
            start = node;
        }
    }
    void push_back(T valor) {
        // Agrega un elemento al final
        auto* node = new Node<T>(valor);
        if (empty()) {
            start = end = node;
        }
        else {
            end->next = node;
            node->prev = end;
            end = node;
        }
    }
    T pop_front() {
        if (empty()) {
            throw std::runtime_error("La lista esta vacia.");
        }
        // Remueve el elemento al comienzo
        if (start == end) {
            // hay 1 elemento
            T return_value = start->data;
            delete start;
            start = end = nullptr;
            return return_value;
        }
        Node<T>* temp = start;
        start = start->next;
        start->prev = nullptr;
        T return_value = temp->data;
        delete temp;
        return return_value;
    }
    T pop_back() {
        if (empty()) {
            throw std::runtime_error("La lista esta vacia.");
        }
        if (start == end) {
            return pop_front();
        }
        // Remueve el elemento al final
        Node<T>* temp = end;
        end = end->prev;
        end->next = nullptr;
        T return_value = temp->data;
        delete temp;
        return return_value;
    }
    void insert(T valor, int n) {
        // Inserta en cualquier posición
        if (n < 0 || n >= size()) {
            throw std::runtime_error("Indice fuera de rango.");
        }
        if (n == 0) {
            push_front(valor);
        }
        else if (n == size() - 1) {
            push_back(valor);
        }
        else {
            auto node = new Node<T>(valor);
            Node<T>* temp = start;
            for (int i = 0; i < n - 1; i++) {
                temp = temp->next;
            }

            node->prev = temp;
            node->next = temp->next;

            temp->next->prev = node;
            temp->next = node;
        }
    }
    void remove(int n) {
        // Remueve en cualquier posicion
        if (n < 0 || n >= size()) {
            throw std::runtime_error("Indice fuera de rango.");
        }
        if (n == 0) {
            pop_front();
        }
        else if (n == size() - 1) {
            pop_back();
        }
        else {
            Node<T>* temp = start;
            for (int i = 0; i < n; i++) {
                temp = temp->next;
            }

            temp->prev->next = temp->next;
            temp->next->prev = temp->prev;

            delete temp;
        }
    }
    T operator[](int n) {
        if (n < 0 || n >= size()) {
            throw std::runtime_error("Indice fuera de rango.");
        }
        // Retorna el elemento en la posición indicada
        Node<T>* temp = start;
        for (int i = 0; i < n; i++) {
            temp = temp->next;
        }
        return temp->data;
    }
    bool empty() {
        // Retorna si la lista está vacía o no
        return start == nullptr && end == nullptr;
    }
    int size() {
        // Retorna el tamaño de la lista
        int tam = 0;
        Node<T>* temp = start;
        while (temp != nullptr) {
            tam++;
            temp = temp->next;
        }
        return tam;
    }
    void clear() {
        // Elimina todos los elementos de la lista
        int n = size();
        for (int i = 0; i < n; i++) {
            pop_back();
        }
    }
    void reverse() {
        if (empty()) {
            return;
        }
        // Revierte la lista
        Node<T>* temp = nullptr;
        Node<T>* node;
        end = start;
        while (start != nullptr) {
            node = start;
            start = start->next;
            node->next = temp;
            node->prev = start;
            temp = node;
        }
        start = temp;
    }

    friend std::ostream& operator<<(std::ostream& os, DoubleLinkedList& a) {
        Node<T>* temp = a.start;
        while (temp != nullptr) {
            os << temp->data << " ";
            temp = temp->next;
        }
        return os;
    }
};

#endif //CS2023_LINKED_LIST_DOUBLELINKEDLIST_H
