#include <stdio.h>
#include <string.h>
#include "funcs.h"
#include "test.h"
#include "my_task.h"

void help_info(void)
{
    printf("========================================\n");
    printf("           Program Help Menu            \n");
    printf("========================================\n");
    printf("Usage:\n");
    printf("  ./program [OPTIONS]\n\n");
    
    printf("Available Options:\n");
    printf("  %-15s %s\n", "-help",      "Show this help message");
    printf("  %-15s %s\n", "-test",      "Run test cases (use with -root and/or -integral)");
    printf("  %-15s %s\n", "-root",      "Run root-finding tests (used with -test)");
    printf("  %-15s %s\n", "-integral",  "Run integral calculation tests (used with -test)");
    printf("  %-15s %s\n", "-roots",     "Display roots of the function in main task");
    printf("  %-15s %s\n", "-iters",     "Display iteration process of the method");
    
    printf("\nExamples:\n");
    printf("  ./program -help\n");
    printf("  ./program -test -root -integral\n");
    printf("  ./program -roots -iters\n");
    printf("========================================\n");
}

int main(int argc, char *argv[])
{
    if (argc >= 2) {
        if (!strcmp(argv[1], "-help")) {
            help_info();
            return 0;
        }
        if (!strcmp(argv[1], "-test")) {
            for (int i = 2; i < argc; i++) {
                if (!strcmp(argv[i], "-root")) {
                    test_root();
                }
                else if (!strcmp(argv[i], "-integral")) {
                    test_integral();
                }
            }
            return 0;
        }
    }

    char print = 0;
    char iter = 0;
    for (int i = 1; i < argc; i++) {
        if (!strcmp(argv[i], "-roots")) {
            print = 1;
        }
        else if (!strcmp(argv[i], "-iters")) {
            iter = 1;
        }
    }
    my_task(print, iter);
    return 0;
}