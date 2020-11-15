#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define endl    "\n"
#define inf 1000000000000000000LL

// https://www.geeksforgeeks.org/painting-fence-algorithm/
// Fence Painting

//Tutorial - https://www.youtube.com/watch?v=_E5dTlV8-Ss&feature=emb_rel_pause

int32_t main()
{   ios_base::sync_with_stdio(false);
    cin.tie(NULL);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int packet, color;
    cin >> packet >> color;

    if (packet == 0)
        cout << 0;
    else if (packet == 1)
        cout << color;
    else if (packet == 2)
        cout << color + color*(color - 1);
    else {

        int same = color, different = color * (color - 1);
        for (int i = 3; i <= packet; i++) {
            same = different;
            different = (same + different) * (color - 1);
        }
        cout << same + different;
    }

    return 0;
}