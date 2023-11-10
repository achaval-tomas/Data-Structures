/*  My Dictionary Specification  */

#ifndef DICT_HEADER
#define DICT_HEADER

typedef struct s_dict MyDict;
typedef char* string;

/*  CREATE a new empty dictionary.  */
MyDict* newDict(void);

/*  RETURNS the amount of words in the dictionary  */
int dictSize(MyDict* dict);

/*  ADD a new word and definition to dictionary.
 *  (or change definiton of existing word)
 */
void addDef(MyDict* dict, string word, string def);

/*  REMOVES a word from the dictionary.  */
void removeWord(MyDict* dict, string word);

/*  RETURNS an array of available words in the dictionary.
 *  Length of array is saved into retSize.
 */
string* availableWords(MyDict* dict, int* retSize);

/*  RETURNS the definiton associated to word.  */
string getDef(MyDict* dict, string word);

/*  FREE ALL SPACE USED BY dict.  */
void freeDict(MyDict* dict);

/*  PRINT dict TO stdout  */
void printDict(MyDict* dict);

#endif /*  DICT_HEADER  */