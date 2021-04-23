#include "RPC.h"

bool_t xdr_parameters (XDR *xdrs, parameters *objp){

	register int32_t *buf;

	 if (!xdr_int (xdrs, &objp->iquestion_number))
		 return FALSE;
	 if (!xdr_int (xdrs, &objp->inumber_of_alternatives))
		 return FALSE;
	 if (!xdr_string (xdrs, &objp->answers, 5))
		 return FALSE;
	return TRUE;
}

bool_t xdr_results (XDR *xdrs, results *objp){

	register int32_t *buf;


	if (xdrs->x_op == XDR_ENCODE) {
		buf = XDR_INLINE (xdrs, 3 * BYTES_PER_XDR_UNIT);
		if (buf == NULL) {
			 if (!xdr_int (xdrs, &objp->iquestion_number))
				 return FALSE;
			 if (!xdr_int (xdrs, &objp->icorrect_answers))
				 return FALSE;
			 if (!xdr_int (xdrs, &objp->wrong_answers))
				 return FALSE;

		} else {
		IXDR_PUT_LONG(buf, objp->iquestion_number);
		IXDR_PUT_LONG(buf, objp->icorrect_answers);
		IXDR_PUT_LONG(buf, objp->wrong_answers);
		}
		 if (!xdr_pointer (xdrs, (char **)&objp->prox, sizeof (results), (xdrproc_t) xdr_results))
			 return FALSE;
		return TRUE;
	} else if (xdrs->x_op == XDR_DECODE) {
		buf = XDR_INLINE (xdrs, 3 * BYTES_PER_XDR_UNIT);
		if (buf == NULL) {
			 if (!xdr_int (xdrs, &objp->iquestion_number))
				 return FALSE;
			 if (!xdr_int (xdrs, &objp->icorrect_answers))
				 return FALSE;
			 if (!xdr_int (xdrs, &objp->wrong_answers))
				 return FALSE;

		} else {
		objp->iquestion_number = IXDR_GET_LONG(buf);
		objp->icorrect_answers = IXDR_GET_LONG(buf);
		objp->wrong_answers = IXDR_GET_LONG(buf);
		}
		 if (!xdr_pointer (xdrs, (char **)&objp->prox, sizeof (results), (xdrproc_t) xdr_results))
			 return FALSE;
	 return TRUE;
	}

	 if (!xdr_int (xdrs, &objp->iquestion_number))
		 return FALSE;
	 if (!xdr_int (xdrs, &objp->icorrect_answers))
		 return FALSE;
	 if (!xdr_int (xdrs, &objp->wrong_answers))
		 return FALSE;
	 if (!xdr_pointer (xdrs, (char **)&objp->prox, sizeof (results), (xdrproc_t) xdr_results))
		 return FALSE;
	return TRUE;
}
