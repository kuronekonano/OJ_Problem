#include<stdio.h>
#include<math.h>
int main()
{
    int s,n;
    while(scanf("%d",&n)!=EOF)//还应注意pow函数后不能求余,否则将编译错误
    {
        s=pow(n%3,5);//(n^5)%3=((n%3)^5)%3
        printf("%d\n",s%3);
    }
    return 0;
}
