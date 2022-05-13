#pragma once

#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <unordered_set>
#include <unordered_map>
#include "LRUCache.h"

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode *next) : val(x), next(next) {}
};

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

struct CLS {
	int m_i;
	CLS(int i) : m_i(i) {
	}
	CLS() {
		CLS(0);
	}
};

class Solution
{
public:
	Solution();
	~Solution();

	static vector<vector<int>> threeSum(vector<int>& nums);
	static vector<vector<int>> fourSum(vector<int>& nums, int target);
	static int fib(int n);
	static int climbStairs(int n);
	static ListNode* addTwoNumbers(ListNode *l1, ListNode *l2);
	static bool canPartition(vector<int>& nums);
	static int reverse(int x);
	static bool isPalindrome(int x);
	static string longestCommonPrefix(vector<string>& strs);
	static bool isVaild(string s);
	static ListNode* mergeTwoLists(ListNode *l1, ListNode *l2);
	static int removeDuplicates(vector<int>& nums);
	static void merge(vector<int> &nums1, int m, vector<int> &nums2, int n);
	static int maxProfit(vector<int> &prices);
	static int singleNumber(vector<int> &nums);
	static bool hasCycle(ListNode* head);
	static int majorityElement(vector<int> &nums);

	//206.��ת����
	static ListNode* reverseList(ListNode *head);

	//217.�����ظ�Ԫ��
	static bool containsDuplicate(vector<int> &nums);

	//231.2����
	static bool isPowerOfTwo(int n);

	//235.�����������������������
	static vector<TreeNode*> getPath(TreeNode *root, TreeNode *target);
	static TreeNode* lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q);

	//237.ɾ�������еĽڵ�
	static void deleteNode(ListNode *node);

	//292.Nim ��Ϸ
	static bool canWinNim(int n);

	//344.��ת�ַ���
	static void reverseString(vector<char> &s);

	//557.��ת�ַ����еĵ���III
	static string reverseWords(string s);

	//700.�����������е�����
	static TreeNode *searchBST(TreeNode *root, int val);

	//458.������С��
	static int poorPigs(int buckets, int minutesToDie, int minutesToTest);

	//5.������ַ���
	static string longestPalindrome(string s);

	//8.�ַ���ת������
	int myAtoi(string s);

	//11.ʢ���ˮ������
	static int maxArea(vector<int>& height);

	//16.��ӽ�������֮��
	static int threeSumClosest(vector<int> &nums, int target);

	//33.������ת��������
	static int search(vector<int>& nums, int target);

	//43.�ַ������
	static string multiply(string num1, string num2);

	//46.ȫ����
	void backtrack(vector<vector<int>>& result, vector<int>& output, int first, int len);
	vector<vector<int>> permute(vector<int>& nums);

	//54.��������
	vector<int> spiralOrder(vector<vector<int>> &matrix);

	//55.��������II
	vector<vector<int>> generateMatrix(int n);

	//61.��ת����
	ListNode* rotateRight(ListNode* head, int k);

	//62.��ͬ·��
	int uniquePaths(int m, int n);

	//78.�Ӽ�
	vector<vector<int>> subsets(vector<int>& nums);
	void dfs(vector<vector<int>>& answer, vector<int>& srcNums, int index, vector<int>& tempNum);

	//89.���ױ���
	vector<int> grayCode(int n);

	//122.������Ʊ�����ʱ��II
	static int maxProfitII(vector<int>& prices);

	//142.��������II
	static ListNode* detectCycle(ListNode *head);

    //148.��������
    ListNode* sortList(ListNode *head);
    ListNode* sortList(ListNode* head, ListNode* tail);
    ListNode* merge(ListNode* head1, ListNode* head2);

    //215.�����еĵ�K�����Ԫ��
    static int findKthLargest(vector<int>& nums, int k);

    //230.�����������е�kС��Ԫ��
    int kthSmallest(TreeNode *root, int k);
};

