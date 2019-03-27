#include<stdio.h>
#include<string.h>
int main()
{
    char a[1008];
    while(scanf("%s",a)!=EOF)
    {
        int i,n,sum=0;
        n=strlen(a);
        for(i=0;i<n;i++)
        {
            sum+=a[i]-'0';
        }
        printf("%d\n",sum%3==0?0:1);
    }
    return 0;
}
