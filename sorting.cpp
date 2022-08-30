#include <bits/stdc++.h>
#include "sorting.hpp"
using namespace std;

template <class Item>
void merge(LinearList<Item> &a, int low, int mid, int high)
{

    int i, j, k;
    int n1 = mid - low + 1;
    int n2 = high - mid;

    Item LeftArray[n1], RightArray[n2];

    /* copy data to temp arrays */
    for (int i = 0; i < n1; i++)
        LeftArray[i] = a[low + i];
    for (int j = 0; j < n2; j++)
        RightArray[j] = a[mid + 1 + j];

    i = 0,
    j = 0;
    k = low;

    while (i < n1 && j < n2)
    {
        if (LeftArray[i] <= RightArray[j])
        {
            a[k] = LeftArray[i];
            i++;
        }
        else
        {
            a[k] = RightArray[j];
            j++;
        }
        k++;
    }
    while (i < n1)
    {
        a[k] = LeftArray[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        a[k] = RightArray[j];
        j++;
        k++;
    }
}

template <class Item>
int partition(LinearList<Item> &arr, int start, int end)
{

    int pivot = arr[start];

    int count = 0;
    for (int i = start + 1; i <= end; i++)
    {
        if (arr[i] <= pivot)
            count++;
    }

    // Giving pivot element its correct position
    int pivotIndex = start + count;
    swap(arr[pivotIndex], arr[start]);

    // Sorting left and right parts of the pivot element
    int i = start, j = end;

    while (i < pivotIndex && j > pivotIndex)
    {

        while (arr[i] <= pivot)
        {
            i++;
        }

        while (arr[j] > pivot)
        {
            j--;
        }

        if (i < pivotIndex && j > pivotIndex)
        {
            swap(arr[i++], arr[j--]);
        }
    }

    return pivotIndex;
}

template <class Item>
void Sort<Item>::insertionSort(LinearList<Item> &A, int low, int high)
{
    int el, j;
    for (int i = 1; i < high; i++)
    {
        el = A[i];
        j = i - 1;
        while (j >= 0 && A[j] > el)
        {
            A[j + 1] = A[j];
            j = j - 1;
        }
        A[j + 1] = el;
    }
}

template <class Item>
void Sort<Item>::mergeSort(LinearList<Item> &A, int low, int high)
{
    if (low >= high)
        return;
    int mid = low + (high - low) / 2;
    mergeSort(A, low, mid);
    mergeSort(A, mid + 1, high - 1);
    merge(A, low, mid, high - 1);
}

template <class Item>
void Sort<Item>::quickSort(LinearList<Item> &A, int low, int high)
{
    if (low >= high)
        return;
    int pivot = partition(A, low, high - 1);
    quickSort(A, low, pivot - 1);
    quickSort(A, pivot + 1, high - 1);
}
