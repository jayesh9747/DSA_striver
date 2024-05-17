#include <bits/stdc++.h>
using namespace std;

class TwoStackInArray
{
public:
    int top1, top2;
    int *arr;
    int size;

    TwoStackInArray(int size)
    {
        arr = new int[size];
        this->size = size;
        top1 = -1;
        top2 = size;
    }

    void Push1(int t)
    {
        if (((top2 - top1) == 1 )|| (top1 >= size - 1))
        {
            cout << "Stack is full" << endl;
        }
        else
        {
            top1++;
            arr[top1] = t;
        }
    }

    void Push2(int t)
    {
        if (((top2 - top1) == 1 )||( top2 <= 0))
        {
            cout << "Stack is full" << endl;
        }
        else
        {
            top2--;
            arr[top2] = t;
        }
    }

    void Pop1()
    {
        if (top1 == -1)
        {
            cout << "Stack is empty" << endl;
        }
        else
        {
            top1--;
        }
    }

    void Pop2()
    {
        if (top2 == size)
        {
            cout << "Stack is empty" << endl;
        }
        else
        {
            top2++;
        }
    }

    void print()
    {
        cout << endl;
        cout << arr[top1] << endl;
        cout << arr[top2] << endl;

        for (int i = 0; i < size; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main()
{

    TwoStackInArray s(10);

    // s.print();
    s.Push1(10);
    s.Push1(20);
    s.Push1(30);
    s.Push1(40);
    s.Push1(60);

    s.Push2(30);
    s.Push2(40);
    s.Push2(20);
    s.Push2(50);
    s.Push2(50);
    s.Push2(50);
    s.Push2(50);

    s.print();
}