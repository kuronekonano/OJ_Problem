#include<bits/stdc++.h>
using namespace std;
const int maxn=5e5+10;
int n,tot;
int tre[maxn][26];
int insert(char *str,int rt)
{
    for(int j=0; str[j]; j++)
    {
        int x=str[j]-'A';
        if(tre[rt][x]==0)
            tre[rt][x]=++tot,memset(tre[tre[rt][x]],0,sizeof(tre[tre[rt][x]]));
        rt=tre[rt][x];
    }
}
int finds(char str[],int rt)
{
    int len=strlen(str);
    for(int i=0; i<len; i++)
    {
        int x=str[i]-'A';
        if(tre[rt][x]==0)return 0;
        rt=tre[rt][x];
    }
    return rt;
}
int main()
{
    while(scanf("%d",&n)!=EOF)
    {
        int tot=0;
        int rt=tot++;
        memset(tre[rt],0,sizeof tre[rt]);
        char a[105];
        for(int i=0; i<n; i++)
            scanf("%s",a),insert(a,rt);
        scanf("%s",a);
        int ans=finds(a,rt);
        for(int i=1; i<=32; i++)
        {
            if(i>=1&&i<=3||i>=30&&i<=32)printf("*");
            else
            {
                if(tre[ans][i-4]!=0)printf("%c",i-4+'A');
                else printf("*");
            }
            if(i%8==0)printf("\n");
        }
    }
}
