#include <stdio.h>
#include <string.h>
#include "realEstateMain.c"

/*
Each apartment has an address, a number of rooms, a number of bathrooms, a purchase price, monthly rent, monthly condo fees, monthly earnings, annual return on investment, current value, and capital gains.
To determing the performance of each apartment:
monthly earnings = monthly rent - monthly condo fees.
return on investment (percent) = 100 x 12 x monthly earnings / purchase price.
current value = 12 x monthly earnings / interest rate. The interest rate is hard-coded to 5% (or 0.05).
capital gains = current value - purchase price
struct apartment
*/

double currentValueA(struct apartment* cvA)
{
    double curVAL;
    cvA->currentValue = (cvA->mEarning * 12) / interestrate;
    return cvA->currentValue;
}

double monthlyEarningA(struct apartment* meA)
{
    meA->mEarning = 0;
    for (int i = 0; i < 5; ++i)
    {
        meA->mEarning = meA->mEarning + (meA[i].mRent - meA[i].mcondoFee);
    }
    return meA->mEarning;
}

double returnInvestmentA(struct apartment* riA)
{
    double total = 0.0;
    for (int i = 0; i < 5; i++)
    {
        total = total + riA[i].pPrice; //totals the purchase price, as we need total ROI percentage
    }
    riA->rInvestment = 100 * 12 * (riA->mEarning / total);
    return riA->rInvestment;
}

double capitalgainsA(struct apartment* cgA)
{
    double total = 0;
    for (int i = 0; i < 5; i++)
    {
        total = total + cgA[i].pPrice;
    }
    cgA->cGains = cgA->currentValue - total;
    return cgA->cGains;
}
/*
Each townhouse has an address, a number of rooms, a number of bathrooms, a purchase price, monthly rent, monthly utilities, monthly condo fees, monthly property tax, monthly earnings, annual return on investment, current value, and capital gains.
To determing the performance of each townhouse:
monthly earnings = monthly rent - monthly utilities - monthly condo fees - monthly property tax.
return on investment (percent) = 100 x 12 x monthly earnings / purchase price.
current value = 12 x monthly earnings / interest rate. The interest rate is hard-coded to 5% (or 0.05).
capital gains = current value - purchase price.
struct townHouse
*/

double monthlyEarningT(struct townHouse* meT)
{
    meT->mEarning = 0;
    for (int i = 0; i < 5; ++i)
    {
        meT->mEarning = meT->mEarning + (meT[i].mRent - meT[i].mutilities - meT[i].mcondoFee - meT[i].mPrtTax);
    }
    return meT->mEarning;
}


double returnInvestmentT(struct townHouse* riT)
{
    double total = 0.0;
    for (int i = 0; i < 5; i++)
    {
        total = total + riT[i].pPrice; //totals the purchase price, as we need total ROI percentage
    }
    riT->rInvestment = 100 * 12 * (riT->mEarning / total);
    return riT->rInvestment;
}

double currentValueT(struct townHouse* cvT)
{
    cvT->currentValue = (12 * cvT->mEarning) / interestrate;
    return cvT->currentValue;
}

double capitalgainsT(struct townHouse* cgT)
{
    double total = 0;
    for (int i = 0; i < 5; i++)
    {
        total = total + cgT[i].pPrice;
    }
    cgT->cGains = cgT->currentValue - total;
    return cgT->cGains;
}

/*
Each semi-detached house has an address, a number of rooms, a number of bathrooms, a purchase price, monthly rent, monthly utilities, monthly property tax, monthly earnings, annual return on investment, current value, and capital gains.
To determing the performance of each semi-detached house:
monthly earnings = monthly rent - monthly utilities - monthly property tax.
return on investment (percent) = 100 x 12 x monthly earnings / purchase price.
current value = 12 x monthly earnings / interest rate. The interest rate is hard-coded to 5% (or 0.05).
capital gains = current value - purchase price.
*/


double monthlyEarningS(struct semiDhouse* meS)
{
    meS->mEarning = 0;
    for (int i = 0; i < 5; ++i) {
        meS->mEarning = meS->mEarning + (meS[i].mRent - meS[i].mutilities - meS[i].mPrtTax);
    }
    return meS->mEarning;
}

double returnInvestmentS(struct semiDhouse* riS)
{
    double total = 0;
    for (int i = 0; i < 5; i++)
    {
        total = total + riS[i].pPrice; //totals the purchase price, as we need total ROI percentage
    }
    riS->rInvestment = 100 * 12 * (riS->mEarning / total);
    return riS->rInvestment;
}

double currentValueS(struct semiDhouse* cvS)
{
    cvS->currentValue = 12 * cvS->mEarning / interestrate;
    return cvS->currentValue;
}

double capitalgainsS(struct semiDhouse* cgS)
{
    double total = 0;
    for (int i = 0; i < 5; ++i) {
        total = total + (cgS[i].pPrice);
    }
    cgS->cGains = cgS->currentValue - total;
    return cgS->cGains;
}
