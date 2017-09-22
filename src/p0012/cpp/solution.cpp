#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string intToRoman(int i) {
        return sd[i/1000] + sc[i%1000/100] + sx[i%100/10] + si[i%10];
    }

public:
    static const string sd[], sc[], sx[], si[];
};

const string Solution::sd[] = {"","M","MM","MMM"};
const string Solution::sc[] = {"","C","CC","CCC","CD","D","DC","DCC","DCCC","CM"};
const string Solution::sx[] = {"","X","XX","XXX","XL","L","LX","LXX","LXXX","XC"};
const string Solution::si[] = {"","I","II","III","IV","V","VI","VII","VIII","IX"};
