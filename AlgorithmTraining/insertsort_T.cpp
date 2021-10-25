#include <iostream>
#include <math.h>

using namespace std;

bool insertSort(int array[], size_t arrLen) {
    if (arrLen < 0) {//数组长度小于0就返回错误
        cout << "Please check your input." << endl;
        return false;
    }

    for (int orderedNum = 1; orderedNum < arrLen; ++orderedNum) {
        int insertValue = array[orderedNum];//第一个数据是有序的
        int orderedIndex = orderedNum - 1;//另一半就是无序的
        for (; orderedIndex >= 0; --orderedIndex) {//无序中的数和第一个比较、大的就放右边
            if (insertValue < array[orderedIndex]) {
                array[orderedIndex + 1] = array[orderedIndex];
            }
            else {//如果小于第一个数据就往左放
                break;
            }
        }
        array[orderedIndex+1] = insertValue;//最后把第一个数据插入到停止比较的位置
    }

    return true;
}

bool insertSort_Sen(int array[], size_t arrLen) {
     if (arrLen < 0) {
        cout << "Please check your input." << endl;
        return false;
    }

    for (int orderedNum = 1; orderedNum < arrLen; ++orderedNum) {
        int insertValue = array[orderedNum];//第一个数据是有序的
        int orderedIndex = orderedNum - 1;//另一半就是无序的
        while(orderedIndex >=0 && array[orderedIndex] > insertValue) {//有序的数要大于等于第一个位置，而后面无序的要比较的数位置在它后面
           array[orderedIndex + 1] = array[orderedIndex];
           --orderedIndex;
        }
        array[orderedIndex+1] = insertValue;//最后把第一个数据插入到停止比较的位置
    }

    return true;
}

void printArray(int array[], int arrLen) {
    for (int i = 0; i < arrLen; ++i) {//打印数组
        cout << array[i] << " ";
    }
    cout << endl;
}

int main(){
    int array0[] = {};
    int arrayLen = sizeof(array0)/sizeof(int);

    printArray(array0, arrayLen);//原数组
    insertSort(array0, arrayLen);//插入排序
    printArray(array0, arrayLen);//插入排序后的数组

    cout << "=========================================" << endl;

    int array1[] = {1};
    arrayLen = sizeof(array1)/sizeof(int);

    printArray(array1, arrayLen);
    insertSort_Sen(array1, arrayLen);
    printArray(array1, arrayLen);

    cout << "=========================================" << endl;

    int array2[] = {2, 1};
    arrayLen = sizeof(array2)/sizeof(int);

    printArray(array2, arrayLen);
    insertSort(array2, arrayLen);
    printArray(array2, arrayLen);

    cout << "=========================================" << endl;

    int array3[] = {1, 5, 3};
    arrayLen = sizeof(array3)/sizeof(int);

    printArray(array3, arrayLen);
    insertSort_Sen(array3, arrayLen);
    printArray(array3, arrayLen);


    cout << "=========================================" << endl;

    int array4[] = {9, 12, 8, 7};
    arrayLen = sizeof(array4)/sizeof(int);

    printArray(array4, arrayLen);
    insertSort(array4, arrayLen);
    printArray(array4, arrayLen);

    cout << "=========================================" << endl;

    int array5[] = {9, 12, 8, 7, 3};
    arrayLen = sizeof(array5)/sizeof(int);

    printArray(array5, arrayLen);
    insertSort_Sen(array5, arrayLen);
    printArray(array5, arrayLen);


}