//
//  menu.c
//  p2p_chat_c
//
//  Created by Gabriel Barbosa on 25/01/25.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../include/l10n/localization.h"
#include "../include/menu/menu.h"
#include "../include/utils/utils.h"

void _showMenuOptions(void) {
    for (int i = 0; i < MenuOptionTypesLength; i++) {
        const char *sourceString = NULL;

        switch (i) {
        case LanguageMenuOptionType:
            sourceString = currentLocalization->languageMenuOptionLabel;
            break;
        case StartChatMenuOptionType:
            sourceString = currentLocalization->startChatMenuOptionLabel;
            break;
        case ExitMenuOptionType:
            sourceString = currentLocalization->exitMenuOptionLabel;
            break;
        default:
            break;
        }

        if (sourceString == NULL) standardError("Invalid menu option type!");

        size_t length = strlen(sourceString) + 1;
        char *optionLabel = malloc(length * sizeof(char));
        if (optionLabel == NULL) memoryAllocationFailed();

        strcpy(optionLabel, sourceString);
        // Sum 1 to the index to show the option number starting from 1,
        // because will be read by getline() and atoi() functions,
        // which returns 0 if the input is not a number.
        printf("%d - %s\n", (i + 1), optionLabel);
        free(optionLabel);
    }
}

void showMenu(void) {
  printf("%s\n", currentLocalization->welcomeMessage);

  char separator[] = "--------------------------------------";

  while (1) {
    printf("%s\n", separator);
    _showMenuOptions();
    printf("%s\n", separator);

    char *buffer;
    size_t bufferSize = 4;
    buffer = (char *)malloc(bufferSize * sizeof(char));
    if (buffer == NULL) memoryAllocationFailed();

    // Read user input
    getline(&buffer, &bufferSize, stdin);
    int choice = atoi(buffer);

    printf("You entered: %i\n", choice);

    if (choice <= 0 || choice > MenuOptionTypesLength) {
        standardError("Invalid option. Try again.\n");
        continue;
    }

    switch (choice) {
        case 1:
            printf("Language\n");
            break;
        case 2:
            printf("Start Chat\n");
            break;
        case 3:
            exit(0);
            break;
        default:
            continue;
            break;
    }
  }
}
