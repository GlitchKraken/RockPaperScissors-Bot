// Andrew Russell
// CS 4318 Agent 1
// 17 Jan 2018
// Agent Challenge 1: Rock, paper, scissors
//
//    nice bash rpsBuild.bash
//
// and then
//
//    nice ./rpsRunSim

#include "rps.h"
#include <cstdlib>

handsign rpsAgentSamFisher(const vector<handsign> focal, const vector<handsign> opponent)
{
   //Maybe use A matrix?

    //0 is rock, 1 is paper, 2 is scissors
	int r = randomInt(6);
	string temp;
	int rWeight = 3, pWeight = 2, sWeight = 1; // weight of points
	if(r > -1 && r <= 2) //(3x prob)
	    //r = 0; // rock
		temp = "rock";
	else if (r > 2 && r <=4) //(2x prob)
	    //r = 1 //paper
		temp = "paper";
	else if (r == 5) //(1x prob)
	    //r = 2; //scissors
		temp = "scissors";
	//int o = 0;

	if(focal.size() <= 5)
	{
		if(temp == "rock")
			return rock;
		else if( temp == "paper")
			return paper;
		else if (temp == "scissors")
			return scissors;
	}

	double rO = 0, pO = 0, sO = 0, count = 1; // initial counts
	for(uint i = 0; i < (opponent.size()-1); i++)
	{
		if(opponent.at(i) == rock)
		   rO++;
		else if(opponent.at(i) == paper)
		   pO++;
		else if(opponent.at(i) == scissors)
		   sO++;

		count++;
	}

	while(opponent.at(focal.size() - count) != opponent.front()) //counts number of each opponent play
	{
		if(opponent.at(focal.size() - count) == rock)
		   rO++;
		else if(opponent.at(focal.size() - count) == paper)
		   pO++;
		else if(opponent.at(focal.size() - count) == scissors)
		   sO++;

		count++;
	}

	double probR = 0, probP = 0, probS = 0; // initial probs

	if(count > 1)
	{
		probR = rO / (count-1) * 100; // Probability of them playing Rock
		probP = pO / (count-1) * 100; // Probability of them playing Paper
		probS = sO / (count-1) * 100; // Probability of them playing Scissors
	}


	//begin problem section
	if(probR != 0 && probR >= 60) //if they play rock too much
		return paper;
	if(probP != 0 && probP >= 60) //if they play paper too much
		return scissors;
	if(probS != 0 && probS >= 60) //if they play scissors too much
		return rock;
	//end problem section

	int markR = 33, markP = 66, markS = 99; // probability of what I should play based on idea of number line

	if(probR > probP && probR > probS) // Rock was highest
	{
		markR -= (probR * markR); // Lower chance that I play rock
		markS -= (probS * markS); // lower chance that I play scissors
	}else if (probP > probR && probP > probS) // Paper was highest
	{
		markP -= ((probP * markP) + (probR * markR)); // Lower chance that I play paper
		markR -= (probR * markR); // Lower chance that I play rock
	}else if (probS > probR && probS > probP) // Scissors was highest
	{
		markS -= ((probS * markS) + (probP * markP)); // Lower chance that I play scissors
		markP -= (probP * markP); // Lower chance that I play paper
	}


	markR += rWeight;
	markS += sWeight;
	markP += pWeight;

	int ret = randomInt(markS); //Finally gets a random number within the bounds of mark used previously
	if (ret < markR)
		return rock;
	else if (ret < markP)
		return paper;
	else
		return scissors;

}

/*

 - First, carefully comment your code above.
 - Here, describe your approach and why you expect it to do well against the
   other submitted agents.
   My initial approach will be as follows. Calculate importance of rolling rock (3x), paper (2x), and scissors(1x). Then include
   probability of opponent running one of the aforementioned and base the roll of the combination between the two. The first part
   initializes the importance that rock has over the other two, followed by paper, and lastly scissors. The second part will calculate
   in the probability of the other agent picking (not totally random) as most shouldn't include completely random choices. the marks
   calculate the probability with importance of winning off of each one.
   selection in their process.
 - Also make a note here if you talked about the assignment with anyone or gave
   or received any kind of help.

*/
