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
    //统计以该节点为根节点的子树的节点数
    int countNodeNum(TreeNode* root) {
        if (root != nullptr)
            m_nodeNumMap[root] = 1 + countNodeNum(root->left) + countNodeNum(root->right);

        return m_nodeNumMap[root];
    }

    //获取以该节点为根节点的子树的节点数
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