#ifndef     __TEST_KREOGCOM__
#   define  __TEST_KREOGCOM__

#include <string>


void    redirect_all_stdout(void);

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

#endif //   !__TEST_KREOGCOM__