#pragma once
#include "Solution.h"
#include <unordered_map>

class MyBst {
public:
    MyBst(TreeNode* root) {
        this->m_root = root;
        countNodeNum(root);
    }

    int kthSmallest(int k) {
        TreeNode *node = m_root;
        while (node != nullptr) {
            int left = getNodeNum(node->left);
            if (k < left + 1) {
                node = node->left;
            }
            else if (k == (left + 1))
                break;
            else {
                node = node->right;
                k = k - left - 1;
            }
        }

        return node->val;
    }

private:
    //ͳ���Ըýڵ�Ϊ���ڵ�������Ľڵ���
    int countNodeNum(TreeNode* root) {
        if (root != nullptr)
            m_nodeNumMap[root] = 1 + countNodeNum(root->left) + countNodeNum(root->right);

        return m_nodeNumMap[root];
    }

    //��ȡ�Ըýڵ�Ϊ���ڵ�������Ľڵ���
    int getNodeNum(TreeNode* root) {
        if (root != nullptr && m_nodeNumMap.count(root) > 0)
            return m_nodeNumMap[root];
        else
            return 0;
    }

private:
    TreeNode *m_root;
    unordered_map<TreeNode*, int> m_nodeNumMap;
};