#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<math.h>
using namespace std;
int gcd(int a,int b)//���Լ��
{
    int c;
    while(b!=0)
    {
        c=a%b;
        a=b;
        b=c;
    }
    return a;
}
int main()
{
    int a,i,b,c,d;
    char k;
    int x,y;
    while(scanf("%d/%d%c%d/%d",&a,&b,&k,&c,&d)!=EOF)
    {
        i=b*d/gcd(abs(b),abs(d));//��С������
        if(k=='+')
        {
            x=a*(i/b)+c*(i/d);
            y=i;
            i=gcd(abs(x),abs(y));
            x=x/i;
            y=y/i;
            if(x%y==0)
            {
                printf("%d\n",x/y);
            }
            else
            {
                if(x<0&&y>0||x>0&&y<0)
                {
                    printf("-%d/%d\n",abs(x),abs(y));
                }
                else
                {
                    printf("%d/%d\n",abs(x),abs(y));
                }
            }
        }
        else if(k=='-')
        {
            x=a*(i/b)-c*(i/d);
            y=i;
            i=gcd(abs(x),abs(y));
            x=x/i;
            y=y/i;
            if(x%y==0)
            {
                printf("%d\n",x/y);
            }
            else
            {
                if((x<0&&y>0)||(x>0&&y<0))
                {
                    printf("-%d/%d\n",abs(x),abs(y));
                }
                else
                {
                    printf("%d/%d\n",abs(x),abs(y));
                }
            }
        }
    }
    return 0;
}
