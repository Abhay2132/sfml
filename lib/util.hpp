#ifndef _UTIL_H_
#define _UTIL_H_

#include<SFML/Graphics.hpp>

using std::cout, std::endl;

typedef void (* Callback )(void);

namespace _ {
	bool oscillate(double &val, double a, double z, double &step)
	{
		bool gg = false;
		if(val < a || val > z){
			gg =true;
		 	step *= -1;
		}
		val += step;

		return gg;
	}

}

double getDist(sf::Time dt, double speed){
	// cout<<speed<<endl;
	return speed * (dt.asMicroseconds()*0.000001);
}

double cycle(double val, double a, double b){
	if(val < a) return b;
	if(val > b) return a;
	return val;
}


#endif