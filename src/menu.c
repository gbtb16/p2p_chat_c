//
//  menu.c
//  p2p_chat_c
//
//  Created by Gabriel Barbosa on 25/01/25.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../include/menu/menu.h"

void _defineMenuOptionsValues(MenuOption options[MenuOptionTypesLength]) {
    const int mustTruncateLabel = TRUNCATE_IF_MENU_OPTION_LABEL_IS_TOO_LONG;
    const int optionMaxLabelLength = MAX_MENU_OPTION_LABEL_LENGTH;

    for (int i = 0; i < MenuOptionTypesLength; i++) {
        MenuOption* pCrrentOption = &options[i];
        MenuOptionType* pType = &pCrrentOption->type;
        int* pChoiceNumber = &pCrrentOption->choiceNumber;
        char* pLabel = pCrrentOption->label;

        // Define the option parameters
        *pType = i;
        *pChoiceNumber = i + 1;

        //Define the option label for the current localization
        const char* pLocalizationLabel = "";
        switch (i) {
        case LanguageMenuOptionType:
            pLocalizationLabel = currentLocalization->languageMenuOptionLabel;
            break;
        case StartChatMenuOptionType:
            pLocalizationLabel = currentLocalization->startChatMenuOptionLabel;
            break;
        case ExitMenuOptionType:
            pLocalizationLabel = currentLocalization->exitMenuOptionLabel;
            break;
        default:
            break;
        }

        int localizationLabelLength = strlen(pLocalizationLabel);
        if (pLocalizationLabel == NULL || localizationLabelLength <= 0) {
            throwCriticalError("Localization label not found for the current option.");
        }

        // Copy the localization label to the option
        char effectiveLabel[optionMaxLabelLength];

        if (localizationLabelLength < optionMaxLabelLength) {
            strcpy(effectiveLabel, pLocalizationLabel);
        } else {
            char currentBuffer[optionMaxLabelLength];
            for (int i = 0; i < optionMaxLabelLength; i++) currentBuffer[i] = pLocalizationLabel[i];

            // If the label is too long, truncate it
            putNullTerminatorString(currentBuffer);
            if (mustTruncateLabel) truncateString(currentBuffer, optionMaxLabelLength);
            strcpy(effectiveLabel, currentBuffer);
        }

        strncpy(pLabel, effectiveLabel, optionMaxLabelLength);
    }
}

void _showMenuOptions(void) {
    MenuOption menuOptions[MenuOptionTypesLength];
    _defineMenuOptionsValues(menuOptions);

    for (int i = 0; i < MenuOptionTypesLength; i++) {
        MenuOption option = menuOptions[i];
        printf("%i - %s\n", option.choiceNumber, option.label);
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
    if (buffer == NULL) throwMemoryAllocationFailed();

    // Read user input
    getline(&buffer, &bufferSize, stdin);
    int choice = atoi(buffer);

    printf("You entered: %i\n", choice);

    if (choice <= 0 || choice > MenuOptionTypesLength) {
        throwStandardError("Invalid option. Try again.\n");
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
