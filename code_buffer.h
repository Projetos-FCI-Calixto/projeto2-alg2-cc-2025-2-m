#ifndef CODE_BUFFER_H
#define CODE_BUFFER_H

typedef struct {
    char *code;
    int length;
    int capacity;
} CodeBuffer;

CodeBuffer* create_code_buffer();
void free_code_buffer(CodeBuffer *buffer);
void append_to_buffer(CodeBuffer *buffer, char c);

#endif
