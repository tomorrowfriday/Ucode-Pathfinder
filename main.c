#include "inc/pathfinder.h"

int main(int argc, const char **file) 
{
    if(argc > 2)
    {
        printf("There is more than 1 file\n");
        exit(1);
    }
    if(argc < 2)
    {
        printf("There is no file\n");
        exit(1);
    }
    char *data = mx_file_to_str(file[1]);
    int sizeoffile = pf_sizeoffile(file[1]);
    int numbersofstrings = pf_numbersofstrings(file[1]);

    char *stringsoffile[numbersofstrings]; 
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
    for(int x = 0; x < numbersofstrings; x++)
    {
    printf("%s", stringsoffile[x]);
    }
    system("leaks -q a.out");
    return 0;
}
