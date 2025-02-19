#!/bin/bash
IS_WSL=$(grep Microsoft /proc/version)

if [[ -n $IS_WSL ]] 
then
    projPath=$(wslpath -a ./)
    echo $projPath
    ./tools/porymap/porymap.exe $projPath
else
    ./tools/porymap/porymap
fi