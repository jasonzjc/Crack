//
//  main.cpp
//
//  Created by Jeff Zhao on 11/07/17.
//  Copyright © 2017 Jeff Zhao. All rights reserved.
//

//  Crack 1-1 Unique Characters
//  Implement an algorithm to determine if a string has all unique characters.
//  What if you can not use additional data structures?

#include<iostream>
#include<string>

using namespace std;

class CheckString{
    string content;
  public:
    bool isUnique(str);
}

bool isUnique(string str){
  bool * characters = new bool[256]();
  for (int i = 0; i < str.length(); i++){
    if (characters[str[i]-'a']){
      delete [] characters;
      return false;
    }
    characters[str[i]-'a'] = true;
  }
  delete [] characters;
  return true;
}

int main(int argc, const char * argv[]){
  string str = "";
  bool result = isUnique(str);
  cout << "result " << result << endl;
}
