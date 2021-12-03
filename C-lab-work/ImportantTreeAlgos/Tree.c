#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct node {
    int tree_val;
    struct node* left;
    struct node* right;
}*AlphaRoot = NULL;

int counter_val = 0;
int BSTarr[100];

int max(int a,int b){
    if(a > b){
        return a;
    }else {
        return b;
    }
}


struct node* NodeCreation(int value){
    struct node* temp = malloc(sizeof(struct node));
    temp -> tree_val = value;
    temp -> left = NULL;
    temp -> right = NULL;
    return temp;
}

struct node* MakeBST(struct node* root,int treenodenumber){
    if(root == NULL){
        root = NodeCreation(treenodenumber);
        return root;
    }else {
        if(treenodenumber > root -> tree_val){
            root -> right = MakeBST(root -> right,treenodenumber);
        }else {
            root -> left = MakeBST(root -> left, treenodenumber);
        }
    }

    return root;
}

void PreT(struct node* root){
    if(root == NULL){
        return;
    }else {
        printf(" %d -> ",root -> tree_val);
        PreT(root -> left);
        PreT(root -> right);
    }
}

void InoT(struct node* root){
    if(root == NULL){
        return;
    }else {
        PreT(root -> left);
        printf(" %d -> ",root -> tree_val);
        PreT(root -> right);
    }
}

int NodeCount(struct node* root){
    if(root == NULL){
        return 0;
    }else {
        return 1 + NodeCount(root -> left) + NodeCount(root -> right);
    }
}

int NodeCountTwoCh(struct node* root){
    if(root == NULL){
        return 0 ;
    }else {
        if(root -> left != NULL && root -> right != NULL){
            return 1 + NodeCountTwoCh(root -> left) + NodeCountTwoCh(root -> right);
        }else {
            return NodeCountTwoCh(root -> left) + NodeCountTwoCh(root -> right);
        }
    }
}

int HieghtofTree(struct node* root){
    if(root == NULL){
        return 0;
    }else{
        return max(HieghtofTree(root -> left),HieghtofTree(root ->right)) + 1;
    }
}

int SearchBst(struct node* root, int NTS){
    struct node* pointer = root;
    while (pointer != NULL)
    {
        if(pointer -> tree_val == NTS){
            return 1;
        }else if(pointer -> tree_val < NTS){
            return SearchBst(pointer -> right, NTS);
        }else {
            return SearchBst(pointer -> left, NTS);
        }
    }

    return 0;
    
}

void ElementinBst(int NTS){
    if(SearchBst(AlphaRoot,NTS)){
        printf("Element found");
    }else {
        printf("Element is not in the BST");
    }
}

struct node* SmallestVal(struct node* root){
    struct node* Tptr = root;
    while (Tptr ->left != NULL){
        Tptr = Tptr -> left;
    }
    
    return Tptr;
}

struct node* DeletionBST(struct node* root, int NTD){
    struct node* pointer = root;
    struct node* deletion_pointer;
    while(pointer != NULL){
        if(pointer -> tree_val == NTD){
            deletion_pointer  = pointer;
            printf("Element found");
            break;
        }else if(pointer -> tree_val < NTD){
            root -> right = DeletionBST(root -> right, NTD);
        }else {
            root -> left = DeletionBST(root -> left, NTD);
        }
    }

    //Case 1: No child
    if(deletion_pointer -> left == NULL && deletion_pointer -> right == NULL){
        free(deletion_pointer);
    }

    //Case 2: One child
    else if(deletion_pointer -> left == NULL){
        deletion_pointer -> tree_val = deletion_pointer -> right -> tree_val;
        deletion_pointer = deletion_pointer -> right;
        free(deletion_pointer);
    }

     else if(deletion_pointer -> right == NULL){
        deletion_pointer -> tree_val = deletion_pointer -> left -> tree_val;
        deletion_pointer = deletion_pointer -> left;
        free(deletion_pointer);
    }


    //Case 3: Two children
    else {
        struct node* temp;
        temp = SmallestVal(deletion_pointer -> right);
        deletion_pointer -> tree_val = temp -> tree_val;
        free(temp);
    }
}

int isBalanced(struct node* root){
    if(root == NULL){
        return 1;
    }else {
        int hL = HieghtofTree(root -> left);
        int hR = HieghtofTree(root -> right);

        if(abs(hL - hR) <= 1 && isBalanced(root -> left) && isBalanced(root -> right)){
            return 1;
        }
    }

    return 0;
}


int main(){
    AlphaRoot =  MakeBST(AlphaRoot,33);
    AlphaRoot =  MakeBST(AlphaRoot,13);
    AlphaRoot =  MakeBST(AlphaRoot,22);
    AlphaRoot =  MakeBST(AlphaRoot,56);
    AlphaRoot =  MakeBST(AlphaRoot,89);
    AlphaRoot =  MakeBST(AlphaRoot,37);
    AlphaRoot =  MakeBST(AlphaRoot,9);
    printf("%d",isBalanced(AlphaRoot));
}