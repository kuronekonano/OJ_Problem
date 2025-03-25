#include <iostream>
#include <map> ///��Ϊ���ﲢ�鼯����ÿ�������֣����Ҫ����map�Ƚ�һ�����ֶ�Ӧ����һ�޶���������
#include <stdio.h> ///���ò��鼯���������ߴ�
#include <string.h>
#include <string>
using namespace std;
int team[3008]; /// ��ϵ���飬�洢ÿ�����ߵ��ϴ�
int find(int x) {
  int r = x, t;
  while (r != team[r]) {
    t = r;
    r = team[r];
    team[t] = team[r];
  }
  return r;
}
int join(int a, int b) {
  int na = find(a), nb = find(b);
  if (na != nb) {
    team[nb] = na;
  }
}
int main() {
  int i, j, n, num;
  while (scanf("%d", &n) != EOF) {
    for (i = 0; i <= 3 * n; i++) {
      team[i] = i;
    }
    num =
        1; /// �����ǵ�num�����֣����ܴ�0��ʼ��ÿ�����ֶ�Ӧһ�����֣������0��ʼ���ᷢ��������ǣ���1��������ַ�����Ӧ������0�ϣ����Ǻ���0�Ǳ���Ϊδ�������ֵı��
    map<string, int>
        m; /// ���ֵĺ�������ǣ���1�����ֱ���Ӧ��0������Ժ��ٳ��ֺ͵�һ������һ���ģ����ᱻ�ж�Ϊ��δ���ֹ��Ķ����¶�Ӧ�µ�����
    string name[3];
    for (i = 0; i < n; i++) {
      for (j = 0; j < 3; j++) {
        cin >> name[j];
        if (m[name[j]] ==
            0) /// ����map��<string,int>����Ӧ��int��ֵΪ0���������δ�ظ����ֵ������ֶ�Ӧ��int����0��������������ж������Ƿ��֮ǰ�����ظ�
        {
          m[name[j]] = num++;
        }
      }
      join(m[name[0]], m[name[1]]); /// ��ÿ�������ʣ���������һ���˽�Ϊһ����
      join(m[name[0]], m[name[2]]);
      //            for(int k=0; k<num; k++)
      //            {
      //                printf("%d====%d\n",k,team[k]);
      //            }
      //            printf("---------------------------\n");
    }
    int flag = 0;
    for (
        i = 1; i < num;
        i++) /// �������ӵ�һ����num-1(��Ϊ��num++�������һ��)�У��Լ����ϴ���Ǹ��˾���һ����
    {
      if (team[i] == i)
        flag++;
    }
    printf("%d\n", flag);
  }
}
