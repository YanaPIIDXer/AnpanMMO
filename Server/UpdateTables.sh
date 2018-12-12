#! /bin/bash

if [ $# -ne 2 ]; then
	echo "UpdateTables.sh Needs 2 Args."
	exit 1
fi

mysqldump -u $1 -p$2 -t AnpanMMO > Tmp.sql
mysql -u $1 -p$2 -D AnpanMMO < AnpanMMO.sql
mysql -u $1 -p$2 -D AnpanMMO < Tmp.sql
rm -rf Tmp.sql
