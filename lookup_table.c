#include <stdlib.h>
#include <string.h>

#define TABSIZE 101

struct defnode {
    struct defnode *next;
    char *text;
    char *defn;
};

uint hash(char *text);
struct defnode *lookup(char *text);
struct defnode *install(char *text, char *defn);
void undef(char *text);

struct defnode *deftable[TABSIZE];

int main(int argc, char *argv[]) { return EXIT_SUCCESS; }

uint hash(char *text) {
    int h;
    for (h = 0; *text != '\0'; text++) {
        h = *text + 31 * h;
    }
    return h % TABSIZE;
}

struct defnode *lookup(char *text) {
    struct defnode *np;
    for (np = deftable[hash(text)]; np != NULL; np = np->next) {
        if (strcmp(text, np->text) == 0) {
            return np;
        }
    }
    return NULL;
}

struct defnode *install(char *text, char *defn) {
    struct defnode *np;
    if ((np = lookup(text)) == NULL) {
        if ((np = malloc(sizeof(struct defnode))) == NULL ||
            (np->text = strdup(text)) == NULL) {
            return NULL;
        }
        uint h = hash(text);
        np->next = deftable[h];
        deftable[h] = np;
    } else {
        free(np->defn);
    }
    if ((np->defn = strdup(defn)) == NULL) {
        return NULL;
    }
    return np;
}

void undef(char *text) {
    struct defnode *np;
    struct defnode *prev = NULL;
    for (np = deftable[hash(text)]; np != NULL; np = np->next) {
        if (strcmp(text, np->text) == 0) {
            if (prev != NULL) {
                prev->next = np->next;
            }
            free(np);
            return;
        }
        prev = np;
    }
}
