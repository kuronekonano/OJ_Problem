#include<bits/stdc++.h>
using namespace std;
struct node///���ڶ�����ÿ���ڵ㣬һ��ֵ��ʾ���꣬Ҳ������ģ���ά������һά������±�
{///�Լ�һ����ʾ���ﵱǰλ�õ�ʱ�䣬��Ϊ���ݵ���ĳ��λ�õ�ʱ�䲻ͬ�����ֵ�᲻ͬ
    int pos,time;
    node (int x,int y)///���캯��
    {
        pos=x;
        time=y;
    }
};
queue<node>q;///�˴��ı������3��״̬��һ����һ�ζ�û�ߣ���-1��ʾ��һ��������һ�Σ���¼�߹�����һ����ʲô״̬�����������߹����Σ�����������ڵ�
int t,n,m,a[100008],sx,sy,ex,ey,vis[100005];///��Ϊn*mһ��С��1e5�������һά����ģ���ά����
bool dir(int pos,int time)///�ж����߷��򣬸��ݵ���õ�ʱ���ж����ֵ���Ǻ��߻�������
{
    if(time%2==0&&a[pos]==0||time%2==1&&a[pos]==1)return true;///����
    else return false;///����
}
bool judge(int x,int y,int time)///�жϸõ��Ƿ�����
{
    if(x>=0&&x<n&&y>=0&&y<m)///��������ͼ����
    {
        if(vis[x*m+y]==-1)///��һ��û�߹������ߣ����Ҽ�¼��һ���߸õ��״̬
        {
            vis[x*m+y]=dir(x*m+y,time)?0:1;
            return true;
        }
        if(vis[x*m+y]==0&&dir(x*m+y,time)==1)return false;///����߹�һ�Σ����ҵڶ���������Ȼ����ͬ��״̬����
        if(vis[x*m+y]==0&&dir(x*m+y,time)==0)///���ǲ�ͬ��״̬�������ߣ����ұ��Ϊ�߹�����
        {
            vis[x*m+y]=2;
            return true;
        }
        if(vis[x*m+y]==1&&dir(x*m+y,time)==1)
        {
            vis[x*m+y]=2;
            return true;
        }
        if(vis[x*m+y]==1&&dir(x*m+y,time)==0)return false;
        if(vis[x*m+y]==2)return false;///�������߹����εĵ�����
    }
    return false;

}
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        while(!q.empty())q.pop();
        scanf("%d%d",&n,&m);
        for(int i=0; i<=n*m; i++) vis[i]=-1;///��ʼ���������
        for(int i=0; i<n; i++)
            for(int j=0; j<m; j++)
                scanf("%d",&a[i*m+j]);
        scanf("%d%d%d%d",&sx,&sy,&ex,&ey);
        node st=node((sx-1)*m+sy-1,0);
        node ed=node((ex-1)*m+ey-1,0);
        vis[st.pos]=a[st.pos];///�����
        q.push(st);
        int ans=0x7fffffff;
        while(!q.empty())
        {
            node top=q.front();
            q.pop();
            int tmx=top.pos/m;///��������
            int tmy=top.pos%m;
            int tim=top.time;
//            printf("==%d   %d   %d==\n",tmx,tmy,tim);
            if(tmx==ed.pos/m&&tmy==ed.pos%m)///�ж��Ƿ񵽴��յ�
            {
                ans=tim>ans?ans:tim;
                break;
            }
            if(dir(tmx*m+tmy,tim))///����
            {
                tim++;
                if(judge(tmx+1,tmy,tim)) q.push(node((tmx+1)*m+tmy,tim));///����
                if(judge(tmx-1,tmy,tim)) q.push(node((tmx-1)*m+tmy,tim));///����
            }
            else///����
            {
                tim++;
                if(judge(tmx,tmy-1,tim))q.push(node(tmx*m+tmy-1,tim));///����
                if(judge(tmx,tmy+1,tim))q.push(node(tmx*m+tmy+1,tim));///����
            }
        }
        printf("%d\n",ans==0x7fffffff?-1:ans);///�ж��Ƿ��ߵ�ͨ
    }
}
