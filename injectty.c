#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/ioctl.h>
#include <termios.h>

void print_help(char *prog_name) {
    printf("[InjecTTY] - Runtime Shell Process Injector");
    printf("Usage: %s [-n] DEVNAME COMMAND\n", prog_name);
    printf("DEVNAME eg /dev/tty1. | -n is a optional flag to newline\n");
    printf("Run as root or sudo. [or sudo su]\n");
    exit(1);
}

int main (int argc, char *argv[]) {
    char *cmd, *nl = "\n";
    int i, fd;
    int devno, commandno, newline;
    int mem_len;

    cmd = NULL;  // Line 28 edited
    devno = 1; commandno = 2; newline = 0;

    if (argc < 3) {
        print_help(argv[0]);
    }
    if (argc > 3 && argv[1][0] == '-' && argv[1][1] == 'n') {
        devno = 2; commandno = 3; newline = 1;
    } else if (argc > 3 && argv[1][0] == '-' && argv[1][1] != 'n') {
        printf("Invalid Option\n");
        print_help(argv[0]);
    }

    fd = open(argv[devno], O_RDWR);
    if (fd == -1) {
        perror("open DEVICE");
        exit(1);
    }

    mem_len = 0;
    for (i = commandno; i < argc; i++) {
        mem_len += strlen(argv[i]) + 2;
        if (i > commandno) {
            cmd = (char *)realloc((void *)cmd, mem_len);
        } else {
            cmd = (char *)malloc(mem_len);
            cmd[0] = '\0';  // Line 43 edited
        }
        strcat(cmd, argv[i]);
        strcat(cmd, " ");
    }

    if (newline == 0)
        usleep(225000);
    for (i = 0; cmd[i]; i++) {
        ioctl(fd, TIOCSTI, cmd + i);  // Line 50 edited
        usleep(20000);                // Line 51 edited
    }
    if (newline == 1)
        ioctl(fd, TIOCSTI, nl);

    close(fd);
    free((void *)cmd);
    exit(0);
}
