#include "seqLinearList.hpp"

template <class Item>
LinearList<Item>::LinearList()
{
    element = new Item[0];
    MaxSize = 0;
    len = 0;
}
template <class Item>
LinearList<Item>::LinearList(const int &MaxListSize)
{
    element = new Item[MaxListSize];
    MaxSize = MaxListSize;
    len = 0;
}

template <class Item>
LinearList<Item>::~LinearList()
{
    delete[] element;
}

template <class Item>
Item &LinearList<Item>::operator[](const int &i)
{
    if (i < 0 || i > len)
    {
        throw std::out_of_range("IndexOutOfBound exception occured\n");
    }
    return element[i];
}

template <class Item>
bool LinearList<Item>::isEmpty()
{
    return len == 0;
}

template <class Item>
int LinearList<Item>::length()
{
    return len;
}

template <class Item>
int LinearList<Item>::maxSize()
{
    return MaxSize;
}

template <class Item>
Item LinearList<Item>::returnListElement(const int k)
{
    return this->operator[](k);
}

template <class Item>
int LinearList<Item>::search(Item &x)
{
    for (int i = 0; i < len; i++)
    {
        if (this->operator[](i) == x)
            return i + 1;
    }
    return 0;
}
template <class Item>
bool LinearList<Item>::find(const int k, Item &x)
{
    if (this->operator[](k) == x)
        return true;
    else
        return false;
}

template <class Item> // deletes the kth element. Follows 1-based indexing
void LinearList<Item>::deleteElement(const int k)
{ // ask for const
    if (len == 0)
    { // Underflow check
        cout << "Underflow...list is empty\n";
        return;
    }
    for (int i = k - 1; i < len; i++)
        this->operator[](i) = this->operator[](i + 1);
    len--;
}

template <class Item>
void LinearList<Item>::insert(const int k, const Item &x)
{ // insert element at idx k
    if (len == MaxSize)
    { // Overflow check
        cout << "Overflow..can not insert\n";
        return;
    }
    // if(k>len){
    //     cout<<"Given index greater than current list length of "<<len<<". Can not insert\n";
    //     return;
    // }
    for (int i = len; i > k; i--)
        this->operator[](i) = this->operator[](i - 1);
    this->operator[](k) = x;
    len++;
}
