#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, a[10] = {}, ans = 1;
    cin >> N;
    while(N) {
        a[N%10]++;
        N /= 10;
    }
    for(int i = 0; i < 10; i++) {
        if(a[i] == 6 || a[i] == 9) continue;
        ans = max(ans, a[i]);
    }
    ans = max(ans, (a[6] + a[9] +1)/2);

    cout << ans;
}