void test_process_words() {
	printf("------------------\n");
	printf("Test: process_words\n\n");

	FILE *fp = fopen(testdata_filename, "r");
	if (fp == NULL) {
		perror("open input file error");
		return;
	}
	char dictionary[DICTIONARY_SIZE] = { 0 };
	create_dictionary(fp, dictionary);
	fclose(fp);

	fp = fopen(testdata_filename, "r");
	if (fp == NULL) {
		perror("open input file error");
		return;
	}
	WORD words[MAX_WORDS];
	WORDSTATS ws = process_words(fp, words, dictionary);
	fclose(fp);

	printf(statsformat, "line_count", ws.line_count);
	printf(statsformat, "word_count", ws.word_count);
	printf(statsformat, "keyword_count", ws.keyword_count);

	printf("\n");
	for (int i = 0; i < ws.keyword_count; i++) {
		printf(statsformat, words[i].word, words[i].count);
	}
	printf("\n");
}