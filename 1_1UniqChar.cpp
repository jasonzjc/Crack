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

class StrCheck{
  private:
    string content;
  public:
    StrCheck(string);
    void showContent();
    bool isUnique(string);
    bool selfUnique() {return isUnique(content);}
};

StrCheck::StrCheck(string str){
  content = str;
}

void StrCheck::showContent(){
    cout << "Content is: " << this->content << endl;
}

bool StrCheck::isUnique(string str){
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
    string str = "sds";
  if (argc > 1){
    str = argv[1];
  }

  StrCheck strck(str);
  strck.showContent();
  bool result = strck.isUnique(str);
  cout << "result " << result << endl;
  bool result2 = strck.selfUnique();
  cout << "result2 " << result2 << endl;
}
