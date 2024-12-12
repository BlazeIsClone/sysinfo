#include <stdio.h>

extern void get_cpu();
extern void get_ram();
extern void get_os();
extern void get_disk();

const char *sysinfo_version()
{
    return "1.0.0";
}

void init_boot()
{
    printf("sysinfo: v%s\n", sysinfo_version());
}

int main()
{
    init_boot();

    get_cpu();
    get_ram();
    get_disk();
    get_os();

    return 0;
}
