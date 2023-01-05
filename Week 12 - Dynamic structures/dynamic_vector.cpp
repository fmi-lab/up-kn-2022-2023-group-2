#include <iostream>
#include <cmath>

struct dynamic_array
{
    double *arr;
    size_t arr_size;
    size_t arr_length;

    void push(double x)
    {
        if (arr_size == arr_length)
        {
            std::cout << "Create new arr.\n";
            double *temp = arr;
            arr = new double[arr_size * 2];
            arr_size *= 2;
            for (int i = 0; i < arr_length; i++)
            {
                arr[i] = temp[i];
            }
            delete[] temp;
        }
        arr[arr_length] = x;
        arr_length++;
    }
};

// void push(dynamic_array& a, double x){
//     if(a.arr_size == a.arr_length){
//         std::cout<<"Create new arr.\n";
//         double* temp = a.arr;
//         a.arr = new double[a.arr_size*2];
//         a.arr_size *= 2;
//         for(int i = 0; i < a.arr_length; i++){
//             a.arr[i] = temp[i];
//         }
//         delete[] temp;
//     }
//     a.arr[a.arr_length] = x;
//     a.arr_length++;
// }

void print(const dynamic_array &a)
{
    for (int i = 0; i < a.arr_length; i++)
    {
        std::cout << a.arr[i] << ' ';
    }
    std::cout << std::endl;
}

int main()
{
    dynamic_array a1;
    a1.arr = new double[2];
    a1.arr_size = 2;
    a1.arr_length = 0;
    a1.push(0);
    a1.push(1);
    a1.push(2);
    a1.push(3);
    a1.push(4);
    // push(a1, 0);
    // push(a1, 1);
    // push(a1, 2);
    // push(a1, 3);
    // push(a1, 4);
    print(a1);
    delete[] a1.arr;
    a1.arr_size = 0;
    a1.arr_length = 0;
}
