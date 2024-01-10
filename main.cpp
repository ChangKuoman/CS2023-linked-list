#include <iostream>
#include "ForwardList.h"
#include "DoubleLinkedList.h"

void fl() {
    ForwardList<int> a;
    a.push_front(7);
    a.push_front(5);
    a.push_back(3);
    a.push_back(9);

    std::cout << a << std::endl;
    std::cout << a.front() << std::endl;
    std::cout << a.back() << std::endl;
    a.pop_front();
    std::cout << a << std::endl;
    a.pop_back();
    std::cout << a << std::endl;
    std::cout << a[1] << std::endl;
    std::cout << a.size() << std::endl;
    a.reverse();
    std::cout << a << std::endl;

    a.clear();
    std::cout << a << std::endl;
    std::cout << a.size() << std::endl;
    std::cout << std::boolalpha << a.empty() << std::endl;
    a.reverse();
    std::cout << a << std::endl;
    a.push_back(8);
    std::cout << a << std::endl;
    a.reverse();
    std::cout << a << std::endl;

    ForwardList<int> b;
    b.push_front(7);
    b.push_front(5);
    b.push_back(3);
    b.push_back(7);
    b.push_back(15);
    b.push_back(48);
    b.push_back(3);
    b.push_back(9);
    std::cout << b << std::endl;
    b.sort();
    std::cout << b << std::endl;
}

void dll() {
    DoubleLinkedList<int> a;
    a.push_front(8);
    a.push_back(5);
    a.push_front(1);
    a.push_back(9);
    std::cout << a << std::endl;
    std::cout << a.size() << std::endl;
    std::cout << a.front() << std::endl;
    std::cout << a.back() << std::endl;
    a.pop_front();
    std::cout << a << std::endl;
    a.pop_back();
    std::cout << a << std::endl;
    a.insert(0, 0);
    a.insert(2, 2);
    std::cout << a << std::endl;
    a.insert(20, 2);
    std::cout << a << std::endl;
    a.remove(2);
    std::cout << a << std::endl;
    a.reverse();
    std::cout << a << std::endl;
    a.clear();
    std::cout << a << std::endl;
    std::cout << a.size() << std::endl;
    a.push_back(9);
    std::cout << a.pop_back() << std::endl;
    std::cout << a << std::endl;
    std::cout << a.size() << std::endl;
}

int main() {
    fl();
    dll();

    return 0;
}
