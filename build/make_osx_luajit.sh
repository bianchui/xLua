mkdir -p build_lj_osx && cd build_lj_osx
cmake -DCMAKE_CXX_STANDARD=11 -DUSING_LUAJIT=ON -DEMMY_LUA_VERSION=jit -GXcode ../
cd ..
cmake --build build_lj_osx --config Release
mkdir -p plugin_luajit/Plugins/xlua.bundle/Contents/MacOS/
cp build_lj_osx/Release/xlua.bundle/Contents/MacOS/xlua plugin_luajit/Plugins/xlua.bundle/Contents/MacOS/xlua

