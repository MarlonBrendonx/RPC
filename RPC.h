#ifndef _RPC_H_RPCGEN
#define _RPC_H_RPCGEN

#include <rpc/rpc.h>


#ifdef __cplusplus
extern "C" {
#endif


struct parameters {
	int iquestion_number;
	int inumber_of_alternatives;
	char *answers;
};
typedef struct parameters parameters;

struct results {
	int iquestion_number;
	int icorrect_answers;
	int wrong_answers;
	struct results *prox;
};
typedef struct results results;

#define PROG 55555555
#define VERSAO 100

#if defined(__STDC__) || defined(__cplusplus)
#define Corrected_questionnaire 1
extern  results * corrected_questionnaire_100(parameters *, CLIENT *);
extern  results * corrected_questionnaire_100_svc(parameters *, struct svc_req *);
#define Statistics 2
extern  results * statistics_100(void *, CLIENT *);
extern  results * statistics_100_svc(void *, struct svc_req *);
extern int prog_100_freeresult (SVCXPRT *, xdrproc_t, caddr_t);

#else /* K&R C */
#define Corrected_questionnaire 1
extern  results * corrected_questionnaire_100();
extern  results * corrected_questionnaire_100_svc();
#define Statistics 2
extern  results * statistics_100();
extern  results * statistics_100_svc();
extern int prog_100_freeresult ();
#endif /* K&R C */

/*  funções xdr */

#if defined(__STDC__) || defined(__cplusplus)
extern  bool_t xdr_parameters (XDR *, parameters*);
extern  bool_t xdr_results (XDR *, results*);

#else /* K&R C */
extern bool_t xdr_parameters ();
extern bool_t xdr_results ();

#endif /* K&R C */

#ifdef __cplusplus
}
#endif

#endif /* !_RPC_H_RPCGEN */
