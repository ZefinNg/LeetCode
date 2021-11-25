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

	//206.反转链表
	static ListNode* reverseList(ListNode *head);

	//217.存在重复元素
	static bool containsDuplicate(vector<int> &nums);

	//231.2的幂
	static bool isPowerOfTwo(int n);

	//235.二叉搜索树的最近公共祖先
	vector<TreeNode*> getPath(TreeNode *root, TreeNode *target);
	static TreeNode* lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q);
};

