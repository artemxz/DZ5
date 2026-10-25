#pragma once
#include <iostream>
#include <stdexcept>

template <typename T>
class ArrayContainer {
private:
    T* m_data;
    size_t m_size;
    size_t m_capacity;

public:

    ArrayContainer() {
        m_capacity = 10;
        m_size = 0;
        m_data = new T[m_capacity];
    }


    ~ArrayContainer() {
        delete[] m_data;
    }


    void push_back(const T& value) {
        if (m_size >= m_capacity) {
            m_capacity *= 2;
            T* new_data = new T[m_capacity];
            for (size_t i = 0; i < m_size; i++) {
                new_data[i] = m_data[i];
            }

            delete[] m_data;
            m_data = new_data;
        }



        m_data[m_size] = value;
        m_size++;
    }


    void insert(size_t index, const T& value) {
        if (index > m_size) return;

        if (m_size >= m_capacity) {
            m_capacity *= 2;
            T* new_data = new T[m_capacity];
            for (size_t i = 0; i < m_size; i++) {
                new_data[i] = m_data[i];
            }
            delete[] m_data;
            m_data = new_data;
        }

        for (size_t i = m_size; i > index; i--) {
            m_data[i] = m_data[i - 1];
        }

        if (index < m_capacity) {
            m_data[index] = value;
        }
       
        m_size++;
    }


    void erase(size_t index) {
        if (index >= m_size) return;

        for (size_t i = index; i < m_size - 1; i++) {
            m_data[i] = m_data[i + 1];
        }

        m_size--;
    }

    void print() const {
        for (size_t i = 0; i < m_size; i++) {
            std::cout << m_data[i] << " ";
        }
        std::cout << std::endl;
    }


    size_t size() const {
        return m_size;
    }


    T& operator[](size_t index) {
        return m_data[index];
    }

    const T& operator[](size_t index) const {
        return m_data[index];
    }
};