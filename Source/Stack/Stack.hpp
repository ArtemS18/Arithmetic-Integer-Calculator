#include <iostream>
#include <math.h>
#include "Tools.hpp"

#ifndef STACK_HPP
#define STACK_HPP
namespace StackInt {
	template <typename T>
	struct Stack {
		T* items;
		int top;
	};

	template <typename T>
	void AddStack(Stack<T>& stack, T val) {
		stack.items[stack.top] = val;
		stack.top++;
	}

	template <typename T>
	void DellStack(Stack<T>& stack) {
		stack.top--;
	}

	template <typename T>
	T GetStack(Stack<T>& stack) {
		return stack.items[stack.top - 1];
	}

	template <typename T>
	void SumStack(Stack<T>& stack, int k, char ch) {
		T answ = 0;
		switch (k) {
		case 1:
			answ = Tools::Oper<T>(stack.items[stack.top - 1], 0, ch);
			stack.top -= 1;

			break;
		case 2:
			answ = Tools::Oper<T>(stack.items[stack.top - 2], stack.items[stack.top - 1], ch);
			stack.top -= 2;
			break;
		}
		AddStack(stack, answ);
	}

	template <typename T>
	void AddLine(Stack<T>& stack, T* newS, int& strPos) {
		newS[strPos] = stack.items[stack.top - 1];
		stack.top--; strPos++;
	}

	template <typename T>
	bool IsEmpty(Stack<T>& stack) {
		if (stack.top > 0) { return 0; }
		return 1;
	}
};

#endif