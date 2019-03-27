#include<stdio.h>
#include <cstdlib>
#include <iostream>
#include <stack>
#include<queue>
using namespace std;

//����������
typedef char ElementType;

typedef struct BiTreeNode
{
    ElementType data;
    struct BiTreeNode* lchild;
    struct BiTreeNode* rchild;
} BiTreeNode, *BiTree;


//�ݹ�Ľ���һ�ö�����
//����Ϊ����������������
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
void creatBiTree_2(BiTree &rt,int n)///�����������
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
int Nodenum(BiTreeNode* root)//�������ڵ���Ŀ
{
    if(root == NULL) return 0;
    else return 1+Nodenum(root->lchild)+Nodenum(root->rchild);
}
//�ݹ�����һ�ö�����
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

//�ݹ��������������
void preOrderTraverse(const BiTree &T)
{
    if(T)
    {
//        cout<<T->data<<" ";//������ڵ�ֵ
        printf("%c ",T->data);
        preOrderTraverse(T->lchild);//����������
        preOrderTraverse(T->rchild);//����������
    }
}

//�ݹ��������������
void inOrderTraverse(const BiTree &T)
{
    if(T)
    {
        inOrderTraverse(T->lchild);//����������
//        cout<<T->data<<" ";//������ڵ�ֵ
        printf("%c ",T->data);
        inOrderTraverse(T->rchild);//����������
    }
}

//�ݹ�������������
void postOrderTraverse(const BiTree &T)
{
    if(T)
    {
        postOrderTraverse(T->lchild);//����������
        postOrderTraverse(T->rchild);//����������
        printf("%c ",T->data);
//        cout<<T->data<<" ";//������ڵ�ֵ
    }
}

//�ݹ����������
int depthOfBiTree(const BiTree &T)
{
    int ldepth;
    int rdepth;

    if(T==NULL)//����
        return 0;
    ldepth = depthOfBiTree(T->lchild);
    rdepth = depthOfBiTree(T->rchild);

    return (ldepth>rdepth)?(ldepth+1):(rdepth+1);
}

//�ݹ����������Ҷ�ӽ�����
int leafCountOfBiTree(const BiTree &T)
{
    if(T==NULL)
        return 0;
    if(T->lchild==NULL && T->rchild==NULL)
        return 1;
    return leafCountOfBiTree(T->lchild) + leafCountOfBiTree(T->rchild);
}

void exchangeChild(BiTree &T)///������������
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
void LevelOrderTraverse(BiTree T,int n)///�������
{
    //Visit�ǶԽڵ������Ӧ�ú���,
    //�������ÿ������Ԫ�ص��ú���Visit,Ҳ���Ǳ����˸ýڵ�
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
    printf("������������: \n");
    exchangeChild(T);

    printf("�������: ");
    LevelOrderTraverse(T,n);
    destroyBiTree(T);//���ٶ��������ͷſռ�
}
/*
5
A B C 0 D E
*/
