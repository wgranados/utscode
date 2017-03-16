#include<bits/stdc++.h>
using namespace std;

int N, M, E, U;
int dr[] = {-1, 0, 1, 0};
int dc[] = {0, 1, 0, -1};
bool v[50][50];
vector<pair<int,pair<int,int> > >enemies;
vector<pair<int,int> >units;

bool valid(int r, int c) {
    return r >= 0 && r < N && c >= 0 && c < M;
}

void dfs(int r, int c, int m) {
    if(m >= 0){
        v[r][c] = true;
        for(int d = 0;d < 4;d++) {
            int nr = r+dr[d];
            int nc = c+dc[d];
            if(valid(nr, nc)) {
                dfs(nr, nc, m-1);
            }
        }
    }
}

vector< pair<int,int> >new_loc;
void dfs_brute(int troop){
    if(troop >= 0){
        // try branching out in 4 standard directions
        for(int d = 0;d < 4;d++) {
            int nr = units[troop].first + dr[d];
            int nc = units[troop].second + dc[d];
            if(valid(nr, nc) && !v[nr][nc]) {
                new_loc.push_back(make_pair(nr, nc));
                dfs_brute(troop-1);
                new_loc.pop_back();
            }
        }
        // try staying in the same place
        int nr = units[troop].first;
        int nc = units[troop].second;
        if(!v[nr][nc]) {
            new_loc.push_back(make_pair(nr, nc));
            dfs_brute(troop-1);
            new_loc.pop_back();
        }
    }else {
        // checking for validaty of generated
        // movement of units
        set< pair<int,int> >check_for_int;
        for(int i = 0;i < new_loc.size();i++) {
            if(!check_for_int.count(new_loc[i])) {
                check_for_int.insert(new_loc[i]);
            } else{
                check_for_int.clear();
                return;
            }
        }
        for(int i = new_loc.size()-1;i >= 0;i--){
            cout << new_loc[i].first+1 << " " << new_loc[i].second+1 << endl;
        }
        exit(0);
    }
}

void debug(int n, int m) {
    for(int i = 0;i < n;i++) {
        for(int j = 0;j < m;j++) {
            cout << (v[i][j] ? "1":"0");
        }
        cout << endl;
    }
}

int main() {
    cin >> N >> M >> E >> U;
    memset(v, false, sizeof(v));
    for(int i = 0;i < E;i++) {
        int x,y,m;
        cin >> x >> y >> m;
        enemies.push_back(make_pair(x-1, make_pair(y-1, m)));
    }
    for(int i = 0;i < U;i++){
        int x,y;
        cin >> x >> y;
        units.push_back(make_pair(x-1,y-1));
    }
    for(int i = 0;i < E;i++){
        // flood fill one more space to check to mark movement and attack range
        dfs(enemies[i].first, enemies[i].second.first, enemies[i].second.second+1);
    }
    dfs_brute(units.size()-1);
    // dfs_brute executes exit(0) on successful brute force
    cout << "soft-reset!" << endl;
    return 0;
}
