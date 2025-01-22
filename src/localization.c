//
//  localization.c
//  p2p_chat_c
//
//  Created by Gabriel Barbosa on 22/01/25.
//

#include <stdio.h>

#include "../include/localization/localization.h"

// Default language
const Localization *currentLocalization = &localizations[LangTypeEn];

int askLanguageChoice(void) {
    int choice = 0;

    printf("Select language:\n");
    printf("0 - English (Default)\n");
    printf("1 - Portuguese\n");
    printf("Press Enter to select default language\n");
    printf("Choice: ");

    // Lê a escolha do usuário e verifica se a entrada é válida
    char inputBuffer[10];
    if (fgets(inputBuffer, sizeof(inputBuffer), stdin) != NULL) {
        // Se o usuário digitou algo, tentamos converter para inteiro
        if (sscanf(inputBuffer, "%d", &choice) != 1) {
            // Se não for possível converter para número, define 0 (English)
            choice = 0;
        }
    }

    return choice;
}

void setLanguage(LanguageType type) {
    if (type >= 0 && type < TotalNumberOfLanguages) {
        currentLocalization = &localizations[type];
        printf("%s\n\n", currentLocalization->languageSetMessage);
    } else {
        printf("Invalid language. Defaulting to English.\n\n");
        currentLocalization = &localizations[LangTypePt];
    }
}
