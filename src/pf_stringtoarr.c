#include "pathfinder.h"

char **pf_stringtoarr(char *data, int sizeoffile, int numbersofstrings)
{
    char **stringsoffile = NULL;    
    int sortoffile = 0;
    int strlen = 0;
    for(int x = 0; x < numbersofstrings; x++)
    {
    stringsoffile[x] = NULL;
    }
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
