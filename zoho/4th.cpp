#include<bits/stdc++.h>
using namespace std;
#define int long long int


int32_t main()
{

    int n; //length of array, to be inputed.
    cin >> n;

    char arr[n]; //array of char is inputed
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    char src;
    cin >> src;

    queue<int> Q;
    for (int i = 0; i < n; i++)
        if (arr[i] == src)
            Q.push(i);

    int result[n];
    memset(result, -1, sizeof result);

    int level = -1;
    while (!Q.empty()) {
        level++;
        int size = Q.size();
        while (size--) {
            int top = Q.front();
            Q.pop();
            if (result[top] != -1)
                continue;

            result[top] = level;
            if (top - 1 >= 0)
                Q.push(top - 1);
            if (top + 1 < n)
                Q.push(top + 1);
        }
    }
    for (int i = 0; i < n; i++)
        cout << result[i] << " ";

    return 0;
}