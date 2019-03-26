#include<stdio.h>
#include<string.h>
int main()
{
    char a[29];
    int t,i;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%s",a);
        int n=strlen(a);
        if(a[n-1]=='p'&&a[n-2]=='p'&&a[n-3]=='c'&&a[n-4]=='.'&&a[n-5]!='.')
        {
            printf("c++\n");
        }
        else if(a[n-1]=='a'&&a[n-2]=='v'&&a[n-3]=='a'&&a[n-4]=='j'&&a[n-5]=='.'&&a[n-6]!='.')
        {
            printf("java\n");
        }
        else if(a[n-1]=='c'&&a[n-2]=='.'&&a[n-3]!='.')
        {
            printf("c\n");
        }
        else
        {
            printf("none\n");
        }
    }
    return 0;
}
