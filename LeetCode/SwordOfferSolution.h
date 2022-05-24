#pragma once
#include <vector>
#include "ListNode.h"
#include <stack>
#include "CQueue.h"

using namespace std;

class SwordOfferSolution
{
public:
    SwordOfferSolution();
    ~SwordOfferSolution();

    //剑指 Offer 03. 数组中重复的数字
    static int findRepeatNumber(vector<int>& nums);

    //剑指 Offer 05. 替换空格
    static string replace(string s);

    //剑指 Offer 06. 从尾到头打印链表
    static vector<int> reversePrint(ListNode* head);

    //剑指 Offer 09. 用两个栈实现队列
    CQueue m_myQueue;
};

