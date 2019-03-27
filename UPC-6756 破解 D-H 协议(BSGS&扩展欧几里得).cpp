#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int maxn=1e5+7;
LL a,b,p,g,m;
map<LL,int>mp;
inline LL qp(LL a,LL b)///������
{
    LL ans=1;
    while(b)
    {
        if(b&1)ans=(ans*a)%p;
        a=(a*a)%p;
        b>>=1;
    }
    return ans;
}
int exgcd(LL a,LL b,LL &xx,LL &yy)///��չŷ�����
{
    if(!b)
    {
        xx=1,yy=0;
        return a;
    }
    int gcd=exgcd(b,a%b,yy,xx);
    yy-=xx*(a/b);
    return gcd;
}
inline LL inv(LL x)///����Ԫ
{
    LL xx,yy;
    return exgcd(x,p,xx,yy)==1?(xx+p)%p:-1;
}
inline LL cal(LL num)///Ԥ����
{
    for(int i=0; i<=m; i++)
    {
        LL k=num*inv(qp(g,i*m))%p;
        if(mp.count(k))return mp[k]+i*m;
    }
    return -1;
}
int main()
{
    int t;
    mp.clear();
    scanf("%lld%lld%d",&g,&p,&t);
    m=ceil(sqrt(p));
    mp[1]=0;
    LL x=1;
    for(int i=1; i<=m; i++)
    {
        x=x*g%p;
        if(!mp[x])mp[x]=i;
    }
    while(t--)
    {
        scanf("%lld%lld",&a,&b);
        LL ab=cal(b);
        printf("%lld\n",qp(a,ab));
    }
}
///exgcd���ʲ���Ϊ������Ԫ,������ax+by=gcd(a,b)��(x,y)��
///a p���ʾ����÷�������Ԫ
