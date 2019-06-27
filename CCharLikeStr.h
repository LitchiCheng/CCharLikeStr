#ifndef _C_CHAR_LIKE_STR_H_
#define _C_CHAR_LIKE_STR_H_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
/* 
函数名称 	功能
构造函数 	产生或复制字符串
析构函数 	销毁字符串
=，assign 	赋以新值
Swap 	交换两个字符串的内容
+ =，append( )，push_back() 	添加字符
insert () 	插入字符
erase() 	删除字符
clear () 	移除全部字符
resize () 	改变字符数量
replace() 	替换字符
+ 	串联字符串
==，！ =，<，<=，>，>=，compare() 	比较字符串内容
size()，length() 	返回字符数量
max_size () 	返回字符的最大可能个数
empty () 	判断字符串是否为空
capacity () 	返回重新分配之前的字符容量
reserve() 	保留内存以存储一定数量的字符
[],at() 	存取单一字符
>>，getline() 	从 stream 中读取某值
<< 	将值写入 stream
copy() 	将内容复制为一个 C - string
c_str() 	将内容以 C - string 形式返回
data() 	将内容以字符数组形式返回
substr() 	返回子字符串
find() 	搜寻某子字符串或字符
begin( )，end() 	提供正向迭代器支持
rbegin()，rend() 	提供逆向迭代器支持
get_allocator() 	返回配置器
*/
#define  CHAR_MAX_LENGTH    150

class CCharLikeStr
{
private:
    char _char_arrary[CHAR_MAX_LENGTH];
public:
    CCharLikeStr();
    ~CCharLikeStr();
    void operator=(char* equal_data);
    void operator+(char* add_data);
    void append(char* append_data);
    uint16_t size();
    bool empty();
    void find();
    char* c_str();
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

void CCharLikeStr::operator=(char* equal_data){
    uint16_t equal_data_length = strlen(equal_data);
    memset(_char_arrary,0x00,CHAR_MAX_LENGTH);
    memcpy(_char_arrary,equal_data,equal_data_length);
}

void CCharLikeStr::operator+(char* add_data){
    uint16_t char_length_now = strlen(_char_arrary);
    uint16_t add_data_length = strlen(add_data);
    memcpy(_char_arrary+char_length_now,add_data,add_data_length);
}


#endif //_C_CHAR_LIKE_STR_H_