#include<iostream>

//二叉树的基本单位是节点，每个节点包含值、左子节点引用和右子节点引用
/*二叉树节点结构体*/
struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x):val(x),left{nullptr},right{nullptr}{}
};


/*
· 根节点（root node）：位于二叉树顶层的节点，没有父节点。
· 叶节点（leaf node）：没有子节点的节点，其两个指针均指向 None 。
· 边（edge）：连接两个节点的线段，即节点引用（指针）。
· 节点所在的层（level）：从顶至底递增，根节点所在层为 1 。
· 节点的度（degree）：节点的子节点的数量。在二叉树中，度的取值范围是 0、1、2 。
· 二叉树的高度（height）：从根节点到最远叶节点所经过的边的数量。
· 节点的深度（depth）：从根节点到该节点所经过的边的数量。
· 节点的高度（height）：从距离该节点最远的叶节点到该节点所经过的边的数量。
请注意，我们通常将“高度”和“深度”定义为“经过的边的数量”，但有些题目或教材可能会将其定义为“经过的节点的数量”。在这种情况下，高度和深度都需要加 1 。
*/


int main(){
    //初始化二叉树
    TreeNode *n1=new TreeNode(1);
    TreeNode *n2=new TreeNode(2);
    TreeNode *n3=new TreeNode(3);
    TreeNode *n4=new TreeNode(4);
    TreeNode *n5=new TreeNode(5);
    //构建节点之间的引用
    
}