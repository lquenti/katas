#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef int VALUE_TYPE;

struct avl {
  struct avl *parent, *left, *right;
  VALUE_TYPE val;
};

struct avl *new_node(struct avl *parent, VALUE_TYPE cont) {
    struct avl *ret = calloc(1, sizeof(struct avl));
    ret->parent = parent;
    ret->val = cont;
    return ret;
}


void add(struct avl *a, VALUE_TYPE cont) {
    while (1) {
        if (a->val == cont) {
            return;
        }
        else if (a->val > cont) {
            if (a->left) {
                a = a->left;
                continue;
            } else {
                a->left = new_node(a, cont);
                return;
            }
        } else {
            if (a->right) {
                a = a->right;
                continue;
            } else {
                a->right = new_node(a, cont);
                return;
            }
        }
    }

}

struct avl *contains(struct avl *a, VALUE_TYPE cont) {
    while (a && a->val != cont) {
        if (a->val < cont) {
            a = a->right;
        } else {
            a = a->left;
        }
    }
    return a;
}

struct avl *min(struct avl *a) {
    for (; a->left; a=a->left);
    return a;
}

struct avl *succ(struct avl *a) {
    if (a->right) {
        return min(a->right);
    }

    while (a->parent) {
        if (a->parent->left == a) {
            return a->parent;
        }
        a = a->parent;
    }
    return NULL;
}

/*
    1
   0     2
 -1    1.5  3
           2.5 4


*/

/*
a  c
  b
d  e
*/


int main() {

    struct avl *a = new_node(NULL, 1);

    /*
         1
      0     3
    -1         5
   -2         4     7
    */

    add(a, 3);
    add(a, 0);
    add(a, 5);
    add(a, -1);
    add(a, -2);
    add(a, 7);
    add(a, 4);

    assert( contains(a, 1) );
    assert( contains(a, 3) );
    assert( contains(a, 0) );
    assert( contains(a, -1) );
    assert( contains(a, -2) );
    assert( contains(a, 5) );
    assert( contains(a, 7) );
    assert( contains(a, 4) );
    assert( !contains(a, 2) );

    int i=0;
    for (struct avl *it = min(a); it; it = succ(it)) {
        printf("%d ", it->val);
        i++;
        if (i>10) break;

    }
    printf("\n");
}
