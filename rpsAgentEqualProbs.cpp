// CS 4318, spring 2018
// Agent Challenge 1: Rock, paper, scissors
//
// Here's an example agent function.  You can do better than this.

#include "rps.h"

handsign rpsAgentEqualProbs(const vector<handsign> focal, const vector<handsign> opponent)
{
   // Play randomly, choosing each sign with 1/3 probability.
   //r will be 0, 1, or 2, in this case.
   int r = randomInt(3);
   if (r < 1)
   {
      return rock;
   }
   if (r < 2)
   {
      return paper;
   }
   return scissors;
}
