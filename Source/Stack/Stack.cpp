//#include "Stack.hpp"
//#include "Tools.hpp"
////void StackInt::StackInt(int64_t* arr) {
////	ST::stack = arr;
////	ST::stackPos = 0;
////}
//template <typename T>
//T StackInt::GetStack(Stack<T>& stack) {
//	return stack.items[stack.top - 1];
//}
//
//template <typename T>
//void StackInt::AddStack(Stack<T>& stack, T val) {
//	stack.items[stack.top] = val;
//	stack.top++;
//}
//
//template <typename T>
//void StackInt::DellStack(Stack<T>& stack) {
//	stack.top--;
//}
//
//template <typename T>
//void StackInt::SumStack(Stack<T>& stack, int k, char ch) {
//	T answ = 0;
//	switch (k) {
//	case 1:
//		answ = Tools::Oper(stack.items[stack.top - 1], 0, ch);
//		stack.top -= 1;
//
//		break;
//	case 2:
//		answ = Tools::Oper(stack.items[stack.top - 2], stack.items[stack.top - 1], ch);
//		stack.top -= 2;
//		break;
//	}
//	AddStack(stack, answ);
//}
//
//template <typename T>
//void StackInt::AddLine(Stack<T>& stack, T* newS, int& strPos) {
//	newS[strPos] = stack.items[stack.top - 1];
//	stack.top--; strPos++;
//}
//
//template <typename T>
//bool StackInt::IsEmpty(Stack<T>& stack) {
//	if (stack.top > 0) { return 0; }
//	return 1;
//}