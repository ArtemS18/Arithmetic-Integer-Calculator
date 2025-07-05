#include <iostream>
#ifndef TOOLS_HPP
#define TOOLS_HPP
using namespace std;
namespace Tools {
    int DefPriority(char ch);
    void AddSpace(char* newS, int& k);
    template <typename T>
    T Oper(T v1, T v2, char ch) {
        switch (ch) {
        case '+': return v1 + v2; break;
        case '-': return v1 - v2; break;
        case '*': return v1 * v2; break;
        case '/':if (v2 != 0) { return T(v1 / v2); }
                else { cout << "Ошибка: Деление на 0"; exit(0); }; break;
        case '^': return T(pow(v1, v2)); break;
        case 'm': return abs(v1); break;
        }
    }
    
}
#endif