#include <stdio.h>
#include <birchutils.h>
#include <stdlib.h>
#include <errno.h>
#include <stdbool.h>
#include <stdint.h>

#define packed __attribute__((__packed__))
#define unused __attribute__((__unused__))
#define Maxwords (1024*1024*1024/4)
#define ErrNoMem 1
#define ErrUnknown 2

typedef unsigned char int8;
typedef unsigned short int  int16;
typedef unsigned int int32;
typedef unsigned long long int int64;
typedef unsigned __int128 int128;
typedef void heap;
typedef int32 word;

struct packed s_header{

    word w:30;    //declares that w occupies 30 bits out of the 32 bits

    bool allocated:1;
    bool unused reserved:1;    // Tells the compiler to not warn me about it's unused state


};

typedef struct packed s_header header;

#define $1 (int8 *)
#define $2 (int16)
#define $4 (int32)
#define $8 (int64)
#define $16 (int128)
#define $c (char *)
#define $i (int)
#define $v (void *)
#define $h (header *)

#define reterr(x) do{ errno = (x); return $v 0; }while(false)

#define findblock(x) findblock_($h memspace,(x),0)


#define free(x) free_($h memspace,(x))


#define show() show_($h memspace)

void show_(header*);
header *findblock_(header*,word,word);
void free_(header*,word);
void *mkalloc(word, header*);
void *alloc(int32);
int main(int , char**);
