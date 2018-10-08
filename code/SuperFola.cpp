#include <iostream>
#include <time.h>
#include <stdlib.h>

template <class T>
void swapThem(T* a, T* b)
{
    T c = *b;
    *b = *a;
    *a = c;
}

// a strange implementation of the fibonacci algorithm, because why not !

int main(void)
{
    using bigint_t = unsigned long long int;
    
    // setting the seed for rand
    srand(static_cast<unsigned>(time(0)));
    // some variables to store the fibonacci serie
    bigint_t a = 1, b = 0;
    // find a limit
    unsigned c = 0, limit = (rand() % 30) + 10;
    
    while (true)
    {
        // calculating the fibonacci serie and displaying it
        a += b;
        std::cout << a << " ";
        swapThem(&a, &b);
        c++;  // so much fun ^^
        
        if (c == limit)
            break;
    }
    std::cout << std::endl;
    
    return 0;
}
