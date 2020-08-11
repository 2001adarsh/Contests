#include<bits/stdc++.h>
using namespace std;
#define nn 100005
int r, n, q;
int tree[nn << 2][2][2] , a[nn][2][2];
void multiply(int a[2][2] , int b[2][2] , int res[2][2]) {
  res[0][0] = (a[0][0] * b[0][0] + a[0][1] * b[1][0]) % r;
  res[0][1] = (a[0][0] * b[0][1] + a[0][1] * b[1][1]) % r;
  res[1][0] = (a[1][0] * b[0][0] + a[1][1] * b[1][0]) % r;
  res[1][1] = (a[1][0] * b[0][1] + a[1][1] * b[1][1]) % r;
}
void build(int node , int start  , int end) {
  if (start == end) {
    for (int i = 0 ; i < 2 ; i++) {
      for (int j = 0 ; j < 2 ; j++) {
        tree[node][i][j] = a[start][i][j];
      }
    }
    return;
  }
  int mid = (start + end) / 2;
  build(2 * node , start , mid);
  build(2 * node + 1  , mid + 1 , end);
  multiply(tree[2 * node] , tree[2 * node + 1], tree[node]);
}
void query(int node , int start , int end , int u , int v  , int ans[2][2]) {
  if (start > end || u > end || start > v)
    return;
  if (u <= start && end <= v)
  {
    for (int i = 0; i < 2; i++)
      for (int j = 0; j < 2; j++)
        ans[i][j] = tree[node][i][j];
    return;
  }
  int mid = (start + end) / 2;
  int r1[2][2] = {{1, 0}, {0, 1}}, r2[2][2] = {{1, 0}, {0, 1}};
  query(node * 2, start, mid, u, v, r1);
  query(node * 2 + 1, mid + 1, end, u, v, r2);
  multiply(r1, r2, ans);
}
int main() {
  cin >> r >> n >> q;
  int mat[2][2];
  for (int i = 0 ; i < n ; i++) {
    for (int j = 0 ; j < 2 ; j++) {
      for (int k = 0 ; k < 2 ; k++) {
        cin >> a[i][j][k];
      }
    }
  }
  build(1 , 0  , n - 1);
  while (q--) {
    int x , y;
    cin >> x >> y;
    int ans[2][2] = {{1 , 0} , {0 , 1}};
    query(1 , 0 , n - 1 , x - 1 , y - 1  , ans);
    for (int j = 0; j < 2; j++)
    {
      for (int k = 0; k < 2; k++)
      {
        cout << ans[j][k] << ' ';
      }
      cout << endl;
    }
    cout << endl;
  }
  return 0;
}