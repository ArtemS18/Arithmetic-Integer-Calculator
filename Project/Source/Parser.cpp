#include "Headers.h"
using namespace std;

int defPriority(char);
int64_t oper(int64_t v1, int64_t v2, char ch);

void stackAdd(char* stack, char ch, int& id);
void addSpace(char* newS, int& k);
void stackToStr(char* stack, char* newS, int& id, int& k);


void postfixNotation(char* s, char* newS, int len) {
    int strPos = 0, stackPos = 0;
    char* stack = new char[len];
    char p = ' ';

    for (int i = 0; i < len+1; i++) {
        if (isdigit(s[i])) {
            newS[strPos] = s[i];
            strPos++;
        }
        else if (defPriority(s[i])) {
            addSpace(newS, strPos);
            while (stackPos != 0 && (defPriority(s[i]) <= defPriority(stack[stackPos - 1])) && stack[stackPos - 1] != '(') {
                newS[strPos] = stack[stackPos - 1];
                stackPos--;strPos++;
            }
            stackAdd(stack, s[i], stackPos);
        }
        else if (s[i] == '(') {
            stackAdd(stack, s[i], stackPos);
        }
        else if (s[i] == ')') {
            while (stackPos != 0) {
                if (stack[stackPos - 1] == '(') {
                    stackPos--;
                    break;
                }
                newS[strPos] = stack[stackPos - 1];
                stackPos--;strPos++;
            }
        }
    }
    while (stackPos > 0) { 
        addSpace(newS, strPos);
        newS[strPos] = stack[stackPos - 1];
        stackPos--;strPos++;
    }
    newS[strPos] = '\0';
}
void coutingValue(char* newS) {
    int len = strlen(newS);
    int k = 0, stackPos = 0;

    int64_t* stack = new int64_t[len];

    int64_t val;
    char createrInteger[128];
    for (int i = 0; i < len; i++) {
        if (isdigit(newS[i])) {
            while (isdigit(newS[i])) {
                createrInteger[k] = newS[i];
                k++;i++;
            }
            createrInteger[k] = '\0';
            stack[stackPos] = int64_t(atoi(createrInteger));
            stackPos++;
            k = 0;
            i--;
       }
         else if (defPriority(newS[i])) {
            if (newS[i] == 'm') {
                val = oper(stack[stackPos - 1], 0, newS[i]);
                stackPos -= 1;
            }
            else {
                val = oper(stack[stackPos - 2], stack[stackPos - 1], newS[i]);
                stackPos -= 2;

            }
            stack[stackPos] = val;
            stackPos++;
        }
    }
    cout << stack[stackPos-1];
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
int64_t oper(int64_t v1, int64_t v2, char ch) {
    switch (ch) {
    case '+': return v1 + v2;break;
    case '-': return v1 - v2; break;
    case '*': return v1 * v2; break;
    case '/': if (v2 != 0) { return int64_t(v1 / v2); }
              else { cout << "Ошибка: Деление на 0"; exit(0); }; break;
    case '^': return int64_t(pow(v1, v2));break;
    case 'm': return abs(v1);break;
    }
}

void stackAdd(char* stack, char ch, int& id) {
    stack[id] = ch;
    id++;
}

void addSpace(char* newS, int& k) {
    newS[k] = ' ';
    k++;
}

void stackToStr(char* stack, char* newS, int& id, int& k) {
    newS[k] = stack[id - 1];
    id--;k++;
}
