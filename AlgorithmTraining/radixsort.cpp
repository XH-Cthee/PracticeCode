#include <iostream>

using namespace std;

unsigned int getRadixValue(unsigned int value, unsigned int radix, unsigned int radixCount) {
    int radixValue = value;
    for (size_t i = 0; i < radixCount; ++i)
    {
        radixValue=radixValue/radix;//找到每个位置上的值
    }
    radixValue = radixValue % radix;//比如92 0位上是2 1位上是9
    return radixValue;   
}
bool radixSort(unsigned int array[], unsigned int arrLen, unsigned int radix) {
    if (arrLen <= 1) {
        return true;
    }

    //Find maximum and minimal value
    int max = array[0];

    for (unsigned int i = 1; i < arrLen; ++i)
    {//求出数组内的最大最小值
         if (max < array[i]) {
            max = array[i];
        }
    }

    int radixCount = 0;
    while ((max/=radix) > 0) {//计算需要多少位 比如100需要1位
        ++radixCount;
    }

    // Create counting buckets
    int *countingRadixBuckets = new int[radix]();//根据分的份数分配内存空间
    int *tempArray = new int[arrLen]();//按数组长度给临时数组分配空间

    for (size_t radixIndex = 0; radixIndex <= radixCount; ++radixIndex)
    {
        // Count number of values in array
        for (size_t j = 0; j < arrLen; ++j)
        {
            ++countingRadixBuckets[getRadixValue(array[j], radix, radixIndex)];//累加位数的值
        }

        // Accumulate coutingBuckets to find the last ordered location of value in array
        for (size_t k = 1; k < radix; ++k)
        {
            countingRadixBuckets[k] += countingRadixBuckets[k-1];//累加需要计数的桶找到最后一个数的位置
        }

        //Traverse the array in reversed order
        for (int l = arrLen - 1; l >= 0; --l)
        {//反向遍历数组然后放到临时数组里
            tempArray[--countingRadixBuckets[getRadixValue(array[l], radix, radixIndex)]] = array[l];
        }

        for (size_t m = 0; m < arrLen; ++m)
        {
            array[m] = tempArray[m];//排好序的数组返回给之前的数组
        }

        for (size_t n = 0; n < radix; ++n)
        {
            countingRadixBuckets[n] = 0;
        }
        
    }
    
    delete [] countingRadixBuckets;//释放空间
    delete [] tempArray;
    
    return true;
}

void printArray(unsigned int array[], int arrLen) {
    for (int i = 0; i < arrLen; ++i) {
        cout << array[i] << " ";
    }
    cout << endl;
}

int main(){
    unsigned int array0[] = {};
    unsigned int arrayLen = sizeof(array0)/sizeof(int);

    printArray(array0, arrayLen);//原数组
    radixSort(array0, arrayLen, 10);//基数排序
    printArray(array0, arrayLen);//基数排序后的数组

    cout << "=========================================" << endl;

    unsigned int array1[] = {1};
    arrayLen = sizeof(array1)/sizeof(int);

    printArray(array1, arrayLen);
    radixSort(array1, arrayLen, 10);
    printArray(array1, arrayLen);

    cout << "=========================================" << endl;

    unsigned int array2[] = {20, 1};
    arrayLen = sizeof(array2)/sizeof(int);

    printArray(array2, arrayLen);
    radixSort(array2, arrayLen, 10);
    printArray(array2, arrayLen);

    cout << "=========================================" << endl;

    unsigned int array3[] = {1, 300, 30};
    arrayLen = sizeof(array3)/sizeof(int);

    printArray(array3, arrayLen);
    radixSort(array3, arrayLen, 10);
    printArray(array3, arrayLen);


    cout << "=========================================" << endl;

    unsigned int array4[] = {92, 29, 12, 121};
    arrayLen = sizeof(array4)/sizeof(int);

    printArray(array4, arrayLen);
    radixSort(array4, arrayLen, 10);
    printArray(array4, arrayLen);

    cout << "=========================================" << endl;

    unsigned int array5[] = {19, 33, 34, 999, 5};
    arrayLen = sizeof(array5)/sizeof(int);

    printArray(array5, arrayLen);
    radixSort(array5, arrayLen, 10);
    printArray(array5, arrayLen);


     cout << "=========================================" << endl;

    unsigned int array6[] = {90, 311, 34, 59, 57, 85, 107, 1277, 125, 143, 169, 162};
    arrayLen = sizeof(array6)/sizeof(int);

    printArray(array6, arrayLen);
    radixSort(array6, arrayLen, 10);
    printArray(array6, arrayLen);


}