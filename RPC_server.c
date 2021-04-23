#include "RPC.h"
#include "file.c"
#include "list.c"


results *init = NULL;
parameters *questions;

	
results *corrected_questionnaire_100_svc(parameters *argp, struct svc_req *rqstp){

	struct results *result;
	struct results *aux;
	results *node;
	FILE *arq;
	int size=5,i=0;
	
	

	result=malloc(sizeof(results));
	result->iquestion_number = argp->iquestion_number;
	result->prox=NULL;

	if(result==NULL){
		printf("ERRO: Memória insuficiente"); 
		exit(1);
	}

	

	if( init == NULL )
		questions=getQuestions();
	
	
    	
	char *p;
	char *u=argp->answers;	

	
	for( i=1; i<=size; i++ ){

		if( argp->iquestion_number == questions[i].iquestion_number ){

			p = questions[i].answers;
			
			result->iquestion_number = argp->iquestion_number ;
			result->icorrect_answers = 0;
			result->wrong_answers = 0;

			while( *u != '\0' ){
			
				if( *u == *p ){	
			
					result->icorrect_answers++;
				
				}else{

					result->wrong_answers++;
				}
				*u++;
				*p++;

			}

		}

	}
	
	
	aux=result;

	init=insert_list(aux,init);
	

	
	return result;
}



results * statistics_100_svc(void *argp, struct svc_req *rqstp){

      
	return init;
}
