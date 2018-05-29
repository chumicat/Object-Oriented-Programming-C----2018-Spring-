/* Name: Russell (Chumicat) (Li-Shuo ZENG)
 * SID： B10332030
 * Date: May. 23, 2018
 * Last Update: May. 23, 2018
 * Version: v1.0
 * Problem statement: ClassInhenitance
 * Reference:
 */

#include "file.h"

File::File(const string & body, const string & pathname) : pathname(pathname)
{
	text = body;
}

void File::setPathname(const string &s)
{
	this->pathname = s;
}

string File::getPathname() const
{
	return this->pathname;
}
