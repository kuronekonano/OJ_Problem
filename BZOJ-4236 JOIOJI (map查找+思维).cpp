#include<stdio.h>///��2e5�����ַ������ҵ�����JIO����ĸ��ͬ���������
#include<string.h>
#include<map>
#include<algorithm>
#define LL long long
using namespace std;
char a[200005];
int main()
{
    int n;
    map<LL,int>mp;
    while(scanf("%d",&n)!=EOF)
    {
        LL jj=0,ii=0,oo=0;///��¼ÿ����ĸ���ִ���
        scanf("%s",a+1);///ע����ΪҪ���ַ���λ�����������룬����ַ�����1��ʼ���룬��Ҫ�����ַ����ĵ�iλʱ����i��ȥ0���Ͳ�����Ϊλ����1���ټ������
        int ans=0;
        mp.clear();
        mp[0]=0;
        for(int i=1;i<=n;i++)///���ڵ�iλ�ĳ��ִ�����������J-O��������J-I������Ӧ���jλ��ȵĹ�ϵ
        {
            jj=a[i]=='J'?jj+1:jj;
            ii=a[i]=='I'?ii+1:ii;
            oo=a[i]=='O'?oo+1:oo;
            LL tmp=100000*(jj-ii)+(jj-oo);///��ϣ��¼�ò�ֵ
            if(mp.find(tmp)!=mp.end()) ans=max(ans,i-mp[tmp]);///������ֹ��ù�ϣֵ(��ֵ)���õ�ǰλ-��ͬ��ֵλ���Ƚϳ��������Ϊans
            else mp[tmp]=i;///��û�г��ֹ��ò�ֵ����¼��ʱ���ָò�ֵ��λ��
        }
        printf("%d\n",ans);
    }
}

