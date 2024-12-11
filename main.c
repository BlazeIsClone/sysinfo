#include <stdio.h>
#include <unistd.h>
#include <sys/utsname.h>

void get_os() {
    struct utsname buffer;

    if (uname(&buffer) != 0) {
        perror("uname");
        return;
    }

    printf("System Name: %s\n", buffer.sysname);
    printf("Node Name: %s\n", buffer.nodename);
    printf("Release: %s\n", buffer.release);
    printf("Version: %s\n", buffer.version);
    printf("Machine: %s\n", buffer.machine);
}

void get_cpu() {
    long cores = sysconf(_SC_NPROCESSORS_ONLN);
    if (cores == -1) {
        perror("sysconf");
        return;
    }

    printf("cpu_cores: %ld\n", cores);
}

void get_ram() {
    long pages = sysconf(_SC_PHYS_PAGES);
    long page_size = sysconf(_SC_PAGE_SIZE);

    if (pages == -1 || page_size == -1) {
        perror("sysconf");
        return;
    }

    long long total_ram = (long long)pages * (long long)page_size;

    printf("ram: %.2f GB\n", total_ram / (1024.0 * 1024.0 * 1024.0));
}

int main() {
    get_cpu();
    get_ram();
    get_os();
    return 0;
}
