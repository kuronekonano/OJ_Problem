#include<stdio.h>
#include<string.h>
#include<string.h>
#include<algorithm>
#define LL long long
using namespace std;
const int maxn=105;
char a[maxn][maxn];
struct node
{
    int x,y;
    node() {}
    node(int a,int b)
    {
        x=a;
        y=b;
    }
} pos[30][maxn*maxn];
int t,n,m,num[30];
bool vis[26][maxn*maxn];
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        memset(vis,false,sizeof vis);
        memset(num,0,sizeof num);
        scanf("%d%d",&n,&m);
        for(int i=0; i<n; i++)
        {
            scanf("%s",a[i]);
            for(int j=0; j<m; j++)
                pos[a[i][j]-'a'][num[a[i][j]-'a']++]=node(i,j);
        }
        int ans=0;
        for(int i=0; i<26; i++)
        {
            for(int j=0; j<num[i]; j++)
            {
                int tmp=j+1;
                while(pos[i][j].x==pos[i][tmp].x&&tmp<num[i])
                {
                    if(vis[i][pos[i][j].y*100+pos[i][tmp].y])
                    {
                        tmp++;
                        continue;
                    }
//                    printf("%d=======%d\n",pos[i][j].y,pos[i][tmp].y);
                    vis[i][pos[i][j].y*100+pos[i][tmp].y]=true;
                    int cnt=1;
                    for(int k=pos[i][j].x+1; k<n; k++)
                        if(a[k][pos[i][j].y]-'a'==i&&a[k][pos[i][tmp].y]-'a'==i)cnt++;
                    ans+=cnt*(cnt-1)/2;
                    tmp++;
                }
            }
        }
        printf("%d\n",ans);
    }
}
///¿¨vector
#include<stdio.h>
#include<string.h>
#include<string.h>
#include<algorithm>
#define LL long long
using namespace std;
const int maxn=105;
char a[maxn][maxn];
struct node
{
    int x,y;
    node() {}
    node(int a,int b)
    {
        x=a;
        y=b;
    }
} pos[30][maxn*maxn];
int t,n,m,num[30];
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        memset(num,0,sizeof num);
        scanf("%d%d",&n,&m);
        for(int i=0; i<n; i++)
        {
            scanf("%s",a[i]);
            for(int j=0; j<m; j++)
                pos[a[i][j]-'a'][num[a[i][j]-'a']++]=node(i,j);
        }
        int ans=0;
        for(int i=0; i<26; i++)
        {
            for(int j=0; j<num[i]; j++)
            {
                int tmp=j+1;
                while(pos[i][j].x==pos[i][tmp].x)
                {
                    for(int k=pos[i][j].x+1; k<n; k++)
                        if(a[k][pos[i][j].y]-'a'==i&&a[k][pos[i][tmp].y]-'a'==i)ans++;
                    tmp++;
                }
            }
        }
        printf("%d\n",ans);
    }
}
