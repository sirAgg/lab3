#include <iostream>

int string_lenght(const char * s)
{
    int size;
    for(size = 0; *(s+size) != '\0'; size++);
    return size;
}

void print_lenght(const char* s)
{
    std::cout << "Length of " << s << " is: " << string_lenght(s) << std::endl;
}

int main(void)
{
    print_lenght("hello");
    print_lenght("there");
    print_lenght("is");
    print_lenght("it");
    print_lenght("you");
    print_lenght("lkösadjflkj");

    return 0;
}
