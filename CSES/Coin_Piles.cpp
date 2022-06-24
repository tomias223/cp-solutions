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

int n, a, b;

int main()
{
    IOS;
    cin >> n;
    while(n--) {
        cin >> a >> b;
        int x1=(2*a-b)/3;
        int x2=(2*a-b)%3;
        int y1=(2*b-a)/3;
        int y2=(2*b-a)%3;
        if((x1>=0 && x2==0) && (y1>=0 && y2==0)) cout << "YES";
        else cout << "NO";
        cout << endl;
    }
    //cerr<<" Execution : "<<(1.0*clock())/CLOCKS_PER_SEC<<"s \n";
    return 0;
}
