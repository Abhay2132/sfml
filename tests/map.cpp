#include<iostream>
#include<map>
#include<string>
#include<vector>
#include<functional>

int main(){

    std::map <std::string, std::vector<std::function<void()>>> m;
    m["ABHAY"].push_back([](){std::cout<<1;});
    m["ABHAY"].push_back([](){std::cout<<1;});
    m["ABHAY"].push_back([](){std::cout<<1;});
    m["ABHAY"].push_back([](){std::cout<<1;});

    for(const auto& _ : m["ABHAY"]){
        // std::cout << mark << "\n";
        _();
    }

    return 0;
}