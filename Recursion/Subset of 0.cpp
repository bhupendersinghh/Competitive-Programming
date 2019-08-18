/**************
* AUTHOR : BHUPENDER SINGH *
* INSTITUTION : DELHI TECHNOLOGICAL UNIVERSITY *
**************/

/*
    Given an array find the sum of all the prime factors of the elements in the array.
    Now suppose there are n zeroes, where n is equal to the sum we calculated. We divide those n zeroes into k parts.
    Find the number of ways % (10^9 + 7) in which this can be achieved.

    INPUT:
        First Line: k -> Number of parts to divide in
        Second Line: n -> Length of array
        Third Line: Array elements
*/

#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define rep(i, n) for(int i = 0; i < n; i++)
#define REP(i,a,b) for(int i = a; i < b; i++)
#define rep1(i,b) for(int i = 1; i <= b ; i++)
#define pb push_back
#define mp make_pair
#define clr(x) x.clear()
#define F first
#define S second

void numberOfWays(int n, int m, int &ways) {
	if(n == 0 || m == 1) {
	    ways = (ways + 1)% 1000000007;
	    return;
	}
	if(n == 1) {
	    ways = (ways + m) % 1000000007;
	    return;
	}
	for(int i = 0; i <= n; i++) {
	    numberOfWays(n - i, m - 1, ways);
	}
}

int main() {
	bool prime[10001];
	memset(prime, true, sizeof(prime));
	for(int p = 2; p * p <= 10001; p++) {
		if(prime[p]) {
			for(int i = p * p; i <= 10001; i += p) {
				prime[i] = false;
			}
		}
	}
	int k, n;
	cin>>k>>n;
	int arr[n];
	rep(i, n) {
		cin>>arr[i];
	}
	int sumOfPrimeFactors = 0;
	rep(i, n) {
		for(int j = 2; j <= (arr[i] / 2) + 1; j++) {
			if(prime[j]) {
				sumOfPrimeFactors += j;
			}
		}
	}
	int ways = 0;
	numberOfWays(sumOfPrimeFactors, k, ways);
	cout<<ways;
	return 0;
}