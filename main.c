#include "pathfinder.h"


int main(int argc, char *argv[]) 
{
    mx_printstr(" ************************\n *\topenFile\t*\n ************************\n\n");

    printf("%s\n", mx_file_to_str("Ilands.txt"));

    system("leaks -q a.out");
    return 0;
}
