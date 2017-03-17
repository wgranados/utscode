#include<bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define MAXN 5001
#define MAXT 5001
#define MAXP 11
#define INF 0x3f3f3f3f
using namespace std;

int N,M,T,P;
vector< pair<int, pair<int,int> > > adj[MAXN]; // safe point, time to cross, safe or not
int dist[MAXN][MAXT][MAXP];

void dijkstra(int start_node, int end_node){
    queue< pair<pair<int,int>, pair<int,int> > >pq; // current distance, current health, potions left, node
    pq.push( mp( mp(0, T), mp(P, start_node) ) );
    while(!pq.empty()){
        int cur_dist = pq.front().first.first;
        int cur_health = pq.front().first.second;
        int cur_potions = pq.front().second.first;
        int cur_node = pq.front().second.second;
        pq.pop();
        //cout << cur_node << endl;
        for(int i = 0;i < adj[cur_node].size();++i){
            int next_node = adj[cur_node][i].first;
            int next_dist = cur_dist + adj[cur_node][i].second.first;
            bool is_safe_road = adj[cur_node][i].second.second;
            // just proceed like normal dijkstras
            if(!is_safe_road) {
                if(dist[next_node][cur_health][cur_potions] > next_dist){
                   dist[next_node][cur_health][cur_potions] = next_dist;
                   pq.push(mp( mp(dist[next_node][cur_health][cur_potions], cur_health),
                               mp(cur_potions, next_node)));
                }
            } else{
                // use a potion incurring no costs
                if(cur_potions > 0) {
                    if(dist[next_node][cur_health][cur_potions-1] > next_dist){
                       dist[next_node][cur_health][cur_potions-1] = next_dist;
                       pq.push(mp( mp(dist[next_node][cur_health][cur_potions-1], cur_health),
                                   mp(cur_potions-1, next_node)));
                    }
                }
                int remaining_health = cur_health-adj[cur_node][i].second.first;
                // try traversing the path without a potion
                if(remaining_health >= 0 && dist[next_node][cur_health][cur_potions] > next_dist){
                   dist[next_node][remaining_health][cur_potions] = next_dist;
                   pq.push(mp( mp(dist[next_node][remaining_health][cur_potions], remaining_health),
                               mp(cur_potions, next_node)));
                }
            }
        }
    }
}

int main(){
    for(int i = 0;i < MAXN;i++)
        for(int j = 0;j < MAXT;j++)
            for(int k = 0;k < MAXP;k++)
                dist[i][j][k] = INF;
    cin >> N >> M >> T >> P;
    for(int i = 0;i < M;i++) {
        int u,v,t,m;
        cin >> u >> v >> t >> m;
        adj[u].push_back(make_pair(v, make_pair(t, m)));
        adj[v].push_back(make_pair(u, make_pair(t, m)));
    }
    int S, E;
    cin >> S >> E;
    dijkstra(S, E);
    int ans = INF;
    for(int t = 0;t <= T;t++) {
        for(int p = 0;p <= P;p++){
            ans = min(ans, dist[E][t][p]);
        }
    }
    if(ans == INF){
        cout << "retreat" << endl;
    } else {
        cout << ans << endl;
    }
    return 0;
}
