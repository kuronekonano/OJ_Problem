#include<stdio.h>
#include<string.h>
int co[100005],x[100005],y[100008];
int main()
{
    int n,link[100005];
    while(scanf("%d",&n)!=EOF)
    {
        memset(co,0,sizeof(co));
        memset(x,0,sizeof(x));
        memset(y,0,sizeof(y));
        memset(link,0,sizeof(link));
        for(int i=1;i<=n-1;i++) scanf("%d%d",&x[i],&y[i]);
        for(int i=1;i<=n;i++) scanf("%d",&co[i]);
        int sum=0;
        for(int i=1;i<=n-1;i++)
        {
            if(co[x[i]]!=co[y[i]])
            {
                sum++;///���ڵ�Ӧ�еĲ�ͬ��ɫ���Ӵ���
                link[x[i]]++;link[y[i]]++;///�����Ϊ���ڵ㣬����������ӵĲ�ͬ��ɫ�ڵ����
            }
        }
        bool flag=false;
        for(int i=1;i<=n;i++)
        {
            if(sum==link[i])///һ���нڵ������Ϊ���ڵ�����Ӵ�����������
            {
                printf("YES\n%d\n",i);
                flag=true;
                break;
            }
        }
        if(!flag)printf("NO\n");

    }
}
/*
���⣺һ������n���ڵ㱻Ⱦ����co[i]��ɫ��������һ���������ѡһ���ڵ���Ϊ���ڵ�,Ȼ���������̧�����������Ƿ����һ���ڵ㣬ʹ���������Ϊ���ڵ�����������еĽڵ����ɫ��ͬ
����˼·�����������Ľڵ㣬�ߵ����˶˵���ɫ��һ���ı�(��Ϊ�����,�����ı�����Ϊsum)�϶����к͸��ڵ�����һ���(���û�к͸��ڵ������Ļ�,�϶����������������������ɫ��һ����);
*/
