int getPaintWays(int n, int k ) {
	//base case
	if(n == 1) {
		return k;
	}
	if(n == 2) {
		return k + k*(k-1);
	}

	int ans = (k-1) * (getPaintWays(n-1,k) + getPaintWays(n-2,k));
	return ans;
}

int main() {

	// int n = 4;
	// cout << solve(n) << endl;


	int n = 3;
	int k = 3;
	int ans = getPaintWays(n,k);
	cout << ans << endl;
	return 0;
}
//visual
if (n == 1) /* base case */
  return k;
if(n==2) return k+k*(k-1);
else /* recursive case */
  return (k-1)*(f(n-1, k) + f(n-2, k));