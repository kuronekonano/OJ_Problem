#include<stdio.h>///���Ʋ��鼯�Ĳ��Һ�����˳�Ŵ洢�ĸ��׽ڵ����ϲ��ҹ������ȣ�����У����YES,�������NO
int n,k,t,r[20005],cas=0;///�޸����ṹ��ֻ��ɾ���Լ��븸�׽ڵ�Ĺ�ϵ����ô����ڵ㽫��Ϊһ�����ڵ���ڣ�û�и��׽ڵ㣬����Ϊ0��ҲΪ���ڵ�
int fin(int x)
{
    int tmp=x;
    while(r[tmp]!=0&&r[tmp]!=tmp) tmp=r[tmp];
    return tmp;
}
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&k);
        for(int i=1;i<=n; i++) scanf("%d",&r[i]);
        char c[3];
        printf("Case #%d:\n",++cas);
        for(int i=0; i<k; i++)
        {
            scanf("%s",c);
            if(c[0]=='C')
            {
                int x;
                scanf("%d",&x);
                r[x]=x;
            }
            else
            {
                int a,b;
                scanf("%d%d",&a,&b);
                printf("%s\n",fin(a)==fin(b)?"YES":"NO");
            }
        }
    }
}
