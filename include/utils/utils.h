//
//  utils.h
//  p2p_chat_c
//
//  Created by Gabriel Barbosa on 28/01/25.
//

#pragma once
#ifndef _UTILS_H_
#define _UTILS_H_

// Print a message in stdout.
// The program will continue running.
void throwStandardError(const char *message);

// Print a critical error message and exit the program.
// The message will be printed in stderr.
// The program will exit with status -1.
void throwCriticalError(const char *message);

// Print a message in stderr and exit the program.
// The message will be printed in stderr.
// The program will exit with status -1.
void throwMemoryAllocationFailed(void);

// Check if a string has a null terminator, and if it doesn't, insert one.
// If the string is NULL, the function will return immediately.
void putNullTerminatorString(char *pString);

// Truncate a string to a maximum length.
// [maxLength] must be at least 4, because the last 3 characters will be replaced by '...'.
// If [maxLength] is less than 4, the function will return immediately.
// If the string is NULL, the function will return immediately.
// If the string is shorter than the maximum length, it will not be modified.
void truncateString(char *pLabel, int maxLength);

#endif // _UTILS_H_
