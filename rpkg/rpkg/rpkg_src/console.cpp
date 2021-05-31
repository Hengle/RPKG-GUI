#include "console.h"
#include "global.h"
#include <iostream>
#include <iomanip>
#include <sstream>

#ifdef _WIN64
#include <io.h>
#else
#include <unistd.h>
#define _isatty isatty
#define _fileno fileno
#endif

int console::update_console(std::string& message, uint64_t indexMax, uint64_t index, std::chrono::time_point<std::chrono::high_resolution_clock> start_time, int stringstream_length)
{
    std::chrono::time_point end_time = std::chrono::high_resolution_clock::now();
    double timeInSecondsFromstart_time = (0.000000001 * std::chrono::duration_cast<std::chrono::nanoseconds>(end_time - start_time).count());

    double percent = ((double)index / (double)indexMax) * 100.0;
    std::stringstream ss;
    ss << message << std::fixed << std::setprecision(1) << percent << "% Done" << " in " << timeInSecondsFromstart_time << "s, estimated completion in " << (timeInSecondsFromstart_time / (double)index) * (indexMax - index) << "s";

    percent_progress = (uint32_t)percent;

    if (ss.str().length() > stringstream_length)
    {
        stringstream_length = (int)ss.str().length();
    }

    timing_string = ss.str();

    if (_isatty(_fileno(stdout)))
    {
        LOG_NO_ENDL("\r" << ss.str() << std::string((stringstream_length - ss.str().length()), ' ') << std::flush);
    }

    return stringstream_length;
}

void console::display_usage_info()
{
    LOG("LICENSE for rpkg:");
    LOG("");
    LOG("RPKG");
    LOG("Copyright (c) 2020+, REDACTED");
    LOG("All rights reserved.");
    LOG("");
    LOG("Redistribution and use in source and binary forms, with or without modification,");
    LOG("are permitted provided that the following conditions are met:");
    LOG("");
    LOG("* Redistributions of source code must retain the above copyright notice, this");
    LOG("  list of conditions and the following disclaimer.");
    LOG("");
    LOG("* Redistributions in binary form must reproduce the above copyright notice, this");
    LOG("  list of conditions and the following disclaimer in the documentation and/or");
    LOG("  other materials provided with the distribution.");
    LOG("");
    LOG("THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS \"AS IS\" AND");
    LOG("ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED");
    LOG("WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE");
    LOG("DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR");
    LOG("ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES");
    LOG("(INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;");
    LOG("LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON");
    LOG("ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT");
    LOG("(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS");
    LOG("SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.");
    LOG("");
    LOG("");
    LOG("");
    LOG("LICENSE for ww2ogg:");
    LOG("");
    LOG("Copyright (c) 2002, Xiph.org Foundation");
    LOG("Copyright (c) 2009-2016, Adam Gashlin");
    LOG("");
    LOG("Redistribution and use in source and binary forms, with or without");
    LOG("modification, are permitted provided that the following conditions");
    LOG("are met:");
    LOG("");
    LOG("- Redistributions of source code must retain the above copyright");
    LOG("notice, this list of conditions and the following disclaimer.");
    LOG("");
    LOG("- Redistributions in binary form must reproduce the above copyright");
    LOG("notice, this list of conditions and the following disclaimer in the");
    LOG("documentation and/or other materials provided with the distribution.");
    LOG("");
    LOG("- Neither the name of the Xiph.org Foundation nor the names of its");
    LOG("contributors may be used to endorse or promote products derived from");
    LOG("this software without specific prior written permission.");
    LOG("");
    LOG("THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS");
    LOG("``AS IS\'\' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT");
    LOG("LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR");
    LOG("A PARTICULAR PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE FOUNDATION");
    LOG("OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,");
    LOG("SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT");
    LOG("LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,");
    LOG("DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY");
    LOG("THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT");
    LOG("(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE");
    LOG("OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.");
    LOG("");
    LOG("");
    LOG("");
    LOG("LICENSE for Costura Fody:");
    LOG("");
    LOG("The MIT License");
    LOG("");
    LOG("Copyright (c) 2012 Simon Cropp and contributors");
    LOG("");
    LOG("Permission is hereby granted, free of charge, to any person obtaining a copy");
    LOG("of this software and associated documentation files (the \"Software\"), to deal");
    LOG("in the Software without restriction, including without limitation the rights");
    LOG("to use, copy, modify, merge, publish, distribute, sublicense, and/or sell");
    LOG("copies of the Software, and to permit persons to whom the Software is");
    LOG("furnished to do so, subject to the following conditions:");
    LOG("");
    LOG("The above copyright notice and this permission notice shall be included in");
    LOG("all copies or substantial portions of the Software.");
    LOG("");
    LOG("THE SOFTWARE IS PROVIDED \"AS IS\", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR");
    LOG("IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,");
    LOG("FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE");
    LOG("AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER");
    LOG("LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,");
    LOG("OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN");
    LOG("THE SOFTWARE.");
    LOG("");
    LOG("");
    LOG("");
    LOG("LICENSE for json:");
    LOG("");
    LOG("MIT License ");
    LOG("");
    LOG("Copyright (c) 2013-2021 Niels Lohmann");
    LOG("");
    LOG("Permission is hereby granted, free of charge, to any person obtaining a copy");
    LOG("of this software and associated documentation files (the \"Software\"), to deal");
    LOG("in the Software without restriction, including without limitation the rights");
    LOG("to use, copy, modify, merge, publish, distribute, sublicense, and/or sell");
    LOG("copies of the Software, and to permit persons to whom the Software is");
    LOG("furnished to do so, subject to the following conditions:");
    LOG("");
    LOG("The above copyright notice and this permission notice shall be included in all");
    LOG("copies or substantial portions of the Software.");
    LOG("");
    LOG("THE SOFTWARE IS PROVIDED \"AS IS\", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR");
    LOG("IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,");
    LOG("FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE");
    LOG("AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER");
    LOG("LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,");
    LOG("OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE");
    LOG("SOFTWARE.");
    LOG("");
    LOG("");
    LOG("");
    LOG("LICENSE for lz4:");
    LOG("");
    LOG("LZ4 Library");
    LOG("Copyright (c) 2011-2020, Yann Collet");
    LOG("All rights reserved.");
    LOG("");
    LOG("Redistribution and use in source and binary forms, with or without modification,");
    LOG("are permitted provided that the following conditions are met:");
    LOG("");
    LOG("* Redistributions of source code must retain the above copyright notice, this");
    LOG("  list of conditions and the following disclaimer.");
    LOG("");
    LOG("* Redistributions in binary form must reproduce the above copyright notice, this");
    LOG("  list of conditions and the following disclaimer in the documentation and/or");
    LOG("  other materials provided with the distribution.");
    LOG("");
    LOG("THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS \"AS IS\" AND");
    LOG("ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED");
    LOG("WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE");
    LOG("DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR");
    LOG("ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES");
    LOG("(INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;");
    LOG("LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON");
    LOG("ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT");
    LOG("(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS");
    LOG("SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.");
    LOG("");
    LOG("");
    LOG("");
    LOG("LICENSE for MahApps.Metro:");
    LOG("");
    LOG("MIT License");
    LOG("");
    LOG("Copyright (c) .NET Foundation and Contributors. All rights reserved.");
    LOG("");
    LOG("Permission is hereby granted, free of charge, to any person obtaining a copy");
    LOG("of this software and associated documentation files (the \"Software\"), to deal");
    LOG("in the Software without restriction, including without limitation the rights");
    LOG("to use, copy, modify, merge, publish, distribute, sublicense, and/or sell");
    LOG("copies of the Software, and to permit persons to whom the Software is");
    LOG("furnished to do so, subject to the following conditions:");
    LOG("");
    LOG("The above copyright notice and this permission notice shall be included in all");
    LOG("copies or substantial portions of the Software.");
    LOG("");
    LOG("THE SOFTWARE IS PROVIDED \"AS IS\", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR");
    LOG("IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,");
    LOG("FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE");
    LOG("AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER");
    LOG("LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,");
    LOG("OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE");
    LOG("SOFTWARE.");
    LOG("");
    LOG("");
    LOG("");
    LOG("LICENSE for ogg:");
    LOG("");
    LOG("Copyright (c) 2002, Xiph.org Foundation");
    LOG("");
    LOG("Redistribution and use in source and binary forms, with or without");
    LOG("modification, are permitted provided that the following conditions");
    LOG("are met:");
    LOG("");
    LOG("- Redistributions of source code must retain the above copyright");
    LOG("notice, this list of conditions and the following disclaimer.");
    LOG("");
    LOG("- Redistributions in binary form must reproduce the above copyright");
    LOG("notice, this list of conditions and the following disclaimer in the");
    LOG("documentation and/or other materials provided with the distribution.");
    LOG("");
    LOG("- Neither the name of the Xiph.org Foundation nor the names of its");
    LOG("contributors may be used to endorse or promote products derived from");
    LOG("this software without specific prior written permission.");
    LOG("");
    LOG("THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS");
    LOG("``AS IS\'\' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT");
    LOG("LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR");
    LOG("A PARTICULAR PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE FOUNDATION");
    LOG("OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,");
    LOG("SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT");
    LOG("LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,");
    LOG("DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY");
    LOG("THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT");
    LOG("(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE");
    LOG("OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.");
    LOG("");
    LOG("");
    LOG("");
    LOG("LICENSE for Ookii Dialogs:");
    LOG("");
    LOG("BSD 3-Clause License");
    LOG("");
    LOG("Copyright (c) C. Augusto Proiete 2018-2021");
    LOG("Copyright (c) Sven Groot         2009-2018");
    LOG("All rights reserved.");
    LOG("");
    LOG("Redistribution and use in source and binary forms, with or without");
    LOG("modification, are permitted provided that the following conditions are met:");
    LOG("");
    LOG("1. Redistributions of source code must retain the above copyright notice, this");
    LOG("   list of conditions and the following disclaimer.");
    LOG("");
    LOG("2. Redistributions in binary form must reproduce the above copyright notice,");
    LOG("   this list of conditions and the following disclaimer in the documentation");
    LOG("   and/or other materials provided with the distribution.");
    LOG("");
    LOG("3. Neither the name of the copyright holder nor the names of its");
    LOG("   contributors may be used to endorse or promote products derived from");
    LOG("   this software without specific prior written permission.");
    LOG("");
    LOG("THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS \"AS IS\"");
    LOG("AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE");
    LOG("IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE");
    LOG("DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE");
    LOG("FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL");
    LOG("DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR");
    LOG("SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER");
    LOG("CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,");
    LOG("OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE");
    LOG("OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.");
    LOG("");
    LOG("");
    LOG("");
    LOG("LICENSE for revorb:");
    LOG("");
    LOG("REVORB - Recomputes page granule positions in Ogg Vorbis files.");
    LOG("version 0.2 (2008/06/29)");
    LOG("");
    LOG("Copyright (c) 2008, Jiri Hruska <jiri.hruska@fud.cz>");
    LOG("");
    LOG("Permission to use, copy, modify, and/or distribute this software for any");
    LOG("purpose with or without fee is hereby granted, provided that the above");
    LOG("copyright notice and this permission notice appear in all copies.");
    LOG("");
    LOG("THE SOFTWARE IS PROVIDED \"AS IS\" AND THE AUTHOR DISCLAIMS ALL WARRANTIES");
    LOG("WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF");
    LOG("MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR");
    LOG("ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES");
    LOG("WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN");
    LOG("ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF");
    LOG("OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.");
    LOG("");
    LOG("");
    LOG("");
    LOG("LICENSE for vorbis:");
    LOG("");
    LOG("Copyright (c) 2002-2020 Xiph.org Foundation");
    LOG("");
    LOG("Redistribution and use in source and binary forms, with or without");
    LOG("modification, are permitted provided that the following conditions");
    LOG("are met:");
    LOG("");
    LOG("- Redistributions of source code must retain the above copyright");
    LOG("notice, this list of conditions and the following disclaimer.");
    LOG("");
    LOG("- Redistributions in binary form must reproduce the above copyright");
    LOG("notice, this list of conditions and the following disclaimer in the");
    LOG("documentation and/or other materials provided with the distribution.");
    LOG("");
    LOG("- Neither the name of the Xiph.org Foundation nor the names of its");
    LOG("contributors may be used to endorse or promote products derived from");
    LOG("this software without specific prior written permission.");
    LOG("");
    LOG("THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS");
    LOG("``AS IS\'\' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT");
    LOG("LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR");
    LOG("A PARTICULAR PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE FOUNDATION");
    LOG("OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,");
    LOG("SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT");
    LOG("LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,");
    LOG("DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY");
    LOG("THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT");
    LOG("(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE");
    LOG("OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.");
    LOG("");
    LOG("");
    LOG("");
    LOG("LICENSE for SharpCompress:");
    LOG("");
    LOG("The MIT License (MIT)");
    LOG("");
    LOG("Copyright (c) 2014  Adam Hathcock");
    LOG("");
    LOG("Permission is hereby granted, free of charge, to any person obtaining a copy");
    LOG("of this software and associated documentation files (the \"Software\"), to deal");
    LOG("in the Software without restriction, including without limitation the rights");
    LOG("to use, copy, modify, merge, publish, distribute, sublicense, and/or sell");
    LOG("copies of the Software, and to permit persons to whom the Software is");
    LOG("furnished to do so, subject to the following conditions:");
    LOG("");
    LOG("The above copyright notice and this permission notice shall be included in");
    LOG("all copies or substantial portions of the Software.");
    LOG("");
    LOG("THE SOFTWARE IS PROVIDED \"AS IS\", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR");
    LOG("IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,");
    LOG("FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE");
    LOG("AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER");
    LOG("LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,");
    LOG("OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN");
    LOG("THE SOFTWARE.");
    LOG("");
    LOG("");
    LOG("");
    LOG("rpkg-cli v2.01 - Works with RPKGv1 (GKPR) and RPKGv2 (2KPR) files.");
    LOG("--------------------------------------------------------------------------------");
    LOG("Note: All the information used to build this program was gleaned");
    LOG("      in a completely 'clean room' environment.");
    LOG("--------------------------------------------------------------------------------");
    LOG("Usage:" << std::endl);
    LOG("  Drag And Drop Options:");
    LOG("    - RPKG files can be dragged and dropped directly onto the rpkg.exe file.");
    LOG("        This causes rpkg.exe to automatically enter RPKG extraction mode and");
    LOG("        will fully extract all the hash files/resources from each RPKG dragged");
    LOG("        and dropped upon rpkg.exe. It mimics (-extract_from_rpkg) in behaviour.");
    LOG("        One or more RPKG files can be dragged and dropped onto rpkg.exe at a time.");
    LOG("    - rpkg.exe command JSON files can be dragged and dropped onto the rpkg.exe file.");
    LOG("        This causes rpkg.exe to automatically enter rpkg.exe command JSON mode and");
    LOG("        will import, parse, and run all the commands listed in the input JSON file.");
    LOG("        One or more JSON files can be dragged and dropped onto rpkg.exe at a time." << std::endl);
    LOG("  Command Line Options:");
    LOG("    -compute_ioi_hash <string>");
    LOG("        Computes the IOI style truncated md5 hash/runtimeid from a string.");
    LOG("    -decrypt_packagedefinition_thumbs <path to file>");
    LOG("        Decrypts packagedefinitions.txt / thumbs.dat files.");
    LOG("    -encrypt_packagedefinition_thumbs <path to file>");
    LOG("        Encrypts packagedefinitions.txt / thumbs.dat files.");
    LOG("    -extract_direct_hash_depends <path to folder containing RPKG files>");
    LOG("        Lists and extracts the forward depends of a given hash file/resource.");
    LOG("        Scans a directory, commonly Hitman's Runtime dir, and imports and");
    LOG("        scans all available RPKG files for dependency information.");
    LOG("    -extract_from_rpkg <path to rpkg file>");
    LOG("        Extracts all hash linked files/resources from an RPKG file.");
    LOG("    -extract_ores_from <path to folder containing RPKG files>");
    LOG("        Extracts all hash linked files/resources located in the ORES files");
    LOG("        by their full IOI path names from all the RPKG files in a given directory.");
    LOG("    -extract_wwem_to_ogg_from <path to folder containing RPKG files>");
    LOG("        Extracts all hash linked files/resources of type WWEM to their");
    LOG("        full IOI internal Wwise file paths / names. It also converts");
    LOG("        the WWES (*.wem) files directly to *.ogg files for easy listening.");
    LOG("    -extract_wwes_to_ogg_from <path to folder containing RPKG files>");
    LOG("        Extracts all hash linked files/resources of type WWES to their");
    LOG("        full IOI internal Wwise file paths / names. It also converts");
    LOG("        the WWES (*.wem) files directly to *.ogg files for easy listening.");
    LOG("    -extract_wwev_to_ogg_from <path to folder containing RPKG files>");
    LOG("        Extracts all hash linked files/resources of type WWEV to their");
    LOG("        partial IOI internal Wwise file paths / names. It also converts");
    LOG("        the WWEV (*.wem) files directly to *.ogg files for easy listening.");
    LOG("    -extract_dlge_to_json_from <path to folder containing RPKG files>");
    LOG("        Extracts all hash linked files/resources of type DLGE from");
    LOG("        all the RPKG files in a given directory and then decrypts");
    LOG("        them in memory and outputs / formats them as JSON files.");
    LOG("    -extract_locr_to_json_from <path to folder containing RPKG files>");
    LOG("        Extracts all hash linked files/resources of type LOCR from");
    LOG("        all the RPKG files in a given directory and then decrypts");
    LOG("        them in memory and outputs / formats them as JSON files.");
    LOG("    -extract_rtlv_to_json_from <path to folder containing RPKG files>");
    LOG("        Extracts all hash linked files/resources of type RTLV from");
    LOG("        all the RPKG files in a given directory and then decrypts");
    LOG("        them in memory and outputs / formats them as JSON files.");
    LOG("    -filter <hash filter>");
    LOG("        Filters hash linked files/resources by string filter.");
    LOG("        String filter can be a full hash value, partial hash value,");
    LOG("        the hash resource type, partial hash resource type, WWES or WWEV");
    LOG("        partial of full file/resource name, etc...");
    LOG("        Can accept multiple filters: -filter <filter1>,<filter2>,...");
    LOG("    -generate_rpkg_from <path to folder to generate rpkg from>");
    LOG("        Generates a RPKG file from hash file(s) in a given folder and all subfolders.");
    LOG("        The folder name is used for the filename of the generated RPKG file.");
    LOG("    -hash_depends <path to folder containing RPKG files>");
    LOG("        Lists the forward and reverse depends of a given hash file/resource.");
    LOG("        Scans a directory, commonly Hitman's Runtime dir, and imports and");
    LOG("        scans all available RPKG files for dependency information and lists the results.");
    LOG("    -hash_probe <path to folder containing RPKG files>");
    LOG("        Probes RPKG files for hash files/resources and displays key data points.");
    LOG("        Scans a directory, commonly Hitman's Runtime dir, and imports and");
    LOG("        scans all available RPKG files for the existence of the hash file/resource.");
    LOG("    -hex_search <hex string>");
    LOG("        Specifices the hex string to find within hash files/resources.");
    LOG("    -output_path <path to output folder>");
    LOG("        Specifies output folder path to use instead of the current directory.");
    LOG("    -rebuild_wwev_in <path to folders containing wem files>");
    LOG("        Rebuilds sets of individual Wwise .wem files that were previously");
    LOG("        extracted with (-extract_wwev_from). The folder specified by the");
    LOG("        argument can contain any number of sub folders, where each subfolder's");
    LOG("        name is linked to an individual WWEV that will be built from the *.wem");
    LOG("        files in that folder.");
    LOG("    -rebuild_dlge_from_json_from <path to folder containing JSON (DLGE) files>");
    LOG("        Rebuilds DLGE files/resources from JSON (DLGE) files that were previously");
    LOG("        extracted with (-extract_dlge_to_json_from).");
    LOG("    -rebuild_locr_from_json_from <path to folder containing JSON (LOCR) files>");
    LOG("        Rebuilds LOCR files/resources from JSON (LOCR) files that were previously");
    LOG("        extracted with (-extract_locr_to_json_from).");
    LOG("    -rebuild_rtlv_from_json_from <path to folder containing JSON (RTLV) files>");
    LOG("        Rebuilds RTLV files/resources from JSON (RTLV) files that were previously");
    LOG("        extracted with (-extract_rtlv_to_json_from).");
    LOG("    -regex_search <regex>");
    LOG("        Specifies the regex which is used to find within hash files/resources.");
    LOG("    -rpkg_command_json <path to rpkg command json file>");
    LOG("        Imports, parses, and runs all the commands listed in the input JSON file.");
    LOG("        See included rpkg_command_reference.JSON for complete JSON command descriptions.");
    LOG("        See included rpkg_command_JSON_examples\\*.JSON for some command JSON examples.");
    LOG("    -search_rpkg <path to rpkg file>");
    LOG("        Specifies RPKG file whose hash files/resources will to be searched through.");
    LOG("    -text_search <text string>");
    LOG("        Specifices the text string to find within hash files/resources.");
    LOG("  Examples:");
    LOG("    Computes the IOI style truncated md5 hash/runtimeid from a string:");
    LOG("        rpkg.exe -compute_ioi_hash \"[assembly:/_PRO/Scenes/Missions/CoastalTown/Mission01.entity].pc_entitytemplate\"");
    LOG("    Decrypts packagedefinitions.txt / thumbs.dat files:");
    LOG("        rpkg.exe -decrypt_packagedefinition_thumbs packagedefinition.txt");
    LOG("    Decrypts packagedefinitions.txt / thumbs.dat files:");
    LOG("        rpkg.exe -encrypt_packagedefinition_thumbs packagedefinition.txt.decrypted");
    LOG("    Extracts all hash linked files/resources from an RPKG file:");
    LOG("        rpkg.exe -extract_from_rpkg \"C:\\Program Files\\Epic Games\\HITMAN3\\Runtime\\chunk0.rpkg\"");
    LOG("    Extracts all hash linked files/resources from an RPKG file to an output folder:");
    LOG("        rpkg.exe -output_path \"R:\\my\\output\\path\" -extract_from_rpkg \"C:\\Program Files\\Epic Games\\HITMAN3\\Runtime\\chunk0.rpkg\"");
    LOG("    Extracts one hash linked files/resources from an RPKG file by hash filter:");
    LOG("        rpkg.exe -filter 00123456789ABCDE -extract_from_rpkg \"C:\\Program Files\\Epic Games\\HITMAN3\\Runtime\\chunk0.rpkg\"");
    LOG("    Extracts multiple hash linked files/resources from an RPKG file by hash filter:");
    LOG("        rpkg.exe -filter 00123456789ABCDE,00123456789ABCDE -extract_from_rpkg \"C:\\Program Files\\Epic Games\\HITMAN3\\Runtime\\chunk0.rpkg\"");
    LOG("    Extracts all hash linked files/resources from an RPKG file by hash resource type filter:");
    LOG("        rpkg.exe -filter ORES -extract_from_rpkg \"C:\\Program Files\\Epic Games\\HITMAN3\\Runtime\\chunk0.rpkg\"");
    LOG("    Extracts all hash linked files/resources from an RPKG file by hash resource types ORES, REPO, and JSON:");
    LOG("        rpkg.exe -filter ORES,REPO,JSON -extract_from_rpkg \"C:\\Program Files\\Epic Games\\HITMAN3\\Runtime\\chunk0.rpkg\"");
    LOG("    Generates a RPKG file from hash file(s) in a given folder and all subfolders:");
    LOG("        rpkg.exe -generate_rpkg_from chunk0patch1");
    LOG("    Extracts all hash linked files/resources located in the ORES files from all the RPKG files in a given directory:");
    LOG("        rpkg.exe -extract_ores_from \"C:\\Program Files\\Epic Games\\HITMAN3\\Runtime\"");
    LOG("    Extracts all hash linked files/resources located in the ORES files from all the RPKG files in a given directory to an output folder:");
    LOG("        rpkg.exe -output_path \"R:\\my\\output\\path\" -extract_ores_from \"C:\\Program Files\\Epic Games\\HITMAN3\\Runtime\"");
    LOG("    Extracts and decrypts (to JSON) all hash linked files/resources of type DLGE from all the RPKG files in a given directory:");
    LOG("        rpkg.exe -extract_dlge_to_json_from \"C:\\Program Files\\Epic Games\\HITMAN3\\Runtime\"");
    LOG("    Extracts and decrypts (to JSON) all hash linked files/resources of type DLGE from all the RPKG files in a given directory to an output folder:");
    LOG("        rpkg.exe -output_path \"R:\\my\\output\\path\" -extract_dlge_to_json_from \"C:\\Program Files\\Epic Games\\HITMAN3\\Runtime\"");
    LOG("    Extracts and decrypts (to JSON) all hash linked files/resources of type LOCR from all the RPKG files in a given directory:");
    LOG("        rpkg.exe -extract_locr_to_json_from \"C:\\Program Files\\Epic Games\\HITMAN3\\Runtime\"");
    LOG("    Extracts and decrypts (to JSON) all hash linked files/resources of type LOCR from all the RPKG files in a given directory to an output folder:");
    LOG("        rpkg.exe -output_path \"R:\\my\\output\\path\" -extract_locr_to_json_from \"C:\\Program Files\\Epic Games\\HITMAN3\\Runtime\"");
    LOG("    Extracts and decrypts (to JSON) all hash linked files/resources of type RTLV from all the RPKG files in a given directory:");
    LOG("        rpkg.exe -extract_rtlv_to_json_from \"C:\\Program Files\\Epic Games\\HITMAN3\\Runtime\"");
    LOG("    Extracts and decrypts (to JSON) all hash linked files/resources of type RTLV from all the RPKG files in a given directory to an output folder:");
    LOG("        rpkg.exe -output_path \"R:\\my\\output\\path\" -extract_rtlv_to_json_from \"C:\\Program Files\\Epic Games\\HITMAN3\\Runtime\"");
    LOG("    Rebuilds sets DLGE files from JSON files that were previously created with (-extract_dlge_to_json_from):");
    LOG("        rpkg.exe -rebuild_dlge_from_json_from \"R:\\DLGE\"");
    LOG("    Rebuilds sets DLGE files from JSON files that were previously created with (-extract_dlge_to_json_from) to an output folder:");
    LOG("        rpkg.exe -output_path \"R:\\my\\output\\path\" -rebuild_dlge_from_json_from \"R:\\DLGE\"");
    LOG("    Rebuilds sets LOCR files from JSON files that were previously created with (-extract_locr_to_json_from):");
    LOG("        rpkg.exe -rebuild_locr_from_json_from \"R:\\LOCR\"");
    LOG("    Rebuilds sets LOCR files from JSON files that were previously created with (-extract_locr_to_json_from):");
    LOG("        rpkg.exe -rebuild_locr_from_json_from \"R:\\LOCR\"");
    LOG("    Rebuilds sets RTLV files from JSON files that were previously created with (-extract_rtlv_to_json_from) to an output folder:");
    LOG("        rpkg.exe -output_path \"R:\\my\\output\\path\" -rebuild_rtlv_from_json_from \"R:\\RTLV\"");
    LOG("    Rebuilds sets RTLV files from JSON files that were previously created with (-extract_rtlv_to_json_from) to an output folder:");
    LOG("        rpkg.exe -output_path \"R:\\my\\output\\path\" -rebuild_rtlv_from_json_from \"R:\\RTLV\"");
    LOG("    Extracts all hash linked files/resources of type WWEM from all the RPKG files in a given directory:");
    LOG("        rpkg.exe -extract_wwem_to_ogg_from \"C:\\Program Files\\Epic Games\\HITMAN3\\Runtime\"");
    LOG("    Extracts all hash linked files/resources of type WWEM from all the RPKG files in a given directory to an output folder:");
    LOG("        rpkg.exe -output_path \"R:\\my\\output\\path\" -extract_wwem_to_ogg_from \"C:\\Program Files\\Epic Games\\HITMAN3\\Runtime\"");
    LOG("    Extracts all hash linked files/resources of type WWES from all the RPKG files in a given directory:");
    LOG("        rpkg.exe -extract_wwes_to_ogg_from \"C:\\Program Files\\Epic Games\\HITMAN3\\Runtime\"");
    LOG("    Extracts all hash linked files/resources of type WWES from all the RPKG files in a given directory to an output folder:");
    LOG("        rpkg.exe -output_path \"R:\\my\\output\\path\" -extract_wwes_to_ogg_from \"C:\\Program Files\\Epic Games\\HITMAN3\\Runtime\"");
    LOG("    Extracts all hash linked files/resources of type WWEV from all the RPKG files in a given directory:");
    LOG("        rpkg.exe -extract_wwev_to_ogg_from \"C:\\Program Files\\Epic Games\\HITMAN3\\Runtime\"");
    LOG("    Extracts all hash linked files/resources of type WWEV from all the RPKG files in a given directory to an output folder:");
    LOG("        rpkg.exe -output_path \"R:\\my\\output\\path\" -extract_wwev_to_ogg_from \"C:\\Program Files\\Epic Games\\HITMAN3\\Runtime\"");
    LOG("    Rebuilds sets of individual Wwise .wem files that were previously extracted with (-extract_wwev_from):");
    LOG("        rpkg.exe -rebuild_wwev_in \"R:\\WWEV\"");
    LOG("    Rebuilds sets of individual Wwise .wem files that were previously extracted with (-extract_wwev_from) to an output folder:");
    LOG("        rpkg.exe -output_path \"R:\\my\\output\\path\" -rebuild_wwev_in \"R:\\WWEV\"");
    LOG("    Lists and extracts the forward depends of a given hash file/resource:");
    LOG("        rpkg.exe -filter 00123456789ABCDE -extract_direct_hash_depends \"C:\\Program Files\\Epic Games\\HITMAN3\\Runtime\"");
    LOG("    Lists and extracts the forward depends of two hash files/resources:");
    LOG("        rpkg.exe -filter 00123456789ABCDE,00123456789ABCDE -extract_direct_hash_depends \"C:\\Program Files\\Epic Games\\HITMAN3\\Runtime\"");
    LOG("    Lists the forward and reverse depends of a given hash file/resource:");
    LOG("        rpkg.exe -filter 00123456789ABCDE -hash_depends \"C:\\Program Files\\Epic Games\\HITMAN3\\Runtime\"");
    LOG("    Lists the forward and reverse depends of two hash files/resources:");
    LOG("        rpkg.exe -filter 00123456789ABCDE,00123456789ABCDE -hash_depends \"C:\\Program Files\\Epic Games\\HITMAN3\\Runtime\"");
    LOG("    Probes RPKG files for hash files/resources and displays key data points:");
    LOG("        rpkg.exe -filter 00123456789ABCDE -hash_probe \"C:\\Program Files\\Epic Games\\HITMAN3\\Runtime\"");
    LOG("    Probes RPKG files for hash files/resources and displays key data points:");
    LOG("        rpkg.exe -filter 00123456789ABCDE,00123456789ABCDE -hash_probe \"C:\\Program Files\\Epic Games\\HITMAN3\\Runtime\"");
    LOG("    Search a RPKG file's hash files/resources by hex string:");
    LOG("        rpkg.exe -hex_search 00112233445566 -search_rpkg \"C:\\Program Files\\Epic Games\\HITMAN3\\Runtime\\chunk0.rpkg\"");
    LOG("    Search a RPKG file's hash files/resources by regex:");
    LOG("        rpkg.exe -regex_search \"assembly:[\\w/_]+\" -search_rpkg \"C:\\Program Files\\Epic Games\\HITMAN3\\Runtime\\chunk0.rpkg\"");
    LOG("    Search a RPKG file's hash files/resources by text string:");
    LOG("        rpkg.exe -text_search assembly -search_rpkg \"C:\\Program Files\\Epic Games\\HITMAN3\\Runtime\\chunk0.rpkg\"");
    LOG("    Search a RPKG file's hash files/resources by regex and filter by type ORES:");
    LOG("        rpkg.exe -filter ORES -regex_search \"assembly:[\\w/_.]+\" -search_rpkg \"C:\\Program Files\\Epic Games\\HITMAN3\\Runtime\\chunk0.rpkg\"");
    LOG("    Imports, parses, and runs all the commands listed in the input JSON file:");
    LOG("      The JSON input below batch extracts from all the RPKGs in the Hitman 3 Runtime folder:");
    LOG("        rpkg.exe -rpkg_command_json rpkg_command-batch_extract_chunk_rpkgs.JSON");
    std::system("pause");
}