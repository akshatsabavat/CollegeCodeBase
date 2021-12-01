
#include<stdio.h>
#include<stdlib.h>

struct treenode {
    int value;
    struct treenode* left;
    struct treenode* right;
}*AlphaRoot = NULL;

int max(int a,int b){
    if(a > b){
        return a;
    }else {
        return b;
    }
}

void PreorderTraversal( struct treenode* Root){
 struct treenode* pointer = Root;

    if(pointer == NULL){
        return;
    }else {
        printf(" %d -> ",pointer -> value);
        PreorderTraversal(pointer -> left);
        PreorderTraversal(pointer -> right);
    }
}

void InorderTraversal( struct treenode* Root){
 struct treenode* pointer = Root;

    if(pointer == NULL){
        return;
    }else {
        InorderTraversal(pointer -> left);
        printf(" %d -> ",pointer -> value);
        InorderTraversal(pointer -> right);
    }
}


struct treenode* TreeNodeCreation(int data){
    struct treenode* temp = malloc(sizeof(struct treenode));
    temp -> value = data;
    temp -> right = NULL;
    temp -> left = NULL;
    return temp;
}

struct treenode* MakeTree(int number,struct treenode* TreeRoot){
    struct treenode* Tptr = TreeRoot;
    if(TreeRoot == NULL){
        TreeRoot = TreeNodeCreation(number);
        return TreeRoot;
    }else if(number <= TreeRoot -> value){
        TreeRoot -> left = MakeTree(number,TreeRoot -> left);
    }else {
        TreeRoot -> right = MakeTree(number,TreeRoot -> right);
    }
    
    return TreeRoot;
}

int TreeHieght(struct treenode* root){
    if(root == NULL){
        return 0;
    }else {
        return max(TreeHieght(root -> left),TreeHieght(root -> right)) + 1;
    }
}

void PrintLeafNodes(struct treenode* root){
    struct treenode* pointer = root;

    if(pointer == NULL){
        return;
    }else {
        if(pointer -> left == NULL && pointer -> right == NULL){
             printf(" %d, ",pointer -> value);
             return;
        }else {
            PrintLeafNodes(pointer -> left);
            PrintLeafNodes(pointer -> right);
        }
    }
}

void LargestVal(struct treenode* root){
    struct treenode* Tptr = root;
    while (Tptr -> right != NULL){
        Tptr = Tptr -> right;
    }
    
    printf("%d",Tptr -> value);
}

void SmallestVal(struct treenode* root){
    struct treenode* Tptr = root;
    while (Tptr ->left != NULL){
        Tptr = Tptr -> left;
    }
    
    printf("%d",Tptr -> value);
}

void CodeExecution(){
       int N;


    FILE *file_pointer1;

    file_pointer1 = fopen("tree.txt","r");

    if(file_pointer1 == NULL){
        puts("file not found");
    }

    while (!feof(file_pointer1))
    {
        fscanf(file_pointer1,"%d",&N);
        AlphaRoot = MakeTree(N,AlphaRoot);
    }

    printf("BST created");
    printf("\n");
    printf("Preorder Traversal: ");
    PreorderTraversal(AlphaRoot);
    printf("\n");
    printf("Inorder Traversal: ");
    InorderTraversal(AlphaRoot);
    printf("\n");
    printf("Leaf Nodes : ");
    PrintLeafNodes(AlphaRoot);
    printf("\n");
    printf("Hieght of the Tree : %d",TreeHieght(AlphaRoot));
    printf("\n");
    printf("Largest value of the Tree : ");
    LargestVal(AlphaRoot);
    printf("\n");
    printf("Smallest value of the Tree : ");
    SmallestVal(AlphaRoot);
    
}

int main()
{
    CodeExecution();
}