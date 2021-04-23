


int search(results *node,results *init){

	results *p=init;

	while( p!= NULL){

		  if( node->iquestion_number == p->iquestion_number   ){

		   	p->icorrect_answers+=node->icorrect_answers;
			p->wrong_answers+=node->wrong_answers;
			return 1;
			
		  }

		p=p->prox;
		
	}

	return 0;	

}


results *insert_list(results *node,results *init){

	    results *p = init;
	   
	    results *atual, *novo, *anterior;
	 
	    atual = p;
	    anterior = NULL;

	
	    if(atual == NULL){

		node->prox = NULL;
		init = node;

	    } else{
	

		 if ( ! search(node,init) ){


			while(atual != NULL && atual->iquestion_number < node->iquestion_number){

			    anterior = atual;
			    atual = atual->prox;

			}


			node->prox = atual;

			if(anterior == NULL){

			    init = node;

			} else{

			    anterior->prox = node;

			}

			

		}
	    

	
	}
	return init;	
}



