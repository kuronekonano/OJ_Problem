#include <algorithm>
#include <stdio.h> ///�����������
#include <string.h>
using namespace std;
int vis[1008][1009], i, j, t;
int main() {

  char x[1005];
  char y[1004];
  scanf("%d", &t);
  while (t--) {
    scanf(
        "%s %s", x + 1,
        y + 1); // Ϊ�����������ÿ��λ�õ�Ԫ�ؼ����������ַ������׵�ַλ��+1��ʼ
    int lx = strlen(x + 1);
    int ly = strlen(y + 1);
    for (i = 1; i <= lx; i++) {
      vis[i][0] =
          i; // �ڼ����ַ����Ǻ�0λ��ȣ������Σ����Դ����պ����ַ���λ�ñ��
    }
    for (i = 1; i <= ly; i++) {
      vis[0][i] = i;
    }
    vis[0][0] = 0; // ��ʼֵ����Ϊ0
    for (i = 1; i <= lx; i++) {
      for (
          int j = 1; j <= ly;
          j++) // ��̬�滮,һ��һ���ַ��Ƚϣ�����ͬ����̳�֮ǰ�Ĵ�������ͬ��������ֱ任��ɸѡ���Ž�
      {
        if (x[i] == y[j]) // һֱ�ۼӵ���������ձ仯���
        {
          vis[i][j] = vis[i - 1][j - 1]; // �̳�
        } else {
          vis[i][j] = vis[i - 1][j - 1] + 1; // �任
        }
        vis[i][j] = min(
            vis[i - 1][j] + 1,
            min(vis[i][j],
                vis[i][j - 1] +
                    1)); // ������������루���ӣ���ɾ�����任������ȡ���Ž⣨�ı�������ٵģ�
        //                vis[i][j]=min(vis[i][j-1]+1,vis[i][j]);
      }
    }
    printf("%d\n", vis[lx][ly]);
  }
  return 0;
}
