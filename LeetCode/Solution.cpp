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

ListNode * Solution::reverseList(ListNode * head)
{
	ListNode *prev = nullptr;
	ListNode *cur = head;

	while (cur != nullptr) {
		ListNode *next = cur->next;
		cur->next = prev;
		prev = cur;
		cur = next;
	}

	return prev;
}

bool Solution::containsDuplicate(vector<int>& nums)
{
	unordered_set<int> mySet;

	for (int num : nums) {
		if (mySet.count(num))
			return true;
		else
			mySet.insert(num);
	}

	return false;
}

bool Solution::isPowerOfTwo(int n)
{
	return n > 0 && (n & (n - 1)) == 0;
}

vector<TreeNode*> Solution::getPath(TreeNode * root, TreeNode * target)
{
	vector<TreeNode *>path;
	TreeNode *temp = root;

	while (temp != target) {
		path.push_back(temp);

		if (target->val < temp->val)
			temp = temp->left;
		else
			temp = temp->right;
	}
	path.push_back(temp);

	return path;
}

TreeNode * Solution::lowestCommonAncestor(TreeNode * root, TreeNode * p, TreeNode * q)
{
	vector<TreeNode *>pathP = getPath(root, p);
	vector<TreeNode *>pathQ = getPath(root, q);
	TreeNode *ancestor = nullptr;

	for (int i = 0; i < pathP.size() && i < pathQ.size(); i++) {
		if (pathP[i] == pathQ[i])
			ancestor = pathP[i];
		else
			break;
	}

	return ancestor;
}

void Solution::deleteNode(ListNode * node)
{
	node->val = node->next->val;
	node->next = node->next->next;
}

bool Solution::canWinNim(int n)
{
	return (n % 4) != 0;
}

void Solution::reverseString(vector<char>& s)
{
#if 0
	int length = s.size();
	char temp;
	for (int i = 0; i < length / 2; i++) {
		temp = s[length - i - 1];
		s[length - i - 1] = s[i];
		s[i] = temp;
	}
#else //˫ָ��
	int left = 0, right = s.size() - 1;

	for (; left < right; left++, right--)
		swap(s[left], s[right]);
#endif
}

string Solution::reverseWords(string s)
{
	int length = s.size();
	int wordStart = 0, wordEnd = 0;

	for (int i = 0; i < length; i++) {
		if (s[i] == ' ' || i == length - 1) {
			s[i] == ' ' ? wordEnd = i - 1 :	wordEnd = i;

			while (wordStart < wordEnd) {
				char temp    = s[wordEnd];
				s[wordEnd]   = s[wordStart];
				s[wordStart] = temp;

				wordStart++;
				wordEnd--;
			}

			wordStart = i + 1;
		}
	}

	return s;
}

TreeNode * Solution::searchBST(TreeNode * root, int val)
{
	TreeNode *targetNode = root;

	while (targetNode != nullptr) {
		if (val == targetNode->val)
			return targetNode;
		else if (val < targetNode->val)
			targetNode = targetNode->left;
		else
			targetNode = targetNode->right;
	}

	return nullptr;
}

int Solution::poorPigs(int buckets, int minutesToDie, int minutesToTest)
{
	int maxTestTimes = minutesToTest / minutesToDie + 1;
	return ceil(log(buckets) / log(maxTestTimes));
}

string Solution::longestPalindrome(string s)
{
	int length = s.size();
	
	if (length < 2)
		return s;

	int maxLength = 1; //�ִ�����󳤶ȣ���1��ʼ����
	int begin = 0;     //���ַ���ͷ�±��¼
	vector<vector<bool>> dp(length, vector<bool>(length));

	for (int i = 0; i < length; i++)
		dp[i][i] = true;  //ֻ��һ���ַ����϶��ǻ����ַ���;

	//ö�����ַ�������̴�2��ʼ
	for (int subLength = 2; subLength <= length; subLength++) {
		//����߽翪ʼ����
		for (int left = 0; left < length; left++) {
			//ȷ��һ���ұ߽�
			int right = left + subLength - 1;

			if (right >= length)
				break;

			if (s[left] != s[right]) {//ͷβ����ȣ���ǰ�϶����ǻ���
				dp[left][right] = false;
			}
			else {
				if (right - left < 3)//ֻ��2���ַ�
					dp[left][right] = true;
				else//ͷβ��ȣ��ÿ��ϸ��ǲ��ǻ���
					dp[left][right] = dp[left + 1][right - 1];
			}

			if (dp[left][right] && (right - left + 1) > maxLength) {
				maxLength = right - left + 1;
				begin = left;
			}
		}
	}

	return s.substr(begin, maxLength);
}

int Solution::myAtoi(string s)
{
#if 0 //����˼·�߼�����
	int length = s.length();
	int i = 0; 
	int sign = 1; //1Ϊ������-1Ϊ����
	int result = 0;

	while (s[i++] == ' '); //һֱѭ����i��Ϊ' 'ʱ���˳�ѭ�����˴�����ȡs[i]����ִ��i++;

	i--; //�˳�ѭ��ʱ����i�Ѿ�++����ʱ����1

	if (i < length && (s[i] == '-' || s[i] == '+')) {
		s[i] == '-' ? sign = -1 : sign = 1;
		i++;
	}

	for (; i < length; i++) {
		if (s[i] >= '0' && s[i] <= '9') {
			/* 
			 * �ж��Ƿ����
			 * INT_MAXΪ2147483647, INT_MINΪ(-2147483647 - 1);
			 * ��ǰ��result�������ֵ������������INT_MAX���ߵ���INT_MAX/10�������Ͽ�����һ�����֣�,��
			 * ��һ�����ִ���7��INT_MAX��β��Ϊ7��˵��������ˡ�
			 * ��������ֵ���������������ŷ���������Сֵ���ɡ�
			 */
			if (result > INT_MAX / 10 || result == INT_MAX / 10 && (s[i] - '0' > 7))
				return (sign + 1) ? INT_MAX : INT_MIN;

			result = result * 10 + (s[i] - '0');
		}
		else
			break;
	}

	return result * sign;
#else //״̬�������Զ���
	string state = "start";
	unordered_map<string, vector<string>> stateTable = {
		//              ����      +/-       number     other
		{"start",     {"start", "signed", "in_number", "end"}},
		{"signed",    {"end",   "end",    "in_number", "end"}},
		{"in_number", {"end",   "end",    "in_number", "end"}},
		{"end",       {"end",   "end",    "end",       "end"}}
	};

	int sign = 1;
	long long result = 0;
	int stateIndex = 0;

	for (char c : s) {
		if (isspace(c))
			stateIndex = 0;
		else if (c == '+' || c == '-')
			stateIndex = 1;
		else if (isdigit(c))
			stateIndex = 2;
		else
			stateIndex = 3;

		state = stateTable[state][stateIndex];

		if (state == "in_number") {
			result = result * 10 + (c - '0');
			result = sign == 1 ? min(result, (long long)INT_MAX) : min(result, -(long long)INT_MIN);
		}
		else if (state == "signed")
			sign = c == '+' ? 1 : -1;
	}

	return result * sign;
#endif
}

int Solution::maxArea(vector<int>& height)
{
#if 0 //��̬�滮˼·��leetcode��ʾ����ʱ������
	int length = height.size();
	vector<vector<int>> dp(length, vector<int>(length));

	for (int i = 0; i < length; i++) {
		for (int j = 0; j < i; j++)
			dp[i][j] = 0;
	}

	int result    = INT_MIN;
	int minHeight = 0;
	int area      = 0;

	for (int i = 0; i < length; i++) {
		for (int j = i+1; j < length; j++) {
			minHeight = min(height[i], height[j]);
			dp[i][j] = max(minHeight * (j - i), dp[i][j - 1]);
			result = max(result, dp[i][j]);
		}
	}

	return result;
#else//˫ָ������
	int length = height.size();
	int first  = 0;
	int last   = length - 1;
	int result = INT_MIN;
	int minHeight = 0;

	while (first != last) {
		minHeight = min(height[first], height[last]);
		result = max(minHeight * (last - first), result);

		if (height[first] < height[last])
			first++;
		else
			last--;
	}

	return result;
#endif
}

int Solution::threeSumClosest(vector<int>& nums, int target)
{
	int result = 0;
	int aIndex, bIndex, cIndex;
	int length = nums.size();
	int currentValue = 1e7;

	sort(nums.begin(), nums.end());

	for (aIndex = 0; aIndex < length; aIndex++) {
		if (aIndex > 0 && nums[aIndex] == nums[aIndex - 1])
			continue;

		bIndex = aIndex + 1;
		cIndex = length - 1;

		while (bIndex < cIndex) {
			result = nums[aIndex] + nums[bIndex] + nums[cIndex];

			if (result == target)
				return result;

			if (abs(result - target) < abs(currentValue - target))
				currentValue = result;

			if (result > target) {
				int cTempIndex = cIndex - 1;
				while (cTempIndex > bIndex && nums[cIndex] == nums[cTempIndex])
					cTempIndex--;

				cIndex = cTempIndex;
			}
			else {
				int bTempIndex = bIndex + 1;
				while (bTempIndex < cIndex && nums[bIndex] == nums[bTempIndex])
					bTempIndex++;

				bIndex = bTempIndex;
			}
		}
	}

	return currentValue;
}

int Solution::search(vector<int>& nums, int target)
{
#if 0//�����ⷨ
	int length = nums.size();

	for (int i = 0; i < length; i++) {
		if (nums[i] == target)
			return i;
	}

	return -1;
#else//���ַ�
	int length = nums.size();
	
	if (length == 0)
		return -1;

	if (length == 1)
		return nums[0] == target ? 0 : -1;

	int left = 0, right = length - 1;

	while (left <= right) {
		int mid = (left + right) / 2;

		if (nums[mid] == target)
			return mid;

		if (nums[0] <= nums[mid]) {
			if (nums[0] <= target && target < nums[mid])
				right = mid - 1;
			else
				left = mid + 1;
		}
		else {
			if (nums[mid] < target && target <= nums[length - 1])
				left = mid + 1;
			else
				right = mid - 1;
		}
	}

	return -1;
#endif
}

string Solution::multiply(string num1, string num2)
{
#if 0//ϰ��˼ά����num2�����ְ���������num1���
	if (num1 == "0" || num2 == "0")
		return string("0");

	if (num1 == "1")
		return num2;

	if (num2 == "1")
		return num1;

	string result = "0";
	int tens      = 0;
	int remainder = 0;
	int product   = 0;

	//num1 * num2
	for (int i = num1.size() - 1; i >= 0; i--) {
		string currentValue;

		//�����ĳ˷�����˼ά��
		//��������ȡ��num2�����֣���num1�������

		//num2��ȡ��������Ҫ����ƫ�����⣬ƫ��һλ����һ��0
		for (int j = num1.size() - 1; j > i; j--)
			currentValue.push_back('0');//����ֱ��push_back������Ϊ�������һ�η�ת

		for (int j = num2.size() - 1; j >= 0; j--) {
			product = (num2[j] - '0') * (num1[i] - '0');
			
			product += tens;
			remainder = product % 10;
			tens = product / 10;

			currentValue.push_back((remainder + '0'));
		}

		while (tens != 0) {
			currentValue.push_back((tens % 10) + '0');
			tens /= 10;
		}

		//��ת����֮ǰֱ��push_back��������ת����
		std::reverse(currentValue.begin(), currentValue.end());

		//�ѽ���ۼ�
		int resultIndex       = result.size() - 1;
		int currentValueIndex = currentValue.size() - 1;
		int add = 0;
		string tempProduct;

		while (resultIndex >= 0 || currentValueIndex >= 0 || add != 0) {
			int x = resultIndex < 0 ? 0 : result[resultIndex] - '0';
			int y = currentValueIndex < 0 ? 0 : currentValue[currentValueIndex] - '0';

			int tempValue = x + y + add;
			tempProduct.push_back((tempValue % 10)+'0');
			add = tempValue / 10;

			resultIndex--;
			currentValueIndex--;
		}

		std::reverse(tempProduct.begin(), tempProduct.end());
		result = tempProduct;
	}

	return result;
#else//��num1�����ְ���������num2���
	if (num1 == "0" || num2 == "0")
		return "0";

	int num1Length = num1.size();
	int num2Length = num2.size();

	vector<int> tempValue = vector<int>(num1Length + num2Length);

	for (int i = num1Length - 1; i >= 0; i--) {
		int num1EachValue = num1[i] - '0';

		for (int j = num2Length - 1; j >= 0; j--) {
			int num2EachValue = num2[j] - '0';
			tempValue[i + j + 1] += num1EachValue * num2EachValue;
		}
	}

	//��tempValue�д���ý�λ����
	for (int i = num1Length + num2Length - 1; i > 0; i--) {
		tempValue[i - 1] += tempValue[i] / 10;
		tempValue[i] %= 10;
	}

	int index = tempValue[0] == 0 ? 1 : 0;
	//��tempValueת��string
	string result;
	for (int i = index; i < num1Length + num2Length; i++)
		result.push_back(tempValue[i] + '0');

	return result;
#endif
}

void Solution::backtrack(vector<vector<int>>& result, vector<int>& output, int first, int len)
{
	if (first == len) {
		result.emplace_back(output);
		return;
	}

	for (int i = first; i < len; i++) {
		swap(output[i], output[first]);
		backtrack(result, output, first + 1, len);
		swap(output[i], output[first]);
	}
}

vector<vector<int>> Solution::permute(vector<int>& nums)
{
	vector<vector<int>> result;
	backtrack(result, nums, 0, nums.size());

	return result;
}

vector<int> Solution::spiralOrder(vector<vector<int>>& matrix)
{
	if (matrix.size() == 0 || matrix[0].size() == 0)
		return vector<int>();

	//�߽�
	int upBoundary    = 0;
	int downBoundary  = matrix.size() - 1;
	int leftBoundary  = 0;
	int rightBoundary = matrix[0].size() - 1;

	vector<int> result;

	while (true) {
		//���ұ���
		for (int i = leftBoundary; i <= rightBoundary; i++)
			result.push_back(matrix[upBoundary][i]);
		
		//�����ϱ߽磬����ϱ߽���±߽�����˳�
		if (++upBoundary > downBoundary)
			break;

		//����
		for (int i = upBoundary; i <= downBoundary; i++)
			result.push_back(matrix[i][rightBoundary]);

		//�����ұ߽磬����ұ߽�С����߽磬���˳�
		if (--rightBoundary < leftBoundary)
			break;

		//����
		for (int i = rightBoundary; i >= leftBoundary; i--)
			result.push_back(matrix[downBoundary][i]);

		//�����±߽磬����±߽�С���ϱ߽磬���˳�
		if (--downBoundary < upBoundary)
			break;

		//����
		for (int i = downBoundary; i >= upBoundary; i--)
			result.push_back(matrix[i][leftBoundary]);

		//������߽磬�����߽�����ұ߽磬���˳�
		if (++leftBoundary > rightBoundary)
			break;
	}

	return result;
}

vector<vector<int>> Solution::generateMatrix(int n)
{
	vector<vector<int>> result(n, vector<int>(n, 0));

	int endValue = n ^ 2;
	int upBoundary = 0;
	int downBoundary = n - 1;
	int leftBoundary = 0;
	int rightBoundary = n - 1;
	int number = 1;

	while (true) {
		for (int i = leftBoundary; i <= rightBoundary; i++, number++)
			result[upBoundary][i] = number;

		if (++upBoundary > downBoundary)
			break;

		for (int i = upBoundary; i <= downBoundary; i++, number++)
			result[i][rightBoundary] = number;

		if (--rightBoundary < leftBoundary)
			break;

		for (int i = rightBoundary; i >= leftBoundary; i--, number++)
			result[downBoundary][i] = number;

		if (--downBoundary < upBoundary)
			break;

		for (int i = downBoundary; i >= upBoundary; i--, number++)
			result[i][leftBoundary] = number;

		if (++leftBoundary > rightBoundary)
			break;
	}

	return result;
}

ListNode * Solution::rotateRight(ListNode * head, int k)
{
	if (head == NULL || k == 0)
		return head;

	int length = 0;

	for (ListNode *tempPtr = head; tempPtr != NULL; tempPtr = tempPtr->next)
		length++;

	int offset = k % length;
	ListNode* newHeadNode = head;
	ListNode* tempNode    = head;
	ListNode* preNode     = nullptr;
	int i = 0;

	while (true) {
		if (i == (length - offset)) {
			newHeadNode = tempNode;
		}
		else if ((i+1)== (length - offset)) {
			preNode = tempNode;

			if (tempNode->next != nullptr) {
				i++;
				tempNode = tempNode->next;
				preNode->next = nullptr;
			}
			else {
				preNode->next = nullptr;
				break;
			}

			continue;
		}

		if (tempNode->next != nullptr) {
			i++;
			tempNode = tempNode->next;
		}
		else
			break;
	}

	if (offset != 0)
	    tempNode->next = head;

	return newHeadNode;
}

int Solution::uniquePaths(int m, int n)
{
	/*
	 * dp[i][j] ��ʾ��i, j��·����
	 * dp[i][j] = dp[i-1][j] + dp[i][j-1]�����ַ���ĺͣ�
	 * ����i-1, j-1, ���i=0��j=0ʱ������
	 */
	vector<vector<int>> dp(m, vector<int>(n));

	for (int i = 0; i < m; i++)
		dp[i][0] = 1;

	for (int j = 0; j < n; j++)
		dp[0][j] = 1;

	for (int i = 1; i < m; i++) {
		for (int j = 1; j < n; j++)
			dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
	}

	return dp[m-1][n-1];
}

vector<vector<int>> Solution::subsets(vector<int>& nums)
{
#if 0//������
	vector<int> element;
	vector<vector<int>> result;

	int length = nums.size();

	for (int i = 0; i < (1 << length); i++) {
		element.clear();

		for (int j = 0; j < length; j++) {
			if (i & (1 << j))
				element.push_back(nums[j]);
		}

		result.push_back(element);
	}

	return result;
#else//���ݷ�
	vector<vector<int>> answer;
	vector<int> temp;
	dfs(answer, nums, 0, temp);

	return answer;
#endif
}

void Solution::dfs(vector<vector<int>>& answer, vector<int>& srcNums, int index, vector<int>& tempNum)
{
	if (index == srcNums.size()) {
		answer.push_back(tempNum);
		return;
	}

	tempNum.push_back(srcNums[index]);
	dfs(answer, srcNums, index + 1, tempNum);
	tempNum.pop_back();
	dfs(answer, srcNums, index + 1, tempNum);
}

vector<int> Solution::grayCode(int n)
{
#if 0//�ԳƷ�
	vector<int> result;
	/*
	 * Ԥ��capacity������pushback�����·����ڴ�͸��ƵĿ���
	 * ����Ӱ��size��С
	 */
	result.reserve(1 << n);
	result.push_back(0);

	for (int i = 1; i <= n; i++) {
		int length = result.size();
		for (int j = length - 1; j >= 0; j--)
			result.push_back(result[j] | (1 << (i - 1)));
	}
	return result;
#else
	vector<int> result(1 << n);

	for (int i = 0; i < result.size(); i++)
		result[i] = (i >> 1) ^ i;

	return result;
#endif
}

int Solution::maxProfitII(vector<int>& prices)
{
#if 0//��̬�滮
	int n = prices.size();
	int dp[n][2]; //dp[n][0] ��ʾ��n�콻���������û�й�Ʊ���������dp[i][1] ��ʾ��n�콻������������һ֧��Ʊ���������n��0��ʼ��

	dp[0][0] = 0;//��0�죬�����й�Ʊ������϶�Ϊ0
	dp[0][1] = -prices[0];//��0�죬����һֻ��Ʊ������϶��Ǹ��ģ���Ǯ������ֻ��Ʊ

	/*
	 * ��������
	 * �ȵ����һ�콻�׽���ʱ����ʱ�������Ʊ�Ϊdp[n-1][0]��dp[n-1][1]��
	 * ��dp[n-1][1]��ʾ������콻�׽�����Ȼ���й�Ʊ�����ֵ�϶�С��dp[n-1][0]��
	 * ��ˣ��������ֵΪdp[n-1][0];
	 */
	for (int i = 1; i < n; i++) {
		dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + prices[i]);
		dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] - prices[i]);
	}

	return dp[n - 1][0];
#else//̰���㷨
	/*
	 * ���ַ���ֻ�����������������ֵ��������̲����ܷ�ӳʵ�ʵĽ��׹��̣�
	 * ÿ��Ľ����У�ֻҪ�ڶ�������ˣ���ô��ǰ�Ϳ�����
	 * ��ˣ�ֻҪ����ÿһ�콻�׺��������󻯼��ɡ�
	 */
	int result = 0;
	for (int i = 1; i < prices.size(); i++)
		result += max(0, prices[i] - prices[i - 1]);

	return result;
#endif

	return 0;
}

ListNode * Solution::detectCycle(ListNode * head)
{
	unordered_set<ListNode*> set;

	while (head != nullptr) {
		if (set.count(head) == 0)
			set.insert(head);
		else
			return head;

		head = head->next;
	}

	return nullptr;
}

void adjustHeap(vector<int> &nums, int nodeIndex, int length)
{
    //int length = nums.size();
    int left = 2 * nodeIndex + 1;
    int right = 2 * nodeIndex + 2;
    int maxIndex = nodeIndex;

    if (left < length && nums[left] < nums[maxIndex])
        maxIndex = left;

    if (right < length && nums[right] < nums[maxIndex])
        maxIndex = right;

    if (maxIndex != nodeIndex) {
        swap(nums[nodeIndex], nums[maxIndex]);
        adjustHeap(nums, maxIndex, length);
    }
}

void heapSort(vector<int>& nums)
{
    int length = nums.size();
    //��ʼ������
    for (int i = (length - 2) / 2; i >= 0; i--)
        adjustHeap(nums, i, length);

    //������
    for (int i = length - 1; i >= 0; i--) {
        swap(nums[0], nums[i]);
        adjustHeap(nums, 0, i);
    }
}

int Solution::findKthLargest(vector<int>& nums, int k)
{
    heapSort(nums);

    return nums[k-1];
}

int Solution::kthSmallest(TreeNode * root, int k)
{
#if 0
    std::stack<TreeNode *> treeStack;
    while (root != nullptr || treeStack.size() > 0) {
        while (root != nullptr) {
            treeStack.push(root);
            root = root->left;
        }
        root = treeStack.top();
        treeStack.pop();
        k--;
        if (k == 0)
            break;

        root = root->right;
    }
    return root->val;
#else

#endif
    return 0;
}
