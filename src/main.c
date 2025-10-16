#define _GNU_SOURCE
#include <stdio.h>
#include <sys/sysinfo.h>
#include <unistd.h>
#include "memory.h"
#include "disk.h"
#include "util.h"


int main(int argc, char *argv[])
{
    if (argc == 1)
    {
        // no args provided
        printf("No arguments provided. Use -h for help.\n");
        return 0;
    }
    int opt;
    // https://www.geeksforgeeks.org/c/getopt-function-in-c-to-parse-command-line-arguments/
    while ((opt = getopt(argc, argv, ":hmd")) != -1)
    {
        switch (opt)
        {
        case 'h':
            print_help();
            break;
        case 'm':
            print_ram_data();
            break;
        case 'd':
            print_total_space_info();
            break;
        case '?':
            printf("Unknown option: -%c\n", optopt);
            printf("Use -h or -H for help\n");
            return 0;
        }
    }

    return 0;
}