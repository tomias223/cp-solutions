// dfs problem

#include <bits/stdc++.h>
typedef long long ll;
#define IOS ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n"
#define ff first
#define ss second
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
bool* visited;
void dfs(vector<int> adj[], int s) {
    if (visited[s]) return;
    visited[s]=true;
    // cout << s << ' ';
    for (auto u: adj[s]) {
        dfs(adj, u);
    }
}

int main()
{
    IOS;
    cin >> n >> m;
    vector<int> adj[n+1];
    visited=new bool[n+1];
    int a, b;
    int ans=0;
    loop(i, 0, m-1) {
        cin >> a >> b;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    vector<int> c;
    loop(i, 1, n) {
        if(!visited[i]) {
            dfs(adj, i);
            ++ans;
            c.pb(i);
            cout << endl;
        }
    }
    cout << ans-1 << endl;
    for(auto it=c.begin(); it!=(c.end()-1); ++it) {
        cout << *it << ' ' << *(it+1) << endl;
    }
    delete[] visited;
    //cerr<<" Execution : "<<(1.0*clock())/CLOCKS_PER_SEC<<"s \n";
    return 0;
}
