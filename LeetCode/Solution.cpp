#include "stdafx.h"
#include "Solution.h"


Solution::Solution()
{
}


Solution::~Solution()
{
}

vector<vector<int>> Solution::threeSum(vector<int>& nums)
{
	vector<vector<int>> result;
	int length = nums.size();
	int aIndex, bIndex, cIndex;
	int target = 0;

	//将nums从小到大排序
	sort(nums.begin(), nums.end());

	//从aValue开始遍历
	for (aIndex = 0; aIndex < length; aIndex++) {
		//需要和前一个值不同，以去重
		if (aIndex > 0 && nums[aIndex] == nums[aIndex - 1])
			continue;

		cIndex = length - 1;   //C值从右边遍历过来
		target = -nums[aIndex];//目标值就是a值的相反数,a=b+c

	    //开始遍历b
		for (bIndex = aIndex + 1; bIndex < length; bIndex++) {
			//需要和上一个值不同
			if ((bIndex > aIndex + 1) && nums[bIndex] == nums[bIndex - 1])
				continue;

			//nums已经小到大排序，如果b+c大于target，则把cIndex向左偏移
			while (bIndex < cIndex && (nums[bIndex] + nums[cIndex] > target))
				cIndex--;

			//如果b和c重合，就不会有满足a+b+c=0的情况了，可以退出循环
			if (bIndex == cIndex)
				break;

			if (nums[bIndex] + nums[cIndex] == target) {
				result.push_back({ nums[aIndex], nums[bIndex], nums[cIndex] });
			}
		}
	}

	return result;
}

vector<vector<int>> Solution::fourSum(vector<int>& nums, int target)
{
	//将nums进行排序
	sort(nums.begin(), nums.end());

	vector<vector<int>> result;
	int aIndex, bIndex, cIndex, dIndex;
	int length = nums.size();

	for (aIndex = 0; aIndex < length; aIndex++) {
		if (aIndex > 0 && nums[aIndex] == nums[aIndex - 1])
			continue;

		for (bIndex = aIndex + 1; bIndex < length; bIndex++) {
			if (bIndex > aIndex + 1 && nums[bIndex] == nums[bIndex - 1])
				continue;

			for (cIndex = bIndex + 1; cIndex < length; cIndex++) {
				if (cIndex > bIndex + 1 && nums[cIndex] == nums[cIndex - 1])
					continue;

				dIndex = length - 1;

				long long partSum = (long long)nums[aIndex] + (long long)nums[bIndex];

				while (dIndex >= 0 && (partSum + nums[cIndex] + nums[dIndex]) > target)
					dIndex--;

				if (dIndex <= cIndex)
					break;

				if ((nums[aIndex] + nums[bIndex] + nums[cIndex] + nums[dIndex]) == target)
					result.push_back({nums[aIndex], nums[bIndex], nums[cIndex], nums[dIndex]});
			}
		}
	}

	return result;
}

int Solution::fib(int n)
{
	if (n == 0)
		return 0;
	else if (n == 1)
		return 1;
	else
		return fib(n - 1) + fib(n - 2);

	return 0;
}

int Solution::climbStairs(int n)
{
	//爬楼梯的本质还是斐波那契数列：f(x) = f(x-1) + f(x-2)
	//可以使用动态数组的方式来解决
	int p = 0, q = 0, r = 1;

	for (int i = 1; i <= n; i++) {
		p = q;
		q = r;
		r = p + q;
	}

	return r;
}

ListNode* Solution::addTwoNumbers(ListNode * l1, ListNode * l2)
{
	ListNode *result = new ListNode();
	ListNode *tag = result;
	ListNode *temp1 = l1;
	ListNode *temp2 = l2;

	int sum = 0;
	bool addOne = false;

	while (temp1 != NULL || temp2 != NULL) {
		if (temp1 != NULL)
			sum += temp1->val;
		else
			sum += 0;

		if (temp2 != NULL)
			sum += temp2->val;
		else
			sum += 0;

		if (addOne)
			sum++;

		if (sum > 10) {
			addOne = true;
			tag->val = sum - 10;
		}
		else if (sum == 10) {
			addOne = true;
			tag->val = 0;
		}
		else {
			addOne = false;
			tag->val = sum;
		}

		//遍历下一个元素
		if (temp1 != NULL)
			temp1 = temp1->next;

		if (temp2 != NULL)
			temp2 = temp2->next;

		sum = 0;

		if (temp1 != NULL || temp2 != NULL) {
			//新节点
			tag->next = new ListNode();
			tag = tag->next;
		}
	}

	if (addOne) {
		tag->next = new ListNode();
		tag = tag->next;
		tag->val = 1;
	}

	return result;
}

bool Solution::canPartition(vector<int>& nums)
{
	if (nums.size() < 2)
		return false;

	int sum = 0;
	for each (auto each in nums)
		sum += each;

	if (sum % 2 == 1)
		return false;

	int target = sum / 2;
	int maxNum = *max_element(nums.begin(), nums.end());

	/*
	 *最大值大于数组之和的一半，
	 *则其余元素之和恒小于数组之和的一半
	 */
	if (maxNum > target) 
		return false;

	vector<vector<bool>> dp(nums.size(), vector<bool>(target+1, 0));

	for (int i = 0; i < nums.size(); i++)
		dp[i][0] = true;//当目标值为0时，遍历所有元素的情况都不选，则和为0，符合

	//当i为0即只有一个元素可以选，则此时选nums[i]即nums[0]则符合情况
	dp[0][nums[0]] = true;

	for (int i = 1; i < nums.size(); i++) {
		int num = nums[i];
		for (int j = 1; j <= target; j++) {
			if (num <= j)
				dp[i][j] = dp[i - 1][j] | dp[i - 1][j - num];
			else
				dp[i][j] = dp[i - 1][j];
		}
	}

	return dp[nums.size() - 1][target];
}

int Solution::reverse(int x)
{
	int temp = x;
	int result = 0;

	while (temp != 0) {
		if (result < (INT_MIN / 10) || (result > INT_MAX / 10))
			return 0;

		result = (result * 10) + (temp % 10);
		temp = temp / 10;
	}

	return result;
}

bool Solution::isPalindrome(int x)
{
	if (x < 0)
		return false;

	int temp = x;
	int newValue = 0;

	while (temp != 0) {
		if (newValue < INT_MIN / 10 || newValue > INT_MAX / 10)
			return false;

		newValue = (newValue * 10) + temp % 10;
		temp /= 10;
	}

	if (newValue == x)
		return true;

	return false;
}

string Solution::longestCommonPrefix(vector<string>& strs)
{
	string result = "";
	string unit   = "";
	string firstOne = strs[0];
	
	for (int i = 0; i < firstOne.length(); i++) {
		unit += firstOne[i];

		int j = 1;
		for (; j < strs.size(); j++) {
			if (strs[j].find(unit) == 0)
				continue;
			else
				break;
		}

		if (j == strs.size())
			result = unit;
		else
			break;
	}

	return result;
}

bool Solution::isVaild(string s)
{
	stack<char> temp;

	for (int i = 0; i < s.size(); i++) {
		switch (s[i]) {
		case '(':
		case '{':
		case '[':
			temp.push(s[i]);
			break;
		case ')':
			if (temp.size() > 0 && temp.top() == '(')
				temp.pop();
			else
				return false;
			break;
		case '}':
			if (temp.size() > 0 && temp.top() == '{')
				temp.pop();
			else
				return false;
			break;
		case ']':
			if (temp.size() > 0 && temp.top() == '[')
				temp.pop();
			else
				return false;
			break;
		default:
			break;
		}
	}

	if (temp.size() > 0)
		return false;

	return true;
}

ListNode * Solution::mergeTwoLists(ListNode * l1, ListNode * l2)
{
	if (l1 == NULL && l2 == NULL)
		return NULL;

	ListNode *result  = new ListNode();
	ListNode *locator = result;
	ListNode *tempL1  = l1;
	ListNode *tempL2  = l2;

	while (tempL1 != NULL || tempL2 != NULL) {
		if (tempL1 == NULL)
			goto temp2;

		if (tempL2 == NULL)
			goto temp1;

		if (tempL1->val < tempL2->val) {
temp1:
			locator->val  = tempL1->val;

			if (tempL1 != NULL)
			    tempL1 = tempL1->next;
		}
		else {
temp2:
			locator->val  = tempL2->val;

			if (tempL2 != NULL)
			    tempL2 = tempL2->next;
		}

		if (tempL1 == NULL && tempL2 == NULL)
			break;
		else {
			locator->next = new ListNode();
			locator = locator->next;
		}
	}

	return result;
}

int Solution::removeDuplicates(vector<int>& nums)
{
#if 0//暴力解法
	int target;
	int length = nums.size();

	for (int i = 0; i < length; i++) {
		target = nums[i];
		if (i + 1 < length) {
			if (target == nums[i + 1]) {
				nums.erase(begin(nums) + (i + 1));
				i--;
				length = nums.size();
			}
		}
	}

	return nums.size();
#else//双指针
	int length = nums.size();
	int slow = 1, fast = 1;

	if (length == 0)
		return 0;

	while (fast < length) {
		if (nums[fast] != nums[fast - 1]) {
			nums[slow] = nums[fast];
			slow++;
		}
		fast++;
	}

	return slow;
#endif
}

void Solution::merge(vector<int>& nums1, int m, vector<int>& nums2, int n)
{
	for (int i = m; i < (m + n); i++) {
		nums1[i] = nums2[i - m];
	}

	sort(nums1.begin(), nums1.end());
}

int Solution::maxProfit(vector<int>& prices)
{
	int result = 0;
	int minPrices = 1e9;

	for (int i = 0; i < prices.size(); i++) {
		minPrices = min(minPrices, prices[i]);
		result = max(result, prices[i] - minPrices);
	}

	return result;
}

int Solution::singleNumber(vector<int>& nums)
{
	int result = 0;
	for (auto each : nums)
		result ^= each;

	return result;
}

bool Solution::hasCycle(ListNode * head)
{
	unordered_set<ListNode *> mySet;

	while (head != NULL) {
		if (mySet.count(head))
			return true;

		mySet.insert(head);
		head = head->next;
	}

	return false;
}

int Solution::majorityElement(vector<int>& nums)
{
#if 0 // 哈希表
	unordered_map<int, int>numMap;
	int majority = 0, count = 0;

	for (int num : nums) {
		numMap[num]++;

		if (numMap[num] > count) {
			majority = num;
			count = numMap[num];
		}
	}

	return majority;
#else
	//摩尔投票法
	int candidate = 0;
	int count = 0;

	for (int num : nums) {
		if (num == candidate) {
			count++;
		}
		else {
			count--;
			if (count < 0) {//支持者小于0，候选人换人
				candidate = num;
				count = 0;
			}
		}
	}

	return candidate;
#endif
}
