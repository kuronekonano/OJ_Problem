#include <stdio.h> ///ģ�⣬������������λ�ã����������������
#include <string.h>
int main() {
  char W[10], B[10], ma[40][40];
  while (scanf("%s", W) != EOF) /// ��ʵ����Ч������
  {
    for (int i = 0; i < 17; i++) /// Ԥ�������������̣��Ȼ����߽�
      for (int j = 0; j < 33; j++)
        if (i % 2 == 0 && j % 4 == 0)
          ma[i][j] = '+';
        else if (i % 2 == 0 && j % 4 != 0)
          ma[i][j] = '-';
        else if (i % 2 != 0 && j % 4 == 0)
          ma[i][j] = '|';
    for (int i = 1; i < 17; i += 2) /// �ٻ��������Ϻڰ���ɫ����
      for (int j = 2; j < 33; j += 4)
        if ((9 - (i + 1) / 2) % 2 != 0)
          ma[i][j + 1] = ma[i][j - 1] = ma[i][j] =
              ((j / 2 + 1) / 2) % 2 == 0 ? '.' : ':';
        else
          ma[i][j + 1] = ma[i][j - 1] = ma[i][j] =
              ((j / 2 + 1) / 2) % 2 == 0 ? ':' : '.';
    char tmp[100];
    scanf("%s", tmp); /// ��������λ��
    int len = strlen(tmp);
    char who = 0; /// ���ӵĽ�ɫ
    for (int i = 0; i < len; i++) {
      int tmx, tmy; /// �洢��������λ��
      if (tmp[i] == ',')
        continue;
      if (tmp[i] >= 'A' && tmp[i] <= 'Z')
        who = tmp[i];
      else if (tmp[i] >= 'a' && tmp[i] <= 'z')
        tmy = (tmp[i] - 'a' + 1) * 4 - 2;
      else
        tmx = (9 - (tmp[i] - '0')) * 2 - 1;
      if (tmp[i + 1] == ',' || i == len - 1) /// �����ж����һ������
      {
        if (who == 0)
          ma[tmx][tmy] = 'P'; /// ���û�н�ɫ�趨��˵����ʿ��
        else
          ma[tmx][tmy] = who;
        who = 0;
      }
    }
    scanf("%s", B); /// Ҳ�����õ�����
    scanf("%s", tmp);
    len = strlen(tmp);
    who = 0;
    for (int i = 0; i < len; i++) {
      int tmx, tmy;
      if (tmp[i] == ',')
        continue;
      if (tmp[i] >= 'A' && tmp[i] <= 'Z')
        who = tmp[i] + 'a' - 'A';
      else if (tmp[i] >= 'a' && tmp[i] <= 'z')
        tmy = (tmp[i] - 'a' + 1) * 4 - 2;
      else
        tmx = (9 - (tmp[i] - '0')) * 2 - 1;
      if (tmp[i + 1] == ',' || i == len - 1) {
        if (who == 0)
          ma[tmx][tmy] = 'p';
        else
          ma[tmx][tmy] = who;
        who = 0;
      }
    }
    for (int i = 0; i < 17; i++) {
      for (int j = 0; j < 33; j++)
        printf("%c", ma[i][j]);
      printf("\n");
    }
  }
}
