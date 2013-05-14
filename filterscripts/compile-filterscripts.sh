#!/bin/sh
# compiles $1


# 
#SCRIPT=`readlink -f "$0"`
#P=`dirname "$SCRIPT"` # $P/$0

PAWNCC="wine ../compiler/bin/pawncc.exe"
PAWNINC="../include"
#PAWNINC="D:\\dev\\projects\\pawn\\lsfr\\include"
PAWNPARAM="-v2 -t4 -;+ -i$PAWNINC -i$P/gm"

if [ "$1" = "" ]
then
  echo "No param specified" > /dev/stderr
  exit 1
fi


#FILEBASE=`basename "$1"`
FILEBASE="${1%\.*}" # file without extension
FILESRC="$1"
FILETMP="$FILEBASE.tmp"
#if [ "" = "" ]
#then
#  FILEOUT="$FILEBASE.amx"
#fi

shift 1 # $2 became $1 ltd


if [ ! -r $FILESRC ]
then
  echo "No source file found: $FILESRC" > /dev/stderr
  exit 2
fi

if [ -r $FILETMP ]
then
  rm $FILETMP
fi

#if [ -r $FILEOUT ]
#then
#  rm $FILEOUT
#fi

# PP goes here

#cp $FILESRC $FILETMP
#if [ $? -ne 0 ]
#then
#  echo "PP ERROR" > /dev/stderr
#fi

# compiling

echo "Launching compiler with params: $PAWNPARAM $* $FILESRC"
$PAWNCC $PAWNPARAM $* $FILESRC  #-o$FILEOUT

RESULT=$?

if [ $RESULT -eq 0 ]
then
  # cleanup
  #rm $FILETMP
  :
else
  echo "CC ERROR: $RESULT" > /dev/stderr
  exit $RESULT
fi



