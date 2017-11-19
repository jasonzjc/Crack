//
//  main.cpp
//
//  Created by Jeff Zhao on 11/17/17.
//  Copyright © 2017 Jeff Zhao. All rights reserved.
//

//  Crack 1-2 C-style string reverse
//  Write code to reverse a C-Style String.
//  (C-String means that “abcd” is represented as  ve characters,
//  including the null character.)

#include<iostream>
#include<string>
#include<cstring>

class StrRev{
  private:
    char *content;
  public:
    StrRev(char *);
    void showContent();
    void reverseCStr(char *);
    void selfReverse() {reverseCStr(content);}
};

StrRev::StrRev(char *str){
  content = str;
}

void StrRev::showContent(){
  std::cout << "Content is: " << this->content << std::endl;
}

void StrRev::reverseCStr(char *str){
  char temp;
  int i;
  const int length = strlen(str);
  for(i = 0; i < length/2; i++){
    temp = str[i];
    str[i] = str[length-i-1];
    str[length-i-1] = temp;
  }
}

int main(int argc, const char * argv[]){
  char *str;
  const char *defstr = "abcd";
  int inputLen;

  if(argc > 1){
    inputLen = strlen(argv[1]);
    str = new char[inputLen];
    strcpy(str, argv[1]);
  }
  else{
    str = new char[5];
    strcpy(str, defstr);
  }

  std::cout << "Target string is: " << str << std::endl;
  StrRev MyStr(str);
  MyStr.selfReverse();
  std::cout << "Execute reverse..." << std:: endl;
  MyStr.showContent();
}
