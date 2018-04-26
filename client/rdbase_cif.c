/* rdbase_cif.c - initw, insertw, deletew, lookupw, ... */

#include <rpc/rpc.h>
#include <stdio.h>
#include "rdbase.h"

extern CLIENT *handle;
static int *ret;

int initw() {
   ret = initw_1 (0, handle);
   return ret==0 ? 0 : *ret;
}

int insertw(word)
char *word;
{
   char **arg;
   arg = &word;
   ret = insertw_1(arg, handle);
   return ret==0 ? 0 : *ret;
}

int deletew (word)
char *word;
{
   char **arg;
   arg = &word;
   ret = deletew_1 (arg, handle);
   return ret==0 ? 0 : *ret;
}

int lookupw (word)
char *word;
{
   char **arg;
   arg = &word;
   ret = lookupw_1 (arg, handle);
   return ret==0 ? 0 : *ret;
}

int updatew (word, word2)
char *word, *word2;
{
   struct upd arguments, *arg;
   arguments.upd_old = word;
   arguments.upd_new = word2;
   arg = &arguments;
   ret = updatew_1 (arg, handle);
   return ret==0 ? 0 : *ret;
}



int countw ()
{
   ret = countw_1 (0, handle);
   return *ret;
}

char* selectw1(){
   char** str= selectw_1(0, handle);
   return *str;
}


char* selectw2(){
   manywords* ret;
   ret = select2w_1(0, handle);
	for(int i =0; i < ret->words.words_len; i++){
		printf("An der Stelle %i ist Wort: %s\n", i+1, ret->words.words_val[i].word);
        }
   printf("_____________________________________________________________\n");
   return "NICE";
}








