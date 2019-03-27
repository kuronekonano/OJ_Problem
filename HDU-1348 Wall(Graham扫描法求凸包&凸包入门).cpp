#include<bits/stdc++.h>
#define LL long long
#define M(a,b) memset(a,b,sizeof a)
#define pb(x) push_back(x)
using namespace std;
const int maxn=1e3+7;
const double PI=acos(-1.0);
struct node///����
{
    double x,y;
} p[maxn],P[maxn];
int n,tot;
double ans,r;
double X(node A,node B,node C)///���
{
    return (B.x-A.x)*(C.y-A.y)-(C.x-A.x)*(B.y-A.y);
}
double dis(node A,node B)///�������
{
    return sqrt((A.x-B.x)*(A.x-B.x)+(A.y-B.y)*(A.y-B.y));
}
bool cmp(node A,node B)///��������
{
    double pp=X(p[0],A,B);
    if(pp>0)return true;
    if(pp<0)return false;
    return dis(p[0],A)<dis(p[0],B);///������ͬ����0����������ǰ��
}
int main()
{
    int t;
    bool flag=false;
    scanf("%d",&t);
    while(t--)
    {
        if(!flag)flag=true;
        else printf("\n");
        scanf("%d%lf",&n,&r);
        ans=2*PI*r;///Բ�ܳ�
        for(int i=0; i<n; i++)scanf("%lf%lf",&p[i].x,&p[i].y);///����n������
        if(n==1)printf("%.0f\n",ans);///͹����ֻ��һ���㣬ֱ�����Բ�ܳ�
        else if(n==2)printf("%.0f\n",ans+dis(p[0],p[1]));///͹�����������㣬��������Բ�ܳ�
        else
        {
            for(int i=0; i<n; i++)///����n���ڵ��ҵ�0�Žڵ�
            {
                if(p[0].y<p[0].y)swap(p[i],p[0]);///�ҵ��ȵ�ǰ0�Žڵ�y����С�ģ�����
                else if(p[0].y==p[0].y&&p[i].x<p[0].x)swap(p[i],p[0]);///�ҵ��뵱ǰ0�Žڵ�y������ͬ��x�����С��,����
            }
            sort(p+1,p+n,cmp);///����p[0]������˲���p[0]�ŵ�����������
            P[0]=p[0];///P����͹���ϵĵ�
            P[1]=p[1];///͹���ϵ�һ���㣬��P[0]�����ڵ�
            tot=1;///͹�����������㣬p[0]���㣬�Ѿ�ѡ�õ�p[1]��һ����
            for(int i=2; i<n; i++)///����ѡ����ĵ�
            {///����ж���ѡ����µ����������λ�ù�ϵ�����������ұߣ���ôѡ�µ�
                while(tot>0&&X(P[tot-1],P[tot],p[i])<=0)tot--;///whileģ��ջɸѡ͹���ϵĽڵ�
                tot++;
                P[tot]=p[i];
            }///͹������
            for(int i=0; i<tot; i++) ans+=dis(P[i],P[i+1]);///�ܳ����
            ans+=dis(P[0],P[tot]);///�����һ���ڵ��0�Žڵ�ķ�վ���
            printf("%.0f\n",ans);
        }
    }
}
