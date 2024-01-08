#include <filesystem>
#include<iostream>
int main(){
    std::filesystem::path pwd = std::filesystem::current_path();

    std::cout<<pwd;
    return 0;
}