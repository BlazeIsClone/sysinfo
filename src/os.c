#include <stdio.h>
#include <unistd.h>
#include <sys/utsname.h>

void get_os() {
    struct utsname buffer;

    if (uname(&buffer) != 0) {
        perror("uname");
        return;
    }

    printf("system: %s\n", buffer.sysname);
    printf("node: %s\n", buffer.nodename);
    printf("release: %s\n", buffer.release);
    printf("version: %s\n", buffer.version);
    printf("machine: %s\n", buffer.machine);
}


