#include "json_serializer.h"

char *serializeToJson(const KeyValuePair *pairs, size_t count) {
    // Initial capacity for the JSON string
    size_t capacity = 256;
    char *json = (char*) malloc(capacity * sizeof(*json));
    if (!json) return NULL; // Check memory allocation

    strcpy(json, "{");

    for (size_t i = 0; i < count; ++i) {
        // Check if reallocation is needed
        size_t needed = strlen(json) + strlen(pairs[i].key) + strlen(pairs[i].value) + 10;
        if (needed >= capacity) {
            capacity *= 2;
            char *newJson = (char*)realloc(json, capacity * sizeof(*newJson));
            if (!newJson) {
                free(json); // Free the original json string on failure
                return NULL;
            }
            json = newJson;
        }

        // Append the current key-value pair to the JSON string
        strcat(json, "\"");
        strcat(json, pairs[i].key);
        strcat(json, "\": \"");
        strcat(json, pairs[i].value);
        strcat(json, "\"");

        if (i < count - 1) strcat(json, ", ");
    }

    strcat(json, "}");
    return json;
}

int writeToFile(const char *filename, const char *content) {
    FILE *file = fopen(filename, "w");
    if (!file) return -1; // Return error if file opening failed

    fputs(content, file);
    fclose(file);
    return 0; // Success
}
