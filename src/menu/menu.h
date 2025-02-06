//
//  menu.h
//  p2p_chat_c
//
//  Created by Gabriel Barbosa on 25/01/25.
//

#pragma once
#ifndef _MENU_H_
#define _MENU_H_

#include <string.h>
#include <stdlib.h>

#include "../l10n/localization.c"
#include "../utils/errors.c"
#include "../utils/string_utils.c"

#define TRUNCATE_IF_MENU_OPTION_LABEL_IS_TOO_LONG 1
#define MAX_MENU_OPTION_LABEL_LENGTH 32

// Enum for the different types of menu options.
typedef enum {
    LanguageMenuOptionType,
    StartChatMenuOptionType,
    ExitMenuOptionType,
    MenuOptionTypesLength
} MenuOptionType;

// Struct for a menu option.
// type: The type of the menu option.
// choiceNumber: The number of the choice in the menu.
// label: The label of the menu option.
typedef struct MenuOption {
    MenuOptionType type;
    int choiceNumber;
    char label[MAX_MENU_OPTION_LABEL_LENGTH];
} MenuOption;

// Show the entire menu.
void showMenu(void);

// Show the menu options.
//
// Must be used only in [showMenu] function.
static void showMenuOptions(void);

// Define the values for the menu options.
//
// Must be used only in [showMenuOptions] function.
static void defineMenuOptionsValues(MenuOption options[MenuOptionTypesLength]);

#endif // _MENU_H_
