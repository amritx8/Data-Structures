#include<bits/stdc++.h>
using namespace std;

// Heaps are complete binary tree

/** max heapify
* 	Time Complexity O(log n)
*	1 based indexing
*   Parent = a[i/2]
*	Left Child = a[2*i]
*	Right Child = a[2*i+1]
*	
*/
void MaxHeapify(vector<int> &a, int i, int n){
	int largest = i;
	int left = 2*i, right = 2*i+1;

	// check if the left and right subtrees are max heaps as well
	// if the left child needs to be swapped
	if(left<=n and a[left]>a[i]) largest=left;

	// if the right child needs to be swapped
	if(left<=n and a[right]>a[i]) largest=right;

	// if something needs to be swapped
	if(largest!=i){
		// send the parent to child's pos
		swap(a[i],a[largest]);

		// max heapify the child just swapped
		MaxHeapify(a,largest,n);
	}

}

void MinHeapify(vector<int> &a, int i, int n){
	int smallest = i;
	int left = 2*i, right = 2*i+1;

	// check if the left and right subtrees are Min heaps as well
	// if the left child needs to be swapped
	if(left<=n and a[left]<a[i]) smallest=left;

	// if the right child needs to be swapped
	if(left<=n and a[right]<a[i]) smallest=right;

	// if something needs to be swapped
	if(smallest!=i){
		// send the parent to child's pos
		swap(a[i],a[smallest]);

		// Min heapify the child just swapped
		MinHeapify(a,smallest,n);
	}

}

// O(n) complexity
/*
*	Looks like O(nlogn) but its not let's see
*	A heap of size n has at most n/(2^(h+1)) nodes with height h.
* 	solve Summation of n/(2^(h+1)) * O(h) with limits
*	get O(n)
*/
void buildHeap(vector<int>&a, int n){

	// we only apply this to non leaf nodes as the leaf nodes will automatically be swapped.
	// Total number of leaf nodes N/2 and internal nodes N/2
	for(int i = n/2;i>0 ;i--){
		MaxHeapify(a,i,n);
		// MinHeapify(a,i,n);
	}
}

// max priority queue implementation

// T.C - O(1)
// pq.top()
int maximum(vector<int> a){
	return a[1];
}
// T.C - O(log n)
// pq.pop()
int extractMax(vector<int> a, int n){
	if(a.empty()) return -1;

	// the top element is max
	int maxEle = a[1];

	// swap with the last element
	swap(a[1],a[n]);

	// remove the last element
	a.pop_back();

	// the swap has resulted in violation of max heap
	MaxHeapify(a,1,a.size());
	return maxEle;
}
// T.C - O(logn)
void increaseVal(vector<int> a, int i, int val){
	if(val<a[i]) return;
	// increase the val of the node to 'val' and then check if it got bigger than the parent or not
	a[i]=val;
	while(i>1 and a[i/2]<a[i]){
		swap(a[i/2],a[i]);
		i=i/2;
	}
}

// TC O(logn)
void insert_value (vector<int>&a, int val){
    int length = length + 1;
    a[ length ] = -1;  //assuming all the numbers greater than 0 are to be inserted in queue.
    increaseVal (a, length, val);
}

// custom comparator
struct Node {
 
    int prop1;
    int prop2;

};

// this is an strucure which implements the
// operator overloading
struct cmp{
    bool operator()(Node const& p1, Node const& p2)
    {
        // return "true" if "p1" is ordered
        // before "p2", for example:
	// so if it is true that means the swap will take place else it won't. Follow https://leetcode.com/problems/find-k-pairs-with-smallest-sums for more example
        return p1.prop1 < p2.prop1;
    }
};
int main(){
	priority_queue<int> maxpq ;// max heap
	priority_queue<int, vector<int>, greater<int>> minpq;// min heap

	priority_queue<Node, vector<Node>, cmp> Q; // custom pq


}
