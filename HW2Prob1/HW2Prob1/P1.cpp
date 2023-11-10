//  HW2Prob1
//
//  Created by Serin Santhosh on 10/11/23.
// Worked with Nicole Collom, Gabby Hontz, Megan O'Brien, and Cecelia Erndwein on all questions
// Also used Chatgpt to help with creating functions


// Given picture design containter that stores the following information:
// 160 mile flight btw SCE and PHL
// 640 mile flight btw SCE and ORD
// 220 mile flight btw SCE and EWR

// can be a single container or multiple (single map container used)

#include <iostream>
#include <map>

int main() {
    // insert code here...
    
    // create map to store the different locations and the miles
    
    std::map<std::string, double> miles;
    miles.insert({"PHL", 160});
    miles.insert({"ORD", 640});
    miles.insert({"EWR", 220});
    
    // cout to make sure they are properly stored...
   
    //std::cout << "PHL and SCE: " << miles["PHL"] << " miles." <<std::endl;
   // std::cout << "ORD and SCE: " << miles["ORD"] << " miles." <<std::endl;
    //std::cout << "EWR and SCE: " << miles["EWR"] << " miles." <<std::endl;
    return 0;
}
