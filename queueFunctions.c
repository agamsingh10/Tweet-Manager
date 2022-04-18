#include"headerA4.h"

//This function checks if the queue is empty
int isEmpty (tweet * head)
{

  if(head == NULL)
  {
     return 1;
  }

  else
  {
     return 0;
  }

}

/*All of the tweets that are currently in memory (ie. in the queue) will be displayed
to the user.*/

void printQueue (tweet * head)
{
		printf("\n");
    if(head == NULL)                               //if the queue is empty
    {
        printf("No tweets present\n" );
    }

    else
		{
       while(head != NULL )
		   {
          printf("%i: Created by %s: %s\n", head->id, head->user, head->text);
          head = head->next;
       }
    }

}

// This function adds the tweet(node) to the present number of tweets from the end
void enqueue (tweet ** head, tweet ** tail, tweet * node)
{

	   if((*head)==NULL)  // in case the list is empty, add first node
     {
	        (*head) = (*tail) = node;    //both tail and head point to first node
     }

	   else
     {
          (*tail)->next = node;
          *tail = node;
          node->next = NULL;      // adding the node after tail
	   }
}

// This function deletes the tweet(node) from the present number of tweets from the beginning of the list
void dequeue (tweet ** head, tweet ** tail)
{

  if((*head) == NULL)  // if queue is empty
  {
    printf("Queue is empty\n" );

  }

  else if((*head) == (*tail))   //if queue has one node
  {
     tweet * p = *head;
     *head = *tail = NULL;
     free(p);

  }

  else
  {
     tweet * p = *head;
     *head = (*head)->next;
     free(p);

  }

}

