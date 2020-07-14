#include <fstream>
#include <iostream>
#include <string>

using namespace std;

int main(){
    ifstream max_path_sum_input;
    max_path_sum_input.open("MaxPathSumInput.txt");
    char line;
    int x = 0;
    std::string::size_type sz; 
    while(max_path_sum_input.get(line)){
        if(line != '\n' || line != ' ');
        x += stoi(string(1,line),&sz);
    };
    cout << x << "\n";
    max_path_sum_input.close();
    return 0;
    
}