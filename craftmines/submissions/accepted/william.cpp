#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#define MAXN 101
using namespace std;

struct edge{
    int d,c,sn,en;
    bool operator < (const edge& rhs) const{
        return (d == rhs.d) ? c > rhs.c:d < rhs.d;
    }
};

int parent[MAXN];
int N,M;
vector <edge> e;

int find(int x){
	if(parent[x]!=x)parent[x]=find(parent[x]);
	return parent[x];
}

bool merge(int x,int y){
	x = find(x);
	y = find(y);
	if(x == y)return false;
	if(parent[x] < parent[y]){// -7 < -3
		parent[y] = x;
	}
	else{
		parent[x] = y;
	}
	return true;
}
int main(){
    scanf("%d%d",&N,&M);
    for(int i = 0; i < 100;i++)parent[i]=i;
    for(int i = 0; i < M;i++){
        int a,b,c,d;
        scanf("%d%d%d%d",&a,&b,&c,&d);
        e.push_back((edge){d,c,a,b});
    }
    sort(e.begin(),e.end());
    int tot_d = 0,tot_c = 0;
    for(int i = 0, n = 0; i < e.size() && n != N-1;i++){
        int a = find(e[i].sn);
        int b = find(e[i].en);
        if(a!=b){
            merge(e[i].sn,e[i].en);
            tot_c+=e[i].c;
            tot_d+=e[i].d;
            n++;
        }
    }
    printf("%d %d\n",tot_d,tot_c);
    return 0;
}

