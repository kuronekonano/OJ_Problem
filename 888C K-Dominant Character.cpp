#include<bits/stdc++.h>///�ַ��������ж�������k�����Ӵ��ж�������ĸc�������k��Сֵ
using namespace std;
int main()
{
    int n,num[30],flag[30],one[30],last[30];///��¼������ͬ��ĸ֮��ľ��룬ȡ�����룬Ȼ����������ĸ��ȡ��С���룬�ǵ��ڴ�֮ǰ��Ҫ���������ĸ��һ�γ��ֺ����һ�γ��ֵľ��룬ȡ��С
    char a[100005];
    while(scanf("%s",a)!=EOF)
    {
        memset(one,0,sizeof(one));
        memset(num,-1,sizeof(num));
        memset(flag,0,sizeof(flag));
        memset(last,-1,sizeof(last));
        int len=strlen(a);
        for(int i=0; i<len; i++)
        {
            if(num[a[i]-'a']==-1)
            {
                num[a[i]-'a']=i;
                one[a[i]-'a']=i+1;
            }
            else
            {
                if(i-num[a[i]-'a']>flag[a[i]-'a'])flag[a[i]-'a']=i-num[a[i]-'a'];
                num[a[i]-'a']=i;
            }
        }
        for(int i=len-1; i>=0; i--)
            if(last[a[i]-'a']==-1)
                last[a[i]-'a']=len-i;
        for(int i=0; i<26; i++)
        {
            if(one[i]>flag[i])flag[i]=one[i];
            if(last[i]>flag[i])flag[i]=last[i];
        }
        int ans=0x7fffffff;
        for(int i=0; i<26; i++)
            if(flag[i]!=0&&flag[i]<ans)
                ans=flag[i];
        if(ans==0x7fffffff)///���ô�о���������Σ���ôֱ��ȥ�ַ����м��Ǹ���ĸ������ȡ�ַ�������һ��
            ans=(len+1)/2;
        printf("%d\n",ans);
    }
}
