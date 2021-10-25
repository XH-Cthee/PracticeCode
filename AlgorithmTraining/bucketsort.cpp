#include <iostream>
#include <math.h>

using namespace std;

bool insertSort(int array[], size_t arrLen) {
    if (arrLen < 0) {//数组长度小于0就返回错误
        cout << "Please check your input." << endl;
        return false;
    }
    //分的桶内的数据选择插入排序
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
     if (arrLen < 0) {//数组长度小于0就返回错误
        cout << "Please check your input." << endl;
        return false;
    }
    //插入排序
    for (int orderedNum = 1; orderedNum < arrLen; ++orderedNum) {
        int insertValue = array[orderedNum];
        int orderedIndex = orderedNum - 1;
        while(orderedIndex >=0 && array[orderedIndex] > insertValue) {//有序的数要大于等于第一个位置，而后面无序的要比较的数位置在它后面
           array[orderedIndex + 1] = array[orderedIndex];
           --orderedIndex;
        }
        array[orderedIndex+1] = insertValue;
    }

    return true;
}
//循环打印数组
void printArray(int array[], int arrLen) {
    for (int i = 0; i < arrLen; ++i) {
        cout << array[i] << " ";
    }
    cout << endl;
}

bool buckertSort(int array[], size_t arrLen, size_t bucketSize) {
    const int DEFAULT_BUCKET_SIZE = 10;//默认桶的大小为10
    if(arrLen < 2) {//数组长度小于2认为有序
        return true;
    }

    if (bucketSize < 1) {
        bucketSize = DEFAULT_BUCKET_SIZE;
    }

    // Find the scope of the array
    int min = array[0];//默认数组第一个数位最小或者最大的数
    int max = array[0];
    
    //找到数组中最大和最小的数来确定数据范围
    for (size_t i = 1; i < arrLen; ++i)
    {
        if (min > array[i]) {
            min = array[i];
        }
        else if (max < array[i]) {
            max = array[i];
        }
    }

    // Create buckets
    int **buckets = new int*[bucketSize]();//定义桶的二维数组
    int *bucketLen = new int[bucketSize]();
    int bucketScope = floor((max - min)/bucketSize) + 1;//每一个桶的数据范围

    for (size_t j = 0; j < bucketSize; j++)
    {
        buckets[j] = new int[arrLen]();//给每个桶按照数据范围分配内存空间
    }

    int mapIndex = -1;

    // Put array value to buckets
    for (size_t k = 0; k < arrLen; ++k)
    {
        mapIndex = floor((array[k] - min)/bucketScope);//桶的数据范围
        buckets[mapIndex][bucketLen[mapIndex]++] = array[k];//把数组放到划分的桶里面
    }

    // Sort value in bucket and put ordered value back to array
    int arrayIndex = 0;
    for (size_t l = 0; l < bucketSize; l++)
    {
        if (bucketLen[l] > 0) {
            insertSort(buckets[l], bucketLen[l]);//把桶内的数据按插入排序排好
            for (size_t m = 0; m < bucketLen[l]; ++m) {
                array[arrayIndex++] = buckets[l][m];//桶内的数组排好顺序后返回给之前的数组
            }
        }
        delete [] buckets[l];//释放桶的空间
        buckets[l] = NULL;
    }

    delete [] buckets;//释放空间
    delete [] bucketLen;

    return true;

}

int main(){
    int array0[] = {};
    int arrayLen = sizeof(array0)/sizeof(int);

    printArray(array0, arrayLen);//原数组
    insertSort(array0, arrayLen);//插入排序后
    printArray(array0, arrayLen);//插入排序后的数组

    cout << "=========================================" << endl;

    int array1[] = {1};
    arrayLen = sizeof(array1)/sizeof(int);

    printArray(array1, arrayLen);//原数组
    buckertSort(array1, arrayLen, 1);//桶排序、三个参数：数组、数组长度、桶的大小
    printArray(array1, arrayLen);//桶排序后的数组

    cout << "=========================================" << endl;

    int array2[] = {2, 1};
    arrayLen = sizeof(array2)/sizeof(int);

    printArray(array2, arrayLen);
    buckertSort(array2, arrayLen, 2);
    printArray(array2, arrayLen);

    cout << "=========================================" << endl;

    int array3[] = {1, 5, 3};
    arrayLen = sizeof(array3)/sizeof(int);

    printArray(array3, arrayLen);
    buckertSort(array3, arrayLen, 2);
    printArray(array3, arrayLen);


    cout << "=========================================" << endl;

    int array4[] = {9, 12, 8, 7};
    arrayLen = sizeof(array4)/sizeof(int);

    printArray(array4, arrayLen);
    buckertSort(array4, arrayLen, 2);
    printArray(array4, arrayLen);

    cout << "=========================================" << endl;

    int array5[] = {9, 12, 8, 7, 3};
    arrayLen = sizeof(array5)/sizeof(int);

    printArray(array5, arrayLen);
    buckertSort(array5, arrayLen, 2);
    printArray(array5, arrayLen);
}