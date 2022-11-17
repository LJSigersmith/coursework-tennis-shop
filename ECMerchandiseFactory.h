//
//  ECMerchandiseFactory.hpp
//  
//
//  Created by Yufeng Wu on 3/11/20.
//
//

#ifndef ECMerchandiseFactory_hpp
#define ECMerchandiseFactory_hpp

#include "ECMerchandise.h"

// *********************************************************
// List of vendors
typedef enum
{
    TENNIS_ADIDAS = 1,
    TENNIS_NIKE = 2,
    TENNIS_HEAD = 3
} TENNIS_VENDOR;

// *********************************************************
// merchandise factory

// your code goes here

class ECMerchandiseFactory {
    public :
        virtual ~ECMerchandiseFactory() = default;
        virtual ECTennisShoe* CreateTennisShoe(int size) = 0;
        virtual ECTennisBallCan* CreateTennisBallCan() = 0;
        virtual ECTennisBag* CreateTennisBag() = 0;
};

class ECNikeFactory : public ECMerchandiseFactory {
    public :
        ~ECNikeFactory() {}
        ECTennisShoe* CreateTennisShoe(int size) override {
            return new ECNikeTennisShoe(size);
        }
        ECTennisBallCan* CreateTennisBallCan() override {
            return new ECNikeTennisBallCan();
        }
        ECTennisBag* CreateTennisBag() override {
            return new ECNikeTennisBag();
        }

};
class ECAdidasFactory : public ECMerchandiseFactory {
    public :
        ~ECAdidasFactory() {}
        ECTennisShoe* CreateTennisShoe(int size) override {
            return new ECAdidasTennisShoe(size);
        }
        ECTennisBallCan* CreateTennisBallCan() override {
            return new ECAdidasTennisBallCan();
        }
        ECTennisBag* CreateTennisBag() override {
            return new ECAdidasTennisBag();
        }

};
class ECHeadFactory : public ECMerchandiseFactory {
    public :
        ~ECHeadFactory() {}
        ECTennisShoe* CreateTennisShoe(int size) override {
            return new ECHeadTennisShoe(size);
        }
        ECTennisBallCan* CreateTennisBallCan() override {
            return new ECHeadTennisBallCan();
        }
        ECTennisBag* CreateTennisBag() override {
            return new ECHeadTennisBag();
        }

};
// *********************************************************
// Merchandise creation: singleton pattern

class ECMerchandiseTennisShop
{
public:
    virtual ~ECMerchandiseTennisShop();
    static ECMerchandiseTennisShop& Instance();
    ECTennisShoe *OrderTennisShoe(int sz);
    ECTennisBallCan *OrderTennisBallCan();
    ECTennisBag *OrderTennisBag();
    void ChooseVendor(TENNIS_VENDOR vendor);
    int GetNumShoesSold() const;
    int GetNumBallcansSold() const;
    int GetNumBagsSold() const;
    int GetTotNumBallsSold() const;
    int GetTotRacquetBagCapaictySold() const;
    int GetTotRevenue() const;

protected :
    inline static ECMerchandiseTennisShop* _instance = nullptr;
    ECMerchandiseTennisShop();
    ECMerchandiseFactory* _factory;
private:
    int _numShoesSold;
    int _numCansSold;
    int _numBagsSold;
    int _numBallsSold;
    int _numRacquetCapacitySold;
    int _totalRevenue;
};


#endif /* ECMerchandiseFactory_hpp */
