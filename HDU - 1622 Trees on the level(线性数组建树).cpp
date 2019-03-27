#include<stdio.h>///线性建树
#include<string.h>
int main()
{
    int tree[60000],maxn=0;
    bool vis[60000];
    char a[300];
    while(scanf("%s",a)!=EOF)
    {
        bool flag=true;
        maxn=0;
        memset(vis,false,sizeof(vis));
        if(strcmp(a,"()")==0)
        {
            printf("not complete\n");
            continue;
        }
        int len=strlen(a),sum=0,pos=1;
        for(int i=1; i<len-1; i++)
        {
            if(a[i]>='0'&&a[i]<='9')
                sum=sum*10+a[i]-'0';
            if(a[i]=='L')pos*=2;
            if(a[i]=='R')pos=2*pos+1;
        }
        if(pos>maxn)maxn=pos;
        if(pos==1)vis[0]=true;
        tree[pos]=sum;
        vis[pos]=true;
        while(scanf("%s",a)!=EOF)
        {
            if(strcmp(a,"()")==0)
            {
                for(int i=1; i<=maxn; i++)
                    if(!vis[i/2]&&vis[i])flag=false;
                if(flag)
                {
                    printf("%d",tree[1]);
                    for(int i=2; i<=maxn; i++)if(vis[i])printf(" %d",tree[i]);
                    printf("\n");
                }
                else printf("not complete\n");
                break;
            }
            int len=strlen(a),sum=0,pos=1;
            for(int i=1; i<len-1; i++)
            {
                if(a[i]>='0'&&a[i]<='9')
                    sum=sum*10+a[i]-'0';
                if(a[i]=='L')pos*=2;
                if(a[i]=='R')pos=2*pos+1;
            }
            if(pos>maxn)maxn=pos;
            if(pos==1)vis[0]=true;
            if(vis[pos])flag=false;
            tree[pos]=sum;
            vis[pos]=true;
        }
    }
}

//#include<cstdio>
//#include<cstring>
//#include<algorithm>
//#include<iostream>
//#include<cmath>
//#include<set>
//#include<queue>
//#include<stack>
//#include<vector>
//#include<string>
//using namespace std;
//#define N 300
//vector<int>anss[N];///保存每一层拥有的节点值
//char s[N];
//int n, f,flag,dep, cnt,ans[N];
//int num=0,tot=0;
//struct node///单个节点
//{
//    int f,v;///保存是否有父亲，以及当前节点的值
//    node *l,*r;///新节点指针，左孩子和右孩子
//};
//node* root;
//
//node* newnode()///创建新节点
//{
//    node* u= (node*) malloc(sizeof (node));///开辟空间
//    if(u!=NULL)///开辟成功
//    {
//        u->f=0;///初始化没有父亲
//        u->l=u->r=NULL;///初始化没有孩子
//    }
//    return u;///返回新创建节点的地址
//}
//
//void addnode(int v, char *s)///加入新节点
//{
//    int n = strlen(s);
//    node* u=root;
//    for(int i=0; i<n; i++)///遍历字符串以确定新节点位置
//    {
//        if(s[i]=='L')///如果是左孩子就创建新节点并接到当前节点左边指针
//        {
//            if(u->l==NULL) u->l=newnode();///如果没有左孩子，创建新节点
//            u=u->l;///将当前节点移动至左孩子位置
//        }
//        if(s[i]=='R')
//        {
//            if(u->r==NULL) u->r=newnode();
//            u=u->r;
//        }
//    }
//    if(u->f) f=1;///如果被赋值过的节点，重复赋值标记为1
//    u->v=v;///投入数值
//    u->f=1;///标记当前节点已经被赋值
//}
//
//int read_input()///建树，读入数据
//{
//    f=0;///初始父亲是否存在标记
//    n=0;
//    root= newnode();///创建新节点
//    int v;
//    while(1)
//    {
//        if(scanf("%s",s)!=1) return 0;///输入
//        if(strcmp(s,"()") ==0 ) break;
//        sscanf(&s[1],"%d",&v);///读取字符串中第一位开始之后的一个数字
//        addnode(v,strchr(s,',')+1);///找到字符串中第一次出现,的位置，然后取这之后的字符串做参数
//    }
//}
//
//void dfs(node* root,int cnt)
//{
//    tot++;
//    dep=max(cnt,dep);
//    if(root->f==0) flag=1;///在整理结果数组时，若发现dfs过程中(从父亲顺序到孩子)，某个节点没有被赋值，说明此节点不存在，创建了节点却没有赋值，错误标记为1
//    anss[cnt].push_back(root->v);
//    if(root->l!=NULL)///遍历左孩子
//    {
//        dfs(root->l,cnt+1);
//    }
//    if(root->r!=NULL)///遍历右孩子
//    {
//        dfs(root->r,cnt+1);
//    }
//}
//
//int main()
//{
//    while(read_input())
//    {
//        for(int i=0; i<N; i++)
//        {
//            anss[i].clear();
//        }
//        num=0,tot=0;
//        cnt=dep=0;
//        flag=0;
//        tot++;
//        dfs(root,0);///根节点开始遍历
//        if(!f && !flag)
//            for(int i=0; i<=dep; i++)
//            {
//                for(int j=0; j<anss[i].size(); j++)
//                {
//                    num++;
//                    printf("%d%c",anss[i][j],( i==dep && j==anss[dep].size()-1 )? '\n':' ');///dep作为深度标记，衡量每一层的输出行末空行
//                }
//            }
//        else printf("not complete\n");
//    }
//}
