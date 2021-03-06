#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
// queue라는 헤더파일을 저장해야 한다.
using namespace std;
int ch[30], dis[30];
// ch배열 역할: 방문했는지 확인한다. 한번 방문한 곳은 방문하지 않는다. 그것이 최소 간선 수.
// dis배열 역할: i번째 정점까지 오는데 필요한 최소 간선 수를 저장한다.

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
        // 방향이 존재하기 때문에 위와 같이 표시한다.
        // 간선 정보 저장
    }
    Q.push(1);
    ch[1] = 1;
    while (!Q.empty()){
        // !Q.empty(): 자료가 있으면 참
        x = Q.front();
        // Q의 맨앞 값을 x에 저장
        Q.pop();
        // Q의 맨앞 값을 제거한다.
        for (i = 0;i < map[x].size();i++) {
        // 시작 정점에서의 맵 크기만큼
            if (ch[map[x][i]] == 0) {
            // 방문하지 않은 정점을 방문한다.
                ch[map[x][i]] = 1;
                // 방문했다고 표시, 이후로 방문하지 않는다.
                Q.push(map[x][i]);
                // 해당 값을 Q에 저장한다.
                dis[map[x][i]] = dis[x] + 1;
                // 방문했던 정점 인덱스에 간선 수를 하나 추가한다.
                // x에서 map[x][i]로 갈 때의 최소 간선 수를 저장한다.
            }
        }

    }
    for (i = 2;i <= n;i++) {
        cout << i << " : " << dis[i] << "\n";
        // 각 간선 정보 저장
    }
    return 0;
}