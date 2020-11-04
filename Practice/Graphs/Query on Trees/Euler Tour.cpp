#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define endl    "\n"
#define inf 1000000000000000000LL

//Euler Tour -> use in Trees, which gives the  way of traversing tree such that
//each vertex is added to the tour when we visit it. Used in LCA
//3 Types of Euler Tour:

const int N = 10005;
vector<int> gr[N];
/*
timer will tell whether the 'x' is ancestor of 'y'
y is in subtree of 'x' or not?
whether x comes in path of y to root.
*/

int timer;
int tin[N], tout[N];

//print changes in the node
/* We get 2(n-1) + 1 outputs because, every edge is traversed twice
    and the first node is written as it is.
*/
void euler_tour1(int cur, int par) {
    cout << cur << " ";
    for (auto x : gr[cur]) {
        if (x != par) {
            euler_tour1(x, cur);
            cout << cur << " ";
        }
    }
}

//print only when entering and exiting
void euler_tour2(int cur, int par) {
    cout << cur << " ";
    // tin[cur] = ++timer;
    for (auto x : gr[cur]) {
        if (x != par) {
            euler_tour2(x, cur);
        }
    }
    cout << cur << " ";
    // tout[cur] = ++timer;
}

//print only when entering
void euler_tour3(int cur, int par) {
    cout << cur << " ";
    tin[cur] = ++timer;
    for (auto x : gr[cur]) {
        if (x != par) {
            euler_tour3(x, cur);
        }
    }
    tout[cur] = timer;
}

bool is_ancestor(int u, int v) {
    return (tin[u] <= tin[v] && tout[u] >= tout[v]);
}

int32_t main()
{   ios_base::sync_with_stdio(false);
    cin.tie(NULL);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n;
    cin >> n;
    for (int i = 0; i < n - 1; i++) { //tree
        int u, v;
        cin >> u >> v;
        gr[u].push_back(v);
        gr[v].push_back(u);
    }

    // euler_tour1(1, 0);
    // euler_tour2(1, 0);
    timer = 0;
    euler_tour3(1, 0);
    cout << '\n';
    for (int i = 1; i <= n; i++) {
        cout << i << " " << tin[i] << " " << tout[i] << endl;
    }
    cout << '\n';
    if (is_ancestor(2, 4))
        cout << "YES";
    else cout << "NO";
    return 0;
}

/*
9
1 2
2 4
2 5
2 6
1 3
3 7
7 8
7 9
*/