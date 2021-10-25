#include <iostream>
#include <math.h>

using namespace std;

bool merge(int array[], size_t arrStart, size_t arrMiddle, size_t arrEnd) {
    int arrLen = arrEnd - arrStart;//数组长度等于第一个数的位置减去最后一个数的位置
    if (arrLen < 2) {
        cout << "Please check your implementation." << endl;
        return false;
    }
    //归并
    int *temp = new int(arrLen);
    int i = arrStart;//把数组第一数赋值给i
    int j = arrMiddle;//把数组中间的数赋值给j
    int tempIndex = 0;

    while (i < arrMiddle && j < arrEnd) {//当i的位置小于数组中间的位置并且j小于数组最后的位置
        if (array[i] > array[j]) {//当前半部分的数组内的元素大于后半部分
            temp[tempIndex] = array[j];//把后半部分的数组的值赋值给临时数组
            ++j;//然后j的位置往后移
        }
        else {
            temp[tempIndex] = array[i];//否则就把前半部分的数组值赋值给临时数组
            ++i;//i的位置也往后移
        }
        ++tempIndex;//临时组数内的下标再逐渐增加
    }

    while (i < arrMiddle) {//前半部分的数组放到临时数组里
        temp[tempIndex++] = array[i++];
    }

    while (j < arrEnd) {//后半部分的数组也放到临时数组里
        temp[tempIndex++] = array[j++];
    }

    for ((tempIndex = 0, i = arrStart); (tempIndex < arrLen && i < arrEnd); (++tempIndex, ++i)) {
        array[i] = temp[tempIndex];//归并完返回给之前的数组
    }

    delete []temp;
    temp = NULL;

    return true;
}
bool mergeSort(int array[], size_t arrStart, size_t arrEnd) {
    int arrLen = arrEnd - arrStart;//数组长度
    if (arrLen < 0) {
        cout << "Please check your input." << endl;
        return false;
    }

    if (arrLen == 0 || arrLen == 1){//递归退出条件
        return true;
    } 

    int middle = arrStart + floor(arrLen / 2);//定义数组中间的位置

    mergeSort(array, arrStart, middle);//递归调用，前半部分排序
    mergeSort(array, middle, arrEnd);//后半部分排序
    return merge(array, arrStart, middle, arrEnd);
}

void printArray(int array[], int arrLen) {
    for (int i = 0; i < arrLen; ++i) {
        cout << array[i] << " ";
    }
    cout << endl;
}

int main(){
    int array0[] = {};
    int arrayLen = sizeof(array0)/sizeof(int);

    printArray(array0, arrayLen);//原数组
    mergeSort(array0, 0, arrayLen);//归并排序
    printArray(array0, arrayLen);//归并排序后的数组

    cout << "=========================================" << endl;

    int array1[] = {1};
    arrayLen = sizeof(array1)/sizeof(int);

    printArray(array1, arrayLen);
    mergeSort(array1, 0, arrayLen);
    printArray(array1, arrayLen);

    cout << "=========================================" << endl;

    int array2[] = {2, 1};
    arrayLen = sizeof(array2)/sizeof(int);

    printArray(array2, arrayLen);
    mergeSort(array2, 0, arrayLen);
    printArray(array2, arrayLen);

    cout << "=========================================" << endl;

    int array3[] = {1, 5, 3};
    arrayLen = sizeof(array3)/sizeof(int);

    printArray(array3, arrayLen);
    mergeSort(array3, 0, arrayLen);
    printArray(array3, arrayLen);


    cout << "=========================================" << endl;

    int array4[] = {9, 12, 8, 7};
    arrayLen = sizeof(array4)/sizeof(int);

    printArray(array4, arrayLen);
    mergeSort(array4, 0, arrayLen);
    printArray(array4, arrayLen);

    cout << "=========================================" << endl;

    int array5[] = {9, 12, 8, 7, 3};
    arrayLen = sizeof(array5)/sizeof(int);

    printArray(array5, arrayLen);
    mergeSort(array5, 0, arrayLen);
    printArray(array5, arrayLen);


}