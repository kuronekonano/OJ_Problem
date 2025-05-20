#include<stdio.h>
#include<math.h>
int main()
{
    int r,a,b,r2;
    while(scanf("%d%d%d",&r,&a,&b)!=EOF)
    {
        r2=sqrt(pow(a/2,2)+pow(b/2,2));//桌子中心到棋盘四角的距离
        if(r2<=r)
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}
