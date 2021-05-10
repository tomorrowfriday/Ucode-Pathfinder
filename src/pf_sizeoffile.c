#include "pathfinder.h"

int pf_sizeoffile(const char *file)
{
    char *data = mx_file_to_str(file);
    int sizeoffile = 0;
    while (data[sizeoffile] != '\0') 
    {
        sizeoffile ++;
    }  
    return sizeoffile;       
}
