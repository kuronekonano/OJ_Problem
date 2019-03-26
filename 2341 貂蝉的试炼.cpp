#include <stdio.h>
#include<string.h>
#include<map>
using namespace std;
char a[1000000];
int main()
{
    int n;
    map<char,int>m;
    m['I']=1;
    m['V']=5;
    m['X']=10;
    m['L']=50;
    m['C']=100;
    m['D']=500;
    m['M']=1000;
    while(~scanf("%s",a))
    {
        int len=strlen(a),ans=0;
        for(int i=0; i<len; i++)
            if(m[a[i]]<m[a[i+1]])ans-=m[a[i]];
            else ans+=m[a[i]];
        printf("%d\n",ans);
    }
}
