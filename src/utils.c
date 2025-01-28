//
//  utils.c
//  p2p_chat_c
//
//  Created by Gabriel Barbosa on 28/01/25.
//

#include <stdio.h>
#include <stdlib.h>

void standardError(const char *message) {
    printf("ERROR: %s\n", message);
}

void criticalError(const char *message) {
    printf("CRITICAL ERROR: ");
    perror(message);
    exit(1);
}

void memoryAllocationFailed(void) {
    criticalError("Memory allocation failed! Use Breakpoints to debug.");
}
