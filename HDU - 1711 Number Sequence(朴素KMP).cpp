#include<stdio.h>///裸KMP模板
void kmp_pre(int x[],int m,int next[])
{
    int i,j;
    j=next[0]=-1;
    i=0;
    while(i<m)
    {
        while(j!=-1&&x[i]!=x[j])j=next[j];
        next[++i]=++j;
    }
}
int kmp_count(int x[],int m,int y[],int n)
{
    int i=0,j=0,next[10005];
    kmp_pre(x,m,next);
    while(i<n)
    {
        while(j!=-1&&x[j]!=y[i])j=next[j];
        i++;j++;
        if(j>=m)return i+1-m;///注意这里要减去模式串的长度
    }
    return -1;///如果没有在主串中找到子串，最后输出-1表示找不到
}
int a[1000006],b[10004],n,m,t;
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&m);
        for(int i=0;i<n;i++)scanf("%d",&a[i]);
        for(int i=0;i<m;i++)scanf("%d",&b[i]);
        printf("%d\n",kmp_count(b,m,a,n));///直接输出第一次查找到完整字符串的位置
    }
}
