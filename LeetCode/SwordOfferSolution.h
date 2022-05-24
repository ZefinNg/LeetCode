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

    //��ָ Offer 03. �������ظ�������
    static int findRepeatNumber(vector<int>& nums);

    //��ָ Offer 05. �滻�ո�
    static string replace(string s);

    //��ָ Offer 06. ��β��ͷ��ӡ����
    static vector<int> reversePrint(ListNode* head);

    //��ָ Offer 09. ������ջʵ�ֶ���
    CQueue m_myQueue;
};

