// #include <stdio.h>///�����˷�
// #include<string.h>
// int main()
//{
//     char a[1005];///�ַ���a
//     char b[1005];///�ַ���b
//     int na[1005];///a����
//     int nb[1005];///b����
//     int nc[1005];///���
//     while(~scanf("%s%s",a,b))
//     {
//         if(a[0]=='0'||b[0]=='0')///����������һΪ0��ĵ����϶�Ϊ0��������Ϊ��0λ�����λ��������λΪ0��϶�Ϊ0
//         {
//             printf("0\n");
//             continue;
//         }
//         memset(na,0,sizeof(na));///����������ִ洢����
//         memset(nb,0,sizeof(nb));
//         memset(nc,0,sizeof(nc));
//         int
//         la=strlen(a);///ͳ�Ƴ��ȣ����У����λ�������0λ�ã���λ��la-1��λ��
//         int lb=strlen(b);
//         int
//         cnt=0;///ע�������Ϊ�ַ������Ǵ����һλ��ʼ����ģ������������Ǵ�0λ��ʼ��ģ����Ը�ֵ��ȥʱ�����������ļ���������ֿ�
//         for(int i=la-1; i>=0; i--)///�Ӹ�λ��ʼ����0λ����������������
//             na[cnt++]=a[i]-'0';
//         int snt=0;
//         for(int i=lb-1; i>=0; i--)
//             nb[snt++]=b[i]-'0';
//         for(int i=0; i<cnt; i++)///���㲿��
//         {
//             for(int j=0; j<snt; j++)
//             {
//                 nc[i+j]+=na[i]*nb[j];///��ѭ��Ƕ��ʵ�������ַ���ÿһλ�Ķ�Ӧ���
//             }///���λ������������λ��֮��
//         }///��˲���Ӵ浽ÿλ���������δ��λ��
//         for(int i=0; i<(cnt+snt); i++)///��λѭ��
//         {
//             if(nc[i]>=10)///����10��λ
//             {
//                 int tmp=nc[i]/10;///tmp��ʱ�洢��λ��
//                 nc[i]=nc[i]%10;///nc�������ÿλ�洢��λС��10��ģ
//                 nc[i+1]+=tmp;///��һλ��tmp
//             }
//         }///���㲿�ֽ���
//         ///�������
//         for(int i=1004; nc[i]==0;
//         i--)///���Ŵ��������һλ�ң�ѭ��������ֻҪ��һλ�ǿյģ�Ϊ0���ͼ�����ȥ
//         {///���ҵ�iλ����һλ��Ϊ�㣡��˵������һλ��ʼ����⴮����
//             if(nc[i-1]!=0)///�����λ�����Ҳ����nc�������Ĵ洢�������Ǹ�λ��
//             {
//                 for(int j=i-1; j>=0;
//                 j--)///��ѭ�������������һλһֱ�����0λ����λ��
//                     printf("%d",nc[j]);///ÿλ���
//                 break;///��ʱ������ˣ���Ϊ��������ѭ���õ���j������λ��������i����������Ѱ�Ҵ���һλ��ʼ����ĵ�һ��ѭ��
//             }
//         }
//         printf("\n");
//     }///��������˷����Ŷ�����
// }
#include <stdio.h>
#include <string.h>
int main() {
  char a[1004];
  char b[1004];
  int numa[1004];
  int numb[1004];
  int numc[1004];
  int i, j;
  while (scanf("%s %s", a, b) != EOF) {
    if (a[0] == '0' || b[0] == '0') {
      printf("0\n");
      continue;
    }
    memset(numa, 0, sizeof(numa));
    memset(numb, 0, sizeof(numb));
    memset(numc, 0, sizeof(numc));
    int na = strlen(a);
    int nb = strlen(b);
    int ant = 0;
    for (i = na - 1; i >= 0; i--) {
      numa[ant++] = a[i] - '0';
    }
    int bnt = 0;
    for (i = nb - 1; i >= 0; i--) {
      numb[bnt++] = b[i] - '0';
    }
    for (i = 0; i < ant; i++) {
      for (j = 0; j < bnt; j++) {
        numc[i + j] = numc[i + j] + numa[i] * numb[j];
      }
    }
    for (i = 0; i < (ant + bnt); i++) {
      if (numc[i] >= 10) {
        int tmp = numc[i] / 10;
        numc[i] = numc[i] % 10;
        numc[i + 1] = numc[i + 1] + tmp;
      }
    }
    for (i = 1003; numc[i] == 0; i--) {
      if (numc[i - 1] != 0) {
        for (j = i - 1; j >= 0; j--) {
          printf("%d", numc[j]);
        }
        break;
      }
    }
    printf("\n");
  }
  return 0;
}
