#include "pathfinder.h"

char **pf_stringtoarr(char *data, int sizeoffile)
{
    char **stringsoffile = malloc(sizeof(char*) * sizeoffile);    
    int sortoffile = 0;
    int strlen = 0;
    int countofstring = 0;
    for(;sortoffile < sizeoffile; sortoffile++)
    {
        if (data[sortoffile] != '\n')
        {
        strlen ++;
        }
        if (data[sortoffile] == '\n')
        {
            stringsoffile[countofstring] = mx_strnew(strlen);
                for(int x = 0; x <= strlen; x++)
                {
                    stringsoffile[countofstring][x] = data[sortoffile - strlen + x];
                }
        countofstring ++;  
        strlen = 0;
        }    
    }   
    return stringsoffile; 
}
