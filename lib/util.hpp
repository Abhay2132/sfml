#ifndef _UTIL_H_
#define _UTIL_H_

#include<SFML/Graphics.hpp>

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
	return speed * (dt.asMicroseconds()*0.000001);
}

double cycle(double val, double a, double b){
	if(val < a) return b;
	if(val > b) return a;
	return val;
}

template<typename T, typename... U>
size_t getAddress(std::function<T(U...)> f) {
    typedef T(fnType)(U...);
    fnType ** fnPointer = f.template target<fnType*>();
    return (size_t) *fnPointer;
};

#endif