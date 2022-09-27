#!/bin/sh
set -e
if test "$CONFIGURATION" = "Debug"; then :
  cd /Users/jinny/my6010Repo/Day18/xcode
  make -f /Users/jinny/my6010Repo/Day18/xcode/CMakeScripts/ReRunCMake.make
fi
if test "$CONFIGURATION" = "Release"; then :
  cd /Users/jinny/my6010Repo/Day18/xcode
  make -f /Users/jinny/my6010Repo/Day18/xcode/CMakeScripts/ReRunCMake.make
fi
if test "$CONFIGURATION" = "MinSizeRel"; then :
  cd /Users/jinny/my6010Repo/Day18/xcode
  make -f /Users/jinny/my6010Repo/Day18/xcode/CMakeScripts/ReRunCMake.make
fi
if test "$CONFIGURATION" = "RelWithDebInfo"; then :
  cd /Users/jinny/my6010Repo/Day18/xcode
  make -f /Users/jinny/my6010Repo/Day18/xcode/CMakeScripts/ReRunCMake.make
fi

