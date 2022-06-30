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

const int N=1005;

int n, m;
int a[N][N], mn[N][N], mx[N][N];
bool pos;

int main()
{
    IOS
    int t;
    cin >> t;
    while(t--) {
        cin >> n >> m;
        loop(i, 1, n) {
            loop(j, 1, m) cin >> a[i][j];
        }
        if((n+m)%2==0) {
            cout << "NO" << endl;
            continue;
        }
        mn[1][1]=mx[1][1]=a[1][1];
        loop(i, 1, n) mx[i][1]=mn[i][1]=mx[i-1][1]+a[i][1];
        loop(j, 1, m) mx[1][j]=mn[1][j]=mx[1][j-1]+a[1][j];
        loop(i, 1, n) {
            loop(j, 1, m) {
                mx[i][j]=max(mx[i-1][j], mx[i][j-1])+a[i][j];
                mn[i][j]=min(mn[i-1][j], mn[i][j-1])+a[i][j];
            }
        }
        if(mx[n][m]>=0 && mn[n][m]<=0) cout << "YES";
        else cout << "NO";
        cout << endl;
    }
    // cerr << "execution time: " << (1.0*clock())/CLOCKS_PER_SEC << "s" << endl;
    return 0;
}
