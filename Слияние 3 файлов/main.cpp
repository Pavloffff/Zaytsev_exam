#include <iostream>

int Min(int l, int r)
{
    return (l < r) ? l : r;
}

int Max(int l, int r)
{
    return (l > r) ? l : r;
}

int getFileSize(FILE* fd) {
    int _file_size = 0;
    if(fd == NULL){
        _file_size = -1;
    }
    else{
        while(getc(fd) != EOF)
            _file_size++;
    }
    fseek(fd, 0, SEEK_SET);
    return _file_size;
}
 

int main(int argc, char const *argv[])
{
    FILE *f1 = fopen(argv[1], "rb");
	FILE *f2 = fopen(argv[2], "rb");
    FILE *f3 = fopen(argv[3], "rb");
    FILE *res = fopen(argv[4], "wb");
    
    int s1 = getFileSize(f1);
    int s2 = getFileSize(f2);
    int s3 = getFileSize(f3);
    int i = 0, j = 0, k = 0;
    int f1_i = 0, f2_j = 0, f3_k = 0;
    while (i < s1 && j < s2 && k < s3) {
        fseek(f1, i, SEEK_SET);
        f1_i = getc(f1);
        fseek(f2, j, SEEK_SET);
        f2_j = getc(f2);
        fseek(f3, k, SEEK_SET);
        f3_k = getc(f3);
        int min = Min(Min(f1_i, f2_j), f3_k);
        fseek(res, Max(Max(i, j), k), SEEK_SET);
        putc(min, res);
        if (min == f1_i) {
            i++;
        } else if (min == f2_j) {
            j++;    
        } else {
            k++;
        }
    }
    while (i < s1 && j < s2) {
        fseek(f1, i, SEEK_SET);
        f1_i = getc(f1);
        fseek(f2, j, SEEK_SET);
        f2_j = getc(f2);
        if (f1_i < f2_j) {
            putc(f1_i, res);
            i++;
        } else {
            putc(f2_j, res);
            j++;
        }
    }
    while (i < s1 && k < s3) {
        fseek(f1, i, SEEK_SET);
        f1_i = getc(f1);
        fseek(f3, k, SEEK_SET);
        f3_k = getc(f3);
        if (f1_i < f3_k) {
            putc(f1_i, res);
            i++;
        } else {
            putc(f3_k, res);
            k++;
        }
    }
    while (j < s2 && k < s3) {
        fseek(f2, j, SEEK_SET);
        f2_j = getc(f2);
        fseek(f3, k, SEEK_SET);
        f3_k = getc(f3);
        if (f2_j < f3_k) {
            putc(f2_j, res);
            j++;
        } else {
            putc(f3_k, res);
            k++;
        }
    }
    while (i < s1) {
        fseek(f1, i, SEEK_SET);
        f1_i = getc(f1);
        putc(f1_i, res);
        i++;
    }
    while (j < s2) {
        fseek(f2, j, SEEK_SET);
        f2_j = getc(f2);
        putc(f2_j, res);
        j++;
    }
    while (k < s3) {
        fseek(f3, k, SEEK_SET);
        f3_k = getc(f3);
        putc(f3_k, res);
        k++;
    }
    fclose(f1);
    fclose(f2);
    fclose(f3);
    fclose(res);
}
