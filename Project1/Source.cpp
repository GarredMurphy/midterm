#include <iostream>
using namespace std;


static class EmotionalStateMachine  //i am using a finite state machine
{
private:
public:
	static Happy isHappy;
	static Hungry isHungry;
	static Tired isTired;


	virtual ~EmotionalStateMachine() {}
	virtual void eventHandler(sim& mysim, Event event) {}
	virtual void SayYourFeeling()   // i was going to add a virutal function that would show what the current emotion is but i ran out of time trying to fix the unfixable error.
	{

	}
};

class Happy : EmotionalStateMachine
{
	virtual void eventHandler(sim& mysim, Event event)
	{
		if (event == RUNNING)
		{
			mysim.setCurrentfeeling(&EmotionalStateMachine::isTired);  // i tried everything but i could not get this to work no matter what i did.  This is what the book on design patterns said to do but it doesn't work.
		}
		if (event == FASTING)
		{
			mysim.setCurrentfeeling(&EmotionalStateMachine::isHungry);
		}
	}



};

class Hungry : EmotionalStateMachine
{
	virtual void eventHandler(sim& mysim, Event event)
	{
		if (event == EATING)
		{
			mysim.setCurrentfeeling(&EmotionalStateMachine::isHappy);
		}
	}

};

class Tired : EmotionalStateMachine
{
	virtual void eventHandler(sim& mysim, Event event)
	{
		if (event == RESTING)
		{
			mysim.setCurrentfeeling(&EmotionalStateMachine::isHappy);
		}
	}

};


class sim
{
	
private:
	EmotionalStateMachine *currentFeeling;

public:

	sim()
	{
		currentFeeling = &EmotionalStateMachine::isHappy;
	}

	void setCurrentfeeling(EmotionalStateMachine *newfeeling)
	{
		currentFeeling = newfeeling;
	}

	void eventhandler(Event theevent)
	{
		currentFeeling->eventHandler(*this, theevent);
	}

	void SayYourFeeling()   // i was going to add a virutal function that would show what the current emotion is but i ran out of time trying to fix the unfixable error.
	{

	}
};


enum Event
{
	RUNNING,
	EATING,
	RESTING,
	FASTING
};


void main()
{
	sim aTestsim;

	aTestsim.SayYourFeeling();
	aTestsim.eventhandler(RUNNING);
	aTestsim.SayYourFeeling();
}