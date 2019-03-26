#include<stdio.h>///kmp重复子串计数
#include<string.h>
char t[10008],s[100008];
int next[10008];
void kmp_pre(int len)
{
    int i,j;
    j=next[0]=-1;
    i=0;
    while(i<len)
    {
        while(-1!=j && t[i]!=t[j])j=next[j];
        ++i,++j;
        next[i]=t[i]==t[j]?next[j]:j;
    }
}
int kmpcount(int lent,int lens)
{
    int i,j;
    int ans=0;
    i=j=0;
    while(i<lens)
    {
        while(-1!=j&&s[i]!=t[j])j=next[j];
        i++;j++;
        if(j>=lent)
        {
            ans++;
            j=next[j];
        }
    }
    return ans;
}
int main()
{
    while(scanf("%s",t)!=EOF)
    {
        int lent=strlen(t);
        kmp_pre(lent);
        scanf("%s",s);
        int lens=strlen(s);
        printf("%d\n",kmpcount(lent,lens));
    }
}
