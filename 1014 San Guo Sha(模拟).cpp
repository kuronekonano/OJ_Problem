#include <stdio.h>
#include <string.h>
struct man {
  int num;
  char name[3];
  bool life;
} a[108];
int main() {
  int t, n, m;
  scanf("%d", &t);
  while (t--) {
    int fz = 0, zc = 0, nj = 0,
        njj = -1; /// ��Ϊ������ɫ��0��ʼ����˲����ڵ�λ��Ӧ�ñ���Ϊ-1������0
    bool zgg = false, fzz = false;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++) {
      scanf("%s", a[i].name);
      a[i].num = 0;
      a[i].life = true;
      if (a[i].name[1] == 'Z')
        fz++;
      if (a[i].name[1] == 'C')
        zc++;
      if (a[i].name[1] == 'J')
        nj++;
    }
    int x[109], y[109];
    for (int q = 1; q <= m; q++) {
      scanf("%d%d", &x[q], &y[q]);
    }
    for (int q = 1; q <= m; q++) {
      if (a[y[q]].name[1] == 'G') /// ������ɱ
      {
        a[y[q]].life = false;
        if (a[x[q]].name[1] == 'Z') /// ����ɱ�������ض�����Ӯ
        {
          a[x[q]].num += 2;
          fzz = true;
        }
        if (a[x[q]].name[1] == 'J') {
          if (nj == 1 && fz == 0 &&
              zc ==
                  0) /// �ڼ�ֻ��ͨ����������������Ӯ����˽����ǵ�ʣ��1���ڼ��1������ʱ���ж��ڼ�ɱ����ʱ�ڼ�Ӯ�������Ƿ���Ӯ
          {
            a[x[q]].num += 4 + n * 2;
            njj = x[q]; /// ��¼����ɱ������������λ�ڼ飬���ʱֻ������ڼ�÷�
          } else {
            fzz = true;
          }
        } /// �ҳ�����ɱ����
        break;
      }
      if (a[y[q]].name[1] == 'C') /// �ҳ���ɱ
      {
        zc--;
        a[y[q]].life = false;
        if (a[x[q]].name[1] == 'Z') /// ֻ�б�����ɱ���ж���ӷ�
        {
          a[x[q]].num++;
        }
      }
      if (a[y[q]].name[1] == 'J') /// �ڼ鱻ɱ
      {
        if (a[x[q]].name[1] == 'G') /// �ڼ鱻����ɱʱ�ж��Ƿ��ǵ������
        {
          if (nj == 1 && zc == 0 && fz == 0) {
            a[y[q]].num =
                n; /// �����������ô��¼����������ڼ飬������������Ϊn
            njj = y[q];
          }
        }
        nj--;
        a[y[q]].life = false;
        if (a[x[q]].name[1] != 'J')
          a[x[q]].num++; /// �ڼ���ܱ��ڼ�ɱ��ֻ�в����ڼ�ɱʱ���ж���ӷ�
        if (nj == 0 && fz == 0) {
          zgg = true;
          break;
        }
      }
      if (a[y[q]].name[1] == 'Z') /// ������ɱ
      {
        fz--;
        a[y[q]].life = false;
        if (a[x[q]].name[1] != 'J' &&
            a[x[q]].name[1] !=
                'Z') /// �����ᱻ����ɱ����˷���ֻ���ҳ�������ɱʱ�ӷ�
        {
          a[x[q]].num++;
        }
        if (nj == 0 && fz == 0) {
          zgg = true;
          break;
        }
      }
    }
    if (zgg) /// ����Ӯ
    {
      for (int i = 0; i < n; i++) {
        if (a[i].name[1] == 'G') {
          printf("%d%c", a[i].num + 4 + zc * 2, i == n - 1 ? '\n' : ' ');
        }
        if (a[i].name[1] == 'C') {
          printf("%d%c", a[i].num + 5 + zc, i == n - 1 ? '\n' : ' ');
        }
        if (a[i].name[1] == 'Z') {
          printf("0%c", i == n - 1 ? '\n' : ' ');
        }
        if (a[i].name[1] == 'J') {
          printf("%d%c", i == njj ? a[i].num : 0,
                 i == n - 1 ? '\n'
                            : ' '); /// ����Ӯʱ���������ڼ��з֣�����Ϊ0��
        }
      }
    } else if (njj != -1 && !zgg) /// �ڼ�Ӯ
    {
      for (int i = 0; i < n; i++) {
        if (a[i].name[1] == 'G') {
          printf("%d%c", 1, i == n - 1 ? '\n' : ' ');
        }
        if (a[i].name[1] == 'C') {
          printf("0%c", i == n - 1 ? '\n' : ' ');
        }
        if (a[i].name[1] == 'Z') {
          printf("0%c", i == n - 1 ? '\n' : ' ');
        }
        if (a[i].name[1] == 'J') {
          printf("%d%c", i == njj ? a[i].num : 0,
                 i == n - 1 ? '\n'
                            : ' '); /// �ڼ�Ӯʱ��ֻ�е������ڼ��з֣�����0��
        }
      }
    } else if (fzz) /// ����Ӯ
    {
      for (int i = 0; i < n; i++) {
        if (a[i].name[1] == 'G') {
          printf("0%c", i == n - 1 ? '\n' : ' ');
        }
        if (a[i].name[1] == 'C') {
          printf("0%c", i == n - 1 ? '\n' : ' ');
        }
        if (a[i].name[1] == 'Z') {
          a[i].num += fz * 3;
          printf("%d%c", a[i].num,
                 i == n - 1 ? '\n'
                            : ' '); /// �������з֣��ڶ���ӷֵĻ����ϼӻ����÷�
        }
        if (a[i].name[1] == 'J') {
          printf("%d%c", a[i].life ? 1 : 0,
                 i == n - 1 ? '\n' : ' '); /// ֻ�л��ŵ��ڼ���1�֣�����Ϊ0��
        }
      }
    }
  }
}
/*
1��������������ʱ���ڼ���Ψһ���Ľ�ɫ�����ҽ���һ���ڼ�������ڼ��ʤ������֮������Ϊ������ʤ�����۷�����ɫ�����
2�����еķ������ڼ鶼���������������ҳ��������������ʤ��
*/
