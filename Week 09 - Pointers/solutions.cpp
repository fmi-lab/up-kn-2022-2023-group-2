#include <iostream>

void print(const int *begin, const int *end)
{
    while (begin != end)
    {
        std::cout << *(begin++) << ' ';
    }
}

void print(int *begin, int *end)
{
    while (begin != end)
    {
        std::cout << *(begin++) << ' ';
    }
}

const int *upper_bound(const int *begin, const int *end, int element)
{
    while (begin != end)
    {
        const int *mid = begin + (end - begin) / 2;
        if (element >= *mid)
        {
            begin = mid + 1;
        }
        else
        {
            end = mid;
        }
    }

    return *begin > element ? begin : nullptr;
}

bool equal(const int *first_begin, const int *first_end, const int *second_begin, const int *second_end)
{
    while (first_begin != first_end && second_begin != second_end && *first_begin == *second_begin)
    {
        ++first_begin;
        ++second_begin;
    }

    return first_begin == first_end && second_begin == second_end;
}

void replace(int *begin, int *end, int old_value, int new_value)
{
    while (begin != end)
    {
        if (*begin == old_value)
        {
            *begin = new_value;
        }
        begin++;
    }
}

void reverse(int *begin, int *end)
{
    while (begin != end && begin + 1 != end)
    {
        std::iter_swap(begin, end - 1);
        ++begin;
        --end;
    }
}

void rotate(int *begin, int *mid, int *end)
{
    reverse(begin, mid);
    reverse(mid, end);
    reverse(begin, end);
}

bool isPrefix(const int *first_begin, const int *first_end, const int *second_begin, const int *second_end)
{
    while (first_begin != first_end && second_begin != second_end && *first_begin == *second_begin)
    {
        ++first_begin;
        ++second_begin;
    }

    return second_begin == second_end;
}

const int *search(const int *first_begin, const int *first_end, const int *second_begin, const int *second_end)
{
    while (first_begin != first_end)
    {
        if (isPrefix(first_begin, first_end, second_begin, second_end))
        {
            return first_begin;
        }
        ++first_begin;
    }
    return nullptr;
}

bool ends_with(const int *first_begin, const int *first_end, const int *second_begin, const int *second_end)
{
    while (first_begin != first_end)
    {
        if (isPrefix(first_begin, first_end, second_begin, second_end) && (first_end - first_begin) == (second_end - second_begin))
        {
            return true;
        }
        ++first_begin;
    }
    return false;
}

const int *find_end(const int *first_begin, const int *first_end, const int *second_begin, const int *second_end)
{
    const int *occurence = search(first_begin, first_end, second_begin, second_end);

    while (occurence)
    {
        const int *newOccurence = search(occurence + (second_end - second_begin), first_end, second_begin, second_end);
        if (newOccurence == nullptr)
        {
            return occurence;
        }
        else
        {
            occurence = newOccurence;
        }
    }

    return nullptr;
}

int *unique(int *begin, int *end)
{
    while (begin != end)
    {
        while (begin + 1 != end && *begin == *(begin + 1))
        {
            rotate(begin + 1, begin + 2, end);
            --end;
        }
        ++begin;
    }
    return end;
}

int *partition(int *begin, int *end)
{
    int *originalBegin = begin;
    while (begin != end)
    {
        if (*begin % 2)
        {
            ++begin;
        }
        else
        {
            rotate(begin, begin + 1, end);
            --end;
        }
    }

    return begin;
}

bool isLastPermutation(int *begin, int *end)
{
    while (begin + 1 != end)
    {
        if (*begin < *(begin + 1))
        {
            return false;
        }
        ++begin;
    }
    return true;
}

int *find_first_min(int *begin, int *end, int element)
{
    while (begin != end && *begin > element)
    {
        ++begin;
    }
    return begin - 1;
}

bool next_permutation(int *begin, int *end)
{
    if (isLastPermutation(begin, end))
    {
        reverse(begin, end);
        return false;
    }

    int *originalEnd = end;
    while (end - 2 != begin - 1 && *(end - 2) > *(end - 1))
    {
        --end;
    }
    int *toSwap = find_first_min(end - 1, originalEnd, *(end - 2));
    std::iter_swap(end - 2, toSwap);
    reverse(end - 1, originalEnd);
    return true;
}

int main()
{
    int arr[]{1, 2, 3};

    do
    {
        print(std::begin(arr), std::end(arr));
        std::cout << std::endl;
    } while (next_permutation(std::begin(arr), std::end(arr)));

    /*
        1 2 3
        1 3 2
        2 1 3
        2 3 1
        3 1 2
        3 2 1
    */
    return 0;
}