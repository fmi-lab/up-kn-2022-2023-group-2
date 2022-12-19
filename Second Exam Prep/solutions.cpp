#include <iostream>
#include <cmath>

size_t arithmeticProgressionLength(int *begin, int *end)
{
    int diff = begin[1] - begin[0];
    size_t length = 1;
    while (begin != end - 1 && *(begin + 1) - *begin == diff)
    {
        ++length;
        ++begin;
    }

    return length;
}

int *longestArithmeticProgression(int *begin, int *end)
{
    size_t maxCounter = 0;
    int *maxStart = begin;
    while (begin != end)
    {
        size_t length = arithmeticProgressionLength(begin, end);
        if (length > maxCounter)
        {
            maxCounter = length;
            maxStart = begin;
        }
        begin += length;
    }

    return maxStart;
}

void print(int *begin, int *end)
{
    while (begin != end)
    {
        std::cout << *begin << ' ';
        ++begin;
    }
}

bool areEqual(double a, double b)
{
    constexpr double EPSILON = 0.0001;
    return std::fabs(a - b) < EPSILON;
}

int decodeLetter(char c, char *letters, int *digits)
{
    while (*letters)
    {
        if (c == *letters)
        {
            return *digits;
        }
        ++letters;
        ++digits;
    }

    return 1;
}

bool containsEqualDigits(int n)
{
    bool digits[10]{};
    while (n > 0)
    {
        if (digits[n % 10])
        {
            return true;
        }

        digits[n % 10] = true;
        n /= 10;
    }

    return false;
}

int *collect(int matrix[][255], size_t N, int *result)
{
    int i = 0, j = N - 1;
    while (!(i == N - 1 && j == 0))
    {
        if (containsEqualDigits(matrix[i][j]))
        {
            *result = matrix[i][j];
            ++result;
        }

        if (i + 1 == N || j + 1 == N)
        {
            if (j > i)
            {
                j = j - i - 1;
                i = 0;
            }
            else if (i == j)
            {
                i = 1;
                j = 0;
            }
            else
            {
                i = N - j;
                j = 0;
            }
        }
        else
        {
            ++i;
            ++j;
        }
    }

    return result;
}

int decode(char *sentence, char *letters, int *digits)
{
    int result = 0;
    int product = 1;
    while (*sentence)
    {
        if (*sentence != ' ' && *sentence != '.' && *sentence != '!' && *sentence != '?')
        {
            product *= decodeLetter(*sentence, letters, digits);
        }
        else
        {
            result += product;
            product = 1;
        }
        ++sentence;
    }
    return result;
}

int main()
{
    // constexpr size_t MAX_LENGTH = 255;
    // unsigned N;
    // do {
    //     std::cin>>N;
    // } while(N > 255);

    // double arr[MAX_LENGTH]{};
    // for(int i = 0; i < N; ++i) {
    //     std::cin>>arr[i];
    // }

    // int arr[] = {0, 2, 4, 5, 2, 3, -1, -5, -9,-6, -3, 5 };

    // int* start = longestArithmeticProgression(std::begin(arr), std::end(arr));
    // print(start, std::end(arr));


    // SOLUTION OF TASK 2
    constexpr size_t MAX_LENGTH = 255;
    unsigned N;
    do
    {
        std::cin >> N;
    } while (N > 255);

    double arr[MAX_LENGTH]{};
    for (int i = 0; i < N; ++i)
    {
        std::cin >> arr[i];
    }

    size_t k = N - 2;
    size_t i = 0;
    bool flag = true;
    while (k > 0 && flag)
    {
        i = 0;
        double diff = std::fabs(arr[0] - arr[k]);
        while (i < N - k && areEqual(std::fabs(arr[i] - arr[i + k]), diff))
        {
            ++i;
        }

        if (i == N - k)
        {
            std::cout << k << ' ' << diff;
            flag = !flag;
        }

        --k;
    }

    // constexpr size_t MAX_LENGTH = 256;
    // constexpr size_t ALPHABET_COUNT = 53;
    // unsigned N;
    // std::cin>>N;
    // char letters[ALPHABET_COUNT]{};
    // int digits[ALPHABET_COUNT]{};
    // for(int i = 0; i < N; ++i) {
    //     std::cin>>letters[i];
    // }

    // for(int i = 0; i < N; ++i) {
    //     std::cin>>digits[i];
    // }

    // char sentence[MAX_LENGTH]{};
    // std::cin.ignore();
    // std::cin.getline(sentence, MAX_LENGTH);

    // std::cout<<decode(sentence, letters, digits);

    // constexpr size_t MAX_LENGTH = 255;
    // unsigned N;
    // std::cin>>N;
    // int matrix[MAX_LENGTH][MAX_LENGTH]{};
    // for(int i = 0; i < N; ++i) {
    //     for(int j = 0; j < N; ++j) {
    //         std::cin>>matrix[i][j];
    //     }
    // }
    // int arr[MAX_LENGTH]{};
    // int* end = collect(matrix, N, arr);
    // print(arr, end);

    return 0;
}