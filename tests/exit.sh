#!/bin/sh
cd ..
bin/rshell << 'EOL'
exit
EOL

bin/rshell << 'EOL'
echo Nishanth || echo KobeByrant && echo whale && exit
EOL

bin/rshell << 'EOL'
echo Agustin && echo Aaron || echo pi 
EOL

bin/rshell << 'EOL'
echo hello || echo goodbye && exit
EOL

bin/rshell << 'EOL'
exitt && exit || echo hello 
EOL
