#include <bits/stdc++.h>
using namespace std;

int Parent[100001], Size[100001], Rank[100001];

void makeRoot(int v)
{
    Parent[v] = v;
    Size[v] = 1;
    Rank[v] = 1;
}

int findRoot(int v)
{
    if (v == Parent[v])
    {
        return v;
    }

    int root = findRoot(Parent[v]);

    // Path compression
    // Change the parent of current node to root.
    Parent[v] = root;

    return root;
}

void unionRoots(int a, int b)
{
    int r1 = findRoot(a);
    int r2 = findRoot(b);

    if (r1 != r2)
    {
        // Union by rank
        // Attach the tree with the lower rank to
        // the one with the bigger rank.
        if(Rank[r1] >= Rank[r2])
        {
            Parent[r2] = r1;

            if(Rank[r1] == Rank[r2])
            {
                Rank[r1]++;
            }
        }
        else
        {
            Parent[r1] = r2;
        }

        // Union by size
        // Attach the tree with the smaller size to
        // the one with the larger size.
        if (Size[r1] >= Size[r2])
        {
            Parent[r2] = r1;
            Size[r1] += Size[r2];
        }
        else
        {
            Parent[r1] = r2;
            Size[r2] += Size[r1];
        }
    }
}

int main()
{

    memset(Parent, -1, sizeof(Parent));
    memset(Size, 0, sizeof(Size));
    memset(Size, 0, sizeof(Rank));

    return 0;
}