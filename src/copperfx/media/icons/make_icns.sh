#!/bin/bash

mkdir copperfx_icon.iconset

sips -z 16 16 ./copperfx_icon.png  --out copperfx_icon.iconset/icon_16x16.png
sips -z 32 32 ./copperfx_icon.png  --out copperfx_icon.iconset/icon_16x16@2x.png
sips -z 32 32 ./copperfx_icon.png  --out copperfx_icon.iconset/icon_32x32.png
sips -z 64 64 ./copperfx_icon.png  --out copperfx_icon.iconset/icon_32x32@2x.png
sips -z 128 128 ./copperfx_icon.png  --out copperfx_icon.iconset/icon_128x128.png
sips -z 256 256 ./copperfx_icon.png  --out copperfx_icon.iconset/icon_128x128@2x.png
sips -z 256 256 ./copperfx_icon.png  --out copperfx_icon.iconset/icon_256x256.png
sips -z 512 512 ./copperfx_icon.png  --out copperfx_icon.iconset/icon_256x256@2x.png

iconutil -c icns copperfx_icon.iconset
rm -R copperfx_icon.iconset