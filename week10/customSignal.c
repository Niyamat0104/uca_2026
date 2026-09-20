#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

// Global variable to count signal triggers
volatile sig_atomic_t signal_count = 0;

// TODO: Write your signal handler function here
void handle_sigint(int sig) {
    signal_count++;
    if(signal_count < 3) {
        printf("\n SIGNINT reeceived !\n");
        printf("Press Ctrl+C %d more times to exit \n",3 - signal_count);

    }
    else{
        printf("\n SIGINT reccived 3 times ,Exiting ... \n");
        exit(0);
    }

}

int main() {
    // TODO: Register the signal handler.

    signal(SIGINT,handle_sigint);
    printf("Program running (PID: %d). Try pressing Ctrl+C...\n", getpid());

    while (1) {
        sleep(1);
    }

    return 0;
}