#include "stdafx.h"
#include "CQueue.h"


CQueue::CQueue()
{
}

void CQueue::appendTail(int value)
{
    m_stackIn.push(value);
}

int CQueue::deleteHead()
{
    if (m_stackOut.empty()) {
        if (m_stackIn.empty())
            return -1;
    
        this->in2Out();
    }

    int value = m_stackOut.top();
    m_stackOut.pop();

    return value;
}

void CQueue::in2Out()
{
    while (!m_stackIn.empty()) {
        m_stackOut.push(m_stackIn.top());
        m_stackIn.pop();
    }
}
