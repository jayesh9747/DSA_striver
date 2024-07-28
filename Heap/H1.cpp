// creation of heaps
// insert value in heaps
// delete value from heaps

#include <bits/stdc++.h>
using namespace std;

class Heap
{

public:
    vector<int> v;
    int size;

    Heap()
    {
        v.push_back(-1);
        size = 0;
    }

    void insertINTOheap(int t)
    {
        v.push_back(t);
        size++;
        int i = size;

        // Yaha pe galti hui thi dhayan rakho is chij ka

        while (i > 1)
        {
            if (v[i] > v[i / 2])
            {
                swap(v[i], v[i / 2]);
                i = i / 2;
            }
            else
            {
                break;
            }
        }
    }

    // yad rakho ki hamesha first node delete hota hai
    void DeleteNodeFromHeap()
    {
        if (v.size() < 1)
            cout << "underFlow" << endl;

        swap(v[1], v.back());

        v.pop_back();

        int i = 1;
        while (i < v.size())
        {

            int large = i;
            int left = 2 * i;
            int right = 2 * i + 1;

            if (left < v.size() && v[large] < v[left])
            {
                large = 2 * i;
            }
            if (right < v.size() && v[large] < v[right])
            {
                large = (2 * i) + 1;
            }
            if (large != i)
            {
                swap(v[i], v[large]);
                i = large;
            }
            else
            {
                break;
            }
        }
    }

    void printV()
    {

        for (int i = 1; i < v.size(); i++)
        {
            cout << v[i] << " ";
        }
        cout << endl;
    }
};

int main()
{

    Heap *a = new Heap();

    a->insertINTOheap(1);
    a->insertINTOheap(2);
    a->insertINTOheap(3);
    a->insertINTOheap(4);
    a->insertINTOheap(5);
    a->DeleteNodeFromHeap();

    a->printV();
}