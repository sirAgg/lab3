#include <iostream>

bool greater_than(int* a, int* b)
{
    return *a > *b;
}

bool less_than(int* a, int* b)
{
    return *a < *b;
}

void swap_sort(int* a, int* b, bool (*sort_func)(int*,int*))
{
    // swaps a and b if sort_func is true
    if(sort_func(a,b))
    {
        *a = *b-*a;
        *b -= *a;
        *a += *b;
    }
}

void swap_sort(int* a, int* b, int* c, bool acsending_order)
{
    bool (*sort_func)(int*,int*) = acsending_order ? greater_than : less_than;

    swap_sort(a,b,sort_func); 
    swap_sort(b,c,sort_func); 
    swap_sort(a,b,sort_func); 
}

#define askValue(v) std::cout << "Give value " #v ": "; std::cin >> v;

int main(void)
{
    int a,b,c;
    
    askValue(a)
    askValue(b)
    askValue(c)

    char ans;

    std::cout << "Sort ascending? (Y/n) ";
    std::cin >> ans;

    bool sort_ascending = ans != 'n';

    swap_sort(&a,&b,&c,sort_ascending);

    std::cout << "Result: " << a << ", " << b << ", " << c << std::endl;

    return 0;
}
