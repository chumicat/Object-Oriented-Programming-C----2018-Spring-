/* Name: Russell (Chumicat) (Li-Shuo ZENG)
 * SID： B10332030
 * Date: May. 23, 2018
 * Last Update: May. 23, 2018
 * Version: v1.0
 * Problem statement: ClassInhenitance
 * Reference:
 */

#include "email.h"

Email::Email(const string & body, const string & sender, const string & recipient, const string & title) : sender(sender), recipient(recipient), title(title)
{
	text = body;
}

Email & Email::operator=(const Email &e)
{
	this->sender = e.sender;
	this->recipient = e.recipient;
	this->title = e.title;
	this->text = e.text;
	return *this;
}
