#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define endl    "\n"
#define mod 1000000007
#define inf 1e18
//-> Never double join, will throw system error.
//-> if needed we can check thread is joinable before joining using (joinable() function)
//-> detach() use to detach the newly created thread form the parent thread.

void run(int x) {
    while (x--)
        cout << x << " ";
    this_thread::sleep_for(chrono::seconds(1));
    cout << endl;
}

int32_t main()
{   ios_base::sync_with_stdio(false);
    cin.tie(NULL);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    thread t1(run, 5);
    cout << "main()\n";
    // t1.join();

    t1.detach(); //will detach the thread form the main() thread.

    if (t1.joinable()) { //this will return false
        t1.join();
        cout << "second time joined";
    }

    cout << "main after()\n";

    return 0;
}