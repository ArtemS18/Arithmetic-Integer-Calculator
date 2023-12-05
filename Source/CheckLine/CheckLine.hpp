namespace checkLine{
    int cheakInput(char* s, int Len);

    void cheakModul(char* newStr, char* prevStr, int& prevPos, int& newPos, int &shift);

    void createNewStr(char* newStr, char* prevStr, int prevLen);

    bool cheakSymbol(char* s, int i) ;

    void coutShift(char* s, int i, int& newLen) ;
}
