#include "Headers.h"
#include "CheckLine.hpp"

using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");
    cout << "TEST VERSION\n";

    char p[100];
    cin >> p;

    char* inpStr = new char[strlen(p) + 1];
    strcpy_s(inpStr, strlen(p)+1, p);

    char* p_inpStr = inpStr;

    int Len = strlen(inpStr);
    int newLen = CheckLine::CheckInput(inpStr, Len);

    if (Len != newLen) {
        p_inpStr = new char[newLen];
        CheckLine::CreateNewStr(p_inpStr, inpStr, Len);
    }
    char* newStr = new char[newLen * 2];
    PostfixNotation(p_inpStr, newStr, newLen);

    cout << "DEBUG: " << newStr << endl;
    cout << "ANSWER: ";
    CoutingValue(newStr);
    delete [] newStr;  delete[] p_inpStr;
    return 0;
}
