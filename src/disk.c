#include <stdio.h>
#include <stdlib.h>
#include <sys/statvfs.h>
#include "util.h"
#include <dirent.h>
#include <sys/stat.h>
#include "disk.h"
// https://stackoverflow.com/questions/1653163/difference-between-statvfs-and-statfs-system-calls
// https://www.man7.org/linux/man-pages/man3/statvfs.3.html
int get_filesystem_stats(
    unsigned long long *out_total,
    unsigned long long *out_available,
    unsigned long long *out_used)
{
    const char *path = "/";
    struct statvfs st;
    if (statvfs(path, &st) != 0)
    {
        perror("statvfs");
        fprintf(stderr, "statvfs error.\n");

        return -1;
    }
    unsigned long long total = (unsigned long long)st.f_blocks * st.f_frsize;
    unsigned long long available = (unsigned long long)st.f_bavail * st.f_frsize;
    unsigned long long used = total - (unsigned long long)st.f_bfree * st.f_frsize;

    *out_total = total;
    *out_available = available;
    *out_used = used;

    return 0;
}

int print_total_space_info()
{
    unsigned long long total, avail, used;
    if (get_filesystem_stats(&total, &avail, &used) != 0)
    {
        fprintf(stderr, "Failed to get filesystem stats");
        return EXIT_FAILURE;
    }
    printf("Disk info:\n");
    printf("  Total:     %20llu bytes (%.2f GB)\n", total, bytes_to_gb(total));
    printf("  Available: %20llu bytes (%.2f GB)\n", avail, bytes_to_gb(avail));
    printf("  Used:      %20llu bytes (%.2f GB)\n", used, bytes_to_gb(used));
    return EXIT_SUCCESS;
}
