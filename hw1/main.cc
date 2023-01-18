#include <iostream>
#include <random>
#include <fstream>
#include <string>
#include <vector>
#include <filesystem>

using namespace std;
void myfunc(string word, string guess){
   const int MAX_CHAR = 26;
   vector<bool> v1(MAX_CHAR,0);
   for(int i = 0; i<5;i++){
       v1[word[i]-'a'] = true;
   }
   for(int i =0; i<5;i++){
      if(v1[guess[i]-'a']==true){
	if(guess[i]==word[i]){
	  cout << "=";
	}
	else{
	  cout << "-";
	}
      }
      else{
	cout << " ";
      }
   }
}


// This is hw1 which is word guessing  
int main(int argc, char *argv[]) {
  
  //check the number of arguments
  if (argc !=2 ){
    cerr << "There was not exactly one argument given." << '\n';
    exit(1);
  }
  //check if the file exist or not
  ifstream file(argv[1]);
  if (!file){
    cerr << "The dictionary file cannot be read." << argv[1]<< '\n';
    exit(1);
  }
 
  string str;
  vector<string> v;
  random_device rd;
  std:: string word;
  std::string guess;

  
  
  while(getline(file,str)){
    if(str.length() == 5){
      v.push_back(str);
    }
  }
  // check the file if is empty
  if(v.empty()){
    cerr <<"The dictionary file contains no words."<<'\n';
    exit(1);
  }

  word = v[rd() % v.size()];//random word select from vector 
  //cout << word <<'\n';
  
  cout << "I am thinking of a 5-letter word." <<'\n';
  int num = 0;
  do{
      std::cout << "Guess: ";
      std::cin >> guess;
      if(guess.length() !=5){
	cerr << "The user's guess was not exactly five characters long."<<'\n';
	exit(1);
      }
      else{
	  num  +=1;
	  if (word != guess && num < 7){
	    
       	     if (num == 6 ){
	      cout<< "       ";
	      myfunc(word,guess);
	      cout<< '\n';
	    
       		cout <<"You lost, the word was \""<< word <<"\"."<<'\n';
       		break;
	        }
       	    else{
	      cout<< "       ";
	      myfunc(word, guess);
	      cout<< '\n';
	      continue;
	    }
	  }
	  else{
	    cout<< "       ====="<< '\n';

	    cout <<"Yon Won!"<<'\n';
	      break;
	  }
	  //	  cout <<"You lost, the word was \""<< word <<"\"."<<'\n';
	  break;
          }
  }
  while (num<7);
  return 0;
}

