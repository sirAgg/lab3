#include <iostream>
#include <vector>
#include <string>
#include <stdio.h>

bool init_database( std::vector<std::string>* names )
{
    std::cout << "Are you sure? (yes/no)" << std::endl;
    while (true)
    {
        std::string input; 
        std::cin >> input;

        if (input == "yes")
            break;
        else if (input == "no")
            return false;
        else
            std::cout << "Please type 'yes' or 'no'" << std::endl;
        
    }
    names->clear();
    return true;
}

void insert_name( std::vector<std::string>* names )
{
    while(true)
    {
        std::string new_name;
        std::cout << "Insert name ('q' to quit): ";  
        std::cin >> new_name;
        if (new_name == "Q" || new_name == "q")
            break;

        (*names).push_back(new_name);
    }
}

void search_name( const std::vector<std::string>* names )
{
    std::string search_name;
    std::cout << "search: ";
    std::cin >> search_name;

    for( auto name : *names )
    {
        if( search_name.length() <=  name.length())  
            if (search_name == name.substr(0,search_name.length()))
                std::cout << name << std::endl;
    }
}

void delete_name( std::vector<std::string>* names )
{
    std::string name;
    std::cout << "delete name: ";
    std::cin >> name;

    for (auto it = (*names).cbegin(); it != (*names).cend(); it++) 
    {
        if (name == *it)
        {
            (*names).erase(it);
            return;
        }
    }
    std::cout << "name not found" << std::endl;
}

void print_names( const std::vector<std::string>* names )
{
    for (auto name : *names) 
        std::cout << name << std::endl;
}

void save_names( std::vector<std::string>* names )
{
    std::string filename;

    std::cout << "Enter filename: ";
    std::cin >> filename;

    FILE* file = fopen(filename.c_str(), "w");

    for (auto name : *names)
        fprintf(file, "%s\n",name.c_str() );

    fclose(file);
}

void load_names( std::vector<std::string>* names )
{
    std::string filename;
    
    std::cout << "Enter filename: ";
    std::cin >> filename;
    
    FILE* file = fopen(filename.c_str(), "r");

    if(!file)
    {
        std::cout << "File does not exist" << std::endl; 
        return;
    }
    
    if( !init_database( names ) )
    {
        fclose(file);
        return;
    }

    char s[100];
    while(fscanf(file,"%s\n", s) != EOF)
        (*names).push_back(s);

    fclose(file);
}

void task_6()
{
    std::vector<std::string> names = std::vector<std::string>();
    while(true)
    {
        std::cout << "\nMENU:" << std::endl; 
        std::cout << 
            "1. Intialise Database\n"
            "2. Insert\n"
            "3. Search\n"
            "4. Delete\n"
            "5. Print\n"
            "6. Save\n"
            "7. Load\n"
            "0. Quit\n";

        int input;
        std::cin >> input;
        std::cout << "\n";
        
        switch (input) {
            case 0: return;
            case 1: init_database(&names); break;
            case 2: insert_name(&names); break;
            case 3: search_name(&names); break;
            case 4: delete_name(&names); break;
            case 5: print_names(&names); break;
            case 6: save_names(&names); break;
            case 7: load_names(&names); break;

            default:
                    std::cout << "Not a valid option" << std::endl;
        }
    }
}

int main(void)
{
    task_6();

    return 0;
}
