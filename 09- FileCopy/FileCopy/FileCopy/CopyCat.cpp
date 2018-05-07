/* Name: Russell (Chumicat) (Li-Shuo ZENG)
 * SID¡G B10332030
 * Date: Mar. 14, 2018
 * Last Update: Mar. 14, 2018
 * Version: v1.0
 * Problem statement:
 * Reference:
https://stackoverflow.com/questions/10195343/copy-a-file-in-a-sane-safe-and-efficient-way
https://stackoverflow.com/questions/12774207/fastest-way-to-check-if-a-file-exist-using-standard-c-c11-c
 */

#include <iostream>
#include <fstream>

int main(int argc, char* argv[]) {
	if (argc != 3) {
		std::cout << "[Number of argc is not correct]" << std::endl;
		return -1;
	}

	std::ifstream  src(argv[1], std::ios::binary);
	std::ofstream  dst(argv[2], std::ios::binary);

	/* Dealing in good file and bad file situation */
	if (src.good() && dst.good()){
		/* File exist, copy file */
		dst << src.rdbuf();
		src.close();
		dst.close();
		std::cout << "[File Copy Finished]" << std::endl;
	} else {
		/* File error occured, delete dst file */
		std::cout << "[File Error Detect]" << std::endl;
		src.close();
		dst.close();
		remove(argv[2]);
	}
	return 0;
}