#include<bits/stdc++.h>///字符串处理，判断在任意k长的子串中都包含字母c，求这个k最小值
using namespace std;
int main()
{
    int n,num[30],flag[30],one[30],last[30];///记录两两相同字母之间的距离，取最大距离，然后在所有字母中取最小距离，记得在此之前还要考虑这个字母第一次出现和最后一次出现的距离，取最小
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
        if(ans==0x7fffffff)///如果么有距离出现两次，那么直接去字符串中间那个字母，长度取字符串长度一半
            ans=(len+1)/2;
        printf("%d\n",ans);
    }
}
