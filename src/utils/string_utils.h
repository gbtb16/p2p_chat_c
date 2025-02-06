//
//  string_utils.h
//  p2p_chat_c
//
//  Created by Gabriel Barbosa on 06/02/25.
//

#pragma once
#ifndef _STRING_UTILS_H_
#define _STRING_UTILS_H_

#include <string.h>

// Check if a string has a null terminator, and if it doesn't, insert one.
//
// If the string is NULL, the function will return immediately.
void putNullTerminatorString(char *pString);

// Truncate a string to a maximum length.
//
// [maxLength] must be at least 4, because the last 3 characters will be replaced by '...'.
//
// If [maxLength] is less than 4, the function will return immediately.
// If the string is NULL, the function will return immediately.
// If the string is shorter than the maximum length, it will not be modified.
void truncateString(char *pLabel, int maxLength);

#endif // _STRING_UTILS_H_
