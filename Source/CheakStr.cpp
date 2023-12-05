#include "Headers.h"
using namespace std;

bool cheakSymbol(char*, int);
void coutShift(char*, int, int&);

int cheakInput(char* s, int Len) {
    int newLen = Len;
    int ms = 0; bool f;
    int shift = 0;

    if (s[0] == '-') {
        newLen += 1;
    }
    for (int i = 0; i < newLen; i++) {
        cheakSymbol(s, i);
        if (i > 0 && s[i - 1] == '(' and s[i] == '-') {
            newLen += 1;
        }
        else if (s[i] == '|') { ms++; }
    }
    newLen += int(ms / 2);
    return newLen;
}
// |1+3|+1-1+|1+12|
// |12+|12+23|+12 |
void cheakModul(char* newStr, char* prevStr, int& prevPos, int& newPos, int &shift) {
   bool  f = 0;
    if (prevPos == 0) {
        newStr[newPos] = 'm';
        newStr[newPos + 1] = '(';
        f = 1;
        shift++;
    }
    else if (prevStr[prevPos - 1] == '|') {
        if (f) {
            newStr[newPos] = 'm'; newStr[newPos + 1] = '(';
            f = 1; shift++;
        }
        else {
            newStr[newPos] = ')';
            f = 0;
        }
    }
    else if ((isdigit(prevStr[prevPos - 1]) || prevStr[prevPos - 1] == ')') && !isdigit(prevStr[prevPos + 1])) {
        newStr[newPos] = ')';
        f = 0;

    }
    else {
        newStr[newPos] = 'm'; newStr[newPos + 1] = '(';
        f = 1; shift++;
    }

}
void createNewStr(char* newStr, char* prevStr, int prevLen) {
    int  shift = 0, space =0;
    if (prevStr[0] == '-') {
        newStr[0] = '0';
        for (int j = 1; j < prevLen; j++) {
            newStr[j] = prevStr[j - 1];
        }
        shift++;
    }
    for (int i = 0; i < prevLen; i++) {
        int newPos = i + shift;
        int  prevPos = i ;
        if (i > 0 && prevStr[prevPos - 1] == '(' && prevStr[prevPos] == '-') {
            newStr[newPos] = '0';
            newStr[newPos + 1] = '-';
            shift++;
        }
        else if (prevStr[prevPos] == '|') {  
            cheakModul(newStr, prevStr, prevPos, newPos, shift);
            
        }
        else {
             newStr[newPos] = prevStr[prevPos]; 
        }
    }
}

bool cheakSymbol(char* s, int i) {
    char allSymbols[] = "+-*/^m ()|";
    bool f = 1;
    for (int g = 0; g < strlen(allSymbols); g++) {
        if (s[i] == allSymbols[g]) { f = 0; break; }
    }
    if (!isdigit(s[i]) && f && s[i] != '\0') { cout << "Ошибка: Обнаружен недопустимый символ (" << s[i] << ")" << endl; exit(0); }

}
void coutShift(char* s, int i, int& newLen) {
    if (i > 0 && s[i - 1] == '(' and s[i] == '-') {
        newLen += 1;
    }
    else if (s[i] == '|'){}
}