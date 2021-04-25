#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define endl    "\n"
#define mod 1000000007
#define inf 1e18
// Mutex : Mutual Exclusion
/*
    Race Condition:
    1. Race condition is a situation where two or more threads/process happen to change a common data at same time.
    2. If there is a race condition then we have to protect it and protection section is called critical section/region.

    Mutex: We use lock() unlock() on mutex to avoid race condition.
*/

mutex mg;

int counter = 0;
void run(int id) {
    mg.lock();
    if (mg.try_lock()) { //will return false if already locked else will lock it, and run the if block
        cout << "Counter before " << id << " : " << counter << endl;
        counter++;
        cout << "Counter after " << id << " : " << counter << endl;
        mg.unlock();
    } else {
        counter = 12;
        mg.unlock();
    }
}


/*
    try_lock(m1, m2, m3...) tries to lock all the lockable objects
    returns -1 for success else 0-based index of mutex where it failed.
*/
mutex m1, m2;
int X = 0, Y = 0;
void incXY(int &XY, mutex& m, string s) {
    for (int i = 0; i < 5; i++) {
        m.lock();
        ++XY;
        cout << s << " " << XY << endl;
        m.unlock();
        this_thread::sleep_for(chrono::seconds(1));
    }
}

void consumeXY() {
    int times = 5;
    int X = 0, Y = 0, XY = 0;
    while (1) {
        int lockedResult = try_lock(m1, m2);
        if (lockedResult == -1) {
            if (X != 0 and Y != 0) {
                times--;
                XY += X + Y;
                X = 0;
                Y = 0;
                cout << "XY: " << XY << endl;
            }
            m2.unlock();
            m1.unlock();
            if (times == 0)
                break;
        }
    }
}

recursive_mutex mut;
int a = 0;
void A() {
    mut.lock();
    a++;
    cout << "A";
    cout << a << endl;
    mut.unlock();
}

int b = 0;
void B() {
    mut.lock();
    b++;
    cout << "B";
    cout << b << endl;
    mut.unlock();
}
void C() {
    mut.lock();
    cout << "C";
    B();
    cout << a + b << endl;
    mut.unlock();
}

int32_t main()
{   ios_base::sync_with_stdio(false);
    cin.tie(NULL);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    //since both the threads use common global variable, hence the data can be inconsitent.
    thread t1(run, 1);
    thread t2(run, 2);

    t1.join();
    t2.join();
    cout << counter;

    thread t3(incXY, std::ref(X), ref(m1), "X");
    thread t4(incXY, std::ref(Y), ref(m2), "Y");
    thread t5(consumeXY);

    t3.join();
    t4.join();
    t5.join();


    return 0;
}