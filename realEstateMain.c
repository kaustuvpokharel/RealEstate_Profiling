//RealEstateMain.c - main program for real estate companies

// 02-Mar-21  M. Watler

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include "realEstate.h"

int main(void) {
	//Read the data for all companies from a file

	struct apartment aprt[NUM];
	struct townHouse twnhouse[NUM];
	struct semiDhouse SemiDhouse[NUM];

	//Retrieve data for apartments
	FILE* fp = fopen("Apartments.txt", "r");
	for (int i = 0; i < NUM; ++i) {
		fscanf(fp, "%[^\n]s", aprt[i].address);
		fscanf(fp, "%d", &aprt[i].nRoom);
		fscanf(fp, "%d", &aprt[i].nRoom);
		fscanf(fp, "%lf", &aprt[i].pPrice);
		fscanf(fp, "%lf", &aprt[i].mRent);
		fscanf(fp, "%lf", &aprt[i].mcondoFee);
		while (fgetc(fp) != '\n');//clear the file buffer before the next fscanf()
	}
	fclose(fp);

	//Retrieve data for townhouses
	fp = fopen("Townhouses.txt", "r");
	for (int i = 0; i < NUM; ++i) {
		fscanf(fp, "%[^\n]s", twnhouse[i].address);
		fscanf(fp, "%d", &twnhouse[i].nRoom);
		fscanf(fp, "%d", &twnhouse[i].nBathroom);
		fscanf(fp, "%lf", &twnhouse[i].pPrice);
		fscanf(fp, "%lf", &twnhouse[i].mRent);
		fscanf(fp, "%lf", &twnhouse[i].mutilities);
		fscanf(fp, "%lf", &twnhouse[i].mcondoFee);
		fscanf(fp, "%lf", &twnhouse[i].mPrtTax);
		while (fgetc(fp) != '\n');//clear the file buffer before the next fscanf()
	}
	fclose(fp);

	//Retrieve data for semi-detached houses
	fp = fopen("SemiDetachedHouses.txt", "r");
	for (int i = 0; i < NUM; ++i) {
		fscanf(fp, "%[^\n]s", SemiDhouse[i].address);
		fscanf(fp, "%d", &SemiDhouse[i].nRoom);
		fscanf(fp, "%d", &SemiDhouse[i].nBathroom);
		fscanf(fp, "%lf", &SemiDhouse[i].pPrice);
		fscanf(fp, "%lf", &SemiDhouse[i].mRent);
		fscanf(fp, "%lf", &SemiDhouse[i].mutilities);
		fscanf(fp, "%lf", &SemiDhouse[i].mPrtTax);
		while (fgetc(fp) != '\n');//clear the file buffer before the next fscanf()
	}
	fclose(fp);

	for (int i = 0; i < 5; ++i)
	{
		monthlyEarningA(&aprt[i]);
		returnInvestmentA(&aprt[i]);
		currentValueA(&aprt[i]);
		capitalgainsA(&aprt[i]);

		monthlyEarningT(&twnhouse[i]);
		returnInvestmentT(&twnhouse[i]);
		currentValueT(&twnhouse[i]);
		capitalgainsT(&twnhouse[i]);

		monthlyEarningS(&SemiDhouse[i]);
		returnInvestmentS(&SemiDhouse[i]);
		currentValueS(&SemiDhouse[i]);
		capitalgainsS(&SemiDhouse[i]);
	}

	printf("\nFinancial stats for Brookfield Asset Management, 11 Yonge Street.\n\n");
	printf("Apartments: monthly earnings are $%.2lf, roi is %.2lf%%,\ntotal value is $%.2lf and capital gains are $%.2lf\n\n", aprt->mEarning, aprt->rInvestment, aprt->currentValue, aprt->cGains);
	printf("Townhouses: monthly earnings are $%.2lf, roi is %.2lf%%,\ntotal value is $%.2lf and capital gains are $%.2lf\n\n", twnhouse->mEarning, twnhouse->rInvestment, twnhouse->currentValue, twnhouse->cGains);
	printf("Semidetached houses: monthly earnings are $%.2lf, roi is %.2lf%%,\ntotal value is $%.2lf and capital gains are $%.2lf\n\n", SemiDhouse->mEarning, SemiDhouse->rInvestment, SemiDhouse->currentValue, SemiDhouse->cGains);
	return 0;
}


// Unlike structure, class is private by default.
// So we need to add the access specifier called public so that the functions can access the members of the class.
// I will add all the members of the structure in the class and the functions.
// The functions will be inside the class.