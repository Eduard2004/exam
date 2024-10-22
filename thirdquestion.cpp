#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_KEYS 100
#define MAX_KEY_LENGTH 50
#define MAX_VALUE_LENGTH 100

typedef struct {
    char key[MAX_KEY_LENGTH];
    char value[MAX_VALUE_LENGTH];
} KeyValuePair;

typedef struct {
    KeyValuePair pairs[MAX_KEYS];
    int size;
} Dictionary;

void initDictionary(Dictionary* dict) {
    dict->size = 0;
}


int addKeyValue(Dictionary* dict, const char* key, const char* value) {
    if (dict->size >= MAX_KEYS) {
        return -1; // Dictionary is full
    }
    strcpy(dict->pairs[dict->size].key, key);
    strcpy(dict->pairs[dict->size].value, value);
    dict->size++;
    return 0; // Success
}


const char* getValue(Dictionary* dict, const char* key) {
    for (int i = 0; i < dict->size; i++) {
        if (strcmp(dict->pairs[i].key, key) == 0) {
            return dict->pairs[i].value;
        }
    }
    return NULL;
}


int deleteKeyValue(Dictionary* dict, const char* key) {
    for (int i = 0; i < dict->size; i++) {
        if (strcmp(dict->pairs[i].key, key) == 0) {

            for (int j = i; j < dict->size - 1; j++) {
                dict->pairs[j] = dict->pairs[j + 1];
            }
            dict->size--;
            return 0; 
        }
    }
    return -1; 
}


void printDictionary(Dictionary* dict) {
    for (int i = 0; i < dict->size; i++) {
        printf("%s: %s\n", dict->pairs[i].key, dict->pairs[i].value);
    }
}

int main() {
    Dictionary dict;
    initDictionary(&dict);

    addKeyValue(&dict, "name", "Alice");
    addKeyValue(&dict, "age", "30");
    addKeyValue(&dict, "city", "New York");

    printf("Dictionary contents:\n");
    printDictionary(&dict);

    const char* age = getValue(&dict, "age");
    if (age) {
        printf("Age: %s\n", age);
    }
    else {
        printf("Key 'age' not found.\n");
    }

    deleteKeyValue(&dict, "city");
    printf("After deleting 'city':\n");
    printDictionary(&dict);

    return 0;
}
