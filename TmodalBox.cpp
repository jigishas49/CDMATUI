#include "TModalBox.h"

TModalBox::TModalBox() :
    TDialog(TRect(0, 0, 46, 11), "About"),
    TWindowInit(initFrame)
{
    insert(new TStaticText(TRect(3, 2, 43, 10),
        "\003Hello\n \n"
        "\003 I Am Jigisha Srivastava\n \n"
        "\003Working in ISRO"));
    insert(new TButton(TRect(18, 8, 28, 10), "~O~K", cmOK, bfDefault));
    options |= ofCentered;
}
