#!/bin/bash
readonly THIS_DIR="$( cd "$(dirname "$0")" ; pwd -P )"

pushd $THIS_DIR/build
  ./make_android_luajit_arm64.sh
  ./make_ios_luajit.sh
  ./make_osx_luajit.sh
popd
