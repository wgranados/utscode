#include<bits/stdc++.h>
#define MAXN 5001
#define MAXH 5001
#define INF 0x3f3f3f3f
using namespace std;

int N,H,R;
int rules[MAXN];
int DP[MAXN][MAXH];

int rec(int num_heads, int cur_health) {
    if(num_heads == 0) {
        return 0;
    }
    else if (DP[num_heads][cur_health] != INF){
        return DP[num_heads][cur_health];
    }
    else {
        // try defending
        int num_head_if_defend = rules[num_heads];
        int cur_health_if_defend  = cur_health-1;
        // avoid case where we constantly defend only to lose health, this is a lost battle anyway
        if(cur_health_if_defend > 0 && rules[num_heads] != num_heads) {
            DP[num_heads][cur_health] = min(DP[num_heads][cur_health], 1+rec(num_head_if_defend, cur_health_if_defend));
        }
        // try attacking
        int num_head_if_attack = rules[num_heads-1];
        int cur_health_if_attack = cur_health-num_heads;
        if(cur_health_if_attack > 0) {
            DP[num_heads][cur_health] = min(DP[num_heads][cur_health], 1+rec(num_head_if_attack, cur_health_if_attack));
        }
        if(DP[num_heads][cur_health] == INF)// i.e.e impossible
            DP[num_heads][cur_health] = INF+1;
        return DP[num_heads][cur_health];
    }
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
        rules[n_i] = n_j;
    }
    int ans = rec(N, H);
    if(ans >= INF)
        cout << "retreat" << endl;
    else
        cout << ans << endl;
    return 0;
}
