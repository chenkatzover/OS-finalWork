#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sched.h>
#include <errno.h>

int set (int pid, int priority, int policy) {
    struct sched_param sp = { .sched_priority = priority };
    int ret = sched_setscheduler(pid, policy, &sp);
    // if (ret == -1) {
    //     perror("sched_setscheduler");
    //     exit (EXIT_FAILURE);
    // }
    switch (errno)
    {
    case EINVAL:
        printf("The priority or policy isn't a valid value. \n");        break;
    case EPERM:
        printf("The calling process doesn't have sufficient privilege to set the priority. \n");        break; 
    case ESRCH:
        printf("The process pid doesn'\n");        break;
    default:
        printf("OK\n");
    }
}

int main(int argc, char *argv[]) {
    printf("%d\n", getppid());
    if (argc < 3) {
        printf("no enough param\n");
        exit (EXIT_FAILURE);
    }

    int policy = atoi(argv[1]);
    int priority = atoi(argv[2]);

    set (0, priority, policy);
    
    exit(EXIT_SUCCESS);
 }