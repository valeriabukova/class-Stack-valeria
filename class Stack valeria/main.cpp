//
//  main.cpp
//  class Stack valeria
//
//  Created by Valeria  Bukova on 30.10.2024.
//

#include <iostream>

template <typename T>
class Stack {
private:
    struct Node {
        T data;
        Node* next;

        Node(T value) : data(value), next(nullptr) {}
    };

    Node* topNode;
    size_t stackSize;

public:
    
    Stack() : topNode(nullptr), stackSize(0) {}

    // Деструктор
    ~Stack() {
        while (!isEmpty()) {
            pop();
        }
    }

   
    void push(T value) {
        Node* newNode = new Node(value);
        newNode->next = topNode;
        topNode = newNode;
        ++stackSize;
    }

  
    void pop() {
        if (isEmpty()) {
            std::cout << "Ошибка: Стек пустой, невозможно удалить элемент.\n";
            return;
        }
        Node* temp = topNode;
        topNode = topNode->next;
        delete temp;
        --stackSize;
    }

    
    T top() const {
        if (isEmpty()) {
            std::cout << "Ошибка: Стек пустой.\n";
            return T();
        }
        return topNode->data;
    }

    
    bool isEmpty() const {
        return topNode == nullptr;
    }

   
    size_t size() const {
        return stackSize;
    }
};

int main() {
    Stack<int> stack;

   
    stack.push(10);
    stack.push(20);
    stack.push(30);

    std::cout << "Верхний элемент: " << stack.top() << std::endl;
    std::cout << "Размер стека: " << stack.size() << std::endl;

   
    stack.pop();
    std::cout << "Верхний элемент после удаления: " << stack.top() << std::endl;
    std::cout << "Размер стека после удаления: " << stack.size() << std::endl;

    
    stack.pop();
    stack.pop();
    stack.pop();

    return 0;
}
