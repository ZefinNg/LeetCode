// LeetCode.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <vector>
#include <iostream>
#include <string>
#include "Solution.h"

using namespace std;

int main()
{
#if 0
	int array[] = { 1000000000,1000000000,1000000000,1000000000 };
	vector<int> test(array, array + sizeof(array)/sizeof(int));

	vector<vector<int>> result = Solution::fourSum(test, 0);

	cout << "result:" << endl;
	for (int i = 0; i < result.size(); i++) {
		for (int j = 0; j < result.at(i).size(); j++) {
			cout << result.at(i).at(j);
			cout << ",";
		}
		cout << endl;
	}
#elif 0
	cout << "result:" << Solution::fib(4) << endl;
#elif 0
	ListNode *l1 = new ListNode();
	ListNode *temp = l1;
	for (int i = 0; i < 7; i++) {
		temp->val = 9;
		if (i != 6) {
			temp->next = new ListNode();
			temp = temp->next;
		}
	}

	ListNode *l2 = new ListNode();
	temp = l2;
	for (int j = 0; j < 4; j++) {
		temp->val = 9;
		if (j != 3) {
			temp->next = new ListNode();
			temp = temp->next;
		}
	}

	temp = Solution::addTwoNumbers(l1, l2);
#elif 0
	int result = Solution::reverse(1534236469);
	cout << "reverse:" << result << endl;
#elif 0
	cout << "result:" << Solution::isPalindrome(101) << endl;
#elif 0
	vector<string> strs;
	strs.push_back("flower");
	strs.push_back("flow");
	strs.push_back("flight");

	cout << "result:" << Solution::longestCommonPrefix(strs) << endl;
#elif 0
	int array1[3] = { 1,2,4 };
	int array2[3] = { 1,3,4 };

	ListNode *l1 = new ListNode();
	ListNode *l2 = new ListNode();

	ListNode *locator1 = l1;
	ListNode *locator2 = l2;

	for (int i = 0; i < 3; i++) {
		locator1->val = array1[i];
		locator2->val = array2[i];

		if (i < 2) {
			locator1->next = new ListNode();
			locator2->next = new ListNode();

			locator1 = locator1->next;
			locator2 = locator2->next;
		}
	}
	ListNode *result = Solution::mergeTwoLists(l1, l2);
#elif 0
	vector<int> nums;
	nums.push_back(1);
	nums.push_back(1);
	nums.push_back(2);

	std::cout << "result:" << Solution::removeDuplicates(nums) << endl;
#elif 0
	cout << "result:" << Solution::reverseWords("hello world") << endl;
#elif 0
	cout << "result:" << Solution::longestPalindrome("bb") << endl;
#elif 0
	int array[] = { 1,8,6,2,5,4,8,3,7 };
	vector<int> test(array, array + sizeof(array) / sizeof(int));

	cout << "result:" << Solution::maxArea(test) << endl;
#elif 0
	int array[] = {3,1};
	vector<int> test(array, array + sizeof(array) / sizeof(int));

	cout << "result:" << Solution::search(test, 1) << endl;
#elif 0
	cout << "result:" << Solution::multiply("9", "99") << endl;
#else

#endif

    return 0;
}