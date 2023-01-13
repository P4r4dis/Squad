#ifndef     __TEST_KREOGCOM__
#   define  __TEST_KREOGCOM__

#include <string>
#include <memory>

void    redirect_all_stdout(void);

class   KreogCom
{
    private:
        int                         _x;
        int                         _y;
        const int                   m_serial;
        KreogCom                    *_next;
        // std::unique_ptr<KreogCom>   m_next;
    public:
        KreogCom(int x, int y, int serial);
        ~KreogCom(void);

        int                         getSerial(void) const;
        int                         getX(void);
        int                         getY(void);

        void                        addCom(int x, int y, int serial);
        // void                        addComSmartPtr(int x, int y, int serial);

        KreogCom                    *getCom(void);
        // std::unique_ptr<KreogCom>   getUniquePtrCom(void);
        void                        removeCom(void);
        void                        ping(void) const;

        void                        locateSquad(void) const;
};

#endif //   !__TEST_KREOGCOM__