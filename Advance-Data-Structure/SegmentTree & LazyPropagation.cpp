#include<bits/stdc++.h>
using namespace std;

// Range sum query and range update segment tree.

const int MX = 100000;
int arr[MX], tree[4 * MX];

void buildTree(int at, int start, int end) {

    if(start == end) {

        tree[at] = arr[start];

        return;
    }

    int mid = (start + end) / 2;
    int leftChild = 2 * at + 1;
    int rightChild = 2 * at + 2;

    // Recursively built left and right children.
    buildTree(leftChild, start, mid);

    buildTree(rightChild, mid + 1, end);

    // This line denoted the type of query in segment tree.
    tree[at] = tree[leftChild] + tree[rightChild];
}

// Here, l and r are the actual range you have to answer. They remain same
// throughout the function.
int query(int at, int start, int end, int l, int r) {

    if(r < start or l > end) {

        return 0;
    } else if(start == l and end == r) {

        return tree[at];
    }

    int mid = (start + end) / 2;
    int leftChild = 2 * at + 1;
    int rightChild = 2 * at + 2;
    
    return query(leftChild, start, mid, l, r) + query(rightChild, mid + 1, end, l, r);
}

int main() {

    int n;
    cin >> n;

    for(int i=0; i<n; i++) {

        cin >> arr[i];
    }

    buildTree(0, 0, n - 1);
    
    int l, r;
    cin >> l >> r;

    cout << query(0, 0, n - 1, l, r);

    return 0;
}