//
//  Prototypes.h
//  lab1
//
//  Created by Erica Diaciuc on 10.03.2023.
//

#ifndef Prototypes_h
#define Prototypes_h

void line_search(Video_Cards* obj, int size);
int Search_Binary(Video_Cards* obj, int left, int right, int key);
int InterpolSearch(Video_Cards* obj, int key);
int min(int x, int y);
int fibMonaccianSearch(Video_Cards* obj, int n);
void newBinTree(int val, BinTree** Tree);
int Search(BinTree* Tree, int key);


#endif /* Prototypes_h */
