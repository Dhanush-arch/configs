#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    // Get the start and end addresses of the current process's address space
    void* start_address = (void*) 0x0;
    void* end_address = (void*) ~0;

    // Calculate the size of the address space
    size_t mem_size = (size_t) end_address - (size_t) start_address;

    // Allocate a buffer to hold the entire address space
    char* mem_buffer = (char*) malloc(mem_size);

    // Copy the address space to the buffer
    memcpy(mem_buffer, start_address, mem_size);

    // Print the contents of the buffer
    for (size_t i = 0; i < mem_size; i++) {
        printf("%02X ", mem_buffer[i]);
        if ((i + 1) % 16 == 0) {
            printf("\n");
        }
    }

    // Free the memory buffer
    free(mem_buffer);

    return 0;
}
