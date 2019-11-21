#include <iostream>
#include <string>
#include <string.h>

void replace_chars(char * text, char search_char, char new_char)
{
    while( *text != '\0' )
    {
        if (*text == search_char)
            *text = new_char;

        text++;
    }
}

int main(void)
{
    const char cs[] = "Hello There How are you";

    char s[sizeof(cs)];
    strcpy(s,cs);

    replace_chars(s, 'e', 'a');
    std::cout << s << std::endl;
    
    return 0;
}
