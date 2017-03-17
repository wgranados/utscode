#include<bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define MAXN 5001
#define MAXS 11
#define INF 0x3f3f3f3f
using namespace std;

int N,M,S;
vector< pair<int, int> > adj[MAXN]; // safe point, time to cross
int dist[MAXN][MAXS];

void dijkstra(int start_node, int end_node){
    priority_queue< pair<int, pair<int,int> > >pq; // current distance, tome uses left, node
    pq.push( mp(0, mp(-S, start_node)) );
    while(!pq.empty()){
        int cur_dist = -pq.top().first;
        int cur_spell_uses = -pq.top().second.first;
        int cur_node = pq.top().second.second;
        pq.pop();
        for(int i = 0;i < adj[cur_node].size();++i){
            int next_node = adj[cur_node][i].first;
            int next_dist = cur_dist + adj[cur_node][i].second;
            if(cur_spell_uses > 0) {
                if(dist[next_node][cur_spell_uses-1] > cur_dist) {
                    dist[next_node][cur_spell_uses-1] = cur_dist;
                    pq.push(mp(-dist[next_node][cur_spell_uses-1], mp(-(cur_spell_uses-1), next_node)));
                }
            }
            if(dist[next_node][cur_spell_uses] > next_dist) {
                dist[next_node][cur_spell_uses] = next_dist;
                pq.push(mp(-dist[next_node][cur_spell_uses], mp(-cur_spell_uses, next_node)));
            }
        }
    }
}

int main(){
    for(int i = 0;i < MAXN;i++)
        for(int j = 0;j < MAXS;j++)
                dist[i][j] = INF;
    cin >> N >> M >> S;
    for(int i = 0;i < M;i++) {
        int u,v,t;
        cin >> u >> v >> t;
        adj[u].push_back(make_pair(v, t));
        adj[v].push_back(make_pair(u, t));
    }
    int S, E;
    cin >> S >> E;
    dijkstra(S, E);
    int ans = INF;
    for(int s = 0;s <= S;s++){
        ans = min(ans, dist[E][s]);
    }
    if(ans == INF){
        cout << "retreat" << endl;
    } else {
        cout << ans << endl;
    }
    return 0;
}
