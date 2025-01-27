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

  char separator[] = "--------------------------------------";
  printf("%s\n", separator);

  while (1) {
    _showMenuOptions();
    printf("%s\n", separator);

    int choiceStringSize = 10;
    char *choiceString = malloc(choiceStringSize * sizeof(char));
    if (choiceString == NULL) {
        printf("ERROR: Memory allocation failed!\n");
        continue;
    }

    // Read user input
    if (fgets(choiceString, choiceStringSize, stdin) == NULL) {
        free(choiceString);
        continue;
    }

    // Check if the input is too long
    if (strchr(choiceString, '\n') == NULL) {
        int c;
        // Clear the input buffer
        while ((c = getchar()) != '\n' && c != EOF);
    }

    // Remove the newline character from the input
    size_t stringLength = strlen(choiceString);
    if (stringLength > 0 && choiceString[stringLength - 1] == '\n') {
        choiceString[stringLength - 1] = '\0';
    }

    // Convert the input to a number
    char *endptr;
    long choice = strtol(choiceString, &endptr, 10);

    // Check if the input is a valid number
    if (*endptr != '\0') {
        printf("Invalid input. Please enter a valid number.\n");
        free(choiceString);
        continue;
    }

    printf("You entered: %ld\n", choice);
    free(choiceString);

    if (choice < 0 || choice > MenuOptionTypesLength) {
        printf("Invalid option. Try again.\n");
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
