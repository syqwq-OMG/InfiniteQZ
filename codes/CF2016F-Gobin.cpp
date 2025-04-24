#include <iostream>
using namespace std;
void solve() {
    int n;
    cin >> n;
    char t;
    long long u = 0, l = 0;
    long long ans = 0;

    for (int i = 1; i <= n; ++i) {
        cin >> t;
        if (t == '0') {
            u += i - 1;
            l += n - i;
        } else {
            ans = max(ans, u);
            u = l + 1;
            ans = max(ans, l);
            l = 0;
        }
    }
    ans = max(ans, max(u, l));
    cout << ans << endl;
}
int main() {
    int t;
    cin >> t;
    while (t--)
        solve();
}
