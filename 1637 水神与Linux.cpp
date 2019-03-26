#include<stdio.h>
#include<string.h>
char a[10008],b[10008];
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        memset(a,0,sizeof(a));
        memset(b,0,sizeof(b));
        int num=1;
        scanf("%s",a);
        getchar();
        bool flag=false;
        while(gets(b))
        {
            num++;
            if(strcmp(b,"EOF")==0)break;
            else if(strstr(b,a)!=NULL)
            {
                flag=true;
                printf("%4d %s\n",num-1,b);
            }
        }
        if(!flag)printf("Can not find string: %s\n",a);
        printf("\n");
    }
    printf("\n");
}
