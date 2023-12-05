#include "Headers.h"
//#include "Stack.hpp"
#include "Stack.cpp"
using namespace std;

int defPriority(char);
void addSpace(char* newS, int& k);


void postfixNotation(char* s, char* newS, int len) {
    int strPos = 0, stackPos = 0;
    char* st = new char[len];
    StackInt::Stack<char> stack;
    stack.items = st;
    stack.top = 0;
    char p = ' ';

    for (int i = 0; i < len+1; i++) {
        if (isdigit(s[i])) {
            newS[strPos] = s[i];
            strPos++;
        }
        else if (defPriority(s[i])) {
            addSpace(newS, strPos);
            while (!StackInt::isEmpty<char>(stack) && defPriority(s[i]) <= defPriority(StackInt::getStack<char>(stack)) && StackInt::getStack<char>(stack) != '(') {
                StackInt::addLine(stack, newS, strPos);
            }
            StackInt::addStack<char>(stack, s[i]);
        }
        else if (s[i] == '(') {
            StackInt::addStack<char>(stack, s[i]);
        }
        else if (s[i] == ')') {
            while (!StackInt::isEmpty<char>(stack)) {
                if (StackInt::getStack<char>(stack) == '(') {
                    StackInt::dellStack<char>(stack);
                    break;
                }
                StackInt::addLine(stack, newS, strPos);
            }
        }
    }
    while (!StackInt::isEmpty<char>(stack)) {
        addSpace(newS, strPos);
        StackInt::addLine(stack, newS, strPos);
    }
    newS[strPos] = '\0';
}
void coutingValue(char* newS) {
    int len = strlen(newS);
    int k = 0, stackPos = 0;

    int64_t* st = new int64_t[len];
    StackInt::Stack<int64_t> stack;
    stack.items = st;
    stack.top = 0;

    char createrInteger[128];
    for (int i = 0; i < len; i++) {
        for (int i = 0; i < len; i++) { cout << stack.items[i] << ' '; }
        cout << endl;
        if (isdigit(newS[i])) {
            while (isdigit(newS[i])) {
                createrInteger[k] = newS[i];
                k++;i++;
            }
            createrInteger[k] = '\0';
            StackInt::addStack<int64_t>(stack, int64_t(atoi(createrInteger)));
            k = 0;
            i--;
       }
         else if (defPriority(newS[i])) {
            if (newS[i] == 'm') {
                StackInt::sumStack<int64_t>(stack, 1, newS[i]);
            }
            else {
                StackInt::sumStack<int64_t>(stack, 2, newS[i]);

            }
        }
    }
    cout << StackInt::getStack<int64_t>(stack);
}

int defPriority(char ch) {
    switch (ch) {
    case '+': return 1; break;
    case '-': return 1; break;
    case '*': return 2; break;
    case '/': return 2; break;
    case '^': return 3; break;
    case 'm': return 4; break;
    default:  return 0; break;
    }
}

void addSpace(char* newS, int& k) {
    newS[k] = ' ';
    k++;
}

