#include <iostream>

struct Point
{
    int x;
    int y;
};

struct PointArray {
    Point* arr;
    size_t size;
};

void addPoint(PointArray& path, Point point) {
    size_t newSize = path.size + 1;
    Point* newArr = new Point[newSize];

    for (size_t i = 0; i < path.size; i++)
    {
        newArr[i] = path.arr[i];
    }
    newArr[path.size] = point;
    
    delete[] path.arr;
    path.arr = newArr;
    path.size = newSize;
}

bool valid(int **matrix, size_t N, int currentX, int currentY, bool **visited,
           int currentVolume, int maxVolume)
{
    return currentX >= 0 && currentX < N &&
           currentY >= 0 && currentY < N &&
           !visited[currentX][currentY] &&
           currentVolume + matrix[currentX][currentY] <= maxVolume &&
           currentVolume + matrix[currentX][currentY] >= 0;
}

bool hasPath(int **matrix, size_t N, int startX, int startY, int endX, int endY,
             bool **visited, int &currentVolume, int maxVolume, PointArray& path)
{
    if (!valid(matrix, N, startX, startY, visited, currentVolume, maxVolume))
    {
        return false;
    }

    if (startX == endX && startY == endY)
    {
        return true;
    }

    visited[startX][startY] = true;
    int tempVolume = currentVolume;
    currentVolume += matrix[startX][startY];

    if (hasPath(matrix, N, startX + 1, startY, endX, endY, visited, currentVolume, maxVolume, path))
    {
        addPoint(path, {startX, startY});
        return true;
    }
    if (hasPath(matrix, N, startX - 1, startY, endX, endY, visited, currentVolume, maxVolume, path))
    {
        addPoint(path, {startX, startY});
        return true;
    }
    if (hasPath(matrix, N, startX, startY + 1, endX, endY, visited, currentVolume, maxVolume, path))
    {
        addPoint(path, {startX, startY});
        return true;
    }
    if (hasPath(matrix, N, startX, startY - 1, endX, endY, visited, currentVolume, maxVolume, path))
    {
        addPoint(path, {startX, startY});
        return true;
    }

    visited[startX][startY] = false;
    currentVolume = tempVolume;
    return false;
}

void reverse(Point* begin, Point* end) {
    while (begin != end && begin + 1 != end)
    {
        std::iter_swap(begin, end - 1);
        ++begin;
        --end;
    }
}

bool canVisitAndGoBack(int **matrix, size_t N, int startX, int startY, int endX, int endY,
                       int maxVolume, PointArray& path)
{
    bool **visited = new bool *[N];
    for (size_t i = 0; i < N; i++)
    {
        visited[i] = new bool[N]{false};
    }

    int currentVolume = 0;
    bool to = hasPath(matrix, N, startX, startY, endX, endY, visited, currentVolume, maxVolume, path);
    
    size_t mid = path.size;
    reverse(path.arr, path.arr + mid);
    
    visited[startX][startY] = false;
    matrix[startX][startY] = 0;
    
    bool from = hasPath(matrix, N, endX, endY, startX, startY, visited, currentVolume, maxVolume, path);
    reverse(path.arr + mid, path.arr + path.size);
    
    for (size_t i = 0; i < N; i++)
    {
        delete[] visited[i];
    }
    delete[] visited;
    
    return to && from;
}

void print(const PointArray& path)
{
    for (size_t i = 0; i < path.size-1; i++)
    {
        std::cout << "(" << path.arr[i].x << ", " << path.arr[i].y << ") -> ";
    }
    std::cout << "(" << path.arr[path.size-1].x << ", " << path.arr[path.size-1].y<<')';
}

int main()
{
    unsigned N;
    std::cin >> N;

    int **matrix = new int *[N];
    for (size_t i = 0; i < N; i++)
    {
        matrix[i] = new int[N];
    }

    for (size_t i = 0; i < N; i++)
    {
        for (size_t j = 0; j < N; j++)
        {
            std::cin >> matrix[i][j];
        }
    }

    int homeX, homeY, grandmaX, grandmaY, maxVolume;
    std::cin >> homeX >> homeY >> grandmaX >> grandmaY >> maxVolume;

    PointArray path {
        new Point[0],
        0
    };

    std::cout << std::boolalpha << canVisitAndGoBack(matrix, N, homeX, homeY, grandmaX, grandmaY, maxVolume, path)<<'\n';
    print(path);

    for (size_t i = 0; i < N; i++)
    {
        delete[] matrix[i];
    }
    delete[] matrix;
    return 0;
}