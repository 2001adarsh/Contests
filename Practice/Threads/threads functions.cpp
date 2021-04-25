#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define endl    "\n"
#define mod 1000000007
#define inf 1e18


int32_t main()
{   ios_base::sync_with_stdio(false);
    cin.tie(NULL);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    cout << boolalpha << endl;

    cout << "hardware_concurrency()= " << thread::hardware_concurrency() << endl;

    thread t1([] {cout << "t1 with id= " << this_thread::get_id() << endl;});
    thread t2([] {cout << "t2 with id= " << this_thread::get_id() << endl;});

    cout << endl;

    cout << "FROM MAIN: id of t1 " << t1.get_id() << endl;
    cout << "FROM MAIN: id of t2 " << t2.get_id() << endl;

    cout << endl;
    swap(t1, t2);

    cout << "FROM MAIN: id of t1 " << t1.get_id() << endl;
    cout << "FROM MAIN: id of t2 " << t2.get_id() << endl;

    cout << endl;

    cout << "FROM MAIN: id of main= " << this_thread::get_id() << endl;

    cout << endl;

    cout << "t1.joinable(): " << t1.joinable() << endl;

    cout << endl;

    t1.join();
    t2.join();

    cout << endl;

    cout << "t1.joinable(): " << t1.joinable() << endl;

    cout << endl;

    return 0;
}