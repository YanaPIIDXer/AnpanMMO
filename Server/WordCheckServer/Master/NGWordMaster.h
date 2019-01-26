#ifndef __NGWORDMASTER_H__
#define __NGWORDMASTER_H__

#include <map>
#include <vector>

class MySqlConnection;

struct NGWordItem
{

public:



	s32 AutoKey;
	std::string NGWord;


};

bool operator <(const NGWordItem &A, const NGWordItem &B);
bool operator >(const NGWordItem &A, const NGWordItem &B);

class NGWordMaster
{

private:

	typedef std::map<s32, NGWordItem> ItemMap;
	typedef std::map<int, ItemMap> SheetMap;

public:

	bool Load(const MySqlConnection &Connection);

	

	std::vector<NGWordItem> GetAllSheetItem(s32 SheetIndex) const;

	std::vector<NGWordItem> GetAll() const;

private:

	SheetMap Items;

};

#endif		// #ifndef __NGWORDMASTER_H__
