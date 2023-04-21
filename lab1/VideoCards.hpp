//
//  VideoCards.hpp
//  lab1
//
//  Created by Erica Diaciuc on 10.03.2023.
//

#pragma once
#ifndef VideoCards_hpp
#define VideoCards_hpp

#include <iostream>
#include <fstream>
#include <string>

class Video_Cards
{
public:
    int Product_code{0};
    std::string Name{""};
    std::string Producer{""};
    int TechnicalProcess{0};
    int EnergyConsum{0};
    float Price{0.0};
    
    void output(){
        std::cout << " " << Product_code << " " << Name << " " << Producer << " " << TechnicalProcess << " " << EnergyConsum << " " << Price;
    }
    
    void line_search(Video_Cards* obj, int size);
    
};
struct BinTree {
    int value;
    BinTree* left;
    BinTree* right;
};
//void line_searc(Video_Cards* obj, int size);
//int Search_Binary(Video_Cards* obj, int left, int right, int key);

#endif /* VideoCards_hpp */
