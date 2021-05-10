#include "pathfinder.h"

int pf_numbersofstrings(const char *file)
{
    char *data = mx_file_to_str(file);
    int sizeoffile = 0;
    int numbersofstrings = 0;
    while (data[sizeoffile] != '\0') 
    {
        if (data[sizeoffile] == '\n') numbersofstrings ++;
    }  
    return numbersofstrings;       
}
