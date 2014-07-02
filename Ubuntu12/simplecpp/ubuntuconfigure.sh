#/bin/sh
# SPRITE=`pwd`"/lib/libsprite.a -I"`pwd`"/include  `pkg-config --libs --cflags x11` -std=c++0x"
MAKEOPT="-I"`pwd`"/include   `pkg-config --libs --cflags x11` -std=c++0x"

rm -f makes++
echo "#!/bin/sh -x" >> makes++
echo "g++ \$@ -Wall "$MAKEOPT >> makes++
chmod +x makes++

cd src
make config
cd ..

rm -f s++

SPRITE=`pwd`"/lib/libsprite.a "$MAKEOPT

echo "#!/bin/sh -x" >> s++
$echo$ "g++ \$@ -Wall "$SPRITE >> s++
chmod +x s++

echo "To compile use: "`pwd`"/s++ filename.cpp"

