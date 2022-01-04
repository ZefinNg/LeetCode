#pragma once

#include <iostream>
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
};

