#include "seqLinearList.hpp"

template <class Item>
LinearList<Item>::LinearList(){
    element = new Item[0];
    MaxSize = 0;
    len = 0;
}
template <class Item>
LinearList<Item>::LinearList(const int& MaxListSize){
    element = new Item[MaxListSize];
    MaxSize = MaxListSize;
    len = 0;
}

template <class Item>
LinearList<Item>::~LinearList(){
    delete [] element;
}

template<class Item>
Item& LinearList<Item>::operator[](const int& i){
    return element[i];
}

template<class Item>
bool LinearList<Item>::isEmpty(){
    return len==0;
}

template<class Item>
int LinearList<Item>::length(){
    return len;
}

template<class Item>
int LinearList<Item>::maxSize(){
    return MaxSize;
}

template<class Item>
Item LinearList<Item>::returnListElement(const int k){
    return element[k];
}

template<class Item>
int LinearList<Item>::  search(Item& x){
    for(int i=0;i<len;i++){
        if(element[i]==x) return i+1;
    }
    return 0;
}
template <class Item>
bool LinearList<Item>:: find(const int k, Item& x){
    if (element[k] == x) return true;
    else return false;
}

template<class Item>
void LinearList<Item>:: deleteElement(const int k, const Item& x){ //ask for const
    for(int i=k-1; i<len;i++) element[i]=element[i+1];
    len--;
}

template <class Item>
void LinearList<Item>:: insert(const int k, const Item& x){
    for(int i=len;i>k;i--) element[i]=element[i-1];
    element[k]=x;
    len++;
}
