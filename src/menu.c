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

void _showMenuOptions(void) {
    for (int i = 0; i < MenuOptionTypesLength; i++) {
        const char* sourceString = NULL;

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

        if (sourceString == NULL) {
            continue;
        }

        size_t length = strlen(sourceString) + 1;
        char *optionLabel = malloc(length * sizeof(char));
        if (optionLabel == NULL) {
            printf("ERROR: Memory allocation failed!\n");
            continue;
        }

        strcpy(optionLabel, sourceString);
        printf("%d - %s\n", i, optionLabel);
        free(optionLabel);
    }
}

void showMenu(void) {
  printf("%s\n", currentLocalization->welcomeMessage);


  while (1) {
    _showMenuOptions();

    char string[100];
    char* stringPtr = string;
    long choice;

    while (fgets(stringPtr, sizeof(&stringPtr), stdin)) {
        choice = strtol(string, &stringPtr, 10);

        if (stringPtr == string || *stringPtr != '\n') {
            printf("Please enter an integer!\n");
        } else break;
    }
    printf("You entered: %ld\n", choice);

    if (choice < 0 || choice > MenuOptionTypesLength) {
      continue;
    }

    switch (choice) {
        case 0:
            printf("Language\n");
            break;
        case 1:
            printf("Start Chat\n");
            break;
        case 2:
            exit(0);
            break;
        default:
            continue;
            break;
    }
  }
}
