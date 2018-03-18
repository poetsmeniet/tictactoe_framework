#include <stdio.h>
#include <stdlib.h>
#define MAXBRANCHES 9 /* Array size */

/* Just a POC for generating an extensive gametree */

typedef struct tree{
    int nr;
    int points;
    struct tree *branche[MAXBRANCHES];
}tree;

int populateTree();

int traverseTree();
    
static int brancheCnt = 0;
    
int main(void)
{
    //int depth = 9; /* Nr of layers to branch */
    //int brCnt = 9; /* Nr of branches per node, dynamic.. */
    int depth = 3; /* Nr of layers to branch */
    int brCnt = 3; /* Nr of branches per node, dynamic.. */

    /* Check for sanity of the programmer */
    if(brCnt > MAXBRANCHES){
        printf("Nope, brCnt too high.. exiting\n");
        return 1;
    }

    /* Define binary tree */
    tree tree;
    tree.nr = 0;
    tree.points = 0;
    tree.branche[0]= NULL;

    populateTree(&tree, depth, brCnt);

    printf("Root: %i\n", tree.nr);

    int i;

    int pathScores[depth];
    for(i = 1; i <= depth; i++)
        pathScores[i] = 0;
    traverseTree(&tree, 0, 0, &pathScores);
    
    printf("checking pathScores:\n");
    for(i = 1; i <= depth; i++){
        printf("path %i has total score of %i\n", i, pathScores[i]);
    }

    return 0;
}

/* Populate tree with arbitrary data */
int populateTree(tree *branch, int depth, int brCnt)
{
    /* Base case */
    if(depth == 0){
        printf("WE HAVE REACHED THE END: %i, points: %i\n", branch->nr, branch->points);
        return 0;
    }

    /* Supplied arbitrary value for tree branche */
    static int cnt = 1;

    int j;
    int points = 3;

    //example points assignment
        if(cnt == 6\
                || cnt == 11)
            points = 1;
        else if(cnt == 15 || cnt == 10)
            points = -1;
        else
            points = 0;

    for(j = 0; j < brCnt; j++){
        branch->branche[j] = malloc(sizeof(tree));
        branch->branche[j]->nr = cnt;
        branch->branche[j]->points = points;
        branch->branche[j]->branche[0]= NULL;
        
        brancheCnt++;
        cnt++;
    }

    /* Relying on last branch to be NULL */
    branch->branche[j]= NULL;

    depth--;
    brCnt--;

    for(j = 0; j <= brCnt; j++)
        populateTree(branch->branche[j], depth, brCnt);

    return 0;
}

/* Traverse the tree recursively */
int traverseTree(tree *tree, int parent, int points, int *pathScores)
{
    int j;

    int totPoints;
    static int endstateCnt = 0;

    /* Get the number of branches */
    int i = 1;
    while(tree->branche[i] != NULL)
        i++;

    totPoints = points + tree->points;
    /* Go through this branch */
    for(j = 0; j < i; j++){
        /* End case */
        if(tree->branche[j] == NULL){
            printf("\tendstate cnt: %i, totPoints: %i\n", endstateCnt, totPoints);
            /* Add score of this path to array */
            pathScores[endstateCnt] += totPoints;
            return totPoints;
        }

        /* Increment path index */
        if(parent == 0)
            endstateCnt++;

        printf("nodenr: %i (parent: %i), points: %i totPoints: %i\n", tree->branche[j]->nr, parent, tree->branche[j]->points, totPoints);
        
        traverseTree(tree->branche[j], tree->branche[j]->nr, totPoints, pathScores);
    }

    return 0;
}
