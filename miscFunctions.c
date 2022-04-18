#include"headerA4.h"

void reverse (tweet ** head, tweet ** tail)
{
  if(isEmpty(*head))   //if no nodes are present
  {
      printf("Empty queue\n");
      return;
  }

  if(*head == *tail)    //if only one node present
  {
       printf("Only one node in queue\n");
       return;
  }

  tweet *nextNode = NULL;
  tweet *previousNode = NULL;
  tweet *presentNode = *head;

  *head = *tail;

	while (presentNode != NULL)
  {
		  nextNode = presentNode->next;   //to move nextNode one ahead of presentNode
		  presentNode->next = previousNode;
		  previousNode = presentNode;    //to store the presentNodeent address of node to put it in presentNode->next later
		  presentNode = nextNode;   //Moving presentNode to the next node in the queue
	}


}

//I have used Bubble sort for sorting

void sortID (tweet ** head, tweet ** tail)
{
  if(isEmpty(*head))
  {
      printf("Queue is empty\n");
      return;
  }

  int numSwap=-1;    //to enter the loop
  while (numSwap!=0)
  {

    numSwap=0;
    tweet *presentNode=*head;
    tweet *previousNode=*head;

    //We compare seperately for the first time.
    if(presentNode->next == NULL) // only one node is present in the queue
    {
         printf("Just one node present, no sorting required.\n");
         return;
    }

    if((presentNode->next)->id < presentNode->id)  //comparing the node ids
    {
         //this is the process of swaping the 2 nodes.
         *head = presentNode->next;
         presentNode->next = (*head)->next;
         (*head)->next = presentNode;
         previousNode = *head;
         numSwap++;
    }
    else
    {
         presentNode=presentNode->next;
    }

    // all the other comparison to be done using this loop
    while(presentNode->next!=NULL)
    {
        if((presentNode->next)->id < presentNode->id)
        {
             previousNode->next = presentNode->next;
             presentNode->next = (presentNode->next)->next;
             (previousNode->next)->next = presentNode;
             previousNode = previousNode->next;
             numSwap++;
         }
         else
         {
              previousNode = presentNode;
              presentNode = presentNode->next;
         }
    }

  }

  // set the tail at the last position as we have made changes in the queue.
  while((*tail)->next!=NULL)
  {
     *tail = (*tail)->next;
  }
}


void sortUsername (tweet ** head, tweet ** tail)
{
  if(isEmpty(*head))
  {
      printf("Queue is empty\n");
      return;
  }

  int numSwap=-1;   //to enter the loop
  while(numSwap!=0)
  {

    numSwap=0;
    tweet *presentNode=*head;
    tweet *previousNode=*head;

    //We compare seperately for the first time.
    if(presentNode->next==NULL)       // only one node is present in the queue
    {
        printf("Just one node present, no sorting required.\n");
        return;
    }


    if(strcmp(presentNode->user,(presentNode->next)->user) > 0) //compare the usernames
    {
         *head = presentNode->next;
         presentNode->next = (*head)->next;
         (*head)->next = presentNode;
         previousNode = *head;
         numSwap++;
    }
    else
    {
        presentNode = presentNode->next;
    }

    // all the other comparison to be done using this loop
    while(presentNode->next!=NULL)
    {
        if(strcmp(presentNode->user, (presentNode->next)->user) > 0)
        {
             previousNode->next = presentNode->next;
             presentNode->next = (presentNode->next)->next;
             (previousNode->next)->next = presentNode;
             previousNode = previousNode->next;
             numSwap++;
         }
         else
         {
              previousNode = presentNode;
              presentNode = presentNode->next;
         }
    }

  }

  // set the tail at the last position as we have made changes in the queue.
  while((*tail)->next != NULL)
  {
      *tail = (*tail)->next;
  }

}

