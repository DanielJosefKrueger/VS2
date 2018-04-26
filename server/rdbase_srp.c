/* rdbase_srp.c - initw, insertw, deletew, lookupw */

#include <rpc/rpc.h>
#include <string.h>
#include "rdbase.h"
char dict[DICTSIZ] [MAXWORD+1];
int  nwords = 0;

char word [DICTSIZ * (MAXWORD+2)];
oneword onewordbuffer;
manywords manywordbuffer;

int initw() {
   nwords = 0;
   return 1;
}

int insertw (word)
char *word;
{
   int i;
   for (i=0; i<nwords; i++)
      if (strcmp (word, dict[i]) == 0)
         return 0;
   strcpy (dict[nwords], word);
   nwords++;
   return nwords;
}


// ####################################################### <Eigener Code> ######################################################
int countw ()
{
  return nwords;
}

char* selectw ()
{
  word[0] = '\0'; 
  for(int i=0; i < nwords; i++){
      strcat(word, dict[i]);
      strcat(word, "/");
  }
  return word;
}


void selectw2 (manywords* buffer, oneword* bufferows)
{
  for(int i=0; i < nwords; i++){
     bufferows[i].word = dict[i];
  }
  buffer->words.words_len= (u_int)countw(); 
}

// ####################################################### </Eigener Code> ######################################################

int deletew (word)
char *word;
{
   int i;
   for (i=0; i<nwords; i++)
      if (strcmp (word, dict[i]) == 0) {
         nwords--;
         strcpy (dict[i], dict[nwords]);
         return 1;
      }
   return 0;
}

int lookupw (word)
char *word;
{
   int i;
   for (i=0; i<nwords; i++)
      if (strcmp (word, dict[i]) == 0)
         return 1;
   return 0;
}

int updatew (word, word2)
char *word, *word2;
{
   
   int i;
   for (i=0; i<nwords; i++)
      if (strcmp (word, dict[i]) == 0) {
         strcpy (dict[i], word2);
         return 1;
      }
   return 0;
}




