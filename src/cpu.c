#include <stdio.h>
#include <sys/utsname.h>
#include <unistd.h>

void get_cpu() {
    long cores = sysconf(_SC_NPROCESSORS_ONLN);
    if (cores == -1) {
        perror("sysconf");
        return;
    }

    printf("cores: %ld\n", cores);
}