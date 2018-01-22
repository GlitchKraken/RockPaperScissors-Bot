// YOUR NAME: Sean Nolan
//
// CS 4318, spring 2018
// Agent Challenge 1: Rock, paper, scissors
//
// Rename this file and the function below.  For example, if your agent name
// is Jones, rename this rpsAgentSmith.cpp file to rpsAgentJones.cpp and the
// rpsAgentSmith function below to rpsAgentJones.  Complete your agent
// function and turn it in on Blackboard.  Feel free to create other
// agents--each in a separate .cpp file--for yours to compete against, but
// turn in only one.  Test your agent(s) with
//
//    nice bash rpsBuild.bash
//
// and then
//
//    nice ./rpsRunSim
//
// Each submitted agent will play each other in contests of some number of
// rounds each (at least 100) to determine the standings, which will be
// posted soon after the agents are due.

#include "rps.h"

// Rename and complete this agent function.
handsign rpsAgentPvpshank(const vector<handsign> focal, const vector<handsign> opponent)
{
   // Your function must end up returning rock, paper or scissors.
   // Number of choices made by you so far: focal.size()
   //    (You may assume that focal.size() and opponent.size() are equal.)
   // Last choice made by you: focal.back() (or focal.at(focal.size() - 1))
   // Second-to-last choice made by you: focal.at(focal.size() - 2)
   // Third-to-last choice made by you: focal.at(focal.size() - 3)
   //    etc.
   // Last choice made by your opponent: opponent.back() (or opponent.at(focal.size() - 1))
   // Second-to-last choice made by your opponent: opponent.at(focal.size() - 2)
   //    etc.

   // Replace this return statement with your agent code.

   //My agent always plays rock first
   if (opponent.size() <= 0)
	{
	   return rock;
	}
	//if my opponents agent plays scissors and my agent played rock in the last round, then my agent plays paper
	else if(opponent.back() == scissors && focal.back() == rock)
		{
			return paper;
		}
	//if my opponents agent plays rock and my agent played paper in the last round, then my agent plays scissors
	else if(opponent.back() == rock && focal.back() == paper)
		{
			return scissors;
		}
	//if my opponents agent plays paper and my agent played scissors in the last round, then my agent plays rock
	else if(opponent.back() == paper && focal.back() == scissors)
		{
			return rock;
		}
	//if my opponents agent plays rock and my agent played scissors in the last round, then my agent plays rock
	else if(focal.back() == scissors && opponent.back() == rock)
		{
			return rock;
		}
	//if my opponents agent plays paper and my agent played rock in the last round, then my agent plays paper
	else if(focal.back() == rock && opponent.back() == paper)
		{
			return paper;
		}
	//if my opponents agent plays scissors and my agent played paper in the last round, then my agent plays scissors
	else if(focal.back() == paper && opponent.back() == scissors)
		{
			return scissors;
		}
	//if my opponents agent plays the same hand sign as my agent played in the last round,
	//then my agent plays rock 2/3 or the time, paper 1/3 of the time, and scissors 1/3 of the time
	else if(opponent.back() == focal.back())
	{
		int r = randomInt(10);
		if (r < 6)
		{
			return rock;
		}
		if (r < 8)
		{
			return paper;
		}
		return scissors;
	}
	//if my opponent just plays rock for the past 5 rounds, then my agent plays paper
	else if(opponent.at(focal.size() - 5) == rock && opponent.at(focal.size() - 4) == rock && opponent.at(focal.size() - 3) == rock && opponent.at(focal.size() - 2) == rock && opponent.at(focal.size() - 1) == rock)
	{
		return paper;
	}
	//if my opponent just plays paper for the past 5 rounds, then my agent plays scissors
	else if(opponent.at(focal.size() - 5) == paper && opponent.at(focal.size() - 4) == paper && opponent.at(focal.size() - 3) == rock && opponent.at(focal.size() - 2) == paper && opponent.at(focal.size() - 1) == paper)
	{
		return scissors;
	}
	//if my opponent just plays scissors for the past 5 rounds, then my agent plays rock
	else if(opponent.at(focal.size() - 5) == scissors && opponent.at(focal.size() - 4) == scissors && opponent.at(focal.size() - 3) == scissors && opponent.at(focal.size() - 2) == scissors && opponent.at(focal.size() - 1) == scissors)
	{
		return rock;
	}
	//my agent plays rock if none of these happen
	else
	{
		return rock;
	}
}

/*

 - First, carefully comment your code above.
 - Here, describe your approach and why you expect it to do well against the
   other submitted agents.
 - Also make a note here if you talked about the assignment with anyone or gave
   or received any kind of help.

   I believe that my agent will do well because my agent changes what he plays every round.
   Also, my agent will not get beat if someone just plays one of them for every round. Another reason why
   I believe that my agent will do well is because it will be hard to pick up on a pattern with my plays.
   I did talk with Ryan Clibbens about this agent change. Ryan and I looked at different ways to win at rock,
   paper, scissors and give each other advice on what we thought was a good plan. Also, I tested my agent against his agent.
   I also watched this YouTube video https://www.youtube.com/watch?v=AnRYS02tvRA for part of my plan at rock, paper, scissors.

*/
