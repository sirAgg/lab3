#include <iostream> 

float avrage_salery(const float* salaries, int n_employees)
{
    float tot_salary = 0.0f;
    for (int i = 0; i < n_employees; ++i)
        tot_salary += *(salaries+i);
        
   return tot_salary/(float)n_employees; 
}

int main(void)
{
    int n_employees;
    std::cout << "Enter number of n_employees: ";
    std::cin >> n_employees;

    float* salaries = new float[n_employees];
    
    for (int i = 0; i < n_employees; ++i) 
    {
        std::cout << "Enter employee salary: ";
        std::cin >> *(salaries+i);
    }

    std::cout << "Average salary: " << avrage_salery(salaries, n_employees) << std::endl;

    return 0;
}
