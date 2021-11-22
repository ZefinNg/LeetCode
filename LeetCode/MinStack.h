#pragma once

#include <stack>
#include <algorithm>

using namespace std;

class MinStack
{
public:
	MinStack();
	~MinStack();

	void push(int val);
	void pop();
	int top();
	int getMin();

private:
	stack<int> m_stack;
	stack<int> m_minStack;
};

