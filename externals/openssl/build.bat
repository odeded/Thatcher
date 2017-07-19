call "C:\Program Files (x86)\Microsoft Visual Studio 14.0\VC\vcvarsall.bat" x86
perl Configure VC-WIN32 no-asm no-shared
ms\do_ms
nmake -f  ms\nt.mak

call "C:\Program Files (x86)\Microsoft Visual Studio 14.0\VC\vcvarsall.bat" amd64
perl Configure VC-WIN64A no-asm  no-shared
ms\do_win64a
nmake -f  ms\nt.mak
