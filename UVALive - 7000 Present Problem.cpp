#include<stdio.h>///��������ӳ��ÿ���ڵ����������һ��line����������link�����¼ÿ����Ծ�ڵ�ĸ߶�
#include<string.h>
#include<algorithm>
using namespace std;
int ma[10004][10004],link[10004][10004];
int main()
{
    int t,n,m,l;
    scanf("%d",&t);
    while(t--)
    {
        int k,x;
        memset(link,0,sizeof(link));
        memset(ma,0,sizeof(ma));
        scanf("%d%d%d",&n,&m,&l);
        for(int i=0;i<m;i++)
        {
            scanf("%d%d",&x,&k);
            ma[x][k]=x+1;///ÿ���ߵĸ߶�kλ��ӳ�䵽��line
            ma[x+1][k]=x;
            link[x][0]++;///������0λ���ڴ洢����line����Ծ�ڵ����
            link[x+1][0]++;
            link[x][link[x][0]]=k;///����½ڵ�ĸ߶�
            link[x+1][link[x+1][0]]=k;
        }
        for(int i=0;i<n;i++)sort(link[i]+1,link[i]+1+link[i][0]);///��¼ÿ��k��λ�ã���Ϊ����������Ҫ����
        for(int i=0;i<n;i++)
        {
            int ans=i;k=0;
            while(1)
            {
                int tmp=*upper_bound(link[ans]+1,link[ans]+1+link[ans][0],k);///�����ҳ���һ�����ӵ�ĸ߶�
                if(tmp==0)break;///���ҵ��ĸ߶�Ϊ0ʱ��˵����ʱ�ҵ���λ���Ѿ���link[ans][0]���ҵ��˺���һ��δ��ֵ��Ԫ�أ�˵������û���������ӵ㣬ֱ�ӵ����յ�
                ans=ma[ans][tmp];///�ƶ����ø߶�ӳ���line
                k=tmp;///�õ���ǰ�߶ȣ���������һ��line�����¸߶�
            }
            printf("%d\n",ans);
        }
    }
}
