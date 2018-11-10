#!/bin/sh
TARGET=AnpanMMOServer.out
pids=(`ps -ef | grep ${TARGET} | grep -v grep | awk '{ print $2; }'`)
for pid in ${pids[*]}
do
kill -9 ${pid}
done
make depend
make
./AnpanMMOServer.out &