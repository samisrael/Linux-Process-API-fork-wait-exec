//C Program to create new process using Linux API system calls fork() and exit()

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    int pid;
    pid = fork();
    
    if (pid == 0) {
        printf("I am child, my pid is %d\n", getpid());
        printf("My parent's pid is: %d\n", getppid());
        exit(0);
    } else {
        printf("I am parent, my pid is %d\n", getpid());
        sleep(100);
        exit(0);
    }
}
