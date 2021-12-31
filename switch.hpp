#include<unordered_map>
#include<string>
#include<functional>

class string_switch{
	public:
		void add(std::string s,std::function<void(void)> f){
			cases.emplace(s,f);
		}
		void add_default(std::function<void(void)> f){
			default_case=f;
		}
		auto match(std::string s){
			if(cases[s]!=nullptr)return cases[s];
			return default_case;
		}
	private:
		std::unordered_map<std::string,std::function<void(void)>> cases;
		std::function<void(void)> default_case;
};