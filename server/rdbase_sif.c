/* rdbase_sif.c - init_1, insert_1, delete_1, lookup_1 */

/*
#undef __STDC__
#undef __cpluplus
*/

#include <rpc/rpc.h>
#include "rdbase.h"

// forward declarations
int initw ();
int insertw (char*);
int deletew (char*);
int lookupw (char*);
int updatew (char*, char*);
int countw();
char* selectw();
void selectw2(manywords* buffer, oneword* bufferow);

static int retcode;
static char* ret_string;
// für select2
static manywords mwbuffer;
static oneword owbuffer[DICTSIZ];


int *initw_1_svc(dummy, handle)
void *dummy;
struct svc_req *handle;
{
   retcode = initw();
   return &retcode;
}

int *insertw_1_svc (w, handle)
char **w;
struct svc_req *handle;
{
   retcode = insertw(*w);
   return &retcode;
}


int *countw_1_svc (dummy, handle)
void *dummy;
struct svc_req *handle;
{
   retcode = countw();
   return &retcode;
}

char* *selectw_1_svc (dummy, handle)
void *dummy;
struct svc_req *handle;
{
   ret_string = selectw();
   return &ret_string;
}



manywords* select2w_1_svc(dummy, handle)
void *dummy;
struct svc_req *handle;
{
   mwbuffer.words.words_val = owbuffer;
   selectw2(&mwbuffer, owbuffer);
   return &mwbuffer;
}






int *deletew_1_svc (w, handle)
char **w;
struct svc_req *handle;
{
   retcode = deletew(*w);
   return &retcode;
}

int *lookupw_1_svc (w, handle)
char **w;
struct svc_req *handle;
{
   retcode = lookupw(*w);
   return &retcode;
}

int *updatew_1_svc (s, handle)
struct upd *s;
struct svc_req *handle;
{
   retcode = updatew(s->upd_old, s->upd_new);
   return &retcode;
}



