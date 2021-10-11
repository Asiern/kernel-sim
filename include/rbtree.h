#ifndef _RBTREE_H
#define _RBTREE_H

#include <assert.h>
#include <stddef.h>

enum color_t
{
    BLACK,
    RED
};

typedef struct
{
    RBnode* parent;
    RBnode* child[2];
    enum color_t color;
    int key;
} RBnode;

#define NIL NULL // null pointer  or  pointer to sentinel node
#define LEFT 0
#define RIGHT 1
#define left child[LEFT]
#define right child[RIGHT]

typedef struct
{
    RBnode* root;
} RBtree;

// Get the child direction (∈ { LEFT, RIGHT })
//   of the non-root non-NIL  RBnode* N:
#define childDir(N) (N == (N->parent)->right ? RIGHT : LEFT)

// Helper functions:

RBnode* GetParent(RBnode* N)
{
    // The parent of the root node is set to NULL.
    return N == NULL ? NULL : N->parent;
}

RBnode* GetGrandParent(RBnode* N)
{
    // Will return NULL if N is root or child of root
    return GetParent(GetParent(N));
}

RBnode* GetSibling(RBnode* N)
{
    RBnode* P = GetParent(N);
    // No parent means no sibling:
    assert(P != NULL);
    return P->child[1 - childDir(N)];
}
// If parent P and child direction dir is available, same as:
//   P->child[1-dir]

RBnode* GetUncle(RBnode* N)
{
    RBnode* P = GetParent(N);
    // No parent means no uncle:
    assert(P != NULL);
    return GetSibling(P);
}

RBnode* GetCloseNephew(RBnode* N)
{
    RBnode* P = GetParent(N);
    int dir;
    RBnode* S;
    assert(P != NULL);
    dir = childDir(N);
    S = P->child[1 - dir]; // sibling of N
    assert(S != NIL);
    return S->child[dir]; // the nephew close to N
}

RBnode* GetDistantNephew(RBnode* N)
{
    RBnode* P = GetParent(N);
    int dir;
    RBnode* S;
    assert(P != NULL);
    dir = childDir(N);
    S = P->child[1 - dir]; // sibling of N
    assert(S != NIL);
    return S->child[1 - dir]; // the nephew distant from N
}

RBnode* RotateDirRoot(RBtree* T, // red–black tree
                      RBnode* P, // root of subtree (may be the root of T)
                      int dir)
{ // dir ∈ { LEFT, RIGHT }
    RBnode* G = P->parent;
    RBnode* S = P->child[1 - dir];
    RBnode* C;
    assert(S != NIL); // pointer to true node required
    C = S->child[dir];
    P->child[1 - dir] = C;
    if (C != NIL)
        C->parent = P;
    S->child[dir] = P;
    P->parent = S;
    S->parent = G;
    if (G != NULL)
        G->child[P == G->right ? RIGHT : LEFT] = S;
    else
        T->root = S;
    return S; // new root of subtree
}

#define RotateDir(N, dir) RotateDirRoot(T, N, dir)
#define RotateLeft(N) RotateDirRoot(T, N, LEFT)
#define RotateRight(N) RotateDirRoot(T, N, RIGHT)

#endif