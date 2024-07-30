@call "..\edksetup.bat"
Build -t VS2022 -a X64 -p OkrPkg\OkrPkg.dsc -m OkrPkg\okr.inf -b RELEASE

rem pause
;copy /b ..\Build\OkrPkg\RELEASE_VS2022\X64\OkrPkg\okr\OUTPUT\okrefi.efi ..\Build\NT32X64\RELEASE_VS2022x86\X64 /y
copy /b ..\Build\OkrPkg\RELEASE_VS2022\X64\OkrPkg\okr\OUTPUT\okrefi.efi ..\Build\OkrPkg\RELEASE_VS2022\X64\OkrPkg\okr\OUTPUT\lenovookr.efi /y
copy /b ..\Build\OkrPkg\RELEASE_VS2022\X64\OkrPkg\okr\OUTPUT\okrefi.efi ..\Build\OkrPkg\RELEASE_VS2022\X64\lenovookr.efi /y


