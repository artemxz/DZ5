#pragma once
#include <iostream>

template <typename T>
struct Nodee { // добавил в конце Node ещё один e
    T m_data;
    Nodee* next; 
    Nodee* prev; 

    Nodee(const T& value) : m_data(value), next(nullptr), prev(nullptr) {}
};

template <typename T>
class TRAIN {
private:
    Nodee<T>* m_head; 
    Nodee<T>* m_tail; 
    size_t m_size;
    
public:
    TRAIN() {
        m_head = nullptr;
        m_tail = nullptr;
        m_size = 0;
    }

    TRAIN(const TRAIN&) = delete; // добавил
    TRAIN& operator=(const TRAIN&) = delete;  // добавил

    ~TRAIN() {
        Nodee<T>* current = m_head;
        while (current != nullptr) {
            Nodee<T>* nextNodee = current->next;
            delete current;
            current = nextNodee;
        }
    }

    void push_back(const T& value) {
        Nodee<T>* new_nodee = new Nodee<T>(value); 

        if (m_size == 0) {
            m_head = new_nodee; 
            m_tail = new_nodee;
            m_size++;
            return;
        }

        m_tail->next = new_nodee;
        new_nodee->prev = m_tail;
        m_tail = new_nodee;
        m_size++;
    }

    void print() const {
        Nodee<T>* current = m_head;
        while (current != nullptr) {
            std::cout << current->m_data << " <-> ";
            current = current->next;
        }
        std::cout << "NULL\n";
    }
};
