#!/bin/bash
cd ..
bin/rshell << 'EOF'
(echo jump || ls) && echo test
(test -e /bin/nofile || echo bye) && mkdir test 
(echo hello && (echo no || echo yes)) && echo this is a test
( ([-f /bin/rshell] || echo no) && echo hello) && (ls && mkdir test) || echo no
echo hello && (ls blah)|| test -d /bin/rshell
echo ()
(echo)
(#hello) && echo no
((echo #nothing && echo hi ) || (echo new 3 && ls #nothing)) && echo this should work
(((echo hello || echo no) || #(echo C && echo D)) && echo good)
(((echo A || echo B) || (exit)) && [/bin/rshell])
(echo hi && ()) && exit
exit
EOF