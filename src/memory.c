#define _GNU_SOURCE
#include <stdio.h>
#include <sys/sysinfo.h>
#include <unistd.h>
#include "util.h"
#include "memory.h"
#include <stdlib.h>
// https://stackoverflow.com/questions/14386856/c-check-currently-available-free-ram
// https://en.cppreference.com/w/c/program/EXIT_status
unsigned long get_available_ram_bytes()
{
    long pages = sysconf(_SC_AVPHYS_PAGES);
    long page_size = sysconf(_SC_PAGESIZE);

    if (pages == -1 || page_size == -1)
    {
        fprintf(stderr, "Failed to retrieve available RAM.\n");
        return -1;
    }

    return pages * page_size;
}

unsigned long get_total_ram_bytes()
{
    long pages = sysconf(_SC_PHYS_PAGES);
    long page_size = sysconf(_SC_PAGESIZE);

    if (pages == -1 || page_size == -1)
    {
        fprintf(stderr, "Failed to retrieve total RAM.\n");
        return -1;
    }

    return pages * page_size;
}

int print_ram_data()
{
    long avail_bytes = get_available_ram_bytes();
    long total_bytes = get_total_ram_bytes();
    long used_bytes = total_bytes - avail_bytes;
    if (avail_bytes == -1 || total_bytes == -1)
    {
        fprintf(stderr, "Failed to retrieve RAM information.\n");
        return EXIT_FAILURE;
    }
    printf("RAM info:\n");
    printf("  Total RAM:     %20ld bytes (%.2f GB)\n", total_bytes, bytes_to_gb(total_bytes));
    printf("  Available RAM: %20ld bytes (%.2f GB)\n", avail_bytes, bytes_to_gb(avail_bytes));
    printf("  Used RAM:      %20ld bytes (%.2f GB)\n", used_bytes, bytes_to_gb(used_bytes));

    return EXIT_SUCCESS;
}