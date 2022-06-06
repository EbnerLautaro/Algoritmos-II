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

static bool invrep(abb tree) {
    bool r = false;

    if (tree == NULL) {                                                 
        // arbol vacio                 
        r = true;
    } else  {
        // arbol izquierdo valido
        bool left = (tree->left == NULL || tree->left->elem < tree->elem);
        // arbol derecho valido
        bool right = (tree->right == NULL || tree->right->elem > tree->elem);
        r = left && right && invrep(tree->left) && invrep(tree->right);

    }    
    return r;
}

abb abb_empty(void) {
    abb tree = NULL;
    assert(invrep(tree) && abb_is_empty(tree));
    return tree;
}

abb abb_add(abb tree, abb_elem e) {
    assert(invrep(tree));
    
    struct _s_abb * node = NULL;
    node = malloc(sizeof(struct _s_abb));
    node->elem = e;
    node->left = NULL;
    node->right = NULL;
    
    if (tree != NULL) {
        if (e > tree->elem)  {	
            tree->right = abb_add(tree->right, e);
        } else if (e < tree->elem) {
            tree->left = abb_add(tree->left, e);
        }
    } else {
        tree = node;
    }
    assert(invrep(tree) && abb_exists(tree, e));
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
    unsigned int length = 0U;
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
        max_e = abb_max(tree->right);
    } else { 
        max_e = tree->elem;
    }
    assert(invrep(tree) && abb_exists(tree, max_e));
    return max_e;
}

abb_elem abb_min(abb tree) {
    abb_elem min_e;
    assert(invrep(tree) && !abb_is_empty(tree));
    if (tree->left!=NULL) {
        min_e = abb_min(tree->left);
    } else { 
        min_e = tree->elem;
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
    if(tree != NULL) {
        abb_destroy(tree->left);
        abb_destroy(tree->right);
        free(tree);
        // free(tree->left);
        // free(tree->right);
        tree = NULL;
    }
    assert(tree == NULL);
    return tree;
}


abb abb_remove(abb tree, abb_elem e) {
    assert(invrep(tree));
    abb res = tree;

    if (tree == NULL) {
        return tree;

    } else if (e > tree->elem) {
        //buscar en el arbol de la derecha
        tree->right = abb_remove(tree->right, e);
    
    } else if (e < tree->elem) {
        //buscar en el arbol de la izquierda
        tree->left = abb_remove(tree->left, e);      
    
    } else if (e == tree->elem) {
        // este es el elemento que tengo que eliminar

        if (tree->left == NULL && tree->right == NULL) {
            free(tree);
            tree = NULL;
            res = tree;
            // return tree;

        } else if (tree->left != NULL && tree->right == NULL) {
            abb tmp = tree->left;
            free(tree);
            tree = NULL;
            res = tmp;
            // return tmp;

        } else if (tree->left == NULL && tree->right != NULL) {
            abb tmp = tree->right;
            free(tree);
            tree = NULL;
            res = tmp;
            // return tmp;

        } else if (tree->left != NULL && tree->right != NULL) {
            abb_elem min_elem = abb_min(tree->right);
            tree->elem = min_elem;
            tree->right = abb_remove(tree->right, min_elem);
            res = tree;
        }
    }    
    assert(invrep(res) && !abb_exists(res, e));
    return res;
}
