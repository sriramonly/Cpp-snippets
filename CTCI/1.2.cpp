// implement a function void reverse(char *str) in C/C++ which reverses a null terminated string

#include <iostream>
using namespace std;
void reverse(char *str) {
	if (str == '\0'){
		return;
	}
	char *end = str;
	char *reversed;

	while(*end) 
		end++;
	--end;
	char *head = end;
	while(str < end){ 
		*str++ = *end--;
	}
	//*str = '\0';
	str = head;

}

int main(){
	char s[] = "abc";
	reverse(s);
	cout <<endl<<s<<endl;
	return 0;
}
