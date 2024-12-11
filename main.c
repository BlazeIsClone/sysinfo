#include <stdio.h>

extern void get_cpu();
extern void get_ram();
extern void get_os();

void init_boot() {
    printf("---\n");
}

int main() {
    init_boot();

    get_cpu();
    get_ram();
    get_os();

    return 0;
}
