//
//  ECMerchandise.h
//  
//
//  Created by Yufeng Wu on 3/11/20.
//
//

#ifndef ECMerchandise_hpp
#define ECMerchandise_hpp

#include <string>

class ECMerchandise {
    public :
        int price() { return _price; }
    protected :
        int _price;
};
// ==================== TENNIS SHOES ================================
class ECTennisShoe : public ECMerchandise {
    protected :
        int _size;
};

class ECNikeTennisShoe : public ECTennisShoe {
    public :
        ECNikeTennisShoe(int size) {
            _size = size;
            _price = 15;
        }
};

class ECAdidasTennisShoe : public ECTennisShoe {
    public :
        ECAdidasTennisShoe(int size) {
            _size = size;
            _price = 20;
        }
};

class ECHeadTennisShoe : public ECTennisShoe {
    public :
        ECHeadTennisShoe(int size) {
            _size = size;
            _price = 10;
        }
};

// ==================== TENNIS BALL CAN ================================

class ECTennisBallCan : public ECMerchandise {
    public :
        int numBalls() { return _numBalls; }
    protected :
        int _numBalls;
};

class ECNikeTennisBallCan : public ECTennisBallCan {
    public :
        ECNikeTennisBallCan() {
            _numBalls = 4;
            _price = 6;
        }
};

class ECAdidasTennisBallCan : public ECTennisBallCan {
    public :
        ECAdidasTennisBallCan() {
            _numBalls = 3;
            _price = 5;
        }
};

class ECHeadTennisBallCan : public ECTennisBallCan {
    public :
        ECHeadTennisBallCan() {
            _numBalls = 3;
            _price = 4;
        }
};

// ==================== TENNIS BAG ================================

class ECTennisBag : public ECMerchandise {
    public :
        int racquetCapacity() { return _numRacquets; }
    protected :
        int _numRacquets;
};

class ECNikeTennisBag : public ECTennisBag {
    public :
        ECNikeTennisBag() {
            _numRacquets = 4;
            _price = 12;
        }
};

class ECAdidasTennisBag : public ECTennisBag {
    public :
        ECAdidasTennisBag() {
            _numRacquets = 6;
            _price = 18;
        }
};

class ECHeadTennisBag : public ECTennisBag {
    public :
        ECHeadTennisBag() {
            _numRacquets = 3;
            _price = 10;
        }
};
#endif /* ECMerchandise_hpp */
