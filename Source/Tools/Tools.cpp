#include "Tools.hpp"
using namespace std;
void Tools::AddSpace(char* newS, int& k) {
    newS[k] = ' ';
    k++;
}
int Tools::DefPriority(char ch) {
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
