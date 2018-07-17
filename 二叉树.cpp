#include <iostream>
using namespace std;


typedef int TelemType;

typedef struct BinaryTreeNode
{
    TelemType data;
    struct BinaryTreeNode *Left;
    struct BinaryTreeNode *Right;
}Node;


//创建二叉树，顺序依次为中间节点->左子树->右子树
Node* createBinaryTree()
{
    Node *p;
    TelemType ch;
    cin>>ch;
    if(ch == 0)     //如果到了叶子节点，接下来的左、右子树分别赋值为0
    {
        p = NULL;
    }
    else
    {
        p = new Node;
        p->data = ch;
        p->Left  = createBinaryTree();  //递归创建左子树
        p->Right = createBinaryTree();  //递归创建右子树
    }
    return p;
}

//先序遍历
void preOrderTraverse(Node* root)
{
    if( root )
    {
        cout<<root->data<<' ';
        preOrderTraverse(root->Left);
        preOrderTraverse(root->Right);
    }
}

//中序遍历
void inOrderTraverse(Node* root)
{
    if( root )
    {
        inOrderTraverse(root->Left);
        cout<<root->data<<' ';
        inOrderTraverse(root->Right);
    }
}

//后序遍历
void lastOrderTraverse(Node* root)
{
    if( root )
    {
        lastOrderTraverse(root->Left);
        lastOrderTraverse(root->Right);
        cout<<root->data<<' ';
    }
}

//二叉树节点总数目
int Nodenum(Node* root)
{
    if(root == NULL)
    {
        return 0;
    }
    else
    {
        return 1+Nodenum(root->Left)+Nodenum(root->Right);

    }
}

//二叉树的深度
int DepthOfTree(Node* root)
{
    if(root)
    {
        return DepthOfTree(root->Left)>DepthOfTree(root->Right)?DepthOfTree(root->Left)+1:DepthOfTree(root->Right)+1;
    }
    if( root == NULL )
    {
        return 0;
    }
}

//二叉树叶子节点数
int Leafnum(Node* root)
{
    if(!root)
    {
        return 0;
    }
    else if(  (root->Left == NULL) && (root->Right == NULL) )
    {
        return 1;
    }
    else
    {
        return  (Leafnum(root->Left) + Leafnum(root->Right)) ;
    }
}


int main()
{
    Node *root = NULL;
    root = createBinaryTree();
    cout <<("二叉树建立成功");
    cout<<endl;

    cout<<"二叉树总节点数为："<<Nodenum(root)<<endl;

    cout<<"二叉树深度为："<<DepthOfTree(root)<<endl;

    cout<<"二叉树叶子节点数为："<<Leafnum(root)<<endl;

    cout<<"前序遍历结果:"<<endl;
    preOrderTraverse(root);
    cout<<endl;

    cout<<"中序遍历结果:"<<endl;
    inOrderTraverse(root);
    cout<<endl;

    cout<<"后序遍历结果:"<<endl;
    lastOrderTraverse(root);
    cout<<endl;

    return 0;
}
