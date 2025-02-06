//
//  operation_mode.c
//  p2p_chat_c
//
//  Created by Gabriel Barbosa on 25/01/25.
//

#include "operation_mode.h"

int showOperationModeSetup(void) {
    int choice = 0;

    printf("%s\n", currentLocalization->selectOperationModeMessage);
    printf("1 - %s\n", currentLocalization->selectServerOperationModeMessage);
    printf("2 - %s\n", currentLocalization->selectClientOperationModeMessage);
    printf("Choice: ");

    return choice;
}
