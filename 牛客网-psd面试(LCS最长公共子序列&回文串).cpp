#include<stdio.h>///�����������
#include<string.h>
#include<algorithm>
using namespace std;
int vis[2008][2009],t;
int main()
{

    char x[2005];
    char y[2004];
    while(scanf("%s",x+1)!=EOF)
    {
        memset(vis,0,sizeof(vis));
        int lx=strlen(x+1);
        for(int i=1; i<=lx; i++)///���Ĵ������У�������ѡ��һ�β�������������ʹ��Ϊ���Ĵ�
            if(x[i]>='a'&&x[i]<='z') x[i]=x[i]-'a'+'A';///��ԭ������������������������������м�����Ĵ�
        int ly=0;
        for(int i=lx; i>=1; i--) y[++ly]=x[i];
//        printf("%s  \n%s\n",x+1,y+1);
        for(int i=1; i<=lx; i++)///�߽��ʼ�������մ����г��ȵĴ��Ƚ�ʱ�����������г���Ϊ0
        {
            vis[i][0]=0;
        }
        for(int i=1; i<=ly; i++)
        {
            vis[0][i]=0;
        }
        vis[0][0]=0;///�մ��ȽϿմ�
        for(int i=1; i<=lx; i++)///dp������i��j��ʾ����һ������i����һ������jʱ���ڴ�����µ������������
        {
            for(int j=1; j<=ly; j++)///��ˣ�ÿ������һ�����ĳ���i��j���Ա����ַ��Ƿ�����ȵ������˵�����ַ�����������������У��̳�i-1,j-1(�������ַ�����ȡ��ǰ�ַ����ֵ)
            {///������ǰ�Ա��ַ����ʱ��ֱ�Ӵ�i-1,j-1����ֵ+1������i-1,j��i,j-1���̳�
                if(x[i]!=y[j])
                {///���ַ�����ʱ������������ȡ���ֵ���̳�

                    vis[i][j]=vis[i-1][j-1];
                    vis[i][j]=max(vis[i-1][j],max(vis[i][j],vis[i][j-1]));
                }
                else
                    vis[i][j]=vis[i-1][j-1]+1;
            }
        }
//        printf("   ");
//        for (int i=1; i<=lx; ++i)
//            printf(" %c",x[i]);
//        puts("");
//        for(int i=0; i<=ly; i++)
//        {
//            printf("%c ",i==0?' ':y[i]);
//            for(int j=0; j<=lx; j++)
//                printf("%d%c",vis[i][j],j==lx?'\n':' ');
//        }
        printf("%d\n",ly-vis[lx][ly]);
    }
    return 0;
}

