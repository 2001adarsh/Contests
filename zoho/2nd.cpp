#include<bits/stdc++.h>
using namespace std;
#define int long long int



int32_t main()
{

    int n;  //length of array is inputed.
    cin >> n;

    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int cars; //no of cars to accomodate.
    cin >> cars;

    for (int i = 1; i < n - 1; i++) {
        if (arr[i] == 1) continue;
        if (arr[i - 1] == 0 and arr[i + 1] == 0)
            arr[i] = 1, cars--;
    }

    if (arr[0] == 0 and arr[1] == 0)
        cars--, arr[0] = 1;
    if (arr[n - 1] == 0 and arr[n - 2] == 0)
        cars--, arr[n - 1] = 1;


    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;

    if (cars <= 0)
        cout << "true";
    else
        cout << "false";


    return 0;
}