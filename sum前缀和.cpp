#include<stdio.h>
#include<string.h>
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int i,m,n,a,sum=0;
        bool vis[5005],flag=false;
        memset(vis,false,sizeof(vis));
        scanf("%d%d",&n,&m);
        for(i=0;i<n;i++)///����
        {
            scanf("%d",&a);
            sum=sum+a;///���
            sum=sum%m;///��ģ
            if(vis[sum])///�����ǰ��ģ�Ľ������֮�󻹳����ˣ�˵��ģһ������ô˵�����ڱ�����ϵ
            {
                flag=true;///���ڱ�����ϵ���
            }
            vis[sum]=true;///����ֱ��break����һ������һ���ҵ�
        }
        printf(flag||vis[0]?"YES\n":"NO\n");
    }
    return 0;
}
