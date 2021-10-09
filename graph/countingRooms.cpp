// Solution for https://cses.fi/problemset/task/1192/
#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define mod 1000000007
#define loop(i, n) for (ll i = 0; i < n; ++i)
#define loopf(i, k, n) for (ll i = k; i <= n; ++i)
#define loopr(i, k, n) for (ll i = k; i >= n; --i)
#define test(cases) \
    ll cases;       \
    input(cases);   \
    while (cases--)
#define print(a) printf("%lld\n", a)
#define input(a) scanf("%lld", &a)
#define inarr(a, n)            \
    for (ll i = 0; i < n; ++i) \
    scanf("%lld", &a[i])
#define assign(arr, x, n) loop(i, n) arr[i] = x
#define v(x) vector<x>
#define p(x,y) pair<x, y>
 
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
 
void dfs(vector<string> &graph, ll r, ll c){
    graph[r][c] = '#';
    loop(i, 4){
        ll row = r+dx[i], col = c+dy[i];
        if(row < graph.size() && row >= 0 && col < graph[0].size() && col >= 0 && graph[row][col] == '.')
        dfs(graph, row, col);
    }
}
 
int main() {
    ll n, m;
    cin>>n>>m;
    vector<string> graph(n);
    loop(i, n)
        cin>>graph[i];
    ll cnt = 0;
    loop(i, n)
    loop(j, m){
        if(graph[i][j] == '.'){
            ++cnt;
            dfs(graph, i, j);
        }
    }
    cout<<cnt;
}