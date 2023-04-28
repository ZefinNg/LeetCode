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
    return vector<int>();
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

ListNode * SwordOfferSolution::getKthFromEnd(ListNode * head, int k)
{
    ListNode *prev = head, *cur = head;

    for (int i = 0; i < k-1; i++) {
        if (cur->next != nullptr)
            cur = cur->next;
    }

    while (cur->next != nullptr) {
        prev = prev->next;
        cur = cur->next;
    }

    return prev;
}

ListNode* SwordOfferSolution::mergeTwoLists(ListNode* l1, ListNode* l2)
{
#if 1 //递归法
    if (l1 == nullptr)
        return l2;
    if (l2 == nullptr)
        return l1;
    if (l1->val < l2->val) {
        l1->next = mergeTwoLists(l1->next, l2);
        return l1;
    }
    else {
        l2->next = mergeTwoLists(l1, l2->next);
        return l2;
    }
#else //迭代法
    //假根节点
    ListNode* preHead = new ListNode(-1);
    //用于遍历的节点
    ListNode* prev = preHead;

    while (l1 != nullptr && l2 != nullptr) {
        if (l1->val < l2->val) {
            prev->next = l1;
            l1 = l1->next;
        }
        else {
            prev->next = l2;
            l2 = l2->next;
        }
        //遍历节点位移至新的节点
        prev = prev->next;
    }

    //当l1或l2某个遍历为空时
    prev->next = (l1 == nullptr ? l2 : l1);

    return preHead->next;//假根节点的next，即是有效的根节点
#endif
}

TreeNode* SwordOfferSolution::mirrorTree(TreeNode* root)
{
    if (root == nullptr)
        return nullptr;

    TreeNode* tmp = root->left;//先保存左节点
    root->left = mirrorTree(root->right);
    root->right = mirrorTree(tmp);

    return root;
}

bool SwordOfferSolution::isSymmetric(TreeNode* root)
{
    if (root == nullptr)
        return true;
    else
        return isSymmetric(root->left, root->right);
}

bool SwordOfferSolution::isSymmetric(TreeNode* left, TreeNode* right)
{
    //均为nullptr说明对称
    if (left == nullptr && right == nullptr)
        return true;
    
    //能进入这一步说明left和right至少二者有一个不为nullptr
    if (left == nullptr || right == nullptr || left->val != right->val)
        return false;

    //到这里说明这一层对称，继续判断各自是否对称
    return isSymmetric(left->left, right->right) && isSymmetric(left->right, right->left);
}

vector<int> SwordOfferSolution::spiralOrder(vector<vector<int>>& matrix)
{
    if (matrix.empty())
        return vector<int>();

    vector<int> result;

    int upBorder = 0;
    int bottomBorder = matrix.size() - 1;
    int leftBorder = 0;
    int rightBorder = matrix[0].size() - 1;

    while (true) {
        //从左向右
        for (int i = leftBorder; i <= rightBorder; i++)
            result.push_back(matrix[upBorder][i]);

        //向下走时判断是否达到结束条件
        if (++upBorder > bottomBorder)
            break;

        //从上到下
        for (int i = upBorder; i <= bottomBorder; i++)
            result.push_back(matrix[i][rightBorder]);

        //往左走时判断是否达到结束条件
        if (--rightBorder < leftBorder)
            break;

        //从右往左
        for (int i = rightBorder; i >= leftBorder; i--)
            result.push_back(matrix[bottomBorder][i]);

        if (--bottomBorder < upBorder)
            break;

        //从下往上
        for (int i = bottomBorder; i >= upBorder; i--)
            result.push_back(matrix[i][leftBorder]);

        if (++leftBorder > rightBorder)
            break;
    }

    return result;
}

#if 1
vector<vector<int>> SwordOfferSolution::levelOrder(TreeNode* root)
{
    if (root == nullptr)
        return vector<vector<int>>();

    vector<vector<int>> res;
    queue<TreeNode*> q;
    q.push(root);

    while (q.size() > 0) {
        vector<int> eachLine;
        //q.size()表示了当前这一层有多少个节点，i为0时说明这一层已经走完了，此时将eachLine插入res
        for (int i = q.size(); i > 0; i--) {
            TreeNode* temp = q.front();
            q.pop();
            eachLine.push_back(temp->val);

            if (temp->left != nullptr)
                q.push(temp->left);
            if (temp->right != nullptr)
                q.push(temp->right);
        }
        res.push_back(eachLine);
    }
    return res;
}
#else
vector<int> SwordOfferSolution::levelOrder(TreeNode * root)
{
    if (root == nullptr)
        return vector<int>();

    vector<int> res;
    //广度优先搜索(BFS)，利用队列先进先出的特性
    queue<TreeNode*> q;
    q.push(root);//先将根节点放入队列

    while (q.size() > 0) {
        //处理出队的节点
        TreeNode* tempNode = q.front();
        q.pop();
        //保存出队节点的值
        res.push_back(tempNode->val);

        //出队节点的左节点不为空，则放到队列中，后续处理
        if (tempNode->left != nullptr)
            q.push(tempNode->left);
        //出队节点的右节点不为空，则放到队列中，后续处理
        if (tempNode->right != nullptr)
            q.push(tempNode->right);
    }

    return res;
}
int SwordOfferSolution::majorityElement(vector<int>& nums)
{
    int vote = 0;//统计票数
    int x = 0;   //众数

    for (int num : nums) {
        if (vote == 0)
            x = num;
        vote += (num == x ? 1 : -1);
    }

#if 1//如果数组没有明确一定存在众数，则需要再进行一次验证
    int count = 0;
    for (int num : nums) {
        if (num == x)
            count++;
    }

    if (count > (nums.count() / 2))
        return x;
    else
        return 0;
#endif

    return x;
}
#endif

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
