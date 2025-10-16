#include <stdio.h>
#include "util.h"
double bytes_to_gb(unsigned long long bytes)
{
    return (double)bytes / (1024.0 * 1024.0 * 1024.0);
}

void print_help()
{
    printf("Display disk/ram usage.\n\n");
    printf("Possible arguments:\n");
    printf("-h    Get help\n");
    printf("-d    Display disk usage\n");
    printf("-m    Display memory usage\n\n");
    printf("Examples:\n");
    printf("sys_info -d\n");
    printf("-> Available RAM: 23.03 GB\n-> Total RAM:     31.02 GB\n");
}
