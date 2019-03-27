#include<bits/stdc++.h>
using namespace std;
int t,n,m;
int main()
{
//    freopen("d.txt","r",stdin);
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&m);
//        printf("=======================%d  %d\n",n,m);
        if(n==1||m==1)
        {
            if(n==1)
                for(int i=0; i<n; i++)
                {
                    for(int j=0; j<m; j++)
                        printf("%c",j&1?')':'(');
                    printf("\n");
                }
            else for(int i=0; i<n; i++)
                {
                    for(int j=0; j<m; j++)
                        printf("%c",i&1?')':'(');
                    printf("\n");
                }
            continue;
        }
        if(n<=2)
            for(int i=0; i<n; i++)
            {
                if(i&1)for(int j=0; j<m; j++)printf(")");
                else for(int j=0; j<m; j++)printf("(");
                printf("\n");
            }
        else if(n<6||m<6)
        {
            if(n&1)
            {
                for(int i=0; i<n; i++)
                {
                    for(int j=0; j<m; j++)printf("%c",j&1?')':'(');
                    printf("\n");
                }
            }
            else if(m&1)
            {
                for(int i=0; i<n; i++)
                {
                    if(i>=n/2)for(int j=0; j<m; j++)printf(")");
                    else for(int j=0; j<m; j++)printf("(");
                    printf("\n");
                }
            }
            else if(m<6)
            {
                for(int i=0; i<n; i++)
                {
                    if(i<n/2) for(int j=0; j<m; j++)printf("%c",j&1?')':'(');
                    else for(int j=0;j<m;j++)printf("%c",j>=m/2?')':'(');
                    printf("\n");
                }
            }
            else
            {
                for(int i=0; i<n; i++)
                {
                    if(i==0) for(int j=0; j<m; j++) printf("(");
                    else if(i==n-1) for(int j=0; j<m; j++) printf(")");
                    else
                    {
                        if(i&1)for(int j=0; j<m; j++)printf("%c",j>=m/2?'(':')');
                        else for(int j=0; j<m; j++)printf("%c",j>=m/2?')':'(');
                    }
                    printf("\n");
                }
            }
        }
        else
        {
            if(n&1||m&1)
            {
                if(n&1)
                {
                    for(int i=0; i<n; i++)
                    {
                        for(int j=0; j<m; j++)printf("%c",j>=m/2?')':'(');
                        printf("\n");
                    }
                }
                else
                {
                    for(int i=0; i<n; i++)
                    {
                        for(int j=0; j<m; j++)printf("%c",i>=n/2?')':'(');
                        printf("\n");
                    }
                }
            }
            else
            {
                for(int i=0; i<n; i++)
                {
                    if(i==0) for(int j=0; j<m; j++)printf("(");
                    else if(i==n-1) for(int j=0; j<m; j++)printf(")");
                    else
                    {
                        if(i&1)for(int j=0; j<m; j++)printf("%c",j&1?')':'(');
                        else for(int j=0; j<m; j++)
                                if(j==0)printf("(");
                                else if(j==m-1)printf(")");
                                else printf("%c",j&1?'(':')');
                    }
                    printf("\n");
                }
            }
        }
    }
}
