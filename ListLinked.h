
#ifndef LIST_LINKED_H
#define LIST_LINKED_H

#include <iostream>
#include <stdexcept>
#include "Node.h"
#include "List.h"

template <typename T>
class ListLinked : public List<T> {
private:
    Node<T>* first;
    int n;

public:

    // Constructor
    ListLinked() {
        first = nullptr;
        n = 0;
    }

    // Destructor
    ~ListLinked() {
        while (first != nullptr) {
            Node<T>* aux = first->next;
            delete first;
            first = aux;
        }
        n = 0;
    }

    // Inserta un elemento en una posición
    void insert(int pos, T e) override {
        if (pos < 0 || pos > n) {
            throw std::out_of_range("Posicion fuera de rango");
        }

        if (pos == 0) {
            first = new Node<T>(e, first);
        } else {
            Node<T>* aux = first;

            for (int i = 0; i < pos - 1; i++) {
                aux = aux->next;
            }

            aux->next = new Node<T>(e, aux->next);
        }

        n++;
    }

    // Añade un elemento al final
    void append(T e) override {
        insert(n, e);
    }

    // Añade un elemento al principio
    void prepend(T e) override {
        insert(0, e);
    }

    // Elimina y devuelve el elemento de una posición
    T remove(int pos) override {
        if (pos < 0 || pos >= n) {
            throw std::out_of_range("Posicion fuera de rango");
        }

        Node<T>* aux = first;
        T element;

        if (pos == 0) {
            element = first->data;
            first = first->next;
            delete aux;
        } else {
            for (int i = 0; i < pos - 1; i++) {
                aux = aux->next;
            }

            Node<T>* toDelete = aux->next;
            element = toDelete->data;
            aux->next = toDelete->next;
            delete toDelete;
        }

        n--;
        return element;
    }

    // Devuelve el elemento de una posición
    T get(int pos) override {
        if (pos < 0 || pos >= n) {
            throw std::out_of_range("Posicion fuera de rango");
        }

        Node<T>* aux = first;

        for (int i = 0; i < pos; i++) {
            aux = aux->next;
        }

        return aux->data;
    }

    // Busca un elemento y devuelve su posición
    int search(T e) override {
        Node<T>* aux = first;
        int pos = 0;

        while (aux != nullptr) {
            if (aux->data == e) {
                return pos;
            }

            aux = aux->next;
            pos++;
        }

        return -1;
    }

    // Comprueba si la lista está vacía
    bool empty() override {
        return n == 0;
    }

    // Devuelve el número de elementos
    int size() override {
        return n;
    }

    // Acceso mediante []
    T operator[](int pos) {
        return get(pos);
    }

    // Imprime la lista
    friend std::ostream& operator<<(std::ostream& out,
                                ListLinked<T>& list) {
    Node<T>* aux = list.first;

    out << "List => [";

    while (aux != nullptr) {
        out << "\n  " << aux->data;
        aux = aux->next;
    }

    out << "\n]";

    return out;
}
};

#endif // LIST_LINKED_H
