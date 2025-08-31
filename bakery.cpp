#include <bits/stdc++.h>
using namespace std;

long long a[100];
long long b[100];
long long c[100];


bool satisfies(long long moonies, int N, long long tC, long long tM) {

    long long tml = 1; 
    long long tmh = tM;
    long long u = moonies;
    
    for (int i = 0; i < N; i++) {
   
        if (b[i] > a[i]) { 
            tmh = min(tmh, (c[i] - a[i]*(tC + tM - u)) / (b[i]-a[i]));
        } else if (b[i] < a[i]) { 
    
            long long numer = a[i]*(tC + tM - u) - c[i];
            long long denom = a[i] - b[i];
            if ((numer % denom) == 0) {
              tml = max(tml, numer/denom);
            } else {
              tml = max(tml, (numer / denom)+1);
            }
        } else { 
            if (a[i]*(tC + tM - u) > c[i]) {
                return false;
            }
        }
    }

    long long tch = tC + tM - u - tml;
    long long tcl = tC + tM - u - tmh;
    
    return ((tml <= tmh) and (tcl <= tC) and (tch >= 1));
}

void batisfies(long long moonies, int N, long long tC, long long tM) {
    long long tml = 1;
    long long tmh = tM;
    long long u = moonies;
    
    for (int i = 0; i < N; i++) {
        if (b[i] > a[i]) {
            tmh = min(tmh, (c[i] - a[i]*(tC + tM - u)) / (b[i]-a[i]));
        } else if (b[i] < a[i]) {
            tml = max(tml, (c[i] - a[i]*(tC + tM - u)) / (b[i]-a[i]));
        } else { 
            if (a[i]*(tC + tM - u) > c[i]) {
                cout << -1 << " " << -1 << endl;
            }
        }
    }

    cout << "tM: " << tml << " " << tmh << endl;
    long long tch = tC + tM - u - tml;
    long long tcl = tC + tM - u - tmh;
    cout << "tC: " << tcl << " " << tch << endl;
}

int main()
{
    int T;
    cin >> T;
    int N;
    long long tC, tM;
    long long A,B,C;
    for (int j = 0; j < T; j++){ 
        cin >> N >> tC >> tM;
        for (int i = 0; i < N; i++) {
            cin >> A >> B >> C;
            a[i] = A;
            b[i] = B;
            c[i] = C;
        }

        long long xl = 0;
        long long xr = tC + tM - 2;
        long long x;
        while (xl < xr) {
            x = (xl + xr) / 2;
            if (satisfies(x, N, tC, tM)) {
                xr = x;
            } else {
                xl = x+1;
            }
        }
        cout << xl << endl;

    }
    return 0;
}
