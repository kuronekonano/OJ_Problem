#include<stdio.h>///���Խ���
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
//vector<int>anss[N];///����ÿһ��ӵ�еĽڵ�ֵ
//char s[N];
//int n, f,flag,dep, cnt,ans[N];
//int num=0,tot=0;
//struct node///�����ڵ�
//{
//    int f,v;///�����Ƿ��и��ף��Լ���ǰ�ڵ��ֵ
//    node *l,*r;///�½ڵ�ָ�룬���Ӻ��Һ���
//};
//node* root;
//
//node* newnode()///�����½ڵ�
//{
//    node* u= (node*) malloc(sizeof (node));///���ٿռ�
//    if(u!=NULL)///���ٳɹ�
//    {
//        u->f=0;///��ʼ��û�и���
//        u->l=u->r=NULL;///��ʼ��û�к���
//    }
//    return u;///�����´����ڵ�ĵ�ַ
//}
//
//void addnode(int v, char *s)///�����½ڵ�
//{
//    int n = strlen(s);
//    node* u=root;
//    for(int i=0; i<n; i++)///�����ַ�����ȷ���½ڵ�λ��
//    {
//        if(s[i]=='L')///��������Ӿʹ����½ڵ㲢�ӵ���ǰ�ڵ����ָ��
//        {
//            if(u->l==NULL) u->l=newnode();///���û�����ӣ������½ڵ�
//            u=u->l;///����ǰ�ڵ��ƶ�������λ��
//        }
//        if(s[i]=='R')
//        {
//            if(u->r==NULL) u->r=newnode();
//            u=u->r;
//        }
//    }
//    if(u->f) f=1;///�������ֵ���Ľڵ㣬�ظ���ֵ���Ϊ1
//    u->v=v;///Ͷ����ֵ
//    u->f=1;///��ǵ�ǰ�ڵ��Ѿ�����ֵ
//}
//
//int read_input()///��������������
//{
//    f=0;///��ʼ�����Ƿ���ڱ��
//    n=0;
//    root= newnode();///�����½ڵ�
//    int v;
//    while(1)
//    {
//        if(scanf("%s",s)!=1) return 0;///����
//        if(strcmp(s,"()") ==0 ) break;
//        sscanf(&s[1],"%d",&v);///��ȡ�ַ����е�һλ��ʼ֮���һ������
//        addnode(v,strchr(s,',')+1);///�ҵ��ַ����е�һ�γ���,��λ�ã�Ȼ��ȡ��֮����ַ���������
//    }
//}
//
//void dfs(node* root,int cnt)
//{
//    tot++;
//    dep=max(cnt,dep);
//    if(root->f==0) flag=1;///������������ʱ��������dfs������(�Ӹ���˳�򵽺���)��ĳ���ڵ�û�б���ֵ��˵���˽ڵ㲻���ڣ������˽ڵ�ȴû�и�ֵ��������Ϊ1
//    anss[cnt].push_back(root->v);
//    if(root->l!=NULL)///��������
//    {
//        dfs(root->l,cnt+1);
//    }
//    if(root->r!=NULL)///�����Һ���
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
//        dfs(root,0);///���ڵ㿪ʼ����
//        if(!f && !flag)
//            for(int i=0; i<=dep; i++)
//            {
//                for(int j=0; j<anss[i].size(); j++)
//                {
//                    num++;
//                    printf("%d%c",anss[i][j],( i==dep && j==anss[dep].size()-1 )? '\n':' ');///dep��Ϊ��ȱ�ǣ�����ÿһ��������ĩ����
//                }
//            }
//        else printf("not complete\n");
//    }
//}
