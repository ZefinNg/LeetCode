#pragma once
#include <vector>
#include "ListNode.h"
#include <stack>
#include <string>
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

    //��ָ Offer 10- I. 쳲���������
    static int fib(int n);

    //��ָ Offer 10- II. ������̨������
    static int numWays(int n);

    //��ָ Offer 11. ��ת�������С����
    static int minArray(vector<int>& nums);

    //��ָ Offer 15. ��������1�ĸ���
    static int hammingWeight(uint32_t n);

    //��ָ Offer 17. ��ӡ��1������nλ��
    static vector<int> printNumbers(int n);

    //��ָ Offer 18. ɾ������Ľڵ�
    static ListNode* deleteNode(ListNode* head, int val);
};

