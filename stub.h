//Stub functions to enable compilation
//It is probably a good idea to not use this!

void panic(const char * str) {
    printf("\nKERNEL PANIC!\n");
    printf("%s\n", str);

    while(1);
}

uint64_t strlen(const char *str) {
    uint64_t len = 0;
    while (*str++ && len < 65535) {
        len++;
    }
    return len;
}

 uint64_t memcmp(const void *dest, const void *src, uint64_t size) {
    uint8_t *d = (uint8_t *)dest;
    uint8_t *s = (uint8_t *)src;
    for (uint64_t i = 0; i < size; i++) {
        if (d[i] != s[i]) {
            return 1;
        }
    }
    return 0;
 }