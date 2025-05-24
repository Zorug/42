#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

#define BOLD_RED "\033[1;31m"
#define RESET    "\033[0m"

long get_elapsed_time_microseconds(struct timeval start, struct timeval end)
{
    return (end.tv_sec - start.tv_sec) * 1000000L + (end.tv_usec - start.tv_usec);
}

void precise_usleep(long usec) {
    struct timeval start, current;
    long elapsed;
    long rem;

    gettimeofday(&start, NULL);
    do {
        gettimeofday(&current, NULL);
        elapsed = get_elapsed_time_microseconds(start, current);
        rem = usec - elapsed;

        if (rem > 1000) 
            usleep(rem / 2);
        
    } while (elapsed < usec);
}

int main(void) 
{
    struct timeval start;
    struct timeval end;
    long seconds;
    long microseconds;
    double elapsed;

    gettimeofday(&start, NULL);
    precise_usleep(500000);
    gettimeofday(&end, NULL);
    seconds = end.tv_sec - start.tv_sec;
    microseconds = end.tv_usec - start.tv_usec;
    elapsed = seconds + microseconds * 1e-6;
    
    printf("Expected sleep duration: "BOLD_RED"\t0.5"RESET" seconds\n");
    printf("Actual sleep duration: "BOLD_RED"\t\t%f"RESET" seconds\n\n", elapsed);
    return (0);
}