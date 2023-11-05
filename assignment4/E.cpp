#include <bits/stdc++.h>
using namespace std;
//写一个合并两个不等长升序数组的函数，返回新的升序数组。用随机数生成数组进行测试
//分别用数组和vector类实现
int* combine(int arr1[], int lenOfArr1, int arr2[], int lenOfArr2) {
    int maximum = max(arr1[lenOfArr1 - 1], arr2[lenOfArr2 - 1]);
    int minimum = min(arr1[0], arr2[0]);

    int *bucket = new int[maximum - minimum + 1];
    memset(bucket, 0, (maximum - minimum + 1) * sizeof(int));

    for(int i = 0; i < lenOfArr1; i++)
        bucket[arr1[i] - minimum]++;
    for(int i = 0; i < lenOfArr2; i++)
        bucket[arr2[i] - minimum]++;

    int *combinedArr = new int[lenOfArr1 + lenOfArr2];
    int index = 0;
    for(int i = 0; i <= maximum - minimum; i++) {
        while(bucket[i] > 0) {
            combinedArr[index] = i + minimum;
            index++;
            bucket[i]--;
        }
    }
    delete[] bucket;
    return combinedArr;
}
//vector 实现
vector<int> combine(vector<int> v1, vector<int> v2) {
    int Max = max(v1.back(), v2.back());
    int Min = min(v1[0], v2[0]);

    int *bucket = new int[Max - Min + 1];
    memset(bucket, 0, (Max - Min + 1) * sizeof(int));
    for(int num : v1)
        bucket[num - Min]++;
    for(int num : v2)
        bucket[num - Min]++;
    
    vector<int> combinedVector;
    for(int i = 0; i <= Max - Min; i++){
        while(bucket[i] > 0) {
            combinedVector.emplace_back(i + Min);
            bucket[i]--;
        }
    }
    return combinedVector;
}
//test
int main() {
    //generate two random arrays
    srand(time(NULL));
    int lenOfArr1 = rand() % 10 + 1;
    int lenOfArr2 = rand() % 10 + 1;
    int *arr1 = new int[lenOfArr1];
    int *arr2 = new int[lenOfArr2];
    vector<int> v1(lenOfArr1);
    vector<int> v2(lenOfArr2);

    for(int i = 0; i < lenOfArr1; i++)
        arr1[i] = rand() % 100;
    for(int i = 0; i < lenOfArr2; i++)
        arr2[i] = rand() % 100;
    sort(arr1, arr1 + lenOfArr1);
    sort(arr2, arr2 + lenOfArr2);

    //print the arrays
    for(int i = 0; i < lenOfArr1; i++) {
        cout << arr1[i] << " ";
        v1[i] = arr1[i];
    }
    cout << endl;
    for(int i = 0; i < lenOfArr2; i++) {
        cout << arr2[i] << " ";
        v2[i] = arr2[i];
    }
    cout << endl;

    //print the combined array
    int *combinedArr = combine(arr1, lenOfArr1, arr2, lenOfArr2);
    for(int i = 0; i < lenOfArr1 + lenOfArr2; i++)
        cout << combinedArr[i] << " ";
    cout << endl;

    vector<int> combinedV = combine(v1, v2);
    for(int num : combinedV)
        cout << num << " ";
    cout << endl;

    delete[] arr1;
    delete[] arr2;
    delete[] combinedArr;

    return 0;
}

//GitHub Copilot: 这段代码试图合并两个整数数组，并返回一个指向新数组的指针。但是，这段代码有几个问题：

//1. `sizeof(arr1) / sizeof(arr1[0])` 和 `sizeof(arr2) / sizeof(arr2[0])` 
//并不能得到数组的长度。在函数参数中，数组会退化为指针，
//所以 `sizeof(arr1)` 和 `sizeof(arr2)` 实际上得到的是指针的大小，而不是数组的大小。
//你需要将数组的长度作为参数传递给函数。

//2. `memset(bucket, 0, sizeof(bucket))` 这行代码也有问题。
//`sizeof(bucket)` 得到的是指针的大小，而不是数组的大小。
//你应该使用 `maximum - minimum + 1` 作为 `memset` 的第三个参数。

//3. `int combinedArr[lenOfArr1 + lenOfArr2];` 
//这行代码定义了一个局部数组，然后函数返回了这个数组的指针。
//但是，当函数返回时，局部数组会被销毁，所以返回的指针将指向无效的内存。
//你应该使用 `new` 关键字动态分配一个数组，然后返回这个数组的指针。

//以上是修改后的代码：

//请注意，你需要在使用完 `combinedArr` 后使用 `delete[]` 释放内存。