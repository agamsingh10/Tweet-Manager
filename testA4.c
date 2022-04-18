#include"headerA4.h"

int main()
{
  srand(time(0));
  tweet* head= NULL;
  tweet* tail= NULL;
  tweet* node = NULL;
  printf("Beginning A4 program testing...\n");
  printf("Creating initial queue list...\n");

  //Creating 5 nodes of the queue using createTweet
  int i=1;
  while(i<=5)
  {
    node = createTweet(head);
    if(node==NULL)
    {
       printf("Tweet creation failed\n");
       node = createTweet(head);
       enqueue(&head, &tail, node);

    }
    else
    {
       enqueue(&head, &tail, node);
    }

    i++;
  }

  //Testing printQueue function first time
  printf("\nVerifying queue contents via printQueue");
  printQueue(head);

  //User needs to press enter to move ahead
  getchar();

  //Testing enqueue function 3 times
  //Also Testing printQueue function 3 more times
  //I have used createTweet function to test enqueue function

  printf("\nTesting [Enqueue] function\n" );
  int j=1;

  while(j<=3)
  {
      printf("\n\n");
      node= createTweet(head);
      if(node==NULL)
      {
          printf("Tweet creation failed\n");
          node = createTweet(head);
          printf("Iteration [%d]: [Node]: %d: Created by %s: %s\n\n", j, node->id, node->user, node->text );
          enqueue(&head, &tail, node);
      }
      else
      {
          printf("Iteration [%d]: [Node]: %d: Created by %s: %s\n\n", j, node->id, node->user, node->text );
          enqueue(&head, &tail, node);
      }


      printf("After enqueue, queue looks like:" );
      printQueue(head);

      //User needs to press enter to move ahead
      getchar();

      j++;

  }

  //User needs to press enter to move ahead
  getchar();

  //Testing dequeue 3 times
  //Also Testing printQueue function 3 more times
  printf("Testing [Dequeue] function\n" );
  int k=1;
  while(k<=3)
  {
      dequeue(&head, &tail);

      printf("Iteration [%d]\nAfter dequeue, queue looks like:",k );
      printQueue(head);
      printf("\n");

    //User needs to press enter to move ahead
      getchar();

      k++;
  }

  //Testing isEmpty function for the first time
  printf("Testing [isEmpty] function\n");
  printf("Testing with list, expecting !isEmpty\n");

  if(!isEmpty(head))
  {
      printf("SUCCESS: list is not empty\n");
  }

  else
  {
      printf("FAILURE: list should not be empty\n" );
  }

  //Again Testing printQueue function
  printf("Using printQueue to verify queue contents");
  printQueue(head);

  //User needs to press enter to move ahead
  getchar();

  //Testing isEmpty function for the second time
  dequeue(&head, &tail);
  dequeue(&head, &tail);

  printf("Testing with list after 2 dequeues, expecting !isEmpty\n");

  if(!isEmpty(head))
  {
      printf("SUCCESS: list is not empty\n");
  }

  else
  {
      printf("FAILURE: list should not be empty\n" );
  }

  //Again Testing printQueue function
  printf("Using printQueue to verify queue contents");
  printQueue(head);


  //User needs to press enter to move ahead
  getchar();

  //Testing isEmpty function for the third time
  tweet *emptyQueueHead=NULL;  //declared and intialized an empty tweet to check if it gives correct output when list is actually empty
  printf("Testing with empty queue, expecting isEmpty\n");

  if(isEmpty(emptyQueueHead))
  {
      printf("SUCCESS: Empty list is declared as empty\n");
  }

  else
  {
      printf("FAILURE: list should have been empty\n" );
  }

  //Again Testing printQueue function
  printf("Using printQueue to verify queue contents"); //it does not print empty list but the list which is already there
  printQueue(head);

  //User needs to press enter to move ahead
  getchar();

  //Testing printQueue but it has already been tested a number of times
  printf("Testing [printQueue] function\n");
  printf("printQueue was used through the verification process already...\n\n\n" );

  //User needs to press enter to move ahead
  getchar();

  //Testing sortID function
  printf("Testing [sortID] function\n" );
  sortID(&head, &tail);

  //Again Testing printQueue function
  printQueue(head);

  //User needs to press enter to move ahead
  getchar();

  //Testing sortUsername function
  printf("Testing [sortUsername] function" );
  sortUsername(&head, &tail);

  //Again Testing printQueue function
  printQueue(head);

  //User needs to press enter to move ahead
  getchar();


  //Testing reverse function
  printf("Testing [reverse] function" );
  reverse(&head, &tail);

  //Again Testing printQueue function
  printQueue(head);

  //User needs to press enter to move ahead
  getchar();

  printf("Completed program testing\n");

  tweet * freeTheNode = NULL;
  while (head != NULL)
  {
		  freeTheNode = head;
		  head = head->next;
		  free(freeTheNode);
	}

  return 0;
}

