#!/bin/bash
cd ..
bin/rshell << 'EOF'
test -e /binn
[test -e /bin/rshell]
test -e /bin/rshell 
test #-d /bin/rshell
[-d /bin/notreal]
test -d /bin
test -f /bin/rshell
[-f /bin/rshell/hello]
[-e /rshell/bin]
test -#e /bin/rshell
[test /bin]
EOF