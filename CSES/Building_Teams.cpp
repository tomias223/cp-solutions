// bipartiteness check

#include <bits/stdc++.h>
typedef long long ll;
#define IOS ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n"
#define loop(i, start, end) for(int i=start; i<=end; ++i)
#define loopr(i, end, start) for(int i=end; i>=start; --i)
#define MOD 1e9+7
#define pb push_back
using namespace std;

template <typename T>
void inputArray(T *a, int start, int end) {
    loop(i, start, end) cin >> a[i];
}

template <typename T>
void printArray(T *a, int start, int end) {
    loop(i, start, end) cout << *(a+i) << ' ';
}

void ruffleSort(int *a, int n) {
    unsigned seed=0;
    shuffle(a, a+n, default_random_engine(seed));
    sort(a, a+n);
}

int n, m;
bool bipartite=true;

void dfs(vector<int>* adj, bool* visited, int* team, int s=1, int t=1) {
    if(visited[s]) return;
    visited[s]=true;
    team[s]=t;
    for(int u: adj[s]) {
        if(team[u]==team[s]) {
            bipartite=false;
            return;
        }
        if(t==1) dfs(adj, visited, team, u, 2);
        else dfs(adj, visited, team, u, 1);
    }
}

int main()
{
    IOS;
    cin >> n >> m;
    vector<int> adj[n+1];
    int a, b;
    bool visited[n+1]={};
    loop(i, 1, m) {
        cin >> a >> b;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    int team[n+1]={};
    team[1]=1;
    loop(i, 1, n) {
        if(!visited[i]) dfs(adj, visited, team, i, 1);
    }
    if(!bipartite) cout << "IMPOSSIBLE";
    else {
        loop(i, 1, n) cout << team[i] << ' ';
    }
    cout << endl;
    // cerr << "execution time: " << (1.0*clock())/CLOCKS_PER_SEC << "s" << endl;
    return 0;
}
