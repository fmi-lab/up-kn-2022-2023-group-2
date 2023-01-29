#include <iostream>
constexpr size_t MAX_SIZE = 255;

struct IntArray {
    int* arr;
    size_t size;
};

void deleteArray(IntArray& elements) {
    elements.size = 0;
    delete[] elements.arr;
}

int findBomb(const IntArray& elements, int bomb) {
    for (size_t i = 0; i < elements.size; i++)
    {
        if(elements.arr[i] == bomb) {
            return i;
        }
    }
    return -1;
}

int max(int lhs, int rhs) {
    return lhs > rhs ? lhs : rhs;
}

int min(int lhs, int rhs) {
    return lhs < rhs ? lhs : rhs;
}

void print(const IntArray& elements) {
    for (size_t i = 0; i < elements.size; i++)
    {
        std::cout<<elements.arr[i]<<' ';
    }
    
}

void detonateBombs(IntArray& elements, int bomb, size_t magnitude) {
    int bombIndex = findBomb(elements, bomb);
    while (bombIndex != -1)
    {
        int begin = max(bombIndex - magnitude, 0);
        int end = min(bombIndex + magnitude, elements.size - 1);

        size_t newSize = elements.size - (end - begin) - 1;
        int* newArr = new int[newSize];
        size_t index = 0;
        for (size_t i = 0; i < begin; i++)
        {
            newArr[index++] = elements.arr[i];
        }
        for (size_t i = end + 1; i < elements.size; i++)
        {
            newArr[index++] = elements.arr[i];
        }
        
        deleteArray(elements);
        elements.size = newSize;
        elements.arr = newArr;

        bombIndex = findBomb(elements, bomb);
    }
    
}

int main() {
    unsigned N;
    std::cin>>N;

    IntArray elements;
    elements.size = N;
    elements.arr = new int[N];

    for (size_t i = 0; i < elements.size; i++)
    {
        std::cin>>elements.arr[i];
    }

    int bomb;
    size_t magnitude;
    std::cin>>bomb>>magnitude;

    detonateBombs(elements, bomb, magnitude);

    print(elements);

    deleteArray(elements);
    
    return 0;
}