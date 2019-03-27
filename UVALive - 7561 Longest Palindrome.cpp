#include<stdio.h>
#include<string.h>
int main()
{
    int n,aa,ab,ba,bb,i,t;
    char a[5];
    scanf("%d",&t);
    while(t--)
    {
        aa=0;bb=0;ab=0;ba=0;
        scanf("%d",&n);
        for(i=0;i<n;i++)
        {
            scanf("%s",a);
            if(strcmp(a,"aa")==0)aa++;
            else if(strcmp(a,"bb")==0)bb++;
            else if(strcmp(a,"ab")==0)ab++;
            else if(strcmp(a,"ba")==0)ba++;
        }
        int num=ab>ba?ba:ab;
        for(i=1;i<=aa/2;i++)printf("aa");
        for(i=1;i<=num;i++)printf("ab");
        for(i=1;i<=bb/2;i++)printf("bb");
        if(aa%2!=0)printf("aa");
        else if(aa%2==0&&bb%2!=0)printf("bb");
        for(i=1;i<=bb/2;i++)printf("bb");
        for(i=1;i<=num;i++)printf("ba");
        for(i=1;i<=aa/2;i++)printf("aa");
        printf("\n");
    }
}
