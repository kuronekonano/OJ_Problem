#include<stdio.h>
#include<vector>
#define pb push_back
using namespace std;
vector<int>v[32];
void init()
{
    v[1].pb(1);
    v[2].pb(1);
    v[2].pb(1);
    for(int i=3; i<=30; i++)
    {
        int cnt=1;
        for(int j=0; j<v[i-1].size(); j++)
            if(v[i-1][j]==v[i-1][j+1]) cnt++;
            else v[i].pb(cnt),v[i].pb(v[i-1][j]),cnt=1;
    }
}
int main()
{
    init();
    int n;
    while(scanf("%d",&n)&&n)
    {
        printf("%d\n",v[n].size());
//        for(int i=0; i<v[n].size(); i++)printf("%d",v[n][i]);
//        printf("\n");
    }
}
