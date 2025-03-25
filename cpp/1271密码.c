#include<stdio.h>
#include<string.h>
int main()
{
    int t,n;
    char a[100];
    while(gets(a))
    {
        n=strlen(a);
        for(t=n;t>0;t--)
        {
            printf("*");
        }
        printf("\n");
    }
    return 0;
}
