//#define TEST2_CPP 
#ifdef TEST2_CPP

#include <iostream>
#include <cstdlib>
#include <vector>
#include "User.h"
/*
此程式應該輸出以下內容
Active User: 3
Name: Enrique, IP: 127.0.0.1, Port: 443
Name: Gerardo, IP: 7.91.205.21, Port: 8080
Name: Troy, IP: unknown, Port: unknown
*/
int main() {
	std::vector<User*> users;
	users.push_back(new User("Enrique", 127, 0, 0, 1, 443));
	users.push_back(new User("Gerardo", 123456789, 8080));
	users.push_back(new User("Austyn", 987654321));
	delete users[users.size() - 1];
	users.pop_back();
	users.push_back(new User("Troy"));
	std::cout << "Active User: " << User::userCount << std::endl;
	for (int i = 0; i < users.size(); i++) {
		std::cout << *users[i] << std::endl;
	}

	system("pause");
	return 0;
}

#endif // TEST2_CPP