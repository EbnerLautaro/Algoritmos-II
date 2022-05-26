#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <assert.h>
#include "abb.h"

struct _s_abb {
    abb_elem elem;
    struct _s_abb *left;
    struct _s_abb *right;
};

static bool elem_eq(abb_elem a, abb_elem b) {
    return a == b;
}

static bool elem_less(abb_elem a, abb_elem b) {
    return a < b;
}

static bool invrep(abb tree) {
    bool r = false;

    if (tree == NULL) {                                                 
        // arbol vacio                 
        r = true;
    } else  {
        // arbol izquierdo valido
        bool left = (tree->left == NULL || tree->left->elem < tree->elem);
        // arbol derecho valido
        bool rigth = (tree->right == NULL || tree->right->elem > tree->elem)
        r = left && rigth;
    }    
    return r && invrep(tree->left) && invrep(tree->right) ;
}

abb abb_empty(void) {
    abb tree = NULL;
    assert(invrep(tree) && abb_is_empty(tree));
    return tree;
}

abb abb_add(abb tree, abb_elem e) {
    assert(invrep(tree));

    


    assert(invrep(tree) && abb_exists(tree, e));
    return tree;
}

abb abb_remove(abb tree, abb_elem e) {
    assert(invrep(tree));
    /*
     * Needs implementation
     */
    assert(invrep(tree) && !abb_exists(tree, e));
    return tree;
}

bool abb_is_empty(abb tree) {
    assert(invrep(tree));
    return tree==NULL;
}

bool abb_exists(abb tree, abb_elem e) {
    assert(invrep(tree));
    bool exists=false;
    if (tree != NULL) {
        if (tree->elem == e){
            exists = true;
        } else if (tree->elem > e) {
            // Analizar arbol izquierdo
            exists = abb_exists(tree->left, e);
            
        } else if (tree->elem < e) {
            // Analizar arbol derecho
            exists = abb_exists(tree->right, e);
        } else {
            // Si es distinto, se podria omitir pero es mas legible
            exists=false;
        }
    }
    return exists;
}

unsigned int abb_length(abb tree) {
    unsigned int length=0;
    assert(invrep(tree));
    
    if (tree != NULL)
    {
        length = 1 + abb_length(tree->left) + abb_length(tree->right);
    }
    assert(invrep(tree) && (abb_is_empty(tree) || length > 0));
    return length;
}

abb_elem abb_root(abb tree) {
    assert(invrep(tree) && !abb_is_empty(tree));
    abb_elem root = tree->elem;
    assert(abb_exists(tree, root));
    return root;
}

abb_elem abb_max(abb tree) {
    abb_elem max_e;
    assert(invrep(tree) && !abb_is_empty(tree));
    if (tree->right!=NULL) {
        e = abb_max(tree->right);
    } else { 
        e = tree->elem;
    }
    assert(invrep(tree) && abb_exists(tree, max_e));
    return max_e;
}

abb_elem abb_min(abb tree) {
    abb_elem min_e;
    assert(invrep(tree) && !abb_is_empty(tree));
    if (tree->left!=NULL) {
        e = abb_min(tree->left);
    } else { 
        e = tree->elem;
    }
    assert(invrep(tree) && abb_exists(tree, min_e));
    return min_e;
}

void abb_dump(abb tree) {
    assert(invrep(tree));
    if (tree != NULL) {
        abb_dump(tree->left);
        printf("%d ", tree->elem);
        abb_dump(tree->right);
    }
}

abb abb_destroy(abb tree) {
    assert(invrep(tree));
    /*
     * Needs implementation
     */
    assert(tree == NULL);
    return tree;
}

