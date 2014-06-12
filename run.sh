#!/bin/sh
APP_DIR=`dirname "$0"`
APP_DIR=`( cd "$APP_DIR" && pwd )`
export LD_LIBRARY_PATH=$APP_DIR:$LD_LIBRARY_PATH
$APP_DIR/codeblocks $@
