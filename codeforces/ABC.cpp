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
    while(t--) {
        int n;
        string s;
        cin >> n >> s;
        if(n>2) {
            cout << "NO" << endl;
            continue;
        }
        if(s[0]==s[1]) cout << "NO";
        else cout << "YES";
        cout << endl;
    }
    // cerr << "execution time: " << (1.0*clock())/CLOCKS_PER_SEC << "s" << endl;
    return 0;
}
