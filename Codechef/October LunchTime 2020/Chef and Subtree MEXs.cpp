#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define endl    "\n"
#define inf 1000000000000000000LL

int N;
int ans;
vector<int> subtree;
vector<vector<int> > graph;

int computeSubtree(int cur, int par) {
    subtree[cur] = 1;
    for (auto nbr : graph[cur]) {
        if (nbr == par) continue;
        subtree[cur] += computeSubtree(nbr, cur);
    }
    return subtree[cur];
}

void dfs(int cur, int par, int ancestorSum) {
    int value = ancestorSum + subtree[cur];
    for (int nbr : graph[cur]) {
        if (nbr == par) continue;
        dfs(nbr, cur, value);
    }
    ans = max(value, ans);
}


int32_t main()
{   ios_base::sync_with_stdio(false);
    cin.tie(NULL);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int t;
    cin >> t;
    while (t--) {
        cin >> N;
        ans = 0;
        graph.clear();
        subtree.assign(N + 1, 0);
        graph.resize(N + 1);

        for (int i = 2; i <= N; i++) {
            int a = i, b;
            cin >> b;
            graph[a].push_back(b);
            graph[b].push_back(a);
        }
        computeSubtree(1, 0);

        dfs(1, 0, 0);
        cout << ans << endl;
    }

    return 0;
}