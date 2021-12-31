#include<unordered_map>
#include<string>
#include<functional>

class string_switch{
	public:
		void add(std::string s,std::function<void(void)> f){
			cases.emplace(s,f);
		}
		auto match(std::string s){
			return cases[s];
		}
	private:
		std::unordered_map<std::string,std::function<void(void)>> cases;
};