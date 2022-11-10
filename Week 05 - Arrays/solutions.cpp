#include <iostream>
#include <limits>

void print(const int arr[], size_t size)
{
    for (size_t i = 0; i < size; i++)
    {
        std::cout << arr[i] << ' ';
    }
}

int findMax(const int arr[], size_t size)
{
    int max = std::numeric_limits<int>::min();
    for (size_t i = 0; i < size; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }
    return max;
}

int find(const int arr[], size_t size, int element)
{
    for (size_t i = 0; i < size; i++)
    {
        if (arr[i] == element)
        {
            return i;
        }
    }
    return -1;
}

unsigned filter(int destination[], const int source[], size_t size)
{
    size_t destinationSize = 0;
    for (size_t i = 0; i < size; i++)
    {
        if (source[i] % 14 == 0)
        {
            destination[destinationSize++] = source[i];
        }
    }
    return destinationSize;
}

bool isSet(const int arr[], size_t size)
{
    for (size_t i = 0; i < size - 1; i++)
    {
        if (arr[i] >= arr[i + 1])
        {
            return false;
        }
    }
    return true;
}

void reverse(int arr[], size_t size)
{
    for (size_t i = 0; i < size / 2; i++)
    {
        int temp = arr[i];
        arr[i] = arr[size - i - 1];
        arr[size - i - 1] = temp;
    }
}

int mostCommon(const int arr[], size_t size)
{
    int common = arr[0];
    int max = 0;
    for (size_t i = 0; i < size; i++)
    {
        unsigned counter = 1;
        for (size_t j = i + 1; j < size; j++)
        {
            if (arr[i] == arr[j])
            {
                counter++;
            }
        }
        if (counter > max)
        {
            max = counter;
            common = arr[i];
        }
    }
    return common;
}

void selectionSort(int arr[], size_t size)
{
    for (size_t i = 0; i < size - 1; i++)
    {
        for (size_t j = i + 1; j < size; j++)
        {
            if (arr[j] < arr[i])
            {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

void bubbleSort(int arr[], size_t size) {
    for (size_t i = 0; i < size-1; i++)
    {
        for (size_t j = 0; j < size-i-1; j++)
        {
            if(arr[j] > arr[j+1]) {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

int main()
{
    int arr[]{10, 5, 8, 3, 13, 7};
    bubbleSort(arr, 6);
    print(arr, 6); // -> 3 5 7 8 10 13
    return 0;
}