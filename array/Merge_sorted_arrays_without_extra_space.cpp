#include <bits/stdc++.h>
using namespace std;

//***********
//  Brute force code

//  void merge(long long arr1[], long long arr2[], int n, int m){
//     long long arr3[n+m];
//     int left =0;
//     int right =0;
//     int index =0;

//     while(left<n && right<m){
//         if(arr1[left] <= arr2[right]){
//             arr3[index] = arr1[left];
//             left++, index++;
//         }
//         else{
//              arr3[index] = arr2[right];
//             right++, index++;
//         }
//     }
//     while(left< n){
//         arr3[index++] = arr1[left++];
//     }
//     while(right< m){
//         arr3[index++] = arr2[right++];
//     }

//     for(int i=0; i<n+m; i++){
//         if(i<n){
//             arr1[i] = arr3[i];
//         }
//         else{
//             arr2[i-n] = arr3[i];
//         }
//     }
//  }

// int main(){
//     long long arr1[] = {1,5,6,7,8};
// 	long long arr2[] = {2,3,4};
//     cout<<"Before merge:"<<endl;
//     for (int i = 0; i < 5; i++) {
//       cout<<arr1[i]<<" ";
//     }
//     cout<<endl;
//     for (int i = 0; i < 3; i++) {
//       cout<<arr2[i]<<" ";
//     }
//     cout<<endl;

//     //now form here merge
//     merge(arr1, arr2, 5, 3);
//     cout<<"After merge:"<<endl;
//     for (int i = 0; i <5; i++) {
//       cout<<arr1[i]<<" ";
//     }
//     cout<<endl;
//     for (int i = 0; i < 3; i++) {
//       cout<<arr2[i]<<" ";
//     }

//   return 0;
// }

//*************** OPTIMAL CODE 1  --- 2 Pointer approach

// void merge(long long arr1[], long long arr2[], int n, int m){
//     int left = n-1;
//     int right =0;
//     while(left>=0 && right<m){
//         if(arr1[left] >arr2[right]){
//             swap(arr1[left], arr2[right]);
//             left--, right++;
//         }
//         else{
//             break;
//         }
//     }
//     sort(arr1, arr1+n);
//     sort(arr2, arr2+m);
// }

// int main(){

//     long long arr1[] = {1,5,6,7,8};
// 	long long arr2[] = {2,3,4};
//     cout<<"Before merge:"<<endl;
//     for (int i = 0; i < 5; i++) {
//       cout<<arr1[i]<<" ";
//     }
//     cout<<endl;
//     for (int i = 0; i < 3; i++) {
//       cout<<arr2[i]<<" ";
//     }
//     cout<<endl;

//     //now form here merge
//     merge(arr1, arr2, 5, 3);
//     cout<<"After merge:"<<endl;
//     for (int i = 0; i <5; i++) {
//       cout<<arr1[i]<<" ";
//     }
//     cout<<endl;
//     for (int i = 0; i < 3; i++) {
//       cout<<arr2[i]<<" ";
//     }

//   return 0;
// }

//***********OPTIMAL CODE 2   -- using GAP METHOD

void swapIfGreater(long long arr1[], long long arr2[], int ind1, int ind2)
{
    if (arr1[ind1] > arr2[ind2])
    {
        swap(arr1[ind1], arr2[ind2]);
    }
}

void merge(long long arr1[], long long arr2[], int n, int m)
{
    int len = (n + m);
    int gap = (len / 2) + (len % 2);
    while (gap > 0)
    {
        int left = 0;
        int right = left + gap;
        while (right < len)
        {
            // arr1 and arr2
            if (left < n && right >= n)
            {
                swapIfGreater(arr1, arr2, left, right - n);
            }
            // arr2 and arr2
            else if (left >= n)
            {
                swapIfGreater(arr2, arr2, left - n, right - n);
            }
            // arr1 and arr1
            else
            {
                swapIfGreater(arr1, arr1, left, right);
            }
            left++, right++;
        }
        if (gap == 1)
        {
            break;
        }
        gap = (gap / 2) + (gap % 2);
    }
}

int main()
{

    long long arr1[] = {1, 5, 6, 7, 8};
    long long arr2[] = {2, 3, 4};
    cout << "Before merge:" << endl;
    for (int i = 0; i < 5; i++)
    {
        cout << arr1[i] << " ";
    }
    cout << endl;
    for (int i = 0; i < 3; i++)
    {
        cout << arr2[i] << " ";
    }
    cout << endl;

    // now form here merge
    merge(arr1, arr2, 5, 3);
    cout << "After merge:" << endl;
    for (int i = 0; i < 5; i++)
    {
        cout << arr1[i] << " ";
    }
    cout << endl;
    for (int i = 0; i < 3; i++)
    {
        cout << arr2[i] << " ";
    }

    return 0;
}