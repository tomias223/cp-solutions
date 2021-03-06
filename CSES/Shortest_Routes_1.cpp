#include <bits/stdc++.h>
typedef long long ll;
#define IOS ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n"
#define loop(i, start, end) for(int i=start; i<=end; ++i)
#define loopr(i, end, start) for(int i=end; i>=start; --i)
#define MOD 1e9+7
#define pb push_back
#define mp make_pair
#define INF 1e18+1e17+1e16+1e15+1e14
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
vector<vector<pair<int, int>>> adj;

int main()
{
    IOS
    cin >> n >> m;
    adj.resize(n+1);
    int a, b, w;
    loop(i, 1, m) {
        cin >> a >> b >> w;
        adj[a].pb(mp(b, w));
    }
    bool visited[n+1]={};
    ll distance[n+1]={};
    distance[1]=0;
    loop(i, 2, n) distance[i]=INF;
    priority_queue<pair<int, int>> q;
    q.push(mp(0, 1));
    while(!q.empty()) {
        int a=q.top().second;
        q.pop();
        if(visited[a]) continue;
        visited[a]=true;
        for(auto u: adj[a]) {
            int b=u.first, w=u.second;
            if(distance[a]+w < distance[b]) {
                distance[b]=distance[a]+w;
                q.push(mp(distance[b]*(-1), b));
            }
        }
    }
    printArray(distance, 1, n);
    // cerr << "execution time: " << (1.0*clock())/CLOCKS_PER_SEC << "s" << endl;
    return 0;
}
