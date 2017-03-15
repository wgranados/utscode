#include<bits/stdc++.h>
using namespace std;

int N, M;
int A[5001][5001];

int dr[] = {-1, 0, 1, 0};
int dc[] = {0, 1, 0, -1};

bool within_range(int r, int c) {
    return 0 <= r && r < N && 0 <= c && c < M;
}

bool is_possible(int r, int c) {
    for(int d = 0;d < 4;d++) {
        if(within_range(r+dr[d], c+dc[d]) && A[r+dr[d]][c+dc[d]] != 0){
            return true;
        }
    }
    return false;
}

int main() {
    cin >> N >> M;
    for(int i = 0;i < N;i++) {
        for(int j = 0;j < M;j++) {
            cin >> A[i][j];
        }
    }
    int r = 0, c = 0, ans = 0;
    while(is_possible(r, c)) {
        int best = 0, dir = 0;
        for(int d = 0;d < 4;d++){
            if(within_range(r+dr[d], c+dc[d]) && A[r+dr[d]][c+dc[d]] != 0){
                if(best < A[r+dr[d]][c+dc[d]] ){
                    best = A[r+dr[d]][c+dc[d]];
                    dir = d;
                }
            }
        }
        ans += best;
        r += dr[dir];
        c += dc[dir];
        A[r][c] = 0;
    }
    cout << ans << endl;
    return 0;
}
