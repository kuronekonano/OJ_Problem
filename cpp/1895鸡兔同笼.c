#include<stdio.h>
int main()
{
    int x,y,a,b;
    //printf("头的数量有：");
    while(scanf("%d%d",&x,&y)!=EOF)
    {//printf("脚的数量有：");
        a=(4*x-y)/2;
        b=x-a;
        if(a<0||b<0||y%2!=0)
        {printf("something wrong\n");}//("输入错误\n");
        else
        {
            printf("chicken:%d ",a);
            printf("rabbit:%d\n",b);
        }
    }
    return 0;
}
