#include<stdio.h>
#include<math.h>
int main()
{
    int s,n;
    while(scanf("%d",&n)!=EOF)//��Ӧע��pow������������,���򽫱������
    {
        s=pow(n%3,5);//(n^5)%3=((n%3)^5)%3
        printf("%d\n",s%3);
    }
    return 0;
}
