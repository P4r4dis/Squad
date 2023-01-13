#ifndef     __KREOGCOM__
#   define  __KREOGCOM__

#include <string>

class   KreogCom
{
    private:
        int         _x;
        int         _y;
        const int   m_serial;
    public:
        KreogCom(int x, int y, int serial);
        ~KreogCom(void);

        int         getSerial(void) const;
        int         getX(void);
        int         getY(void);
};


#endif //   !__KREOGCOM__