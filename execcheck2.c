//C Program to execute Linux system commands using Linux API system calls exec() family

#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <unistd.h>

int main() {
    int status;

    printf("Running ps with execlp\n");
    execlp("ps", "ps", "ax", NULL);
    wait(&status);
    if (WIFEXITED(status))
        printf("child exited with status of %d\n", WEXITSTATUS(status));
    else
        puts("child did not exit successfully\n");
    printf("Done.\n");

    printf("Running ps with execlp. Now with path specified\n");
    execl("/bin/ps", "ps", "ax", NULL);
    wait(&status);
    if (WIFEXITED(status))
        printf("child exited with status of %d\n", WEXITSTATUS(status));
    else
        puts("child did not exit successfully\n");
    printf("Done.\n");

    exit(0);
}
