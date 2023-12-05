#include <iostream>
#include <math.h>

namespace StackInt {
	template <typename T>
	struct Stack {
		T* items;
		int top;
	};
	template <typename T>
	T oper(T v1, T v2, char ch);

	template <typename T>
	void addStack(Stack<T>& stack, T val);

	template <typename T>
	void dellStack(Stack<T>& stack);

	template <typename T>
	T getStack(Stack<T>& stack);

	template <typename T>
	void sumStack(Stack<T>& stack, int k, char ch);

	template <typename T>
	void addLine(Stack<T>& stack, T* newS, int& strPos);

	template <typename T>
	bool isEmpty(Stack<T>& stack);
};

