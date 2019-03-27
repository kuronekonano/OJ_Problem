#include<stdio.h>//数组模拟
#include<string.h>
int tot;//为每个不相同的字符标号
int trie[1000000][26];//有那么多层的树，每层有26个分支
bool isw[1000000];//用于标记是否是单词完结节点
struct str//第一个字符串和第二个字符串相匹配
{
    char str1[18];
    char str2[18];
} a[100005];
int insert(char *str,int rt)//建树
{
    for(int j=0; str[j]; j++)
    {
        int x=str[j]-'a';//第x个分支是这个字母，此层的分支就是x，从x再分出节点
        if(trie[rt][x]==0)
        {
            trie[rt][x]=++tot;//若是未标记的新字母，则重新标号
        }
        rt=trie[rt][x];//用rt记录这个新号数，然后从这个号数开始找下一个字母的位置
    }
    isw[rt]=true;//标记为结束
}
bool find(char *str,int rt)//查询字典
{
    for(int i=0; str[i]; i++)
    {
        int x=str[i]-'a';
        if(trie[rt][x]==0)//若被查询的字母不存在标记，则不是字典中的数
            return false;
        rt=trie[rt][x];//若找到了这个字母，记录其所在节点，一直重走一遍这个单词的每一个字母，直到完全相符，并返回结束标记节点
    }
    return isw[rt];
}

int main()
{
    tot=0;///根节点
    int floor=++tot;
    int i=0;
    memset(isw,false,sizeof(isw));
    memset(trie[floor],0,sizeof(trie[floor]));
    char tmp;
    while(tmp=getchar())//输入时用tmp承接一个字符，看看是否是\n
    {
        if(tmp=='\n')//若等于换行符，则打破输入字典循环，开始询问输入
            break;
        a[i].str1[0]=tmp;//若不为换行符，将第一个输入的字符放入字符串str1中
        scanf("%s %s",a[i].str1+1,a[i].str2);//并且从str1+1处继续输入，并输入str2
        getchar();//最后把回车确认的字符用getchar()带走
        insert(a[i].str2,floor);//建树
        i++;//输入下一个字符串
    }
    char s[15];
    while(scanf("%s",s)!=EOF)
    {
        if(find(s,floor))//查找树
        {
            for(int k=0; k<i; k++)
            {
                if(strcmp(s,a[k].str2)==0)
                {
                    printf("%s\n",a[k].str1);
                    break;
                }
            }
        }
        else
        {
            printf("eh\n");
        }
    }
    return 0;
}
