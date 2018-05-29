/* Name: Russell (Chumicat) (Li-Shuo ZENG)
 * SID： B10332030
 * Date: May. 23, 2018
 * Last Update: May. 23, 2018
 * Version: v1.0
 * Problem statement: ClassInhenitance
 * Reference:
 */

#include "document.h"

string Document::setText(const string &s)
{
	return text = s;
}

string Document::getText() const
{
	return text;
}

Document & Document::operator=(const Document &d)
{
	this->text = d.text;
	return *this;
}

bool ContainsKeyword(const Document & d, const string & searchTarget)
{
	return d.getText().find(searchTarget) != -1;
}
