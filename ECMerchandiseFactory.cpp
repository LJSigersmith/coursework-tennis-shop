//
//  ECMerchandiseFactory.cpp
//  
//
//  Created by Yufeng Wu on 3/11/20.
//
//

#include "ECMerchandiseFactory.h"
#include <iostream>

using namespace  std;

// *********************************************************
// Merchandise creation: singleton pattern
ECMerchandiseTennisShop::~ECMerchandiseTennisShop() {

}

ECMerchandiseTennisShop& ECMerchandiseTennisShop::Instance() {
    if (_instance == nullptr) {
        _instance = new ECMerchandiseTennisShop;
    }
    return *_instance;
}

ECMerchandiseTennisShop::ECMerchandiseTennisShop() {
    _factory = new ECAdidasFactory();
    _numShoesSold = _numCansSold = _numBagsSold = _numBallsSold = _numRacquetCapacitySold = _totalRevenue = 0;
}

ECTennisShoe* ECMerchandiseTennisShop::OrderTennisShoe(int size) {
    ECTennisShoe* newShoe = _factory->CreateTennisShoe(size);
    _numShoesSold += 1;
    _totalRevenue += newShoe->price();
    return newShoe;
}

ECTennisBallCan* ECMerchandiseTennisShop::OrderTennisBallCan() {
    ECTennisBallCan* newCan = _factory->CreateTennisBallCan();
    _numCansSold += 1;
    _numBallsSold += newCan->numBalls();
    _totalRevenue += newCan->price();
    return newCan;
}

ECTennisBag* ECMerchandiseTennisShop::OrderTennisBag() {
    ECTennisBag* newBag = _factory->CreateTennisBag();
    _numRacquetCapacitySold += newBag->racquetCapacity();
    _numBagsSold += 1;
    _totalRevenue += newBag->price();
    return newBag;
}

void ECMerchandiseTennisShop::ChooseVendor(TENNIS_VENDOR vendor) {
    if (vendor == TENNIS_ADIDAS && dynamic_cast<ECAdidasFactory*>(_factory) == NULL) {
        delete _factory;
        _factory = new ECAdidasFactory();
    } else
    if (vendor == TENNIS_HEAD && dynamic_cast<ECHeadFactory*>(_factory) == NULL) {
        delete _factory;
        _factory = new ECHeadFactory();
    } else
    if (vendor == TENNIS_NIKE && dynamic_cast<ECNikeFactory*>(_factory) == NULL) {
        delete _factory;
        _factory = new ECNikeFactory();
    } else {
        // Default is Adidas but check if factory is already Adidas
        if (dynamic_cast<ECAdidasFactory*>(_factory) == NULL) {
            delete _factory;
            _factory = new ECAdidasFactory();
        }
    }
}

int ECMerchandiseTennisShop::GetNumShoesSold() const {
    return _numShoesSold;
}

int ECMerchandiseTennisShop::GetNumBallcansSold() const {
    return _numCansSold;
}

int ECMerchandiseTennisShop::GetNumBagsSold() const {
    return _numBagsSold;
}

int ECMerchandiseTennisShop::GetTotNumBallsSold() const {
    return _numBallsSold;
}

int ECMerchandiseTennisShop::GetTotRacquetBagCapaictySold() const {
    return _numRacquetCapacitySold;
}

int ECMerchandiseTennisShop::GetTotRevenue() const {
    return _totalRevenue;
}