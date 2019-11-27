#include <iostream>
#include <vector>
#include <string>
#include <stdio.h>

void init_database( std::vector<std::string>* names )
{
    names->clear();
}

void insert_name( std::vector<std::string>* names, std::string& name )
{
    (*names).push_back(name);
}

bool search_name( const std::vector<std::string>* names, std::string& search_name )
{
    bool found_name = false;
    for( auto name : *names )
    {
        if( search_name.length() <=  name.length())  
            if (search_name == name.substr(0,search_name.length()))
            {
                std::cout << name << std::endl;
                found_name = true;
            }
    }
    return found_name;
}

bool delete_name( std::vector<std::string>* names, std::string& name )
{

    for (auto it = (*names).cbegin(); it != (*names).cend(); it++) 
    {
        if (name == *it)
        {
            (*names).erase(it);
            return true;
        }
    }
    return false;
}

void print_names( const std::vector<std::string>* names )
{
    for (auto name : *names) 
        std::cout << name << std::endl;
}

bool save_names( const std::vector<std::string>* names, std::string& filename )
{

    FILE* file = fopen(filename.c_str(), "w");
    
    if(!file)
        return false;

    for (auto name : *names)
        fprintf(file, "%s\n",name.c_str() );

    fclose(file);
    return true;
}

bool load_names( std::vector<std::string>* names, std::string& filename )
{
    
    FILE* file = fopen(filename.c_str(), "r");

    if(!file)
    {
        return false;
    }

    char s[100];
    while(fscanf(file,"%s\n", s) != EOF)
        (*names).push_back(s);

    fclose(file);

    return true;
}

bool ask_conformation()
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
    return true;
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
            // quit
            case 0: return;

            // init database       
            case 1: {
                        std::cout << "Clear all data." << std::endl;
                        if(!ask_conformation())
                            break;
                        init_database(&names);
                    } break;

            // inset names
            case 2: 
                while(true)
                {
                    std::string new_name;
                    std::cout << "Insert name ('q' to quit): ";  
                    std::cin >> new_name;
                    if (new_name == "Q" || new_name == "q")
                        break;
                    insert_name(&names, new_name);
                }
                break;

            //  search name
            case 3: {
                    std::string s_name;
                    std::cout << "search: ";
                    std::cin >> s_name;
                    if(!search_name(&names, s_name))
                        std::cout << "No matching names." << std::endl;
                    } break;

            // delete name
            case 4: {
                        std::string d_name;
                        std::cout << "delete name: ";
                        std::cin >> d_name;
                        if(delete_name(&names, d_name))
                            std::cout << "Named removed" << std::endl;
                        else
                            std::cout << "Name not found." << std::endl;
                    } break;

            // print names
            case 5: print_names(&names); break;

            // save to file
            case 6: {
                        std::string filename;

                        std::cout << "Enter filename: ";
                        std::cin >> filename;

                        if(save_names(&names, filename))
                            std::cout << "File saved" << std::endl;
                        else
                            std::cout << "Could not save file" << std::endl;
                    } break;

            // load form file
            case 7: {
                        std::cout << "Loading a file will override the current data." << std::endl;
                        if(!ask_conformation())
                            break;

                        init_database(&names);
                        
                        std::string filename;
                        std::cout << "Enter filename: ";
                        std::cin >> filename;

                        if(load_names(&names, filename))
                            std::cout << "File loaded." << std::endl;
                        else
                            std::cout << "File does not exists." << std::endl;
                    } break;

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
