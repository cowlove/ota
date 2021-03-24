#!/bin/bash 
#make csim && ./csim --seconds 20 --serial > out.txt && tail -1 out.txt | tr -s ' ' | bash -c "grep \"\$0 \$*\"" \
#19 ota.ino no-git-version 0xdeadbeef TIMESTRING 16.003056 20.003056 16.005278 1 t:0,0.000000 i2c:0 50000019
touch testexpected.out
make csim && ./csim --seconds 20 --serial > testresult.out && tail -1 testresult.out | diff - testexpected.out


