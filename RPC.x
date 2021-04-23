struct parameters {
	
	int iquestion_number ;
	int inumber_of_alternatives;
	string answers<5>; };

struct results {

	int iquestion_number;
	int icorrect_answers;
	int wrong_answers;
	struct results *prox;
	

};



program PROG {
	version VERSAO {
	results Corrected_questionnaire(parameters) = 1;
	results Statistics() = 2;

	} = 100;
} = 55555555;
