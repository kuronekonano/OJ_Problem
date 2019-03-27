#include<bits/stdc++.h>
using namespace std;
int t,a,b,x,y;
int main()
{
    char tim[10];
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&a,&b);
        scanf("%s",tim);
        x=0,y=0;
        for(int i=4;i<strlen(tim);i++)
        {
            if(tim[i]=='.')
            {
                y=tim[i+1]-'0';
                break;
            }
            x*=10;
            x+=tim[i]-'0';
        }
        x=x*60+y*6;
        if(tim[3]=='-')x=-x;
        x-=480;
        a=a*60+b;
        a=(a+x+1440)%1440;
        printf("%02d:%02d\n",a/60,a%60);
    }
}
