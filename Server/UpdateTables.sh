#! /bin/bash

if [ $# -ne 2 ]; then
	echo "�������Q�K�v�ł��B"
	exit 1
fi

mysqldump -u $1 -p$2 -t AnpanMMO > Tmp.sql
mysql -u $1 -p$2 -D AnpanMMO < AnpanMMO.sql
mysql -u $1 -p$2 -D AnpanMMO < Tmp.sql
rm -rf Tmp.sql
