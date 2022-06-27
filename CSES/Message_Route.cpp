// bfs problem

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

void bfs(vector<int> adj[], bool visited[], queue<int> q, int distance[]) {
    int parent[n+1]={};
    vector<int> path;
    while(!q.empty()) {
        int s=q.front();
        q.pop();
        if(s==n) {
            path.pb(n);
            cout << distance[s]+1 << endl;
            int x=parent[s];
            while(x!=1) {
                path.pb(x);
                x=parent[x];
            }
            path.pb(1);
            reverse(begin(path), end(path));
            for(int p: path) {
                cout << p << ' ';
            }
        }
        for(int u: adj[s]) {
            if(visited[u]) continue;
            visited[u]=true;
            parent[u]=s;
            distance[u]=distance[s]+1;
            q.push(u);
        }
    }
    if(!visited[n]) {
        cout << "IMPOSSIBLE";
    }
    cout << endl;
}

int main()
{
    IOS;
    cin >> n >> m;
    vector<int> adj[n+1];
    int a, b;
    loop(i, 0, m-1) {
        cin >> a >> b;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    bool visited[n+1]={};
    int distance[n+1]={};
    queue<int> q;
    visited[1]=true;
    distance[1]=0;
    q.push(1);
    bfs(adj, visited, q, distance);
    // cerr << "execution time: " << (1.0*clock())/CLOCKS_PER_SEC << "s" << endl;
    return 0;
}
