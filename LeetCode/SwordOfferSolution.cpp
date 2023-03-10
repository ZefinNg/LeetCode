#include "stdafx.h"
#include "SwordOfferSolution.h"



SwordOfferSolution::SwordOfferSolution()
{
}


SwordOfferSolution::~SwordOfferSolution()
{
}

int SwordOfferSolution::findRepeatNumber(vector<int>& nums)
{
    //注意：在一个长度为 n 的数组 nums 里的所有数字都在 0～n-1 的范围内
    int length = nums.size();
    int i = 0;

    while (i < length) {
        if (nums[i] == i) {
            i++;
            continue;
        }

        if (nums[i] == nums[nums[i]])
            return nums[i];

        int temp = nums[i];
        nums[i] = nums[temp];
        nums[temp] = temp;
    }

    return -1;
}

string SwordOfferSolution::replace(string s)
{
    int spaceCount = 0;
    int length = s.length();

    for (char c : s) {
        if (c == ' ')
            spaceCount++;
    }

    s.resize(s.length() + spaceCount * 2);

    for (int i = length - 1, j = s.size() - 1; i < j; i--, j--) {
        if (s[i] == ' ') {
            s[j] = '0';
            s[j - 1] = '2';
            s[j - 2] = '%';
            j -= 2;
        }
        else
            s[j] = s[i];
    }

    return s;
}

vector<int> SwordOfferSolution::reversePrint(ListNode * head)
{
    vector<int> result;
    stack<int> tmpStack;

    while (head != nullptr) {
        tmpStack.push(head->val);
        head = head->next;
    }

    while (!tmpStack.empty()) {
        result.push_back(tmpStack.top());
        tmpStack.pop();
    }

    return result;
}

int SwordOfferSolution::fib(int n)
{
#if 0//超出时间限制
    if (n == 0)
        return 0;
    else if (n == 1)
        return 1;

    return fib(n-1) + fib(n-2);
#else//动态数组
    int r = 0, p = 0, q = 1;
    if (n < 2)
        return n;
    int MOD = 1e9 + 7;

    for (int i = 2; i <= n; i++) {
        r = p;
        p = q;
        q = (r + p) % MOD;
    }

    return q;
#endif
}

int SwordOfferSolution::numWays(int n)
{
    if (n < 2)
        return 1;
    int MOD = 1e9 + 7;
    int r = 1, p = 1, q = 2;

    for (int i = 2; i <= n; i++) {
        r = p;
        p = q;
        q = (r + p) % MOD;
    }

    return q;
}

int SwordOfferSolution::minArray(vector<int>& numbers)
{
#if 0//暴力解法
    for (int i = 1; i < numbers.size(); i++) {
        if (numbers[i] < numbers[i - 1])
            return numbers[i];
    }

    return numbers[0];
#else//二分法
    int low = 0;
    int high = numbers.size() - 1;

    while (low < high) {
        int mid = (low + high) / 2;
        if (numbers[mid] > numbers[high])
            low = mid + 1;
        else if (numbers[mid] < numbers[high])
            high = mid;
        else//中点与最后值相等，抛弃最后端点继续判断
            high--;
    }

    return numbers[low];
#endif
}

int SwordOfferSolution::hammingWeight(uint32_t n)
{
    int result = 0;
    for (int i = 0; i < 32; i++) {
        if ((n & (0x01 << i)) != 0)
            result++;
    }

    return result;
}

vector<int> SwordOfferSolution::printNumbers(int n)
{
#if 0 //暴力解法，没有考虑大数问题
    vector<int> result;
    int max = 1;
    for (int i = 0; i < n; i++) {
        max *= 10;
    }

    for (int i = 1; i < max; i++)
        result.push_back(i);

    return result;
#else
    string str(n, '0');
#endif
}

ListNode* SwordOfferSolution::deleteNode(ListNode* head, int val)
{
    ListNode* prev = head;
    ListNode* next = head->next;

    if (prev->val == val) {
        return prev->next;
    }

    while (next != nullptr) {
        if (next->val == val) {
            prev->next = next->next;
            break;
        }

        prev = next;
        next = next->next;
    }

    return head;
}

vector<int> SwordOfferSolution::exchange(vector<int>& nums)
{
    if (nums.size() <= 1)
        return nums;

    int prev = 0, cur = 1;
    while (prev < cur && cur < nums.size()) {
        if (nums.at(prev) % 2 == 0) {//偶数
            if (nums.at(cur) % 2 == 0) {
                cur++;
            }
            else {
                int temp = nums.at(prev);
                nums.at(prev) = nums.at(cur);
                nums.at(cur) = temp;
                prev++;
                cur++;
            }
        }
        else {//奇数
            prev++;
            cur++;
        }
    }


    return nums;
}
