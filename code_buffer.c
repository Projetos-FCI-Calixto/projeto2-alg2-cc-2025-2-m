#include <stdlib.h>
#include <string.h>
#include "code_buffer.h"

CodeBuffer* create_code_buffer() {
    CodeBuffer *buffer = (CodeBuffer*)malloc(sizeof(CodeBuffer));
    buffer->capacity = 64;
    buffer->length = 0;
    buffer->code = (char*)malloc(buffer->capacity * sizeof(char));
    buffer->code[0] = '\0';
    return buffer;
}

void free_code_buffer(CodeBuffer *buffer) {
    if (buffer) {
        free(buffer->code);
        free(buffer);
    }
}

void append_to_buffer(CodeBuffer *buffer, char c) {
    if (buffer->length + 2 >= buffer->capacity) {
        buffer->capacity *= 2;
        buffer->code = (char*)realloc(buffer->code, buffer->capacity * sizeof(char));
    }
    buffer->code[buffer->length++] = c;
    buffer->code[buffer->length] = '\0';
}
