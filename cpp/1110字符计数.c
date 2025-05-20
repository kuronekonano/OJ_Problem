#include<stdio.h>
#include<string.h>
int main()
{
    char c[21];
    while(scanf("%s",&c)!=EOF)
    {
        printf("%d\n",strlen(c));//strlen函数用于字符串的计数，可以记空格
    }
    return 0;
}
