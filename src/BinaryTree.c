#include <stdio.h>
#include "BinaryTree.h"
#include "Stack.h"

void binaryTreeTraverseInOrder(Node *root)
{
    Stack *stack = stackNew();
    Node *currentNode = root;
    printf("created a stack\n");

    printf("currentNode->data: %d\n", currentNode->data);
    currentNode->state = UNKNOWN_NODE_STATE;

    do{
        if(currentNode->left == NULL && currentNode->right == NULL)
        {
            if(currentNode->state == VISITED_RIGHT_NODE)
            {
                currentNode = stackPop(stack);
                if(currentNode != NULL)
                {
                    printf("pop: %d\n", currentNode->data);
                    if(currentNode->left == NULL)
                    {
                        currentNode->right = NULL;
                        currentNode->state = VISITED_RIGHT_NODE;
                    }
                    else
                        currentNode->left = NULL;
                }
            }
            else
            {
                display(currentNode->data);
                printf("display: %d\n", currentNode->data);
                currentNode = stackPop(stack);
                if(currentNode != NULL)
                {
                    printf("pop: %d\n", currentNode->data);
                    if(currentNode->state == VISITED_LEFT_NODE)
                    {
                        currentNode->state = VISITED_RIGHT_NODE;
                        currentNode->right = NULL;
                    }
                    else
                    {
                        currentNode->state = VISITED_LEFT_NODE;
                        currentNode->left = NULL;
                    }
                }
            }
        }
        else if(currentNode->left != NULL)
        {
            currentNode->state = ENTERED_NODE;
            stackPush(stack, (Node *)currentNode);
            printf("push: %d\n", currentNode->data);
            currentNode = currentNode->left;    //visiting left child node
            printf("currentNode->data: %d\n", currentNode->data);
        }
        else if(currentNode->right != NULL)
        {
            display(currentNode->data);
            printf("display: %d\n", currentNode->data);
            currentNode->state = VISITED_LEFT_NODE;
            stackPush(stack, (Node *)currentNode);
            printf("push: %d\n", currentNode->data);
            currentNode = currentNode->right;   //visiting right child node
            printf("currentNode->data: %d\n", currentNode->data);
        }
    }while(currentNode != NULL);

    stackDel(stack);
    printf("deleted a stack\n");
}

void binaryTreePrintInOrder(Node *node)
{
    if(node != NULL)
    {
        binaryTreePrintInOrder(node->left);
        display(node->data);
        printf("%d ", node->data);
        binaryTreePrintInOrder(node->right);
    }
}

void printLinear(Node *node)
{
    if(node != NULL)
    {
        binaryTreePrintInOrder(node->left);
        display(node->data);
        printf("%d ", node->data);
    }
    printf("\n");
}