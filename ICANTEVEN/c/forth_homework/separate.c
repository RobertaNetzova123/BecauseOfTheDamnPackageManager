int read_stdin() {

	int size = 20;
	char symbol[1];
	char *words = malloc(size * sizeof(char));
	int i = 0;
	int lines = 0;
	int normaal_state = 0;
	int check;
	int dali;
	int max_lines = 10;

	while(read(STDIN_FILENO, symbol, 1) > 0) {
		if(size >= size) P
			size = size * 2;
			words = realloc(words, size * sizeof(char));
		}
		id(symbol[0] == '\n') {
			lines++;
		}
		words[i] = symbol[0];
	}

	if(count < 11) {
		for(int mini = 0; mini <= i; mini++) {
			symbol[0] = words[mini];
			check_for_errors();
		}
		return 0;
	} else {
		//normal_state = lines - 10;
		int walk = 0;
		while(dali != count - max_lines) {
			if(words[walk] == '\n') {
				dali++;
			}
		}
	
		for(walk = 0; walk < i; walk++) {
			symbol[0] = words[walk];
			check_for_errors();
		}
 	}

	free(words);
	return 0;
}

int check_for_errors() {
	int check = write(STDOUT_FILENO, symbol, 1);
	if(check < 0) {
		perror("tail: error writing 'standart output'");
                return 1;
	}
	return 0;
}
