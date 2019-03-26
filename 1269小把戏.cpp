#include<stdio.h>
#include<string.h>
int main()
{
    char a[10000],b[1000];
    while(scanf("%s %s",a,b)!=EOF)//每个位单独相加求和
    {
        int sum=0;
        int n=strlen(a);
        int m=strlen(b);
        for(int i=0;i<n;i++)
        {
            sum=sum+a[i]-'0';
        }
        for(int i=0;i<m;i++)
        {
            sum=sum+b[i]-'0';
        }
        printf("%d\n",sum);
    }
    return 0;
}
