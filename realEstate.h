#define NUM 5
#define MAX_STR 40
#define interestrate 0.05 //Global variable as it's contant for every calculation

/* Each apartment has an address, a number of rooms, a number of bathrooms, a purchase price, monthly rent, monthly condo fees,
monthly earnings, annual return on investment, current value, and capital gains.
*/

struct apartment
{
    char address[MAX_STR];
    int nRoom;
    int nBathroom;
    double pPrice;
    double mRent;
    double mcondoFee;
    double mEarning;
    double rInvestment;
    double currentValue;
    double cGains;
};
/* Each townhouse has an address, a number of rooms, a number of bathrooms, a purchase price, monthly rent, monthly utilities,
monthly condo fees, monthly property tax, monthly earnings, annual return on investment, current value, and capital gains.
*/
struct townHouse
{
    char address[MAX_STR];
    int nRoom;
    int nBathroom;
    double pPrice;
    double mRent;
    double mutilities;
    double mcondoFee;
    double mPrtTax;
    double mEarning;
    double rInvestment;
    double currentValue;
    double cGains;
};
/* Each semi-detached house has an address, a number of rooms, a number of bathrooms, a purchase price, monthly rent, monthly utilities,
monthly property tax, monthly earnings, annual return on investment, current value, and capital gains.
*/
struct semiDhouse
{
    char address[MAX_STR];
    int nRoom;
    int nBathroom;
    double pPrice;
    double mRent;
    double mutilities;
    double mPrtTax;
    double mEarning;
    double rInvestment;
    double currentValue;
    double cGains;
};
/*
Some of the fuctions for the calculations of the performance of the given data
*/

double monthlyEarningA(struct apartment* meA);
double returnInvestmentA(struct apartment* riA);
double currentValueA(struct apartment* cvA);
double capitalgainsA(struct apartment* cgA);

double monthlyEarningT(struct townHouse* meT);
double returnInvestmentT(struct townHouse* riT);
double currentValueT(struct townHouse* cvT);
double capitalgainsT(struct townHouse* cgT);

double monthlyEarningS(struct semiDhouse* meS);
double returnInvestmentS(struct semiDhouse* riS);
double currentValueS(struct semiDhouse* cvS);
double capitalgainsS(struct semiDhouse* cgS);