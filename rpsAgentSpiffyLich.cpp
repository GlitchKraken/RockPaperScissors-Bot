// Chad Fry (Agent SpiffyLich):
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
#include <iostream>
using namespace std;

// Rename and complete this agent function.
handsign rpsAgentSpiffyLich(const vector<handsign> focal, const vector<handsign> opponent)
{
        /*
           Your function must end up returning rock, paper or scissors.
           Number of choices made by you so far: focal.size()
           (You may assume that focal.size() and opponent.size() are equal.)
           Last choice made by you: focal.back() (or focal.at(focal.size() - 1))
           Second-to-last choice made by you: focal.at(focal.size() - 2)
           Third-to-last choice made by you: focal.at(focal.size() - 3)
           etc.
           Last choice made by your opponent: opponent.back() (or opponent.at(focal.size() - 1))
           Second-to-last choice made by your opponent: opponent.at(focal.size() - 2)
           etc.

           Replace this return statement with your agent code.

           so: focal is a vector of my choices so far...
           and opponent is a vector of my opponents choices so far.

           doesn't seem to hard. I get the feeling im going to somehow butcher this before monday.

         */


        // ----- Begin My Code ----- //


        //first two moves- playing risky against the class' most likely choice,
        // and setting up for a rock-play myself.
        if(opponent.size() < 2)
        {
                return paper;
        }

        //we have reached the third move, our opponent likely has picked scissors, thinking we
        //are an "All-Paper" bot.
        if(opponent.size() == 2)
        {
                return rock;
        }

        //we have now past the third turn, and need to start analyzing the enemies choices.
        if(opponent.size() > 2)
        {

                //number of times the opponent has picked each handsign
                double rockCount =0;
                double paperCount =0;
                double scissorsCount =0;


                //we have at least 4 things to look at, so count up everything the opponent
                //has done so far.
                for(uint i =0; i < opponent.size()-1; i++)
                {
                        if(opponent[i] == rock)
                        {
                                rockCount++;
                        }
                        if(opponent[i] == paper)
                        {
                                paperCount++;
                        }
                        if(opponent[i] == scissors)
                        {
                                scissorsCount++;
                        }
                }




                //obtain the probability of each handsign occuring.
                double rockPercent = (rockCount / opponent.size())*100;
                double paperPercent = (paperCount / opponent.size())*100;
                double scissorsPercent = (scissorsCount / opponent.size())*100;

                //return a response based on how likely their next move is.
                if(rockPercent > paperPercent && rockPercent > scissorsPercent)
                {
                        //rock was played the most...
                        if(rockPercent > 45)
                        {
                            return paper;
                        }

                }
                if(paperPercent > rockPercent && paperPercent > scissorsPercent)
                {
                        //paper was played the most.
                        if(paperPercent > 60)
                        {
                            return scissors;
                        }
                }
                if(scissorsPercent > rockPercent && scissorsPercent > paperPercent)
                {
                        //scissors was played the most, we can comfortably play rock...
                        if(scissorsPercent > 30)
                        {
                            return rock;
                        }

                }



        }

        return rock;
}


//The logic here is as follows:

//Most players are being persuaded, statisically, to play rock as often as possible.
// for our first two moves, we have practically no data to process.
//Therefore, we will both play against that, and attempt to bait
//the enemy AI into thinking we are an "all paper" bot,
//and then proceed to play rock for our third move. *After this*,
//we should have a decent enough amount of data to analyze to make intelligent decisions
//against the enemy bot.

//Therefore, after move 3, our bot will scan every decision the enemy has made
//thus far, and determine what the enemy is most likely to play next.
//then, it will run a simple statistical analysis to determine whether the
//counter to that move is worth playing.
