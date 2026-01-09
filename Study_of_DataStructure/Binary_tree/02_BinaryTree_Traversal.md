# 二叉树的遍历 (Binary Tree Traversal)

## 1. 基本概念

从物理结构的角度来看，树是一种基于链表的数据结构。但与线性链表不同，树的非线性结构使得遍历更加复杂，需要借助**搜索算法**来实现。

二叉树常见的遍历方式主要分为两类：

1. **广度优先遍历 (BFS)**：层序遍历。
2. **深度优先遍历 (DFS)**：前序、中序、后序遍历。

------

## 2. 层序遍历 (Level-Order Traversal)

层序遍历从顶部到底部逐层遍历二叉树，并在每一层按照从左到右的顺序访问节点。

它体现了一种“一圈一圈向外扩展”的逻辑，本质上属于广度优先搜索 (BFS)。

### 2.1 代码实现 (使用队列)

BFS 通常借助 **队列 (Queue)** 来实现，利用队列“先进先出 (FIFO)”的特性来控制访问顺序。

C++

```
/* 层序遍历 */
#include <vector>
#include <queue>
using namespace std;

vector<int> levelOrder(TreeNode *root) {
    vector<int> res;
    if (root == nullptr) return res;

    // 1. 初始化队列，加入根节点
    queue<TreeNode*> q;
    q.push(root);

    // 2. 循环处理队列
    while (!q.empty()) {
        TreeNode *node = q.front();
        q.pop(); // 队头出队

        res.push_back(node->val); // 访问节点

        // 将左右子节点入队
        if (node->left != nullptr) q.push(node->left);
        if (node->right != nullptr) q.push(node->right);
    }
    return res;
}
```

### 2.2 复杂度分析

- **时间复杂度**：$O(N)$。所有节点被访问一次，其中 $N$ 为节点数量。
- **空间复杂度**：$O(N)$。在最差情况（完美二叉树）下，队列中最多同时存在层级节点数，即 $(N+1)/2$ 个节点，故为 $O(N)$。

------

## 3. 深度优先遍历 (DFS)

前序、中序和后序遍历都属于深度优先遍历。它体现了一种“先走到尽头，再回溯继续”的逻辑。

### 3.1 遍历顺序定义

- **前序遍历 (Pre-order)**：根 $\to$ 左 $\to$ 右
- **中序遍历 (In-order)**：左 $\to$ 根 $\to$ 右
- **后序遍历 (Post-order)**：左 $\to$ 右 $\to$ 根

### 3.2 递归方式实现 (Recursive)

代码简洁，利用系统栈隐式处理回溯。

C++

```
// 全局 result 数组用于演示，实际项目中建议作为参数传递
vector<int> res; 

/* 前序遍历：根->左->右 */
void preOrder(TreeNode *root) {
    if (root == nullptr) return; // 递归终止条件
    res.push_back(root->val);    // 1. 访问根
    preOrder(root->left);        // 2. 递归左
    preOrder(root->right);       // 3. 递归右
}

/* 中序遍历：左->根->右 */
void inOrder(TreeNode *root) {
    if (root == nullptr) return;
    inOrder(root->left);         // 1. 递归左
    res.push_back(root->val);    // 2. 访问根
    inOrder(root->right);        // 3. 递归右
}

/* 后序遍历：左->右->根 */
void postOrder(TreeNode *root) {
    if (root == nullptr) return;
    postOrder(root->left);       // 1. 递归左
    postOrder(root->right);      // 2. 递归右
    res.push_back(root->val);    // 3. 访问根
}
```

### 3.3 迭代方式实现 (Iterative) - **重点补充**

递归的本质是使用**栈**。为了避免递归过深导致栈溢出，或者为了提升性能，我们常显式地使用 `std::stack` 来模拟递归过程。

#### (1) 前序遍历迭代法

**思路**：利用栈“后进先出”的特点。先推入根节点，弹出并访问，然后**先推入右孩子，再推入左孩子**（这样出栈时就是先左后右）。

C++

```
vector<int> preOrderIterative(TreeNode* root) {
    vector<int> res;
    if (root == nullptr) return res;
    stack<TreeNode*> st;
    st.push(root);

    while (!st.empty()) {
        TreeNode* node = st.top();
        st.pop();
        res.push_back(node->val); // 访问根

        // 注意：栈是后进先出，所以先压右，再压左
        if (node->right) st.push(node->right);
        if (node->left) st.push(node->left);
    }
    return res;
}
```

#### (2) 中序遍历迭代法

**思路**：中序是“左根右”。我们需要指针一直向左走到底，将沿途节点压栈，直到没有左孩子，再弹出栈顶（访问根），然后转向右孩子。

C++

```
vector<int> inOrderIterative(TreeNode* root) {
    vector<int> res;
    stack<TreeNode*> st;
    TreeNode* curr = root;

    while (curr != nullptr || !st.empty()) {
        // 1. 指针一直向左走，沿途入栈
        if (curr != nullptr) {
            st.push(curr);
            curr = curr->left;
        } 
        // 2. 左边走到头了，弹出栈顶访问，然后转向右边
        else {
            curr = st.top();
            st.pop();
            res.push_back(curr->val); // 访问根
            curr = curr->right;
        }
    }
    return res;
}
```

### 3.4 复杂度分析

- **时间复杂度**：$O(N)$。所有节点被访问一次。
- **空间复杂度**：$O(H)$。其中 $H$ 为树的高度。
  - 最坏情况（链表）：递归/栈深度为 $N$，空间 $O(N)$。
  - 最好情况（完全二叉树）：递归/栈深度为 $\log N$，空间 $O(\log N)$。