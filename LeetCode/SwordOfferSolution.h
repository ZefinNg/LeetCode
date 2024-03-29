#pragma once
#include <vector>
#include "DataType.h"
#include <stack>
#include <string>
#include "CQueue.h"
#include <queue>

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

    //剑指 Offer 10- I. 斐波那契数列
    static int fib(int n);

    //剑指 Offer 10- II. 青蛙跳台阶问题
    static int numWays(int n);

    //剑指 Offer 11. 旋转数组的最小数字
    static int minArray(vector<int>& nums);

    //剑指 Offer 15. 二进制中1的个数
    static int hammingWeight(uint32_t n);

    //剑指 Offer 17. 打印从1到最大的n位数
    static vector<int> printNumbers(int n);

    //剑指 Offer 18. 删除链表的节点
    static ListNode* deleteNode(ListNode* head, int val);

    //剑指 Offer 21. 调整数组顺序使奇数位于偶数前面
    static vector<int> exchange(vector<int>& nums);

    //剑指 Offer 22. 链表中倒数第k个节点
    static ListNode* getKthFromEnd(ListNode* head, int k);

    //剑指 Offer 25. 合并两个排序的链表
    static ListNode* mergeTwoLists(ListNode* l1, ListNode* l2);

    //剑指 Offer 27. 二叉树的镜像
    static TreeNode* mirrorTree(TreeNode* root);

    //剑指 Offer 28. 对称的二叉树
    static bool isSymmetric(TreeNode* root);
    static bool isSymmetric(TreeNode* left, TreeNode* right);

    //剑指 Offer 29. 顺时针打印矩阵
    static vector<int> spiralOrder(vector<vector<int>>& matrix);

#if 1
    //剑指 Offer 32 - II. 从上到下打印二叉树 II
    static vector<vector<int>> levelOrder(TreeNode* root);
#else
    //剑指 Offer 32 - I. 从上到下打印二叉树
    static vector<int> levelOrder(TreeNode* root);
#endif

    //剑指 Offer 39. 数组中出现次数超过一半的数字
    static int majorityElement(vector<int>& nums);
};

