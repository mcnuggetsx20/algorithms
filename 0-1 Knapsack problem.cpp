#include <bits/stdc++.h>
using namespace std;

#define boost ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define all(c) c.begin(), c.end()
#define nln cout << "\n";

typedef signed long long sll;
typedef unsigned long long ll;

const int E = 1e5 + 1;
const int mxn = 1e9;

ll w[100], v[100], dp[101][E];

void solve(){
	int n , W;
	cin >> n >> W;
	for(int i = 0; i < n; ++i){
		cin >> w[i] >> v[i];
	}	
	for(int i = 0; i <= n; ++i){
		for(int j = 0; j <= W; ++j){
			if(i * j == 0){
				dp[i][j] = 0;
			}
			else{
				if(j >= w[i - 1]){
					dp[i][j] = max(dp[i-1][j], v[i-1] + dp[i-1][j-w[i-1]]);
				}
				else{
					dp[i][j] = dp[i-1][j];
				}
			}
		}
	}
	cout << dp[n][W];
}

int main(){
	boost;
	int t = 1;
	//cin >> t;
	while(t--){
		solve();
	}
}
