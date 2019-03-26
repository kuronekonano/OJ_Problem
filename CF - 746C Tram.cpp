#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<stdlib.h>
using namespace std;
int main()
{
    int s,x1,x2,t1,t2,p,d,i;
    while(scanf("%d%d%d%d%d%d%d",&s,&x1,&x2,&t1,&t2,&p,&d)!=EOF)
    {
       int peo=abs(x2-x1)*t2;
       if(d>0)
       {
           if(p<=x1&&x1<x2)s=x2-p;
           else if(x1<x2&&x2<=p)s=s-p+s+x2;
           else if(x1<p&&p<=x2)s=s-p+s+x2;
           else if(x2<=p&&p<=x1)s=s-p+s-x2;
           else if(x2<x1&&x1<=p)s=s-p+s-x2;
           else if(p<=x2&&x2<x1)s=s-p+s-x2;
       }
       else
       {
           if(p<=x1&&x1<x2)s=p+x2;
           else if(x1<x2&&x2<=p)s=p+x2;
           else if(x1<=p&&p<=x2)s=p+x2;
           else if(x2<=p&&p<x1)s=p+s+s-x2;
           else if(x2<x1&&x1<=p)s=p-x2;
           else if(p<=x2&&x2<x1)s=p+s+s-x2;
       }
       int ans=min(peo,s*t1);
       printf("%d\n",ans);
    }
}
