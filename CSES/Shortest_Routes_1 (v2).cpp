// shortest path -- bellman-ford (TLE)

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
#define INF 1000000000
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

int main()
{
    IOS;
    vector<tuple<int, int, int>> edges;
    cin >> n >> m;
    int a, b, w;
    loop(i, 1, m) {
        cin >> a >> b >> w;
        edges.pb({a, b, w});
    }
    int distance[n+1];
    distance[1]=0;
    loop(i, 2, n) distance[i]=INF;
    loop(i, 1, n-1) {
        for(auto e: edges) {
            tie(a, b, w)=e;
            distance[b]=min(distance[b], distance[a]+w);
        }
    }
    loop(i, 1, n) cout << distance[i] << ' ';
    cout << endl;
    // cerr << "execution time: " << (1.0*clock())/CLOCKS_PER_SEC << "s" << endl;
    return 0;
}
