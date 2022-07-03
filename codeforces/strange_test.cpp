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
    	int a, b;
    	cin >> a >> b;
    	int k=0;
    	while(a/(1<<k)) ++k;
    	int i=0;
        vector<bool> bin;
        int m=b;
        while(m) {
            bin.pb(m%2);
            m/=2;
        }
        int c=0;
        reverse(bin.begin(), bin.end());
        loop(i, 0, k-1) {
            c+=(bin[i]<<i);
        }
        int ans=0;
        int diff=abs(c-a);
        
        cout << endl;
    }
    // cerr << "execution time: " << (1.0*clock())/CLOCKS_PER_SEC << "s" << endl;
    return 0;
}
