#!/bin/sh
cd ..
bin/rshell << 'EOL'
echo Brian Crites is a Legend
echo Amir is dope too && ls && echo jump
echo 
ls && echo hello || exit
mkdir exit && ls & echo this is a #test || && hello this is a test
echo run &&& ls || lss && echo hello 
echo run ||| echo hello
mkdir ls &&& echoo problem || echo works 
ls && echo dragonslayer || mkdir battleaxe
echo run && ls && echo jump || echo fly #dhasdj
exit
EOL