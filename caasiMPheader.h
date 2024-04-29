#include <stdio.h>

/* These constants are the minimum and maximum prices, normal and special, of each wares and goods.
	 ITEM_ NP for Normal / SP for Special Price_ MIN OR MAX
*/

#define SB_NP_MIN 180							// SB stands for Sweet Beet // Volantis' special item
#define SB_NP_MAX 200							
#define SB_SP_MIN 100
#define SB_SP_MAX 150

#define TR_NP_MIN 280							// TR stands for Timber // Winterfell's special item
#define TR_NP_MAX 300							
#define TR_SP_MIN 200
#define TR_SP_MAX 250

#define IL_NP_MIN 380							// IL stands for Intricate Lace // Myr's special item
#define IL_NP_MAX 400							
#define IL_SP_MIN 300
#define IL_SP_MAX 350

#define IP_NP_MIN 480							// IP stands for Intoxicating Perfume // Lys' special item
#define IP_NP_MAX 500							
#define IP_SP_MIN 400
#define IP_SP_MAX 450

#define PAW_NP_MIN 580							// PAW stands for Pale Amber Wine // Pentos' special item
#define PAW_NP_MAX 600							
#define PAW_SP_MIN 500
#define PAW_SP_MAX 550

#define ME_NP_MIN 680							// ME stands for Myrish Eye // Myr's special item
#define ME_NP_MAX 700							
#define ME_SP_MIN 600
#define ME_SP_MAX 650

#define QT_NP_MIN 780							// QT stands for Qohorik Tapestry // Qohor's special item
#define QT_NP_MAX 800							
#define QT_SP_MIN 700
#define QT_SP_MAX 750

#define VS_NP_MIN 880							// VS stands for Valyrian Steel // Qohor's special item
#define VS_NP_MAX 900							
#define VS_SP_MIN 800
#define VS_SP_MAX 850

void displayIntro() {
	system("cls");																				// Clears screen
	printf("\n\tMy Lord, King Bran of House Stark wants you to trade with other kingdoms in Westeros\n"); 
	printf("\tand other cities in Essos in order to improve the economic growth of the Six Kingdoms.\n");
	printf("\tThe Royal Treasury currently has 2,000 Golden Dragons only and you only have 15 days to \n\tcomplete the task.\n");
	printf("\n\tMay your travels be always safe, my Lord.\n");
	printf("\n\tPress any key to start the journey...");
	getch();																					// Pauses output until a key is pressed
	system("cls");																				// Clears screen
}

/* 	This function is the First Menu. It displays the list of Trading Partners. */
void printFirstMenu () {
	printf("\n\t\t\t\t\t+======= TRADING PARTNERS =======+\n");
	printf("\t\t\t\t\t|\t\t\t\t |\n");
	printf("\t\t\t\t\t|\t[1] Winterfell \t\t |\n");
	printf("\t\t\t\t\t|\t[2] Lys \t\t |\n");
	printf("\t\t\t\t\t|\t[3] Myr \t\t |\n");
	printf("\t\t\t\t\t|\t[4] Pentos \t\t |\n");
	printf("\t\t\t\t\t|\t[5] Qohor \t\t |\n");
	printf("\t\t\t\t\t|\t[6] Volantis \t\t |\n");
	printf("\t\t\t\t\t|\t\t\t\t |");
	printf("\n\t\t\t\t\t|\t[9] Quit\t\t |\n");	
	printf("\t\t\t\t\t|\t\t\t\t |\n");
	printf("\t\t\t\t\t+================================+");
	printf("\n\n\t\t\t\t\tChoice: ");
}

/* 	This function generates a random number given a range of values.

	Precondition: nMin and nMax must be positive integers.

	@param nMin is the lower bound of the range
	@param nMax is the upper bound of the range

	@return nRandom is the random number generated
*/
int getRandom(int nMin, int nMax) {
	int nRandom;

	nRandom = nMin + rand() % (nMax + 1 - nMin);
	return nRandom;
}

/* 	This function displays the header of the trading screen respective to the trading partner selected.

	Precondition: nIntChoice must be a positive integer.

	@param nIntChoice is the user's Trading Partner choice in the First Menu
*/
void displayTradingMenu(int nIntChoice) {
	printf("\n\t+================================================================================================+\n");

	switch(nIntChoice)	// Checks for the user's trading partner choice and prints its respective header.
	{	// 
		case 1: printf("\t| \t\t\t\t\t   WINTERFELL \t\t\t\t\t\t |"); break;
		case 2: printf("\t| \t\t\t\t\t\tLYS \t\t\t\t\t\t |"); break;
		case 3: printf("\t| \t\t\t\t\t\tMYR \t\t\t\t\t\t |"); break;
		case 4: printf("\t| \t\t\t\t\t    PENTOS \t\t\t\t\t\t |"); break;
		case 5: printf("\t| \t\t\t\t\t\tQOHOR \t\t\t\t\t\t |"); break;
		case 6: printf("\t| \t\t\t\t\t  VOLANTIS \t\t\t\t\t\t|"); break;		
	}
}

/* 	This function displays the list of Wares and Goods, their respective item numbers and
	Selling/Buying prices, and the number of Wares and Goods owned per item.

	Precondition: 	nSBPrice, nTRPrice, nILPrice, nIPPrice, nPAWPrice, nMEPRice, 
					nQTPrice, nVSPrice, *nSB, *nTR, *nIL, *nIP, *nPAW, *nME, *nQT, *nVS 
					must be positive integers.

	@param nSBPrice is the generated price of Sweet Beet					
	@param nTRPrice is the generated price of Timber						
	@param nILPrice is the generated price of Intricate Lace				
	@param nIPPrice is the generated price of Intoxicating Perfume			
	@param nPAWPrice is the generated price of Pale Amber Wine				
	@param nMEPrice is the generated price of Myrish Eye					
	@param nQTPrice is the generated price of Qohorik Tapestry				
	@param nVSPrice is the generated price of Valyrian Steel				
	
	@param *nSB is the quantity of Sweet Beet owned
	@param *nTR is the quantity of Timber owned
	@param *nIL is the quantity of Intricate Lace owned
	@param *nIP is the quantity of Intoxicating Perfume owned
	@param *nPAW is the quantity of Pale Amber Wine owned
	@param *nME is the quantity of Myrish Eye owned
	@param *nQT is the quantity of Qohorik Tapestry owned
	@param *nVS is the quantity of Valyrian Steel owned		
*/
void displayPrices(int nSBPrice, int nTRPrice, int nILPrice, int nIPPrice, 
					int nPAWPrice, int nMEPrice, int nQTPrice, int nVSPrice,
					int *nSB, int *nTR, int *nIL, int  *nIP, 
					int *nPAW, int *nME, int *nQT, int *nVS) {
		printf("\n\t+================================================================================================+\n");
		printf("\t|\tITEM \t\tWARES AND GOODS \t\t SELLING/BUYING PRICE\t\tOWNED\t |");
		printf("\n\t+================================================================================================+\n");
		printf("\t| \t[1] \t\tSweet Beet \t\t\t\t %d \t\t\t %d \t | \n", nSBPrice, *nSB);
		printf("\t| \t[2] \t\tTimber \t\t\t\t\t %d \t\t\t %d \t | \n", nTRPrice, *nTR);
		printf("\t| \t[3] \t\tIntricate Lace \t\t\t\t %d \t\t\t %d \t | \n", nILPrice, *nIL);
		printf("\t| \t[4] \t\tIntoxicating Perfume \t\t\t %d \t\t\t %d \t | \n", nIPPrice, *nIP);
		printf("\t| \t[5] \t\tPale Amber Wine \t\t\t %d \t\t\t %d \t | \n", nPAWPrice, *nPAW);
		printf("\t| \t[6] \t\tMyrish Eye \t\t\t\t %d \t\t\t %d \t | \n", nMEPrice, *nME);
		printf("\t| \t[7] \t\tQohorik Tapestry \t\t\t %d \t\t\t %d \t | \n", nQTPrice, *nQT);
		printf("\t| \t[8] \t\tValyrian Steel \t\t\t\t %d \t\t\t %d \t |", nVSPrice, *nVS);
		printf("\n\t+================================================================================================+\n");
}

/* 	This function displays the Inventory. It displays the remaining days, amount of
	Golden Dragons owned, Debt, Savings, Capacity, and Maximum Capacity. It displays the
	Buy, Sell, Wheelhouse, Iron Bank, and Quit options. 
	
	It will also display the Merchant option if the value of nMerchantRand matches the if condition.

	Precondition:	nDays, nGD, nDebt, nSavings, nCap, nMaxCap, nMerchantRand
					must be positive integers.

	@param nDays is the number of days remaining
	@param nGD is the Golden Dragons on hand
	@param nDebt is the amount of Golden Dragons owed from the Iron Bank of Braavos
	@param nSavings is the total amount of Golden Dragons deposited to the Iron Bank of Braavos
	@param nCap is the number of wares and goods owned
	@param nMaxCap is the maximum number of wares and goods that can be owned
	@param nMerchantRand is the random number generated for the Merchant's 10% chance of appearance
*/
 void displayInventory(int nDays, int nGD, int nDebt, int nSavings, int nCap, int nMaxCap, int nMerchantRand) {
	printf("\n\t\tDays Remaining: %d", nDays);
	printf("\n\t\tGolden Dragons: %d", nGD);
	printf("\n\t\tDebt: %d", nDebt);
	printf("\n\t\tSavings: %d", nSavings);
	printf("\n\t\tCapacity: %d / %d", nCap, nMaxCap);
	printf("\n\n\t+================================================================================================+\n");

	if(nMerchantRand == 10) 	// This part will only execute when the 10% chance of Merchant appearance is met
		{
			printf("\t|\t\t\t\t\t   MERCHANT \t\t\t\t\t\t |");
			printf("\n\t|\t\t\t\t\t  [M]erchant \t\t\t\t\t\t |");
			printf("\n\t+================================================================================================+\n");
		}
			
	printf("\n\t[B]uy \t\t [S]ell\t\t [W]heelhouse \t\t [I]ron Bank \t\t\t [Q]uit\n");		
	printf("\n\tChoice: ");
}

/* This function validates the Buying and Selling quantity entered by the user. The loop inside 
	this function will run if nQuantity is a negative integer or is zero.
	
	Precondition: 	nQuantity must be an integer

	@param nQuantity is the quantity entered by the user when buying or selling

	return valid quantity input
*/
int isQuantityValid (int nQuantity) {
	while(nQuantity <= 0)												// Loops when user enters negative integers and zero (0)
	{															
		printf("\n\tThat is not a valid quantity.");					// Warning display
		printf("\n\tQuantity: ");										
		scanf("%d", &nQuantity);										// Asks for quantity
	}	
	return nQuantity;
}

/* This function validates the the item number entered by the user. The loop inside this function will 
run if nItemNo is a negative integer, zero, or a positive integer above 8.
	
	Precondition:	nItemNo must be an integer

	@param nItemNo is the user's item number input respective to the wares/goods chosen

	return valid item number input
*/
int isItemNoValid (int nItemNo) {
	while(nItemNo < 1 || nItemNo > 8)									// Loops when user enters negative integers, zero "0", and positive integers "9" and above
	{																 
		printf("\n\tThat is not a valid item number.");					// Warning display
		printf("\n\tPlease select the item number (1-8): ");			
		scanf("%d", &nItemNo);											// Asks for item choice
	}
	return nItemNo;
}

/* 	This function facilitates the Buy feature of the game. It is inclusive of
	prompting the user for the item choice and buying quantity. It also
	updates the inventory by adding items to the inventory if the 
	buying transaction is successful.

	Precondition:	*nGD, *nCap, *nMaxCap, nSBPrice, nTRPrice, 
					nILPrice, nIPPrice, nPAWPrice, nMEPRice, nQTPrice, 
					nVSPrice, *nSB, *nTR, *nIL, *nIP, *nPAW, *nME, *nQT, *nVS 
					must be positive integers.

	@param *nGD is the Golden Dragons on hand 
	@param *nCap is the number of wares and goods owned
	@param *nMaxCap is the maximum number of wares and goods that can be owned

	@param nSBPrice is the generated price of Sweet Beet					
	@param nTRPrice is the generated price of Timber						
	@param nILPrice is the generated price of Intricate Lace				
	@param nIPPrice is the generated price of Intoxicating Perfume			
	@param nPAWPrice is the generated price of Pale Amber Wine				
	@param nMEPrice is the generated price of Myrish Eye					
	@param nQTPrice is the generated price of Qohorik Tapestry				
	@param nVSPrice is the generated price of Valyrian Steel				
	
	@param *nSB is the quantity of Sweet Beet owned
	@param *nTR is the quantity of Timber owned
	@param *nIL is the quantity of Intricate Lace owned
	@param *nIP is the quantity of Intoxicating Perfume owned
	@param *nPAW is the quantity of Pale Amber Wine owned
	@param *nME is the quantity of Myrish Eye owned
	@param *nQT is the quantity of Qohorik Tapestry owned
	@param *nVS is the quantity of Valyrian Steel owned	
*/
void choiceBuy	(int *nGD, int *nCap, int *nMaxCap, 
				int nSBPrice, int nTRPrice, int nILPrice, int nIPPrice, 
				int nPAWPrice, int nMEPrice, int nQTPrice, int nVSPrice,
				int *nSB, int *nTR, int *nIL, int *nIP, 
				int *nPAW, int *nME, int *nQT, int *nVS) {

	int nItemNo, nBought, nPrice, nQuantity;
	
	if(*nMaxCap - *nCap != 0)												// Checks if the user has capacity to store items
	{
		if(*nGD > 0) {													// Checks if Golden Dragons at hand are greater than 0
			printf("\n\tWhich item would you like to purchase?");				
			printf("\n\tPlease select the item number (1-8): ");				 
			scanf("%d", &nItemNo);												// Asks which item to buy
			nItemNo = isItemNoValid(nItemNo);									// Calls validation function for item choice
						
			printf("\n\tHow many of these would you like to purchase?"); 		 
			printf("\n\tQuantity: ");											 
			scanf("\n%d", &nQuantity);											// Asks for buying quantity
			nQuantity = isQuantityValid(nQuantity);								// Calls validation function for quantity														
																

			if(nQuantity <= *nMaxCap - *nCap) {									// Checks if the quantity entered exceeds the current capacity
				
					switch(nItemNo)													
					{	// Sets nPrice to the price of the item number chosen
						case 1: nPrice = nSBPrice; break;
						case 2: nPrice = nTRPrice; break;
						case 3: nPrice = nILPrice; break;
						case 4: nPrice = nIPPrice; break;
						case 5: nPrice = nPAWPrice; break;
						case 6: nPrice = nMEPrice; break;
						case 7: nPrice = nQTPrice; break;
						case 8: nPrice = nVSPrice; break;
					} 
				
					nBought = nPrice * nQuantity;								// Computes for the total bill
							
					if(nBought <= *nGD)											// Checks if the total bill is less than or equal to the Golden Dragons at hand
					{
						*nGD = *nGD - nBought;									// Replaces the value of Golden Dragons after a purchase
						*nCap = nQuantity + *nCap;								// Replaces the value of capacity after a purchase
						
						switch(nItemNo)										
						{	// Updates the inventory by adding the quantity of the item bought to its respective item
							case 1: *nSB += nQuantity; break;				
							case 2: *nTR += nQuantity; break;
							case 3: *nIL += nQuantity; break;
							case 4: *nIP += nQuantity; break;
							case 5: *nPAW += nQuantity; break;
							case 6: *nME += nQuantity; break;
							case 7: *nQT += nQuantity; break;
							case 8: *nVS += nQuantity; break;
						} 
						printf("\n\tTotal: %d Golden Dragons x %d = %d Golden Dragons.", nPrice, nQuantity, nBought); // Prints total bill

						printf("\n\tYou bought (%d) of this item.\n", nQuantity);				// Prints buying confirmation receipt				
					}
				else printf("\n\tYou have insufficient Golden Dragons.\n");						// Prints if the total bill is higher than the Golden Dragons at hand	
			}		
			else printf("\n\tYou do not have enough capacity.\n");								// Prints if the user has insufficient capacity
		}	
		else printf("\n\tYou do not have any Golden Dragons.\n");								// Prints if there are no more Golden Dragons at hand
	}
	else printf("\n\tYour inventory is full.\n");												// Prints when the capacity is full	
	printf("\n\tPress any key to continue...");
	getch();																					// Pauses output until a key is pressed
	system("cls");	
}

/* 	This function facilitates the Sell feature of the game. It is inclusive of
	prompting the user for the item choice and selling quantity. It also
	updates the inventory by subtracting items from the inventory if 
	the selling transaction is successful.

	Precondition: *nGD, *nCap, *nMaxCap must be positive integers

	@param *nGD is the Golden Dragons on hand 
	@param *nCap is the number of wares and goods owned
	@param *nMaxCap is the maximum number of wares and goods that can be owned

	@param nSBPrice is the generated price of Sweet Beet					
	@param nTRPrice is the generated price of Timber						
	@param nILPrice is the generated price of Intricate Lace				
	@param nIPPrice is the generated price of Intoxicating Perfume			
	@param nPAWPrice is the generated price of Pale Amber Wine				
	@param nMEPrice is the generated price of Myrish Eye					
	@param nQTPrice is the generated price of Qohorik Tapestry				
	@param nVSPrice is the generated price of Valyrian Steel				
	
	@param *nSB is the quantity of Sweet Beet owned
	@param *nTR is the quantity of Timber owned
	@param *nIL is the quantity of Intricate Lace owned
	@param *nIP is the quantity of Intoxicating Perfume owned
	@param *nPAW is the quantity of Pale Amber Wine owned
	@param *nME is the quantity of Myrish Eye owned
	@param *nQT is the quantity of Qohorik Tapestry owned
	@param *nVS is the quantity of Valyrian Steel owned	
*/
void choiceSell	(int *nGD, int *nCap, int *nMaxCap, 
				int nSBPrice, int nTRPrice, int nILPrice, int nIPPrice, 
				int nPAWPrice, int nMEPrice, int nQTPrice, int nVSPrice,
				int *nSB, int *nTR, int *nIL, int *nIP, 
				int *nPAW, int *nME, int *nQT, int *nVS) {

	int nItemNo, nSold, nPrice, nQuantity, nItemInv;
	
	if(*nCap > 0) {																	// Checks if the user has items owned 
		printf("\n\tWhich item would you like to sell?");
		printf("\n\tSelect Item (1-8): ");
		scanf("\n%d", &nItemNo);
		nItemNo = isItemNoValid(nItemNo);											// Calls validation function for item choice

		switch(nItemNo)
		{	// Sets nPrice to the price of the item number chosen						
			case 1: nPrice = nSBPrice; nItemInv = *nSB; break;
			case 2: nPrice = nTRPrice; nItemInv = *nTR; break;
			case 3: nPrice = nILPrice; nItemInv = *nIL; break;
			case 4: nPrice = nIPPrice; nItemInv = *nIP; break;
			case 5: nPrice = nPAWPrice; nItemInv = *nPAW; break;
			case 6: nPrice = nMEPrice; nItemInv = *nME; break;
			case 7: nPrice = nQTPrice; nItemInv = *nQT; break;
			case 8: nPrice = nVSPrice; nItemInv = *nVS; break;
		}		
		
		if(nItemInv > 0)															// Checks if the inventory contains atleast one of the respective item
			{
				printf("\n\tHow many of these would you like to sell?");			// Asking for selling quantity
				printf("\n\tQuantity: ");											
				scanf("\n%d", &nQuantity);
				nQuantity = isQuantityValid(nQuantity);								// Calls validation function for quantity

				if(nQuantity <= nItemInv)											// Checks if the selling quantity is less than or equal to the amount of the
					{																// respective item the user has
						nSold = nPrice * nQuantity;									// Computes for the total bill
						*nGD = *nGD + nSold;										// Updates the Golden Dragons owned by adding the total bill to it
						*nCap -= nQuantity;											// Updates the Capacity by subtracting the quantity sold

						printf("\n\tTotal: %d Golden Dragons x %d = %d Golden Dragons.", nPrice, nQuantity, nSold);	// Prints total bill
						
						printf("\n\tSold (%d) of this item.\n", nQuantity);			// Prints selling confirmation receipt

						switch(nItemNo)	
						{	// Subtracts the quantity from the respective item choice								
							case 1: *nSB -= nQuantity; break;				
							case 2: *nTR -= nQuantity; break;
							case 3: *nIL -= nQuantity; break;
							case 4: *nIP -= nQuantity; break;
							case 5: *nPAW -= nQuantity; break;
							case 6: *nME -= nQuantity; break;
							case 7: *nQT -= nQuantity; break;
							case 8: *nVS -= nQuantity; break;
						}
					}
				else printf("\n\tYou do not have enough of this item.\n");			// Execute when the user tries to sell exceeding the amount of a specific 
																					// item in their inventory
			}			
			else printf("\n\tYou do not have any of this item.\n");					// Executes when the user tries to sell an item that is not in their inventory
	}				
	else printf("\n\tThere is nothing to sell. Your inventory is empty.\n");		// Executes when there is nothing inside the user's inventory // Warning display
	printf("\n\tPress any key to continue...");
	getch();																					// Pauses output until a key is pressed
	system("cls");
}

/* 	This function displays the Iron Bank of Braavos. It displays the 
	bank's features and prompts the user for a choice.

	Precondition: *nGD, *nSavings, *nDebt must be positive integers.

	@param nGD is the Golden Dragons on hand
	@param nSavings is the total amount of Golden Dragons deposited to the Iron Bank of Braavos
	@param nDebt is the amount of Golden Dragons owed from the Iron Bank of Braavos
*/
void displayIronBank(int nGD, int nSavings, int nDebt) {

	printf("\n\t\t\t\t+============= IRON BANK OF BRAAVOS =============+\n");
	printf("\t\t\t\t|\t\t\t\t\t\t |\n");
	printf("\t\t\t\t|\t[1] Deposit GDs \t\t\t |\n");
	printf("\t\t\t\t|\t[2] Withdraw GDs \t\t\t |\n");
	printf("\t\t\t\t|\t[3] Get a loan \t\t\t\t |\n");
	printf("\t\t\t\t|\t[4] Pay-back a debt\t\t\t |\n");
	printf("\t\t\t\t|\t\t\t\t\t\t |\n");
	printf("\t\t\t\t|\t[5] Return\t\t\t\t |\n");
	printf("\t\t\t\t|\t\t\t\t\t\t |\n");
	printf("\t\t\t\t+================================================+\n\n");
	printf("\t\t\t\t\tGolden Dragons: %d \t\t\t\n", nGD);
	printf("\t\t\t\t\tBank Balance: %d \t\t\t\n", nSavings);
	printf("\t\t\t\t\tDebt: %d\t\t\t\t\t\n\n", nDebt);	
	printf("\t\t\t\t\tMinimum Deposit: 10 GD\t\t\t\t\t\n");
	printf("\t\t\t\t\tMinimum Loan: 10 GD\t\t\t\t\t\n\n");		
	printf("\n\t\t\t\t+================================================+");
	printf("\n\t\t\t\tChoice: ");
}	

/* 	This function displays the Iron Bank of Braavos. It displays the 
	bank's features and prompts the user for a choice.

	Precondition:	nIronBankChoice must be a positive integer from 1 to 5.
					Moroever, *nGD, *nDebt, and *nSavings must be positive integers.

	@param nIronBankChoice is the user's choice in the Iron Bank of Braavos
	@param *nGD is the Golden Dragons on hand
	@param *nDebt is the amount of Golden Dragons owed from the Iron Bank of Braavos
	@param *nSavings is the total amount of Golden Dragons deposited to the Iron Bank of Braavos
*/
void choiceIronBank(int nIronBankChoice, int *nGD, int *nDebt, int *nSavings) {
		
	int nDeposit;				// Stores the deposit amount
	int nWithdraw;				// Stores the Withdraw amount
	int nLoan;					// Stores the Loan amount
	int nPayBack;				// Stores the amount of loan being paid

	switch(nIronBankChoice)
	{	
		case 1: if(*nGD > 0)																				// Checks if the Golden Dragons on hand are greater than zero
				{	
					printf("\n\t\t\t\t\tHow much would you like to deposit?");							// Asks for the deposit amount
					printf("\n\t\t\t\t\tAmount: ");
					scanf("%d", &nDeposit);
					
					if(nDeposit >= 10) {																	// Checks if the deposit amount input is greater than the minimum deposit of 10 GD
						if(nDeposit <= *nGD) {																// Checks if the deposit amount is less than or equal to the Golden Dragons on hand
							*nGD = *nGD - nDeposit;															// Updates the Golden Dragons at hand by subtracting the deposit amount from it
							*nSavings = *nSavings + nDeposit;												// Updates the Savings by adding the deposit amount to it
							printf("\n\t\t\t\t\tYou have deposited %d Golden Dragons.\n", nDeposit);		// Prints deposit confirmation receipt
						}			
						else printf("\n\t\t\t\t\tYou do not have enough Golden Dragons.\n");				// Prints when trying to deposit more than Golden Dragons at hand
					}
					
					else printf("\n\t\t\t\t\tThe minimum deposit is 10 Golden Dragons.\n");					// Prints when trying to deposit lower than minimum deposit amount
				}

				else printf("\n\t\t\t\t\tYou don't have any Golden Dragons on hand.");						// Prints when there are no Golden Dragons on hand
				break;
				
		case 2: 
				if(*nSavings > 0) {																			// Checks if the user has Savings
					printf("\n\t\t\t\t\tHow much would you like to withdraw?");							// Asks user for withdraw amount
					printf("\n\t\t\t\t\tAmount: ");
					scanf("%d", &nWithdraw);

					if(nWithdraw > 0) {																		// Checks if the withdraw amount is greater than zero
						if(nWithdraw <= *nSavings) {														// Checks if the withdraw amount is less than or equal to the Savings
							*nGD = *nGD + nWithdraw;														// Updates the Golden Dragons on hand by adding withdraw amount to it
							*nSavings = *nSavings - nWithdraw;												// Updates the Savings by subtracting the withdraw amount from it
							printf("\n\t\t\t\t\tYou have withdrawn %d Golden Dragons\n", nWithdraw);		// Prints withdraw confirmation receipt
						}

						else printf("\n\t\t\t\t\tYou do not have enough bank balance.\n");					// Prints withdraw amount exceeds Savings owned

					}

					else printf("\n\t\t\t\t\tPlease enter a valid amount.\n");								// Prints when the withdraw amount is negative or equal to zero
				}

				else printf("\n\t\t\t\tYour bank balance is zero.\n");										// Prints when there are no Savings
				break;

		case 3:	printf("\n\t\t\t\t\tHow much would you like to loan?");										// Asks for the loan amount
				printf("\n\t\t\t\t\tAmount: ");
				scanf("%d", &nLoan);

				if(nLoan >= 10) {																			// Checks if the loan amount is greater than or equal to the minimum loan of 10 GD
					*nDebt = *nDebt + nLoan;																// Updates Debt by adding the loan amount to it
					*nGD = *nGD + nLoan;																	// Updates Golden Dragons on hand by adding loan amount to it
					printf("\n\t\t\t\t\tYou loaned %d Golden Dragons.\n", nLoan);							// Prints loan confirmation receipt
				}					
				
				else printf("\n\t\t\t\t\tThe minimum loan is 10 Golden Dragons.\n");						// Prints when trying to loan lower than minimum loan amount
				break;

		case 4:	if(*nDebt > 0) {																			// Checks if the user has Debt
					printf("\n\t\t\t\t\tHow much debt would you like to pay?");							// Asks user for payback amount
					printf("\n\t\t\t\t\tAmount: ");
					scanf("%d", &nPayBack);

					if(nPayBack <= *nDebt) {																// Checks if the payback amount is less than or equal to the debt 
						*nDebt = *nDebt - nPayBack;
						*nGD = *nGD - nPayBack;																// Updates Golden dragons on hand by subtracting payback amount from it
						printf("\n\t\t\t\t\tYou have paid back %d Golden Dragons.\n", nPayBack);			// Prints Payback confirmation
					}

					else printf("\n\t\t\t\t\tYou are paying more than your debt.\n");						// Prints when trying to pay back more than debt
				}
				
				else printf("\n\t\t\t\t\tYou do not have debt.\n");											// Prints when there is no debt
				break;
				
		case 5: nIronBankChoice = 5;																		// Returns to the trading screen 
				break;
		
		default: printf("\n\t\t\t\tPlease enter a valid choice.\n");										// Prints when user does not enter a valid choice
				 printf("\n\t\t\t\t\tPress any key to continue...");
				 getch();																					// Pauses output until a key is pressed
		break;
	}
}

/*  This function displays the Merchant screen. It prompts the user for a choice
	to avail the wheelhouse capacity upgrade.

	Precondition: *nGD and *nMaxCapcity must be positive integers

	@param *nGD is the Golden Dragons on hand
	@param *nMaxCap is the maximum number of wares and goods that can be owned
*/
void displayMerchant(int *nGD, int *nMaxCap) {
	char cMerchantChoice;					// Stores user's Merchant upgrade choice

	printf("\n\t\t+========================================================================+\n");
	printf("\t\t\t\t\t\t MERCHANT \t\t\t\t\t\t ");
	printf("\n\t\t\t\tDo you want to increase your wheelhouse capacity by 50?\t\t\n");
	printf("\t\t\tCost: 200 Golden Dragons\t\t\n");
	printf("\n\t\t+========================================================================+\n\n");
	
	printf("\t\t\t\t[Y]es \t\t\t\t [N]o\n\n");
	printf("\t\t\t\tChoice: ");
	scanf(" %c", &cMerchantChoice);
	
	
	if(cMerchantChoice == 'Y' || cMerchantChoice == 'y') {											// Checks if the user avails the upgrade
		if(*nGD >= 200) {																			// Checks if the Golden Dragons on hand is greater than or equal to 200 GD
			*nMaxCap += 50;																			// Updates the Maximum Capacity by adding 50 more capacity
			*nGD -= 200;																			// Updates the Golden Dragons on hand by subtracing 200 GD from it
			printf("\n\t\t\t\tThe wheelhouse capacity is now 100.\n");								// Prints wheelhouse capacity upgrade confirmation
		}
		else printf("\n\t\t\t\tYou do not have enough Golden dragons to avail the upgrade.\n");		// Prints when Golden Dragons on hand is less than 200 GD
	}	 
	else if(cMerchantChoice == 'N' || cMerchantChoice == 'n') {										// Checks if the user does not want to avail the upgrade
		printf("\n\t\t\tUntil we meet again.\n");													// Prints wheelhouse capacity upgrade decline confirmation
	}
	else printf("\n\t\t\tPlease enter a valid choice.\n");											// Prints when user does not enter a valid choice
	printf("\n\t\t\t\t\tPress any key to continue...");
	getch();																						// Pauses output until a key is pressed
}

/* 	This function is the Final Inventory which displays the Inventory of the user upon quitting. 
	It displays the remaining days, amount of Golden Dragons owned, Debt, Savings, Capacity, and Maximum Capacity. 
	It also displays the respective number of wares and goods owned.

	Precondition: nDays, nGD, nDebt, nSavings, nCap, nMaxCap, 
					nSB, nTR, nIL, nIP, nPAW, nME, nQT, nVS are positive integers

	@param nDays is the number of days remaining 
	@param nGD is the Golden Dragons on hand
	@param nDebt is the amount of Golden Dragons owed from the Iron Bank of Braavos
	@param nSavings is the total amount of Golden Dragons deposited to the Iron Bank of Braavos
	@param nCap is the number of wares and goods owned
	@param nMaxCap is the maximum number of wares and goods that can be owned

	@param nSB is the quantity of Sweet Beet owned
	@param nTR is the quantity of Timber owned
	@param nIL is the quantity of Intricate Lace owned
	@param nIP is the quantity of Intoxicating Perfume owned
	@param nPAW is the quantity of Pale Amber Wine owned
	@param nME is the quantity of Myrish Eye owned
	@param nQT is the quantity of Qohorik Tapestry owned
	@param nVS is the quantity of Valyrian Steel owned	
*/

void displayFinalInventory	(int nDays, int nGD, int nDebt, int nSavings, int nCap, int nMaxCap, 
							int nSB, int nTR, int nIL, int nIP, 
							int nPAW, int nME, int nQT, int nVS) {

	printf("\n\t\t\t+========================================================================+\n");
	printf("\t\t\t|\t\t\t    FINAL INVENTORY \t\t\t\t |");
	printf("\n\t\t\t+========================================================================+\n");
	printf("\t\t\t|\tITEM \t\tWARES AND GOODS \t\t OWNED\t\t |");
	printf("\n\t\t\t+========================================================================+\n");
	printf("\t\t\t| \t[1] \t\tSweet Beet\t\t\t  %d \t\t |\n", nSB);
	printf("\t\t\t| \t[2] \t\tTimber \t\t\t\t  %d \t\t |\n", nTR);
	printf("\t\t\t| \t[3] \t\tIntricate Lace\t\t\t  %d \t\t |\n", nIL);
	printf("\t\t\t| \t[4] \t\tIntoxicating Perfume \t\t  %d \t\t | \n", nIP);
	printf("\t\t\t| \t[5] \t\tPale Amber Wine \t\t  %d \t \t |\n", nPAW);
	printf("\t\t\t| \t[6] \t\tMyrish Eye\t\t\t  %d \t\t |\n", nME);
	printf("\t\t\t| \t[7] \t\tQohorik Tapestry \t\t  %d \t\t |\n", nQT);
	printf("\t\t\t| \t[8] \t\tValyrian Steel\t\t\t  %d \t\t |", nVS);
	printf("\n\t\t\t+========================================================================+");
	printf("\n\t\t\t|\tDays Remaining: %d  \t\t\t\t\t\t |\n", nDays);
	printf("\t\t\t|\tGolden Dragons: %d  \t\t\t\t\t\t |\n", nGD);
	printf("\t\t\t|\tDebt: %d  \t\t\t\t\t\t\t |\n", nDebt);
	printf("\t\t\t|\tSavings: %d  \t\t\t\t\t\t\t |\n", nSavings);
	printf("\t\t\t|\tCapacity: %d / %d\t\t\t\t\t\t |", nCap, nMaxCap);
	printf("\n\t\t\t+========================================================================+\n");
}
