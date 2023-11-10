/*  My Dictionary implementation  */

#include "dict.h"

struct s_keydef {
    string key;
    string def;
};

struct s_dict {
    int size;
    struct s_keydef* data;
};

/*  CREATE a new empty dictionary.  */
MyDict* newDict(void){
    MyDict* d = malloc(sizeof(*d));
    d->size = 0;
    d->data = NULL;
    return d;
}

/*  RETURNS the amount of words in the dictionary  */
int dictSize(MyDict* dict){
    return dict->size;
}

/*  ADD a new word and definition to dictionary.
 *  (or change definiton of existing word)
 */
void addDef(MyDict* dict, string word, string def){

}

/*  REMOVES a word from the dictionary.  */
void removeWord(MyDict* dict, string word){

}

/*  RETURNS true if word is available in the dictionary.  */
bool isAvailable(MyDict* dict, string word){
    return false;
}

/*  RETURNS an array of available words in the dictionary.
 *  Length of array is saved into retSize.
 */
string* availableWords(MyDict* dict, int* retSize){
    return NULL;
}

/*  RETURNS the definiton associated to word.  */
string getDef(MyDict* dict, string word){
    return NULL;
}

/*  Save the dictionary into the file at fpath.  */
void saveDict(MyDict* dict, FILE* fpath){
    
}

/*  FREE ALL SPACE USED BY dict.  */
void freeDict(MyDict* dict){

}

/*  PRINT dict TO stdout  */
void printDict(MyDict* dict){

}