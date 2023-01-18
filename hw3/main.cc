#include <iostream>
#include <unistd.h>
#include <stdlib.h> 
#include <random>
#include <fstream>
#include <string>
#include <vector>
#include <filesystem>

using namespace std;
void myfunc(string word, string guess, string good, string bad,string wrong,size_t word_length){
   const int MAX_CHAR = 26;
   vector<bool> v1(MAX_CHAR,0);
   for(int i = 0; i<int(word_length);i++){
       v1[word[i]-'a'] = true;
   }
   for(int i =0; i<int(word_length);i++){
      if(v1[guess[i]-'a']==true){
	if(guess[i]==word[i]){
	  cout << good;
	}
	else{
	  cout << wrong;
	}
      }
      else{
	cout << bad;
      }
   }
}

int main(int argc, char *argv[]) {

//default value
  string good = "=", wrong = "-", bad = " ";
  size_t max_turns = 6;
  size_t word_length = 5;

  bool V_FLAG = false, T_FLAG = false,G_FLAG = false, W_FLAG = false, B_FLAG = false, length_seen = false;
  
  string program_name = argv[0];
  int o;
    while((o = getopt(argc,argv,"+vt:g:w:b:3456789") )!= -1){
        switch(o){
            case 'v':
                V_FLAG = true;
                break;

            case 't':
	        //check if true or not 
                if(T_FLAG){
                cerr << program_name << ": " <<"-t is given more than once."<<'\n';
                exit(1);

                }
                //error message check bad argument (print argument and option)
                for(int i = 0;optarg[i]!='\0';i++){
                    if(optarg[i] < '0' || optarg[i] > '9' ){
                       cerr << program_name << ": "<< optarg << " is a bad argument from option " << char(o) << '\n';
                       exit(1);
                    }
                }
                T_FLAG = true;
                max_turns = atoi(optarg);
                
                break;

            case 'g':
                if(G_FLAG){
                    cerr << program_name << ": " <<"-g is given more than once."<<'\n';
                    exit(1);
                }
                G_FLAG = true;
                good.assign(optarg);
                break;

            case 'w':
                if(W_FLAG){
                cerr << program_name << ": " <<"-w is given more than once."<<'\n';
                exit(1);
                }
                W_FLAG = true;
                wrong.assign(optarg);
                break;

            case 'b':
                if(B_FLAG){
                cerr << program_name << ": " <<"-b is given more than once."<<'\n';
                exit(1);
                }           
                B_FLAG = true;
                bad.assign(optarg);          
                break;
            case '3': case '4': case '5': case '6': case '7': case '8': case '9':
            // error check for word length  eg. ./hw3 -v -3 -4 words.txt
	            if (length_seen){
                     cerr << program_name << ": " <<"The words of the given length is given more than once."<< '\n';
                     exit(1);
                }
                length_seen = true;
	            word_length = o  - '0';

                break;
            case '?':
                cerr << program_name << ": " <<"The bad option is given."<<'\n';
                exit(1);
                break;
           
        }
    }
   
    //cout << << " " << argc <<'\n';
    if (optind >= argc) {
            cerr << program_name << ": " << "Expected arguments after options" << '\n';
            exit(1);
    }
//point to the dictionary 
    // argc -= optind - 1;
    // *argv += optind - 1;

    //cout << "testing " << max_turns << '\n';


    vector<string> v;
    random_device rd;
    string str;
    string word;
    string guess;
    // without using  (argc -= optind - 1;*argv += optind - 1;), we should initalize the value to optind
    for(int i = optind;i < argc; i++ ){
    //for(int i = 0;i < argc; i++ ){
        ifstream file (argv[i]);
            if(file.fail()){
                cerr << program_name <<" " << argv[i] << ": " <<"Fail to open the file " << '\n';
                exit(1);
            }
            // bool EMPTY_FLAG = true;
            while(getline(file,str)){
                // EMPTY_FLAG = false;
                if(str.length() == word_length){
                    v.push_back(str);
                }
            }
            // if(EMPTY_FLAG){
            //      cerr << program_name << ": " << "The file contain no word from " << argv[i] << '\n';
            //      exit(1);
            // }
    }

            // Check  if the vector contain no word length
            if(v.empty()){
                cerr << program_name << ": " <<"The dictionary file contains no words of the length " <<word_length  <<"."<<'\n';
                exit(1);
            }

            word = v[rd() % v.size()];//random word select from vector
           // cout << word << '\n';
            cout << "I am thinking of a "<<word_length <<"-letter word." <<'\n';   


            int num = 0;
  do{
      cout << "Guess: ";
      cin >> guess;
      if(guess.length() !=word_length){
	    cerr << program_name << ": " <<"The user's guess was not exactly "<< word_length << " characters long."<<'\n';
	    exit(1);
      }
      else{
	    num  +=1;
	    if (word != guess && num < int(max_turns+1)){
            if (num == int(max_turns )){
                cout<< "       ";
	            myfunc(word,guess,good,bad,wrong,word_length);
	            cout<< '\n';
       		    cout <<"You lost, the word was \""<< word <<"\"."<<'\n';
       		    break;
	            }
            else{
	            cout<< "       ";
	            myfunc(word, guess,good,bad,wrong,word_length);
	            cout<< '\n';
	            continue;
	        }
	    }
        else{
            cout<< "       ";
            myfunc(word, guess,good,bad,wrong,word_length);
            cout<< '\n';
	        cout <<"Yon won!"<<'\n';
	        break;
        }
        break;
      }
    }
  while (num<int(max_turns+1));
  //this line is only for vaiables set but not used without compiling error 
  if(V_FLAG ){
  }
      return 0;
}

