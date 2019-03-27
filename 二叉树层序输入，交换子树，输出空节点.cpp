#include<stdio.h>
#include <cstdlib>
#include <iostream>
#include <stack>
#include<queue>
using namespace std;

//二叉树定义
typedef char ElementType;

typedef struct BiTreeNode
{
    ElementType data;
    struct BiTreeNode* lchild;
    struct BiTreeNode* rchild;
} BiTreeNode, *BiTree;


//递归的建立一棵二叉树
//输入为二叉树的先序序列
void createBiTree(BiTree &T)
{
    char data;
    data = getchar();
    if(data == '#')
    {
        T = NULL;
    }
    else
    {
        T = new BiTreeNode;
        T->data = data;
        createBiTree(T->lchild);
        createBiTree(T->rchild);
    }
}
void creatBiTree_2(BiTree &rt,int n)///层序遍历建树
{
    char root[2];
    scanf("%s",root);
    rt=new BiTreeNode;
    rt->data=root[0];
    for(int i=2; i<=n; i++)
    {
        BiTreeNode* T=rt;
        char tmp[2];
        int num=0,a[16];
        scanf("%s",tmp);
        if(tmp[0]=='0')n++;
        int ii=i;
        while(ii)
        {
            a[num++]=ii%2;
            ii/=2;
        }
        BiTreeNode *node=new BiTreeNode;
        node->data=tmp[0];
        node->rchild=NULL;
        node->lchild=NULL;
        for(int j=num-2; j>0; j--)
            if(a[j])T=T->rchild;
            else T=T->lchild;
        if(a[0])T->rchild=node;
        else T->lchild=node;
    }
}
int Nodenum(BiTreeNode* root)//二叉树节点数目
{
    if(root == NULL) return 0;
    else return 1+Nodenum(root->lchild)+Nodenum(root->rchild);
}
//递归销毁一棵二叉树
void destroyBiTree(BiTree &T)
{
    if(T)
    {
        destroyBiTree(T->lchild);
        destroyBiTree(T->rchild);
        delete T;
        T = NULL;
    }
}

//递归先序遍历二叉树
void preOrderTraverse(const BiTree &T)
{
    if(T)
    {
//        cout<<T->data<<" ";//输出根节点值
        printf("%c ",T->data);
        preOrderTraverse(T->lchild);//遍历左子树
        preOrderTraverse(T->rchild);//遍历右子树
    }
}

//递归中序遍历二叉树
void inOrderTraverse(const BiTree &T)
{
    if(T)
    {
        inOrderTraverse(T->lchild);//遍历左子树
//        cout<<T->data<<" ";//输出根节点值
        printf("%c ",T->data);
        inOrderTraverse(T->rchild);//遍历右子树
    }
}

//递归后序遍历二叉树
void postOrderTraverse(const BiTree &T)
{
    if(T)
    {
        postOrderTraverse(T->lchild);//遍历左子树
        postOrderTraverse(T->rchild);//遍历右子树
        printf("%c ",T->data);
//        cout<<T->data<<" ";//输出根节点值
    }
}

//递归求树的深度
int depthOfBiTree(const BiTree &T)
{
    int ldepth;
    int rdepth;

    if(T==NULL)//空树
        return 0;
    ldepth = depthOfBiTree(T->lchild);
    rdepth = depthOfBiTree(T->rchild);

    return (ldepth>rdepth)?(ldepth+1):(rdepth+1);
}

//递归求二叉树的叶子结点个数
int leafCountOfBiTree(const BiTree &T)
{
    if(T==NULL)
        return 0;
    if(T->lchild==NULL && T->rchild==NULL)
        return 1;
    return leafCountOfBiTree(T->lchild) + leafCountOfBiTree(T->rchild);
}

void exchangeChild(BiTree &T)///交换左右子树
{
    if(T)
    {
        BiTree temp = NULL;

        if(T->lchild ||T->rchild)
        {
            temp = T->lchild;
            T->lchild = T->rchild;
            T->rchild = temp;
            exchangeChild(T->lchild);
            exchangeChild(T->rchild);
        }
    }
}
void LevelOrderTraverse(BiTree T,int n)///层序遍历
{
    //Visit是对节点操作的应用函数,
    //在这里，对每个数据元素调用函数Visit,也即是遍历了该节点
    queue<BiTree>q;
    BiTree p;
    BiTree zero;
    zero=new BiTreeNode;
    zero->data='0';
    zero->lchild=NULL;
    zero->rchild=NULL;
    int num=0;
    if(T)
    {
        q.push(T);
        while(!q.empty())
        {
            if(num>n)break;
            p=q.front();
            q.pop();
            printf("%c ",p->data);
            num++;
            if(p->lchild!=NULL) q.push(p->lchild);
            if(p->lchild==NULL&&p->rchild!=NULL)q.push(zero);
            if(p->rchild!=NULL) q.push(p->rchild);
        }
        printf("\n");
    }
}
int main()
{
    BiTree T = NULL;
    int n;
    scanf("%d",&n);
    creatBiTree_2(T,n);
    printf("交换左右子树: \n");
    exchangeChild(T);

    printf("层序遍历: ");
    LevelOrderTraverse(T,n);
    destroyBiTree(T);//销毁二叉树，释放空间
}
/*
5
A B C 0 D E
*/
