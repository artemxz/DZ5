#pragma once
#include <iostream>

template <typename T>
struct Node {
    T m_data;
    Node* next;

    Node(const T& value) : m_data(value), next(nullptr) {}
};

template <typename T>
class OneWayList {
private:
    Node<T>* m_head;
    Node<T>* m_tail;
    size_t m_size;

public:
    OneWayList() {
        m_head = nullptr;
        m_tail = nullptr;
        m_size = 0;
    }


    ~OneWayList() {
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

        m_tail = new_node;
        m_size++;
    }

    void print() const {
        Node<T>* current = m_head;
        while (current != nullptr) {

            std::cout << current->m_data << " -> ";
            current = current->next;
        }
        std::cout << "NULL\n";
    }
    size_t size() const {
        return m_size;
    }

    T& operator[](size_t index) {
        Node<T>* current = m_head;
        if (index >= m_size) {
            throw std::out_of_range("Индекс за пределами списка!");
        }

        for (size_t i = 0; i < index; i++) {
            current = current->next;
        }
        return current->m_data;
    }


    const T& operator[](size_t index) const {
        Node<T>* current = m_head;
        if (index >= m_size) {
            throw std::out_of_range("Индекс за пределами списка!");
        }

        for (size_t i = 0; i < index; i++) {
            current = current->next;
        }
        return current->m_data;
    }

    void erase(size_t index) {

        if (index >= m_size) {
            throw std::out_of_range("Призраков не трогаем, только живых");
        }


        if (index == 0) {
            Node<T>* temp = m_head;
            m_head = m_head->next;
            delete temp;
            m_size--;
        }

        else {
            Node<T>* current = m_head;


            for (size_t i = 0; i < index - 1; i++) {
                current = current->next;
            }


            Node<T>* node_to_delete = current->next;


            current->next = node_to_delete->next;


            delete node_to_delete;
            m_size--;
        }
    }
    void insert(size_t index, const T& value) {

        if (index > m_size) {
            throw std::out_of_range("Призраков не трогаем, только живых");
        }


        if (index == 0) {
            Node<T>* new_node = new Node<T>(value);
            new_node->next = m_head;
            m_head = new_node;

            if (m_size == 0) {
                m_tail = new_node;
            }
            m_size++;
            return;
        }


        Node<T>* current = m_head;


        for (size_t i = 0; i < index - 1; i++) {
            current = current->next;
        }


        Node<T>* new_node = new Node<T>(value);
        new_node->next = current->next;
        current->next = new_node;


        if (index == m_size) {
            m_tail = new_node;
        }

        m_size++;
    }
};