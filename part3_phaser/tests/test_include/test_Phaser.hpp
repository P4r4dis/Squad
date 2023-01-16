#ifndef     __TEST_PHASER__
#   define  __TEST_PHASER__

#include <string>
#include "test_sounds.hpp"

void    redirect_all_stdout(void);

class   Phaser
{
    public:

        enum                AmmoType
        {
            REGULAR,
            PLASMA,
            ROCKET
        };

        Phaser(int maxAmmo = 20, AmmoType type = REGULAR);
        ~Phaser(void);

        int                 getCurrentAmmos(void);
        int                 getEmpty(void)  const;
        AmmoType            getAmmoType(void);
        void                fire(void);
        void                ejectClip(void);
    private:
        static const int    Empty = 0;
        int                 _maxAmmo;
        AmmoType            _type;
};

#endif //   !__TEST_PHASER__