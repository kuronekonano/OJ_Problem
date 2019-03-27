#include <cstdio>
#include <cstring>
using namespace std;
int tot;
int trie[500000][26];
int num[500000];///��¼�ڵ㱻���ʴ���
int insert(char *str,int rt)//����
{
    for(int j=0; str[j]; j++)
    {
        int x=str[j]-'a';//��x����֧�������ĸ���˲�ķ�֧����x����x�ٷֳ��ڵ�
        if(trie[rt][x]==0)
        {
            trie[rt][x]=++tot;//����δ��ǵ�����ĸ�������±��
        }
        num[trie[rt][x]]++;
        rt=trie[rt][x];
    }
}
int find(char *str,int rt)//��ѯ�ֵ�
{
    int x,len=strlen(str);
    for(int i=0; i<len; i++)
    {
        x=str[i]-'a';
        if(trie[rt][x]==0)
            return 0;
        if(i!=len-1)rt=trie[rt][x];
    }
    return num[trie[rt][x]];
}

char str[100];
int main()
{
    tot=0;///���ڵ�
    int floor=++tot;
    memset(trie[floor],0,sizeof(trie[floor]));
    memset(num,0,sizeof(num));
    while(gets(str))
    {
        if(str[0]==NULL)
            break;
        insert(str,floor);
    }
    char s[15];
    while(scanf("%s",s)!=EOF)
        printf("%d\n",find(s,floor));
    return 0;
}
