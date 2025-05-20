#include<stdio.h>
#include<math.h>
int main()
{
    int x;
    while(scanf("%d",&x)!=EOF)//卧槽特么是滑下来两米
    {
        if(x<=3)
            printf("1\n");
        else
            printf("%d\n",x-2);//4米时，第一天走三米掉两米，第二天一米加三米达到4米
    }
    return 0;
}
