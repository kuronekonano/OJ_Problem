#include<stdio.h>
#include<math.h>
#include<string.h>
#include<algorithm>
using namespace std;
int n,m,t;
int tri[305][305][102];///��ά���飬��ά��ʾ���꣬��ά��ʾ�����ֳ��ִ�����ǰ׺�ͼ��������ֳ��ִ���
int a[305][305];
int lowbit(int x)
{
    return x&(-x);
}
void update(int x,int y,int num)
{
    for(int i=x; i<=n; i+=lowbit(i))///�Զ�ά������б���������ÿ�����ֳ��ֵĴ���
        for(int j=y; j<=m; j+=lowbit(j))
            tri[i][j][num]++;
}
void del(int x,int y,int num)
{
    for(int i=x; i<=n; i+=lowbit(i))///�������ֽ��и�����ɾ��ĳ���ֵĳ��ִ���Ӱ��
        for(int j=y; j<=m; j+=lowbit(j))
            tri[i][j][num]--;
}
int sum(int x,int y,int z)///��Ŀ�����������1,1λ�ã��õ����������ǰ׺��
{
    int sum=0;
    for(int i=x; i>0; i-=lowbit(i))
        for(int j=y; j>0; j-=lowbit(j))
            sum+=tri[i][j][z];
    return sum;
}
int main()
{
    scanf("%d%d",&n,&m);
    memset(tri,0,sizeof(tri));
    for(int i=1; i<=n; i++)
        for(int j=1; j<=m; j++)
        {
            scanf("%d",&a[i][j]);
            update(i,j,a[i][j]);
        }
    scanf("%d",&t);
    while(t--)
    {
//        printf("=====%d\n",t);
        int flag;
        scanf("%d",&flag);
        if(flag==1)
        {
            int x,y,tmp;
            scanf("%d%d%d",&x,&y,&tmp);
            del(x,y,a[x][y]);
            a[x][y]=tmp;
            update(x,y,tmp);
        }
        else
        {
            int x1,x2,y1,y2,tmp,ans=0;
            scanf("%d%d%d%d%d",&x1,&x2,&y1,&y2,&tmp);
            ans=sum(x2,y2,tmp)-sum(x1-1,y2,tmp)-sum(x2,y1-1,tmp)+sum(x1-1,y1-1,tmp);///�ݳ�ԭ��������ͺ����õ���1,1��ʼ�����½ǽڵ��ȫ������ǰ׺�ͣ���ôҪ��ȥ������������򣬼ӻر���ȥ���ε�����
            printf("%d\n",ans);
        }
    }
}
