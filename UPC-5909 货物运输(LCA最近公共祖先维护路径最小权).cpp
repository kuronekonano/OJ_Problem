#include<stdio.h>///LCA����������������㷨
#include<string.h>
#include<algorithm>
using namespace std;
int fa[100005];
int val[100005];
int deep(int x)
{
    int cnt=0;
    while(x)
    {
        cnt++;
        x=fa[x];
    }
    return cnt;
}
int main()
{
    int n,m;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        int x,y,w;
        memset(fa,0,sizeof(fa));
        for(int i=0;i<n-1;i++)
        {
            scanf("%d%d%d",&x,&y,&w);///���ڽ�ͼ����Ϊ��Ŀû�и������ӹ�ϵ��Ҳû���Ⱥ�˳��
            if(fa[x]!=0)fa[y]=x,val[y]=w;///����ж�˫���Ƿ��и��׼��ɣ������û�и���Ĭ��x������
            else fa[x]=y,val[x]=w;
        }
        while(m--)
        {
            scanf("%d%d",&x,&y);
            int dx=deep(x),dy=deep(y);
            int minx=0x7fffffff,miny=0x7fffffff;///ֻ���ڻ���ʱ����ά����ǰ��СȨ
            if(dx<dy)
            {
                int tt=dy-dx;
                while(tt--)
                {
                    miny=min(miny,val[y]);///ע����ȡ��СȨ�����ϻ���
                    y=fa[y];
                }
            }
            else if(dx>dy)
            {
                int tt=dx-dy;
                while(tt--)
                {
                    minx=min(minx,val[x]);
                    x=fa[x];
                }
            }
            while(x!=y)///ÿ�λ��ݶ���ȡ��СȨ
            {
                minx=min(minx,val[x]);
                x=fa[x];
                miny=min(miny,val[y]);
                y=fa[y];
            }
            printf("%d\n",min(minx,miny));
        }
    }
}
