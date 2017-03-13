#include<bits/stdc++.h>
using namespace std;

int N;
int A[5001];
bool smaller[5001];

int main() {
    cin >> N;
    for(int i = 0;i < N;i++) {
        cin >> A[i];
    }
    for(int i = 0;i < N-1;i++) {
        smaller[i] = A[i] < A[i+1];
    }
    int ans = 0;
    for(int i = 0;i < N;i++){
        int j = i;
        while(smaller[j++] && j != N-1);
        ans = max(ans, j-i);
    }
    cout << ans << endl;
    return 0;
}
