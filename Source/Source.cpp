#include "Headers.h"
#include "Tools.hpp"
#include "Stack.hpp"
using namespace std;

void PostfixNotation(char* s, char* newS, int len) {
    int strPos = 0, stackPos = 0;
    char* st = new char[len];
    StackInt::Stack<char> stack;
    stack.items = st;
    stack.top = 0;

    for (int i = 0; i < len + 1; i++) {
        if (isdigit(s[i])) {
            newS[strPos] = s[i];
            strPos++;
        }
        else if (Tools::DefPriority(s[i])) {
            Tools::AddSpace(newS, strPos);
            while (!StackInt::IsEmpty<char>(stack) && Tools::DefPriority(s[i]) <= Tools::DefPriority(StackInt::GetStack<char>(stack)) && StackInt::GetStack<char>(stack) != '(') {
                StackInt::AddLine<char>(stack, newS, strPos);
            }
            StackInt::AddStack<char>(stack, s[i]);
        }
        else if (s[i] == '(') {
            StackInt::AddStack<char>(stack, s[i]);
        }
        else if (s[i] == ')') {
            while (!StackInt::IsEmpty<char>(stack)) {
                if (StackInt::GetStack<char>(stack) == '(') {
                    StackInt::DellStack<char>(stack);
                    break;
                }
                StackInt::AddLine<char>(stack, newS, strPos);
            }
        }
    }
    while (!StackInt::IsEmpty<char>(stack)) {
        Tools::AddSpace(newS, strPos);
        StackInt::AddLine<char>(stack, newS, strPos);
    }
    newS[strPos] = '\0';
}
void CoutingValue(char* newS) {
    int len = strlen(newS);
    int k = 0, stackPos = 0;

    int64_t* st = new int64_t[len];
    StackInt::Stack<int64_t> stack;
    stack.items = st;
    stack.top = 0;

    char createrInteger[128];
    for (int i = 0; i < len; i++) {
       /* for (int i = 0; i < len; i++) { cout << stack.items[i] << ' '; }
        cout << endl;*/
        if (isdigit(newS[i])) {
            while (isdigit(newS[i])) {
                createrInteger[k] = newS[i];
                k++; i++;
            }
            createrInteger[k] = '\0';
            StackInt::AddStack<int64_t>(stack, int64_t(atoi(createrInteger)));
            k = 0;
            i--;
        }
        else if (Tools::DefPriority(newS[i])) {
            if (newS[i] == 'm') {
                StackInt::SumStack<int64_t>(stack, 1, newS[i]);
            }
            else {
                StackInt::SumStack<int64_t>(stack, 2, newS[i]);

            }
        }
    }
    cout << StackInt::GetStack<int64_t>(stack);
}