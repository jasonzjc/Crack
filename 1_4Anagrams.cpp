//
//  main.cpp
//
//  Created by Jeff Zhao on 11/05/17.
//  Copyright © 2017 Jeff Zhao. All rights reserved.
//

//  Crack 1-4 Write a method to decide if two strings are anagrams or not.

#include <iostream>
#include <string>
#include <cstring>

class Str{
  private:
    std::string content;
  public:
    Str(std::string);
    void showContent();
    bool anagrams(std::string, std::string);
    bool selfRmvDupl(std::string str2) {return anagrams(this->content, str2);}
};

Str::Str(std::string str){
  content = str;
}

void Str::showContent(){
  std::cout << "Content is: " << this->content << std::endl;
}

// decide if two strings are anagrams or not
// use two arrays with fixed size to record the characters in each string
bool Str::anagrams(std::string str1, std::string str2){
  if(str1.length() != str2.length())
    return false;

  if(str1.empty() && str2.empty())
    return true;

  int * characters = new int[256]();
  for(int i = 0; i < 256; i++)
    characters[i] = 0;

  for(int i = 0; i < str1.length(); i++){
    // if the scanned character is not duplicated, mark it in the bool array,
    // copy it to the tail position and increase the tail
    characters[str1[i]]++;
    characters[str2[i]]--;
  }

  for(int i = 0; i < 256; i++){
    if(characters[i])
      return false;
  }
  return true;
}

int main(int argc, const char * argv[]){
  std::string str1, str2;
  std::string defstr = "abcd";
  bool result;

  if(argc > 2){
    str1 = argv[1];
    str2 = argv[2];
  }
  else if(argc == 2){
    str1 = argv[1];
    str2 = defstr;
  }
  else
    std::cout << "Not Enough Arguments: Need at least two arguments (strings) to compare." << std::endl;

  std::cout << "String1 is: " << str1 << std::endl;
  std::cout << "String2 is: " << str2 << std::endl;

  Str MyStr(str1);
  result = MyStr.anagrams(str1, str2);

  if(result)
    std::cout << "They are anagrams." << std::endl;
  else
    std::cout << "They are not anagrams." << std::endl;

  return(1);
}
