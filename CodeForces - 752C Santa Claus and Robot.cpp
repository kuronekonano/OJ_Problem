#include<stdio.h>
int main()
{
    int n,i;
    char a[200008];
    while(scanf("%d %s",&n,a)!=EOF)
    {
        int sum=1;
        char x,y;
        bool flag=false,flag1=false;
        for(i=0; i<n; i++)
        {
            if(!flag&&(a[i]=='U'||a[i]=='D'))
            {
                y=a[i];
                flag=true;
            }
            if(!flag1&&(a[i]=='R'||a[i]=='L'))
            {
                x=a[i];
                flag1=true;
            }
            if((a[i]=='R'||a[i]=='L'))
            {
                if(a[i]!=x)
                {
                    sum++;
                    x=a[i];
                    flag=false;
                }
            }
            if(a[i]=='U'||a[i]=='D')
            {
                if(a[i]!=y)
                {
                    sum++;
                    y=a[i];
                    flag1=false;
                }
            }
        }
        printf("%d\n",sum);
    }
}
