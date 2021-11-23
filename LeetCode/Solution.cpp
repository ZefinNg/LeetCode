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

	//��nums��С��������
	sort(nums.begin(), nums.end());

	//��aValue��ʼ����
	for (aIndex = 0; aIndex < length; aIndex++) {
		//��Ҫ��ǰһ��ֵ��ͬ����ȥ��
		if (aIndex > 0 && nums[aIndex] == nums[aIndex - 1])
			continue;

		cIndex = length - 1;   //Cֵ���ұ߱�������
		target = -nums[aIndex];//Ŀ��ֵ����aֵ���෴��,a=b+c

	    //��ʼ����b
		for (bIndex = aIndex + 1; bIndex < length; bIndex++) {
			//��Ҫ����һ��ֵ��ͬ
			if ((bIndex > aIndex + 1) && nums[bIndex] == nums[bIndex - 1])
				continue;

			//nums�Ѿ�С�����������b+c����target�����cIndex����ƫ��
			while (bIndex < cIndex && (nums[bIndex] + nums[cIndex] > target))
				cIndex--;

			//���b��c�غϣ��Ͳ���������a+b+c=0������ˣ������˳�ѭ��
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
	//��nums��������
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
	//��¥�ݵı��ʻ���쳲��������У�f(x) = f(x-1) + f(x-2)
	//����ʹ�ö�̬����ķ�ʽ�����
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

		//������һ��Ԫ��
		if (temp1 != NULL)
			temp1 = temp1->next;

		if (temp2 != NULL)
			temp2 = temp2->next;

		sum = 0;

		if (temp1 != NULL || temp2 != NULL) {
			//�½ڵ�
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
	 *���ֵ��������֮�͵�һ�룬
	 *������Ԫ��֮�ͺ�С������֮�͵�һ��
	 */
	if (maxNum > target) 
		return false;

	vector<vector<bool>> dp(nums.size(), vector<bool>(target+1, 0));

	for (int i = 0; i < nums.size(); i++)
		dp[i][0] = true;//��Ŀ��ֵΪ0ʱ����������Ԫ�ص��������ѡ�����Ϊ0������

	//��iΪ0��ֻ��һ��Ԫ�ؿ���ѡ�����ʱѡnums[i]��nums[0]��������
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
#if 0//�����ⷨ
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
#else//˫ָ��
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
#if 0 // ��ϣ��
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
	//Ħ��ͶƱ��
	int candidate = 0;
	int count = 0;

	for (int num : nums) {
		if (num == candidate) {
			count++;
		}
		else {
			count--;
			if (count < 0) {//֧����С��0����ѡ�˻���
				candidate = num;
				count = 0;
			}
		}
	}

	return candidate;
#endif
}
