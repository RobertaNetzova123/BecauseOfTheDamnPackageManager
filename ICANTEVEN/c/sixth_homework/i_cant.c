char **parse_cmdline( const char *cmdline) {
	int size = 77;
	int size_for_ch = 1;
	char **words =(char**)malloc(size * sizeof(char*)); //kastvame
	//char symbol[1];
	
	//for(int i = 0; i < size; i++) {
		//size = size * 2;
		//words[i] = (char*)malloc(words, size * sizeof(char)); //zadelqme pamet za purviq masiv ot elementi v masiva
	//}
//cmdline - stringa koito podavame na parse_cmdline [purviq red koito si prochel]
	int count = 0;
	int count_for_ch = 0;
	int p = 0; //broi charackters v reda 
//p - sledi ot kraq na minalata duma do nachaloto na novata duma
	int i = 0;//broi dumi 
	for(int k = 0; k < cmdline[k] != '\0'; k++,count++) { //cmdline[k] != '\n'

		if(count >= size) {
			size = size * 2;
			words = (char**)realloc(words, size * sizeof(char*));
		}
		words[i] = (char*)malloc(size_for_ch * sizeof(char));
//k - obhojda mi purviq string ot masiva
		while(cmdline[k] != ' ' && cmdline[k] != '\n') {
			if( count_for_ch >= size_for_ch) {
				size_for_ch = size_for_ch * 2;
				words[i] = (char*)realloc(words, size_for_ch * sizeof(char*));
			}
			
			for(int m = 0 ;p < k; p++,m++) { //m - broi characters vuv vsqka duma 
				words[i][m] = cmdline[k]; 
			}
			p = k; //izchakva k-to
		}		
			
		size_for_ch = 1;
		m = 0;
	}
	size = size * 2;
	words = (char**)realloc(words, size * sizeof(char*));
	words[i] = NULL;
	return words; 
}







char **parse_cmdline( const char *cmdline) {
	int size = 77;
	char **words =(char**)malloc(size * sizeof(char*));
	//char symbol[1];
	
	//for(int i = 0; i < size; i++) {
		//size = size * 2;
		//words[i] = (char*)malloc(words, size * sizeof(char)); //zadelqme pamet za purviq masiv ot elementi v masiva
	//}
//cmdline - stringa koito podavame na parse_cmdline [purviq red koito si prochel]
	int count = 0;
	int p = 0; //broi charackters v reda 
//p - sledi ot kraq na minalata duma do nachaloto na novata duma
	int i = 0;//broi dumi 
	for(int k = 0; k < cmdline[k] != '\0'; k++,count++) { //cmdline[k] != '\n'

		if(count == size) {
			size = size * 2;
			words = (char**)realloc(words, size * sizeof(char*));
		}
		
//k - obhojda mi purviq string ot masiva
		while(cmdline[k] != ' ') {
			words[i] = (char*)malloc( size * sizeof(char));
			
			for(int m = 0 ;p < k; p++,m++) { //m - broi characters vuv vsqka duma 
				words[i][m] = cmdline[k]; 
			}
			p = k; //izchakva k-to
		}		
			
	}
	return words; 
}



char **parse_cmdline(const char *cmdline) {

	int size = 40; //size-a na celiq red
	int el_size = 15; //size-a na elementite dokato sreshtne space
	char **words = (char**)malloc(size * sizeof(char*)); //zadelqne na pamet za celiq red + kastvane kum char
	int count = 0; //promenliva za proverka za reallocirane na reda
	int el_count = 0; //promenliva za proverka za reallocirane na dumata
	int i = 0; //broqch na koq duma se namirame	

	for(int k = 0; cmdline[k] != '\0'; count++) { //cikul dokato stigne do kraq na reda
		if(count == size) { //count >= size
			size = size * 2; //uvelichavame size-a 2 puti i posle reallokirame
			words = realloc(words, size * sizeof(char*)); //reallocirame
		}
		words[i] = (char*)malloc(el_size * sizeof(char)); //zadelqme pamet za edin string ot masiva

		while(cmdline[k] != ' ') {
			int m = 0;
			puts("molq te iskam 100 pone"); //hardcode
			if(cmdline[k] == '\n') { break; }
			if(el_count == el_size) { //count_for_ch >= size_for_ch
				el_size= el_size * 2; //uvelichavame size-a za edin string 2 puti i posle reallokirame
				words[i] = (char*)realloc(words, el_size * sizeof(char*)); //reallocirame za edin string ot masiva
			}
				words[i][m] = cmdline[k];
				m++;k++;
		}
		i++;		
	}

	words[i] = NULL;
	return words;
}










































