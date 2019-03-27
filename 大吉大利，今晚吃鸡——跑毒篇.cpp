#include<stdio.h>
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int a,b,c,blood=100;
        scanf("%d%d%d",&a,&b,&c);
        int down=a*6+1;
        bool ans=false;
        if(a*b<=100)ans=true;
        while(blood&&!ans)
        {
            int tmp=blood-down;
            b-=tmp/a;
            blood-=a*(tmp/a);
            if(b<=0)
            {
                ans=true;
                break;
            }
            if(c)
            {
                blood=80;
                c--;
            }
            if(!c)
            {
                b-=blood/a;
                blood-=a*(blood/a);
                if(b==1&&blood)ans=true;
                if(b<=0)ans=true;
                break;
            }
        }
        printf("%s\n",ans?"YES":"NO");
    }
}
