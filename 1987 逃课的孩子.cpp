#include<map>
#include<string>
#include<stdio.h>
using namespace std;
int main()
{
    int n,m;
    map<string,bool>mp;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        mp.clear();
        char a[20];
        for(int i=0;i<n;i++)
        {
            scanf("%s",a);
            mp[a]=true;
        }
        for(int i=0;i<m;i++)
        {
            scanf("%s",a);
            printf("%s\n",mp[a]?"yes":"no");
        }
    }
}
