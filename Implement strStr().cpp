#include <iostream>
using namespace std;

class Solution {
public:

  void getNext(const char* needle,int next[])
	{
		next[0]=   -1;
		int k=-1,j=0;
		while(needle[j] != '\0')
		{
			if(k!= -1 && needle[k]!= needle[j] )
				k=next[k];
			++j;++k;
			if(needle[k]== needle[j])
				next[j]=next[k];
			else
				next[j]=k;
		} 
	}

	char *strStr(char *haystack, char *needle) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function

		if( !haystack||!needle|| haystack[0]=='\0' && needle[0]!='\0' )//
			return NULL;//空指针或空串，返回-1。
		if(needle[0]=='\0')
			return haystack;
		int len=0;
		const char * c=needle;
		while(*c++!='\0')//移动指针比移动下标快。
		{    
			++len;//字符串长度。
		}
		int *next=new int[len+1];
		getNext(needle,next);//求needle的next函数值

		int index=0,i=0,j=0;
		while(haystack[i]!='\0' && needle[j]!='\0' )
		{
			if(haystack[i]== needle[j])
			{
				++i;// 继续比较后继字符
				++j;
			}
			else
			{
				index += j-next[j];
				if(next[j]!=-1)
					j=next[j];// 模式串向右移动
				else
				{
					j=0;
					++i;
				}
			}
		}//while

		delete []next;
		if(needle[j]=='\0')
			return haystack+index;// 匹配成功
		else
			return NULL;  
	}
};

void main()
{
	Solution s;
	char needle[] = "abcabcad";
	int next[8];
	//s.getNext(needle, next);

	s.strStr("a","a");
}
