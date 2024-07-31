# UEFI-One-Key-Recovery
Lenovo UEFI OKR is a GUI-based backup and recovery software. You can back up all data on the partition in which Windows has been installed (usually the C: drive) to a partition of your choice (including partitions on mobile storage devices). In the event of Windows operating system getting corrupted, you can restore the system to any backup point through "System Recovery".

The Windows system will be recovered to the same state as the backup point you selected in the "System Backup". As your personal data may be damaged during the recovery, please read the information displayed on the screen carefully to prevent any unintended loss of personal data.
## Get Started
### Prerequisites
1. Download [Microsoft Visual Studio 2022 Build Tools](https://aka.ms/vs/17/release/vs_BuildTools.exe).
2. Select and Install the Required Components:
   - MSVC v142 - VS 2022 C++ x64/x86 build tools 14.40.33807 (or the latest version available).
   - Windows 11 SDK 10.0.22621.0 (or the latest version available).
   - C++ CMake tools for Windows.
3. Locate vcvarsall.bat:  
   `C:\Program Files (x86)\Microsoft Visual Studio\2022\BuildTools\VC\Auxiliary\Build\vcvarsall.bat`
4. Set Up the Environment:
   - Download [NASM for Windows](https://www.nasm.us/pub/nasm/releasebuilds/2.16.03/win64/nasm-2.16.03-win64.zip) and extract files to `C:\nasm`.
   - Download [Python for Windows](https://www.python.org/ftp/python/3.12.4/python-3.12.4-amd64.exe) and install.
   - Open a command prompt.
   - Install setuptools
     ```pip install --upgrade setuptools```
   - Configure the environment variables
     ```bat
     "C:\Program Files (x86)\Microsoft Visual Studio\2022\BuildTools\VC\Auxiliary\Build\vcvarsall.bat" x86
     set CLANG_BIN=C:\Program Files (x86)\Microsoft Visual Studio\2022\BuildTools\VC\Tools\MSVC\14.40.33807\bin\HostX64\x64\cl.exe
     set NASM_PREFIX=C:\nasm\
     set PYTHON_HOME=%USERPROFILE%\AppData\Local\Programs\Python\Python312\
     ```
### Installation
   1. Make a new directory. For example `C:\src`
   2. Clone into `C:\src`
      ```bat
      cd /d C:\src
      git clone https://github.com/tianocore/edk2
      git clone https://github.com/tianocore/edk2-libc
      git clone https://github.com/loonpn/UEFI-One-Key-Recovery
      cd edk2
      git submodule update --init
      ```
   3. Build EDK2 Base Tools
      ```bat
      edksetup.bat ForceRebuild
      ```
   4. Build UEFI One Key Recovery
      ```bat
      set PACKAGES_PATH=C:\src\edk2;C:\src\edk2-libc;C:\src\UEFI-One-Key-Recovery;
      set OKRPKG_PATH=C:\src\UEFI-One-Key-Recovery
      cd /d C:\src\edk2
      call edksetup.bat
      Build -t VS2022 -a X64 -p %OKRPKG_PATH%\OkrPkg\OkrPkg.dsc -m %OKRPKG_PATH%\OkrPkg\okr.inf -b RELEASE
      ```
## Acknowledgments
- [tianocore/edk2: EDK II](https://github.com/tianocore/edk2)
- [tianocore/edk2-libc: Port of libc to EDK II with applications that depend on libc](https://github.com/tianocore/edk2-libc)
- [Lenovo UEFI One Key Recovery Open Source Code](https://support.lenovo.com/us/en/downloads/ds502005-lenovo-uefi-one-key-recovery-open-source-code-thinkcentre)
