#include<bits/stdc++.h>///失败的代码，无限RE
#define LL long long
#define M(a,b) memset(a,b,sizeof a)
#define pb(x) push_back(x)
using namespace std;
const int maxn=160000+7;
struct node
{
    int val;
    node *next,*pre;
};
int n,q;
node* newnode()
{
    node* p=(node*)malloc(sizeof (node));
    p->next=NULL;
    p->pre=NULL;
    return p;
}
node* head[maxn];
node* tail[maxn];
node* rhead[maxn];
node* rtail[maxn];
void init()
{
    for(int i=1; i<=n; i++)
    {
        head[i]=newnode();
        head[i]->val=-1;
        head[i]->next=NULL;
        head[i]->pre=NULL;
        tail[i]=head[i];

        rhead[i]=newnode();
        rhead[i]->val=-1;
        rhead[i]->next=NULL;
        rhead[i]->pre=NULL;
        rtail[i]=rhead[i];
    }
}
int u,w,v,val,flag;
int main()
{
    while(scanf("%d%d",&n,&q)!=EOF)
    {
        init();
        while(q--)
        {
            scanf("%d",&flag);
            if(flag==1)///插入
            {
                scanf("%d%d%d",&u,&w,&val);
                node* p=newnode();
                p->val=val;

                node* rp=newnode();
                rp->val=val;
                if(w)
                {
                    p->pre=tail[u];///正向
                    tail[u]->next=p;
                    tail[u]=p;
                    if(head[u]==tail[u])head[u]->next=p;

                    rp->next=rhead[u]->next;///反向
                    rp->pre=rhead[u];
                    if(rhead[u]->next!=NULL)rhead[u]->next->pre=rp;
                    else rtail[u]=rp;
                    rhead[u]->next=rp;
                }
                else
                {
                    p->next=head[u]->next;///正向
                    p->pre=head[u];
                    if(head[u]->next!=NULL)head[u]->next->pre=rp;
                    else tail[u]=p;
                    head[u]->next=p;

                    rp->pre=rtail[u];///反向
                    rtail[u]->next=rp;
                    rtail[u]=rp;
                    if(rhead[u]==rtail[u])rhead[u]->next=rp;
                }
            }
            else if(flag==2)///删除
            {
                scanf("%d%d",&u,&w);
                if(head[u]==tail[u]) printf("-1\n");
                else
                {
                    if(w)
                    {
                        printf("%d\n",tail[u]->val);///正向
                        node *p=tail[u];
                        if(tail[u]->pre!=NULL) tail[u]=tail[u]->pre;
                        else head[u]=tail[u];
                        tail[u]->next=NULL;

                        node *rp=rhead[u]->next;///反向
                        rhead[u]->next=rp->next;
                        if(rp->next!=NULL) rp->next->pre=rhead[u];
                        else rhead[u]=rtail[u];
                    }
                    else
                    {
                        printf("%d\n",head[u]->next->val);///正向
                        node* p=head[u]->next;
                        head[u]->next=p->next;
                        if(p->next!=NULL) p->next->pre=head[u];
                        else head[u]=tail[u];

                        node* rp=rtail[u];///反向
                        if(rtail[u]->pre!=NULL) rtail[u]=rtail[u]->pre;
                        else rhead[u]=rtail[u];
                        rtail[u]->next=NULL;
                    }
                }
            }
            else
            {
                scanf("%d%d%d",&u,&v,&w);
                if(w)///逆向接
                {
                    if(rhead[v]!=rtail[v])
                    {
                        tail[u]->next=rhead[v]->next;///u之后接逆v,清空逆v
                        if(rhead[v]->next!=NULL) rhead[v]->next->pre=tail[u];
                        tail[u]=rtail[v];
                        rhead[v]->next=NULL;
                        rtail[v]=rhead[v];

                        if(rhead[u]->next!=NULL) rhead[u]->next->pre=tail[v];
                        tail[v]->next=rhead[u]->next;
                        rhead[u]=head[v];
                        tail[v]->next=NULL;
                        head[v]=tail[v];
                    }
                }
                else ///顺序接
                {
                    if(head[v]!=tail[v])
                    {
                        tail[u]->next=head[v]->next;///u之后接v，清空v
                        if(head[v]->next!=NULL) head[v]->next->pre=tail[u];
                        tail[u]=tail[v];
                        head[v]->next=NULL;
                        tail[v]=head[v];

                        if(head[u]->next!=NULL) rhead[u]->next->pre=rtail[v];
                        rtail[v]->next=rhead[u]->next;
                        rhead[u]=rhead[v];
                        rtail[v]->next=NULL;
                        rhead[v]=rtail[v];
                    }
                }
            }
        }
    }
}
/*
2 10
1 1 1 23
1 1 0 233
2 1 1
1 2 1 2333
1 2 1 23333
3 1 2 1
2 2 0
2 1 1
2 1 0
2 1 1
*/

///假的代码，能A但是明显会超时
//#include<bits/stdc++.h>
//#define LL long long
//#define M(a,b) memset(a,b,sizeof a)
//#define pb(x) push_back(x)
//using namespace std;
//const int maxn=150000+10;
//int n,t;
//int u,w,v,val,flag;
//int main()
//{
//    while(scanf("%d%d",&n,&t)!=EOF)
//    {
//        deque<int>q[n+10];
//        for(int i=0; i<=n; i++)while(!q[i].empty()) q[i].pop_back();
//        while(t--)
//        {
//            scanf("%d",&flag);
//            if(flag==1)
//            {
//                scanf("%d%d%d",&u,&w,&val);
//                if(w)q[u].push_front(val);
//                else q[u].push_back(val);
//            }
//            else if(flag==2)
//            {
//                scanf("%d%d",&u,&w);
//                if(q[u].empty()) printf("-1\n");
//                else
//                {
//                    if(w)
//                    {
//                        printf("%d\n",q[u].front());
//                        q[u].pop_front();
//                    }
//                    else
//                    {
//                        printf("%d\n",q[u].back());
//                        q[u].pop_back();
//                    }
//                }
//            }
//            else
//            {
//                scanf("%d%d%d",&u,&v,&w);
//                if(w)
//                {
//                    while(!q[v].empty())
//                    {
//                        q[u].push_front(q[v].front());
//                        q[v].pop_front();
//                    }
//                }
//                else
//                {
//                    while(!q[v].empty())
//                    {
//                        q[u].push_front(q[v].back());
//                        q[v].pop_back();
//                    }
//                }
//            }
//        }
//    }
//}
//
