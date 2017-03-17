#include<bits/stdc++.h>
#define MAXN 5001
#define MAXH 5001
#define INF 0x3f3f3f3f
using namespace std;

int N,H,R;
int rules[MAXN];
int DP[MAXN][MAXH];

void rec(int num_heads, int cur_health) {
    int next_head_if_attack = rules[num_heads];
    int next_health_if_attack = cur_health-num_heads;

}

int main() {
    cin >> N >> H >> R;
    memset(DP, INF, sizeof(DP));
    for(int i = 0;i < MAXN;i++) {
        rules[i] = i;
    }
    for(int i = 0;i < R;i++) {
        int n_i, n_j;
        cin >> n_i >> n_j;
        rules[n_j] = n_j;
    }
    rec(N, H);
    return 0;
}
