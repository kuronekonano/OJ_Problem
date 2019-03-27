#include<bits/stdc++.h>///��ʬ�Ĵ�Ⱦ�������,���������֪�ǰ���"α����"��������Ⱦ��
#define LL long long
using namespace std;
const int maxn=1e7+5;
const int mod=1e9+7;
int fac[maxn],inv[maxn];
bool vis[maxn];///��ô���ҵ����е�α�����ͷ�α���������д�Ⱦ˳����������
LL poww(LL a,LL b)
{
    LL ans=1;
    while(b)
    {
        if(b&1)ans=(ans*a)%mod;
        a=(a*a)%mod;
        b>>=1;
    }
    return ans;
}
int prim(int l,int r)
{
    int sum=0;
    for(int i=l; i<=r; i++)
        if(!vis[i])
        {
            sum++;
            for(int j=i*2;j<=r;j+=i)vis[j]=true;
        }
    return sum;
}
int init(int r)///����Ԥ�����������
{
    fac[0]=1;
    for(int i=1; i<=r; i++)
        fac[i]=1LL*i*fac[i-1]%mod;
    inv[r]=poww(fac[r],mod-2);
    for(int i=r; i; i--)
        inv[i-1]=1LL*i*inv[i]%mod;
}
int main()
{
    int l,r;
    scanf("%d%d",&l,&r);
    init(r);
    if(l==1)
    {
        printf("%lld\n",1LL*fac[r]*(r+1)%mod*poww(2,mod-2)%mod);
        return 0;
    }
    int sum=prim(l,r);
    int len=r-l+1;
    LL ans=0;
    for(int i=sum;i<=len;i++)ans=(ans+1LL*sum*fac[len-sum]%mod*inv[i-sum]%mod*fac[i]%mod)%mod;
    printf("%lld\n",ans);
}
