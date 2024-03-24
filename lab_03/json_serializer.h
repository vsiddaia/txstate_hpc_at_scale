#ifndef JSON_SERIALIZER_H
#define JSON_SERIALIZER_H

#include <stdio.h>
#include <stddef.h> // For size_t
#include <stdlib.h>
#include <string.h>

// Forward declaration of KeyValuePair struct
// Ensure the actual definition is available in the source files
// that include this header or in another header file.
typedef struct {
    char *key;
    char *value;
} KeyValuePair;

/**
 * Serializes an array of KeyValuePair structures into a JSON string.
 * Dynamically allocates memory for the JSON string, which must be freed by the caller.
 *
 * @param pairs Pointer to the first element of an array of KeyValuePair structures.
 * @param count The number of elements in the 'pairs' array.
 * @return A pointer to the dynamically allocated JSON string, or NULL if an error occurs.
 */
char *serializeToJson(const KeyValuePair *pairs, size_t count);

/**
 * Writes a string to a file.
 *
 * @param filename The name of the file to write to.
 * @param content The string content to write into the file.
 * @return 0 on success, -1 on error (e.g., if the file cannot be opened).
 */
int writeToFile(const char *filename, const char *content);

#endif // JSON_SERIALIZER_H
