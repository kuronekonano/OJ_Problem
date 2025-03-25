#include<stdio.h>
#include<string.h>
int main()
{
    char a[105];
    int i,n;
    while(scanf("%s",a)!=EOF)
    {
        n=strlen(a);
        for(i=0;i<n;i++)
        {
            if(a[i]>64)//可用ASCII码比较大小，也可直接用字符‘9’比较大小
            {
                printf("%c",a[i]);
            }
            if(a[i]>64&&a[i+1]<64)
                printf("\n");
        }
    }
    return 0;
}
