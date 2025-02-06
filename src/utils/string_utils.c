//
//  string_utils.c
//  p2p_chat_c
//
//  Created by Gabriel Barbosa on 06/02/25.
//

#include "string_utils.h"

void putNullTerminatorString(char *pString) {
    if (pString == NULL) return;

    int stringLength = (int) strlen(pString);
    if (pString[stringLength] != '\0') pString[stringLength] = '\0';
}

void truncateString(char *pLabel, int maxLength) {
    if (pLabel == NULL || maxLength < 4) return;

    int labelLength = (int) strlen(pLabel);
    if (labelLength <= maxLength) return;

    pLabel[maxLength - 4] = '.';
    pLabel[maxLength - 3] = '.';
    pLabel[maxLength - 2] = '.';
    pLabel[maxLength - 1] = '\0';
}
