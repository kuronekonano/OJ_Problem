#include <stdio.h> ///�ֵ�������ͬʱ����
#include <string.h>
int tot, tre[100040][12]; /// ����ֻ��0-9��˱�26����ĸ��Ҫ��
bool vis[100050], ans;
int insert(
    char str[],
    int rt) { /// ҪԤ������ǰ׺�ظ��������һ���Ƕ̵��ȳ��֣�һ���ǳ����ȳ��֣���911��911245
  int len = strlen(str);
  for (int i = 0; i < len; i++) {
    int x = str[i] - '0';
    if (tre[rt][x] == 0) {
      tre[rt][x] = ++tot;
      memset(
          tre[tre[rt][x]], 0,
          sizeof(
              tre[tre[rt]
                     [x]])); /// ��t�����룬��˲����������ɻ��ң����ÿ�������µĽڵ�Ҫ��յ�ǰ�ڵ�ĺ���
    }
    rt = tre[rt][x];
    if (vis[rt] == true)
      ans =
          false; /// Ԥ���̵ĺ����ȳ��֣��ڽ����������ʱʱ�̼�鵱ǰ·���Ľڵ�rt�Ƿ�������Ϊ����λ��
  } /// ���������������жϼ��ɣ�ע��������rt<tot!!
  if (rt < tot)
    ans =
        false; /// Ԥ�����ĺ����ȳ��֣��������̺���ĵ����ս����ڵ������������߹���һ���ڵ㣬Ҳ����˵����ڵ��ϱ�ǵĺ���С�����ڵ����
  vis[rt] = true; /// ��˵������ս�ڵ������߹����˶̺������ѳ��ֳ������ǰ׺��
}
int main() {
  int t, n, num;
  char phone[12];
  scanf("%d", &t);
  while (t--) {
    tot = 0;
    num = ++tot;
    ans = true;
    memset(vis, false, sizeof(vis));
    memset(tre[num], 0, sizeof(tre[num])); /// ������numҲ����totҲ��
    scanf("%d", &n);
    for (int i = 0; i < n; i++) /// �ڽ���ͬʱ����֮ǰ�ĺ����Ƿ��ǰ׺�ظ�
    {
      scanf("%s", phone);
      insert(phone, num);
    }
    printf("%s\n", ans ? "YES" : "NO");
  }
}
