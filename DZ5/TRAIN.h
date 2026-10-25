#pragma once
#include <iostream>

template <typename T>
struct Node {
    T m_data;
    Node* next;
    Node* prev;

    Node(const T& value) : m_data(value), next(nullptr), prev(nullptr) {}
};

template <typename T>
class TRAIN {
private:
    Node<T>* m_head;
    Node<T>* m_tail;
    size_t m_size;

public:
    TRAIN() {
        m_head = nullptr;
        m_tail = nullptr;
        m_size = 0;
    }


    ~TRAIN() {
        Node<T>* current = m_head;
        while (current != nullptr) {
            Node<T>* nextNode = current->next;
            delete current;
            current = nextNode;
        }
    }

    void push_back(const T& value) {
        Node<T>* new_node = new Node<T>(value);

        if (m_size == 0) {
            m_head = new_node;
            m_tail = new_node;
            m_size++;
            return;
        }

        m_tail->next = new_node;
        new_node->prev = m_tail;
        m_tail = new_node;
        m_size++;
    }

    void print() const {
        Node<T>* current = m_head;
        while (current != nullptr) {
            std::cout << current->m_data << " <-> ";
            current = current->next;
        }
        std::cout << "NULL\n";
    }
};