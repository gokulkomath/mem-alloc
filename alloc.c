#include "alloc.h"


extern heap *memspace; // beacause it is defined in heap.asm


header *findblock_(header *hdr, word allocation, word n){

    bool ok;
    void *mem;
    header *hdr_;
    word n_;

    if((n+allocation)>(Maxwords-2))
        reterr(ErrNoMem);

    ok = (!(hdr->w))?true:
        (!(hdr->allocated)&& (hdr->w >= allocation))?true:
        false;

    if (ok)
        return hdr;

    else{

        mem = $v hdr+(hdr->w*4)+4;
        hdr_ = $h mem;
        n_ = n+hdr->w;

        return findblock_(hdr_,allocation,n_);



    }

    reterr(ErrUnknown);



}


void *mkalloc(word words, header *hdr){


    void *ret, *bytesin;
    word wordsin;

    bytesin = ($v (($v hdr) - memspace));          /* lines 13 - 15 computes the words avoilable
                                                        after the header*/
    wordsin = ((word)((uintptr_t)bytesin / 4)) + 1;

    if (words > (Maxwords-wordsin)){

        reterr(ErrNoMem);


    }


    hdr->w = words;
    hdr->allocated = true;
    ret =($v hdr)+4;   //returns the address after 4 bytes from header


    return ret;

}




void *alloc(int32 bytes){

    word words;
    header *hdr;
    void *mem;


    words = (!(bytes % 4))? bytes/4:(bytes/4)+1;  //gives how much empty space we should allocate  { Each space is 4 bytes long }




    hdr = findblock(words); //points to header at memspace

    if (!hdr)
        return $v 0;


    if (words > Maxwords)
        reterr(ErrNoMem);

    mem = mkalloc(words, hdr);   //we pass the no of words and the header
        if(!mem)
            return $v 0;

        return mem;

}




void free_(header* hdr,int32 bytes){

       word words = (!(bytes % 4))? bytes/4:(bytes/4)+1;
       int32 space_left;


        do{

            space_left=(Maxwords*4) - ((hdr->w*4)+4);

        if(hdr->w>=words){

            hdr->allocated=false;
            return;

        }


        hdr = $h($v hdr+(hdr->w*4)+4);

    } while(space_left>1);






        }






void show_(header *hdr){

    header *p;
    void *mem;
    int32 n;

    for(n=1,p=hdr;p->w;mem=$v p+((p->w+1)*4), p=mem,n++)
        printf("Alloc %d = %d %s words\n", n,p->w, (p->allocated)?"alloced":"free");

    return;

}



int main(int argc, char *argv[]){


    int no_of_blocks = 0;
    int32 bytes;

    printf("Enter the no. of blocks to allocate: ");
    scanf("%d",&no_of_blocks);


    for(int i=0;i<no_of_blocks;i++){

        printf("Bytes to allocate: ");
        scanf("%d",&bytes);

        alloc(bytes);

    }

show();





    printf("Bytes to free: ");
    scanf("%d",&bytes);

    free(bytes);



show();



    return 0;
}
