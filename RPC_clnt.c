#include <memory.h> /* for memset */
#include "RPC.h"

static struct timeval TIMEOUT = { 2, 0 };


/* STUB do cliente */

results *corrected_questionnaire_100(parameters *argp, CLIENT *clnt){

	static results clnt_res;

	memset((char *)&clnt_res, 0, sizeof(clnt_res));

        /* 1-Identificação do servidor remoto */
        /* 2-Identificação do processo remoto */
	/* 3-Parametros convertidos 	      */
        /* 4-Resultado da função remota       */

	if ( clnt_call (clnt, Corrected_questionnaire,
		(xdrproc_t) xdr_parameters, (caddr_t) argp,
		(xdrproc_t) xdr_results, (caddr_t) &clnt_res,
		TIMEOUT) != RPC_SUCCESS) {

		return (NULL);
	}

	return (&clnt_res);
}

results * statistics_100(void *argp, CLIENT *clnt) {

	static results clnt_res;

	memset((char *)&clnt_res, 0, sizeof(clnt_res));

	if (clnt_call (clnt, Statistics,
		(xdrproc_t) xdr_void, (caddr_t) argp,
		(xdrproc_t) xdr_results, (caddr_t) &clnt_res,
		TIMEOUT) != RPC_SUCCESS) {
		return (NULL);
	}

	return (&clnt_res);
}
