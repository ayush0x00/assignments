#include <bits/stdc++.h>
#include "seqLinearList.cpp"
#include "sorting.cpp"
using namespace std;

template <class Item>
void printList(LinearList<Item> &a)
{
    for (int i = 0; i < a.length(); i++)
        cout << a[i] << " ";
    cout << "\n";
    return;
}

int main()
{
    // if asked for position please use 1-based indexing, for index use 0-based indexing
    int n;
    int el;
    cout << "Enter the max list size\n";
    cin >> n;
    LinearList<int> test(n);
    Sort<int> sortOpt;
    cout << "List operations\n";
    bool flag = true;
    while (flag)
    {
        int opt;
        cout << "------------------------\n";
        cout << " 1. Insert\n 2. Delete\n 3. Find\n 4. Search\n 5. PrintList\n 6. InsertionSort\n 7. QuickSort\n 8. MergeSort\n 0. Exit\n";
        cout << "------------------------\n";
        cin >> opt;
        try
        {
            switch (opt)
            {
                int idx, ele, pos;
            case 1:
                cout << "Enter index\n";
                cin >> idx;
                cout << "Enter element\n";
                cin >> ele;
                test.insert(idx, ele);
                break;
            case 2:
                cout << "Enter position of element to delete\n";
                cin >> pos;
                test.deleteElement(pos);
                break;
            case 3:
                cout << "Enter index\n";
                cin >> idx;
                cout << "Enter element\n";
                cin >> ele;
                pos = test.find(idx, ele);
                if (pos == 0)
                    cout << "Element not found";
                else
                    cout << "Element found at pos " << pos << "\n";
                break;
            case 4:
                cout << "Enter element to search\n";
                cin >> ele;
                pos = test.search(ele);
                if (pos == 0)
                    cout << "Element not found";
                else
                    cout << "Element found at pos " << pos << "\n";
                break;
            case 5:
                printList(test);
                break;
            case 6:
                sortOpt.insertionSort(test, 0, test.length());
                printList(test);
                break;
            case 7:
                sortOpt.quickSort(test, 0, test.length() - 1);
                printList(test);
                break;
            case 8:
                sortOpt.mergeSort(test, 0, test.length());
                printList(test);
                break;
            case 0:
                flag = false;
                break;
            default:
                cout << "Enter valid option\n";
                break;
            }
        }
        catch (std::out_of_range &exception)
        {
            cout << exception.what() << "\n";
            continue;
        }
    }
}