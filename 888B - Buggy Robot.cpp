#include<bits/stdc++.h>///���������ߣ�ȥ���м������ǰ��һЩָ��󣬻������ܻص�ԭ������ָ������ֻ�ü�����ȥ�ͻ����Ĵ����ͺ�
using namespace std;
int main()
{
    int n;
    char a[1002];
    while(scanf("%d",&n)!=EOF)
    {
        scanf("%s",a);
        int R=0,L=0,U=0,D=0,ans=0;
        for(int i=0;i<n;i++)
        {
            if(a[i]=='L')L++;
            if(a[i]=='R')R++;
            if(a[i]=='U')U++;
            if(a[i]=='D')D++;
        }
        ans=2*min(L,R)+2*min(U,D);
        printf("%d\n",ans);
    }
}
