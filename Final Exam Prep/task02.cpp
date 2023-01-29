#include <iostream>
#include <fstream>
#include <cstring>
#include <cmath>
constexpr size_t MAX_SIZE = 255;

struct Product {
    char name[MAX_SIZE];
    unsigned quantity;
    double price;
};

struct ProductArray {
    Product* arr;
    size_t size;
};

ProductArray serialize(std::istream& is) {
    unsigned N;
    is>>N;

    ProductArray products {
        new Product[N],
        N
    };

    for (size_t i = 0; i < N; i++)
    {
        is >> products.arr[i].name;
        is >> products.arr[i].quantity;
        is >> products.arr[i].price;
    }

    return products;    
}

void deserialize(const ProductArray& products, std::ostream& os) {
    os << products.size << '\n';
    for (size_t i = 0; i < products.size; i++)
    {
        Product product = products.arr[i];
        os << product.name << ' ' <<product.quantity<<' '<<product.price<<'\n';
    }
}

double buy(const ProductArray& products, char name[MAX_SIZE], unsigned quantity) {
    for (size_t i = 0; i < products.size; i++)
    {
        Product& product = products.arr[i];
        if(strcmp(product.name, name) == 0 && quantity <= product.quantity) {
            product.quantity -= quantity;
            return quantity * product.price;   
        }
    }
    return 0;
}

bool areEqual(double a, double b) {
    constexpr double EPSILON = 0.000001;
    return std::fabs(a - b) < EPSILON;
}

void deleteArray(ProductArray& elements) {
    elements.size = 0;
    delete[] elements.arr;
}


int main() {
    std::ifstream is("inventory.txt");
    ProductArray products = serialize(is);
    is.close();

    unsigned M;
    std::cin>>M;

    double result = 0;
    for (size_t i = 0; i < M; i++)
    {
        char name[MAX_SIZE]{'\0'};
        unsigned quantity;
        std::cin>>name>>quantity;
        double stonks = buy(products, name, quantity);
        result += stonks;
        if(areEqual(stonks, 0)) {
            std::cout<<"Not enough "<<name<<'\n';
        }
    }
    std::cout<<result<<'\n';
    
    std::ofstream os("inventory.txt");
    deserialize(products, os);
    os.close();

    deleteArray(products);
    return 0;
}