#pragma once

#include <vector>
#include <algorithm>
#include <stack>
#include <unordered_set>
#include <unordered_map>

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
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution
{
public:
	Solution();
	~Solution();

	vector<vector<int>> threeSum(vector<int>& nums);
	vector<vector<int>> fourSum(vector<int>& nums, int target);
	int fib(int n);
	int climbStairs(int n);
	ListNode* addTwoNumbers(ListNode *l1, ListNode *l2);
	bool canPartition(vector<int>& nums);
	int reverse(int x);
	bool isPalindrome(int x);
	string longestCommonPrefix(vector<string>& strs);
	bool isVaild(string s);
	ListNode* mergeTwoLists(ListNode *l1, ListNode *l2);
	int removeDuplicates(vector<int>& nums);
	void merge(vector<int> &nums1, int m, vector<int> &nums2, int n);
	int maxProfit(vector<int> &prices);
	int singleNumber(vector<int> &nums);
	bool hasCycle(ListNode* head);
	int majorityElement(vector<int> &nums);

	//206.��ת����
	ListNode* reverseList(ListNode *head);

	//217.�����ظ�Ԫ��
	bool containsDuplicate(vector<int> &nums);

	//231.2����
	bool isPowerOfTwo(int n);

	//235.�����������������������
	vector<TreeNode*> getPath(TreeNode *root, TreeNode *target);
	TreeNode* lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q);

	//237.ɾ�������еĽڵ�
	void deleteNode(ListNode *node);

	//292.Nim ��Ϸ
	bool canWinNim(int n);
};

