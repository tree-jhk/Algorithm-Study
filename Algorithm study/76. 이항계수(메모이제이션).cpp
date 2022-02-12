#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
int dy[21][21];
//dy 선언해서 같은 경우가 또 발생하면 더 이상 가지를 뻗지 않게 함.

int DFS(int n, int r) {
    if(dy[n][r] > 0)
        return dy[n][r];
        // 기존에 계산된 값을 리턴함.
    if(n == r || r == 0)
        return 1;
    else
        return dy[n][r] = DFS(n - 1,r - 1) + DFS(n - 1, r);
        // 메모리제이션 기법: 재귀를 더 빨리 돌릴 수 있다.
}

int main(int argc, const char* argv[]) {
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);
    int n;
    cin >> n >> r;
    cout << DFS(n, r);
    return 0;
}