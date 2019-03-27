#include<bits/stdc++.h>
#define pb(x) push_back(x)
using namespace std;
const int maxn=1e3+7;
int a[maxn];
vector<int >q;
int main()
{
    int n,k;
    while(scanf("%d",&n)&&n)
    {
        q.clear();
        scanf("%d",&k);
        for(int i=0; i<n; i++)
        {
            scanf("%d",&a[i]);
            if(i!=0)
                if(abs(a[i]-a[i-1])>k)q.pb(i);
        }
        if(q.size()>2) printf("N\n");
        else
        {
            if(q.size()<=1)
            {
                bool flag=true;
                for(int i=1; i<n-1; i++)if(abs(a[i-1]-a[i+1])>2*k)
                    {
                        flag=false;
                        printf("N\n");
                        break;
                    }
                if(flag)printf("Y\n");
            }
            else
            {
                if(q.size()>2)printf("N\n");
                else
                {
                    if(q.size()==2)
                    {
                        if(q[0]+1==q[1]&&abs(a[q[0]-1]-a[q[1]])<=2*k)printf("Y\n");
                        else printf("N\n");
                    }
                }
            }
        }
    }
}
