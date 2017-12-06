//
//  main.cpp
//
//  Created by Jeff Zhao on 11/20/17.
//  Copyright © 2017 Jeff Zhao. All rights reserved.
//

//  Crack 1-3 Remove duplicated character in a string without extra buffer
//  Design an algorithm and write code to remove the duplicate characters
//  in a string without using any additional buffer.
//  NOTE: One or two additional variables are fine. An extra copy of the array is not.
//  FOLLOW UP
//  Write the test cases for this method.

#include <iostream>
#include <string>
#include <cstring>

class Str{
  private:
    char *content;
  public:
    Str(char *);
    void showContent();
    void RmvDupl(char *);
    void selfRmvDupl() {RmvDupl(this->content);}
    void RmvDupl2(char *);
    void selfRmvDupl2() {RmvDupl2(this->content);}
};

Str::Str(char *str){
  content = str;
}

void Str::showContent(){
  std::cout << "Content is: " << this->content << std::endl;
}

void Str::RmvDupl(char *str){
  if(str == NULL)
    return;

  const int length = strlen(str);
  if(length < 2)
    return;

  int i, j;
  int tail = 1;

  // for each element i from 1 to end, check if it is duplicated with any element
  // ahead. use j to scan from the beginning to the end of tail which includes all
  // the elements already been checked and edited

  for(i = 1; i < length; i++){
    for(j = 0; j < tail; j++){
      if(str[j] == str[i])
        break;
    }
    if(j == tail){
      str[tail] = str[i];
      tail++;
    }
  }
  str[tail] = '\0';
}

// another removing method
// use a bool array to accelerate the speed
void Str::RmvDupl2(char *str){
  if(str == NULL)
    return;

  const int length = strlen(str);
  if(length < 2)
    return;

  int i;
  bool * characters = new bool[256]();
  for(i = 0; i < 256; i++)
    characters[i] = false;

  int tail = 0;             // tail of the string
  for(i = 0; i < length; i++){
    // if the scanned character is not duplicated, mark it in the bool array,
    // copy it to the tail position and increase the tail
    if(!characters[str[i]]){
      characters[str[i]] = true;
      str[tail] = str[i];
      tail++;
    }
  }
  str[tail] = '\0';
}

int main(int argc, const char * argv[]){
  char *tarstr;
  const char *defstr = "abcd";
  int inputLen;

  if(argc > 1){
    inputLen = strlen(argv[1]);
    tarstr = new char[inputLen];
    strcpy(tarstr, argv[1]);
  }
  else{
    tarstr = new char[5];
    strcpy(tarstr, defstr);
  }

  std::cout << "Target string is: " << tarstr << std::endl;
  std::cout << "Try method 1:" << std::endl;
  Str MyStr(tarstr);
  MyStr.selfRmvDupl();
  std::cout << "Execute removing..." << std::endl;
  MyStr.showContent();

  std::cout << "Try method 2:" << std::endl;
  Str MyStr2(tarstr);
  MyStr2.selfRmvDupl2();
  std::cout << "Execute removing..." << std::endl;
  MyStr2.showContent();
}
