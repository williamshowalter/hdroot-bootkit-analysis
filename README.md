Index of Suplemental Files
---------------------------------------------------

1.1 Binary Files – hdroot-bootkit-analysis/binaries
---------------------------------------------------

| File                             | Description                                                                                                                       |
|----------------------------------|-----------------------------------------------------------------------------------------------------------------------------------|
| C\_932.NLS                       | 64-bit bootkit service DLL sample, as installed                                                                                   |
| driver32.sys.bin                 | 32-bit kernel driver used by the dropper to write directly to the physical disk.                                                  |
| driver64.sys.bin                 | 64-bit signed kernel driver used by the dropper to write directly to the physical disk.                                           |
| dropper64.bin                    | 64-bit dropper sample that installs bootkit                                                                                       |
| mbr-clean.bin                    | MBR before modification, for comparison.                                                                                          |
| mbr-inst.bin                     | MBR that has been modified after install.                                                                                         |
| pe1\_decrypted.bin               | 32-bit bootkit service DLL sample, extracted and decrypted from decrypted rkimage                                                 |
| pe1\_encrypted\_b61e1dcf.bin     | 32-bit bootkit service DLL sample, extracted in original form from decrypted rkimage. XOR key is 0xb64e1dcf.                      |
| pe2\_decrypted.bin               | 64-bit bootkit service DLL sample, extracted and decrypted from decrypted rkimage                                                 |
| pe2\_encrypted\_b61e8d81.bin     | 64-bit bootkit service DLL sample, extracted in original form from decrypted rkimage. XOR key is 0xb64e8d81.                      |
| rkimage\_decrypted.bin           | rkImage sample, extracted from harddrive and decrypted.                                                                           |
| rkimage\_encrypted.bin           | rkImage sample, extracted from harddrive and decrypted.                                                                           |
| rkimage\_backdoor\_decrypted.bin | rkImage sample with example backdoor, extracted from harddrive and decrypted.                                                     |
| rkimage\_backdoor\_encrypted.bin | rkImage sample with example backdoor, extracted from harddrive. Obfuscated with 0x76 byte-XOR.                                    |
| verifier\_win7\_decrypted.bin    | verifier sample, containing the verifier sector followed by two copies of the original mbr sector.                                |
| verifier\_win7\_encrypted.bin    | Verifier sample, containing the verifier sector followed by two copies of the original mbr sector. Obfuscated with 0x76 byte-XOR. |
| verifier\_win10\_decrypted.bin   | verifier sample, containing the verifier sector followed by two copies of the original mbr sector.                                |
| verifier\_win10\_encrypted.bin   | Verifier sample, containing the verifier sector followed by two copies of the original mbr sector. Obfuscated with 0x76 byte-XOR. |

1.2 Code Files – hdroot-bootkit-analysis/code
---------------------------------------------

| File             | Description                                                                                         |
|------------------|-----------------------------------------------------------------------------------------------------|
| convert.c        | C utility to decrypt verifier and rkimage samples.                                                  |
| dll\_decryptor.c | C utility to decrypt service DLL samples with 4-byte XOR keys.                                      |
| fuzzer.py        | Simple python fuzzer to discover commands to dropper64.bin                                          |
| proof.cpp        | C++ program to install as backdoor. Writes C:\\proof.txt as evidence that bootkit ran successfully. |

1.3 Evidence Files – hdroot-bootkit-analysis/evidence
-----------------------------------------------------

| File                       | Description                                                                                                |
|----------------------------|------------------------------------------------------------------------------------------------------------|
| crc\_error.PNG             | Error message shown by check command when secondary bootkit image is modified after install.               |
| driver64\_certificate.PNG  | Screenshot of the stolen certificate used by the 64-bit kernel driver.                                     |
| driver64\_valid.PNG        | Screenshot showing that the certificate on the kernel driver has not been revoked.                         |
| dropper64\_certificate.PNG | Screenshot of the stolen certificate used by the 64-bit dropper.                                           |
| dropper64\_revoked.PNG     | Screenshot showing that the certificate on the dropper has been revoked.                                   |
| hashes\_after.txt          | Hashes taken of files after the bootkit has run on a Windows 7 virtual machine.                            |
| hashes\_before.txt         | Hashes taken of files before the bootkit has run on a Windows 7 virtual machine.                           |
| hashes\_win10.txt          | Hashes of the first and second rkImage locations on a Windows 10 virtual machine with &gt; 30% free space. |
| install\_win10.PNG         | Screenshot of installing a backdoor on Windows 10.                                                         |
| install\_win10\_cmd.PNG    | Screenshot of installing cmd.exe as the backdoor.                                                          |
| install\_win7.PNG          | Screenshot of installing a backdoor on Windows 7 with low disk space.                                      |
| installer\_cmd.txt         | The text output of installing a backdoor on Windows 10.                                                    |
| Neowiz.p7b                 | Extracted certificate used in the 64-bit kernel driver.                                                    |
| reg\_service\_after.txt    | Registry after boot, with timestamps showing it was written to, even if the values didn’t change.          |
| reg\_service\_before.txt   | Registry before rebooting, with timestamps.                                                                |
| vol\_modules.txt           | Volatility output snippet from listing modules that shows the kernel driver.                               |
| vol\_reg\_debugfile.txt    | Volatility output that shows a registry key for the DEBUGFILE service used by the kernel driver.           |

1.4 Ida Pro Files – hdroot-bootkit-analysis/ida pro
---------------------------------------------------

| File                    | Description                                                                                                                                                                                                           |
|-------------------------|-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| driver32.sys.idb        | Ida Pro file for the 32-bit kernel driver. Functionally same as the 64-bit driver.                                                                                                                                    |
| driver64.sys.idb        | Ida Pro file for the 64-bit kernel driver. Functionally same as the 32-bit driver.                                                                                                                                    |
| dropper64.i64           | Ida Pro file for the dropper sample. Largely not reversed, as the static sample is packed with VMProtect.                                                                                                             |
| mbr\_infected.idb       | Ida Pro file for the bootkit MBR. Disassembly is 16-bit.                                                                                                                                                              |
| pe1\_decrypted.idb      | Ida Pro file for the 32-bit service DLL. Functionally same as the 64-bit DLL.                                                                                                                                         |
| pe2\_decrypted.i64      | Ida Pro file for the 64-bit service DLL. Functionally same as the 32-bit DLL.                                                                                                                                         |
| rkimage\_decrypted.idb  | Ida Pro file for rkImage. Contains real mode (16-bit) and protected mode (32-bit) segments. Also has undefined data at the end because the sample disassembled was mistakenly longer than the rkimage+bootkit length. |
| verifier\_decrypted.idb | Ida Pro file for the verifier. Contains verifier and original MBR. Disassembly is 16-bit.                                                                                                                             |
