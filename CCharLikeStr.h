#ifndef _C_CHAR_LIKE_STR_H_
#define _C_CHAR_LIKE_STR_H_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#define  CHAR_MAX_LENGTH    150

class CCharLikeStr
{
private:
    char _char_arrary[CHAR_MAX_LENGTH];
public:
    CCharLikeStr();
    ~CCharLikeStr();
    CCharLikeStr operator=(char* equal_data);
    CCharLikeStr operator+(char* add_data);
    void append(char* append_data);
    void push_back(char* append_data){append(append_data);}
    uint16_t size();
    uint16_t length(){return size();}
    bool empty();
    void clear(){memset(_char_arrary,0x00,CHAR_MAX_LENGTH);}
    bool find(char* find_data);
    char* c_str();
    void erase(char* erase_data);
    void insert(char* insert_data, uint8_t postion);
};

CCharLikeStr::CCharLikeStr()
{
    memset(_char_arrary, 0x00, CHAR_MAX_LENGTH);
}

CCharLikeStr::~CCharLikeStr()
{
}

void CCharLikeStr::append(char* append_data){
    uint16_t char_length_now = strlen(_char_arrary);
    uint16_t append_data_length = strlen(append_data);
    if(CHAR_MAX_LENGTH-char_length_now <= 0){
        //return -1;
    }else if(CHAR_MAX_LENGTH-char_length_now < append_data_length){
        //
    }else{
        memcpy(_char_arrary+char_length_now,append_data,append_data_length);
    }
}

char* CCharLikeStr::c_str(){
    return _char_arrary;
}

uint16_t CCharLikeStr::size(){
    return strlen(_char_arrary);
}

bool CCharLikeStr::empty(){
    return (strlen(_char_arrary) > 0) ? true : false; 
}

CCharLikeStr CCharLikeStr::operator=(char* equal_data){
    uint16_t equal_data_length = strlen(equal_data);
    memset(_char_arrary,0x00,CHAR_MAX_LENGTH);
    memcpy(_char_arrary,equal_data,equal_data_length);
}

CCharLikeStr CCharLikeStr::operator+(char* add_data){
    uint16_t char_length_now = strlen(_char_arrary);
    uint16_t add_data_length = strlen(add_data);
    memcpy(_char_arrary+char_length_now,add_data,add_data_length);
}

bool CCharLikeStr::find(char* find_data){
    uint8_t index = 0;
    uint8_t cpy_size = strlen(find_data);
    uint8_t char_length_now = strlen(_char_arrary);
    uint8_t size_diff = char_length_now - cpy_size;
    if(size_diff < 0){
        return false;
    }
    char* temp_data = new char[cpy_size+1];
    temp_data[cpy_size] = '\0';
    for(int i=0;i<size_diff;i++){
        memcpy(temp_data,_char_arrary + i,cpy_size);
        if(strcmp(temp_data,find_data) == 0){
            delete []temp_data;
            return true;
        }    
    }
    delete []temp_data;
    return false;
}

void CCharLikeStr::erase(char* erase_data){
    if(find(erase_data)){
        
    }
}

#endif //_C_CHAR_LIKE_STR_H_
