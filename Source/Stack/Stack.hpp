#include <iostream>
#include <math.h>

namespace StackInt {
	template <typename T>
	struct Stack {
		T* items;
		int top;
	};
	template <typename T>
	T Oper(T v1, T v2, char ch);

	template <typename T>
	void AddStack(Stack<T>& stack, T val);

	template <typename T>
	void DellStack(Stack<T>& stack);

	template <typename T>
	T GetStack(Stack<T>& stack);

	template <typename T>
	void SumStack(Stack<T>& stack, int k, char ch);

	template <typename T>
	void AddLine(Stack<T>& stack, T* newS, int& strPos);

	template <typename T>
	bool IsEmpty(Stack<T>& stack);
};

