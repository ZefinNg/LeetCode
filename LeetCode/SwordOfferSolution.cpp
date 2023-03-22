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
    //ע�⣺��һ������Ϊ n ������ nums ����������ֶ��� 0��n-1 �ķ�Χ��
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
#if 0//����ʱ������
    if (n == 0)
        return 0;
    else if (n == 1)
        return 1;

    return fib(n-1) + fib(n-2);
#else//��̬����
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
#if 0//�����ⷨ
    for (int i = 1; i < numbers.size(); i++) {
        if (numbers[i] < numbers[i - 1])
            return numbers[i];
    }

    return numbers[0];
#else//���ַ�
    int low = 0;
    int high = numbers.size() - 1;

    while (low < high) {
        int mid = (low + high) / 2;
        if (numbers[mid] > numbers[high])
            low = mid + 1;
        else if (numbers[mid] < numbers[high])
            high = mid;
        else//�е������ֵ��ȣ��������˵�����ж�
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
#if 0 //�����ⷨ��û�п��Ǵ�������
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
#if 1 //�ݹ鷨
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
#else //������
    //�ٸ��ڵ�
    ListNode* preHead = new ListNode(-1);
    //���ڱ����Ľڵ�
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
        //�����ڵ�λ�����µĽڵ�
        prev = prev->next;
    }

    //��l1��l2ĳ������Ϊ��ʱ
    prev->next = (l1 == nullptr ? l2 : l1);

    return preHead->next;//�ٸ��ڵ��next��������Ч�ĸ��ڵ�
#endif
}

TreeNode* SwordOfferSolution::mirrorTree(TreeNode* root)
{
    if (root == nullptr)
        return nullptr;

    TreeNode* tmp = root->left;//�ȱ�����ڵ�
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
    //��Ϊnullptr˵���Գ�
    if (left == nullptr && right == nullptr)
        return true;
    
    //�ܽ�����һ��˵��left��right���ٶ�����һ����Ϊnullptr
    if (left == nullptr || right == nullptr || left->val != right->val)
        return false;

    //������˵����һ��Գƣ������жϸ����Ƿ�Գ�
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
        //��������
        for (int i = leftBorder; i <= rightBorder; i++)
            result.push_back(matrix[upBorder][i]);

        //������ʱ�ж��Ƿ�ﵽ��������
        if (++upBorder > bottomBorder)
            break;

        //���ϵ���
        for (int i = upBorder; i <= bottomBorder; i++)
            result.push_back(matrix[i][rightBorder]);

        //������ʱ�ж��Ƿ�ﵽ��������
        if (--rightBorder < leftBorder)
            break;

        //��������
        for (int i = rightBorder; i >= leftBorder; i--)
            result.push_back(matrix[bottomBorder][i]);

        if (--bottomBorder < upBorder)
            break;

        //��������
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
        //q.size()��ʾ�˵�ǰ��һ���ж��ٸ��ڵ㣬iΪ0ʱ˵����һ���Ѿ������ˣ���ʱ��eachLine����res
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
    //�����������(BFS)�����ö����Ƚ��ȳ�������
    queue<TreeNode*> q;
    q.push(root);//�Ƚ����ڵ�������

    while (q.size() > 0) {
        //������ӵĽڵ�
        TreeNode* tempNode = q.front();
        q.pop();
        //������ӽڵ��ֵ
        res.push_back(tempNode->val);

        //���ӽڵ����ڵ㲻Ϊ�գ���ŵ������У���������
        if (tempNode->left != nullptr)
            q.push(tempNode->left);
        //���ӽڵ���ҽڵ㲻Ϊ�գ���ŵ������У���������
        if (tempNode->right != nullptr)
            q.push(tempNode->right);
    }

    return res;
}
int SwordOfferSolution::majorityElement(vector<int>& nums)
{
    int vote = 0;//ͳ��Ʊ��
    int x = 0;   //����

    for (int num : nums) {
        if (vote == 0)
            x = num;
        vote += (num == x ? 1 : -1);
    }

#if 1//�������û����ȷһ����������������Ҫ�ٽ���һ����֤
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
        if (nums.at(prev) % 2 == 0) {//ż��
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
        else {//����
            prev++;
            cur++;
        }
    }

    return nums;
}
