// heapify
// build Heap from arr
// heap sort

#include <bits/stdc++.h>
using namespace std;

void heapify(vector<int> &v, int n, int i)
{
    int leftInd = 2 * i;
    int rightInd = 2 * i + 1;
    int maxi = i;

    if (leftInd < n && v[maxi] < v[leftInd])
    {
        maxi = leftInd;
    }
    if (rightInd < n && v[maxi] < v[rightInd])
    {
        maxi = rightInd;
    }
    if (maxi != i)
    {
        swap(v[maxi], v[i]);
        heapify(v, n, maxi);
    }

    return;
}

void heapSort(vector<int> &v, int n)
{
    int size = n - 1;
    for (int i = size; i > 1; i--)
    {
        swap(v[i], v[1]);
        heapify(v, size--, 1);
    }
}

int main()
{

    vector<int> a = {0, 1, 2, 6, 7, 8, 9, 10, 3, 4, 5};

    int n = a.size();

    for (int i = n / 2; i >= 1; i--)
    {
        heapify(a, n, i);
    }

    heapSort(a, n);

    // Print the heapified array
    for (auto it : a)
    {
        cout << it << " ";
    }
    cout << endl;
    cout << endl;
}