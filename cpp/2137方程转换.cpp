#include <stdio.h>
int main() {
  int t;
  char b[10] = {'m', 'n', 'p', 'i', 'j', 'k'};
  scanf("%d", &t);
  while (t--) {
    long a[10];
    for (int i = 0; i < 7; i++) {
      scanf("%ld", &a[i]);
    }
    bool flag = false;
    for (int i = 0; i <= 6; i++) {
      if (flag && a[i] > 0)
        printf("+"); /// ע�����Ҫ�������������Ƿ��žͲ��������
      if (a[i] != 0 && i != 6) {
        if (a[i] == 1) /// �ӵ�:ע��ϵ��Ϊ1ʱû������ֻ����ĸ
        {
          printf("%c", b[i]);
        } else if (a[i] == -1)
          printf("-%c", b[i]); /// ͬʱҪע�⸺��Ҳ�����
        else
          printf("%ld%c", a[i],
                 b[i]); /// �������1��ϵ�����Ǿ����ֺ���ĸһ�����
        flag = true;    /// �������Ǳ����û�в�Ϊ0������
      }
      if (a[i] != 0 && i == 6) /// ���һ����������������ж�
      {
        printf("%ld", a[i]);
        flag = true;
      }
    }
    if (!flag)
      printf("0");
    printf("\n");
  }
  return 0;
}

// #include<cstdio>
// char c[9]= {'m','n','p','i','j','k'};
// int main()
//{
//     int k=0,p,a[9],q=0;
//     scanf("%*d");
//     while(~scanf("%d",&a[p=k++%7]))
//     {
//         if((a[p]==1||a[p]==-1)&&p<6)printf(a[p]>0?q?"+%c":"%c":"-%c",c[p]);
//         else printf(a[p]?q?p>5?"%+d":"%+d%c":p>5?"%d":"%d%c":"",a[p],c[p]);
//         if(a[p])q=1;
//         if(p>5)printf(a[0]||a[1]||a[2]||a[3]||a[4]||a[5]||a[6]?"\n":"0\n"),q=0;
//     }
// }
