#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
int main()
{
    int n,i,j,k;
    char a[108];
    while(scanf("%d%d",&n,&k)!=EOF)
    {
        scanf("%s",a);
        int g,t;
        for(i=0;i<n;i++)
        {
            if(a[i]=='T')t=i;
            if(a[i]=='G')g=i;
        }
        bool flag=false;
        for(i=min(g,t)+k;i<n;i+=k)
        {
            if(a[i]=='#')
            {
                break;
            }
            if(a[i]=='G'||a[i]=='T')
            {
                printf("YES\n");
                flag=true;
                break;
            }
        }
        if(!flag)printf("NO\n");
    }
}
