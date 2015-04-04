#include <err.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "arg.h"

char *argv0;

int
update()
{
    // iterate through files on FS via links
    // convert page content to text
    // diff page from previous
    // use heuristic to skip certain diffs
    // generate feed entries
    // write entries to file
    return 1;
}

static void
usage(int status)
{
    fprintf(status ? stderr : stdout,
            "usage: %s [-h] [-v] [-i interval]\n", argv0);
    exit(status);
}

int
main(int argc, char *argv[])
{
    unsigned int interval_secs = 300;

    ARGBEGIN {
        case 'v':
            printf("tildefeed-"VERSION", © 2015 Charles E. Lehner\n");
            return 0;
        case 'i':
            interval_secs = atoi(EARGF(usage(1)));
            break;
        case 'h':
            usage(0);
        default:
            usage(1);
    } ARGEND;

    while (update() == 0)
        sleep(interval_secs);
    errx(1, "Update failed");
}
