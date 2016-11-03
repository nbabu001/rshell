#!/bin/sh
cd ..
bin/rshell << 'EOF'
ls
echo This is lit
echo Dragons are in the building
echo 
ls
echo
mkdir test
ls
echo It worked
echo testing is over
EOF