#include<bits/stdc++.h>
using namespace std;
#define N 100005
vector<int> bit(N);

/* Better understanding https://www.youtube.com/watch?v=DPiY9wFxGIw
*  Use one based indexing in BIT otherwise the update function
*  will get stuck in an infinite loop
*  Space Complexity O(n)
*  (x&-x) gives us the right most set bit. x-(x&-x) removes the
*  rightmost set bit from the number
*  The BIT array element stores sum between j+1 and i
*  where j = removed the rightmost setbit = i-(i&-i)

*/


// Caution: the update function adds x to the ith index.
// We find those indexes which have i in the range after removing
// the right most set bit and add x to those indices.
void update(int i, int x){
	for(; i < N; i += (i&-i))
		bit[i] += x;
}



/* O(log n)
	Explanation. Every time we remove the rightmost set bit
	this gives us the idea that the for loop will run at most
	log n times.

	Eg. sum(13)
	13 = 1101 : Stores sum of 13-13
	12 = 1100 : Stores sum of 9-12
	8 =  1000 : Stores sum of 1-8
	0 = 0000 (End)

	In total we get the sum from 1-13
*/

int sum(int i){
	int ans = 0;
	for(; i > 0; i -= (i&-i))
		ans += bit[i];
	return ans;
}

int main(){
	bit.assign(N,0);

	// 1 based indexing;
	int n; cin>>n;
	vector<int> a(n);
	for (int i = 0; i < n; ++i)
	{
		cin>>a[i];
	}

	// make the bit array in the following manner

	for (int i = 1; i <= n; ++i)
	{
		/* code */
		update(i,a[i-1]);
	}

	// continue here.
}