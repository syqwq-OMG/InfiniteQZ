void solve_A() {
    priority_queue<int, vector<int>, greater<int>> q;
    int cnt[20] = {0};
    char c;
    for (int i = 1; i <= 10; ++i) {
        cin >> c;
        cnt[c - '0']++;
    }
    for (int i = 1; i <= 10; ++i) {
        for (int j = 1; j <= cnt[10 - i]; ++j) {
            q.push(10 - i);
        }
        cout << q.top();
        q.pop();
    }
    cout << endl;
}

void upd(int l, int r) {
    int len = r - l + 1;
    if (len % 2 == 0) {
        ansl = min(a[l + len / 2 - 1], ansl);
        ansr = max(a[len / 2 + l], ansr);
    } else {
        ansl = min(a[len / 2 + l], ansl);
        ansr = max(a[len / 2 + l], ansr);
    }
}

solve_B() {
    int n, k;
    cin >> n >> k;

    ansr = 0, ansl = 0x7fffffff;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }

    sort(a + 1, a + n + 1);
    upd(1, n - k);
    upd(1 + k, n);
    if (k >= 1) {
        upd(1, n - k + 1);
        upd(1, n);
    }

    cout << ansr - ansl + 1 << endl;
}

struct Node {
    int cnt;
    int val;
};

vector<Node> ns;

void solve_C() {
    ns.clear();
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }

    sort(a + 1, a + n + 1);
    for (int i = 1; i <= n; ++i) {
        int c = 1;
        while (a[i + 1] == a[i]) {
            i++;
            c++;
        }
        ns.push_back({c, a[i]});
    }

    int last = -1;
    bool fl = false;
    for (auto v : ns) {
        if (v.cnt >= 4) {
            cout << "Yes" << endl;
            return;
        }
        if (v.val - last != 1) {
            fl = false;
        }
        last = v.val;
        if (fl == true) {
            if (v.cnt >= 2) {
                cout << "Yes" << endl;
                return;
            }
            if (v.cnt == 0)
                fl = false;
        } else {
            if (v.cnt >= 4) {
                cout << "Yes" << endl;
                return;
            } else if (v.cnt >= 2) {
                fl = true;
            }
        }
    }
    cout << "No" << endl;
}
