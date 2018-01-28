//
// Created by lhd on 18-1-28.
//
#include <iostream>
#include <stack>
#include <queue>

#include <algorithm>
using namespace std;

void adjust(int arr[],int len,int index)
{
    int left=2*index+1;
    int right=2*index+2;
    int maxIdx =index;
    if(left<len && arr[left] > arr[maxIdx]) maxIdx=left;
    if(right<len && arr[right] > arr[maxIdx]) maxIdx=right;
    if(maxIdx != index)
    {
        swap(arr[maxIdx],arr[index]);
        adjust(arr,len,maxIdx);
    }
}

void present(int arr[],int length)
{
    for(int i=0;i<length;i++)
        cout<<*(arr+i)<<" ";
}

void headSort(int arr[],int size)
{
    for(int i=size/2-1;i>=0;i--)
    {
        adjust(arr,size,i);
    }
    for(int i=size-1;i>=1;i--)
    {
        swap(arr[0],arr[i]);
        adjust(arr,i,0);
    }
}



int main()
{
    int array[13]={8,1,14,3,21,5,7,10,7,4,2,1,8};
    cout<<*begin(array)<<endl;
    headSort(array,13);
    for(auto item:array)
    {
        cout<<item<<endl;
    }
//    cout<<a[1]<<a[2]<<endl;
    return 0;
}
