#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXWORD 100

struct tnode {
    char *text;
    int count;
    struct tnode *lchild;
    struct tnode *rchild;
};

int getword(char *, int);
struct tnode *addtree(struct tnode *, char *);
struct tnode *addcounttree(struct tnode *dest, struct tnode *source);
struct tnode *sorttree(struct tnode *dest, struct tnode *source);
void printtree(struct tnode *);

int main(int argc, char *argv[]) {

    char *word = malloc(sizeof(char) * MAXWORD);
    struct tnode *root = NULL;
    struct tnode *sorted_root = NULL;

    while (getword(word, MAXWORD) != EOF) {
        if (isalpha(word[0])) {
            root = addtree(root, word);
        }
    }

    printtree(root);

    sorted_root = sorttree(sorted_root, root);

    printtree(sorted_root);

    return EXIT_SUCCESS;
}

struct tnode *addtree(struct tnode *p, char *word) {
    if (p == NULL) {
        struct tnode *newnode = malloc(sizeof(struct tnode));
        newnode->text = strdup(word);
        newnode->count = 1;
        newnode->lchild = newnode->rchild = NULL;
        return newnode;
    }

    int cmp = strcmp(word, p->text);
    if (cmp < 0) {
        p->lchild = addtree(p->lchild, word);
    } else if (cmp > 0) {
        p->rchild = addtree(p->rchild, word);
    } else {
        p->count++;
    }
    return p;
}

struct tnode *addcounttree(struct tnode *dest, struct tnode *source) {
    if (dest == NULL) {
        struct tnode *newnode = malloc(sizeof(struct tnode));
        newnode->text = source->text;
        newnode->count = source->count;
        newnode->lchild = newnode->rchild = NULL;
        return newnode;
    }

    if (source->count <= dest->count) {
        dest->lchild = addcounttree(dest->lchild, source);
    } else {
        dest->rchild = addcounttree(dest->rchild, source);
    }
    return dest;
}

struct tnode *sorttree(struct tnode *dest, struct tnode *source) {
    dest = addcounttree(dest, source);
    if (source != NULL) {
        if (source->lchild != NULL) {
            sorttree(dest, source->lchild);
        }
        if (source->rchild != NULL) {
            sorttree(dest, source->rchild);
        }
    }
    return dest;
}

void printtree(struct tnode *p) {
    if (p == NULL) {
        return;
    }
    printtree(p->lchild);
    printf("Word \"%s\": %d\n", p->text, p->count);
    printtree(p->rchild);
}

int getword(char *word, int lim) {
    int c;
    char *w = word;

    while (isspace(c = getchar()))
        ;

    if (c != EOF) {
        *w++ = c;
    }

    if (!isalpha(c)) {
        *w = '\0';
        return c;
    }

    for (; --lim > 0; w++) {
        if (!isalpha(*w = getchar())) {
            ungetc(*w, stdin);
            break;
        }
    }

    *w = '\0';
    return word[0];
}
