#include "stdafx.h"
#include "MinStack.h"


MinStack::MinStack()
{
}


MinStack::~MinStack()
{
}

void MinStack::push(int val)
{
	m_stack.push(val);
	m_minStack.push(min(m_minStack.top(), val));
}

void MinStack::pop()
{
	m_stack.pop();
	m_minStack.pop();
}

int MinStack::top()
{
	return m_stack.top();
}

int MinStack::getMin()
{
	return m_minStack.top();
}
