#! /bin/sh
cat /proc/cpuinfo | grep "ARM926EJ-S"
if [ $? == 0 ];then
    export LD_LIBRARY_PATH=$PWD/extlib/arm:$PWD/guicore/lib/libmx27
else
    export LD_LIBRARY_PATH=$PWD/guicore/lib/libpc
fi

echo $LD_LIBRARY_PATH
./ctx2000 -m plugin -c . -vvvvv

