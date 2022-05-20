#include <stdio.h>
#include <stdlib.h>

struct treeNode{
	struct treeNode *leftPtr;
	int data;
	struct treeNode *rightPtr;
};

void inOrder(struct treeNode *nodePtr);
void preOrder(struct treeNode *nodePtr);
void postOrder(struct treeNode *nodePtr);
struct treeNode *search(struct treeNode *rootPtr, int value);
void insert(struct treeNode **PtrtorootPtr, int value);
struct treeNode *max(struct treeNode *nodePtr);
struct treeNode *min(struct treeNode *nodePtr);
struct  treeNode* deleteNode(struct  treeNode* root, int key);
int depth(struct treeNode *nodePtr);

int main()
{
    int user = 0, value;
    struct treeNode *rootPtr = NULL, *auxPtr;

    while (user != 99) {   
    printf("Enter your choice: \n"
		"1 to insert a new node\n"
		"2 to inOrder tree traversal\n"
		"3 to preOrder tree traversal\n"
		"4 to postOrder tree traversal\n"
		"5 to search a value\n"
		"6 to find max value\n"
		"7 to find min value\n"
    "8 to find the depth\n"
    "9 to delete a node:\n"
    "99 to exit\n"
		);

    printf("? ");
	  scanf(" %d", &user);

    switch (user)
        {
      	case 1:
      	    printf("Enter value to be inserted: ");
	    scanf(" %d", &value);

	    auxPtr = search(rootPtr, value);

	    if (auxPtr == NULL)
	        insert(&rootPtr, value);
				
	    else
	        printf("Duplicate data!\n");
				
	    break;

        case 2:
	    printf("\n The inOrder tree walk is: \n");

	    inOrder(rootPtr);
	    printf("\n");
                
	    break;

	case 3:
	    printf("\n The preOrder tree walk is: \n");

	    preOrder(rootPtr);
	    printf("\n");

	    break;

	case 4:
	    printf("\n The postOrder tree walk is: \n");

	    postOrder(rootPtr);
	    printf("\n");

	    break;

	case 5:
            printf("Enter value to be searched: ");
	    scanf(" %d", &value);

	    auxPtr = search(rootPtr, value);

	    if (auxPtr != NULL)
	    	printf("-Value: %d\n", auxPtr->data);
				
	    else
		printf("-Value: NULL\n");
				
            break;

        case 6:
	    printf("The maximum value is: \n");	
	    auxPtr = max(rootPtr);

	    if(auxPtr != NULL)
	        printf(" %d\n", auxPtr->data);
				
	    else
		printf("Emptry tree!\n");
				
	    break;

	case 7:
	    printf("The minmum value is: \n");	
	    auxPtr = min(rootPtr);

	    if(auxPtr != NULL)
	        printf(" %d\n", auxPtr->data);
				
	    else
		printf("Emptry tree!\n");
				
	    break;
            
        case 8:
           if (rootPtr == NULL)
               printf("There is no data!\n");

	   else
               printf("The depth of the tree is: %d\n", depth(rootPtr));

	   break;
      
        case 9:
	    if(rootPtr == NULL)
		printf("\nThere are no nodes\n");
        
		
	    else
		{
		printf("Delete a node: ");
        	scanf("%d",&value);

        	deleteNode(rootPtr, value);
		}

            break;

	default:
	    printf("Invalid choice!\n\n");
	    break;
        }
    }
    return 0;
}

void inOrder(struct treeNode *nodePtr){
	/* if subtree is not empty then traverse */
	if(nodePtr != NULL){
		inOrder(nodePtr->leftPtr);
		printf("%d ", nodePtr->data);
		inOrder(nodePtr->rightPtr);
	}
}

void preOrder(struct treeNode *nodePtr){
	/* if subtree is not empty then traverse */
	if(nodePtr != NULL){
		printf("%d ", nodePtr->data);
		preOrder(nodePtr->leftPtr);
		preOrder(nodePtr->rightPtr);
	}
}

void postOrder(struct treeNode *nodePtr){
	/* if subtree is not empty then traverse */
	if(nodePtr != NULL){
		postOrder(nodePtr->leftPtr);
		postOrder(nodePtr->rightPtr);
		printf("%d ", nodePtr->data);
	}
}

struct treeNode *search(struct treeNode *rootPtr, int value){
	struct treeNode *currentPtr;
	currentPtr = rootPtr;

	while(currentPtr != NULL && currentPtr->data != value){
		if (value > currentPtr->data){
			currentPtr = currentPtr->rightPtr;
		}
		else{
			currentPtr = currentPtr->leftPtr;
		}
	}

	return currentPtr;
}

void insert(struct treeNode **PtrtorootPtr, int value){
	struct treeNode *newPtr, *previousPtr, *currentPtr;

	/* Create new node */
	newPtr = malloc(sizeof(struct treeNode));

	/* Check if newPtr is not NULL */
	if (newPtr != NULL){
		newPtr->data = value;
		newPtr->rightPtr = NULL;
		newPtr->leftPtr = NULL;

		/* Iterate until right position */
		previousPtr = NULL;
		// *PtrtorootPtr = rootPtr
		currentPtr = *PtrtorootPtr;

		while(currentPtr != NULL){

			/* previousPtr Update */
			previousPtr = currentPtr;

			/* currentPtr Update */
			if (value > currentPtr->data){
				currentPtr = currentPtr->rightPtr;
			}
			else{
				currentPtr = currentPtr->leftPtr;
			}

		}

		/* Check if tree is empty */
		if (previousPtr == NULL){
			/* rootPtr (*PtrtorootPtr) Update */
			*PtrtorootPtr = newPtr;
		}
		/* Insert node to the right */
		else if (value > previousPtr->data){
			previousPtr->rightPtr = newPtr;
		}
		/* Insert node to the left */
		else{
			previousPtr->leftPtr = newPtr;
		}
	}
	else{
		printf("No memory available.\n");
	}
}

struct treeNode *max(struct treeNode *nodePtr){
	struct treeNode *temp = nodePtr;

	while(temp->rightPtr != NULL){
		temp = temp->rightPtr;
	}

	return temp;
}

struct treeNode *min(struct treeNode *nodePtr){
	struct treeNode *temp = nodePtr;
	
	while(temp->leftPtr != NULL){
		temp = temp->leftPtr;
	}

	return temp;
}

int depth(struct treeNode *nodePtr){


  return 0;
}

struct  treeNode* deleteNode(struct  treeNode* root, int val)
{
  if(root->data < val)
    root->rightPtr = deleteNode(root->rightPtr,val);

  else if(root->data > val)
    root->leftPtr = deleteNode(root->leftPtr,val);

    else
    {
        if(root->leftPtr == NULL && root->rightPtr == NULL)
        {
            free(root);
            return NULL;
        }

        else if(root->leftPtr == NULL&&root->rightPtr!=NULL)
        { 
            struct treeNode *temp = root->rightPtr;
            free(root);
            return temp;
        }

        else if(root->rightPtr == NULL&&root->leftPtr != NULL)
        {
            struct treeNode *temp = root->leftPtr;
            free(root);
            return temp;
        }

        else
        {
            int leftMax = max(root->leftPtr)->data;
            root->data = leftMax;
            root->leftPtr = deleteNode(root->leftPtr, leftMax);
        }

    }

    return root;
}
