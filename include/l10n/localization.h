//
//  localization.h
//  p2p_chat_c
//
//  Created by Gabriel Barbosa on 22/01/25.
//

#pragma once
#ifndef _LOCALIZATION_H_
#define _LOCALIZATION_H_

#include "localization_en.h"
#include "localization_pt.h"

// Enum for languages.
typedef enum {
    EnglishLanguageType,
    PortugueseLanguageType,
    LanguageTypesLength
} LanguageType;

// Localization structure with all the messages available in the application.
typedef struct {
    const char* languageSetMessage;
    const char* welcomeMessage;
    const char* languageMenuOptionLabel;
    const char* startChatMenuOptionLabel;
    const char* exitMenuOptionLabel;
    const char* selectOperationModeMessage;
    const char* selectServerOperationModeMessage;
    const char* selectClientOperationModeMessage;
    const char* typePeerIpMessage;
    const char* typePeerPortMessage;
    const char* goodbyeMessage;
} Localization;

// Array of localizations.
static const Localization localizations[LanguageTypesLength] = {
    [EnglishLanguageType] = {
        .welcomeMessage = LANG_EN_WELCOME_MSG,
        .languageMenuOptionLabel = LANG_EN_LANGUAGE_MENU_OPTION_LABEL,
        .startChatMenuOptionLabel = LANG_EN_START_CHAT_MENU_OPTION_LABEL,
        .exitMenuOptionLabel = LANG_EN_EXIT_MENU_OPTION_LABEL,
        .languageSetMessage = LANG_EN_LANGUAGE_SET_MSG,
        .selectOperationModeMessage = LANG_EN_SELECT_OP_MODE_MSG,
        .selectServerOperationModeMessage = LANG_EN_SELECT_SERVER_OP_MODE_MSG,
        .selectClientOperationModeMessage = LANG_EN_SELECT_CLIENT_OP_MODE_MSG,
        .typePeerIpMessage = LANG_EN_TYPE_PEER_IP_MSG,
        .typePeerPortMessage = LANG_EN_TYPE_PEER_PORT_MSG,
        .goodbyeMessage = LANG_EN_GOODBYE_MSG
    },
    [PortugueseLanguageType] = {
        .welcomeMessage = LANG_PT_WELCOME_MSG,
        .languageMenuOptionLabel = LANG_PT_LANGUAGE_MENU_OPTION_LABEL,
        .startChatMenuOptionLabel = LANG_PT_START_CHAT_MENU_OPTION_LABEL,
        .exitMenuOptionLabel = LANG_PT_EXIT_MENU_OPTION_LABEL,
        .languageSetMessage = LANG_PT_LANGUAGE_SET_MSG,
        .selectOperationModeMessage = LANG_PT_SELECT_OP_MODE_MSG,
        .selectServerOperationModeMessage = LANG_PT_SELECT_SERVER_OP_MODE_MSG,
        .selectClientOperationModeMessage = LANG_PT_SELECT_CLIENT_OP_MODE_MSG,
        .typePeerIpMessage = LANG_PT_TYPE_PEER_IP_MSG,
        .typePeerPortMessage = LANG_PT_TYPE_PEER_PORT_MSG,
        .goodbyeMessage = LANG_PT_GOODBYE_MSG
    }
};

// Current localization pointer.
// Your value represents the current language.
// Default will be English.
extern const Localization *currentLocalization;

// Function to show the language setup, where the user can choose the actual language.
// Returns the choice number in range of [0-LanguageTypesLength].
int showLanguageSetup();

// Function to select the language of the application.
void setLanguage(LanguageType type);

#endif // _LOCALIZATION_H_
