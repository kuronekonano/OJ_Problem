#include<stdio.h>
int main()
{
    int x,y,a,b;
    //printf("ͷ�������У�");
    while(scanf("%d%d",&x,&y)!=EOF)
    {//printf("�ŵ������У�");
        a=(4*x-y)/2;
        b=x-a;
        if(a<0||b<0||y%2!=0)
        {printf("something wrong\n");}//("�������\n");
        else
        {
            printf("chicken:%d ",a);
            printf("rabbit:%d\n",b);
        }
    }
    return 0;
}
