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

int main()
{
    IOS
    int t;
    cin >> t;
    int n, m, k, x, y, Max, ans;
    while(t--) {
        Max=INT_MIN;
        x=0; y=0;
        cin >> n >> m;
        int a[n][m];
        loop(i, 0, n-1) {
            loop(j, 0, m-1) {
                cin >> k;
                if(k>Max) {
                    Max=k;
                    x=i;
                    y=j;
                }
            }
        }
        int p=max(x, n-1-x); ++p;
        int q=max(y, m-1-y); ++q;
        // cout << x << ' ' << y << ' ' << Max << endl;
        cout << p*q << endl;
    }
    // cerr << "execution time: " << (1.0*clock())/CLOCKS_PER_SEC << "s" << endl;
    return 0;
}
