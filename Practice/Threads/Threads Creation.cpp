#include<thread> //inside bits
#include<bits/stdc++.h>
using namespace std;

#define int long long int
#define endl    "\n"
#define mod 1000000007
#define inf 1e18

using namespace std::chrono;

// MultiThreading in C++.

/*
1. Function Pointers
2. Lambda Functions
3. Functors
4. Member Functions
5. Static Member Functions
*/
int oddSum = 0;
void findOdd(int start, int end) {
    for (int i = start; i <= end; i++)
        if (i & 1)
            oddSum += i;
}
int evenSum = 0;
void findEven(int start, int end) {
    for (int i = start; i <= end; i++)
        if ((i & 1) == 0)
            evenSum += i;
}

class Base
{
public:
    void operator()(int x) {
        while (x-- > 0)
            cout << x << " ";
        cout << endl;
    }
    void run(int x) {
        while (x-- > 0)
            cout << x << " ";
        cout << endl;
    }
    static void runAgain(int x) {
        while (x-- > 0)
            cout << x << " ";
        cout << endl;
    }
};

int32_t main()
{   ios_base::sync_with_stdio(false);
    cin.tie(NULL);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int start = 0, end = 1900000;

    auto startTime = high_resolution_clock::now(); //chrono

    thread t1(findEven, start, end);
    thread t2(findOdd, start, end);

    t1.join();
    t2.join();

    // findOdd(start, end);
    // findEven(start, end);

    auto stopTime = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stopTime - startTime);

    cout << "Odd Sum: " << oddSum << endl;
    cout << "Even Sum: " << evenSum << endl;

    cout << "seconds took: " << duration.count() / 1000000 << endl;


    //Method 2 : using Lambda's
    auto fun = [](int x) {
        while (x-- > 0)
            cout << x << " ";
        cout << endl;
    };

    thread t3(fun, 10);
    t3.join();


    //Method 3: using thread itself
    thread t4([](int x) {
        while (x-- > 0)
            cout << x << " ";
        cout << endl;
    }, 5);
    t4.join();

    //Method 4: Functor (Function Object)
    thread t5(Base(), 5);
    t5.join();

    //Method 5: Non-static member function of a class
    Base b;
    //passing the address.
    thread t6(&Base::run, &b, 4);
    t6.join();


    //Method 6: Static member functions.
    thread t7(&Base::runAgain, 4);
    t7.join();

    return 0;
}