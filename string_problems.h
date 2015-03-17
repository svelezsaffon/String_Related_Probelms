//
// Created by santiago on 3/16/15.
//

#include <string>
#include <string.h>
#include <map>
#include <iostream>
#include <unordered_map>
#include <cstdlib>


#ifndef _STRINGS_STRING_PROBLEMS_H_
#define _STRINGS_STRING_PROBLEMS_H_

#define CHAR_TO_POS(A) A-97
#define CHAR_TO_INT(A) A-'0'


void reverse(char *text,int start,int end){

    while(start < end){
        char aux=text[start];
        text[start]=text[end];
        text[end]=aux;
        start++;
        end--;
    }

}



int stringtoint(char *number){
    int mul=1;
    int result=0;
    for(int i=strlen(number)-1;i>=0;i--){
        result+=CHAR_TO_INT(number[i])*mul;
        mul*=10;
    }

    return result;
}

void reverse_chars(char *text){

    reverse(text,0,strlen(text)-1);

    int last=0;
    for(int i=0;i<strlen(text);i++){
        if(i+1==strlen(text)){
            int where=i;
            reverse(text,last,where);
        }else if(text[i]==' '){
            int where=i-1;
            reverse(text,last,where);
            last=i+1;
        }

    }


}





void remove_chars_arrays(char *from,char *which){
    int aux[128]={0};

    for(int i=0;i<strlen(which);i++){
        aux[CHAR_TO_POS(which[i])]++;
    }

    int copypos=0;

    for(int i=0;i<strlen(from);i++){
        if(aux[CHAR_TO_POS(from[i])]==0 ){
            //if this bit is set to 0, then we have to copy it, otherwise dont copy it :)
            from[copypos]=from[i];
            copypos++;
        }
    }

    from[copypos]='\0';
}

void remove_chars(char *from,char *which){
    int aux=0;

    for(int i=0;i<strlen(which);i++){
        aux |= (1<<CHAR_TO_POS(which[i]));
    }

    int copypos=0;

    for(int i=0;i<strlen(from);i++){
        if(!(aux & 1<<CHAR_TO_POS(from[i])) ){
            //if this bit is set to 0, then we have to copy it, otherwise dont copy it :)
            from[copypos]=from[i];
            copypos++;
        }
    }

    from[copypos]='\0';
}


char first_non_reapeated_big_languages(char *text){
    char ret;

    std::unordered_map<char,int> counts;

    for(int i=0;i<strlen(text);i++){

        std::unordered_map<char,int>::iterator find=counts.find(text[i]);

        if(find==counts.end()){
            int zero=0;
            counts.insert(std::pair<char,int>(text[i],zero));
        }else{

            counts[text[i]]=counts[text[i]]+1;
        }

    }

    for(int i=0;i<strlen(text);i++){
        std::unordered_map<char,int>::iterator find2=counts.find(text[i]);

        if(find2!=counts.end()){
            if(find2->second==0){
                ret=find2->first;
                break;
            }

        }
    }


    return ret;
}

char first_non_repeated_char(char *text ){

    char ret;
    int count[26]={0};

    for(int i=0;i<strlen(text);i++){
        count[CHAR_TO_POS(text[i])]++;
    }

    for(int i=0;i<strlen(text);i++){
        if(count[CHAR_TO_POS(text[i])]==1){
            ret=text[i];
            break;
        }
    }
    return ret;

}





#endif //_STRINGS_STRING_PROBLEMS_H_
