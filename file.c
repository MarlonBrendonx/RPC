
parameters * getQuestions(){

	char  aux[2];
	char  *delimiter = ":";
	char  *cut;
	int   count=1;
	size_t len = 0;
    	size_t read;
	size_t size=5;
	char * line = NULL;
	FILE *arq;

	parameters *questions = malloc( size*sizeof(parameters) );
	
	arq=fopen("questions.txt","r");
	
	if(  arq == NULL )
		exit(1); 		


	while( (read = getline(&line, &len, arq)) != -1  ) {

		
 		cut = strtok(line,delimiter);
		questions[count].iquestion_number = atoi( cut );
     		
		cut = strtok(NULL, delimiter);
		questions[count].inumber_of_alternatives = atoi( cut );
		
		cut = strtok(NULL, delimiter);

		questions[count].answers = malloc(5);
		strcpy(questions[count].answers,cut);
		
		
		cut = strtok(NULL, delimiter);
		
		count++;
		
		
	
        }

	
	
	fclose(arq);
	
	return questions;
		
}



	

