#include "Headers.h"
using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");
    cout << "TEST VERSION\n";
    char inpStr[100];//"m(12*(132-1122))-(123*7+12-(234+98*(-12989+123)*m(992*(34+6^(234/23))/23*23/2-(2394*231)+938)/(12-923+123*1-83-289)*239+902+92-12)-39)";
    cin >> inpStr;
    char* p_inpStr = inpStr;

    int Len = strlen(inpStr);
    int newLen = cheakInput(inpStr, Len);

    if (Len != newLen) {
        p_inpStr = new char[newLen];
        createNewStr(p_inpStr, inpStr, Len);
    }

    char* newStr = new char[newLen*2];
    postfixNotation(p_inpStr, newStr, newLen);
    cout << "DEBUG: " << newStr << endl;
    cout << "ANSWER: ";
    coutingValue(newStr);
}
