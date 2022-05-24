#pragma once
#include <stack>

class CQueue
{
public:
    CQueue();
    
    void appendTail(int value);
    int deleteHead();

private:
    void in2Out();

private:
    std::stack<int> m_stackIn;
    std::stack<int> m_stackOut;
};

