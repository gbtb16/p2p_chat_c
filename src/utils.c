//
//  utils.c
//  p2p_chat_c
//
//  Created by Gabriel Barbosa on 28/01/25.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../include/utils/utils.h"

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

void putNullTerminatorString(char *pString) {
    if (pString == NULL) return;

    int stringLength = strlen(pString);
    if (pString[stringLength] != '\0') pString[stringLength] = '\0';
}

void truncateString(char *pLabel, int maxLength) {
    if (pLabel == NULL || maxLength < 4) return;

    int labelLength = strlen(pLabel);
    if (labelLength <= maxLength) return;

    pLabel[maxLength - 4] = '.';
    pLabel[maxLength - 3] = '.';
    pLabel[maxLength - 2] = '.';
    pLabel[maxLength - 1] = '\0';
}
