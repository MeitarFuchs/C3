#define LINE 256
#define WORD 30

int getline1 (char s[]);
int getword (char w[]);
int substring (char *str1 , char *str2);
int helpEquals(char *s, char *t, int size);
int similar (char *s, char *t, int n);
void print_lines(char* str,char *word);
void print_similar_words(char* str, char *w);