#include <bits/stdc++.h>
typedef long long ll;
#define IOS ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n"
#define loop(i, start, end) for(int i=start; i<=end; ++i)
#define loopr(i, end, start) for(int i=end; i>=start; --i)
#define MOD 1e9+7
#define pb push_back
#define mp make_pair
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
int sv, ev;
vector<vector<int>> adj;
vector<int> visited;
vector<int> parent;


bool dfs(int u, int p) {
	visited[u]=true;
	parent[u]=p;
	for(auto v: adj[u]) {
		if(v == p) continue;
		if(visited[v])
		{
			sv=v;
			ev=u;
			return true;
		}
		if(!visited[v])
			if(dfs(v, u))
				return true;
	}
	return false;
}


bool visit_all() {
	loop(i, 1, n) {
		if(!visited[i])
			if(dfs(i, -1)) return true;
	}
	return false;
}

int main() {
	IOS
	cin >> n >> m;
	adj.resize(n+1);
	visited.resize(n+1);
	parent.resize(n+1);
    int a, b;
	loop(i, 1, m) {
		cin >> a >> b;
		adj[a].pb(b);
		adj[b].pb(a);
	}
	if(!visit_all()) {
		cout << "IMPOSSIBLE" << endl;
		return 0;
	}

	int tv=ev;
	vector<int> ans;
	ans.pb(ev);
	while(tv!=sv) {
		ans.pb(parent[tv]);
		tv=parent[tv];
	}
	ans.pb(ev);
	cout << ans.size() << endl;
	for(auto c: ans) {
		cout << c << " ";
	}
    cout << endl;
    return 0;
}
