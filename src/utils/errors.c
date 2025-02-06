//
//  errors.c
//  p2p_chat_c
//
//  Created by Gabriel Barbosa on 28/01/25.
//

#include "errors.h"

void throwStandardError(const char *message) {
    printf("ERROR: %s\n", message);
}

void throwCriticalError(const char *message) {
    printf("CRITICAL ERROR: %s\n", message);
    exit(-1);
}

void throwMemoryAllocationFailed(void) {
    throwCriticalError("Memory allocation failed! Use Breakpoints to debug.");
}
