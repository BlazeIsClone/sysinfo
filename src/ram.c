#include <stdio.h>
#include <sys/utsname.h>
#include <unistd.h>

void get_ram()
{
    long pages = sysconf(_SC_PHYS_PAGES);
    long page_size = sysconf(_SC_PAGE_SIZE);

    if (pages == -1 || page_size == -1)
    {
        perror("sysconf");
        return;
    }

    double byte_size = 1024.0;

    long long total_ram = (long long)pages * (long long)page_size;

    printf("ram: %.2f GB\n", total_ram / (byte_size * byte_size * byte_size));
}
