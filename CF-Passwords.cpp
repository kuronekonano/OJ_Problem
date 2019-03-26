#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
int main()
{
    int i,j,n,k,a[108];
    char len[108];
    while(scanf("%d%d",&n,&k)!=EOF)
    {
        for(i=0;i<n;i++)
        {
            scanf("%s",len);
            a[i]=strlen(len);
        }
        scanf("%s",len);
        int pass=strlen(len);
        sort(a,a+n);
        int best=0,bad=0,flag=0;
        for(i=0;i<n;i++)
        {
            best++;
            flag++;
            if(a[i]==pass)
                break;
            if(flag==k)
            {
                best+=5;
                flag=0;
            }
        }
        flag=0;
        for(i=0;i<n;i++)
        {
            bad++;
            flag++;
            if(a[i+1]>pass||i==n-1)
            {
                break;
            }
            if(flag==k)
            {
                flag=0;
                bad+=5;
            }
        }
        printf("%d %d\n",best,bad);
    }
    return 0;
}
