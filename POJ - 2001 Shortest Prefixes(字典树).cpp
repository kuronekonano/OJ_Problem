#include<stdio.h>
#include<string.h>
int tot,tre[6000][26],vis[6000];///�ֵ�������㣬��Ȼ�ܷ���WA����֪��ȥ�Ķ��Ҵ�
char word[1002][23];
bool flag[6008];
int insert(char str[],int rt)
{
    int len=strlen(str);
    for(int i=0; i<len; i++)
    {
        int x=str[i]-'a';
        if(tre[rt][x]==0)
        {
            tre[rt][x]=++tot;
            memset(tre[tre[rt][x]],0,sizeof(tre[tre[rt][x]]));
        }
        rt=tre[rt][x];
        vis[rt]++;
    }
    flag[rt]=true;
}
void finds(char str[],int rt)
{
    int len=strlen(str);
    for(int i=0; i<len; i++)
    {
        int x=str[i]-'a';
        rt=tre[rt][x];
        printf("%c",str[i]);
        if(vis[rt]==1)
        {
            printf("\n");
            return;
        }
        if(flag[rt]&&i==len-1)
        {
            printf("\n");
            return;
        }
        if(vis[tre[rt][str[i+1]-'a']]==1)
        {
            printf("%c\n",str[i+1]);
            return;
        }
    }
}
int main()
{
    int num=0;
    tot=0;
    int rt=++tot;
    memset(flag,false,sizeof(flag));
    memset(tre[rt],0,sizeof(tre[rt]));
    memset(vis,0,sizeof(vis));
    while(scanf("%s",word[++num])!=EOF) insert(word[num],rt);
    for(int i=1; i<=num; i++)
    {
        printf("%s ",word[i]);
        finds(word[i],rt);
    }
}
