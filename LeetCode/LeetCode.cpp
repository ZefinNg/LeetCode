// LeetCode.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <vector>
#include <iostream>
#include <string>
#include "Solution.h"
#include "SwordOfferSolution.h"

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
#elif 0
	int temp1[] = {1, 2, 3};
	vector<int> temp1Vector(temp1, temp1 + 3);

	int temp2[] = {4, 5, 6};
	vector<int> temp2Vector(temp2, temp2 + 3);

	int temp3[] = {7, 8, 9};
	vector<int> temp3Vector(temp3, temp3 + 3);

	vector<vector<int>> matrix;
	matrix.push_back(temp1Vector);
	matrix.push_back(temp2Vector);
	matrix.push_back(temp3Vector);

	Solution solution;
	solution.spiralOrder(matrix);
#elif 0
    Solution solution;
	solution.generateMatrix(4);
#elif 0
    CLS obj;
	cout << obj.m_i << endl;
#elif 0
    int result;
    LRUCache lRUCache(2);
	lRUCache.put(1, 1); // 缓存是 {1=1}
	lRUCache.put(2, 2); // 缓存是 {1=1, 2=2}
	result = lRUCache.get(1);    // 返回 1
    lRUCache.put(3, 3); // 该操作会使得关键字 2 作废，缓存是 {1=1, 3=3}
	result = lRUCache.get(2);    // 返回 -1 (未找到)
    lRUCache.put(4, 4); // 该操作会使得关键字 1 作废，缓存是 {4=4, 3=3}
	result = lRUCache.get(1);    // 返回 -1 (未找到)
	result = lRUCache.get(3);    // 返回 3
	result = lRUCache.get(4);    // 返回 4
#elif 0
    int array[] = { 3,2,1,5,6,4 };
    vector<int> test(array, array + sizeof(array) / sizeof(int));

    int result = Solution::findKthLargest(test, 2);
#elif 0
    int array[] = { 3, 4, 2, 0, 0, 1 };
    vector<int> test(array, array + sizeof(array) / sizeof(int));

    int result = SwordOfferSolution::findRepeatNumber(test);
#elif 0
    ListNode *head = new ListNode(1);
    ListNode *mid = new ListNode(3);
    ListNode *tail = new ListNode(2);

    head->next = mid;
    mid->next = tail;
    tail->next = nullptr;

    vector<int> result = SwordOfferSolution::reversePrint(head);

    delete head;
    delete mid;
    delete tail;
#elif 0
    int value = SwordOfferSolution::fib(43);
#else
    int count = SwordOfferSolution::hammingWeight(11);
#endif

    return 0;
}