#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/mman.h>
#include <fcntl.h>
#include <dlfcn.h>
#include <stdarg.h>
#include <string.h>
#include <setjmp.h>

int global_var = 10;
jmp_buf buf;

void test_va_args(int count, ...) {
    va_list args;
    va_start(args, count);
    for (int i = 0; i < count; i++) {
        printf("Arg %d: %d\n", i, va_arg(args, int));
    }
    va_end(args);
}

void signal_handler(int signum) {
    printf("Caught signal %d\n", signum);
    longjmp(buf, 1);
}

int main(void) {
    // Memory allocation
    int *arr = (int *)malloc(sizeof(int) * 5);
    if (!arr) return 1;
    memset(arr, 0, sizeof(int) * 5);

    // File handling
    int fd = open("testfile.txt", O_CREAT | O_RDWR, 0644);
    if (fd >= 0) {
        write(fd, "Hello, AFL!", 12);
        close(fd);
    }

    // Dynamic library loading
    void *handle = dlopen("libc.so.6", RTLD_LAZY);
    if (handle) dlsym(handle, "printf");

    // POSIX syscalls
    pid_t pid = getpid();
    printf("Process ID: %d\n", pid);

    // Setjmp/Longjmp test
    if (setjmp(buf) == 0) {
        raise(SIGTERM);  // Trigger a signal
    }

    // Variable argument function
    test_va_args(3, 10, 20, 30);

    free(arr);
    return 0;
}