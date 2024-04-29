/*
Description: 	The program is a Game of Thrones themed game. The goal is to improve the economic growth of the Six Kingdoms by 
				trading with other kingdoms in Westeros and other free cities in Essos with just 2,000 Golden Dragons.

Programmed by: 	Samantha Nicole L. Caasi S16A
Last modified: 	February 6, 2022
[Acknowledgements: 	https://www.geeksforgeeks.org/getch-function-in-c-with-examples/#:~:text=getch()%20is%20a%20nonstandard,single%20character%20from%20the%20keyboard.
					https://mathbits.com/MathBits/CompSci/LibraryFunc/rand.htm]
*/

#include <stdio.h>			
#include <stdlib.h>				/* where the srand, random, and system are defined */ 
#include <time.h> 				/* where the time function is defined */
#include <conio.h> 				/* where the getch is defined */

#include "caasiMPheader.h"		/* where the functions of this main C file are defined */  

int main() 
{
	int nIntChoice;																// Integer choice
	int nIronBankChoice;														// Choice in Iron Bank 
	char cCharChoice = '!';														// Character choice  
	
	int nSB = 0, nTR = 0,  nIL = 0, nIP = 0, 									// Stores the quantity of the each of the items owned
		nPAW = 0, nME = 0, nQT = 0, nVS = 0;  
	// SB is Sweet Beet // TR is Timber // IL is Intricate Lace // IP is Intoxicating Perfume
	// PAW is Pale Amber Wine // ME is Myrish Eye // QT is Qohorik Tapestry // VS is Valyrian Steel

	int nSBPrice, nTRPrice, nILPrice, nIPPrice, 								// The price of each item
		nPAWPrice, nMEPrice, nQTPrice, nVSPrice; 													

	int nMerchantRand;															// Stores the value generated for the merchant with 10% chance of appearance 
																				
	int nDays = 15, nGD = 2000, nDebt = 0, nSavings = 0, nCap = 0, nMaxCap = 50;
	// The value of Days, Golden Dragons, Debt, Savings, Capacity, and Max Capacity of the user

	srand(time(NULL));															// initialize a random sequence based on time 

	displayIntro();

	while(cCharChoice == '!' || cCharChoice == 'W')								// Loops the wheelhouse
	{
		
		while(cCharChoice != 'Q')												// Loops the game until user wants to quit in trading menu
		{
			cCharChoice = '!';													// Resets cCharChoice to re-enter the loop		

		
			printFirstMenu();													// Displays the lists of Trading Partners
			scanf("%d", &nIntChoice);											// Asks for which Trading Partner
	
			while(nIntChoice < 1 || nIntChoice == 7 || nIntChoice == 8 || nIntChoice > 9) // Loop to continuously asks the user for a valid input
			{ 
				printf("\n\t\t\t\t\tPlease enter a valid choice.");				// Prints when user enters an invalid choice
				printf("\n\t\t\t\t\tPress any key to continue...");
				getch();														// Pauses output until a key is pressed
				system("cls");
				printFirstMenu();												// Displays the lists of Trading Partners
				scanf("%d", &nIntChoice);										// Asks for which Trading Partner 
			}
				
												
					nMerchantRand = getRandom(1,10);							// Generates the number for the 10% appearance of the merchant
					
					// Generates normal price for the respective wares and goods //
					nSBPrice = getRandom(SB_NP_MIN, SB_NP_MAX);			
					nTRPrice = getRandom(TR_NP_MIN, TR_NP_MAX);			  
					nILPrice = getRandom(IL_NP_MIN, IL_NP_MAX);			 
					nIPPrice = getRandom(IP_NP_MIN, IP_NP_MAX);
					nPAWPrice = getRandom(PAW_NP_MIN, PAW_NP_MAX);
					nMEPrice = getRandom(ME_NP_MIN, ME_NP_MAX);
					nQTPrice = getRandom(QT_NP_MIN, QT_NP_MAX);
					nVSPrice = getRandom(VS_NP_MIN, VS_NP_MAX);			
				
							
					switch(nIntChoice)
					{	// Updates the normal price to special price depending on the user's trading partner choice //
						case 1: nTRPrice = getRandom(TR_SP_MIN, TR_SP_MAX); break;		
						case 2: nIPPrice = getRandom(IP_SP_MIN, IP_SP_MAX); break;
						case 3: nILPrice = getRandom(IL_SP_MIN, IL_SP_MAX);
								nMEPrice = getRandom(ME_SP_MIN, ME_SP_MAX);
								break;
						case 4: nPAWPrice = getRandom(PAW_SP_MIN, PAW_SP_MAX); break;
						case 5: nQTPrice = getRandom(QT_SP_MIN, QT_SP_MAX);
								nVSPrice = getRandom(VS_SP_MIN, VS_SP_MAX);
								break;
						case 6: nSBPrice = getRandom(SB_SP_MIN, SB_SP_MAX); break;

						
						case 9:	displayFinalInventory	(nDays, nGD, nDebt, nSavings, nCap, nMaxCap, 	// Calls the displayFinalInventory function
														nSB, nTR, nIL, nIP, 
														nPAW, nME, nQT, nVS);
									
								cCharChoice = 'Q';														// Sets cCharChoice to Q to exit the loop
								break;
					}
				

				while(cCharChoice != 'Q' && cCharChoice != 'W')							// Loops until user wants to use the wheelhouse or quit
				{	
					nIronBankChoice = 0;												// Resets Iron Bank choice so it loops again after using [5] Return

					displayTradingMenu(nIntChoice);										// Calls the displayTradingMenuA function
					displayPrices(nSBPrice, nTRPrice, nILPrice, nIPPrice, 				// Calls the displayPrices function
									nPAWPrice, nMEPrice, nQTPrice, nVSPrice, 
									&nSB, &nTR, &nIL, &nIP, 
									&nPAW, &nME, &nQT, &nVS);

					displayInventory(nDays, nGD, nDebt, nSavings, 						// Calls the displayInventory function
										nCap, nMaxCap, nMerchantRand);
						
					scanf(" %c", &cCharChoice);											// Asks for a character input
					
					switch(cCharChoice)
					{
						case 'B':
						case 'b': 	choiceBuy(&nGD, &nCap, &nMaxCap, 					// Calls the choiceBuy function
									nSBPrice, nTRPrice, nILPrice, nIPPrice, 
									nPAWPrice, nMEPrice, nQTPrice, nVSPrice,
									&nSB, &nTR, &nIL, &nIP, 
									&nPAW, &nME, &nQT, &nVS);
									break;
						case 'S':
						case 's':	choiceSell(&nGD, &nCap, &nMaxCap, 					// Calls the choiceSell function
									nSBPrice, nTRPrice, nILPrice, nIPPrice, 
									nPAWPrice, nMEPrice, nQTPrice, nVSPrice,
									&nSB, &nTR, &nIL, &nIP, 
									&nPAW, &nME, &nQT, &nVS);
									break;
						case 'I':
						case 'i':	while(nIronBankChoice != 5)												// Loops until the user has not used [5] Return
									{
										displayIronBank(nGD, nSavings, nDebt);								// Calls the displayIronBank function
										scanf("%d", &nIronBankChoice);

										choiceIronBank(nIronBankChoice, &nGD, &nDebt, &nSavings);			// Calls the choiceIronBank function
									}
									break;
									
						case 'W':
						case 'w':	cCharChoice = 'W';														
									if(nDays <= 1) {														// Checks if the remaining days is less than or equal to 1
										nDays -= 1;															// Subracts one day from the days remaining
										printf("\n\t\t\t15 days are over.\n");									// Prints when there are no days left
										displayFinalInventory	(nDays, nGD, nDebt, nSavings, 				// Calls the displayFinalInventory function
																nCap, nMaxCap,  
																nSB, nTR, nIL, nIP, 
																nPAW, nME, nQT, nVS);
										cCharChoice = 'Q';													// Sets cCharChoice to Q to exit the loop
									}

									else {																	// Executes when the remaining days are more than 1
										nDays -= 1;															// Subracts one day from the days remaining
										nSavings += nSavings * 0.10;										// Adds 10% interest to Savings daily
										nDebt += nDebt * 0.05;												// Adds 5% interest to Debt daily 
									} 
									break;		
													
						case 'M':	
						case 'm':	displayMerchant(&nGD, &nMaxCap);										// Calls displayMerchant
									break;
						case 'Q':
						case 'q':	displayFinalInventory	(nDays, nGD, nDebt, nSavings, nCap, nMaxCap, 	// Calls the displayFinalInventory function
															nSB, nTR, nIL, nIP, 
															nPAW, nME, nQT, nVS);
									cCharChoice = 'Q';
									break;

						printf("\n\t\t\t\t\tPlease enter a valid choice.");									// Prints when user enters an invalid choice
						printf("\n\t\t\t\t\tPress any key to continue...");
						getch();
						break;
					}
				}		
		}
	}	
	return 0;
}
	



	

	
	








