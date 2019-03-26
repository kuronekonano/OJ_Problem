#include<stdio.h>
#include<string.h>
int main()
{
    int i,j,n;
    char a[1008],b[1008];
    char vis[28];
    bool flag[28];
    while(scanf("%s %s",a,b)!=EOF)
    {
        if(strcmp(a,b)==0)
        {
            printf("0\n");
            continue;
        }
        memset(flag,false,sizeof(flag));
        n=strlen(a);
        int sum=0;
        bool mis=false;
        for(i=0; i<n; i++)
        {
            if(!flag[a[i]-'a']&&!flag[b[i]-'a'])
            {
                if(a[i]!=b[i])
                {
                    sum++;
                }
                vis[a[i]-'a']=b[i];
                vis[b[i]-'a']=a[i];
                flag[b[i]-'a']=flag[a[i]-'a']=true;
            }
            else if(flag[a[i]-'a']!=flag[b[i]-'a']||(flag[a[i]-'a']&&flag[b[i]-'a']&&vis[a[i]-'a']!=b[i]))
            {
                mis=true;
                break;
            }
        }
        if(mis)
        {
            printf("-1\n");
        }
        else
        {
            printf("%d\n",sum);
            for(i=0;i<26;i++)
            {
                if(flag[i]&&(i+'a')!=vis[i])
                {
                    printf("%c %c\n",i+'a',vis[i]);
                    flag[i]=false;
                    flag[vis[i]-'a']=false;
                }
            }
        }
    }
}
