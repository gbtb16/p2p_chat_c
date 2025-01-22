//
//  main.c
//  p2p_chat_c
//
//  Created by Gabriel Barbosa on 22/01/25.
//

#include <stdio.h>

#include "../include/localization/localization.h"

int main(int argc, char *argv[]) {
    int choice = askLanguageChoice();
    setLanguage((LanguageType)choice);

    printf("%s\n", currentLocalization->welcomeMessage);
    printf("%s\n", currentLocalization->selectOperationModeMessage);

    return 0;
}
