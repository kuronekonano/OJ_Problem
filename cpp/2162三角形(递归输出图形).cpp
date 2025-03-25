#include <math.h>
#include <stdio.h>
#include <string.h>
char a[5000][5000];
int digui(int n, int x, int y, int h, int w) {
  if (n == 2) {
    a[x][y] = a[x - 1][y - 1] = a[x][y - 2] = '*';
    return 0;
  }
  int nh = pow(2, n - 2) / 2,
      nw = (pow(2, n - 1) - 1) / 2; /// ��һ�����������꣬��������
  digui(n - 1, x, y, nh, nw);       /// ���½ǣ������������½�Ϊ��׼�㣬��֧��չ
  digui(n - 1, x, y - w - 1, nh, nw); /// ���½�
  digui(
      n - 1, x - h, y - w / 2 - 1, nh,
      nw); /// �Ϸ�///�����½�����
           /// һֻ����������Ͷ����һ��ͼ�δ�ӡ�ĺ����д���ֱ���ҵ�ÿһ��n=2ʱ������
} /*                      /  |  \                    */
int main() /*��ߴ�ͼ�� �м�  �ұߴ�ͼ��*/
{
  /*   / | \   /|\     / | \     */
  int n, x, y, stop, i, j;
  while (scanf("%d", &n) != EOF) {
    memset(a, ' ', sizeof(a));
    x = pow(2, n - 1);
    y = (pow(2, n)) - 1;
    int h = x / 2; /*Сͼ�εĸ߿�*/
    int w = y / 2;
    digui(n, x, y, h, w); /*��������*/

    for (i = 1; i <= x; i++) /*�������*/
    {
      for (j = 1; j <= pow(2, n) - 1; j++) // �������
      {
        if (a[i][j] == '*')
          stop = j; // ��ֹ����Ŀո����
      }
      for (j = 1; j <= stop; j++) // �ڿո���ִ�ֹͣ���
      {
        printf("%c", a[i][j]);
      }
      printf("\n");
    }
  }
  return 0;
}
// #include<stdio.h>
// #include<string.h>
// #include<math.h>
// #define N 5000
// char mp[N][N];
// void print(int n,int x,int y,int h,int w)
//{
/// ��ʹ�õ���ÿ�������ε����½���Ϊ��׼
/// ÿ����ͼ��������Сͼ����ɣ�h��w����Сͼ�εĸ߶ȺͿ��
//
//    if(n == 2)
//    {
//        printf("��׼(%d,%d)\n",x,y);
//        mp[x][y] = mp[x][y-2] = mp[x-1][y-1] = '*';//�����½�Ϊ��׼��
//        return;
//    }
//    int nh = pow(2,n-2)/2,nw =
//    (pow(2,n-1)-1)/2;//nh��ʾ��һ��ͼ�εĸ߶ȼ��㷽�������Ϊn-1-1��nwΪ��һ��Сͼ�εĿ�ȼ��㷽��
//    /������ͼ�εĸߺͿ�
//    print(n-1,x,y,nh,nw);///����
//    print(n-1,x,y-w-1,nh,nw);///���£������Ϊ�����и��ո�����-1�����ո�-w����һ��������λ��
//    print(n-1,x-h,y-w/2-1,nh,nw);///�ϣ��߶ȼ���һ��߶ȴﵽ�����Ǹ�����͵����������½�
//}
// int main()
//{
//    int n,stop=-1,j;
//    while(~scanf("%d",&n))
//    {
//        memset(mp,'0',sizeof(mp));//�������
//        int x = pow(2,n-1),y = pow(2,n)-1;//�����½ǵĵ�,X��Y����߶ȺͿ��
//        int h = x/2,w =
//        y/2;//h�����׼�����꣬Ҳ����1/2�ĸ߶ȣ�w�����׼�����꣬Ҳ����1/2���
//        print(n,x,y,h,w);//����print�����еݹ鴦��
//        for(int i = 1; i <= x; i++)
//        {
//            for(int j = 1; j <=pow(2,n)-1; j++)
//            ///������Ϊ�˿��Ʋ��������Ŀո�
//            {
//                if(mp[i][j]=='*')
//                    stop=j;
//            }
//            for(int j=1;j<=stop;j++)
//            {
//                printf("%c",mp[i][j]);
//            }
//            printf("\n");
//        }
//    }
//    return 0;
//}

#include <math.h>
#include <stdio.h> ///�ݹ�Ӧ�ã���ӡ������
#include <string.h>
char a[5000][5000];
int digui(int n, int x, int y, int h, int w) /// �ݹ麯��
{
  if (n == 2) {
    a[x][y] = a[x - 1][y - 1] = a[x][y - 2] = '*';
    return 0;
  }
  int nh = pow(2, n - 2) / 2,
      nw = (pow(2, n - 1) - 1) / 2; /// ��һ�����������꣬��������
  digui(n - 1, x, y, nh, nw);       /// ���½ǣ������������½�Ϊ��׼�㣬��֧��չ
  digui(n - 1, x, y - w - 1, nh, nw); /// ���½�
  digui(
      n - 1, x - h, y - w / 2 - 1, nh,
      nw); /// �Ϸ�///�����½�����
           /// һֻ����������Ͷ����һ��ͼ�δ�ӡ�ĺ����д���ֱ���ҵ�ÿһ��n=2ʱ������
} /*                      /  |  \                    */
int main() /*��ߴ�ͼ�� �м�  �ұߴ�ͼ��*/
{
  /*   / | \   /|\     / | \     */
  int n, x, y, stop, i, j;
  while (scanf("%d", &n) != EOF) {
    memset(a, ' ', sizeof(a));
    x = pow(2, n - 1);   /// �����������½ǵĵ�ĺ�����
    y = (pow(2, n)) - 1; /// ������
    int h = x / 2;       /// �߶�     /*Сͼ�εĸ߿�*/

    int w = y / 2; /// ���

    digui(n, x, y, h, w); /*��������*/

    for (i = 1; i <= x; i++) /*�������*/
    {
      for (j = 1; j <= pow(2, n) - 1; j++) // �������
      {
        if (a[i][j] == '*')
          stop = j; // ��ֹ����Ŀո����
      }
      for (j = 1; j <= stop; j++) // �ڿո���ִ�ֹͣ���
      {
        printf("%c", a[i][j]);
      }
      printf("\n");
    }
  }
  return 0;
}
