
#ifndef __PUBLIC_H__
#define __PUBLIC_H__

int strequal(const char* restrict a, const char* restrict b, int size);

char* secret_get(char *buf, int len);

void bubble_sort(int list[], int N);

#endif /* __PUBLIC_H__ */