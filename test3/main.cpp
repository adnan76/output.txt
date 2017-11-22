#include<iostream>
#include<fstream>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

using namespace std;

int isKeyword(char buffer[]){

    char keywords[50][10] = {"auto","break","case","char","const","continue","default",
                            "do","double","else","enum","extern","float","for","goto",
                            "if","int","long","register","return","short","signed",
                            "sizeof","static","struct","switch","typedef","union",
                            "unsigned","void","volatile","while","main","void","cout"};

    int i, flag = 0;

    for(i = 0; i < 32; ++i){
        if(strcmp(keywords[i], buffer) == 0){
            flag = 1;
            break;
        }
    }

    return flag;
}

int main(){
    char ch, buffer[15], operators[] = "+-*/%=><";

    ifstream fin("input.txt");
    ofstream fot("output.txt");
    int i,j=0;

    if(!fin.is_open()){
        cout<<"error while opening the file\n";
        exit(0);
    }

    while(!fin.eof()){
           ch = fin.get();

        for(i = 0; i < 6; ++i){
               if(ch == operators[i])
                   cout<<ch<<" is operator\n";

           }
// fot <<ch<<" is operator"<<endl;

           if(isalnum(ch)){
               buffer[j++] = ch;
           }
           else if((ch == ' ' || ch == '\n') && (j != 0)){
                   buffer[j] = '\0';
                   j = 0;

                   if(isKeyword(buffer) == 1){
                       cout<<buffer<<" is keyword\n";
                     //  fot <<buffer<<" is keyword\n"<<endl;
           }
                   else {
                       cout<<buffer<<" is variable\n";

                       }
                        fot <<buffer<<" is keyword\n"<<endl;
           }

    }
    fot.close();
    fin.close();

         return 0;
}
