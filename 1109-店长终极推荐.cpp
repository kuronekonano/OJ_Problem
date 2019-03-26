#include<bits/stdc++.h>
#define LL long long
#define M(a,b) memset(a,b,sizeof a)
using namespace std;
int t;
map<string,int>q;
char a[209];
int main()
{
    while(scanf("%d",&t)&&t)
    {
        getchar();
        while(t--)
        {
            int ans=0;
            string str;
            str.clear();
            q.clear();
            gets(a);
            int len=strlen(a);
            for(int i=0; i<len-1; i++)
            {
                string tmp;
                tmp+=a[i];
                tmp+=a[i+1];
                q[tmp]++;
                if(q[tmp]>=ans)
                {
                    if(q[tmp]==ans)
                    {
                        if(tmp<str)str=tmp;
                    }
                    else ans=q[tmp],str=tmp;
                }
            }
            cout<<str<<endl;
        }
        puts("");
    }
}
