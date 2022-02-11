#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
// queue��� ��������� �����ؾ� �Ѵ�.
using namespace std;
int ch[30], dis[30];
// ch�迭 ����: �湮�ߴ��� Ȯ���Ѵ�. �ѹ� �湮�� ���� �湮���� �ʴ´�. �װ��� �ּ� ���� ��.
// dis�迭 ����: i��° �������� ���µ� �ʿ��� �ּ� ���� ���� �����Ѵ�.

int main(int argc, const char* argv[]) {
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);
    int i, n, m, a, b, x;
    vector<int> map[30];
    queue<int> Q;
    cin >> n >> m;
    for (i = 1;i <= m;i++) {
        cin >> a >> b;
        map[a].push_back(b);
        // ������ �����ϱ� ������ ���� ���� ǥ���Ѵ�.
        // ���� ���� ����
    }
    Q.push(1);
    ch[1] = 1;
    while (!Q.empty()){
        // !Q.empty(): �ڷᰡ ������ ��
        x = Q.front();
        // Q�� �Ǿ� ���� x�� ����
        Q.pop();
        // Q�� �Ǿ� ���� �����Ѵ�.
        for (i = 0;i < map[x].size();i++) {
        // ���� ���������� �� ũ�⸸ŭ
            if (ch[map[x][i]] == 0) {
            // �湮���� ���� ������ �湮�Ѵ�.
                ch[map[x][i]] = 1;
                // �湮�ߴٰ� ǥ��, ���ķ� �湮���� �ʴ´�.
                Q.push(map[x][i]);
                // �ش� ���� Q�� �����Ѵ�.
                dis[map[x][i]] = dis[x] + 1;
                // �湮�ߴ� ���� �ε����� ���� ���� �ϳ� �߰��Ѵ�.
                // x���� map[x][i]�� �� ���� �ּ� ���� ���� �����Ѵ�.
            }
        }

    }
    for (i = 2;i <= n;i++) {
        cout << i << " : " << dis[i] << "\n";
        // �� ���� ���� ����
    }
    return 0;
}