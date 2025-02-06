//
//  localization.c
//  p2p_chat_c
//
//  Created by Gabriel Barbosa on 22/01/25.
//

#include "localization.h"

int showLanguageSetup(void) {
    int choice = 0;

    printf("Select language:\n");
    printf("0 - English (Default)\n");
    printf("1 - Portuguese\n");
    printf("Press Enter to select default language\n");
    printf("Choice: ");

    // Read the user's choice and check if the input is valid
    char inputBuffer[10];
    if (fgets(inputBuffer, sizeof(inputBuffer), stdin) != NULL) {
        // If the user typed something, try to convert to number
        if (sscanf(inputBuffer, "%d", &choice) != 1) {
            // If it's not possible to convert to number, set to 0 (English)
            choice = 0;
        }
    }

    return choice;
}

void setLanguage(LanguageType type) {
    if (type >= LanguageTypesLength) {
        printf("Invalid language choice. Defaulting to English.\n\n");
        return;
    }

    if (type > 0) {
        currentLocalization = &localizations[type];
    }

    printf("%s\n\n", currentLocalization->languageSetMessage);
}
