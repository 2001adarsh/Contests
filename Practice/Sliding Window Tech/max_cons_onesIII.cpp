#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define endl    "\n"
#define inf 1000000000000000000ll

/*
Given an array A of 0s and 1s, we may change up to K values from 0 to 1.

Return the length of the longest (contiguous) subarray that contains only 1s.

Input: A = [1,1,1,0,0,0,1,1,1,1,0], K = 2
Output: 6
Explanation:
[1,1,1,0,0,1,1,1,1,1,1]
Bolded numbers were flipped from 0 to 1.  The longest subarray is underlined.
*/

int longestOnes(vector<int>& A, int K) {
    int Zcnt = 0;
    int end = 0, start = 0, ans = INT_MIN;

    for (end = 0; end < A.size(); end++) {
        if (A[end] == 0)
            Zcnt++;
        while (Zcnt > K) {
            if (A[start] == 0)
                Zcnt--;
            start++;
        }
        ans = max(ans, end - start + 1);
    }
    return ans;
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
    std::vector<int> A(n);
    for (int i = 0; i < n; i++)
        cin >> A[i];
    int K;
    cin >> K;
    cout << longestOnes(A, K);
    return 0;
}