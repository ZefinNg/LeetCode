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

	//206.反转链表
	static ListNode* reverseList(ListNode *head);

	//217.存在重复元素
	static bool containsDuplicate(vector<int> &nums);

	//231.2的幂
	static bool isPowerOfTwo(int n);

	//235.二叉搜索树的最近公共祖先
	static vector<TreeNode*> getPath(TreeNode *root, TreeNode *target);
	static TreeNode* lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q);

	//237.删除链表中的节点
	static void deleteNode(ListNode *node);

	//292.Nim 游戏
	static bool canWinNim(int n);

	//344.反转字符串
	static void reverseString(vector<char> &s);

	//557.反转字符串中的单词III
	static string reverseWords(string s);

	//700.二叉搜索树中的搜索
	static TreeNode *searchBST(TreeNode *root, int val);

	//458.可怜的小猪
	static int poorPigs(int buckets, int minutesToDie, int minutesToTest);

	//5.最长回文字符串
	static string longestPalindrome(string s);

	//8.字符串转换整数
	int myAtoi(string s);

	//11.盛最多水的容器
	static int maxArea(vector<int>& height);

	//16.最接近的三数之和
	static int threeSumClosest(vector<int> &nums, int target);

	//33.搜索旋转排序数组
	static int search(vector<int>& nums, int target);

	//43.字符串相乘
	static string multiply(string num1, string num2);

	//46.全排列
	void backtrack(vector<vector<int>>& result, vector<int>& output, int first, int len);
	vector<vector<int>> permute(vector<int>& nums);

	//54.螺旋矩阵
	vector<int> spiralOrder(vector<vector<int>> &matrix);

	//55.螺旋矩阵II
	vector<vector<int>> generateMatrix(int n);

	//61.旋转链表
	ListNode* rotateRight(ListNode* head, int k);

	//62.不同路径
	int uniquePaths(int m, int n);

	//78.子集
	vector<vector<int>> subsets(vector<int>& nums);
	void dfs(vector<vector<int>>& answer, vector<int>& srcNums, int index, vector<int>& tempNum);

	//89.格雷编码
	vector<int> grayCode(int n);

	//122.买卖股票的最佳时机II
	static int maxProfitII(vector<int>& prices);

	//142.环形链表II
	static ListNode* detectCycle(ListNode *head);

    //148.排序链表
    ListNode* sortList(ListNode *head);
    ListNode* sortList(ListNode* head, ListNode* tail);
    ListNode* merge(ListNode* head1, ListNode* head2);

    //215.数组中的第K个最大元素
    static int findKthLargest(vector<int>& nums, int k);

    //230.二叉搜索树中第k小的元素
    int kthSmallest(TreeNode *root, int k);
};

