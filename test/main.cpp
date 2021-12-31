#include<iostream>
#include"../switch.hpp"
int main(){
	int x=0;
	string_switch ss;
	ss.add("set",[&]{x=0;});
	ss.add("add",[&]{x++;});
	ss.add("get",[&]{std::cout<<x<<std::endl;});
	ss.add("return0",[&]{return 0;});//:(
	ss.add("exit",[&]{exit(0);});
	std::string s;
	while(true){
		std::cin>>s;
		std::function<void(void)> f=ss.match(s);
		if(f!=nullptr)f();
	}
	return 0;
}