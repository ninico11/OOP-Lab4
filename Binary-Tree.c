#include<stdio.h>
#include<stdlib.h>
struct node{
 int element;
 struct node *left, *right;
};
struct node *new_node(int element){
 struct node *temp = (struct node *)malloc(sizeof(struct node));
 temp->element = element;
 temp->left = temp->right = NULL;
 return temp;
}
void inorder(struct node* root){
 if (root != NULL) {
  inorder(root->left);
  printf("%d ", root->element);
  inorder(root->right);
 }
}
void postorder(struct node* node){
 if (node != NULL){
  postorder(node->left);
  postorder(node->right);
  printf("%d ", node->element);
 }
}
void preorder(struct node* node){
 if (node != NULL){
  printf("%d ", node->element);
  preorder(node->left);
  preorder(node->right);
 }
}
struct node *insert(struct node *node, int element){
int k;
  if (node == NULL) return new_node(element);
  else {
   printf("Element: %d\n ", node->element);
  if (node->left != NULL) printf("Left: %d\n ", node->left->element);
  else printf("Left: Empty\n ");
  if (node->right != NULL) printf("Right: %d\n ", node->right->element);
  else printf("Right: Empty\n ");
   printf("\nInsert 1- left, 2 - right\n"); scanf("%d", &k);
  switch(k){
     case 1: node->left = insert(node->left, element); break;
     case 2: node->right = insert(node->right, element); break;
  }
}
return node;
}
struct node* minValueNode(struct node* node){
    struct node* current = node;
    while (current && current->left != NULL)
        current = current->left;
    return current;
}
struct node* deleteNode(struct node* root, int element){
    if (root == NULL)
        return root;
    if (element < root->element)
        root->left = deleteNode(root->left, element);
    else if (element> root->element)
        root->right = deleteNode(root->right, element);
    else {
        if (root->left == NULL) {
            struct node* temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL) {
            struct node* temp = root->left;
            free(root);
            return temp;
        }
        struct node* temp = minValueNode(root->right);
        root->element = temp->element;
        root->right = deleteNode(root->right, temp->element);
    }
    return root;
}
void storeInorder(struct node* node, int inorder[], int* index_ptr){
    if (node == NULL)
        return;
    storeInorder(node->left, inorder, index_ptr);
    inorder[*index_ptr] = node->element;
    (*index_ptr)++;
    storeInorder(node->right, inorder, index_ptr);
}
int countNodes(struct node* root){
    if (root == NULL)
        return 0;
    return countNodes(root->left) + countNodes(root->right) + 1;
}
int compare(const void* a, const void* b){
    return (*(int*)a - *(int*)b);
}
void arrayToBST(int* arr, struct node* root, int* index_ptr){
    if (root == NULL)
        return;
    arrayToBST(arr, root->left, index_ptr);
    root->element = arr[*index_ptr];
    (*index_ptr)++;
    arrayToBST(arr, root->right, index_ptr);
}
void Sort(struct node* root){
    if (root == NULL)
        return;
    int n = countNodes(root);
    int* arr = malloc(n*sizeof(*arr));
    int i = 0;
    storeInorder(root, arr, &i);
    qsort(arr, n, sizeof(arr[0]), compare);
    i = 0;
    arrayToBST(arr, root, &i);
    free(arr);
}
struct node* buildTreeUtil(int* arr, int start,int end){
    if (start > end)
        return NULL;
    int mid = (start + end)/2;
    struct node *root = NULL;
    root->element=arr[mid];
    root->left  = buildTreeUtil(arr, start, mid-1);
    root->right = buildTreeUtil(arr, mid+1, end);
    return root;
}
struct node* Balance(struct node* root){
    int n = countNodes(root);
    int* arr = malloc(n*sizeof(*arr));
    int i = 0;
    storeInorder(root, arr, &i);
    qsort(arr, n, sizeof(arr[0]), compare);
    return buildTreeUtil(arr, 0, n-1);

}
int main(){
 FILE *fp;
 struct node *root = NULL;
 int nr,choice,height=0;
 do{
  printf("Menu\n\n");
  printf("1. Insert\n");
  printf("2. Delete\n");
  printf("3. Inorder\n");
  printf("4. Postorder\n");
  printf("5. Preorder\n");
  printf("6. Sort\n");
  printf("7. Balance\n");
  printf("8. Save In File\n");
  printf("9. Load From File\n");
  printf("10. Exit\n");
  scanf("%d",&choice);

  switch (choice){
     case 1:printf("Write the element: ");
            scanf("%d",&nr);
            root=insert(root,nr);
          break;
     case 2:printf("Delete the element: ");
            scanf("%d",&nr);
            root=deleteNode(root,nr);
          break;
     case 3:inorder(root);
            printf("\n");
          break;
     case 4:postorder(root);
            printf("\n");
          break;
     case 5:preorder(root);
            printf("\n");
          break;
     case 6:Sort(root);
          break;
     case 7:Balance(root);
          break;
     case 8:char fname[20];
	    printf(" Input the filename to be opened : ");
            scanf("%s",fname);
            int n = countNodes(root);
            int* arr = malloc(n*sizeof(*arr));
            int i = 0;
            storeInorder(root, arr, &i);
            fp = fopen(fname,"w+");
            for(int i=0;i<n;i++){
              fprintf(fp,"%d ",arr[i]);
            }
            fclose(fp);
          break;
     case 9:printf(" Input the filename to be opened : ");
            scanf("%s",fname);
            fp = fopen("tree.txt", "r");
            int* tree=malloc(100*sizeof(*tree));
            int j=0;
            int num;
            while(fscanf(fp, "%d", &num) > 0) {
             tree[j] = num;
             j++;
            }
            for(int i=0;i<j;i++){
             printf("%d ",tree[i]);
            };
            printf("\n");
            int ind=0;
            root=new_node(tree[0]);
            arrayToBST(tree,root,&ind);
            fclose(fp);
          break;
     case 10: printf("Goodbye\n");
          break;
     default: printf("Wrong Choice. Enter again\n");
          break;
  }
 } while (choice != 10);
return 0;
}
