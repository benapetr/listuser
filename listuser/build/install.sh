#!/bin/sh

DEST=/

if [ "$#" -gt 0 ];then
  if [ x"$1" != x"" ];then
    DEST=$1/
  fi
fi

if [ ! -f bin/Release/listuser ];then
  echo "FATAL: You need to build listuser first"
  exit 1
fi

echo "Installing listuser to $DEST"
if [ ! -d "$DEST"usr/bin ];then
  mkdir -p "$DEST"usr/bin
fi
if [ ! -d "$DEST"usr/share/man/man1 ];then
  mkdir -p "$DEST"usr/share/man/man1
fi
cp -v bin/Release/listuser "$DEST"usr/bin/listuser || exit 1
cp -v man/listuser.1 "$DEST"usr/share/man/man1 || exit 1
gzip "$DEST"usr/share/man/man1/listuser.1 || exit 1

echo "Installed"
exit 0

