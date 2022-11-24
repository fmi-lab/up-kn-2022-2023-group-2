#include<iostream>
#include <iomanip>
#include<cmath>

void print_matrix(size_t size_n, size_t size_m, const int arr[255][255]){
    for(int i = 0; i < size_n; i++){
        for(int j = 0; j < size_m; j++){
            std::cout<<std::setw(4)<<arr[i][j];
        }
        std::cout<<std::endl;
    }
}

void diagonal_snake(size_t size_n, size_t size_m, int arr[255][255]){
    for(int i = 0; i < size_n; i++){
        for(int j = 0; j < size_m; j++){
            arr[i][j] = pow(2, i)*(2*j + 1);
        }
    }
}

void horizontal_snake(size_t size_n, size_t size_m, int arr[255][255]){
    size_t count = 0;
    std::cout<<size_m<<' '<<size_n<<std::endl;
    for (size_t i = 0; i < size_n; i++)
    {
        if(i%2 == 0){
            for (int j = 0; j < size_m; j++)
            {
                arr[i][j] = count;
                count++;
            }
        } else{
            for (int j = size_m - 1; j >= 0; j--)
            {
                arr[i][j] = count;
                count++;
            }
        }
    }
}

void main_diagonal(size_t size_n, size_t size_m, int arr[255][255]){
    // for(int i = 0; i<size_n*size_m; i++){
    //     arr[][size_m - (size_m % i)]
    // }
    // for(int i = 0; i < size_n; i++){
    //     for(int j = 0; j<size_m; j++){
    //         arr[i][j] = size_m - 
    //     }
    // }
    int diagonal_counter = 0;
    int counter = 0;
    for(diagonal_counter = 0; diagonal_counter < size_n+size_m; diagonal_counter++){
        int dx, dy;
        if(diagonal_counter < size_m){
            dx = size_m - diagonal_counter;
            dy = 0;
        } else {
            dy = diagonal_counter - size_m;
            dx = 0;
        }
        while(dy < size_n && dx < size_m){
            arr[dy][dx] = counter;
            counter++;
            dx++;
            dy++;
        }
    }
}

void secondary_diagonal(size_t size_n, size_t size_m, int arr[255][255]){
    int i = 0, j = 0, temp = 0;
    while(i < size_n && j < size_m && j>=0){
        int temp_i = i, temp_j = j;
        while(i < size_n && j < size_m && j>=0){
            arr[i][j] = temp;
            ++i;
            --j;
            ++temp;
        }
        if(temp_j < size_m - 1){
            i = temp_i;
            j = temp_j + 1;
        } else {
            i = temp_i + 1;
            j = temp_j;
        }
    }
}

int main(){
    size_t size_n = 5, size_m = 7;
    int arr[255][255]{0};
    secondary_diagonal(size_n, size_m, arr);
    print_matrix(size_n, size_m, arr);
    system("pause");
    return 0;
}
