#include<stdio.h>
#include<string.h>
char a[200005];///����������
char b[2005];///�����߻������
int next[2008];
int lena,lenb;
void getnext()///Ԥ����
{
    memset(next,0,sizeof(next));///����next���飬��ʼȫ��Ϊ0
    int i=0,j=next[0]=-1;///ģʽ���Լ����Լ��Ƚ�
    while(i<lenb)///i��һֱ����ģ�����Ҳ������for����ʵ�൱�ڱ���һ��ģʽ��
    {///���jΪ0����ɹ�ƥ�����ַ�
        while(j!=-1&&b[i]!=b[j])j=next[j];
        ++i,++j;///ƥ����һλ
        next[i]= b[i]==b[j]?next[j]:j;///ͬʱ��next�������һλ��ֵj��λ��
    }
}
bool kmp()///������ģʽ����ƥ��
{
      int i=0,j=0;
      while(i<lena)
      {
          if(j==-1||a[i]==b[j]) i++,j++;
          else j=next[j];
          if(j==lenb) return true;
      }
      return false;
}
int main()
{

    while(scanf("%s%s",a,b)!=EOF)
    {
        lena=strlen(a);
        lenb=strlen(b);
        getnext();///ģʽ��Ԥ����
//        for(int i=0; i<=lenb; i++)
//        {
//            printf("%d->%d\n",i,next[i]);///next����
//        }
        printf("%s\n",kmp()?"yes":"no");
    }
    return 0;
}
//#include<stdio.h>
//#include<string.h>
//char a[200005];///����������
//char b[2005];///�����߻������
//int next[2008];
//int lena,lenb;
//void getnext()///Ԥ����
//{
//    memset(next,0,sizeof(next));///����next���飬��ʼȫ��Ϊ0
//    for(int i=1; i<lenb; i++)///����һ��ģʽ������ʱ����next�����൱���Լ����Լ�ƥ��
//    {///i��һֱ�����ģ�j�Ǽ����nextֵ
//        int j=next[i];///ÿ�ν���λ(i)��nextֵ����j�����j��Ϊ0����ô���Լ�������j�ĳ��ȣ����jΪ0��˵����һλiû��ʲô�ǰ��׺�����ô�Ŀǰ�����ĵ�iλ��ʼ�����ǰ��׺
//        while(j&&b[i]!=b[j])///���j��Ϊ0��˵���ǰ��׺������һ�����ȣ����ǵ�j+1λ
//        {
//            j=next[j];
//        }
//        next[i+1]=(b[i]==b[j])?(j+1):0;///�����i��jλ�ַ�ƥ�䣬��ô��i+1��λ�þ�����֮ǰ�������ǰ׺�������ƥ�䣬ǰ׺��׺���Ⱦ�Ϊ0
//    }///��ʱ��һ�����ƵĹ���
//}
//bool kmp()///������ģʽ����ƥ��
//{
//    int j=0;///ģʽ���ڲ�ͣ�ƶ�����next����Ϊ��׼�����˵��ƶ�
//    for(int i=0; i<lena; i++)///����������iֵ��һֱ������
//    {
//        while(j&&a[i]!=b[j])///j!=0(ģʽ��ƥ�䵽ǰ��׺��ĳ��λ����)�����������ַ�ƥ��ʧ��ʱ
//        {
//            j=next[j];///��ģʽ����next������ƣ��ƶ�����next[j]λ(��Ϊ�ǵ�jλ��ƥ��ģ�����Ӧ�ô���һ����j��ͬ��ǰ׺���ٱȽ�)
//        }
//        if(a[i]==b[j])///���ƥ���ˣ�j��iͬʱ���ƱȽ���һλ
//        {
//            j++;
//        }
//        if(j>=lenb)///ģʽ��ƥ����ɣ�ȷ����������ģʽ�����Է���
//           return true;
//    }
//    return false;///���������������������ģʽ��ָ��j��δ�ﵽģʽ���ĳ��ȣ�˵����ƥ�䣬���� ƥ��ʧ��
//}
//int main()
//{
//
//    while(scanf("%s%s",a,b)!=EOF)
//    {
//        lena=strlen(a);
//        lenb=strlen(b);
//        getnext();///ģʽ��Ԥ����
////        for(int i=0; i<=lenb; i++)
////        {
////            printf("%d->%d\n",i,next[i]);///next����
////        }
//        printf("%s\n",kmp()?"yes":"no");
//    }
//    return 0;
//}
