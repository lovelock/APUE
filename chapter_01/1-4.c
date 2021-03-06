#include "../apue.h"

#define BUFFSIZE 4096

/**
 * I/O without buffer, open/read/write/lseek/close work with file handler
 */
int
main(void)
{
    int n;
    char buf[BUFFSIZE];

    while ( (n = read(STDIN_FILENO, buf, BUFFSIZE)) > 0) {
        if (write(STDOUT_FILENO, buf, n) != n) {
            err_sys("write error");
        }
    }

    if (n < 0) {
        err_sys("read error");
    }

    exit(0);
}
