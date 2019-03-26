#include<stdio.h>
#include<stdlib.h>
int n,x1[500005],x2,y1[500005],y2,i;
int main()
{
    while(scanf("%d",&n)!=EOF)
    {
        for(i=0; i<n; i++)scanf("%d%d%d%d",&x1[i],&y1[i],&x2,&y2);
        printf("YES\n");
        for(i=0; i<n; i++)
            if(abs(x1[i])%2==1&&abs(y1[i])%2==0)printf("1\n");
            else if(abs(x1[i])%2==0&&abs(y1[i])%2==0) printf("2\n");
            else if(abs(x1[i])%2==1&&abs(y1[i])%2==1)printf("3\n");
            else if(abs(x1[i])%2==0&&abs(y1[i])%2==1)printf("4\n");

    }
}
