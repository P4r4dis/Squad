#ifndef     __KREOGCOM__
#   define  __KREOGCOM__

#include <string>

class   KreogCom
{
    private:
        int         _x;
        int         _y;
        const int   m_serial;
        KreogCom    *_next;
    public:
        KreogCom(int x, int y, int serial);
        ~KreogCom(void);

        int         getSerial(void) const;
        int         getX(void);
        int         getY(void);

        void        addCom(int x, int y, int serial);
        void        addCom(KreogCom *com);
        KreogCom    *getCom(void);

        void        removeCom(void);
        void        ping(void) const;
        void        locateSquad(void) const;
};


#endif //   !__KREOGCOM__