#include<bits/stdc++.h>

using namespace std;

void buildTree(int arr[], int tree[], int start, int end, int index) {

    if(start == end) {

        tree[index] = arr[start];

        return;
    }

    int mid = (start + end) / 2;

    buildTree(arr, tree, start, mid, 2*index + 1);

    buildTree(arr, tree, mid + 1, end, 2*index + 2);

    tree[index] = tree[2*index + 1] + tree[2*index + 2];
}

int query(int arr[], int tree[], int start, int end, int index, int left, int right) {

    if(right < start or left > end) {

        return 0;
    } else if(start == left and end == right) {

        return tree[index];
    }

    int mid = (start + end) / 2;
    
    return query(arr, tree, start, mid, 2*index + 1, left, right) + query(arr, tree, mid + 1, end, 2*index + 2, left, right);
}

int main() {

    int n;
    cin >> n; 

    int arr[n], tree[5*n];

    for(int i=0; i<n; i++) {

        cin >> arr[i];
    }

    buildTree(arr, tree, 0, n - 1, 0);

    cout<<query(arr, tree, 0, n - 1, 0, 2, n - 1);

    return 0;
}