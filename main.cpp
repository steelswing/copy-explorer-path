#include <windows.h>
#include <string>

int wmain(int argc, wchar_t* argv[]) {
    if (argc < 2) return 1;

    std::wstring text;
    for (int i = 1; i < argc; i++) {
        if (i > 1) text += L" ";  
        text += argv[i];
    }

    if (!OpenClipboard(nullptr)) return 1;
    EmptyClipboard();

    size_t size = (text.length() + 1) * sizeof(wchar_t);
    HGLOBAL hMem = GlobalAlloc(GMEM_MOVEABLE, size);
    if (!hMem) {
        CloseClipboard();
        return 1;
    }

    memcpy(GlobalLock(hMem), text.c_str(), size);
    GlobalUnlock(hMem);

    SetClipboardData(CF_UNICODETEXT, hMem);
    CloseClipboard();

    return 0;
}
