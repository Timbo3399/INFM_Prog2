#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>
#include <stdio.h>

struct Node
{
   unsigned int uiData;
   struct Node* psNextNode;
};
typedef struct Node sNode_t;
typedef sNode_t* psNode_t;
typedef psNode_t* ppsNode_t;

// API functions for linked list
int InsertElementBack(ppsNode_t ppsAnchor, psNode_t psNewNodePassed);
int InsertElementFront(ppsNode_t ppsAnchor, psNode_t psNewNodePassed);
int InsertElementAt  (ppsNode_t ppsAnchor, psNode_t psNewNodePassed, unsigned int uiPos);
int DeleteElementBack(ppsNode_t ppsAnchor);
int DeleteElementFront(ppsNode_t ppsAnchor);
int DeleteElementAt  (ppsNode_t ppsAnchor, unsigned int uiPos);
int DeleteList(ppsNode_t ppsAnchor);
int DeleteElementsRecursive(psNode_t psNodeDelete);

// Utilities functions for linked list
void PrintElements(psNode_t psNode);
void PrintList(psNode_t psNodeAnchor);
unsigned int GetNumberElements(psNode_t psNode);



int main(void)
{
   // Definition Nodes and Anchor
   psNode_t psAnchorNode = NULL;
   sNode_t asNodes[2] = { {1U,NULL},
                         {2U,NULL} };
   sNode_t sNodeA = { 3U,NULL };

   psNode_t psNodeB = (psNode_t)malloc(sizeof(sNode_t));
   psNodeB->psNextNode = NULL;
   psNodeB->uiData = 4U;

   // Start Testdriver for linked list

   putchar('\n');
   printf("***Test 1: Input empty list *******************************\n");
   PrintList(psAnchorNode);
   printf("***Check 1: List is empty - no elements *******************\n");

   putchar('\n');
   printf("***Test 2: Fill empty list with InsertElementBack *********\n");
   InsertElementBack(&psAnchorNode, &asNodes[1]);
   InsertElementBack(&psAnchorNode, psNodeB);
   InsertElementBack(&psAnchorNode, &asNodes[0]);
   InsertElementBack(&psAnchorNode, &sNodeA);
   PrintList(psAnchorNode);
   printf("***Check 2: List with 4 elements, uiData 2, 4, 1, 3 *******\n");

   putchar('\n');
   printf("***Test 3: Delete previous filled list ********************\n");
   DeleteList(&psAnchorNode);
   PrintList(psAnchorNode);
   printf("***Check 3: List is empty - no elements *******************\n");

   putchar('\n');
   printf("***Test 4: Fill empty list with InsertElementFront ********\n");
   InsertElementFront(&psAnchorNode, &asNodes[1]);
   InsertElementFront(&psAnchorNode, psNodeB);
   InsertElementFront(&psAnchorNode, &asNodes[0]);
   InsertElementFront(&psAnchorNode, &sNodeA);
   PrintList(psAnchorNode);
   printf("***Check 4: List with 4 elements, uiData 3, 1, 4, 2 ******\n");

   putchar('\n');
   printf("***Test 5: Delete previous filled list ********************\n");
   DeleteList(&psAnchorNode);
   PrintList(psAnchorNode);
   printf("***Check 5: List is empty - no elements *******************\n");

   putchar('\n');
   printf("***Test 6: Fill empty list with InsertElementFront ********\n");
   printf("***        and InsertElementBack **************************\n");
   InsertElementFront(&psAnchorNode, psNodeB);
   InsertElementBack(&psAnchorNode, &asNodes[0]);
   InsertElementFront(&psAnchorNode, &asNodes[1]);
   InsertElementFront(&psAnchorNode, &sNodeA);
   InsertElementBack(&psAnchorNode, &sNodeA);
   InsertElementBack(&psAnchorNode, &asNodes[0]);
   PrintList(psAnchorNode);
   printf("***Check 6: List with 6 elements, uiData 3, 2, 4, 1, 3, 1**\n");

   putchar('\n');
   printf("***Test 7: Delete 2 elements with DeleteElementBack********\n");
   DeleteElementBack(&psAnchorNode);
   DeleteElementBack(&psAnchorNode);
   PrintList(psAnchorNode);
   printf("***Check 7: List with 4 elements, uiData 3, 2, 4, 1 *******\n");

   putchar('\n');
   printf("***Test 8: Delete 4 elements with DeleteElementBack *******\n");
   DeleteElementBack(&psAnchorNode);
   DeleteElementBack(&psAnchorNode);
   DeleteElementBack(&psAnchorNode);
   DeleteElementBack(&psAnchorNode);
   PrintList(psAnchorNode);
   printf("***Check 8: List is Empty - no Elements *******************\n");

   putchar('\n');
   printf("***Test 9: Test InsertElementAdd uiPos too high   ********\n");
   printf("***        List is empty *********************************\n");
   InsertElementAt(&psAnchorNode, psNodeB, 1);
   PrintList(psAnchorNode);
   printf("***Check 9: List is Empty - no Elements *******************\n");

   putchar('\n');
   printf("***Test 10: Test InsertElementAdd uiPos correct ***********\n");
   printf("***         List is empty *********************************\n");
   InsertElementAt(&psAnchorNode, psNodeB, 0);
   PrintList(psAnchorNode);
   printf("***Check 10: List with 1 elements uiData 4 ****************\n");

   putchar('\n');
   printf("***Test 11: Test InsertElementAdd uiPos correct ***********\n");
   printf("***         List has 1 element ****************************\n");
   InsertElementAt(&psAnchorNode, &sNodeA, 1);
   PrintList(psAnchorNode);
   printf("***Check 11: List with 2 elements uiData 4, 3 *************\n");

   putchar('\n');
   printf("***Test 12: Test InsertElementAdd uiPos not correct *******\n");
   printf("***         List has 2 elements ***************************\n");
   InsertElementAt(&psAnchorNode, &asNodes[0], 3);
   PrintList(psAnchorNode);
   printf("***Check 12: List with 2 elements uiData 4, 3 *************\n");

   putchar('\n');
   printf("***Test 12: Test InsertElementAdd uiPos is correct ********\n");
   printf("***         List has 2 elements ***************************\n");
   InsertElementAt(&psAnchorNode, &asNodes[0], 2);
   PrintList(psAnchorNode);
   printf("***Check 12: List with 3 elements uiData 4, 3, 1 **********\n");

   putchar('\n');
   printf("***Test 13: Test InsertElementAdd uiPos is correct ********\n");
   printf("***         List has 3 elements ***************************\n");
   InsertElementAt(&psAnchorNode, &asNodes[0], 0);
   PrintList(psAnchorNode);
   printf("***Check 12: List with 4 elements uiData 1, 4, 3, 1 *******\n");

   putchar('\n');
   printf("***Test 13: Test InsertElementAdd uiPos is correct ********\n");
   printf("***         List has 4 elements ***************************\n");
   InsertElementAt(&psAnchorNode, &asNodes[1], 2);
   PrintList(psAnchorNode);
   printf("***Check 13: List with 5 elements uiData 1, 4, 2, 3, 1 ****\n");

   putchar('\n');
   printf("***Test 14: Test InsertElementAdd uiPos is correct ********\n");
   printf("***         List has 5 elements ***************************\n");
   InsertElementAt(&psAnchorNode, &asNodes[1], 5);
   PrintList(psAnchorNode);
   printf("***Check 14: List with 6 elements uiData 1, 4, 2, 3, 1, 2 *\n");

   putchar('\n');
   printf("***Test 15: Delete previous filled list ********************\n");
   DeleteList(&psAnchorNode);
   PrintList(psAnchorNode);
   printf("***Check 15: List is empty - no elements *******************\n");

   putchar('\n');
   printf("***Test 16: Fill empty list with InsertElementFront ********\n");
   printf("***         InsertElementBack and InsertElementAt **********\n");
   InsertElementAt(&psAnchorNode, psNodeB,0);
   InsertElementFront(&psAnchorNode, &asNodes[1]);
   InsertElementBack(&psAnchorNode, &asNodes[0]);
   InsertElementAt(&psAnchorNode, &sNodeA, 3);
   InsertElementAt(&psAnchorNode, psNodeB, 0);
   InsertElementAt(&psAnchorNode, &asNodes[1], 3);
   PrintList(psAnchorNode);
   printf("***Check 17: List with 6 elements, uiData 4, 2, 4, 2, 1, 3**\n");

   putchar('\n');
   printf("***Test 18: Delete previous filled list ********************\n");
   DeleteList(&psAnchorNode);
   PrintList(psAnchorNode);
   printf("***Check 18: List is empty - no elements *******************\n");


   // End Testdriver for linked list


   if (psNodeB != NULL)
   {
      free(psNodeB);
      psNodeB = NULL;
   }

   // Check Heap: If leaks the CRT will print to output (Dump)
   _CrtDumpMemoryLeaks();

   return 0;
}

int InsertElementBack(ppsNode_t ppsAnchor, psNode_t psNewNodePassed)
{
   int iRet = -1;
   psNode_t psNewNode = NULL;
   psNode_t psEnd = NULL;

   //sanity check
   if (ppsAnchor != NULL && psNewNodePassed != NULL)
   {
      psNewNode = (psNode_t)malloc(sizeof(sNode_t));
      if (psNewNode != NULL)
      {
         psNewNode->uiData = psNewNodePassed->uiData;
         psNewNode->psNextNode = NULL;

         if (*ppsAnchor == NULL)
         {
            //List is empty
            *ppsAnchor = psNewNode;
         }
         else
         {
            //List is not empty
            psEnd = *ppsAnchor;
            while (psEnd->psNextNode != NULL)
            {
               psEnd = psEnd->psNextNode;
            }
            // psEnd is now at the End
            psEnd->psNextNode = psNewNode;
         }
         iRet = 0;
      }
   }
   return iRet;
}

int InsertElementFront(ppsNode_t ppsAnchor, psNode_t psNewNodePassed)
{
   int iRet = -1;
   psNode_t psNewNode;

   //sanity check
   if (ppsAnchor != NULL && psNewNodePassed != NULL)
   {
      psNewNode = (psNode_t)malloc(sizeof(sNode_t));
      if (psNewNode != NULL)
      {
         psNewNode->uiData = psNewNodePassed->uiData;
 
         if (*ppsAnchor == NULL)
         {
            //List is empty
            psNewNode->psNextNode = NULL;
          }
         else
         {
            psNewNode->psNextNode = *ppsAnchor;
            // List is not empty
         }
         *ppsAnchor = psNewNode;
         iRet = 0;
      }
   }
   return iRet;
}


int InsertElementAt(ppsNode_t ppsAnchor, psNode_t psNewNodePassed, unsigned int uiPos)
{
   int iRet = -1;
   unsigned int uiNumberElements = 0U;
   psNode_t psNewNode;
   psNode_t psNodeActual = NULL;
   psNode_t psNodeLast = NULL;
   unsigned int uiCurrentPos = 0U;

   if ((ppsAnchor != NULL) && (psNewNodePassed != NULL))
   {
      uiNumberElements = GetNumberElements(*ppsAnchor);

      if (uiPos <= uiNumberElements)
      {
         if (uiPos == 0U)
         {
            iRet = InsertElementFront(ppsAnchor, psNewNodePassed);
         }
         if ((uiPos == uiNumberElements) && (uiPos != 0U))
         {
            iRet = InsertElementBack(ppsAnchor, psNewNodePassed);
         }
         if ((uiPos > 0U) && (uiPos < uiNumberElements))
         {
            psNewNode = (psNode_t)malloc(sizeof(sNode_t));

            if (psNewNode != NULL)
            {
               psNewNode->uiData = psNewNodePassed->uiData;

               psNodeActual = *ppsAnchor;
               psNodeLast = psNodeActual;

               while (uiCurrentPos != uiPos)
               {
                  psNodeLast = psNodeActual;
                  psNodeActual = psNodeActual->psNextNode;
                  uiCurrentPos++;
               }
               psNodeLast->psNextNode = psNewNode;
               psNewNode->psNextNode = psNodeActual;
            }
         }
      }
   }
   return iRet;
}

int DeleteElementBack(ppsNode_t ppsAnchor)
{
   int iRet = -1;
   unsigned int uiNumberElements;
   psNode_t psNodeActual = NULL;
   psNode_t psNodeLast = NULL;

   //sanity check
   if (ppsAnchor != NULL)
   {
      uiNumberElements = GetNumberElements(*ppsAnchor);
      if (uiNumberElements == 1)
      {
         free(*ppsAnchor);
         *ppsAnchor = NULL;
      }
      else
      {
         psNodeActual = *ppsAnchor;
         psNodeLast = psNodeActual;

         while (psNodeActual->psNextNode != NULL)
         {
            psNodeLast = psNodeActual;
            psNodeActual = psNodeActual->psNextNode;
         }
         free(psNodeActual);
         psNodeLast->psNextNode = NULL;
      }
      iRet = 0;
   }
   return iRet;
}

int DeleteList(ppsNode_t ppsAnchor)
{
   int iRet = -1;

   if (ppsAnchor != NULL)
   {
      iRet = DeleteElementsRecursive(*ppsAnchor);
      *ppsAnchor = NULL;
   }

   return iRet;
}

int DeleteElementsRecursive(psNode_t psNodeDelete)
{
   int iRet = -1;

   if (psNodeDelete != NULL)
   {
      iRet = DeleteElementsRecursive(psNodeDelete->psNextNode);
      free(psNodeDelete);
   }
   else
   {
      iRet = 0;
   }

   return iRet;
}

void PrintList(psNode_t psAnchorNode)
{
   if (psAnchorNode != NULL)
   {
      printf("List is not empty, psAnchorNode is not NULL\n");
      PrintElements(psAnchorNode);
   }
   else
   {
      printf("List is empty, psAnchorNode is NULL\n");
   }
   printf("Number of Elements: %u\n", GetNumberElements(psAnchorNode));
}


void PrintElements(psNode_t psNode)
{
   //sanity check
   if (psNode != NULL)
   {
      printf("Node address: %08p uiData: %u psNextNode: %08p\n", psNode, psNode->uiData, psNode->psNextNode);
      PrintElements(psNode->psNextNode);
   }
}

unsigned int GetNumberElements(psNode_t psNode)
{
   unsigned int uiRet = 0U;
   //sanity check
   if (psNode != NULL)
   {
      uiRet = 1U;
      uiRet += GetNumberElements(psNode->psNextNode);
   }
   return uiRet;
}

int DeleteElementFront(ppsNode_t ppsAnchor)
{
    int iRet = -1;
    psNode_t psNodeFirst = NULL;

    //sanity check
    if (ppsAnchor != NULL && *ppsAnchor != NULL)
    {
        psNodeFirst = *ppsAnchor;

        *ppsAnchor = psNodeFirst->psNextNode;

        free(psNodeFirst);
        
        iRet = 0;
    }
    return iRet;
}

int DeleteElementAt(ppsNode_t ppsAnchor, unsigned int uiPos)
{
	
}