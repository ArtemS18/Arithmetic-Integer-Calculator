#include "Stack.hpp"
//void StackInt::StackInt(int64_t* arr) {
//	ST::stack = arr;
//	ST::stackPos = 0;
//}
template <typename T>
T StackInt::getStack(Stack<T>& stack) {
	return stack.items[stack.top - 1];
}
template <typename T>
T StackInt::oper(T v1, T v2, char ch) {
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
template <typename T>
void StackInt::addStack(Stack<T>& stack, T val) {
	stack.items[stack.top] = val;
	stack.top++;
}
template <typename T>
void StackInt::dellStack(Stack<T>& stack) {
	stack.top--;
}

template <typename T>
void StackInt::sumStack(Stack<T>& stack, int k, char ch) {
	T answ = 0;
	switch (k) {
	case 1:
		answ = oper(stack.items[stack.top - 1], T(0), ch);
		stack.top -= 1;

		break;
	case 2:
		answ = oper(stack.items[stack.top - 2], stack.items[stack.top - 1], ch);
		stack.top -= 2;
		break;
	}
	addStack(stack, answ);
}
template <typename T>
void StackInt::addLine(Stack<T>& stack, T* newS, int& strPos) {
	newS[strPos] = stack.items[stack.top - 1];
	stack.top--; strPos++;
}

template <typename T>
bool StackInt::isEmpty(Stack<T>& stack) {
	if (stack.top > 0) { return 0; }
	return 1;
}