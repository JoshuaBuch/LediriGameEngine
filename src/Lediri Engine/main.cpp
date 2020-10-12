#include "Lediri.h"

int CALLBACK WinMain(HINSTANCE , HINSTANCE ,  LPSTR , int)                  
{          
	// create Lediri
	//Lediri *pLediri = new Lediri();    
	//assert(pLediri);

	// start the game
	Lediri::pubRun();

	Lediri::TerminateLediri();

	return 0;                                       
}

