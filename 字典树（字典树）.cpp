#include<stdio.h>//����ģ��
#include<string.h>
int tot;//Ϊÿ������ͬ���ַ����
int trie[1000000][26];//����ô��������ÿ����26����֧
bool isw[1000000];//���ڱ���Ƿ��ǵ������ڵ�
struct str//��һ���ַ����͵ڶ����ַ�����ƥ��
{
    char str1[18];
    char str2[18];
} a[100005];
int insert(char *str,int rt)//����
{
    for(int j=0; str[j]; j++)
    {
        int x=str[j]-'a';//��x����֧�������ĸ���˲�ķ�֧����x����x�ٷֳ��ڵ�
        if(trie[rt][x]==0)
        {
            trie[rt][x]=++tot;//����δ��ǵ�����ĸ�������±��
        }
        rt=trie[rt][x];//��rt��¼����º�����Ȼ������������ʼ����һ����ĸ��λ��
    }
    isw[rt]=true;//���Ϊ����
}
bool find(char *str,int rt)//��ѯ�ֵ�
{
    for(int i=0; str[i]; i++)
    {
        int x=str[i]-'a';
        if(trie[rt][x]==0)//������ѯ����ĸ�����ڱ�ǣ������ֵ��е���
            return false;
        rt=trie[rt][x];//���ҵ��������ĸ����¼�����ڽڵ㣬һֱ����һ��������ʵ�ÿһ����ĸ��ֱ����ȫ����������ؽ�����ǽڵ�
    }
    return isw[rt];
}

int main()
{
    tot=0;///���ڵ�
    int floor=++tot;
    int i=0;
    memset(isw,false,sizeof(isw));
    memset(trie[floor],0,sizeof(trie[floor]));
    char tmp;
    while(tmp=getchar())//����ʱ��tmp�н�һ���ַ��������Ƿ���\n
    {
        if(tmp=='\n')//�����ڻ��з�������������ֵ�ѭ������ʼѯ������
            break;
        a[i].str1[0]=tmp;//����Ϊ���з�������һ��������ַ������ַ���str1��
        scanf("%s %s",a[i].str1+1,a[i].str2);//���Ҵ�str1+1���������룬������str2
        getchar();//���ѻس�ȷ�ϵ��ַ���getchar()����
        insert(a[i].str2,floor);//����
        i++;//������һ���ַ���
    }
    char s[15];
    while(scanf("%s",s)!=EOF)
    {
        if(find(s,floor))//������
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
