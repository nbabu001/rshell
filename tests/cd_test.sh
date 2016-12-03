#!/bin/bash
cd ..
bin/rshell << 'EOF'
cd
cd -
cd -
cd --
cd ..
cd .
cd - && cd -
cd bin/rshell/ src
(cd - || (cd bin/rshell && cd -))
echo cd ..
#cd -
cd #-
cd ..#.
cd exit
exit cd -
EOF