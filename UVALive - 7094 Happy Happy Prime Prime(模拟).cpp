#include<stdio.h>///Ä£Äâ
#include<string.h>
#include<map>
using namespace std;
bool prim[10008];
void inti()
{
    memset(prim,false,sizeof(prim));
    prim[1]=true;
    for(int i=2;i<=10000;i++)
        if(!prim[i])
            for(int j=i+i;j<=10000;j+=i) prim[j]=true;
}
int main()
{
    inti();
    int t,k,m;
    map<int,bool>mp;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&k,&m);
        if(prim[m]) printf("%d %d NO\n",k,m);
        else
        {
            int ans=m;
            mp.clear();
            while(!mp[m]&&m!=1)
            {
                mp[m]=true;
                int tmp=m;
                m=0;
                while(tmp>0)
                {
                    m+=(tmp%10)*(tmp%10);
                    tmp/=10;
                }
            }
            printf("%d %d %s\n",k,ans,m==1?"YES":"NO");
        }
    }
}
