/*
 * Please do not edit this file.
 * It was generated using rpcgen.
 */

#include "rdbase.h"

bool_t
xdr_upd (XDR *xdrs, upd *objp)
{
	register int32_t *buf;

	 if (!xdr_string (xdrs, &objp->upd_old, MAXWORD))
		 return FALSE;
	 if (!xdr_string (xdrs, &objp->upd_new, MAXWORD))
		 return FALSE;
	return TRUE;
}

bool_t
xdr_oneword (XDR *xdrs, oneword *objp)
{
	register int32_t *buf;

	 if (!xdr_string (xdrs, &objp->word, MAXWORD))
		 return FALSE;
	return TRUE;
}

bool_t
xdr_manywords (XDR *xdrs, manywords *objp)
{
	register int32_t *buf;

	 if (!xdr_array (xdrs, (char **)&objp->words.words_val, (u_int *) &objp->words.words_len, DICTSIZ,
		sizeof (oneword), (xdrproc_t) xdr_oneword))
		 return FALSE;
	return TRUE;
}
