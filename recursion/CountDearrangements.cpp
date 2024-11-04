
#include <iostream>
#include<vector>
using namespace std;
// count derrangments
int solve(int n) {

	//base case
	if(n == 1) {
		return 0;
	}
	if(n == 2) {
		return 1;
	}

	int ans = (n-1) * (solve(n-1) + solve(n-2));
	return ans;
}
// visualalgo.net
if(n==1) return 0;
if(n==2) return 1;
else{
return (n-1)*(f(n-1) + f(n-2));
}
