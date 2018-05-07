#define TEST3_CPP 
#ifdef TEST3_CPP

#include <iostream>
#include <cstdlib>
#include <vector>
#include "User.h"
/*
此程式應該輸出以下內容
Active User: 4
Name: Enrique, IP: 127.0.0.1, Port: 443
Name: Enrique, IP: 127.0.0.1, Port: 443
Name: Austyn, IP: 58.222.104.177, Port: unknown
Name: Troy, IP: unknown, Port: unknown
*/
int main() {
	std::vector<User> users;
	users.push_back(User("Enrique", 127, 0, 0, 1, 443));
	users.push_back(User("Enrique", 127, 0, 0, 1, 443));
	users.push_back(User("Gerardo", 123456789, 8080));
	users.pop_back();
	users.push_back(User("Austyn", 987654321));
	users.push_back(User("Troy"));
	std::cout << "Active User: " << User::userCount << std::endl;
	for (int i = 0; i < users.size(); i++) {
		std::cout << users[i] << std::endl;
	}

	system("pause");
	return 0;
}

#endif // #TEST3_CPP