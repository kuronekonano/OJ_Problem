#include<bits/stdc++.h>
using namespace std;
struct num
{
    int val,pos;
} a[508],b[508];
bool cmp(num a,num b)
{
    return a.val<b.val;
}
int ans[508*508];
int main()
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        bool flag=true;
        memset(ans,0,sizeof(ans));
        for(int i=1; i<=n; i++)
        {
            scanf("%d",&a[i].val);
            b[i].val=a[i].val;
            b[i].pos=a[i].pos=i;
        }
        sort(b+1,b+n+1,cmp);
        int it=1;
        for(int i=1; i<=n; i++)
        {
            ans[a[b[i].pos].val]=b[i].pos;
            for(int j=1; j<b[i].pos; j++) ///�ڵ�valΪ֮ǰҪ���pos��pos
            {
                while(ans[it])it++;///ֻ����û�б�������λ����
                ans[it]=b[i].pos;
            }
            if(it>a[b[i].pos].val)///����䳬��˵��������������
            {
                printf("No\n");
                flag=false;
                break;
            }
        }
        if(!flag) continue;
        for(int i=1; i<=n; i++) ///��������������������䣬��֤��valǰ����乻pos��
        {
            for(int j=1; j<=n-b[i].pos; j++) ///�ٷ�����䣬ǰpos���ܱ�֤������£���ʣ���λ����乻n��
            {
                while(ans[it])it++;
                if(it<a[b[i].pos].val)///��һ��ѭ���������±�̫С���������������жϷ�ֹ�±�̫����valλ���������ʣ��n-pos��
                {
                    printf("No\n");
                    flag=false;
                    break;
                }
                ans[it]=b[i].pos;
            }
            if(!flag) break;
        }
        if(flag)printf("Yes\n");
//        for(int i=1; i<=n*n; i++)printf("%d ",ans[i]);
    }
}
