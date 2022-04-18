#include"headerA4.h"

/*The user has the option to create a new tweet and fill in some of the parameters for the
struct manually (namely, the username and users tweet). The user id is computer generated*/

tweet * createTweet(tweet * tweetList)
{
    int i, sum=0,len=0,len1=0, idCheck=0;
    tweet *temp=tweetList;
    tweet *temp2= tweetList;

    temp2= malloc(sizeof(tweet));

    printf("Enter a username: ");
    scanf("%s",temp2->user);
    getchar();

    len= strlen(temp2->user);

    if(len>51)                        //checking if username length exceeds its limit
    {
        printf("Length of username exceeded\n");
        return NULL;
    }

    if(len==0)                      //checking if username is non-zero length
    {
        printf("Length of username should be non-zero\n");
        return NULL;
    }

    printf("Enter the users tweet: ");
    scanf("%[^\n]",temp2->text);
    len1=strlen(temp2->text);

    if(len1>141)                  //checking if tweet length exceeds its limit
    {
        printf("Length of tweet exceeded\n");
        return NULL;
    }

    if(len1==0)                    //checking if tweet is non-zero length
    {
        printf("Length of tweet should be non-zero\n");
        return NULL;
    }


    for( i=0; i<len; i++)           //calculating user id
    {
        sum =  sum + temp2->user[i];
    }

    idCheck = sum + len1;

    // if user id is not unique, we repeatedly add random numbers betwwen 1 and 999

        while(temp!=NULL)
        {
            if(idCheck == temp->id)
            {
                 idCheck= idCheck + (1+(rand()%999));
                 temp = tweetList;


            }
            else
            {
                 temp=temp->next;
            }

        }

    temp2->id= idCheck;
    printf("Your computer-generated userid is: %d\n",temp2->id);

    temp2->next=NULL;
    return temp2;



}

