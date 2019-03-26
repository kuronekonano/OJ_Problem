#include<stdio.h>
#include<algorithm>
using namespace std;
int main()
{
    int a,b,c;
    while(scanf("%d%d%d",&a,&b,&c)!=EOF)
    {
        if(a<1||b<2||c<4)
        {
            printf("0\n");
        }
        else
        {
            b=b/2;
            c=c/4;
            int num=min(a,min(b,c));
            printf("%d\n",num+num*2+num*4);
        }
    }
}
