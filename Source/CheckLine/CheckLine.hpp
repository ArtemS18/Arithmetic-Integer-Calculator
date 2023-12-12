namespace CheckLine{
    int CheckInput(char* s, int Len);

    void CheckModul(char* newStr, char* prevStr, int& prevPos, int& newPos, int &shift);

    void CreateNewStr(char* newStr, char* prevStr, int prevLen);

    bool CheckSymbol(char* s, int i) ;

    void CoutShift(char* s, int i, int& newLen) ;
}
